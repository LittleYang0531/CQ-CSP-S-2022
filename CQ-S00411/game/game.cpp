#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
ll a[N],b[N];
ll kin1,kin2,kin11,kin12,kin21,kin22,maxn,min1,max2,minn,max1,min2,ans,l1,r1,l2,r2,q,n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q); 
	for(int i = 1;i <= n;i ++)
		scanf("%lld",&a[i]);
	for(int i = 1;i <= m;i ++)
		scanf("%lld",&b[i]);
	while(q --)
	{
		kin1 = kin2 = kin11 = kin12 = kin21 = kin22 = 0;
		min1 = max2 = -1e18,max1 = min2 = 1e18,ans = 0;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		for(int i = l1;i <= r1;i ++)
		{
			if(a[i] >= 0)kin11 = 1;
			if(a[i] < 0)kin12 = 1;
			if(kin11 && kin12)break;
		}
		kin1 = kin11+kin12;
		for(int i = l2;i <= r2;i ++)
		{
			if(b[i] >= 0)kin21 = 1;
			if(b[i] < 0)kin22 = 1;
			if(kin21 && kin22)break;
		}
		kin2 = kin21+kin22;
		if((kin2 == 1) && ((kin11 && kin21) || (kin12 && kin22)))
		{
			if(kin22 == 1)
			{
				maxn = 1e18,minn = -1e18;
				for(int i = l1;i <= r1;i ++)maxn = min(maxn,a[i]);
				for(int i = l2;i <= r2;i ++)minn = max(minn,b[i]);
			}
			else
			{
				maxn = -1e18,minn = 1e18;
				for(int i = l1;i <= r1;i ++)maxn = max(maxn,a[i]);
				for(int i = l2;i <= r2;i ++)minn = min(minn,b[i]);
			}
			ans = maxn*minn;
		}
		else
		{
			if(kin1 == 2)
			{
				for(int i = l1;i <= r1;i ++)
				{
					if(a[i] > 0)max1 = min(max1,a[i]);
					else min1 = max(min1,a[i]);
				}
				for(int i = l2;i <= r2;i ++)
				{
					if(b[i] < 0)min2 = min(min2,b[i]);
					else max2 = max(max2,b[i]);
				}
				ans = max(max1*min2,min1*max2);
			}
			else
			{
				if(kin11 == 1)
				{
					max1 = 1e18,min2 = 1e18;
					for(int i = l1;i <= r1;i ++)
						max1 = min(max1,a[i]);
					for(int i = l2;i <= r2;i ++)
					{
						if(b[i] < 0)min2 = min(min2,b[i]);
					}
					ans = max1*min2;
				}
				else
				{
					max1 = -1e18,min2 = -1e18;
					for(int i = l1;i <= r1;i ++)
						max1 = max(max1,a[i]);
					for(int i = l2;i <= r2;i ++)
					{
						if(b[i] > 0)min2 = max(min2,b[i]);
					}
					ans = max1*min2;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/
