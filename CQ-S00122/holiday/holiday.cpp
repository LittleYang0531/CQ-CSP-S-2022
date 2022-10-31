#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,v[2505],vis[2505],ch[2505][2505],ans,dis[2505][2505];
pair<int,int>f[3][2505];
struct edge
{
	int next,to;
}e[20005];
int h[2505],cnt;
void addedge(int x,int y)
{
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
void bfs(int v0)
{
	for(int i=1;i<=n;i++)vis[i]=0;
	queue<int>q;
	q.push(v0);
	vis[v0]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if(!vis[y])vis[y]=1,dis[v0][y]=dis[v0][x]+1,q.push(y);
		}
	}
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&v[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%lld %lld",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(dis[i][j]!=0 && dis[i][j]<=k+1)ch[i][j]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ch[1][j]==0 || ch[i][j]==0)continue;
			if(v[j]>f[0][i].first)f[2][i]=f[1][i],f[1][i]=f[0][i],f[0][i]={v[j],j};
			else if(v[j]>f[1][i].first)f[2][i]=f[1][i],f[1][i]={v[j],j};
			else if(v[j]>f[2][i].first)f[2][i]={v[j],j};
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(!ch[i][j])continue;
			if(f[0][i].first==0 || f[0][j].first==0)continue;
			for(int x=0;x<=2;x++)for(int y=0;y<=2;y++)if(f[x][i].second!=f[y][j].second && f[x][i].second!=j && f[y][j].second!=i && f[x][i].second!=0 && f[y][j].second!=0)ans=max(ans,f[x][i].first+f[y][j].first+v[i]+v[j]);
		}
	}
	printf("%lld",ans);
	return 0;
}
