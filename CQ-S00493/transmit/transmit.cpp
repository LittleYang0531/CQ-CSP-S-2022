#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5, MAXM = 35, INF = 1e18;
int n, q, k;
int a[MAXN];
int head[MAXN], ver[MAXN], nxt[MAXN], tot;
int fa[MAXN][MAXM], dep[MAXN];
int dis[MAXN];
void add(int u, int v) {
	nxt[++tot] = head[u], head[u] = tot, ver[tot] = v;
}
template <typename _Tp>inline void read(_Tp& x) {
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
void dfs(int u, int f) {
	fa[u][0] = f, dis[u] = dis[f] + a[u], dep[u] = dep[f] + 1;
	for (int i = 1; i <= 25; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = nxt[i]) {
		int v = ver[i];
		if (v != f)
			dfs(v, u);
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 25; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = 25; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int dp[MAXN];
signed main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n), read(q), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u), read(v); 
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	while (q--) {
		int s, t;
		read(s), read(t);
		int ans = INF;
		int d = lca(s, t);
		if (dep[s] + dep[t] - 2 * dis[d] <= k)
			ans = min(ans, dis[s] + dis[t] - dis[d]);
		vector<int> v, v1;
		v.push_back(0ll);
		for (int x = s; x != d; x = fa[x][0])
			v.push_back(a[x]);
		v.push_back(a[d]);
		for (int y = t; y != d; y = fa[y][0])
			v1.push_back(a[y]);
		for (int i = v1.size() - 1; i >= 0; i--)
			v.push_back(v1[i]);
		dp[0] = INF, dp[1] = v[1];
		for (int i = 2; i < v.size(); i++) {
			dp[i] = dp[i - 1] + v[i];
			for (int j = 1; j <= k; j++)
				if (i >= j)
					dp[i] = min(dp[i], dp[i - j] + v[i]);
		}
		ans = min(ans, dp[v.size() - 1]);
		printf("%lld\n", ans);
	}
	return 0;
}
