#include <bits/stdc++.h>
using namespace std;
int n, q, k;
int v[200005], a[200005], b[200005];
int main() {
	freopen ("transmit.in", "r", stdin);
	freopen ("transmit.out", "w", stdout);
	scanf ("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; i ++) scanf ("%d", &v[i]);
	for (int i = 1; i < n; i ++) {
		scanf ("%lld %lld", &a[i], &b[i]);
	}
	for (int i = 1; i <= q; i ++) {
		int s, t;
		scanf ("%d %d", &s, &t);
		printf ("%d\n", s + t);
	}
	return 0;
}

