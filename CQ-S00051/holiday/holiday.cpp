#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define mp make_pair
int n,m,k;
long long int dis[2505][2505];
long long int dis2[5][2505];
long long int num[2505];
vector<int> G[2505];
bool f[2505];
bool f2[5][2505];
priority_queue<pair<int,int> > pq;
priority_queue<pair<int,pair<int,int>> > pq2;
void Dijkstra(int S){
	memset(f,0,sizeof f);
	dis[S][S]=-1,pq.push(make_pair(0,S));
	while(!pq.empty()){
		int t=pq.top().second;
		pq.pop();
		if(f[t]) continue;
		f[t]=1;
		for(auto &x:G[t])
			if((!f[x])&&dis[S][x]>dis[S][t]+1)
				dis[S][x]=dis[S][t]+1,pq.push(make_pair(-dis[S][x],x));
	}
}
void Dijkstra2(){
	memset(dis,0x80,sizeof dis);
	memset(f,0,sizeof f);
	dis2[0][1]=0,pq2.push(mp(0,mp(0,1)));
	while(!pq2.empty()){
		int t=pq2.top().second.second,tt=-pq2.top().first;
//		printf("%d %d\n",t,tt);
		pq2.pop();
		if(tt>=4||f2[tt][t]||f2[tt-2][t]||f2[tt-3][t]) continue;
		f2[tt][t]=1;
		for(auto &x:G[t]){
			if(tt<4&&dis2[tt+1][x]<dis2[tt][t]+num[x]) 
				dis2[tt+1][x]=dis2[tt][t]+num[x],pq2.push(mp(-tt-1,mp(dis2[tt+1][x],x))); 
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%lld ",dis2[4][i]);
}
long long int ans;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++)
		scanf("%lld",num+i);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) Dijkstra(i);
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(j!=1&&i!=j&&dis[i][j]<=k) G[i].push_back(j);
	for(auto &x:G[1]) for(auto &x2:G[x]) for(auto &x3:G[1]) for(auto &x4:G[x3])
		if(x!=x2&&x!=x3&&x!=x4&&x2!=x3&&x2!=x4&&x3!=x4&&dis[x2][x4]<=k)
			ans=max(ans,num[x]+num[x2]+num[x3]+num[x4]);
	printf("%lld",ans);
	return 0;
}
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
