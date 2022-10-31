#include <bits/stdc++.h>
using namespace std;
int n,m,q,l1,l2,r1,r2;
long long a[100005],b[100005],c[1005][1005];
int main ()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c[i][j]=a[i]*b[j];
		}
	}
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long minn=1e18,maxx=-1e18;
		for(int i=l1;i<=r1;i++)
		{
			minn=1e18;
			for(int j=l2;j<=r2;j++)
			{
				minn=min(minn,c[i][j]);
			}
			maxx=max(maxx,minn);
		}
		printf("%lld\n",maxx);
	}
	return 0;
}
