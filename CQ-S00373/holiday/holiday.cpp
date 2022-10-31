#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 2505;
int n, m, k, w[MAXN], ans, b[MAXN];
bool vis[MAXN];
struct node {
	int step, u;
} t1, t2;
vector<int> G[MAXN], r[MAXN];
void bfs(int x) {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	queue<node> q;
	t1.step = 0, t1.u = x;
	q.push(t1);
	vis[x] = 1;
	while (!q.empty()) {
		t1 = q.front();
		q.pop();
		if (t1.step == k + 1) continue;
		vis[t1.u] = 1;
		int len = G[t1.u].size(), u = t1.u;
		for (int i = 0; i < len; i++) {
			if (!vis[G[u][i]]) {
				t2.step = t1.step + 1, t2.u = G[u][i];
				r[x].push_back(t2.u);
				q.push(t2);
			}
		}
	}
}
void dfs(int x, int cnt, int sum) {
	if (cnt == 4) {
		int f = 0, len = r[x].size();
		for (int i = 0; i < len; i++) {
			if (r[x][i] == 1) {
				f = 1;
				break;
			}
		}
		if (f) ans = max(ans, sum);
		return;
	}
	int len = r[x].size();
	for (int i = len - 1; i >= 0; i--) {
		if (!vis[r[x][i]]) {
			vis[r[x][i]] = 1;
			dfs(r[x][i], cnt + 1, sum + w[r[x][i]]);
			vis[r[x][i]] = 0;
		}
	}
}
bool cmp(int x, int y) {
	return w[x] < w[y];
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 2; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) bfs(i);
	for (int i = 1; i <= n; i++) vis[i] = 0;
	vis[1] = 1;
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}
