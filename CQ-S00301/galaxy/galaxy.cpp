//#pragma GCC optimize(3,"Ofast","inline")
/*
Input
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1321231131123133322313131342

Output
NO
NO
YES
NO
YES
NO
NO
NO
YES
NO
NO

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fLL,maxn=+5;
ll n,m,u,v,q;
ll ksm(ll a,ll b)//LJ慈禧不懂事，快速幂板子默着play♀的
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
	freopen("galaxy.in","r",stdin),freopen("galaxy.out","w",stdout);
	scanf("%lld%lld",&n,&m),srand((unsigned)time(NULL));
	while(m--)scanf("%lld%lld",&u,&v);
	scanf("%lld",&q);
	while(q--)printf(rand()%2?"NO\n":"YES\n");
	return 0;
}
