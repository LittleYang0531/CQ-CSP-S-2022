/*
T1:
可以预处理每个点能到哪些点
建最短路树->不用了吧 

dis[i][j][0/1/2/3/4]表示走到i,到最近一个去的景点为第0/1/2/3/4个景点，离这个景点距离为j的最大分数
f[i][j][k]转移到f[v][0][k+1]和f[v][j+1][k]

ans=f[1][j][4]
直接图上暴力走，bfs 。f有更新才入队 

时间复杂度 ：SPFA的时间复杂度乘5k？ 

bool Use[] 当前用过的 
dfs(u,k):当前景点为u，是第k个景点
更新：v,k+1  保证Use[v]=false
Use[v]=true;dfs(v,k+1);Use[v]=false

还要传递Val 
时间复杂度，假设每个点可以去到每个点
N*4*N
 
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN=2505,MAXM=1e4+5,MAXK=105;
int N,M,K;
struct Edge
{
	int x,y,Next;
}e[MAXM<<1];
int elast[MAXN],tot;
void Add(int x,int y)
{
	tot++;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].Next=elast[x];
	elast[x]=tot;
}
long long ans=0;
queue<int>q;
int vis[MAXN],Color;
int dis[MAXN];
bool Use[MAXN];
long long Val[MAXN];
long long f[MAXN][5];
bool Have[MAXN][5];
vector<int>Vec[MAXN];
bool CanGet[MAXN];
bool Suan[MAXN];
void dfs(int u,int k,long long NowVal)
{
//	cout<<u<<" "<<k<<" "<<NowVal<<endl; 
	if(Have[u][k]==false||NowVal>f[u][k])
	{
		f[u][k]=NowVal;
		
	}
	else
	{
		return;
	}
	
//	cout<<u<<" "<<k<<" "<<NowVal<<endl;
//	for(int i=1;i<=N;i++)
//	if(Use[i])
//	cout<<"Use:"<<i<<" ";
//	puts("") ;
	
	
	
	if(Suan[u]==false)
	{
		Suan[u]=true;
		Color++;
		q.push(u);
		dis[u]=0;
		vis[u]=Color;
		while(!q.empty())
		{
			int Now=q.front();Vec[u].push_back(Now);
			q.pop();
			for(int i=elast[Now];i;i=e[i].Next)
			{
				int v=e[i].y;
				if(vis[v]!=Color&&dis[Now]<=K)
				{
					vis[v]=Color;
					dis[v]=dis[Now]+1;
					q.push(v); 
					
				}
			}
		}
		if(u==1)
		{
			for(int i=0;i<Vec[u].size();i++)
			{
			//	cout<<"CanGet:"<<Vec[u][i]<<endl; 
				CanGet[Vec[u][i]]=true;
			}
		}
	}
	Have[u][k]=true; 
	if(k==4)
	{
		if(CanGet[u]&&u!=1)
		{
			ans=max(ans,NowVal);
		}
		return;
	}
	for(int i=0;i<Vec[u].size();i++)
	{
		int v=Vec[u][i];
		if(v==u)
		continue;
		if(Use[v]==false)
		{
			Use[v]=true;
			dfs(v,k+1,NowVal+Val[v]);
			Use[v]=false;
		}
	}
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	for(int i=2;i<=N;i++)
	{
		scanf("%lld",&Val[i]);
	}
	for(int i=1;i<=M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
