#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,k,fa[200005][20],depth[200005];
ll val[200005],dist[200005],dd[2003][2003];
vector<int>edge[200005];
void dfs(int id,int from){
	dist[id]=dist[from]+val[id];
	depth[id]=depth[fa[id][0]=from]+1;
	for(int v:edge[id])if(v!=from)dfs(v,id);
}
inline void init(){
	for(int len=1;(1<<len)<=n;len++)
	for(int i=1;i<=n;i++)
	fa[i][len]=fa[fa[i][len-1]][len-1];
}
inline int lca(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	for(int i=19;i>=0;i--)if(depth[fa[u][i]]>=depth[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)if(fa[u][i]!=fa[v][i])
	u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}dfs(1,0),init();
	if(k==1){
		while(q--){
			int s,t;
			scanf("%d%d",&s,&t);
			printf("%lld\n",dist[s]+dist[t]-dist[lca(s,t)]);
		}exit(0);
	}
}
