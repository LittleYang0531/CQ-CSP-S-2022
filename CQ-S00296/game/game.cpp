#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define int long long
#define MAXN 100005

template <typename T> inline void read (T &x){x = 0;char c = getchar ();int f = 1;while(!isdigit (c)) f*= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T,typename ... Args> inline void read (T &x,Args& ... args){read (x),read (args...);}
template <typename T> inline void write (T x){if (x < 0) putchar ('-'),x = -x;if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

int n,m,q,A[MAXN],B[MAXN],pa[MAXN],pb[MAXN],lg[MAXN];

struct node{
	int N,s[MAXN],st[5][MAXN][21];
	int query (int t,int l,int r){
		int k = lg[r - l + 1];
		if (t == 1 || t == 3) return min (st[t][l][k],st[t][r - (1 << k) + 1][k]);
		else return max (st[t][l][k],st[t][r - (1 << k) + 1][k]);
	}
	void init (){
		for (Int i = 1;i <= N;++ i)
			st[1][i][0] = (s[i] < 0 ? s[i] : 1e18),st[2][i][0] = (s[i] < 0 ? s[i] : -1e18),
			st[3][i][0] = (s[i] > 0 ? s[i] : 1e18),st[4][i][0] = (s[i] > 0 ? s[i] : -1e18);
		for (Int j = 1;(1 << j) <= N;++ j)
			for (Int i = 1;i + (1 << j) - 1 <= N;++ i)
				st[1][i][j] = min (st[1][i][j - 1],st[1][i + (1 << j - 1)][j - 1]),
				st[2][i][j] = max (st[2][i][j - 1],st[2][i + (1 << j - 1)][j - 1]),
				st[3][i][j] = min (st[3][i][j - 1],st[3][i + (1 << j - 1)][j - 1]),
				st[4][i][j] = max (st[4][i][j - 1],st[4][i + (1 << j - 1)][j - 1]);
	}
}sa,sb;

signed main(){
	freopen ("game.in","r",stdin);
	freopen ("game.out","w",stdout);
	read (n,m,q),sa.N = n,sb.N = m;
	for (Int i = 2;i <= max (n,m);++ i) lg[i] = lg[i >> 1] + 1;
	for (Int i = 1;i <= n;++ i) read (A[i]),sa.s[i] = A[i],pa[i] = pa[i - 1] + (A[i] == 0);
	for (Int i = 1;i <= m;++ i) read (B[i]),sb.s[i] = B[i],pb[i] = pb[i - 1] + (B[i] == 0);
	sa.init (),sb.init();
	while (q --> 0){
		int l1,r1,l2,r2;read (l1,r1,l2,r2);
		int ans = -1e18;
		if (pa[r1] != pa[l1 - 1]) ans = 0;
		for (Int i = 1;i <= 4;++ i){
			int v = sa.query (i,l1,r1);
			if (abs(v) == 1e18) continue;
			int now = 1e18;
			if (pb[r2] != pb[l2 - 1]) now = 0;
			for (Int j = 1;j <= 4;++ j){
				int v1 = sb.query (j,l2,r2);
				if (abs(v1) == 1e18) continue;
				chkmin (now,v * v1);
			}
			chkmax (ans,now);
		}
		write (ans),putchar ('\n');
	}
	return 0;
}

