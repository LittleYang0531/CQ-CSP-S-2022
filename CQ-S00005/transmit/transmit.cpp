#include <bits/stdc++.h>

#define int long long

const int N = 2e6 + 101, inf = 1e18;

int w[N], from[N], pos[N];

std::vector<int> vec[N];

int dp[N][5];

signed main() {
//	freopen("transmit2.in", "r", stdin);
//	freopen("ex_transmit.out", "w", stdout);
	
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, q, k; std::cin >> n >> q >> k;
	for (int i = 1; i <= n; ++i) std::cin >> w[i];
	for (int i = 1; i <= n - 1; ++i) {
		int u, v; std::cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	while (q--) {
		int u, v; std::cin >> u >> v;
		std::function<void(int, int)> dfs = [&] (int u, int fa) {
			for (auto v : vec[u]) {
				if (v == fa) continue;
				from[v] = u; dfs(v, u);
			}
		};
		dfs(u, 0);
		int now = v, cnt = 0;
		while (1) {
			pos[++cnt] = from[now];
			now = from[now];
			if (now == u) break;
		}
		pos[0] = v;
		//for (int j = 1; j <= cnt; ++j) std::cout << w[pos[j]] << " "; std::cout << '\n';
		for (int j = 0; j <= cnt; ++j) {
			for (int t = 0; t <= k; ++t) dp[j][t] = inf;
		}
		dp[0][0] = w[v];
		for (int j = 1; j <= cnt; ++j) {
			for (int t = 1; t <= k && j - t >= 0; ++t) {
				for (int p = 0; p <= k; ++p) {
					dp[j][t] = std::min(dp[j][t], dp[j - t][p] + w[pos[j]]);
					//std::cout << pos[j - t] << " " << t << " " << pos[j] << " " << dp[j - t][p] + w[pos[j]] << '\n';
				}
			}
		}
		int ans = inf;
		for (int j = 1; j <= k && cnt - j >= 0; ++j) {
			ans = std::min(ans, dp[cnt][j]);
		}
		std::cout << ans << '\n'; 
	}
	
	return 0;
}
