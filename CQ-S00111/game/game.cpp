#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=1e4+5;
const ll INF=1e18+7;
ll n,m,q,a[MAXN],b[MAXN],c[MAXN][MAXN];

ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}


void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

ll choose(int l1,int r1,int l2,int r2)
{
	ll maxx=-INF;
	for(int i=l1;i<=r1;i++)
	{
		ll minx=INF;
		for(int j=l2;j<=r2;j++)
			minx=min(minx,c[i][j]);
		maxx=max(maxx,minx);
	}	
	return maxx;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	m=read();
	q=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	for(ll i=1;i<=m;i++) b[i]=read();
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
	while(q--)
	{
		ll l1,r1,l2,r2;
		l1=read();r1=read();
		l2=read();r2=read();
		write(choose(l1,r1,l2,r2)),putchar('\n');
	}
	return 0;
}

