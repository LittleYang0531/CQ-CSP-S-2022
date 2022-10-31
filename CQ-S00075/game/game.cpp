#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	register int s = 0, f = 1;
	register char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -f; ch = getchar(); }
	while (isdigit(ch)) { s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar(); }
	return s * f;
}
const int N=100005;
int n,m,q;
ll a[N],b[N],c[1005][1005];
struct STTT {
	ll st[1005][20];
	void solve(int x) {
		for(int i=1;i<=m;i++) st[i][0]=c[x][i];
		for(int j=1;j<=15;j++) {
			for(int i=1; i+(1<<j)-1 <= m; i++) {
			    st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
 		    }
		} 	
	}
	ll query(int x,int y) {
		int k=log2(y-x+1);
		return min(st[x][k], st[y-(1<<k)+1][k]);
	}
} f[1005];
ll sta[N][20][2], stb[N][20][2];
ll querya_min(int x,int y) {
	int k=log2(y-x+1);
	return min(sta[x][k][0], sta[y-(1<<k)+1][k][0]);
}
ll querya_max(int x,int y) {
	int k=log2(y-x+1);
	return max(sta[x][k][1], sta[y-(1<<k)+1][k][1]);
}
ll queryb_min(int x,int y) {
	int k=log2(y-x+1);
	return min(stb[x][k][0], stb[y-(1<<k)+1][k][0]);
}
ll queryb_max(int x,int y) {
	int k=log2(y-x+1);
	return max(stb[x][k][1], stb[y-(1<<k)+1][k][1]);
}
void sub() {
	for(int i=1;i<=n;i++) sta[i][0][0]=sta[i][0][1]=a[i];
	for(int j=1;j<=18;j++) {
		for(int i=1; i+(1<<j)-1 <= n; i++) {
		    sta[i][j][0]=min(sta[i][j-1][0], sta[i+(1<<(j-1))][j-1][0]);
		    sta[i][j][1]=max(sta[i][j-1][1], sta[i+(1<<(j-1))][j-1][1]);
	    }
	} 	
	for(int i=1;i<=m;i++) stb[i][0][0]=stb[i][0][1]=b[i];
	for(int j=1;j<=18;j++) {
		for(int i=1; i+(1<<j)-1 <= m; i++) {
		    stb[i][j][0]=min(stb[i][j-1][0], stb[i+(1<<(j-1))][j-1][0]);
		    stb[i][j][1]=max(stb[i][j-1][1], stb[i+(1<<(j-1))][j-1][1]);
	    }
	} 
	while(q--) {
		int l1=read(),r1=read(),l2=read(),r2=read();
		if(l1==r1) {
			ll x = queryb_min(l2, r2);
			ll y = queryb_max(l2, r2);
			cout << min(a[l1]*x, a[l1]*y) << "\n";
		}
		if(l2==r2) {
			ll x = querya_min(l1, r1);
			ll y = querya_max(l1, r1);
			cout << max(b[l2]*x, b[l2]*y) << "\n";
		}
	}
}
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n=read(), m=read(), q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	if(n>1000) { sub(); return 0; }
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) c[i][j]=a[i]*b[j];
	}
 	for(int i=1;i<=n;i++) f[i].solve(i);
	while(q--) {
		int l1=read(),r1=read(),l2=read(),r2=read();
		ll ans=-1e18;
		for(int i=l1;i<=r1;i++) {
			ll t = f[i].query(l2, r2);
			if(t > ans) ans = t;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
