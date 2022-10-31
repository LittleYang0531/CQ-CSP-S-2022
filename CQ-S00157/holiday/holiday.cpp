#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long a[10005];
int b[2505][2505],c[10];
long long dp[2505][6][105]; //存最大值 
int d[10];//已经选择的地点 
void dfs(int w1,int w2,int w3)//当前地点序号，当前已选择数量,当前转车次数； 
{
	if(w2>=5)
	return;
	if(w3>=k+1)
	return;
	if(w2<4)
	for(int i=1;i<=n;i++)//i是预选地点序号 
	{
		if(b[w1][i]==1)
		{
			if(dp[i][w2][w3+1]<=dp[w1][w2][w3])
			{
				dp[i][w2][w3+1]=dp[w1][w2][w3];
				dfs(i,w2,w3+1);
			}
			if(dp[i][w2+1][0]<dp[w1][w2][w3]+a[i]&&d[w2]!=i&&d[w2-1]!=i&&d[w2-2]!=i&&d[w2-3]!=i)
			{
				dp[i][w2+1][0]=dp[w1][w2][w3]+a[i];
				d[w2+1]=i;
				dfs(i,w2+1,0);
				d[w2+1]=0;
			}
		}
	}
	if(w2==4)
	for(int i=1;i<=n;i++)//i是预选地点序号 
	{
		if(b[w1][i]==1)
		{
			if(i==1)
			{
				if(dp[1][5][0]<dp[w1][w2][w3])
				{
					dp[1][5][0]=dp[w1][w2][w3];
				}
			}
			else
			if(dp[i][w2][w3+1]<dp[w1][w2][w3])
			{
				dp[i][w2][w3+1]=dp[w1][w2][w3];
				dfs(i,w2,w3+1);
			}			
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	d[0]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		b[x][y]=1;
		b[y][x]=1;
	}
	dfs(1,0,0);
	cout<<dp[1][5][0]<<endl;
	return 0;
}
