//POYE's Code
#include<cstdio>
using namespace std;
typedef long long ll;
int n,m,Q;
bool flag,g[1005][1005],a[1005][1005],vis[1005];
inline void dfs(int x)
{
	if(vis[x]) return flag=1,void();
	vis[x]=1;
	for(int i=1;i<=n;i++)
		if(g[x][i])
		{
			dfs(i);
			if(flag) return;
		}
}

inline bool check()
{
	for(int i=1;i<=n;i++)
	{
		flag=0;
		int cnt=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		dfs(i);
		if(!flag) return 0;
		for(int j=1;j<=n;j++)
			if(g[i][j]) cnt++;
		if(cnt!=1) return 0;
	}
	return 1;
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=g[x][y]=1;
	}
	scanf("%d",&Q);
	for(int o=1;o<=Q;o++)
	{
		int t,x,y;
		scanf("%d%d",&t,&x);
		if(t==1)
		{
			scanf("%d",&y);
			g[x][y]=0;
		}
		else if(t==2)
		{
			for(int i=1;i<=n;i++)
				if(a[i][x]) g[i][x]=0;
		}
		else if(t==3)
		{
			scanf("%d",&y);
			g[x][y]=1;
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(a[i][x]) g[i][x]=1;
		}
		if(check()) puts("YES");
		else puts("NO");
	}

	return 0;
}
