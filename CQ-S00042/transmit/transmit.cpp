//Floyd+ฑฌหั 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2005;
//vector<int>G[MAXN];
int dis[MAXN][MAXN];
bool G[MAXN][MAXN];
bool vis[MAXN];
int a[MAXN];
int ans=LONG_LONG_MAX;
int n,q,k;
void Floyd(int n)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void dfs(int x,int y,int cnt)
{
	if(x==y)
	{
		ans=min(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		if(dis[x][i]<=k&&!vis[i])
		{
			vis[i]=true;
			cnt+=a[i];
			dfs(i,y,cnt);
			cnt-=a[i];
			vis[i]=false;
		}
	}
}
void solve()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
//		G[x].push_back(y);
//		G[y].push_back(x);
		dis[x][y]=1;
		dis[y][x]=1;
		G[x][y]=true;
		G[y][x]=true;
	}
	Floyd(n);
	while(q--)
	{
		ans=LONG_LONG_MAX;
		memset(vis,false,sizeof(vis));
		int s,t;
		scanf("%lld%lld",&s,&t);
		if(G[s][t]) 
		{
			printf("%lld\n",a[s]+a[t]);
			continue;
		}
		dfs(s,t,a[s]);
		printf("%lld\n",ans);
	}
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	solve();
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
