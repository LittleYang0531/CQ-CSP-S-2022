#include <bits/stdc++.h>
#define ll long long
#define wr(x,ch) write(x),putchar(ch)
using namespace std;
ll read() {
	ll x=0;
	char c=getchar();
	bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?~(x-1):x;
}
void write(ll x) {
	if(x<0) putchar('-'),x=~(x-1);
	if(x>=10) write(x/10);
	putchar(x%10^48);
}
const int N=100005,inf=1000000000;
int n,m,q,l1,r1,l2,r2,lg[N];
struct ST {
	int Min[25][N],Max[25][N];
	void init() {
		for(int i=1;(1<<i)<=n;i++) {
			for(int j=1;j+(1<<i)-1<=n;j++) {
				Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<(i-1))]);
				Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<(i-1))]);
			}
		}
	}
	int getmin(int l,int r) {
		return min(Min[lg[r-l+1]][l],Min[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
	}
	int getmax(int l,int r) {
		return max(Max[lg[r-l+1]][l],Max[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
	}
}a,b,c;
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	freopen("game4.in","r",stdin);
//	freopen("game4.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=2,j=max(n,m);i<=j;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) a.Max[0][i]=a.Min[0][i]=read(),
						  c.Max[0][i]=a.Max[0][i]<0?a.Max[0][i]:-inf,c.Min[0][i]=a.Max[0][i]>=0?a.Max[0][i]:inf;
	for(int i=1;i<=m;i++) b.Max[0][i]=b.Min[0][i]=read();
	a.init(),b.init(),c.init();
	for(int i=1;i<=q;i++) {
		l1=read(),r1=read(),l2=read(),r2=read();
		ll ans;
		int Min1=a.getmin(l1,r1),Min2=b.getmin(l2,r2),Max1=a.getmax(l1,r1),Max2=b.getmax(l2,r2);
		if(Max2<0) {
			if(Min1>=0) ans=1ll*Min1*Min2;
			else ans=1ll*Min1*Max2;
		}else if(Min2>=0) {
			if(Max1<0) ans=1ll*Max1*Max2;
			else ans=1ll*Max1*Min2;
		}else {
			if(Max1<0) ans=1ll*Max1*Max2;
			else if(Min1>=0) ans=1ll*Min1*Min2;
			else ans=max(1ll*c.getmin(l1,r1)*Min2,1ll*c.getmax(l1,r1)*Max2);
		}
		wr(ans,'\n');
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/

