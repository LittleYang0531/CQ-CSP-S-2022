#include<bits/stdc++.h>
using namespace std;
int dp[100005][35][7];
int n,m,q;
int a[100005],b[100005];
void init()
{
	for(int i=1;i<=n;++i)
	{
		dp[i][0][0]=a[i],dp[i][0][1]=a[i];
		if(a[i]>=0) dp[i][0][4]=a[i],dp[i][0][5]=-2e9;
		else dp[i][0][5]=a[i],dp[i][0][4]=2e9;
	}
	for(int i=1;i<=m;++i)
	{
		dp[i][0][2]=b[i],dp[i][0][3]=b[i];
	}
	for(int j=1;(1<<j)<=n;++j)
	{
		for(int i=1;i+(1<<j)-1<=n;++i)
		{
			dp[i][j][0]=max(dp[i][j-1][0],dp[i+(1<<j-1)][j-1][0]);
			dp[i][j][1]=min(dp[i][j-1][1],dp[i+(1<<j-1)][j-1][1]);
			dp[i][j][5]=max(dp[i][j-1][5],dp[i+(1<<j-1)][j-1][5]);
			dp[i][j][4]=min(dp[i][j-1][4],dp[i+(1<<j-1)][j-1][4]);
		}
	}
	for(int j=1;(1<<j)<=m;++j)
	{
		for(int i=1;i+(1<<j)-1<=m;++i)
		{
			dp[i][j][2]=max(dp[i][j-1][2],dp[i+(1<<j-1)][j-1][2]);
			dp[i][j][3]=min(dp[i][j-1][3],dp[i+(1<<j-1)][j-1][3]);
		}
	}
}
int rmq(int l,int r,int bj)
{
	int k=log2(r-l+1);
	if(bj==0||bj==2||bj==5) return max(dp[l][k][bj],dp[r-(1<<k)+1][k][bj]);
	else return min(dp[l][k][bj],dp[r-(1<<k)+1][k][bj]);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) scanf("%d",&b[i]);
	init();
	while(q--)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int no1=rmq(l1,r1,0),no2=rmq(l1,r1,1);
		int no3=rmq(l2,r2,2),no4=rmq(l2,r2,3);
		if(no4>=0)
		{
			if(no1>=0)
			printf("%lld\n",1ll*no1*no4);
			else
			printf("%lld\n",1ll*no1*no3);
		}
		else if(no3<=0)
		{
			if(no2>=0)
			printf("%lld\n",1ll*no2*no4);
			else
			printf("%lld\n",1ll*no2*no3);
		}
		else
		{
			int no5=rmq(l1,r1,5),no6=rmq(l1,r1,4);
			printf("%lld\n",max(1ll*no5*no3,1ll*no6*no4));
		}
	}
	return 0;
}

