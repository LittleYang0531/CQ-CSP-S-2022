#include<bits/stdc++.h>
using namespace std;
#define MAXN 200000
int n, q, k, u, v, last[3], a[MAXN+5], dis[MAXN+5], fa[MAXN+5][30];
vector<int> G[MAXN+5];
inline int read() {
	int s = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
	return s; 
}
void dfs(int x) {
	for (int i = 0; i < G[x].size(); ++i) {
		int j = G[x][i];
		if (j == fa[x][0]) continue;
		dis[j] = dis[x] + 1;
		fa[j][0] = x;
		for (int k = 1; (1 << k) <= dis[j]; ++k) fa[j][k] = fa[fa[j][k - 1]][k - 1];
		dfs(j);
	}
}
int lca(int x, int y) {
	if (dis[x] < dis[y]) swap(x, y);
	while (dis[x] > dis[y]) x = fa[x][0];
	if (x == y) return x;
	for (int i = 1; (1 << i) <= n; ++i) {
		if (fa[x][i] == fa[y][i]) {
			x = fa[x][i - 1], y = fa[y][i - 1];
			break;
		}
	}
	while (x != y) x = fa[x][0], y = fa[y][0];
	return x;
}
int find(int x, int y, int t) {
	memset(last, 0, sizeof(last));
	int dp = 0;
	stack<int> st;
	while (x != t) {
		last[2] = last[1], last[1] = last[0], last[0] = dp, x = fa[x][0];
		int res = last[0];
		for (int i = 1; i < k; ++i) res = min(res, last[i]);
		dp = res + a[x];
	}
	while (y != t) st.push(y), y = fa[y][0];
	while (!st.empty()) {
		last[2] = last[1], last[1] = last[0], last[0] = dp, x = st.top();
		st.pop();
		int res = last[0];
		for (int i = 1; i < k; ++i) res = min(res, last[i]);
		dp = res + a[x];
	}
	return dp;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	n = read(), q = read(), k = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	while (q--) {
		u = read(), v = read();
		const int t = lca(u, v);
		printf("%lld\n", find(u, v, t) + a[u]);
	}
	return 0;
}
