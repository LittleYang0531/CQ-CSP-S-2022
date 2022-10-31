#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pt printf
#define IL inline
using namespace std;
IL int _() {
	int x=0,f=0;char ch=gc();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}
IL void __(int x) {
	int stk[30],tp=0;
	if(x<0) x=-x,pc('-');
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp) pc(stk[tp--]^48);
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	return 0;
}
