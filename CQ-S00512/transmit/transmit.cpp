#include <bits/stdc++.h>
#define IOS\
	ios::sync_with_stdio(false);\
	cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
const int N = 2003;
int f[N][12], dep[N], n, m, val[N], k;
vector<int> e[N];

void dfs(int u, int dad) {
	dep[u] = dep[dad] + 1;
	f[u][0] = dad;
	for (int i = 1; i <= 11; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for (auto v : e[u]) {
		if (v != dad) {
			dfs(v, u);
		}
	}
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) {
		swap(x, y);
	}
	for (int i = 11; i >= 0; i--) {
		if (dep[x] <= dep[f[y][i]]) {
			y = f[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 11; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i], y = f[y][i];
		}
	}
	return f[x][0];
}

int a[N];
ll g[N];

void calc() {
	ll res = 0;
	if (k == 1) {
		for (int i = 1; i <= m; i++) {
			res += val[a[i]];
		}
		cout << res << '\n';
		return;
	}
	g[1] = val[a[1]];
	g[2] = g[1] + val[a[2]];
	if (k >= 2) g[3] = g[1] + val[a[3]];
	else g[3] = g[2] + val[a[3]];
	for (int i = 4; i <= m; i++) {
		g[i] = g[i - 1];
		for (int j = 2; j <= k; j++) {
			g[i] = min(g[i], g[i - j]);
		}
		g[i] += val[a[i]];
	}
	cout << g[m] << '\n';
}

int Q, x, y, t;

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	IOS;
	cin >> n >> Q >> k;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1, 0);
	
	while (Q--) {
		cin >> x >> y;
		t = lca(x, y);
		m = 0;
//		cout << x << " " << y << " " << t << '\n';
		while (x != t) {
			a[++m] = x;
			x = f[x][0];
		}
		a[++m] = t;
		int mm = m + dep[y] - dep[t];
		while (y != t) {
			a[m + dep[y] - dep[t]] = y;
			y = f[y][0];
		}
		m = mm;
		calc();
	}
	return 0;
}
