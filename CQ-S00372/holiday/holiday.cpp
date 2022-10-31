#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 104514114514114514ll
#define pii pair <int,int>
int n,m,k;
const int maxn=2500+5;
vector <int> G[maxn],E[maxn],T[maxn];
ll a[maxn],ans;
int p[maxn][maxn],vis[maxn];
inline bool cmp(int x,int y)	{return a[x]>a[y];}
void dfs(int u,ll s,int dep)
{
	if(dep==4)
	{
		if(p[1][u])	ans=max(s,ans);
		return ;
	}
	for(int v : E[u])
	{
		if(vis[v]||v==1)	continue;
		vis[v]=1;
		dfs(v,s+a[v],dep+1);
		vis[v]=0;
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;++i)	scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y),G[y].push_back(x);
	}
	queue <pii> que;
	for(int s=1;s<=n;++s)
	{
		while(!que.empty())	que.pop();
		for(int i=1;i<=n;++i)	vis[i]=0;
		que.push(pii(s,0));
		vis[s]=1;
		while(!que.empty())
		{
			int u=que.front().first,d=que.front().second;
			que.pop();
			if(d>k)	break;
			for(int v : G[u])
			{
				if(vis[v])	continue;
				vis[v]=1,p[s][v]=1;
				E[s].push_back(v);
				que.push(pii(v,d+1));
			}
		}
	}
	if(n<=300)
	{
		for(int i=1;i<=n;++i)	vis[i]=0;
		dfs(1,0,0);
		printf("%lld\n",ans);
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			for(int j : E[i])
			{
				if(p[1][j])	T[i].push_back(j);
			}
		}
		for(int i=1;i<=n;++i)	sort(T[i].begin(),T[i].end(),cmp);
		for(int i=2;i<=n;++i)
		{
			int sz1=T[i].size();
			if(!sz1)	continue;
			for(int j : E[i])
			{
				int sz2=T[j].size();
				if(!sz2)	continue;
				if(sz1==1&&T[i][0]==j)	continue;
				if(sz2==1&&T[j][0]==i)	continue;
				ll res=-INF;
				if(T[i][0]==j)
				{
					if(T[j][0]==i)
					{
						if(T[i][1]==T[j][1])
						{
							if(sz1>2)	res=max(res,a[T[i][2]]+a[T[j][1]]);
							if(sz2>2)	res=max(res,a[T[i][1]]+a[T[j][2]]);
						}
						else	res=max(res,a[T[i][1]]+a[T[j][1]]);
					}
					else
					{
						if(T[i][1]==T[j][0])
						{
							if(sz1>2)	res=max(res,a[T[i][2]]+a[T[i][0]]);
							if(T[j][1]!=i)	res=max(res,a[T[i][1]]+a[T[j][1]]);
							else	if(sz2>2)	res=max(res,a[T[i][1]]+a[T[j][2]]);
						}
						else	res=max(res,a[T[i][1]]+a[T[j][0]]);
					}
				}
				else
				{
					if(T[j][0]==i)
					{
						if(T[i][0]==T[j][1])
						{
							if(T[i][1]!=j)	res=max(res,a[T[i][1]]+a[T[j][1]]);
							else	if(sz1>2)	res=max(res,a[T[i][2]]+a[T[j][1]]);
							if(sz2>2)	res=max(res,a[T[i][0]]+a[T[j][2]]);
						}
						else	res=max(res,a[T[i][0]]+a[T[j][1]]);
					}
					else
					{
						if(T[i][0]==T[j][0])
						{
							if(T[i][1]!=j)	res=max(res,a[T[i][1]]+a[T[i][0]]);
							else	res=max(res,a[T[i][2]]+a[T[i][0]]);
							if(T[j][1]!=i)	res=max(res,a[T[i][0]]+a[T[j][1]]);
							else	res=max(res,a[T[i][0]]+a[T[j][2]]);
						}
						else	res=max(res,a[T[i][0]]+a[T[j][0]]);
					}
				}
				ans=max(ans,res+a[i]+a[j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*

8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1


*/
