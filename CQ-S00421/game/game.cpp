#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimze(Ofast,inline)
using namespace std;
ll read(){ll ret=0;int flag=1;char ch=getchar();while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();if(ch=='-')flag=-1,ch=getchar();while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}return ret*flag;}
void _write(ll val){if(val<0){putchar('-');_write(-val);return ;}if(val>=10)_write(val/10);putchar(val%10+'0');}
void write(ll val){if(val)_write(val);else putchar('0');}
ll a[100002];
ll b[100002];
ll C(ll x,ll y)
{
	return a[x]*b[y];
}
int main(void)
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ll n,m,q;
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++){a[i]=read();}
	for(int i=1;i<=m;i++){b[i]=read();}
	for(int i=0;i<q;i++)
	{
		ll l1,r1,l2,r2,L,R;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ll mx=-1000000,mi=LLONG_MAX,pos1=-1,pos2=-1;
		for(int j=l2;j<=r2;j++)
		{
			if(b[j]<mi)mi=b[j],pos2=j;
		}
		for(int j=l1;j<=r1;j++)
		{
			if(a[j]>mx)mx=a[j],pos1=j;
		}
		
		write(C(pos1,pos2));
		putchar('\n');
	}	
	return 0;
}
