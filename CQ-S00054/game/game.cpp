#include<bits/stdc++.h>
using namespace std;
int n,m,q,l1,l2,r1,r2;
long long a[100005],b[100005];
long long rmqamaxx[20][100005],rmqaminn[20][100005],rmqa1[20][100005],rmqa2[20][100005];
long long rmqbmaxx[20][100005],rmqbminn[20][100005];
void pre()
{
	for(int i=1;i<=n;i++)rmqamaxx[0][i]=rmqaminn[0][i]=a[i];
	for(int i=1;i<=log2(n);i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			rmqamaxx[i][j]=max(rmqamaxx[i-1][j],rmqamaxx[i-1][j+(1<<(i-1))]);
			rmqaminn[i][j]=min(rmqaminn[i-1][j],rmqaminn[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=1;i<=m;i++)rmqbmaxx[0][i]=rmqbminn[0][i]=b[i];
	for(int i=1;i<=log2(m);i++)
	{
		for(int j=1;j+(1<<i)-1<=m;j++)
		{
			rmqbmaxx[i][j]=max(rmqbmaxx[i-1][j],rmqbmaxx[i-1][j+(1<<(i-1))]);
			rmqbminn[i][j]=min(rmqbminn[i-1][j],rmqbminn[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)rmqa1[0][i]=a[i];
		else rmqa1[0][i]=0x7fffffff;
	}
	for(int i=1;i<=log2(n);i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)rmqa1[i][j]=min(rmqa1[i-1][j],rmqa1[i-1][j+(1<<(i-1))]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=0)rmqa2[0][i]=a[i];
		else rmqa2[0][i]=-0x7fffffff;
	}
	for(int i=1;i<=log2(n);i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)rmqa2[i][j]=max(rmqa2[i-1][j],rmqa2[i-1][j+(1<<(i-1))]);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++)scanf("%lld",b+i);
	pre();
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int k=log2(r1-l1+1);
		long long minn1=min(rmqaminn[k][l1],rmqaminn[k][r1-(1<<k)+1]),maxx1=max(rmqamaxx[k][l1],rmqamaxx[k][r1-(1<<k)+1]);
		int k1=log2(r2-l2+1);
		long long minn2=min(rmqbminn[k1][l2],rmqbminn[k1][r2-(1<<k1)+1]),maxx2=max(rmqbmaxx[k1][l2],rmqbmaxx[k1][r2-(1<<k1)+1]);
		if((minn1>=0&&minn2>=0)||(minn1<=0&&maxx1>=0&&minn2>=0))printf("%lld\n",maxx1*minn2);
		else if(minn1>=0)printf("%lld\n",minn1*minn2);
		else if(maxx2<=0)printf("%lld\n",minn1*maxx2);
		else if(maxx1<=0)printf("%lld\n",maxx1*maxx2);
		else{
			long long s=min(rmqa1[k][l1],rmqa1[k][r1-(1<<k)+1]);
			long long t=max(rmqa2[k][l1],rmqa2[k][r1-(1<<k)+1]);
			printf("%lld\n",max(s*minn2,t*maxx2));
		}
	}
	return 0;
}
