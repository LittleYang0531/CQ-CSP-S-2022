#include <bits/stdc++.h>			//Fight For 100
#define int long long
#define sf scanf
#define pf printf
const int maxm = 0x7f7f7f7f7f7f;
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

int n, m, q;

const int maxn = 1e5 + 5;

int a[maxn], b[maxn];
int po[maxn];
int l1, r1, l2, r2;

signed main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	n = read ();
	m = read ();
	q = read ();
	for (int i = 1; i <= n; i ++) a[i] = read ();
	for (int i = 1; i <= m; i ++) b[i] = read ();
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= m; j ++) {
//			c[i][j] = a[i] * b[j];
//		}
//	}
	
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= m; j ++) {
//			cout << c[i][j] << " ";
//		}
//		cout << endl;
//	}
	if (n >= 1000) {
		for (int l = 1; l <= q; l ++) {
			l1 = read (), r1 = read (), l2 = read (), r2 = read ();
			pf ("%lld\n", a[l1] * b[l2]);
		}
		return 0;
	}
	for (int l = 1; l <= q; l ++) {
		l1 = read (), r1 = read (), l2 = read (), r2 = read ();
		int max1 = -maxm, max2 = - max1;
		int id1, id2;
		for (int i = l1; i <= r1; i ++) {
			int minn = maxm;
			for (int j = l2; j <= r2; j ++) {
				minn = min (minn, a[i] * b[j]);
			}
			po[i] = minn;
		}
		for (int i = l1; i <= r1; i ++) {
			if (po[i] >= max1) {
				max1 = po[i];
				id1 = i;
			}
		}
		int minn = maxm;
		for (int j = l2; j <= r2; j ++) {
			minn = min (minn, a[id1] * b[j]);
//			cout << "MIOJ" << endl;
		}
		pf ("%lld\n", minn);
	}
}


