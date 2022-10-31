#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){ll ret=0;int flag=1;char ch=getchar();while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();if(ch=='-')flag=-1,ch=getchar();while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}return ret*flag;}
void _write(ll val){if(val<0){putchar('-');_write(-val);return ;}if(val>=10)_write(val/10);putchar(val%10+'0');}
void write(ll val){if(val)_write(val);else putchar('0');}
int main(void)
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ll n,m,k,sum=0;
	n=read();
	m=read();
	k=read();
	for(ll i=1;i<n;i++)
	{
		sum+=read();
	}
	write(sum);
	return 0;
}
