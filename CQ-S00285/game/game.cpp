#include <iostream>
#include <cstdio>
const int nn = 1e5 + 5;
int n, m, q, a[nn], a1[nn], a2[nn], b[nn], lg[nn], sum0[nn];
struct stable {
	int st1[18][nn], st2[18][nn];
	void init(int a[], int len, int op) {
		for (int i = 1; i <= len; i++) {
			if (op && a[i] == 0) {
				st1[0][i] = 1e9;
				st2[0][i] = -1e9;
			} else st1[0][i] = st2[0][i] = a[i];
		}
		for (int i = 1; (1 << i) <= len; i++) {
			for (int j = 1; j + (1 << i) - 1 <= len; j++) {
				st1[i][j] = std::min(st1[i - 1][j], st1[i - 1][j + (1 << i - 1)]);
				st2[i][j] = std::max(st2[i - 1][j], st2[i - 1][j + (1 << i - 1)]);
			}
		}
	}
	int getmin(int l, int r) {
		int tmp = lg[r - l + 1];
		return std::min(st1[tmp][l], st1[tmp][r - (1 << tmp) + 1]);
	}
	int getmax(int l, int r) {
		int tmp = lg[r - l + 1];
		return std::max(st2[tmp][l], st2[tmp][r - (1 << tmp) + 1]);
	}
} s1, s2, t;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++) scanf("%d", b + i);
	lg[0] = -1;
	for (int i = 1; i <= n; i++) {
		lg[i] = lg[i >> 1] + 1;
		sum0[i] = sum0[i - 1] + (a[i] == 0);
		a1[i] = a[i] > 0 ? a[i] : 0;
		a2[i] = a[i] < 0 ? a[i] : 0;
	}
	s1.init(a1, n, 1); s2.init(a2, n, 1), t.init(b, m, 0);
	int l1, r1, l2, r2;
	while (q--) {
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		int mi1 = s1.getmin(l1, r1), mx1 = s1.getmax(l1, r1);
		int mi2 = s2.getmin(l1, r1), mx2 = s2.getmax(l1, r1);
		int mi = t.getmin(l2, r2), mx = t.getmax(l2, r2);
//		printf("(%d %d) (%d %d) (%d %d)\n", mi1, mx1, mi2, mx2, mi, mx);
		long long ans = sum0[r1] == sum0[l1 - 1] ? -1e18 : 0;
		if (mi1 <= mx1) {
			ans = std::max(ans, 1ll * mi1 * mi);
			ans = std::max(ans, 1ll * mx1 * mi);
		}
		if (mi2 <= mx2) {
			ans = std::max(ans, 1ll * mi2 * mx);
			ans = std::max(ans, 1ll * mx2 * mx);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
