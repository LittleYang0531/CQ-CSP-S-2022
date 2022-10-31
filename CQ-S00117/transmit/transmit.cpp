#include<bits/stdc++.h>
using namespace std;
const int N=200+5;
int n,q,k,g1,g2;
int f[N],bj[N],vis[N][N];
long long ans=0x7fffffffffff;
void dfs(int now,long long sum)
{
	if(now==g2)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==0&&vis[now][i]<=k)
		{
			bj[i]=1;
			dfs(i,sum+f[i]);
			bj[i]=0;
		}
	}
	return;
}
void fl()
{
	for(int g=1;g<=n;g++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[i][g]+vis[g][j]<=k)
				{
					vis[i][j]=min(vis[i][j],vis[i][g]+vis[g][j]);
				}
			}
		}
	}
	cout<<vis[1][2]<<endl;;
	return;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	memset(vis,0x3f,sizeof(vis));
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&g1,&g2);
		vis[g1][g2]=1;
		vis[g2][g1]=1;
	}
	fl();
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&g1,&g2);
		bj[g1]=1;
		ans=0x7ffffffff;
		dfs(g1,f[g1]);
		bj[g1]=0;
		printf("%lld\n",ans);
	}
	return 0;
}
