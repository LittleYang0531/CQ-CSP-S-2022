//P10 ÑùÀıÍ¼ ×îÖÕ×´Ì¬ 
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500005
using namespace std;
int n, m, q, out[MAXN], colour[MAXN];
vector <int> g[MAXN];
bool dfs(int i) {
	colour[i] = 1;
	for (int t = 0; t < g[i].size(); t++) {
		int v = g[i][t];
		if (v <= 0) continue;
		if (colour[v] == 1) return true;
		else if (colour[v] != 2) {
			if (dfs(v)) return true;
		}
	}
	colour[i] = 2;
	return false;
}
bool check() {
//	for (int i = 1; i <= n; i++) {
//		printf("%d: %d ", i, out[i]);
//		for (int t = 0; t < g[i].size(); t++) {
//			printf("%d ", g[i][t]);
//		}
//		printf("\n");
//	}
	for (int i = 1; i <= n; i++) {
		colour[i] = 0;
		if (out[i] != 1) return false;
	}
	return dfs(1);
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		out[x]++;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int f, x, y;
		scanf("%d", &f);
		if (f == 1) {
			scanf("%d %d", &x, &y);
			for (int t = 0; t <= g[x].size(); t++) {
				if (g[x][t] == y) {
					g[x][t] = -y;
					out[x]--;
				}
			}
		} else if (f == 2) {
			scanf("%d", &x);
			for (int j = 1; j <= n; j++) {
				for (int t = 0; t <= g[j].size(); t++) {
					if (g[j][t] == x) {
						g[j][t] = -x;
						out[j]--;
					}
				}
			}
		} else if (f == 3) {
			scanf("%d %d", &x, &y);
			g[x].push_back(y);
			out[x]++;
		} else {
			scanf("%d", &x);
			for (int j = 1; j <= n; j++) {
				for (int t = 0; t <= g[j].size(); t++) {
					if (g[j][t] == -x) {
						g[j][t] = x;
						out[j]++;
					}
				}
			}
			for (int t = 0; t <= g[x].size(); t++) {
				if (g[x][t] < 0) {
					g[x][t] = -g[x][t];
					out[x]++;
				}
			}
		}
		if (check()) printf("YES\n");
		else printf("NO\n");
	}
}
