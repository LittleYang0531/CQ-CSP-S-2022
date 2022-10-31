#include<bits/stdc++.h>
using namespace std;
long long k,n,q,v[10001],dis[2002][2002],ans=1e18,vis[2002]; 
void dfs(int now,long long sum,int en)
{
	//cout<<now<<" "<<sum<<endl;
	if(now<0||now>n)return;
	if(now==en)
	{
		ans=min(ans,sum);return;
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[now][i]&&dis[now][i]<=k&&now!=i&&!vis[i])
		{
			vis[i]=1;
			dfs(i,sum+v[i],en);vis[i]=0;
		}
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e18;
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]),dis[i][i]=0;;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		dis[x][y]=dis[y][x]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--)
	{
		int st;int en;
		scanf("%d%d",&st,&en);
		if(dis[st][en]<=k)printf("%lld\n",v[st]+v[en]);
		else
		{
			ans=1e18;
			dfs(st,v[st],en);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
