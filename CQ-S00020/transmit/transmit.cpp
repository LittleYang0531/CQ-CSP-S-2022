#include <cstdio>
const int MAXN = 5005;
bool vis[MAXN];
int a[MAXN][MAXN];
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
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
	}
	scanf("%d", &Q);
	for (int i = 1, q, x, y; i <= Q; i++) {
		scanf("%d %d", &q, &x);
		if (q == 1) {
			scanf("%d", &y);
			a[x][y] = 2;
		}
		if (q == 2) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] != 0) a[x][y] = 2;
			}
		}
		if (q == 3) {
			scanf("%d", &y);
			a[x][y] = 1;
		}
		if (q == 4) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] != 0) a[x][y] = 1;
			}
		}
		bool flag = 1;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				vis[k] = 0;
			}
			if (!dfs(j)) {
				flag = 0;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
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
