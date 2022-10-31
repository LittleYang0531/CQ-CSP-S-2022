#include <bits/stdc++.h>
using namespace std;
const long long N = 2505;
long long n, m, k, maxn, val[N];
vector<long long> G[N], GG[N];
long long f[N][N];
bool vis[N];
queue<long long> q;
void Dijkstra(long long s) {
	for (long long i = 1;i <= n;i++) {
		f[s][i] = 0x3f3f3f3f, vis[i] = 0;
	}
	f[s][s] = 0;
	q.push(s);
	while(!q.empty()) {
		long long t = q.front();
		q.pop();
		if (vis[t]) continue;
		vis[t] = 1;
		long long len = GG[t].size();
		for (long long i = 0;i < len;i++) {
			if (f[s][GG[t][i]] > f[s][t] + 1) {
				f[s][GG[t][i]] = f[s][t] + 1;
				q.push(GG[t][i]);
			}
		}
	}
} 
bool cmp(long long x, long long y) {
	return val[x] > val[y];
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	f[1][1] = 0;
	for (long long i = 2;i <= n;i++) {
		scanf("%lld", &val[i]);
		maxn = max(maxn, val[i]);
	}
	for (long long i = 1, x, y;i <= m;i++) {
		scanf("%lld%lld", &x, &y);
		GG[x].push_back(y);
		GG[y].push_back(x);
	}
	for (long long i = 1;i <= n;i++) {
		Dijkstra(i);
	}
	for (long long i = 1;i <= n;i++) {
		for (long long j = 1;j <= n;j++) {
			if (i != j && f[i][j] <= k + 1) G[i].push_back(j);
		}
	}
	for (long long i = 1;i <= n;i++) sort(G[i].begin(), G[i].end(), cmp);
	long long len1 = G[1].size();
	long long ans = -1;
	for (long long i = 0;i < len1;i++) {
		if (G[1][i] == 1) continue;
		long long len2 = G[G[1][i]].size();
		if (val[G[1][i]] + 3 * maxn <= ans) break;
		for (long long j = 0;j < len2;j++) {
			if (G[G[1][i]][j] == 1) continue;
			if (G[G[1][i]][j] == G[1][i]) continue;
			long long len3 = G[G[G[1][i]][j]].size();
			if (val[G[1][i]] + 2 * maxn + val[G[G[1][i]][j]] <= ans) break;
			for (long long k = 0;k < len3;k++) {
				if (G[G[G[1][i]][j]][k] == 1) continue;
				if (G[1][i] == G[G[G[1][i]][j]][k] || G[G[1][i]][j] == G[G[G[1][i]][j]][k]) continue;
				long long len4 = G[G[G[G[1][i]][j]][k]].size();
				if (val[G[1][i]] + maxn + val[G[G[G[1][i]][j]][k]] + val[G[G[1][i]][j]] <= ans) break;
				for (long long l = 0;l < len4;l++) {
					if (G[G[G[G[1][i]][j]][k]][l] == 1) continue;
					long long len5 = G[G[G[G[G[1][i]][j]][k]][l]].size();
					if (G[1][i] == G[G[G[G[1][i]][j]][k]][l] || G[G[1][i]][j] == G[G[G[G[1][i]][j]][k]][l] || G[G[G[1][i]][j]][k] == G[G[G[G[1][i]][j]][k]][l]) continue;
					for (long long r = 0;r < len5;r++) {
						if (G[G[G[G[G[1][i]][j]][k]][l]][r] == 1) ans = max(ans, val[G[1][i]] + val[G[G[G[G[1][i]][j]][k]][l]] + val[G[G[G[1][i]][j]][k]] + val[G[G[1][i]][j]]);
					}
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
