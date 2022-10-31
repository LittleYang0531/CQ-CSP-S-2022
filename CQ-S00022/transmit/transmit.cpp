#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 5;
vector<int> G[MAXN];
int n, t, k, w[MAXN], dis[MAXN][MAXN], en;
long long ans;
bool vis[MAXN];
struct node{
	int u, w;
	node (int U, int W) {
		u = U;
		w = W;
	}
	bool operator < (const node& a) const { return w > a.w; } 
};
priority_queue<node> q;
void Dijkstra(int x) {
	memset(vis, 0, sizeof(vis));
	dis[x][x] = 0;
	q.push(node(x, 0));
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.u])
			continue;
		vis[t.u] = 1;
		for (int i = 0; i < G[t.u].size(); i++) {
			if (dis[x][G[t.u][i]] > dis[x][t.u] + 1) {
				dis[x][G[t.u][i]] = dis[x][t.u] + 1;
				q.push(node(G[t.u][i], dis[x][G[t.u][i]]));
			}
		}
	}
}
void dfs(int now, long long sum) {
	if (sum >= ans)
		return ;
	if (dis[now][en] <= k) {
		ans = min(ans, sum + (long long) w[en]);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && dis[now][i] <= k) {
			vis[i] = 1;
			dfs(i, sum + (long long) w[i]);
			vis[i] = 0;
		}
	} 
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &t, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		Dijkstra(i);
	while (t--) {
		int u, v;
		scanf("%d %d", &u, &v);
		en = v;
		ans = 1e18;
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		dfs(u, w[u]);
		printf("%lld\n", ans);
	}
	return 0;
}
