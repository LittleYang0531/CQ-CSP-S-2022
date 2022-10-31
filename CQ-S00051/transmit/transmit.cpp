#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define mp make_pair
int n,q,k;
long long int dis[50005];
long long int num[50005];
vector<int> G[50005];
vector<pair<int,int> > G2[50005];
bool f[50005];
priority_queue<pair<int,int> > pq;
void Dijkstra(int S){
	memset(f,0,sizeof f);
	memset(dis,0x3f,sizeof dis);
	dis[S]=0,pq.push(make_pair(0,S));
	while(!pq.empty()){
		int t=pq.top().second;
		pq.pop();
		if(f[t]) continue;
		f[t]=1;
		for(auto &x:G[t])
			if((!f[x])&&dis[x]>dis[t]+1)
				dis[x]=dis[t]+1,pq.push(make_pair(-dis[x],x));
	}
	for(int i=1;i<=n;i++)
		if(S!=i&&dis[i]<=k) G2[S].push_back(make_pair(i,0));
}
void Dijkstra2(int S){
	memset(f,0,sizeof f);
	memset(dis,0x3f,sizeof dis);
	dis[S]=num[S],pq.push(make_pair(num[S],S));
	while(!pq.empty()){
		int t=pq.top().second;
		pq.pop();
		if(f[t]) continue;
		f[t]=1;
		for(auto &x:G[t])
			if((!f[x])&&dis[x]>dis[t]+num[x])
				dis[x]=dis[t]+num[x],pq.push(make_pair(-dis[x],x));
	}
	for(auto &x:G2[S]) x.second=dis[x.first];
}
long long int Dijkstra(int S,int T){
	memset(f,0,sizeof f);
	memset(dis,0x3f,sizeof dis);
	dis[S]=0,pq.push(make_pair(0,S));
	while(!pq.empty()){
		int t=pq.top().second;
		pq.pop();
		if(f[t]) continue;
		f[t]=1;
		for(auto &x:G2[t])
			if((!f[x.first])&&dis[x.first]>dis[t]+x.second)
				dis[x.first]=dis[t]+x.second,pq.push(make_pair(-dis[x.first],x.first));
	}
	return dis[T];
}
long long int ans;
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&q,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",num+i);
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) Dijkstra(i);
	for(int i=1;i<=n;i++) Dijkstra2(i);
//	for(int i=1;i<=n;i++)
//		for(auto &x:G2[i]) printf("%d->%d %d\n",i,x.first,x.second);
	int s=0,t=0;
	while(q--){
		scanf("%d %d",&s,&t);
		printf("%lld\n",Dijkstra(s,t));
	}
	return 0;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2

*/
