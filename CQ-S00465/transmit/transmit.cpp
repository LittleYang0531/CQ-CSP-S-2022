/*
T4好难的样子

树上两个点，选一些点（包括端点）使得任意两个点的距离不超过K且Sumv最小

k很小，可以暴力dp的样子

先考虑k为1的情况->这条链的和，树上倍增可以做到
16分 

f[i]:必须选i的最小代价 

f[i]=min(f[j])+v[i]
j为i能在k步内到达且f已经有值的点

dis[i][j]：i到j的距离
for(int j=1;j<=N;j++)
if(vis[j])
f[i]=min(f[i],f[j]+v[i])

bfs求vis

可以做到：一个询问n^2
20分 
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e6+50;

int N,Q,K;

struct Edge
{
	int x,y,Next; 
}e[MAXN<<1];
int elast[MAXN],tot;
void Add(int x,int y)
{
	tot++;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].Next=elast[x];
	elast[x]=tot;
}
long long Val[MAXN];


int depth[MAXN],f[MAXN][21];
long long Sum[MAXN];
void dfs1(int u,int fa)//算倍增数组 
{
	Sum[u]=Sum[fa]+Val[u];
	f[u][0]=fa;
	depth[u]=depth[fa]+1;
	for(int i=1;f[f[u][i-1]][i-1];i++)
	{
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=elast[u];i;i=e[i].Next)
	{
		int v=e[i].y;
		if(v==fa)
		continue;
		dfs1(v,u);
	}
}
int GetLca(int x,int y)
{
	if(depth[x]<depth[y])
	swap(x,y);
	for(int i=18;i>=0;i--)
	{
		if(f[x][i]&&depth[f[x][i]]>=depth[y])
		{
			x=f[x][i];
		}
	}
	if(x==y)
	return x;
	for(int i=18;i>=0;i--)
	{
		if(f[x][i]&&f[y][i]&&f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
long long GetDis(int x,int y)
{
	int Lca=GetLca(x,y);
	return Sum[x]+Sum[y]-Sum[Lca]-Sum[f[Lca][0]];
}
void Solve1()
{
	dfs1(1,0);
	while(Q--)
	{
		int S,T;
		scanf("%d%d",&S,&T);
		printf("%lld\n",GetDis(S,T));
	}
 } 
int dis[2005][2005];
void dfs2(int u,int fa,int Now)
{
	for(int i=elast[u];i;i=e[i].Next)
	{
		int v=e[i].y;
		if(v==fa)
		continue;
		dis[Now][v]=dis[Now][u]+1;
		dfs2(v,u,Now);
	}
}
long long dp[MAXN];
bool vis[MAXN];
queue<int>q;
void bfs(int Begin)
{
	for(int i=1;i<=N;i++)
	vis[i]=false;
	dp[Begin]=Val[Begin];
	q.push(Begin);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u])
		continue;
		vis[u]=true;
		
		if(u!=Begin)
		{
			dp[u]=1e18;
			for(int i=1;i<=N;i++)
			{
				if(vis[i]==true&&dis[u][i]<=K)
				{
					dp[u]=min(dp[u],dp[i]+Val[u]);
				}
			}
		}
		for(int i=elast[u];i;i=e[i].Next)
		{
			int v=e[i].y;
			q.push(v);
		}
		
	}
	
}
/*
7 100 1
2 2 3 5 3 4 1
1 2
2 3
2 4
1 5
5 6
6 7
1 2
*/
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&N,&Q,&K);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&Val[i]);
	}
	for(int i=1;i<N;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	if(K==1)
	{
		Solve1();
		return 0;
	}
	for(int i=1;i<=N;i++)
	{
		dfs2(i,0,i);
	}
	while(Q--)
	{
		int S,T;
		scanf("%d%d",&S,&T);
		bfs(S);
		printf("%lld\n",dp[T]);
	}
	return 0;
}
