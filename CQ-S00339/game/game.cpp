#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q,ans;
ll a[100005],b[100005],ad[100005];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int l1,r1,l2,r2;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ll cnt=0;
		memset(ad,0x3f3f3f3f,sizeof ad);
		for(int j=l1;j<=r1;j++)
		{
			for(int k=l2;k<=r2;k++)
			{
				ad[j]=min(ad[j],(ll)a[j]*b[k]);
			}
		}
		ans=-1e18-1;
		for(int j=l1;j<=r1;j++) ans=max(ans,ad[j]);
		printf("%lld\n",ans);
	}
	return 0;
}
/*

3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
-----------
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/
