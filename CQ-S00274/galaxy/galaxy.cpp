#include<bits/stdc++.h>
#define maxn 10004
using namespace std;
int n,m,q,t;
bool a[maxn][maxn];
bool cz[maxn][maxn];
int suma,sumb;
bool b[maxn];
bool flag,ppdd;
bool vis[maxn];
inline void dfs(int step)
{
	int ssuumm=0;
	if (flag==1 || ppdd==1)
		return ;
	for (int i=1; i<=n; i++)
	{
		if (a[step][i]==1 && cz[step][i]==1)
		{
			if (vis[i]==1)
			{
				ppdd = 1;
				break;
			}
			vis[i] = 1;
			ssuumm++;
			if (a[i][step]==1)
			{
				ppdd = 1;
				break;
			}
			dfs(i);
			if (ppdd==1 || flag==1)
				return ;
		}
	}
	if (ssuumm==0 && ppdd==0)
		flag = 1;
	return ;
}
inline void solve()
{
	for (int i=1; i<=n; i++)
	{
		memset(vis,0,sizeof(vis));
		ppdd = 0;
		vis[i] = 1;
		dfs(i);
		if (flag==1)
		{
//			cout<<i<<endl;
			break;
		}	
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++)
		b[i] = 1;
	for (int i=1; i<=m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		cz[u][v] = a[u][v] = 1;
	}
	sumb = n;
	suma = m;
	cin>>q;
	while (q--)
	{
		flag = 0;
		scanf("%d",&t);
		int x,y;
		if (t==1)
		{
			scanf("%d%d",&x,&y);
			a[x][y] = 0;
			suma--;
		}
		else if (t==2)
		{
			scanf("%d",&x);
			if (b[x]==1)
				b[x] = 0, sumb--;
			for (int i=1; i<=n; i++)
				if (a[i][x]==1)
					a[i][x] = 0, suma--;
		}
		else if (t==3)
		{
			scanf("%d%d",&x,&y);
			a[x][y] = 1;
			suma++;
			if (b[y]==0)
				b[y] = 1, sumb++;
		}
		else
		{
			scanf("%d",&x);
			if (b[x]==0)
				b[x] = 1, sumb++;
			for (int i=1; i<=n; i++)
				if (a[i][x]==0 && cz[i][x]==1)
					a[i][x] = 1, suma++;
		}
		
//		cout<<sumb<<" "<<suma<<endl;
		if (sumb!=suma)
			printf("NO\n");
		else
		{
			solve();
			if (flag==1)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}
