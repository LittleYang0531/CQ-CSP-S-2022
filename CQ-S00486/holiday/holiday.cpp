#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define LL long long

using namespace std;

const int N = 3e3 + 5, M = 1e4 + 5;

int n, m, k, head[N], tot, dis[N][N];
LL a[N], ans, maxv;
bool vis[N];
struct Edge {
	int to, w, next;
} edge[M << 1];
struct node {
	int u, w;
	node(int U, int W) { u = U, w = W; }
	inline bool operator<(node X) const { return w > X.w; }
};
priority_queue<node> q;
vector<int> ve[N];

inline void add(int u, int v, int w) {
	edge[++tot].to = v, edge[tot].w = w;
	edge[tot].next = head[u], head[u] = tot;
}

inline void dijkstra(int s) {
	while (!q.empty())
		q.pop();
	for (int i = 1; i <= n; i++)
		dis[s][i] = 0x3f3f3f3f, vis[i] = false;
	dis[s][s] = 0;
	q.push(node(s, 0));
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u])	
			continue;
		vis[u] = true;
		for (int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to, w = edge[i].w;
			if (dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				q.push(node(v, dis[s][v]));
			}
		}
	}
}

inline void dfs(int now, int sum, LL res) {
	if (sum == 4) {
		if (dis[1][now] - 1 <= k)
			ans = max(ans, res);
		return ;
	}
	if (res + maxv * (4ll - sum) <= ans)
		return ;
	int s = ve[now].size();
	for (int i = 0; i < s; i++)
		if (!vis[ve[now][i]])
			vis[ve[now][i]] = true, dfs(ve[now][i], sum + 1, res + a[ve[now][i]]), vis[ve[now][i]] = false;
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 2; i <= n; i++)
		scanf("%lld", &a[i]), maxv = max(maxv, a[i]);
	for (int i = 1, x, y; i <= m; i++)
		scanf("%d %d", &x, &y), add(x, y, 1), add(y, x, 1);
	for (int i = 1; i <= n; i++)
		dijkstra(i);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (dis[i][j] - 1 <= k)
				ve[i].push_back(j), ve[j].push_back(i);
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	vis[1] = true;
	int s = ve[1].size();
	for (int i = 0; i < s; i++)
		vis[ve[1][i]] = true, dfs(ve[1][i], 1, a[ve[1][i]]), vis[ve[1][i]] = false;
	printf("%lld\n", ans);
	return 0;
}
