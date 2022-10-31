#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=2510,M=100010;
char Ch;
inline void r(ll &x)
{
	x=0;
	while((Ch=getchar())<48||Ch>57);
	while(Ch>47&&Ch<58)x*=10,x+=Ch-48,Ch=getchar();
	return;
}
bool c[N][N];
bool g[N][N];
int dis[N];
queue<int> bfs;
ll n,m,k;
inline void BFS(int s)
{
	memset(dis,127,sizeof dis);
	bfs.push(s);
	dis[s]=0;
	while(!bfs.empty())
	{
		int x=bfs.front();
		bfs.pop();
		if(dis[x]>k)continue;
		for(int i=1;i<=n;i++)
		{
			if(c[x][i]&&dis[i]>1e9)
			{
				dis[i]=dis[x]+1;
				g[s][i]=g[i][s]=true;
				bfs.push(i);
			}
		}
	}
	return;
}
ll val[N];
ll arr[N];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	r(n),r(m),r(k);
	for(int i=2;i<=n;i++)r(val[i]);
	int u,v;
	for(int i=1;i<=m;i++)scanf("%d%d",&u,&v),c[u][v]=c[v][u]=g[u][v]=g[v][u]=true;
	for(int i=1;i<=n;i++)BFS(i);
	ll ans=-1,fb=0,sb=0;
	for(int i=2;i<=n;i++)
	{
		if(!g[1][i])continue;
		for(int j=2;j<=n;j++)
		{
			if(i==j)continue;
			fb=sb=0;
			int f=0;
			bool f1=false,f2=false;
			for(int k=2;k<=n;k++)
			{
				if(i==k||j==k)continue;
				if((g[1][k]||g[i][k])&&g[j][k])
				{
					if(g[1][k])sb=max(sb,val[k]),f1=true;
					else if(g[i][k])fb=max(fb,val[k]),f2=true;
					f++;
				}
			}
			if(f>1&&f1&&f2)ans=max(ans,val[i]+val[j]+fb+sb);
		}
	}
	printf("%lld",ans);
	return 0;
}
