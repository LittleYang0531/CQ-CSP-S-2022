#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;

const int MAXN = 2e5 + 5; 
int n, q, k, x, y, a[MAXN], s, t;
int dis[MAXN];
bool vis[MAXN], v[MAXN];
vector <int> G[MAXN];

void dijkstra (int s) {
	memset (dis, 0x3f, sizeof dis);
	memset (vis, 0, sizeof vis);
	priority_queue <pair <int, int> > q;
	q.push(make_pair (0, s)), dis[s] = 0;
	while (q.size()) {
		int t = q.top().second; q.pop();
		if (vis[t])
			continue;
		vis[t] = 1;
		for (int i = 0; i < G[t].size(); i ++) {
			int to = G[t][i];
			if (dis[to] > dis[t] + 1)
				dis[to] = dis[t] + 1, q.push(make_pair (-dis[to], to));
		}
	}
}

int ans (int s, int t) {
	dijkstra (s);
	if (dis[t] <= k)
		return a[s] + a[t];
	int Min = inf;
	for (int i = 1; i <= n; i ++) {
		if (i != s && i != t && dis[i] <= k && !v[i])
			v[i] = 1, Min = min (Min, a[s] + ans (i, t)), v[i] = 0;
	}
	return Min;
}

int main () {
	freopen ("transmit.in", "r", stdin);
	freopen ("transmit.out", "w", stdout);
	scanf ("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &a[i]);
	for (int i = 1; i < n; i ++) {
		scanf ("%d %d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	while (q --) {
		scanf ("%d %d", &s, &t);
		dijkstra (s);
		if (dis[t] <= k) {
			printf ("%d\n", a[s] + a[t]);
		} else {
			memset (v, 0, sizeof v);
			v[s] = v[t] = 1;
			printf ("%d\n", ans (s, t));
		}
	}
	return 0;
} 
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
*/
