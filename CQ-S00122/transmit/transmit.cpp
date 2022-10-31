#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,k,v[200005],f[200005],p[200005][25],d[200005];
struct edge
{
	int next,to;
}e[400005];
int h[200005],cnt;
void addedge(int x,int y)
{
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
bool vis[200005],flag,vv[200005];
int st[200005],top,dis[2005][2005];
void dfs0(int v0,int x,int prt)
{
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==prt)continue;
		dis[v0][y]=dis[v0][x]+1;
		dfs0(v0,y,x);
	}
}
void dfs(int x,int goal)
{
	st[++top]=x;
	vis[x]=1;
	if(x==goal){flag=1;return ;}
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(vis[y])continue;
		dfs(y,goal);
		if(flag)return ;
	}
	top--;
}
void dfs1(int x,int prt)
{
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(vv[y] || y==prt)continue;
		for(int j=1;j<=n;j++)if(dis[y][j]<=k)f[y]=min(f[y],f[j]+v[y]);
		dfs(y,x);
	}
}
void dfs_pre(int x,int prt)
{
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==prt)continue;
		p[y][0]=x;
		d[y]=d[x]+1;
		v[y]+=v[x];
		dfs_pre(y,x);
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	for(int i=20;i>=0;i--)if(d[x]-d[y]>=(1<<i))x=p[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(p[x][i]!=p[y][i])x=p[x][i],y=p[y][i];
	return p[x][0];
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld %lld %lld",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld %lld",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	if(k==1)
	{
		dfs_pre(1,0);
		for(int j=1;(1<<j)<=n;j++)for(int i=1;i<=n;i++)if(p[i][j-1])p[i][j]=p[p[i][j-1]][j-1];
		while(q--)
		{
			int x,y;
			scanf("%lld %lld",&x,&y);
			int l=lca(x,y);
			printf("%lld\n",v[x]+v[y]-v[l]-v[p[l][0]]);
		}
		return 0;
	}
	if(n<=2e3 && q<=2e3)
	{
		for(int i=1;i<=n;i++)dfs0(i,i,0);
		while(q--)
		{
			int x,y;
			scanf("%lld %lld",&x,&y);
			for(int i=1;i<=n;i++)vis[i]=0,f[i]=4e18,st[i]=0,vv[i]=0;
			top=0;
			flag=0;
			dfs(x,y);
			f[st[1]]=v[st[1]];
			for(int i=1;i<=top;i++)vv[st[i]]=1;
			for(int i=2;i<=top;i++)
			{
				for(int j=1;j<=n;j++)if(dis[st[i]][j]<=k)f[st[i]]=min(f[st[i]],f[j]+v[st[i]]);
				dfs1(st[i],0);
			}
			printf("%lld\n",f[st[top]]);
		}
		return 0;
	}
	return 0;
}
