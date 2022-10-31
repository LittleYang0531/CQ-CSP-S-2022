#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, q, k;
struct edge {
	int nxt, to;
} e[N*2];
int v[N], h[N], num;
int fa[25][N];
int dep[N];
void addedge(int x, int y) {
	e[++num].nxt = h[x];
	e[num].to = y;
	h[x] = num;
}
void dfs(int x, int prt, int d) {
	dep[x] = d;
	fa[0][x] = prt;
//	for (int i = 1; i <= 20; ++i) {
//		fa[i][x] = fa[i-1][fa[i-1][x]];
//	}
	for (int i = h[x]; i; i = e[i].nxt) {
		int y = e[i].to;
		if (y == prt) continue;
		dfs(y, x, d+1);
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	while (dep[x] > dep[y]) {
		x = fa[0][x];
	}
	if (x == y) return x;
	while (x != y) {
		x = fa[0][x];
		y = fa[0][y];
	}
	return x;
}
void Read() {
	scanf ("%d%d%d", &n, &q, &k);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &v[i]);
		v[i]+=v[i-1];
	}
	for (int i = 1, x, y; i < n; ++i) {
		scanf ("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
}
void Solve() {
	dfs(1, -1, 0);
	int s, t;
	while (q--) {
		scanf ("%d%d", &s, &t);
		printf ("%d\n", v[lca(s, t)]);
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	Read();
	Solve();
	return 0;
}

