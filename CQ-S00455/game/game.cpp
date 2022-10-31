#include <cstdio>
#include <algorithm>

int Log[100005];
template<typename comp> struct RMQ {
	int st[18][100005], n;
	comp tmp;
	void init(int *a, int _n) {
		n = _n;
		for (int i = 1; i <= n; ++ i) st[0][i] = a[i];
		for (int i = 1; i <= 17; ++ i)
		for (int j = 1; j + (1 << i) - 1 <= n; ++ j)
			st[i][j] = tmp(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	}
	inline int operator () (int l, int r) {
		int k = Log[r - l + 1];
		return tmp(st[k][l], st[k][r - (1 << k) + 1]);
	}
};
struct mymax {
	inline int operator () (const int x, const int y) {return x > y ? x : y;}
};
struct mymin {
	inline int operator () (const int x, const int y) {return x < y ? x : y; }
};
int a[100005], b[100005], c[100005], d[100005];
RMQ<mymax> allmax_a, negative_a, allmax_b;
RMQ<mymin> allmin_a, positive_a, allmin_b;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 2; i <= n || i <= m; ++ i) Log[i] = Log[i >> 1] + 1; 
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", a + i);
		if (a[i] >= 0) c[i] = a[i], d[i] = -2e9;
		else d[i] = a[i], c[i] = 2e9;
	}
	for (int i = 1; i <= m; ++ i) scanf("%d", b + i);
	allmax_a.init(a, n), allmin_a.init(a, n);
	allmax_b.init(b, m), allmin_b.init(b, m);
	positive_a.init(c, n), negative_a.init(d, n);
	while (q --) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int mx = allmax_b(l2, r2), mn = allmin_b(l2, r2);
		if (mx >= 0 && mn >= 0) {
			int t = allmax_a(l1, r1);
			printf("%lld\n", t > 0 ? 1ll * t * mn : 1ll * t * mx);
		} else if (mx >= 0 && mn < 0) {
			long long ans = -9e18;
			int t1 = positive_a(l1, r1), t2 = negative_a(l1, r1);
			if (t1 < 0x3f3f3f3f) ans = std::max(ans, 1ll * mn * t1);
			if (t2 > -0x3f3f3f3f) ans = std::max(ans, 1ll * mx * t2);
			printf("%lld\n", ans);
		} else {
			int t = allmin_a(l1, r1);
			printf("%lld\n", t > 0 ? 1ll * t * mn : 1ll * t * mx);
		}
	}
	return 0;
}
