#include <bits/stdc++.h>
#define IOS\
	ios::sync_with_stdio(false);\
	cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

const int N = 1003;
const ll inf = 1e18;
int a[N], b[N], l, r, L, R;
ll f[N][N][10], ans, tmp;

void solve1() {
	ans = -inf;
	for (int i = l; i <= r; i++) {
		tmp = inf;
		for (int j = L; j <= R; j++) {
			tmp = min(tmp, f[i][j][0]);
		}
		ans = max(ans, tmp);
	}
	cout << ans << '\n';
}

int n, m, Q;

int main() {// 60 pts
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	IOS;
	cin >> n >> m >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
//			c[i][j] = 1ll * a[i] * b[j];
			f[i][j][0] = 1ll * a[i] * b[j];
//			cout << 
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int l = m; l >= 1; l--) {
//			f[i][l][0] = c[i][l];
			for (int x = 1; x < 10; x++) {
				if (l + (1 << x) - 1 > m) break;
				f[i][l][x] = min(f[i][l][x - 1], f[i][l + (1 << x - 1)][x - 1]);
			}
		}
	}
	while (Q--) {
		cin >> l >> r >> L >> R;
		if (r <= 200 && R <= 200) {
			solve1();
			continue;
		}
		ans = -inf;
		int k = log2(R - L + 1);
		k = k;
		for (int i = l; i <= r; i++) {
			ans = max(ans, min(f[i][L][k], f[i][R - (1 << k) + 1][k]));
		}
		cout << ans << '\n';
	}
	return 0;
}
