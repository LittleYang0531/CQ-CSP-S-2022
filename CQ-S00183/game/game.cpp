#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
long long n,m,q;
long long c[5005][5005]={0};
long long a[MAXN]={0},b[MAXN]={0};
long long maxxx(long long x,long long y)
{
	if(x>y)return x;
	return y;
}
long long minnn(long long x,long long y)
{
	if(x>y)return y;
	return x;
}
int main()
{
	//貌似线段树？懒得写了，写个暴力跑路 
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c[i][j]=a[i]*b[j];
		}
	}

	while(q--)
	{
		long long p=0;
		long long l1,l2,r1,r2,L2=0x7fffffffffffffff;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		long long maxx=-0x7fffffffff;
		for(long long i=l1;i<=r1;i++)
		{
			long long minn=0x7fffffffffffffff;
			for(long long j=l2;j<=r2;j++)
			{
				minn=minnn(c[i][j],minn);
			}
			if(maxx<minn)
			{
				p=i;
				maxx=minn;
			}	
		}
		for(long long i=l2;i<=r2;i++)
		{
			 L2=min(L2,c[p][i]); 
		}
		cout<<L2<<endl;
	}
	/*
		orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
		orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
		orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
		orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
		x_kai保佑我 x_kai保佑我 x_kai保佑我 x_kai保佑我 x_kai保佑我 x_kai保佑我 x_kai保佑我 x_kai保佑我 
	*/
	return 0;
}

