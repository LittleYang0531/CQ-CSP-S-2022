#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int e[maxn][maxn];
int n, m, q, c[maxn], cnt, fl, vis[maxn];
vector<int> V[maxn];
struct edge {
	int u, v;
} p[maxn];
void check(int now, int s, int cnt) {
	if (cnt > 1e3) {
		fl = 1;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (fl) return;
		if (e[now][i] && !vis[i]) 
			check(i, s, cnt + 1);
		if (fl) return;
	}
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		e[u][v] = 1;
		c[u]++;
		V[u].push_back(i);
		p[i].u = u, p[i].v = v;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int opt, u, v;
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d %d", &u, &v);
			if (e[u][v] == 1)
				c[u]--;
			e[u][v] = 0;
		}
		else if (opt == 2) {
			scanf("%d", &u);
			for (int j = 0; j < V[u].size(); j++) {
				if (e[p[V[u][j]].u][p[V[u][j]].v] == 1)
					c[p[V[u][j]].u]--;
				e[p[V[u][j]].u][p[V[u][j]].v] = 0;
			}
		}
		else if (opt == 3) {
			scanf("%d %d", &u, &v);
			if (e[u][v] == 0)
				c[u]++;
			e[u][v] = 1;
		}
		else {
			scanf("%d", &u);
			for (int j = 0; j < V[u].size(); j++) {
				if (e[p[V[u][j]].u][p[V[u][j]].v] == 0)
					c[p[V[u][j]].u]++;
				e[p[V[u][j]].u][p[V[u][j]].v] = 1;
			}
		}
		fl = 0;
		for (int j = 1; j <= n; j++) {
			if (c[j] != 1) {
				fl = 1;
				break;
			}	
		}
		if (fl) {
			puts("NO");
			continue;
		}
		int fl2 = 0;
		for (int j = 1; j <= n; j++) {
			fl = 0;
			check(j, j, 0);
			if (!fl) {
				fl2 = 1;
				puts("NO");
				break;
			}
		}
		if (fl2 == 0)
			puts("YES");
	}
}
