#include <cstdio>
#define int long long
const int MAXN = 1e5 + 5, INF = 1e18;
int n, m, q;
int a[MAXN][2];
struct Node {
	int l, r;
	int minv, maxv;
} t[MAXN << 4][3];
int max(int x, int y) {
	return x > y ? x : y;
}
int min(int x, int y) {
	return x < y ? x : y; 
}
inline void read(int& x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar(); 
	}
	x *= f;
}
void build(int d, int p, int l, int r) {
	t[p][d].l = l, t[p][d].r = r;
	t[p << 1][d].maxv = -INF, t[p << 1][d].minv = INF;
	t[p << 1 | 1][d].maxv = -INF, t[p << 1 | 1][d].minv = INF;
	if (l == r) {
		t[p][d].maxv = t[p][d].minv = a[l][d];
		return ;
	}
	int mid = (l + r) >> 1;
	build(d, p << 1, l, mid);
	build(d, p << 1 | 1, mid + 1, r);
	t[p][d].maxv = max(t[p << 1][d].maxv, t[p << 1 | 1][d].maxv);
	t[p][d].minv = min(t[p << 1][d].minv, t[p << 1 | 1][d].minv);
}
int query_max(int d, int p, int l, int r) {
	if (!p)
		return -INF;
	if (t[p][d].l > r || t[p][d].r < l)
		return -INF;
	if (l <= t[p][d].l && t[p][d].r <= r)
		return t[p][d].maxv;
	int res = max(query_max(d, p << 1, l, r), query_max(d, p << 1 | 1, l, r));
	return res;
}
int query_min(int d, int p, int l, int r) {
	if (!p)
		return INF;
	if (t[p][d].l > r || t[p][d].r < l)
		return INF;
	if (l <= t[p][d].l && t[p][d].r <= r)
		return t[p][d].minv;
	int res = min(query_min(d, p << 1, l, r), query_min(d, p << 1 | 1, l, r));
	return res;
}
void print(int x) {
	if (x < 0) {
		putchar('-'), print(-x);
		return ;
	}
	if (x > 10)
		print(x / 10);
	putchar(x % 10 + '0');
}
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		read(a[i][0]);
		if (a[i][0] <= 0)
			flag = 0;
	}
	for (int i = 1; i <= m; i++) {
		read(a[i][1]);
		if (a[i][1] <= 0)
			flag = 0;
	}
	build(0, 1, 1, n);
	build(1, 1, 1, m);
	while (q--) { 
		int l1, r1, l2, r2;
		read(l1), read(r1), read(l2), read(r2);
		int x, y, x1, y1;
		x = query_max(0, 1, l1, r1), y = query_max(1, 1, l2, r2);
		x1 = query_min(0, 1, l1, r1), y1 = query_min(1, 1, l2, r2);
		if (l1 == r1)
			print(min(a[l1][0] * y, a[l1][0] * y1)), putchar('\n');
		else if (l2 == r2)
			print(max(a[l2][1] * x, a[l2][1] * x1)), putchar('\n');
		else if (flag) {
			print(x * y1), putchar('\n');
		} else {
			int ans = -INF;
			for (int i = l1; i <= r1; i++) {
				int res = min(a[i][0] * y, a[i][0] * y1);
				ans = max(ans, res);
			}
			print(ans), putchar('\n');
		}
	}
	return 0;
}
/*
2 -2
2 -3
*/ 
