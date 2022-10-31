//POYE's Code
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int n,m,q;
ll a[100005],b[100005],c[1005][1005],pa[100005][3][20],pb[100005][3][20];
inline void Solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) c[i][j]=a[i]*b[j];
	for(int o=1;o<=q;o++)
	{
		ll ans=-2e18;
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int i=l1;i<=r1;i++)
		{
			ll minn=2e18;
			for(int j=l2;j<=r2;j++) minn=min(minn,c[i][j]);
			ans=max(ans,minn);
		}
		printf("%lld\n",ans);
	}
}

inline void ST()
{
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			pa[i][1][j]=max(pa[i][1][j-1],pa[i+(1<<j-1)][1][j-1]);
			pa[i][2][j]=min(pa[i][2][j-1],pa[i+(1<<j-1)][2][j-1]);
		}
	for(int j=1;(1<<j)<=m;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			pb[i][1][j]=max(pb[i][1][j-1],pb[i+(1<<j-1)][1][j-1]);
			pb[i][2][j]=min(pb[i][2][j-1],pb[i+(1<<j-1)][2][j-1]);
		}
}

inline ll aska(int now,int x,int y)
{
	int k=log2(y-x+1);
	if(now==1) return max(pa[x][1][k],pa[y-(1<<k)+1][1][k]);
	return min(pa[x][2][k],pa[y-(1<<k)+1][2][k]);
}

inline ll askb(int now,int x,int y)
{
	int k=log2(y-x+1);
	if(now==1) return max(pb[x][1][k],pb[y-(1<<k)+1][1][k]);
	return min(pb[x][2][k],pb[y-(1<<k)+1][2][k]);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=m;i++) scanf("%lld",b+i);
	if(n<=1000) {Solve();return 0;}
	for(int i=1;i<=n;i++) pa[i][1][0]=pa[i][2][0]=a[i];
	for(int i=1;i<=m;i++) pb[i][1][0]=pb[i][2][0]=b[i];
	ST();
	for(int o=1;o<=q;o++)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1)
		{
			if(a[l1]>=0) printf("%lld\n",askb(2,l2,r2)*a[l1]);
			else printf("%lld\n",askb(1,l2,r2)*a[l1]);
		}
		else if(l2==r2)
		{
			if(b[l2]>=0) printf("%lld\n",aska(1,l1,r1)*b[l2]);
			else printf("%lld\n",aska(2,l1,r1)*b[l2]);
		}
		else printf("%lld\n",aska(1,l1,r1)*askb(2,l2,r2));
	}

	return 0;
}
