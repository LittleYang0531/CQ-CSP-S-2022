#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
typedef double lf;
const int nx=100010;
ll inf=LLONG_MAX-1;
inline ll read()
{
	ll x=0;
	bool f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=1;
		ch=getchar();
	}
	while('0'<=ch&&'9'>=ch)
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return f?-x:x;
}
ll A[nx],B[nx];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ll n=read(),m=read(),q=read();//printf("%d %d %d",n,m,q);
	for(int i=1;i<=n;++i)A[i]=read();
	for(int i=1;i<=m;++i)B[i]=read();
	while(q--)
	{
		int l1=read(),r1=read(),l2=read(),r2=read();
		ll ans=-inf,xb=-inf,nb=inf;
		for(int i=l2;i<=r2;++i)
		{
			nb=nb>B[i]?B[i]:nb;
			xb=xb>B[i]?xb:B[i];
		}
		for(int i=l1;i<=r1;++i)
			ans=max(ans,A[i]>0?A[i]*nb:A[i]*xb);
		printf("%lld\t",ans);
	}
	return 0;
}
