#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
int n,Q,k,m,cnt,h[200005],Log[200005],len[200005],fa[200005][30];
long long v[200005],dis[200005],dp[200005];
struct edge{
	int v,nxt;
}e[400005];
void adde(int u,int v){
	e[++cnt].nxt=h[u];
	h[u]=cnt;
	e[cnt].v=v;
}
void dfs(int x){
	for(int i=h[x];i;i=e[i].nxt){
		if(e[i].v==fa[x][0])continue;
		len[e[i].v]=len[x]+1;
		dis[e[i].v]=dis[x]+v[e[i].v];
		fa[e[i].v][0]=x;
		for(int j=1;j<=Log[len[e[i].v]];j++)fa[e[i].v][j]=fa[fa[e[i].v][j-1]][j-1];
		dfs(e[i].v);
	}
}
int LCA(int u,int v){
	if(len[u]<len[v])swap(u,v);
	for(int j=Log[len[u]];j>=0;j--){
		if(len[fa[u][j]]>=len[v]){
			u=fa[u][j];
		}
	}
	if(u==v)return u;
	for(int j=25;j>=0;j--){
		if(fa[u][j]!=fa[v][j]){
			u=fa[u][j],v=fa[v][j];
		}
	}
	return fa[v][0];
}
deque<long long>q,p;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),Q=read(),k=read();
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
	for(int i=2,u,v;i<=n;i++)u=read(),v=read(),adde(u,v),adde(v,u);
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	len[1]=1;dis[1]=v[1];
	dfs(1);
	int u,v,lca;
	if(k==1){
		while(Q--){
			u=read();v=read();lca=LCA(u,v);
			printf("%lld\n",dis[u]+dis[v]-dis[lca]-dis[fa[lca][0]]);
		}
	}
	else{
		while(Q--){
			u=read();v=read();lca=LCA(u,v);
			m=len[u]+len[v]-2*len[lca]+1;
			while(!q.empty())q.pop_back();
			while(!p.empty())p.pop_back();
			while(u!=lca)q.push_back(::v[u]),u=fa[u][0];
			while(v!=lca)p.push_back(::v[v]),v=fa[v][0];
			q.push_back(::v[lca]);
			while(!p.empty())q.push_back(p.back()),p.pop_back();
			q.push_front(0);
			dp[1]=q[1];
			for(int i=2;i<=m;i++){
				dp[i]=4e18;
				for(int j=max(1,i-k);j<i;j++)dp[i]=min(dp[i],dp[j]+q[i]);
			}
			printf("%lld\n",dp[m]);
		}
	}
	return 0;
}
