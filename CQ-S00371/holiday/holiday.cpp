#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
int n,m,k,dist[2503];
bool vis[2503],check[2503];
ll score[2503],ans;
vector<int>edge[2503],e[2503];
priority_queue<pii,vector<pii>,greater<pii>>q;
inline void dijkstra(int S){
	memset(dist,0x3f,sizeof(dist));
	q.emplace(dist[S]=-1,S);
	while(q.size()){
		auto h=q.top();q.pop();
		if(dist[h.second]<h.first)continue;
		for(int v:edge[h.second])
		if(dist[v]>dist[h.second]+1)
		q.emplace(dist[v]=dist[h.second]+1,v);
	}
	for(int i=1;i<=n;i++)if(S!=i&&dist[i]<=k){
		e[S].emplace_back(i);
		if(i==1)check[S]=1;
	}
}
void dfs(int id,int depth,ll res){
	if(depth==4){
		if(check[id])ans=max(ans,res);
		return;
	}vis[id]=1;
	for(int v:e[id])if(!vis[v])dfs(v,depth+1,res+score[v]);
	vis[id]=0; 
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&score[i]);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	dfs(1,0,0);
	printf("%lld",ans);return 0;
}
