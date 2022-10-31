#include <bits/stdc++.h>

#define int long long

const int N = 3010, inf = 1e9;

int n, m, t, s;

int w[N], dis[N][N], vis[N];

std::vector<int> vec[N];

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > q;
void DJ() {
	for (int i = 1; i <= n; ++i) dis[s][i] = inf, vis[i] = 0;
	q.push(std::make_pair(0, s)), dis[s][s] = 0;
	while (q.size()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v : vec[u]) {
			if (dis[s][v] > dis[s][u] + 1) {
				dis[s][v] = dis[s][u] + 1;
				q.push(std::make_pair(dis[s][v], v));
			}
		}
	}
}

std::vector<int> can;
std::vector<std::pair<int, int> > z[N];

signed main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m >> t;
	for (int i = 2; i <= n; ++i) std::cin >> w[i];
	for (int i = 1; i <= m; ++i) {
		int u, v; std::cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		s = i; DJ();
	}
	
	if (n <= 100) {
		int ans = 0;
		for (int i = 2; i <= n; ++i) {
			if (dis[1][i] > t + 1) continue;
			for (int j = 2; j <= n; ++j) {
				if (i == j) continue; if (dis[i][j] > t + 1) continue;
				for (int k = 2; k <= n; ++k) {
					if (i == k || j == k) continue; if (dis[j][k] > t + 1) continue;
					for (int p = 2; p <= n; ++p) {
						if (i == p || j == p || k == p) continue; if (dis[k][p] > t + 1 || dis[p][1] > t + 1) continue;
						ans = std::max(ans, w[i] + w[j] + w[k] + w[p]);
					}
				}
			}
		}
		std::cout << ans;
		return 0;
	}
	
	for (int i = 2; i <= n; ++i) {
		if (dis[1][i] > t + 1) continue;
		can.push_back(i); 
	}
	for (int i = 2; i <= n; ++i) {
		for (auto v : can) {
			if (i == v || dis[i][v] > t + 1) continue;
			z[i].push_back({-w[v], v}); 
		}
		std::sort(z[i].begin(), z[i].end());
	}
	
	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			if (i == j || dis[i][j] > t + 1) continue;
			int x = 0, y = 0;
			for (auto v : z[i]) {
				if (v.second != j) { x = v.second; break; }
			}
			for (auto v : z[j]) {
				if (v.second != i && v.second != x) { y = v.second; break; }
			}
			if (x && y) ans = std::max(ans, w[i] + w[j] + w[x] + w[y]);
			x = 0, y = 0;
			for (auto v : z[j]) {
				if (v.second != i) { y = v.second; break; }
			}
			for (auto v : z[i]) {
				if (v.second != j && v.second != y) { x = v.second; break; }
			}
			if (x && y) ans = std::max(ans, w[i] + w[j] + w[x] + w[y]);
		}
	}
	std::cout << ans;
	
	return 0;
}
