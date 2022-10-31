#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm> 
#define MAXN 200005
#define MAXX 32
using namespace std;
int n, q, k, v[MAXN], log1[MAXN], dp[MAXN][MAXX], dep[MAXN];
bool flag[MAXN];
vector <int> g[MAXN];
void logset() {
	log1[1] = 0;
	for (int i = 2; i <= MAXN; i++) {
		log1[i] = log1[i / 2] + 1;
	}
}
void dfs(int x) {
	flag[x] = true;
	for (int t = 0; t < g[x].size(); t++) {
		int v = g[x][t];
		if (!flag[v]) {
			dep[v] = dep[x] + 1;
			dp[v][1] = x;
			for (int i = 1; i <= log1[dep[v]]; i++) {
				dp[v][i] = dp[dp[v][i - 1]][i - 1];
			}
			dfs(v);
		}
	}
}
int LCA(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	while (dep[u] != dep[v]) {
		v = dp[v][log1[dep[v]]];
	}
	for (int i = log1[dep[v]]; i >= 0; i--) {
		v = dp[v][log1[dep[v]]];
		u = dp[u][log1[dep[u]]];
		if (v == u) break;
	}
	return v;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	logset();
	scanf("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= q; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		printf("%d\n", dep[s] + dep[t] - dep[LCA(s, t)] - 2);
	}
	return 0;
}
