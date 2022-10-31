#define ll long long
#include<bits/stdc++.h>
using namespace std;
char Ch;
inline void r(ll &x)
{
	x=0;
	while((Ch=getchar())<48||Ch>57);
	while(Ch>47&&Ch<58)x*=10,x+=Ch-48,Ch=getchar();
	return;
}
ll n,m,q;
ll a[1010],b[1010];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	r(n),r(m),r(q);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int j=1;j<=m;j++)scanf("%lld",b+j);
	ll l1,r1,l2,r2;
	while(q--)
	{
		r(l1),r(r1),r(l2),r(r2);
		ll ans=-1e18;
		for(int i=l1;i<=r1;i++)
		{
			ll Min=1e18;
			for(int j=l2;j<=r2;j++)Min=min(Min,a[i]*b[j]);
			ans=max(ans,Min);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
