#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,k,v[10005],tot,f[4005][4005];
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
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ll i,j,k,x,y;
	n=read();q=read();k=read();
	if (k!=1)
	{cout<<rand();return 0;}
	for (i=1;i<=n;++i)
	v[i]=read();
	for (i=1;i<n;++i)
	{
		x=read();y=read();
		f[y][x]=v[x];
		f[x][y]=v[y];
	}
	for (i=1;i<=n;++i)
	for (j=1;j<=n;++j)
	{
		if (i==j)
			continue;
		x=min(i,j),y=max(i,j);
		for (k=x+1;k<y;++k)
			if (f[i][k]+f[k][j]<f[i][j])
				f[i][j]=f[i][k]+f[k][j];
	}
	for (i=1;i<=q;++i)
	{
		x=read();y=read();
		printf("%lld\n",v[x]+f[x][y]);
	}
	return 0;
}
