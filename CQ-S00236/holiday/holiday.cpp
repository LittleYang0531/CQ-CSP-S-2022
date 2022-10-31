#include<bits/stdc++.h>
using namespace std;
#define MAXN 2500
#define LL long long
int n, m, k, u, v;
LL ans, w, a[MAXN+5], dis[MAXN+5][MAXN+5];
bool d[MAXN+5][MAXN+5], vis[MAXN+5];
vector<int> G[MAXN+5];
inline int read() {
	int s = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
	return s; 
} 
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis[s], 0x3f, sizeof(dis[s]));
	dis[s][s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		u = q.top().second, w = q.top().first;
		if (w > dis[s][u]) w = dis[s][u];
		q.pop();
		vis[u] = 0;
		for (int i = 0; i < G[u].size(); ++i) {
			v = G[u][i];
			if (w + 1 < dis[s][v]) {
				dis[s][v] = w + 1;
				if (!vis[v]) vis[v] = 1, q.push(make_pair(w + 1, v));
			}
		}
	}
}
void dfs(int x, int sum, LL res) {
	if (dis[x][1] / (k + 1) + sum > 5) return;
	if (sum == 4) {
		if (d[x][1]) ans = max(ans, res);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (d[x][i] && !vis[i]) vis[i] = 1, dfs(i, sum + 1, res + a[i]), vis[i] = 0;
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 2; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= m; ++i) {
		u = read(), v = read();
		G[u].push_back(v), G[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
		for (int j = 1; j <= n; ++j) {
			if (dis[i][j] <= k + 1 && i != j) d[i][j] = 1;
		}
	}
	memset(vis, 0, sizeof(vis));
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
