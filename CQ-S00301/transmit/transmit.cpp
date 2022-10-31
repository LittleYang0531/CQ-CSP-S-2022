//#pragma GCC optimize(3,"Ofast","inline")
/*
Input


Output


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fLL,maxn=200000+5;
struct node{
	ll a,b;
}cp[maxn];
ll n,q,k,v[maxn],s,t;
ll ksm(ll a,ll b)//Kevin不懂事，快速幂板子抽着van♂的 
{
	ll ans=1;
	while(b)
	{
		if(b%2)ans*=a;
		a*=a,b/=2;
	}
	return ans;
}
signed main()
{
	freopen("transmit.in","r",stdin),freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(ll i=1;i<=n;i++)scanf("%lld",&v[i]);
	for(ll i=1;i<n;i++)scanf("%lld%lld",&cp[i].a,&cp[i].b);
	while(q--)
	{
		scanf("%lld%lld",&s,&t);
		for(ll i=1;i<n;i++)
		{
			if((cp[i].a==s&&cp[i].b==t)||(cp[i].b==s&&cp[i].a==t))
			{
				printf("%lld\n",v[s]+v[t]);
				break;
			}
		}
	}
	return 0;
}
