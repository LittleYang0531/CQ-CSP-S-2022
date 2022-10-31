#include<bits/stdc++.h>
using namespace std;
long long maps[1001][1001],n,m,dis,v[3003];
long long ans;
int check(int a,int b,int c,int d)
{
	if(maps[a][1]==0||maps[a][b]==0||maps[b][c]==0||maps[d][c]==0||maps[d][1]==0)return 0;
	return 1;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&dis);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)maps[i][j]=1e18;
	maps[1][1]=0;
	for(int i=2;i<=n;i++)scanf("%lld",&v[i]),maps[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		maps[y][x]=maps[x][y]=1;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(maps[i][k]&&maps[k][j]&&i!=j)maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);
	}
	for(int a=2;maps[a][1]-1>dis,a<=n;a++)
	{
		if(maps[a][1]-1>dis)continue;
		for(int b=2;b<=n;b++)
		{
			if(maps[b][a]-1>dis)continue;
			for(int c=2;c<=n;c++)
			{
				if(maps[c][b]-1>dis)continue;
				for(int d=2;d<=n;d++)
				{
					if(maps[d][c]-1>dis||maps[d][1]-1>dis)continue;
					if(a!=b&&a!=c&&c!=b&&d!=a&&d!=b&&d!=c)
					{
						if(check(a,b,c,d))ans=max(ans,v[a]+v[b]+v[c]+v[d]);
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
