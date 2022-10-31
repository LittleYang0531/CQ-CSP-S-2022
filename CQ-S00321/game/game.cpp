#include<bits/stdc++.h>
using namespace std;
const long long INF=1e9+5;
const long long N=1e5+5;
const long long M=1e5+5;
const long long Q=1e5+5;
long long n,m,q,l1,r1,l2,r2,flag,min1,max1,min2,max2,abs1,abs2,abs1_,abs2_,ans1,ans2;
long long a[N],b[M];
long long abss(long long x)
{
	if(x<0)
	{
		return -x;
	}
	return x;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(long long u=1;u<=q;u++)
	{
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		min1=a[l1];
		max1=a[l1];
		abs1=a[l1];
		abs1_=-INF;
		min2=b[l2];
		max2=b[l2];
		abs2=b[l2];
		abs2_=-INF;
		for(long long i=l2+1;i<=r2;i++)
		{
			max2=max(max2,b[i]);
			min2=min(min2,b[i]);
			if(abss(b[i])<abss(abs2))
			{
				abs2=b[i];
			}
		}
		for(long long i=l1+1;i<=r1;i++)
		{
			max1=max(max1,a[i]);
			min1=min(min1,a[i]);
			if(a[i]>0&&abss(a[i])<abs1)
			{
				abs1=min(ans1,a[i]);
			}
			else if(a[i]<0&&abss(a[i])<-abs1_)
			{
				abs1_=max(abs1_,a[i]);
			}
		}
		if(max2>0&&min2<0)
		{
			if(abss(min2)<abss(max2))
			{
				ans1=abs1_;
			}
			else
			{
				ans2=abs1; 
			}
			if(ans1>0)
			{
				ans2=min1;
			}
			else
			{
				ans2=max1;
			}
		}
		else if(max2>0&&min2>0)
		{
			ans1=max1;
			ans2=min2;
		}
		else if(max2<0&&min2<0)
		{
			ans1=min1;
			ans2=max2;
		}
		printf("%lld %lld %lld %lld %lld %lld\n",min1,max1,min2,max2,abs1,abs2);
		printf("%lld\n",ans1*ans2);
	}
	return 0;
}
