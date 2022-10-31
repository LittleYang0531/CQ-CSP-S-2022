#include <cstdio>
#include <cstring>
const int MAXN = 1e5 + 5;

int n, m, q;
int lgg[MAXN];
int Max(int x, int y) {
	return x > y ? x : y;
}
int Min(int x, int y) {
	return x < y ? x : y;
}
struct Node {
	int maxn, minn;
	Node () {
		maxn = -0x3f3f3f3f;
		minn = 0x3f3f3f3f;
	}
	#define ls (pos << 1)
	#define rs (pos << 1 | 1)
};
struct Node1 {
	int maxn[32][MAXN], minn[32][MAXN];
	Node1() {
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < MAXN; j++) {
				maxn[i][j] = -0x3f3f3f3f;
				minn[i][j] = 0x3f3f3f3f;
			}
		}
	}
	int Query_Max(int l, int r) {
		int len = r - l + 1;
		int lggg = lgg[len];
		int a1 = maxn[lggg][l];
		int a2 = maxn[lggg][r - (1 << lggg) + 1];
		return Max(a1, a2);
	}
	int Query_Min(int l, int r) {
		int len = r - l + 1;
		int lggg = lgg[len];
		int a1 = minn[lggg][l];
		int a2 = minn[lggg][r - (1 << lggg) + 1];
		return Min(a1, a2);
	}
	void Update(int x, int k) {
		maxn[0][x] = minn[0][x] = k;
	}
	void Build(int x) {
		for (int i = 1; i <= 30; i++) {
			for (int j = 1; j <= x; j++) {
				maxn[i][j] = Max(maxn[i - 1][j], maxn[i - 1][Min(x, j + (1 << (i - 1)))]);
				minn[i][j] = Min(minn[i - 1][j], minn[i - 1][Min(x, j + (1 << (i - 1)))]);
			}
		}
	}
};
Node1 a[4], b[4];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	lgg[1] = 0;
	for (int i = 2; i <= 100000; i++) {
		lgg[i] = lgg[i / 2] + 1;
	}
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (x > 0) {
			a[1].Update(i, x);
		}
		if (x < 0) {
			a[2].Update(i, x);
		}
		if (x == 0) {
			a[3].Update(i, x);
		}
	}
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		if (x > 0) {
			b[1].Update(i, x);
		}
		if (x < 0) {
			b[2].Update(i, x);
		}
		if (x == 0) {
			b[3].Update(i, x);
		}
	}
	a[1].Build(n);
	a[2].Build(n);
	a[3].Build(n);
	b[1].Build(m);
	b[2].Build(m);
	b[3].Build(m);
	int x = 0, y = 0;
	long long L = 0, R = 0;
	for (int i = 1, l1, r1, l2, r2; i <= q; i++) {
		x = y = 0;
		L = R = 0LL;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		if (a[1].Query_Max(l1, r1) != -0x3f3f3f3f) {
			x += 1;
		}
		if (a[2].Query_Max(l1, r1) != -0x3f3f3f3f) {
			x += 2;
		}
		if (a[3].Query_Max(l1, r1) != -0x3f3f3f3f) {
			x += 4;
		}
		if (b[1].Query_Max(l2, r2) != -0x3f3f3f3f) {
			y += 1;
		}
		if (b[2].Query_Max(l2, r2) != -0x3f3f3f3f) {
			y += 2;
		}
		if (b[3].Query_Max(l2, r2) != -0x3f3f3f3f) {
			y += 4;
		}
		long long ans = 0;
		if (x == 1 && y == 1) {
			L = a[1].Query_Max(l1, r1);
			R = b[1].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 1 && y == 2) {
			L = a[1].Query_Min(l1, r1);
			R = b[2].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 1 && y == 3) {
			L = a[1].Query_Min(l1, r1);
			R = b[2].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 1 && y == 4) {
			L = R = 0;
			ans = L * R;
		}
		else if (x == 1 && y == 5) {
			L = R = 0;
			ans = L * R;
		}
		else if (x == 1 && y == 6) {
			L = a[1].Query_Min(l1, r1);
			R = b[2].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 1 && y == 7) {
			L = a[1].Query_Min(l1, r1);
			R = b[2].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 2 && y == 1) {
			L = a[2].Query_Max(l1, r1);
			R = b[1].Query_Max(l2, r2);
			ans = L * R;
		}
		else if (x == 2 && y == 2) {
			L = a[2].Query_Min(l1, r1);
			R = b[2].Query_Max(l2, r2);
			ans = L * R;
		}
		else if (x == 2 && y == 3) {
			L = a[2].Query_Max(l1, r1);
			R = b[1].Query_Max(l2, r2);
			ans = L * R;
		}
		else if (x == 2 && y == 4) {
			L = R = 0;
			ans = L * R;
		}
		else if (x == 2 && y == 5) {
			L = a[2].Query_Max(l1, r1);
			R = b[1].Query_Max(l2, r2);
			ans = L * R;
		}
		else if (x == 2 && y == 6) {
			L = R = 0;
			ans = L * R;
		}
		else if (x == 2 && y == 7) {
			L = a[2].Query_Max(l1, r1);
			R = b[1].Query_Max(l2, r2);
			ans = L * R;
		}
		else if (x == 3 && y == 1) {
			L = a[1].Query_Max(l1, r1);
			R = b[1].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 3 && y == 2) {
			L = a[2].Query_Min(l1, r1);
			R = b[2].Query_Max(l2, r2);
			ans = L * R;
		}
		else if (x == 3 && y == 3) {
			L = a[1].Query_Min(l1, r1);
			R = b[2].Query_Min(l2, r2);
			ans = L * R;
			L = a[2].Query_Max(l1, r1);
			R = b[1].Query_Max(l2, r2);
			if (L * R > ans) ans = L * R;
		}
		else if (x == 3 && y == 4) {
			ans = 0;
		}
		else if (x == 3 && y == 5) {
			ans = 0;
		}
		else if (x == 3 && y == 6) {
			ans = 0;
		}
		else if (x == 3 && y == 7) {
			L = a[1].Query_Min(l1, r1);
			R = b[2].Query_Min(l2, r2);
			ans = L * R;
			L = a[2].Query_Max(l1, r1);
			R = b[1].Query_Max(l2, r2);
			if (L * R > ans) ans = L * R;
		}
		else if (x == 4 && y == 1) {
			ans = 0;
		}
		else if (x == 4 && y == 2) {
			ans = 0;
		}
		else if (x == 4 && y == 3) {
			ans = 0;
		}
		else if (x == 4 && y == 4) {
			ans = 0;
		}
		else if (x == 4 && y == 5) {
			ans = 0;
		}
		else if (x == 4 && y == 6) {
			ans = 0;
		}
		else if (x == 4 && y == 7) {
			ans = 0;
		}
		else if (x == 5 && y == 1) {
			L = a[1].Query_Max(l1, r1);
			R = b[1].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 5 && y == 2) {
			ans = 0;
		}
		else if (x == 5 && y == 3) {
			ans = 0;
		}
		else if (x == 5 && y == 4) {
			ans = 0;
		}
		else if (x == 5 && y == 5) {
			ans = 0;
		}
		else if (x == 5 && y == 6) {
			ans = 0;
		}
		else if (x == 5 && y == 7) {
			ans = 0;
		}
		else if (x == 6 && y == 1) {
			ans = 0;
		}
		else if (x == 6 && y == 2) {
			L = a[2].Query_Min(l1, r1);
			R = b[2].Query_Max(l2, r2);
			ans = L * R;
		}
		else if (x == 7 && y == 1) {
			L = a[1].Query_Max(l1, r1);
			R = b[1].Query_Min(l2, r2);
			ans = L * R;
		}
		else if (x == 7 && y == 2) {
			L = a[2].Query_Min(l1, r1);
			R = b[2].Query_Max(l2, r2);
			ans = L * R;
		}
		else ans = 0;
		printf("%lld\n", ans);
	}
	return 0;
}
