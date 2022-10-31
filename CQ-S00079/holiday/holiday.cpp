#include<bits/stdc++.h>
using namespace std;
#define N 2505
int n,m,k;
int mx;
int ans;
int a[N];
int vis[N];
int cet[N][N];
vector<int>g[N],h[N];
void connect_(int now,int fa,int rot,int stp)
{
	if(stp>k)return ;
	if(cet[rot][now]==0)
	{
//		cout<<rot<<' '<<now<<endl;
		g[now].push_back(rot);
		g[rot].push_back(now);
		cet[now][rot]=cet[rot][now]=1;
	}
	for(int i=0;i<h[now].size();i++)
	{
		int y=h[now][i];
		if(y!=fa)connect_(y,now,rot,stp+1);
	}
}
void dfs(int now,int stp,int sum)
{
	if(stp==5)
	{
		if(now==1)ans=max(ans,sum);
		return ;
	}
//		cout<<ans<<' '<<sum<<endl;
	vis[now]=1;
	for(int i=0;i<g[now].size();i++)
	{
		int y=g[now][i];
		if(vis[y]==0||(y==1&&stp==4))dfs(y,stp+1,sum+a[now]);
	}
	vis[now]=0;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		if(cet[u][v]==0)
		{
			h[u].push_back(v);
			h[v].push_back(u);
			g[u].push_back(v);
			g[v].push_back(u);
			cet[u][v]=cet[v][u]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cet[i][i]=1;
		connect_(i,0,i,-1);
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<g[i].size();
//		for(int j=0;j<g[i].size();j++)
//			cout<<g[i][j]<<' ';
//			cout<<endl;
//	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
