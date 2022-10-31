#include <cstdio>
#include <algorithm>
#include <queue>
const int MAXN = 2505, MAXM = 10005;
int n, m, k, cost[MAXN], dp[MAXN];
std::vector<int> G[MAXN];
struct Edge {
	int v, w;
	Edge (int vv, int ww) { v = vv, w = ww; }
	bool operator < (const Edge other) const { return w > other.w; }
};
bool vis[MAXN];
int Dijkstra (int S, int T) {
	for (int i = 1; i <= n; i++)
		dp[i] = 0, vis[i] = 0;
	std::priority_queue<Edge> q;
	q.push(Edge(S, 0));
	while (!q.empty()) {
		int u = q.top().v, d = q.top().w;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v : G[u])
			if (dp[v] < dp[u] + cost[v]) {
				dp[v] = dp[u] + cost[v];
				q.push(Edge(v, dp[v]));
			}
	}
	return dp[T];
}
int main () {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 2; i <= n; i++) scanf("%d", cost + i);
	std::sort(cost + 2, cost + n + 1);
	printf("%lld", 1ll * cost[n] + cost[n - 1] + cost[n - 2] + cost[n - 3]);
//	for (int i = 1, u, v; i <= m; i++) {
//		scanf("%d%d", &u, &v);
//		G[u].push_back(v), G[v].push_back(u);
//	}
//	Dijkstra(1, n);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", dp[i]);
	return 0;
}
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

*/
