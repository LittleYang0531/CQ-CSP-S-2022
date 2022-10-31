#include <cstdio>
#include <queue>
#include <cstring>
#define int long long

typedef std::pair<int, int> PII;
struct Edge {int to, nxt, w;} e[4000005];
int head[2000005], a[500005], dis[2000005], tot, n, q, k;
bool done[2000005];
std::priority_queue<PII, std::vector<PII>, std::greater<PII> > Q;
inline int ID(int i, int j) {return j * n + i;}
inline void AddEdge(int u, int v, int w) {
	e[++ tot].to = v, e[tot].w = w, e[tot].nxt = head[u], head[u] = tot;
}
int Dijkstra(int src, int tgt) {
	memset(dis, 0x3f, sizeof dis);
	memset(done, false, sizeof done);
	Q.push(std::make_pair(dis[src] = 0, src));
	while (Q.size()) {
		int u = Q.top().second;
		if (u == tgt) break;
		Q.pop();
		if (done[u]) continue;
		done[u] = true;
		for (int i = head[u]; i; i = e[i].nxt)
			if (dis[u] + e[i].w < dis[e[i].to])
				Q.push(std::make_pair(dis[e[i].to] = dis[u] + e[i].w, e[i].to));
	}
	while (Q.size()) Q.pop();
	return dis[tgt];
}

signed main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &q, &k);
	for (int i = 1; i <= n; ++ i) scanf("%lld", a + i);
	for (int i = 1, u, v; i < n; ++ i) {
		scanf("%lld%lld", &u, &v);
		for (int j = 0; j < k - 1; ++ j)
			AddEdge(ID(u, j), ID(v, j + 1), 0), AddEdge(ID(v, j), ID(u, j + 1), 0);
		AddEdge(ID(u, k - 1), ID(v, 0), a[v]);
		AddEdge(ID(v, k - 1), ID(u, 0), a[u]);
	}
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= k; ++ j) AddEdge(ID(i, j), ID(i, 0), a[i]);
	while (q --) {
		int u, v;
		scanf("%lld%lld", &u, &v);
		Dijkstra(ID(u, 0), ID(v, 0));
		printf("%lld\n", dis[ID(v, 0)] + a[u]);
	}
	return 0;
}
