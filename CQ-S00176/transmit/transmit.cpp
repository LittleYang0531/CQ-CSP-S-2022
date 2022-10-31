#include <bits/stdc++.h>			//Fight For 100
#define int long long
#define sf scanf
#define pf printf
const int maxn = 1005;


using namespace std;

int read () {
	int s = 0, w = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar ();
	}
	while (ch <= '9' && ch >= '0') {
		s = s * 10 + (ch - '0');
		ch = getchar ();
	}
	return s * w;
}

int fl[maxn][maxn];
int ab[maxn][maxn];
int n, q, k;

int a[maxn];

int fa[maxn];

int Find (int x) {
	if (fa[x] == x) {
		return x;
	}
	else return fa[x] = Find (fa[x]);
}

signed main () {
	freopen ("transmit.in", "r", stdin);
	freopen ("transmit.out", "w", stdout);
	for (int i = 1; i <= maxn; i ++) {
		fa[i] = i;
		for (int j = 1; j <= maxn; j ++) {
			fl[i][j] = ab[i][j] = 2 * maxn;
		}
	}
	n = read (), q = read (), k = read ();
	for (int i = 1; i <= n; i ++) a[i] = read ();
	for (int i = 1; i <= n - 1; i ++) {
		int x = read (), y = read ();
		int xx = Find (x), yy = Find (y);
		if (xx != yy) {
			if (yy < xx) fa[xx] = yy;
			else fa[yy] = xx;
		}
		ab[x][y] = ab[y][x] = fl[x][y] = fl[y][x] = 1;
		
	}
//	for (int i = 1; i < n; i ++) {
//		for (int j = 1; j < n; j ++) {
//			cout << fl[i][j] << " ";
//		}
//		puts ("");
//	}
	for (int kk = 1; kk <= n; kk ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (fl[i][kk] + fl[kk][j] < fl[i][j]) {
					fl[i][j] = fl[i][kk] + fl[kk][j];
				}
			}
		}
	}
//	for (int i = 1; i < n; i ++) {
//		for (int j = 1; j < n; j ++) {
//			cout << fl[i][j] << " ";
//		}
//		puts ("");
//	}
	while (q --) {
		int x = read (), y = read ();
		if (fl[x][y] <= k) {
			pf ("%lld\n", a[x] + a[y]);
		} else {
			int r = maxn;
//			pf ("%lld\n", min (a[Find (x)], a[Find (y)]) + a[x] + a[y]);
			int minn = maxn;
			for (int i = 1; i <= n; i ++) {
				if (i == x || i == y) {
					continue;
				}
				if (Find (i) == Find (x)) {
					minn = min (minn, a[i]);
				}
			}
			pf ("%lld\n", minn + a[x] + a[y]);
		}
	}
}

//7 3 3
//1 2 3 4 5 6 7
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//4 7
//5 6
//1 2

