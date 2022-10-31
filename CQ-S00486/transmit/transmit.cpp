#include <cstdio>
#include <queue>
#include <vector>
#define LL long long

using namespace std;

const int N = 2e3 + 5;

int n, m, k, tot, head[N], dis[N][N], start, End;
bool vis[N];
LL v[N], ans;
struct Edge {
	int w, to, next;
} edge[N << 1];
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

inline void dfs(int now, LL sum) {
	if (sum >= ans)
		return ;
	if (now == End) {
		ans = sum;
		return ;
	}
	for (int i = 0; i < ve[now].size(); i++)
		if (!vis[ve[now][i]]) {
			vis[ve[now][i]] = true;
			dfs(ve[now][i], sum + v[ve[now][i]]);
			vis[ve[now][i]] = false;
		}
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &v[i]);
	for (int i = 1, x, y; i < n; i++)
		scanf("%d %d", &x, &y), add(x, y, 1), add(y, x, 1);
	for (int i = 1; i <= n; i++)
		dijkstra(i);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (dis[i][j] <= m)
				ve[i].push_back(j), ve[j].push_back(i);
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	while (k--) {
		scanf("%d %d", &start, &End);
		ans = 1e18;
		vis[start] = true;
		dfs(start, v[start]);
		vis[start] = false;
		printf("%lld\n", ans);
	}
	return 0;
}
