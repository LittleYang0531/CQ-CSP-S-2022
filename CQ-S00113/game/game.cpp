#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
long long a[100005], b[100005], w[1005];
long long c[1005][1005];
int main() {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	scanf ("%lld %lld %lld", &n, &m, &q);
	for (int i = 1; i <= n; i ++) scanf ("%lld", &a[i]);
	for (int i = 1; i <= m; i ++) scanf ("%lld", &b[i]);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			c[i][j] = 1LL * a[i] * b[j];
		}
	}
	while (q --) {
		long long l1, r1, l2, r2;
		scanf ("%lld %lld %lld %lld", &l1, &r1, &l2, &r2);
		for (int i = 1; i <= n; i ++) w[i] = 99999999999999999ll;
		for (int i = l1; i <= r1; i ++) {
			for (int j = l2; j <= r2; j ++) {
				w[i] = min (c[i][j], w[i]);
			}
		}
		long long mp = -99999999999999999ll, mi;
		for (int i = l1; i <= r1; i ++) {
			mp = max (mp, w[i]);
		}
		printf ("%lld\n", mp);
	}
	return 0;
}

