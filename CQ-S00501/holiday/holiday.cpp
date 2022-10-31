#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 2505
using namespace std;
int n, m, k, c[MAXN];
vector <int> g[MAXN];
int dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct edge {
	int to, tot;
	bool operator < (const edge x) const {
		return tot > x.tot;
	}
};
void dijkstra(int s) {
	priority_queue <edge> q;
	q.push(edge({s, 0}));
	dis[s][s] = 0;
	while (!q.empty()) {
		int x = q.top().to;
		q.pop();
		if (vis[s][x]) continue;
		vis[s][x] = true;
		for (int t = 0; t < g[x].size(); t++) {
			int v = g[x][t];
			if (dis[s][x] + 1 < dis[s][v]) {
				dis[s][v] = dis[s][x] + 1;
				q.push(edge({v, dis[s][v]}));
			}
		}
	}
	return;
}
struct piont {
	long long c;
	int i;
	bool operator < (const piont x) const {
		return c > x.c;
	}
} a[MAXN];
bool flag[MAXN];
void dfs(int i, int left, int tot) {
	if (left == 0) {
		if (dis[a[i].i][1] - 1 <= k) {
			printf("%lld\n", tot);
			exit(0);
		}
		return;
	}
	for (int j = 2; j <= n; j++) {
		if (dis[a[i].i][a[j].i] - 1 <= k && !flag[j]) {
			flag[j] = true;
			dfs(j, left - 1, tot + a[j].c);
			flag[j] = false;
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 2; i <= n; i++) {
		scanf("%lld", &a[i].c);
		a[i].i = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	sort(2 + a, 2 + a + n);
	a[1].i = 1;
	dfs(1, 4, 0);
	return 0;
} 
