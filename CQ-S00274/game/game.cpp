#include<bits/stdc++.h>
#define maxn 100015
#define L long long
using namespace std;
int n,m,q;
L a[maxn],b[maxn];
L l[maxn],r[maxn],ll[maxn],rr[maxn];
int pt1=1;
int pt2=1;
inline void baoli()
{
	for (int i=1; i<=q; i++)
	{
		L sl=l[i];
		L sr=r[i];
		L sll=ll[i];
		L srr=rr[i];
		L maxx=-LONG_LONG_MAX;
		for (int j=sl; j<=sr; j++)
		{
			L suma=a[j];
			L minn=LONG_LONG_MAX;
			for (int t=sll; t<=srr; t++)
			{
				L sumb=b[t];
				minn = min(minn,sumb*suma);
			}
			maxx = max(maxx,minn);
		}
		printf("%lld\n",maxx);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		if (a[i]<=0)
			pt1 = 0;
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%lld",&b[i]);
		if (b[i]<=0)
			pt1 = 0;
	}
	for (int i=1; i<=q; i++)
	{
		scanf("%lld%lld%lld%lld",&l[i],&r[i],&ll[i],&rr[i]);
		if (l[i]!=r[i] && ll[i]!=rr[i])
			pt2 = 0;
	}
	baoli();
	return 0;
}
