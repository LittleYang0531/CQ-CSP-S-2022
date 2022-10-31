#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
const int N = 2e5, LOGN = 18, M = 2e5, inf = 0x3f3f3f3f;
int n, q, k;
int p[N + 5];
std::vector<int> adj[N + 5];
int father[N + 5][LOGN + 1], depth[N + 5];
long long dp[N + 5][LOGN + 1];
std::vector<int> children[N + 5];
inline void dfs(const int &x, const int &f) {
	father[x][0] = f;
	for (int i = 1; i <= LOGN; i++)
		father[x][i] = father[father[x][i - 1]][i - 1];
	dp[x][0] = p[x];
	for (int i = 1; i <= LOGN; i++)
		dp[x][i] = dp[x][i - 1] + dp[father[x][i - 1]][i - 1];
	dp[x][0] = p[x];
	dp[x][1] = p[x];
	for (int i = 2; i <= LOGN; i++)
		dp[x][i] = dp[x][i - 1] + dp[father[x][i - 1]][i - 1];
	depth[x] = depth[f] + 1;
	for (std::vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++) {
		if (*it != f) {
			children[x].push_back(*it);
			dfs(*it, x);
		}
	}
	return;
}
inline int lca(int x, int y) {
	if (depth[x] > depth[y])
		std::swap(x, y);
	int h = depth[y] - depth[x];
	for (int i = LOGN; i >= 0; i--)
		if ((h >> i) & 1)
			y = father[y][i];
	if (x == y)
		return x;
	for (int i = LOGN; i >= 0; i--)
		if (father[x][i] != father[y][i])
			x = father[x][i], y = father[y][i];
	return father[x][0];
}
inline long long dff(int x, int y) {
	if (depth[x] > depth[y])
		std::swap(x, y);
	long long ans = 0;
	int h = depth[y] - depth[x];
	for (int i = LOGN; i >= 0; i--)
		if ((h >> i) & 1)
			ans += dp[y][i], y = father[y][i];
	if (x == y)
		return ans + p[x];
	for (int i = LOGN; i >= 0; i--)
		if (father[x][i] != father[y][i])
			ans += (long long)dp[x][i] + dp[y][i], x = father[x][i], y = father[y][i];
	return ans + dp[x][0] + dp[y][0] + p[father[x][0]];
}
inline long long ffd(int x, int y) {
	if (depth[x] > depth[y])
		std::swap(x, y);
	int ax[3] = {}, ay[3] = {};
	long long pdx[3] = {0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f}, pdy[3] = {0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f};
	int h = depth[y] - depth[x];
	int i = 0;
	for (; i < h; i++) {
		long long cur = 0x3f3f3f3f3f3f3f3f;
		for (int j = std::min(i - 1, k - 1); j >= 0; j--)
			cur = std::min(pdy[j] + p[y], cur);
		if (cur == 0x3f3f3f3f3f3f3f3f)
			cur = p[y];
		pdy[2] = pdy[1];
		pdy[1] = pdy[0];
		pdy[0] = cur;
		ay[2] = ay[1];
		ay[1] = ay[0];
		ay[0] = y;
		y = father[y][0];
	}
	if (x == y) {
		if (k == 2)
			return std::min(pdy[0] + p[x], pdy[1] + p[x]);
		return std::min(std::min(pdy[0] + p[x], pdy[1] + p[x]), pdy[2] + p[x]);
	}
	int l = 0;
	while (x != y) {
		long long cur = 0x3f3f3f3f3f3f3f3f;
		for (int j = std::min(i - 1, k - 1); j >= 0; j--)
			cur = std::min(pdy[j] + p[y], cur);
		if (cur == 0x3f3f3f3f3f3f3f3f)
			cur = p[y];
		pdy[2] = pdy[1];
		pdy[1] = pdy[0];
		pdy[0] = cur;
		ay[2] = ay[1];
		ay[1] = ay[0];
		ay[0] = y;
		y = father[y][0];
		cur = 0x3f3f3f3f3f3f3f3f;
		for (int j = std::min(l - 1, k - 1); j >= 0; j--)
			cur = std::min(pdx[j] + p[x], cur);
		if (cur == 0x3f3f3f3f3f3f3f3f)
			cur = p[x];
		pdx[2] = pdx[1];
		pdx[1] = pdx[0];
		pdx[0] = cur;
		ax[2] = ax[1];
		ax[1] = ax[0];
		ax[0] = x;
		x = father[x][0];
		i++;
		l++;
	}
	if (k == 2)
		return std::min(pdx[0] + pdy[0], std::min(pdx[0] + p[x] + pdy[1], pdx[1] + p[x] + pdy[0]));
	return std::min(std::min(pdx[1] + pdy[0], pdx[0] + pdy[1]), std::min(std::min(pdx[0], std::min(pdx[1], pdx[2])) + p[x] + std::min(pdy[0], std::min(pdy[1], pdy[2])), pdx[0] + pdy[0]));
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> n >> q >> k;
	for (int i = 1; i <= n; i++)
		std::cin >> p[i];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int root = 1;
	dfs(root, 0);
	for (int i = 0; i < q; i++) {
		int x, y;
		std::cin >> x >> y;
		std::cout << (k == 1 ? dff(x, y) : ffd(x, y)) << '\n';
	}
	return 0;
}
