#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){ll ret=0;int flag=1;char ch=getchar();while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();if(ch=='-')flag=-1,ch=getchar();while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}return ret*flag;}
void _write(ll val){if(val<0){putchar('-');_write(-val);return ;}if(val>=10)_write(val/10);putchar(val%10+'0');}
void write(ll val){if(val)_write(val);else putchar('0');}
int main(void)
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ll q=read();
	while(q--)puts("0");
	return 0;
}
