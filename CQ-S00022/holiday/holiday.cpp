#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 2500 + 5;
vector<int> G[MAXN];
long long n, m, p, w[MAXN], dis[MAXN][MAXN], dp[MAXN][105], ans, a[MAXN][8];
bool vis[MAXN];
struct node{
	long long u, w;
	node (long long U, long long W) {
		u = U;
		w = W;
	}
	bool operator < (const node& a) const { return w > a.w; } 
};
priority_queue<node> q;
void Dijkstra(long long x) {
	memset(vis, 0, sizeof(vis));
	dis[x][x] = 0;
	q.push(node(x, 0));
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.u])
			continue;
		vis[t.u] = 1;
		for (int i = 0; i < G[t.u].size(); i++) {
			if (dis[x][G[t.u][i]] > dis[x][t.u] + 1) {
				dis[x][G[t.u][i]] = dis[x][t.u] + 1;
				q.push(node(G[t.u][i], dis[x][G[t.u][i]]));
			}
		}
	}
} 
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = 0x3f3f3f3f;
	for (int i = 2; i <= n; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= m; i++) {
		long long u, v;
		scanf("%lld %lld", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		Dijkstra(i);
	for (int i1 = 2; i1 <= n; i1++) {
		for (int i2 = 2; i2 <= n; i2++) {
			if (i1 == i2)
				continue;
			for (int i3 = 2; i3 <= n; i3++) {
				if (i1 == i3 || i2 == i3)
					continue;
				for (int i4 = 2; i4 <= n; i4++) {
					if (i1 == i4 || i2 == i4 || i3 == i4)
						continue;
					if (dis[i1][1] <= p + 1 && dis[i2][i1] <= p + 1 && dis[i3][i2] <= p + 1 && dis[i4][i3] <= p + 1 && dis[i4][1] <= p + 1) {
						ans = max(ans, w[i1] + w[i2] + w[i3] + w[i4]);
					}
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
/*	
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4


8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

*/
