#include<bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define ft first
#define sd second
#define mkp make_pair
const int N = 2e5 + 10;
using namespace std;
int n, q, k, f[N][25], d[N], num[N], a[N], now[N], vis[N], cnt, ans;
vector <int> e[N];
void dfs(int x) {
	for(int i = 0; i < (int)e[x].size(); ++i) {
		int sx = e[x][i];
		if(sx == f[x][0]) continue;
		d[sx] = d[x] + 1; f[sx][0] = x;
		dfs(sx);
	}
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	for(int i = 20; i >= 0; --i) if(d[u] - (1 << i) >= d[v]) u = f[u][i];
	if(u == v) return u;
	for(int i = 20; i >= 0; --i) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}
void clear() {
	for(int i = 1; i <= cnt; ++i) {
		if(i == 1) num[i] = a[now[i]];
		else num[i] = INT_MAX;
	}
}
void cnt1(int x, int y) {
	while(d[x] >= d[y]) {
		now[++cnt] = x;
		x = f[x][0];
	}
}
void cnt2(int x, int y) {
	if(d[x] <= d[y]) return ;
	cnt2(f[x][0], y);
	now[++cnt] = x;
}
void dfs1(int x, int sum, int y) {
	vis[x] = 1;
	if(x == y) ans = min(ans, sum);
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) continue;
		int Lca = lca(i, x);
		int dis = d[x] + d[i] - 2 * d[Lca];
		if(dis <= k) {
			dfs1(i, sum + a[i], y);
			vis[i] = 0;
		}
	}
}
signed main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &q, &k);
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	} d[1] = 1; dfs(1);
	for(int i = 1; i <= 20; ++i) {
		for(int j = 1; j <= n; ++j) {
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	if(n <= 10) {
		for(int i = 1; i <= q; ++i) {
			int s, t; scanf("%lld%lld", &s, &t);
			ans = LLONG_MAX; dfs1(s, a[s], t);
			vis[s] = 0; printf("%lld\n", ans);
		} return 0;
	}
	for(int i = 1; i <= q; ++i) {
		int s, t; scanf("%lld%lld", &s, &t);
		int Lca = lca(s, t); cnt = 0;
		cnt1(s, Lca); cnt2(t, Lca); clear();
		for(int j = 1; j <= cnt; ++j) {
			for(int p = 1; p <= k; ++p) {
				num[p + j] = min(a[now[p + j]] + num[j], num[p + j]);
			}
		}
		printf("%lld\n", num[cnt]);
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

10 1 3
8 9 4 2 3 7 5 10 1 6
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
10 5

10 10 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7

*/
