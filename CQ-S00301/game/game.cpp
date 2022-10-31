//#pragma GCC optimize(3,"Ofast","inline")
/*
Input #1 
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

Output #1
0
4

Input #2 
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

Output #2
0
-2
3
2
-1

Tips #2
3 6 -3 -9
-1 -2 1 3
-2 -4 2 6
1 2 -1 -3
2 4 -2 -6
0 0 0 0

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fLL,maxn=10000+5;//为什么马晓楠二维不能取1e5+5甚至1e5？？ 
//struct node{
//	ll num,pos;
//}lm[maxn],qm[maxn];
ll n,m,q,l1,l2,r1,r2,lmax,lmin;
ll a[maxn],b[maxn],c[maxn][maxn];
//bool cmp(node x1,node x2)
//{
//	return x1.pos<x2.pos;
//}
signed main()
{
	freopen("game.in","r",stdin),freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
//	ll a[n],b[m],c[n][m];
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);//,lm[i].num=i;
	for(ll i=1;i<=m;i++)scanf("%lld",&b[i]);//,qm[i].num=i;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)c[i][j]=a[i]*b[j];
//	for(ll i=1;i<=n;i++)
//	{
//		for(ll j=1;j<=m;j++)cout<<c[i][j]<<" ";
//		puts("");
//	}
	while(q--)
	{
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2),lmax=-inf;
		for(ll i=l1;i<=r1;i++)
		{
			lmin=inf;
			for(ll j=l2;j<=r2;j++)lmin=min(c[i][j],lmin);
			lmax=max(lmin,lmax);
//			lm[i].pos=lmax+lmin;
		}
//		sort(lm+1,lm+n+1,cmp);
		printf("%lld\n",lmax);
	}
	return 0;
}
