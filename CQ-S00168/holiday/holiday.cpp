#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=2505,M=20005,inf=0x3f3f3f3f;

int n,k,m;
int g[N][N];
LL s[N];
bool st[N];
LL ans;

void dfs(int u,int p,LL x)
{
	if(p==4)
	{
		if(g[u][1]!=inf)ans=max(ans,x);
		return;
	}
	for(int v=2;v<=n;v++)
		if(!st[v]&&g[u][v]!=inf)
		{
			st[v]=true;
			dfs(v,p+1,x+s[v]);
			st[v]=false;
		}
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&s[i]);
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a][b]=g[b][a]=1;
	}
	
	if(k)
	{
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(g[i][j]<=k+1)g[i][j]=1;
				else g[i][j]=inf;
	}
	
	dfs(1,0,0);
	
	printf("%lld\n",ans);
	
	return 0;
}
