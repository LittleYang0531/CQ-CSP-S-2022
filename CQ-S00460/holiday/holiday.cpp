#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
const int N = 2500, M = 10000, inf = 0x3f3f3f3f;
int n, m, k;
long long p[N + 5];
int head[N + 5], cnt;
struct edge {
	int to;
	int w;
	int next;
} edges[(M << 1) + 5];
inline void addEdge(const int &u, const int &v, const int &w) {
	edges[cnt].to = v;
	edges[cnt].w = w;
	edges[cnt].next = head[u];
	head[u] = cnt++;
	return;
}
inline void insEdge(const int &u, const int &v, const int &w) {
	addEdge(u, v, w);
	addEdge(v, u, w);
	return;
}
bool vis[N + 5];
int dis[N + 5][N + 5];
std::priority_queue<std::pair<int, int>> q;
inline void Dijkstra__(const int &s) {
	for (int i = 1; i <= n; i++)
		vis[i] = false, dis[s][i] = inf;
	q.push({-(dis[s][s] = 0), s});
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		for (int i = head[x]; ~i; i = edges[i].next) {
			int y = edges[i].to;
			if (dis[s][x] + edges[i].w < dis[s][y] && dis[s][x] + edges[i].w <= k + 1)
				q.push({-(dis[s][y] = dis[s][x] + edges[i].w), y});
		}
	}
	return;
}
//int d[N + 5][N + 5];
//inline void Dijkstra(const int &s) {
//	for (int i = 1; i <= n; i++)
//		vis[i] = false, d[s][i] = -inf;
//	q.push({-(d[s][s] = 0), s});
//	while (!q.empty()) {
//		int x = q.top().second;
//		q.pop();
//		if (vis[x])
//			continue;
//		vis[x] = true;
//		for (int i = head[x]; ~i; i = edges[i].next) {
//			int y = edges[i].to;
//			if (d[s][x] + edges[i].w > d[s][y])
//				q.push({-(d[s][y] = d[s][x] + edges[i].w), y});
//		}
//	}
//	return;
//}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> n >> m >> k;
	for (int i = 2; i <= n; i++)
		std::cin >> p[i];
	for (int i = 1; i <= n; i++)
		head[i] = -1;
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		insEdge(x, y, 1);
	}
	for (int i = 1; i <= n; i++)
		Dijkstra__(i);
	for (int i = 1; i <= n; i++)
		head[i] = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dis[i][j] != inf && dis[i][j])
				addEdge(i, j, 1);
	long long ans = 0;
	for (int i = head[1]; ~i; i = edges[i].next) {
		int x = edges[i].to;
		if (x == 1)
			continue;
		for (int j = head[x]; ~j; j = edges[j].next) {
			int y = edges[j].to;
			if (y == 1 || y == x)
				continue;
			for (int l = head[y]; ~l; l = edges[l].next) {
				int z = edges[l].to;
				if (z == 1 || z == x || z == y)
					continue;
				for (int q = head[z]; ~q; q = edges[q].next) {
					int w = edges[q].to;
					if (w == 1 || w == x || w == y || w == z || dis[w][1] == inf)
						continue;
					ans = std::max(p[x] + p[y] + p[z] + p[w], ans);
				}
			}
		}
	}
	std::cout << ans;
//	for (int i = 1; i <= n; i++)
//		Dijkstra(i);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			std::cout << d[i][j] << ' ';
//		std::cout<<'\n';
//	}
	return 0;
}
