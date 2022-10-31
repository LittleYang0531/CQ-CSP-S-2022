// % Alex_wei

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define pli pair<ll, int>
#define mp make_pair
#define fir first
#define sec second
using namespace std;
const int N = 2505, M = 1e4 + 5;
const int inf = 0x3f3f3f3f;

int n, m, K, f[N], id1[2][N], id2[2][N];
ll a[N], mx1[2][N], mx2[2][N];
pli ta[10], tb[10];
vector<pli> v1[N], v2[N];

int cnt, elst[N];
struct edge {
	int to, nxt;
} e[M << 1];
void add(int u, int v) {
	e[++cnt].to = v;
	e[cnt].nxt = elst[u];
	elst[u] = cnt;
}

int tim, dis[N][N], vis[N];
queue<int> q;
void bfs(int s) {
	dis[s][s] = -1;
	q.push(s);
	vis[s] = tim;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = elst[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (vis[v] == tim) continue;
			if (dis[s][u] + 1 > K) continue;
			dis[s][v] = dis[s][u] + 1;
			q.push(v);
			vis[v] = tim;
		}
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &K);
	for (int i = 2; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
	}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++) dis[i][j] = dis[j][i] = inf;
	for (int i = 1; i <= n; i++) tim++, bfs(i);
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++) {
			if (i == j) continue;
			if (dis[1][i] == inf || dis[i][j] == inf) continue;
			v1[j].push_back(mp(-a[i], i));
		}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == j) continue;
			if (dis[i][j] == inf || dis[j][1] == inf) continue;
			v2[i].push_back(mp(-a[j], j));
		}
	}
	for (int i = 1; i <= n; i++) sort(v1[i].begin(), v1[i].end()), sort(v2[i].begin(), v2[i].end());
	ll ans = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++) {
			if (i == j || dis[i][j] == inf) continue;
			if (v1[i].empty() || v2[j].empty()) continue;
			int c1 = 0, c2 = 0;
			pli x, y;
			for (int k = 0, p = v1[i].size(); k < min(3, p); k++) ta[c1++] = v1[i][k];
			for (int k = 0, p = v2[j].size(); k < min(3, p); k++) tb[c2++] = v2[j][k];
			for (int k = 0; k < c1; k++)
				for (int p = 0; p < c2; p++) {
					x = ta[k];
					y = tb[p];
					if (x.sec != y.sec && x.sec != j && y.sec != i) {ans = max(ans, a[i] + a[j] - x.fir - y.fir); break;}
				}
		}
	printf("%lld", ans);
	return 0;
}
