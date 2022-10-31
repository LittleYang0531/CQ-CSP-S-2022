#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2505;
int n,m,k,dis[N][N],vis[N][N],vvis[N],flag[N];
LL val[N],ans;
vector<int>G[N],T[N];
void bfs(int x){
	queue<pair<int,int> >q;
	q.push(make_pair(x,0));
	dis[x][x]=0;
	for(int i=1;i<=n;i++) flag[i]=0;
	while(!q.empty()){
		pair<int,int>st=q.front();
		q.pop();
		if(flag[st.first]) continue;
		flag[st.first]=1;
		for(int i=0;i<G[st.first].size();i++){
			int to=G[st.first][i];
			if(dis[x][to]>dis[x][st.first]+1){
				dis[x][to]=dis[x][st.first]+1;
				if(dis[x][to]<=k) q.push(make_pair(to,dis[x][to]));
			}
		}
	}
}
void dfs(int pos,int dep,LL res){
	if(dep==4){
		if(vis[pos][1]) ans=max(ans,res);
		return ;
	}
	int S=T[pos].size();
	for(int i=0;i<S;i++){
		int to=T[pos][i];
		if(!vvis[to] && to!=1) vvis[to]=1,dfs(to,dep+1,res+val[to]),vvis[to]=0;
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&val[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(dis[i][j]<=k+1) vis[i][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(vis[i][j]) T[i].push_back(j);
		}
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
} 
