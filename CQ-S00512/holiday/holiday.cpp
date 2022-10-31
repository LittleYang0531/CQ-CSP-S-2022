#include <bits/stdc++.h>
#define IOS\
	ios::sync_with_stdio(false);\
	cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
const ll inf = 4e18;
const int N = 2505, V = 1e7;

ll val[N];
int g[N][N], n, m, K, f[N][4];
vector<int> b;

ll calc(int x, int y) {
	ll res = 0;
	for (int i = 1; i <= 3; i++) {
		if (!f[x][i]) continue;
		for (int j = 1; j <= 3; j++) {
			if (!f[y][j]) continue;
			if (f[x][i] != f[y][j] && f[x][i] != y && f[y][j] != x) {
				res = max(res, val[f[x][i]] + val[f[y][j]]);
			}
		}
	}
	return res ? res + val[x] + val[y] : res;
}

void bao() {// 70 pts
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = V;
		}
		g[i][i] = 0;
	}
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		g[x][y] = g[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << i << " " << j << " " << g[i][j] << '\n';
		}
	}*/
	K++;
	for (int i = 2; i <= n; i++) {
		if (g[1][i] <= K) {
//			vis[i] = 1;
			b.push_back(i);
//			cout << i << " ";
		}
	}
//	cout << '\n';
	for (int i = 2; i <= n; i++) {
		for (auto u : b) {
			if (g[u][i] > K || u == i) {
				continue;
			}
			if (val[u] > val[f[i][1]]) {
				f[i][3] = f[i][2];
				f[i][2] = f[i][1];
				f[i][1] = u;
			}
			else if (val[u] > val[f[i][2]]) {
				f[i][3] = f[i][2];
				f[i][2] = u;
			}
			else if (val[u] > val[f[i][3]]) {
				f[i][3] = u;
			}
		}
	}
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == j || g[i][j] > K) continue;
			ans = max(ans, calc(i, j));
		}
	}
	cout << ans;
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
//	freopen("data.in", "r", stdin);
	IOS;
	cin >> n >> m >> K;
	for (int i = 2; i <= n; i++) {
		cin >> val[i];
	}
	if (n <= 300) {
		bao();
		return 0;
	}
	return 0;
}
