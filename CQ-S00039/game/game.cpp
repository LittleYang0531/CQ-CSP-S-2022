#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[10001],b[10001],c[1001][1001];
long long getmax(int l,int r,int f)
{
	long long maxn=-1e18;
	if(f)for(int i=l;i<=r;i++)maxn=max(maxn,b[i]);
	else for(int i=l;i<=r;i++)maxn=max(maxn,a[i]);
	return maxn;
}
long long getmin(int l,int r,int f)
{
	long long minn=1e18;
	if(f)for(int i=l;i<=r;i++)minn=min(minn,b[i]);
	else for(int i=l;i<=r;i++)minn=min(minn,a[i]);
	return minn;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	while(q--)
	{
		int l1,r1,l2,r2;long long ans=0;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1)
		{
			long long x=a[l1],y;
			if(x<0)
			{
				y=getmax(l2,r2,1);
			}
			else
			{
				y=getmin(l2,r2,1);
			}
			printf("%lld\n",x*y);
		}
		else if(l2==r2)
		{
			long long y=b[l2],x;
			if(y<0)
			{
				x=getmin(l1,r1,0);
			}
			else
			{
				x=getmax(l1,r1,0);
			}
			printf("%lld\n",x*y);
		}
		else
		{
			printf("%lld\n",getmax(l1,r1,0)*getmin(l2,r2,1));
		}
	}
	return 0;
}
