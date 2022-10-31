// % gyh20

#include <cstdio>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, Q, K, tot, tt, id[N], tmp[N];
ll a[N], f[N];
vector<int> G[N];

int fa[N][20], dep[N];
ll sum[N];
void dfs(int u) {
	dep[u] = dep[fa[u][0]] + 1;
	sum[u] = sum[fa[u][0]] + a[u];
	for (auto v : G[u]) {
		if (fa[u][0] == v) continue;
		fa[v][0] = u;
		dfs(v);
	}
}
void init_fa(int n) {
	for (int j = 1; j < 18; j++)
		for (int i = 1; i <= n; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 0; i < 18; i++)
		if (dep[u] - dep[v] & 1 << i) u = fa[u][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &Q, &K);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	init_fa(n);
	while (Q--) {
		int u, v, lca;
		scanf("%d %d", &u, &v);
		lca = LCA(u, v);
		if (K == 1) {printf("%lld\n", sum[u] + sum[v] - sum[lca] - sum[fa[lca][0]]); continue;}
		tot = tt = 0;
		while (u != lca) id[++tot] = u, u = fa[u][0];
		id[++tot] = lca;
		while (v != lca) tmp[++tt] = v, v = fa[v][0];
		for (int i = tt; i; i--) id[++tot] = tmp[i];
		f[1] = a[id[1]];
		f[2] = a[id[1]] + a[id[2]];
		f[3] = a[id[1]] + a[id[3]];
		for (int i = 4; i <= tot; i++) {
			if (K == 2) f[i] = min(f[i - 1], f[i - 2]) + a[id[i]];
			else f[i] = min(min(f[i - 1], f[i - 2]), f[i - 3]) + a[id[i]];
		}
		printf("%lld\n", f[tot]);
	}
	return 0;
}
