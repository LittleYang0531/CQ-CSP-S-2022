#include <iostream>
using namespace std;
int n,m,q,l1,r1,l2,r2,x,y;
long long minn,maxx;
int a[50010],b[50010];
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&b[j]);
	}
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		maxx=-1e18;
		for(int i=l1;i<=r1;i++)
		{
			minn=1e18;
			for(int j=l2;j<=r2;j++)
			{
				minn=min(minn,(long long)a[i]*b[j]);
			}
			maxx=max(maxx,minn);
		}
		printf("%lld\n",maxx);
	}
	
	return 0;
}
