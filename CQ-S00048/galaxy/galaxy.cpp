#include <cstdio>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 5e5 + 5;
int n, m, in_deg[MAXN], out_deg[MAXN];
set<int> G[MAXN];
vector<int> G2[MAXN];
void AddEdge (int u, int v) {
	if (G[u].find(v) != G[u].end()) return ;
	G[u].insert(v);
	in_deg[v]++, out_deg[u]++;
}
void DelEdge (int u, int v) {
	auto t = G[u].find(v);
	if (t == G[u].end()) return ;
	G[u].erase(t);
	in_deg[v]--, out_deg[u]--;
}
bool vis[MAXN];
bool dfs (int u) {
	if (vis[u]) return true;
	vis[u] = 1;
	for (auto v : G[u])
		if (dfs(v)) return true;
	vis[u] = 0;
	return false;
}
int main () {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		AddEdge(u, v);
		G2[v].push_back(u);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int opt, v;
		scanf("%d", &opt);
		if (opt == 1) {
			int u;
			scanf("%d%d", &u, &v);
			DelEdge(u, v);
		} else if (opt == 2) {
			scanf("%d", &v);
			for (auto u : G2[v]) {
				DelEdge(u, v);
			}
		} else if (opt == 3) {
			int u;
			scanf("%d%d", &u, &v);
			AddEdge(u, v);
			G2[v].push_back(u);
		} else {
			scanf("%d", &v);
			for (auto u : G2[v]) {
				AddEdge(u, v);
			}
		}
		bool ans = true;
		for (int i = 1; i <= n; i++) {
//			printf("%d %d\n", in_deg[i], out_deg[i]);
			if (/*!in_deg[i] || */out_deg[i] != 1) {
				ans = false; break;
			}
		}
		if (!ans) {
			puts("NO");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			if (!dfs(i)) {
				ans = false; break;
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2

*/
