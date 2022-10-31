#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << "=" << x << endl
using namespace std;

namespace True_False {
	// gcd
	template <class T>
	T gcd(T x, T y) {
		if (!y) return x;
		return gcd(y, x % y);
	}
	// read
	template <class T>
	void read(T& x) {
		x = 0; static char ch; static bool some;
		some = 0;
		while ((ch = getchar()) < '0' || ch > '9') some = ch == '-';
		while (ch >= '0' && ch <= '9')
			x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
		if (some) x = -x;
	}
	template <class T, class... Args>
	void read(T& x, Args& ...args) { read(x), read(args...); }
	// write
	template <class T>
	void fwrite(T x) {
		if (x > 9) fwrite(x / 10);
		putchar(x % 10 + 48);
	}
	template <class T>
	void write(T x) {
		if (x < 0) putchar('-'), x = -x;
		fwrite(x);
	}
	void write(char x) { putchar(x); }
	template <class T, class... Args>
	void write(T x, Args ...args) { write(x), write(args...); }
}
using namespace True_False;

const int inf = 2e5 + 5;

int n, q, k, v[inf];
ll sum[inf], dp[5][inf];
int Log[inf], fa[30][inf], dep[inf];
vector<int> e[inf];

void _dfs(int x) {
	dp[1][x] = dp[1][fa[0][x]] + v[x];
	for (int i : e[x]) {
		if (i == fa[0][x]) continue;
		fa[0][i] = x;
		dep[i] = dep[x] + 1;
		for (int j = 1; (1 << j) <= dep[i]; ++j)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
		_dfs(i);
	}
}

int LCA(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	while (dep[x] != dep[y])
		x = fa[Log[dep[x] - dep[y]]][x];
	if (x == y) return x;
	for (int i = Log[dep[x]]; ~i; --i)
		if (fa[i][x] != fa[i][y])
			x = fa[i][x], y = fa[i][y];
	return fa[0][x];
}

int Possize(int x, int y) {
	int lca = LCA(x, y);
	return dep[x] + dep[y] - dep[lca] * 2;
}

ll Poslen(int x, int y) {
	int lca = LCA(x, y);
	return dp[1][x] + dp[1][y] - dp[1][lca] - dp[1][fa[0][lca]];
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n, q, k);
	for (int i = 2; i <= n; ++i) Log[i] = Log[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) read(v[i]);
	for (int i = 1, x, y; i < n; ++i) {
		read(x, y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	_dfs(1);
	dep[0] = -1;
	while (q--) {
		int s, t;
		read(s, t);
		ll ans = LONG_LONG_MAX;
		if (Possize(s, t) <= k) {
			write(v[s] + v[t], '\n');
			continue;
		}
		if (k == 1) ans = Poslen(s, t);
		if (k == 2) {
			memset(dp[3], 0x3f, sizeof dp[3]);
			memset(dp[4], 0x3f, sizeof dp[4]);
			dp[3][s] = v[s], dp[4][t] = v[t];
			int sd[3] = {}, td[3] = {};
			int lca = LCA(s, t);
			for (int i = s; dep[i] >= dep[lca]; i = fa[0][i]) {
				int cha = dep[i] - dep[lca];
				if (cha <= 2) sd[cha] = i;
				if (cha >= 1) dp[3][fa[0][i]] = min(dp[3][i] + v[fa[0][i]], dp[3][fa[0][i]]);
				if (cha >= 2) dp[3][fa[1][i]] = min(dp[3][i] + v[fa[1][i]], dp[3][fa[1][i]]);
			}
			for (int i = t; dep[i] >= dep[lca]; i = fa[0][i]) {
				int cha = dep[i] - dep[lca];
				if (cha <= 2) td[cha] = i;
				if (cha >= 1) dp[4][fa[0][i]] = min(dp[4][i] + v[fa[0][i]], dp[4][fa[0][i]]);
				if (cha >= 2) dp[4][fa[1][i]] = min(dp[4][i] + v[fa[1][i]], dp[4][fa[1][i]]);
			}
			ans = dp[3][lca] + dp[4][lca] - v[lca];
			for (int i = 0; i <= 2; ++i)
				for (int j = 0; i + j <= 2; ++j)
					if (sd[i] && td[j]) ans = min(dp[3][sd[i]] + dp[4][td[j]], ans);
		}
		if (k == 3) {
			memset(dp[3], 0x3f, sizeof dp[3]);
			memset(dp[4], 0x3f, sizeof dp[4]);
			dp[3][s] = v[s], dp[4][t] = v[t];
			int sd[4] = {}, td[4] = {};
			int lca = LCA(s, t);
			for (int i = s; dep[i] >= dep[lca]; i = fa[0][i]) {
				int cha = dep[i] - dep[lca];
				if (cha <= 3) sd[cha] = i;
				if (cha >= 1) dp[3][fa[0][i]] = min(dp[3][i] + v[fa[0][i]], dp[3][fa[0][i]]);
				if (cha >= 2) dp[3][fa[1][i]] = min(dp[3][i] + v[fa[1][i]], dp[3][fa[1][i]]);
				if (cha >= 3) dp[3][fa[0][fa[1][i]]] = min(dp[3][i] + v[fa[0][fa[1][i]]], dp[3][fa[0][fa[1][i]]]);
			}
			for (int i = t; dep[i] >= dep[lca]; i = fa[0][i]) {
				int cha = dep[i] - dep[lca];
				if (cha <= 3) td[cha] = i;
				if (cha >= 1) dp[4][fa[0][i]] = min(dp[4][i] + v[fa[0][i]], dp[4][fa[0][i]]);
				if (cha >= 2) dp[4][fa[1][i]] = min(dp[4][i] + v[fa[1][i]], dp[4][fa[1][i]]);
				if (cha >= 3) dp[4][fa[0][fa[1][i]]] = min(dp[4][i] + v[fa[0][fa[1][i]]], dp[4][fa[0][fa[1][i]]]);
			}
			ans = dp[3][lca] + dp[4][lca] - v[lca];
			for (int i = 0; i <= 3; ++i)
				for (int j = 0; i + j <= 3; ++j)
					if (sd[i] && td[j]) ans = min(dp[3][sd[i]] + dp[4][td[j]], ans);
		}
		write(ans, '\n');
	}
	return 0;
}
