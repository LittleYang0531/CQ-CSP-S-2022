#include<bits/stdc++.h>
#define N 1005
#define int long long
using namespace std;
int n,m,q,a[N],b[N],c[N][N],lg[N];
int mn[N][N][11];
int ask(int i,int l,int r)
{
	int len=lg[r-l+1];
	return min(mn[i][l][len],mn[i][r-(1<<len)+1][len]);
}
inline int re()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	lg[1]=0;
	for(int i=2;i<=1000;i++) lg[i]=lg[i/2]+1;
	n=re(),m=re(),q=re();
	for(int i=1;i<=n;i++) a[i]=re();
	for(int i=1;i<=m;i++) b[i]=re();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) c[i][j]=a[i]*b[j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) mn[i][j][0]=c[i][j];
		for(int k=1;(1<<k)<=n;k++)
			for(int j=1;j+(1<<k)-1<=n;j++)
				mn[i][j][k]=min(mn[i][j][k-1],mn[i][j+(1<<(k-1))][k-1]);
	}
	for(int l1,r1,l2,r2;q--;)
	{
		l1=re(),r1=re(),l2=re(),r2=re();
		int res=-1e18;
		for(int i=l1;i<=r1;i++) res=max(res,ask(i,l2,r2));
		printf("%lld\n",res);
	}
	return 0;
}
/*
d**kwish       \
hhpq			\
push_and_knock   \
junkfood 		  \
multiset		   \				
horse               \                   Orz
chicken(unrated)    /
stasis             /
jason_sun         /
rxm              /
geng            /
captainWei     /
soup          /
*/
