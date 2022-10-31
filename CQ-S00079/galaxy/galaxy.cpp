#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,m;
int q;
int vis[N];
int cnt[N];
int sta[N],len,js;
int ide[N],ode[N];
int cet[N][N];
vector<int>g[N];
void dfs(int now)
{
	if(vis[now]!=0)
	{
		int u;
		if(cnt[now]!=0)u=cnt[now];
		else u=js;
		while(len)
		{
			cnt[len]=u;
			len--;
		}
		return ;
	}
	sta[++len]=now;vis[now]=1;
	for(int i=0;i<g[now].size();i++)
	{
		int y=g[now][i];
		if(cet[now][y]==1)dfs(y);
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t,u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		ide[v]++,ode[u]++;
		cet[u][v]=1;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&u,&v);
			if(cet[u][v]==1)
			{
				cet[u][v]=-1;
				ode[u]--,ide[v]--;
			}
		}
		if(t==2)
		{
			scanf("%d",&u);
			for(int i=1;i<=n;i++)
			{
				if(cet[i][u]==1)
				{
					cet[i][u]=-1;
					ode[i]--,ide[u]--;
				}
			}
		}
		if(t==3)
		{
			scanf("%d%d",&u,&v);
			if(cet[u][v]==-1)
			{
				cet[u][v]=1;
				ode[u]++,ide[v]++;
			}
		}
		if(t==4)
		{
			scanf("%d",&u);
			for(int i=1;i<=n;i++)
			{
				if(cet[i][u]==-1)
				{
					cet[i][u]=1;
					ode[i]++,ide[u]++;
				}
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(ode[i]!=1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		js=0;memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			if(ide[i]==0)
			{
				len=0,js++;
				dfs(i);
			}
		}
		for(int i=2;i<=n;i++)
			if(cnt[i]!=cnt[i-1])
			{
				flag=1;
				break;
			}
		if(flag==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
} 
