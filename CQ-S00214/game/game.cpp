#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 1e9 + 1;
const long long INF_ = 1ll * INF * INF;

int n[2], q, f[11][20][N], lg[N], a[2][N];
int l[2], r[2];

inline int g(int x, int t) {
	int l_ = l[x], r_ = r[x], id = t + x * 5;
	int len = lg[r_ - l_ + 1];
	if (id == 1 || id == 3 || id == 4 || id == 6 || id == 8 || id == 9) return max(f[id][len][l_], f[id][len][r_ - (1 << len) + 1]);
	else return min(f[id][len][l_], f[id][len][r_ - (1 << len) + 1]);
}

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n[0] = read(), n[1] = read(), q = read();
	for (int id = 0; id <= 1; id++)
		for (int i = 1; i <= n[id]; i++) {
			a[id][i] = read();
			f[1 + id * 5][0][i] = a[id][i] > 0 ? a[id][i] : -INF;
			f[2 + id * 5][0][i] = a[id][i] > 0 ? a[id][i] : INF;
			f[3 + id * 5][0][i] = a[id][i] == 0;
			f[4 + id * 5][0][i] = a[id][i] < 0 ? a[id][i] : -INF;
			f[5 + id * 5][0][i] = a[id][i] < 0 ? a[id][i] : INF;
		}
	lg[0] = -1;
	for (int i = 1; i <= max(n[0], n[1]); i++) lg[i] = lg[i >> 1] + 1;
	for (int id = 0; id <= 1; id++)
		for (int len = 1; 1 << len <= n[id]; len++)
			for (int i = 1; i + (1 << len) - 1 <= n[id]; i++) {
				f[1 + id * 5][len][i] = max(f[1 + id * 5][len - 1][i], f[1 + id * 5][len - 1][i + (1 << len - 1)]);
				f[2 + id * 5][len][i] = min(f[2 + id * 5][len - 1][i], f[2 + id * 5][len - 1][i + (1 << len - 1)]);
				f[3 + id * 5][len][i] = f[3 + id * 5][len - 1][i] | f[3 + id * 5][len - 1][i + (1 << len - 1)];
				f[4 + id * 5][len][i] = max(f[4 + id * 5][len - 1][i], f[4 + id * 5][len - 1][i + (1 << len - 1)]);
				f[5 + id * 5][len][i] = min(f[5 + id * 5][len - 1][i], f[5 + id * 5][len - 1][i + (1 << len - 1)]);
			}
	while (q--) {
		l[0] = read(), r[0] = read(), l[1] = read(), r[1] = read();
		long long ans = -INF_;
		for (int i = 1; i <= 5; i++) {
			if (i == 3) continue;
			long long res = INF_;
			for (int j = 1; j <= 5; j++) {
				if (j == 3) continue;
				int x = g(0, i), y = g(1, j);
				if (x != INF && y != INF && x != -INF && y != -INF) res = min(res, 1ll * x * y);
			}
			if (res != INF_) ans = max(ans, res);
		}
		if (ans < 0 && g(0, 3)) ans = 0;
		if (ans > 0 && g(1, 3)) ans = 0;
		printf("%lld\n", ans);
	} // Hopefully I can AC.
	// 延续一下去年传统，祝大家以梦为马，不负韶华（） 
	return 0;
}
