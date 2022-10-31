#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
int point[114514];
int a[1005][1005];
int dp[10500];
int maxx=-0x7ffffff;
void dfs(int num,int ans,int u)//num:当前的值 ans:已经搜了几个点了 u:当前搜点 
{
	if(ans==4)
	{
		maxx=max(num,maxx);
		return;
	}
	int dq=0,p;
	for(int i=2;i<=n;i++)
	{
		if(a[u][i]==true)
		{
			dq=point[i],p=i;
			dfs(num+dq,ans+1,p);
		}
	 } 
	 return;
}
int main()
{//和上午一样，AFO了~
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);//O(n^4)暴力跑路 
	for(int i=2;i<=n;i++)
	{
		cin>>point[i];
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u][v]=1;
	}
	dfs(0,0,2);
	cout<<maxx;
	return 0;
}

