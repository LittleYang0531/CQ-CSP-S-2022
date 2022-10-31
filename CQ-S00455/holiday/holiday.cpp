#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF = 1000000000;
long long s[2505], a[2505][2505];
int lmx[2505], lse[2505], lth[2505], cmx[2505], cse[2505], cth[2505];
struct Edge {int to, nxt;} e[20005];
int head[2505], dis[2505][2505], q[2505], hd, tl, tot, n, m, k;
inline void AddEdge(int u, int v) {
	e[++ tot].to = v, e[tot].nxt = head[u], head[u] = tot;
}
void bfs(int s) {
	memset(dis[s], 0x3f, sizeof dis[s]);
	q[hd = tl = 1] = s, dis[s][s] = 0;
	while (hd <= tl) {
		int u = q[hd ++];
		if (dis[s][u] < k)
		for (int i = head[u]; i; i = e[i].nxt)
			if (dis[s][e[i].to] >= INF) dis[s][e[i].to] = dis[s][u] + 1, q[++ tl] = e[i].to;
	}
	dis[s][s] = INF;
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	memset(a, ~0x3f, sizeof a);
	scanf("%d%d%d", &n, &m, &k);
	++ k;
	for (int i = 2; i <= n; ++ i) scanf("%lld", s + i);
	for (int i = 1, u, v; i <= m; ++ i) scanf("%d%d", &u, &v), AddEdge(u, v), AddEdge(v, u);
	for (int i = 1; i <= n; ++ i) {
		bfs(i);
		for (int j = 1; j <= n; ++ j) if (i != j && dis[i][j] < INF) a[i][j] = s[i] + s[j];
	}
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j) {
		if (dis[1][j] < INF) {
			if (a[i][j] > a[i][lmx[i]]) lth[i] = lse[i], lse[i] = lmx[i], lmx[i] = j;
			else if (a[i][j] > a[i][lse[i]]) lth[i] = lse[i], lse[i] = j;
			else if (a[i][j] > a[i][lth[i]]) lth[i] = j;
		}
		if (dis[1][i] < INF) {
			if (a[i][j] > a[cmx[j]][j]) cth[j] = cse[j], cse[j] = cmx[j], cmx[j] = i;
			else if (a[i][j] > a[cse[j]][j]) cth[j] = cse[j], cse[j] = i;
			else if (a[i][j] > a[cth[j]][j]) cth[j] = i;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j) if (i != j && dis[i][j] < INF) {
		int fst1, sec1, fst2, sec2;
		if (j == cmx[i]) fst1 = cse[i], sec1 = cth[i];
		else if (j == cse[i]) fst1 = cmx[i], sec1 = cth[i];
		else fst1 = cmx[i], sec1 = cse[i];
		if (i == lmx[j]) fst2 = lse[j], sec2 = lth[j];
		else if (i == lse[j]) fst2 = lmx[j], sec2 = lth[j];
		else fst2 = lmx[j], sec2 = lse[j];
		if (fst1 != fst2) ans = std::max(ans, a[fst1][i] + a[j][fst2]);
		if (fst1 != sec2) ans = std::max(ans, a[fst1][i] + a[j][sec2]);
		if (sec1 != fst2) ans = std::max(ans, a[sec1][i] + a[j][fst2]);
	}
	printf("%lld", ans);
	return 0;
}
