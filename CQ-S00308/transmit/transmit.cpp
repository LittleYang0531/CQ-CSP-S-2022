#include <bits/stdc++.h>


using namespace std;


struct Edge {
	int enode, enext;
} edge[400003];

int elast[200003], cntEdge = 0;

void addEdge(int u, int v) {
	edge[++ cntEdge].enode = v;
	edge[cntEdge].enext = elast[u];
	elast[u] = cntEdge;
}


int n, q, m, x, y;
int v[200003];
int parent[200003][19], depth[200003];
long long f[200003];


void DFS(int u, int fa) {
	f[u] = f[fa] + v[u];
	parent[u][0] = fa;
	depth[u] = depth[fa] + 1;
	for (int i = elast[u]; i; i = edge[i].enext) {
		if (edge[i].enode == fa) continue;
		DFS(edge[i].enode, u);
	}
}


int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	for (int i = 18; i >= 0; -- i)
		if (depth[parent[u][i]] >= depth[v]) u = parent[u][i];
	if (u == v) return u;
	for (int i = 18; i >= 0; -- i)
		if (parent[u][i] != parent[v][i]) u = parent[u][i], v = parent[v][i];
	return parent[u][0];
}


int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &q, &m);
	for (int i = 1; i <= n; ++ i) scanf("%d", &v[i]);
	for (int i = 1; i < n; ++ i) {
		scanf("%d %d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}
	DFS(1, 0);
	for (int i = 1; i <= log2(n) + 1; ++ i)
		for (int j = 1; j <= n; ++ j)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
	if (m == 1) {
		for (int i = 1; i <= q; ++ i) {
			scanf("%d %d", &x, &y);
			int z = LCA(x, y);
			printf("%lld\n", f[x] + f[y] - f[z] - (parent[z][0] ? f[parent[z][0]] : 0));
		}
	} else {
		for (int i = 1; i <= q; ++ i) {
			scanf("%d %d", &x, &y);
			int z = LCA(x, y);
			printf("%lld\n", (f[x] + f[y] - f[z] - (parent[z][0] ? f[parent[z][0]] : 0)) / m);
		}
	}
	return 0;
}
