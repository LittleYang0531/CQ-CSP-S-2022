#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2500 + 5;
int n, m, k, x, y;
long long a[MAXN], ans;
bool vis[MAXN];
vector <int> G[MAXN];

void dfs (int step, int x, long long sum) {
	if (step == 6) {
		if (x == 1)
			ans = max (ans, sum);
		return;
	}
	bool v[MAXN] = {};
	int w[MAXN] = {};
	queue <int> q;
	q.push(x);
	while (q.size()) {
		int t = q.front(); q.pop();
		v[x] = 1;
		for (int i = 0; i < G[t].size(); i ++) {
			int to = G[t][i]; 
			if (!vis[to] && !v[to]) {
				w[to] = w[t] + 1;
				if (w[t] < k + 1) {
					q.push(to);
					if (step != 5 || to == 1) {
						vis[to] = 1;
						v[to] = 1, dfs (step + 1, to, sum + a[to]), vis[to] = 0;
					}
				}
			}
		}
	}
}

int main () {
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 2; i <= n; i ++)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= m; i ++) {
		scanf ("%d %d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs (1, 1, 0);
	printf ("%lld", ans);
	return 0;
} 
