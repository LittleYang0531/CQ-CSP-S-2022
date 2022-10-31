#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q,a[10005],b,c[10005][10005],ans1,ans;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9')
	{if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')
	{x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ll i,j,k,l1,l2,r1,r2;
	n=read();m=read();q=read();
	for (i=1;i<=n;++i)
	a[i]=read();
	for (i=1;i<=m;++i)
	{
		b=read();
		for (j=1;j<=n;++j)
		c[j][i]=a[j]*b;
	}
	for (i=1;i<=q;++i)
	{
		l1=read();r1=read();l2=read();r2=read();
		ans=-0x3f;
		for (j=l1;j<=r1;++j)
		{
			ans1=0x3f;
			for (k=l2;k<=r2;++k)
			if (ans1>c[j][k])
			ans1=c[j][k];
			if (ans<ans1)
			ans=ans1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
