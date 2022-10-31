#include<bits/stdc++.h>
using namespace std;
int h[200005],to[400005],nxt[400005];
long long w[200005],sum[200005],dp[200005];
int fa[200005][20],dep[200005],son[200005];
int n,q,k,tot,a,b;
void jb(int u,int v){
	++tot;
	to[tot]=v;
	nxt[tot]=h[u];
	h[u]=tot;
}
void dfs(int u,int f){
	sum[u]=sum[f]+w[u];
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=17;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=h[u];i!=0;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		if(w[son[u]]>w[v]) son[u]=v;
	}
}
int Lca(int u,int v){
	for(int i=17;i>=0;i--){
		if(dep[fa[v][i]]>=dep[u]) v=fa[v][i];
	}
	if(u==v) return u;
	for(int i=17;i>=0;i--){
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
int jump(int x,int lca){
	int res=x;
	dp[x]=w[x];
	dp[fa[x][0]]=1e18;
	while(fa[x][0]!=lca){
		dp[fa[x][1]]=dp[x]+w[fa[x][1]];
		dp[fa[x][0]]=min(dp[fa[x][0]],dp[x]+w[fa[x][0]]);
		res=x;
		x=fa[x][0];
	}
	return res;
}
struct node{int x;};
bool operator < (node p1,node p2){
	return dp[p1.x]<dp[p2.x];
}
priority_queue<node> Q;
bool bl[200005];
int kk[200005],cnt;
long long an1,an2;
long long dfs2(int u,int lca){
	if(bl[u]==1) return dp[u];
	if(dep[u]<dep[lca]) return 1e18;
	bl[u]=1;kk[++cnt]=u;
	dp[u]=w[u]+min(dfs2(fa[u][1],lca),min(dfs2(fa[fa[u][1]][0],lca),dfs2(son[fa[u][1]],lca)));
	if(fa[u][0]==lca) dp[u]=min(dp[u],w[u]+min(an1,an2));
	if(fa[u][1]==lca) dp[u]=min(dp[u],w[u]+an1);
	return dp[u];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		jb(a,b);jb(b,a);
	}
	w[0]=1e18;son[0]=1;
	dfs(1,0);
	if(k==1){
		for(int i=1;i<=q;i++){
			scanf("%d%d",&a,&b);
			if(dep[a]>dep[b]) swap(a,b);
			int lca=Lca(a,b);
			printf("%lld\n",sum[a]+sum[b]-sum[lca]-sum[fa[lca][0]]);
		}
		return 0;
	}
	if(k==2){
		for(int i=1;i<=q;i++){
			scanf("%d%d",&a,&b);
			if(dep[a]>dep[b]) swap(a,b);
			int lca=Lca(a,b);
			if(a==lca){
				int x=jump(b,lca);
				printf("%lld\n",w[a]+min(dp[x],dp[fa[x][0]]));
			}
			else{
				if(fa[a][0]==lca){
					if(fa[b][0]==lca) printf("%lld\n",w[a]+w[b]);
					else{
						int x=jump(b,lca);
						printf("%lld\n",w[a]+min(w[lca]+dp[x],dp[fa[x][0]]));
					}
				}
				else{
					int x=jump(b,lca);
					int y=jump(a,lca);
					long long ans=w[lca]+min(dp[x],dp[fa[x][0]])+min(dp[y],dp[fa[y][0]]);
					ans=min(ans,dp[fa[x][0]]+dp[fa[y][0]]);
					printf("%lld\n",ans);
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a,&b);
		if(dep[a]>dep[b]) swap(a,b);
		int lca=Lca(a,b);
		cnt=0;
		dp[a]=w[a];bl[a]=1;kk[++cnt]=a;
		Q.push(node{a});
		an1=an2=1e18;
		while(!Q.empty()){
			int u=Q.top().x;Q.pop();
			if(dep[u]<=dep[lca]) continue;
			if(fa[u][0]==lca){
				an1=min(an1,dp[u]);
			}
			if(fa[u][1]==lca){
				an2=min(an2,dp[u]);
			}
			if(bl[fa[u][1]]==0){
				int v=fa[u][1];
				dp[v]=dp[u]+w[v];
				bl[v]=1;kk[++cnt]=v;
				Q.push(node{v});
			}
			if(bl[son[fa[u][1]]]==0){
				int v=son[fa[u][1]];
				dp[v]=dp[u]+w[v];
				bl[v]=1;kk[++cnt]=v;
				Q.push(node{v});
			}
			if(bl[fa[fa[u][1]][0]]==0){
				int v=fa[fa[u][1]][0];
				dp[v]=dp[u]+w[v];
				bl[v]=1;kk[++cnt]=v;
				Q.push(node{v});
			}
		}
		printf("%lld\n",dfs2(b,lca));
		for(int j=1;j<=cnt;j++) bl[kk[j]]=0;
	}
	return 0;
}
