#include <cstdio>
const int MAXN = 5005;
bool vis[MAXN];
int a[MAXN][MAXN], d[MAXN];
int n, m, Q;
bool dfs(int x) {
	if (vis[x]) return 1;
	vis[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[x][i] != 1) continue;
		if (dfs(x)) return 1;
	}
	return 0;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		d[u]++;
		a[u][v] = 1;
	}
	scanf("%d", &Q);
	for (int i = 1, q, x, y; i <= Q; i++) {
		scanf("%d %d", &q, &x);
		if (q == 1) {
			scanf("%d", &y);
			a[x][y] = 2;
			d[x]--;
		}
		if (q == 2) {
			for (int j = 1; j <= n; j++) {
				if (a[j][x] == 1) {
					a[j][x] = 2;
					d[j]--;
				}
			}
		}
		if (q == 3) {
			scanf("%d", &y);
			a[x][y] = 1;
			d[x]++;
		}
		if (q == 4) {
			for (int j = 1; j <= n; j++) {
				if (a[j][x] == 2) {
					a[j][x] = 1;
					d[j]++;
				}
			}
		}
		bool flag = 1;
		for (int j = 1; j <= n; j++) {
			if (d[j] != 1) {
				flag = 0;
				continue;
			}
		}
		if (flag) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					vis[k] = 0;
				}
				if (!dfs(j)) {
					flag = 0;
				}
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
