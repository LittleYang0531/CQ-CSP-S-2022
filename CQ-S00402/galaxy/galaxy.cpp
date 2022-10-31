// % feecle6418

#include <cstdio>
#include <iostream>
using namespace std;
const int N = 5e5 + 5;

int n, m, q, U[N], V[N], tot[N];
bool mark[N];

int cnt, elst[N];
struct edge {
	int to, nxt;
} e[N];
void add(int u, int v) {
	e[++cnt].to = v;
	e[cnt].nxt = elst[u];
	elst[u] = cnt;
}

bool vis[N];
bool dfs(int u) {
	vis[u] = true;
	for (int i = elst[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!vis[v]) return dfs(v);
		return true;
	}
	return false;
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d %d", &U[i], &V[i]), mark[i] = true;
	scanf("%d", &q);
	while (q--) {
		int op, u, v;
		scanf("%d %d", &op, &u);
		if (op == 1) {
			scanf("%d", &v);
			for (int i = 1; i <= m; i++)
				if (U[i] == u && V[i] == v) mark[i] = false;
		}
		if (op == 2) {
			for (int i = 1; i <= m; i++)
				if (V[i] == u) mark[i] = false;
		}
		if (op == 3) {
			scanf("%d", &v);
			for (int i = 1; i <= m; i++)
				if (U[i] == u && V[i] == v) mark[i] = true;
		}
		if (op == 4) {
			for (int i = 1; i <= m; i++)
				if (V[i] == u) mark[i] = true;
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) elst[i] = tot[i] = vis[i] = 0;
		for (int i = 1; i <= m; i++)
			if (mark[i]) add(U[i], V[i]);
		bool fl = true;
		for (int i = 1; i <= m; i++)
			if (mark[i]) tot[U[i]]++;
		for (int i = 1; i <= n; i++)
			if (tot[i] != 1) {fl = false; break;}
		if (!fl) {puts("NO"); continue;}
		for (int i = 1; i <= n; i++)
			if (!vis[i] && !dfs(i)) {fl = false; break;}
		if (!fl) {puts("NO"); continue;}
		puts("YES");
	}
	return 0;
}
