#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,q,sz[N],scc[N],dfn[N],low[N],sy[N],in[N],flag[N],idx,cnt;
vector<int>G[N],T[N],P[N];
map<int,int>vis[N],vvis[N];
stack<int>s;
void tarjan(int x){
	dfn[x]=low[x]=++idx;
	s.push(x);
	for(int i=0;i<G[x].size();i++){
		int to=G[x][i];
		if(vis[x][to]) continue;
		if(dfn[to]) low[x]=min(low[x],dfn[to]);
		else tarjan(to),low[x]=min(low[x],low[to]);
	}
	if(low[x]==dfn[x]){
		cnt++;
		while(!s.empty()){
			sy[cnt]++;
			int d=s.top();
			scc[d]=cnt;
			s.pop();
			if(d==x) break;
		}
	}
}
bool check(){
	idx=cnt=0;
	for(int i=1;i<=n;i++) dfn[i]=scc[i]=in[i]=sy[i]=flag[i]=0;
	for(int i=1;i<=n;i++) if(!vis[i][0] && !dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) vvis[i].clear(),P[i].clear();
	for(int i=1;i<=n;i++){
		if(!vis[i][0]){
			for(int j=0;j<G[i].size();j++){
				if(!vis[i][G[i][j]]){
					if(!vvis[scc[i]][scc[G[i][j]]]) in[scc[i]]++,vvis[scc[i]][scc[G[i][j]]]=1,P[scc[G[i][j]]].push_back(scc[i]);
				}
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=cnt;i++) if(sy[i]>1) flag[i]=1;
	for(int i=1;i<=cnt;i++) if(!in[i]) q.push(i);
//	for(int i=1;i<=n;i++) printf("%d",scc[i]);puts("");
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<P[x].size();i++){
			int to=P[x][i];
			flag[to]|=flag[x];
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	for(int i=1;i<=cnt;i++) if(!flag[i]) return 0;
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		T[v].push_back(u),G[u].push_back(v),sz[u]++;
	}
	scanf("%d",&q);
	while(q--){
		int t,u,v,flag=0;
		scanf("%d %d",&t,&u);
		if(t==1 || t==3) scanf("%d",&v);
		if(t==1){
			if(!vis[u][v]){
				sz[u]--;
				vis[u][v]=1;
			}
		}
		if(t==2){
			if(!vis[u][0]) vis[u][0]=1;
			for(int i=0;i<T[u].size();i++){
				if(!vis[T[u][i]][u]){
					vis[T[u][i]][u]=1;
					sz[T[u][i]]--;
				}
			}
		}
		if(t==3){
			if(vis[u][v]){
				sz[u]++;
				vis[u][v]=0;
			}
		}
		if(t==4){
			if(vis[u][0]) vis[u][0]=0;
			for(int i=0;i<T[u].size();i++){
				if(vis[T[u][i]][u]){
					vis[T[u][i]][u]=0;
					sz[T[u][i]]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!vis[i][0]){
				if(sz[i]>1) flag=1;
			}
		}
		if(flag){
			printf("NO\n");
			continue;
		}
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
