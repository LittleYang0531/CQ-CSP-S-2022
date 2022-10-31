#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define fi first
#define se second
using namespace std;
const int Maxn=2e5;
const ll Inf=1e18;
priority_queue<pair<ll,int>>q;
vector<int>T[Maxn+5];
vector<pair<int,int>>adj[Maxn+5];
ll sum[Maxn+5],dis[2005][2005];
int st[2*Maxn+5][20],log_2[2*Maxn+5],dep[Maxn+5],pos[Maxn+5],timer;
int mark[Maxn+5];
int v[Maxn+5];
int n,m,k;
inline int check(int x,int y) {
	return dep[x]<dep[y]?x:y;
}
inline int lca(int x,int y) {
	int l=pos[x],r=pos[y];
	if(l>r)swap(l,r);
	int t=log_2[r-l+1];
	return check(st[l][t],st[r-(1<<t)+1][t]);
}
void build() {
	log_2[0]=-1;
	for(ri i=1;i<=2*n-1;i++)log_2[i]=log_2[i>>1]+1;
	for(ri j=1;j<=log_2[2*n-1];j++)
		for(ri i=1;i<=2*n-1-(1<<j)+1;i++)st[i][j]=check(st[i][j-1],st[i+(1<<j-1)][j-1]);
}
void dfs_euler(int u,int fa) {
	dep[u]=dep[fa]+1,pos[u]=++timer,st[timer][0]=u;
	sum[u]=sum[fa]+v[u];
	for(ri v:T[u])
		if(v!=fa) {
			dfs_euler(v,u);
			st[++timer][0]=u;
		}
}
void dfs(int rt,int u,int fa,int dep) {
	adj[rt].emplace_back(u,v[u]);
	if(dep==k)return ;
	for(ri v:T[u])
		if(v!=fa) {
			dfs(rt,v,u,dep+1);
		}
}
void dij(int source,ll dis[]) {
	for(ri i=1;i<=n;i++)mark[i]=0,dis[i]=Inf;
	dis[source]=0,q.push(make_pair(0,source));
	while(!q.empty()) {
		int u=q.top().se;q.pop();
		if(mark[u])continue;
		mark[u]=1;
		for(auto &e:adj[u]) {
			int v=e.fi;
			if(dis[v]>dis[u]+e.se) {
				dis[v]=dis[u]+e.se;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1;i<=n;i++)scanf("%d",&v[i]);
	for(ri i=1;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		T[x].push_back(y);
		T[y].push_back(x);
	}
	if(k==1) {
		dfs_euler(1,0),build();
		while(m--) {
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",sum[x]+sum[y]-2*sum[lca(x,y)]+v[lca(x,y)]);
		}
		return 0;
	}
	for(ri i=1;i<=n;i++)dfs(i,i,0,0);
	for(ri i=1;i<=n;i++)dij(i,dis[i]);
	while(m--) {
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dis[x][y]+v[x]);	
	}
	return 0;
}

