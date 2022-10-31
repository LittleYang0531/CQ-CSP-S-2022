#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 5e5;
int n, m, q, tot, sum;
bool vis[MAXN];
vector<int> G[MAXN];
//struct node {
//	int cnt, a[MAXN];
//} rd[MAXN], cd[MAXN];
void dfs(int k) {
	if (tot == n) return;
	int len = G[k].size();
	for (int i = 0; i < len; i++) {
		if (!vis[G[k][i]]) {
			vis[G[k][i]] = 1;
			tot++;
			dfs(G[k][i]);
			if (tot == n) return;
		}
	}
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		if (G[i].size() == 1) sum++;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int t, u, v;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d", &u, &v);
			int len = G[u].size(), b[MAXN], cnt = 0;
			if (len == 2) sum++;
			if (len == 1) sum--;
			for (int j = 0; j < G[u].size(); j++)
				if (G[u][j] != v)
					b[cnt++] = G[u][j];
			G[u].clear();
			for (int i = 0; i < cnt; i++)
				G[u].push_back(b[i]);
		} else if (t == 3) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			if (G[u].size() == 2) sum--;
			if (G[u].size() == 1) sum++;
		}
//		printf("===\n%d\n===\n", sum);
		if (sum == n) {
			printf("YES\n");
//			for (int i = 1; i <= n; i++) vis[i] = 0;
//			vis[1] = 1;
//			tot = 1;
//			dfs(1);
//			if (tot == n) printf("YES\n");
//			else printf("NO\n");
		} else printf("NO\n");
	}
	return 0;
}
