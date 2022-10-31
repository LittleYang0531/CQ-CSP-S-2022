#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 998244353;
constexpr int N = 1010;

i64 n, m, q;
i64 a[10010], b[10010];
i64 c[N][N];

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
i64 val[N][N << 2];
void pushup(int i, int rt) {
	val[i][rt] = std::min(val[i][rt << 1], val[i][rt << 1 | 1]);
}
void build(int i, int l, int r, int rt) {
	if (l == r) {
		val[i][rt] = c[i][l];
		return;
	}
	int mid = (l + r) / 2;
	build(i, lson);
	build(i, rson);
	pushup(i, rt);
}
i64 ask(int i, int L, int R, int l, int r, int rt) {
	if (L <= l && R >= r) {
		return val[i][rt];
	}
	int mid = (l + r) / 2;
	i64 ans = (1LL << 60);
	if (L <= mid) {
		ans = std::min(ans, ask(i, L, R, lson));
	}
	if (mid < R) {
		ans = std::min(ans, ask(i, L, R, rson));
	}
	return ans;
}


int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);	
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);	
	
	std::cin >> n >> m >> q;	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = a[i] * b[j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		build(i, 1, m, 1);
	}
	
	while (q--) {
		int l1, r1, l2, r2;
		std::cin >> l1 >> r1 >> l2 >> r2;
		i64 ans = -(1LL << 60);
		for (int i = l1; i <= r1; i++) {
			ans = std::max(ans, ask(i, l2, r2, 1, m, 1));
		}
		std::cout << ans << '\n';
	}
	
		
	return 0;
}
