#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct E{
	int v,nxt;
}e[N<<2];
int head[N],cnt;
void add(int u,int v) {
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
ll n,q,k,ans;
ll dep[N],sw[N],fa[N][25],w[N];
void dfs(int u) {
	dep[u]=dep[fa[u][0]]+1;
	sw[u]=sw[fa[u][0]]+w[u];
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].v;
		if(v==fa[u][0]) continue;
		fa[v][0]=u;
		dfs(v);
	}
}
int LCA(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	ll h=dep[x]-dep[y];
	for(int i=20;i>=0;i--) {
		if((1<<i)&h) {
			x=fa[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--) {
		if(fa[x][i]!=fa[y][i]) {
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
ll dp[N],dp2[N];
void solve_RP() {
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=q;i++) {
		int st,ed;
		scanf("%d%d",&st,&ed);
		if(k==1) {
			printf("%lld\n",sw[st]+sw[ed]-sw[LCA(st,ed)]);
		}
		if(k==3) {
			int x=fa[fa[st][1]][0],a1=st,b1=fa[st][0],c1=fa[st][1],a2,b2,c2;
			dp[a1]=w[a1];
			dp[b1]=dp[a1]+w[b1];
			dp[c1]=min(dp[a1]+w[c1],dp[b1]+w[c1]);
			int lca=LCA(st,ed);
			if(a1!=lca&&b1!=lca&&c1!=lca) {
				while(x!=lca) {
					dp[x]=min(dp[a1],min(dp[b1],dp[c1]))+w[x];
					a1=b1;
					b1=c1;
					c1=fa[c1][0];
					x=fa[x][0];
				}
				dp[x]=min(dp[a1],min(dp[b1],dp[c1]))+w[x];
			}
			
			a2=a1;
			b2=b1;
			c2=c1;
			
			x=fa[fa[ed][1]][0],a1=ed,b1=fa[ed][0],c1=fa[ed][1];
			dp2[a1]=w[a1];
			dp2[b1]=dp2[a1]+w[b1];
			dp2[c1]=min(dp2[a1]+w[c1],dp2[b1]+w[c1]);
			if(a1!=lca&&b1!=lca&&c1!=lca) {
				while(x!=lca) {
					dp2[x]=min(dp2[a1],min(dp2[b1],dp2[c1]))+w[x];
					a1=b1;
					b1=c1;
					c1=fa[c1][0];
					x=fa[x][0];
				}
				dp2[x]=min(dp2[a1],min(dp2[b1],dp2[c1]))+w[x];
			}
			int z1[10]={0,a1,b1,c1,lca};
			int z2[10]={0,a2,b2,c2,lca};
			ans=100000000000000000;
			int tot1=4,tot2=4;
			if(a1==lca) tot1=1;
			if(b1==lca)	tot1=2;
			if(c1==lca) tot1=3;
			if(a2==lca) tot2=1;
			if(b2==lca)	tot2=2;
			if(c2==lca) tot2=3;
			for(int j=1;j<=tot1;j++) {
				for(int p=tot2;p>=max(1ll,tot2-(k-(tot1-j)));p--) {
					if(j==tot1&&p==tot2) continue;
					ll zz=dp2[z1[j]]+dp[z2[p]];
					ans=min(ans,zz);
				}
			}
			printf("%lld\n",ans);
		}
	}
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) {
		solve_RP();
	}
	return 0;
}
