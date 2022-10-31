#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 5e5 + 5;
int out_deg[MAXN], n, m, x[MAXN], y[MAXN], T;
bool visd[MAXN], visb[MAXN];
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &x[i], &y[i]);
	scanf("%d", &T);
	while (T--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			for (int i = 1; i <= m; i++) {
				if (x[i] == u && y[i] == v) {
					visb[i] = 1;
					break;
				}
			} 
		} else if (op == 2) {
			int u;
			scanf("%d", &u);
			for (int i = 1; i <= m; i++) {
				if (y[i] == u) {
					visb[i] = 1;
				}
			}
		} else if (op == 3) {
			int u, v;
			scanf("%d %d", &u, &v);
			for (int i = 1; i <= m; i++) {
				if (x[i] == u && y[i] == v) {
					visb[i] = 0;
					break;
				}
			}
		} else {
			int u;
			scanf("%d", &u);
			for (int i = 1; i <= m; i++) {
				if (y[i] == u) {
					visb[i] = 0;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			out_deg[i] = 0;
		bool f = 0;
		for (int i = 1; i <= m; i++) {
			if (!visb[i])
				out_deg[x[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			if (out_deg[i] != 1) {
				f = 1;
				break;
			}
		} 
		if (!f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 
