//#pragma GCC optimize(3,"Ofast","inline")
/*
Input #1
8 8 1
9 7 1 8 2 3 6 1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

Output #1
27

Input #2
7 9 0
1 1 1 2 3 4 1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

Output #2
7

*/
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fLL,maxn=2500+5;
ll n,m,k,p[maxn];
//priority_queue<ll,vector<ll,ll> >pq;
ll ksm(ll a,ll b)//肖孩子不懂事，快速幂板子打着玩的 
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
	freopen("holiday.in","r",stdin),freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<n;i++)scanf("%lld",&p[i]);
//	for(ll i=1;i<=m;i++)pq.push_back(i);
	sort(p+1,p+n+1,greater<ll>());
	printf("%lld",p[1]+p[2]+p[3]+p[4]);
	return 0;
}
