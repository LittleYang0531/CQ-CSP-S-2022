#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL unsigned long long
#define N 10005
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
LL s[N],ans;
int n,m,k;
vector<int> e[N];
bool vis[N];
void dfs(int u,LL sum,int step)
{
	if(step>5)
	{
		if(u==1)
		{
			ans=max(ans,sum);
		}
		return;
	}
	if(vis[u])
	{
		return;
	}
	vis[u]=1;
	for(auto v:e[u])
	{
		dfs(v,sum+s[v],step+1);
	}
}
void solve()
{
	dfs(1,0,1);
}
int main() 
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v;
	for(int i=2;i<=n;i++)
	{
		scanf("%llu",&s[i]);
	}
	while(m--)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(!k)
	{
		solve();
		printf("%llu\n",ans);
	}
	return 0;
}

