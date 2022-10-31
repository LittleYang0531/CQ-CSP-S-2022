#include <cstdio>
#include <unordered_set>
#include <cstring>

std::unordered_set<int> s[100005], G[100005], t[100005];
int fa[100005], ed[100005], cnt;
int head[1005], cir[100005], tot;
bool vis[1005];
struct Edge {int to, nxt;} e[2005];
inline void AddEdge(int u, int v) {
	e[++ tot].to = v, e[tot].nxt = head[u], head[u] = tot;
}
int	find(int x) {return fa[x] == x ? x : find(fa[x]);}
void deledge(int u, int v) {
	s[u].erase(v), t[v].erase(u);
	if (s[u].empty()) ed[u] = 0;
	else if (s[u].size() == 1) {ed[u] = *(s[u].begin());}
}
void addedge(int u, int v) {
	s[u].insert(v), t[v].insert(u);
	if (s[u].size() == 1) ed[u] = v;
	else ed[u] = 0;
}
void dfs(int u) {
	vis[u] = true;
	for (int i = head[u]; i; i = e[i].nxt) dfs(e[i].to);
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int n, m, q;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	for (int i = 1, u, v; i <= m; ++ i)
		scanf("%d%d", &u, &v), G[v].insert(u), s[u].insert(v), t[v].insert(u);
	for (int i = 1; i <= n; ++ i) if (s[i].size() == 1) addedge(i, *(s[i].begin()));
	for (int i = 1; i <= n; ++ i) if (fa[i] == i) ++ cnt;
	scanf("%d", &q);
	while (q --) {
		int op;
		scanf("%d", &op);
		if (op == 1 || op == 3) {
			int u, v;
			scanf("%d%d", &u, &v);
			op == 1 ? deledge(u, v) : addedge(u, v);
		} else {
			int u;
			scanf("%d", &u);
			if (op == 2) for (int v : t[u]) deledge(v, u);
			else for (int v : G[u]) if (!s[v].count(u)) addedge(v, u);
		}
		memset(head, 0, sizeof head), tot = cnt = 0;
		bool flag = true;
		for (int i = 1; i <= n; ++ i) fa[i] = i;
		for (int i = 1; i <= n; ++ i)
			if (ed[i]) {
				if (find(i) != find(ed[i])) AddEdge(ed[i], i), fa[find(i)] = find(ed[i]);
				else cir[++ cnt] = find(i);
			} else {flag = false; break;}
		if (!flag) {puts("NO"); continue;}
		for (int i = 1; i <= cnt; ++ i) dfs(cir[i]);
		for (int i = 1; i <= n; ++ i) if (!vis[i]) {flag = false; break;}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
