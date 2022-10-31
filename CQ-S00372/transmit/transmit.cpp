#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair <int,int>
#define INF 114514114514ll
int n,m,k;
const int maxn=5005;
vector <int> G[maxn],E[maxn];
ll a[maxn],ans;
int p[maxn][maxn],vis[maxn];
ll dis[maxn][maxn];
inline void dij(int s)
{
//	cerr << s << endl;
	priority_queue <pii> que;
	for(int i=1;i<=n;++i)	dis[s][i]=INF,vis[i]=0;
	dis[s][s]=a[s];
	que.push(pii(-a[s],s));
	while(!que.empty())
	{
		int u=que.top().second,d=-que.top().first;
		que.pop();
		if(vis[u])	continue;
		vis[u]=1;
//		if(d!=dis[s][u])	continue;
		for(int v : E[u])
		{
			if(dis[s][v]>dis[s][u]+a[v])
			{
				dis[s][v]=dis[s][u]+a[v];
				que.push(pii(-dis[s][v],v));
			}
		}
	}
//	for(int i=1;i<=n;++i)	if(vis[i]==0)	cerr << "a";
//	for(int i=1;i<=n;++i)	if(dis[s][i]==INF)	cerr << "  " << s << "  " << i << endl;
//	cerr << endl;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)	scanf("%lld",&a[i]);
	for(int i=1;i<=n-1;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y),G[y].push_back(x);
	}
	queue <pii> que;
	for(int s=1;s<=n;++s)
	{
		while(!que.empty())	que.pop();
		for(int i=1;i<=n;++i)	vis[i]=0;
		que.push(pii(s,0));
		while(!que.empty())
		{
			int u=que.front().first,d=que.front().second;
			que.pop();
			if(d>=k)	break;
			for(int v : G[u])
			{
				if(vis[v])	continue;
				vis[v]=1,p[s][v]=1;
				E[s].push_back(v);
				que.push(pii(v,d+1));
			}
		}
	}
	for(int i=1;i<=n;++i)	dij(i);
//	cerr << "aa";
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",dis[x][y]);
	}
	return 0;
}
/*
10 10 1
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7


*/
