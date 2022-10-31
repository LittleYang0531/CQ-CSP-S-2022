#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e3 + 5;
struct node {
	int v, nxt;
} e[maxn << 1];
int n, q, k, head[maxn], cnt, dis[maxn][maxn], fl, vis[maxn];
ll a[maxn], M = 1e18, p;
void add_edge(int u, int v) {
	e[++cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void init(int s, int t, int now, int k) {
	if (fl) return;
	if (now == t) {
		dis[s][t] = k;
		fl = 1;
		return;
	}
	for (int i = head[now]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (!vis[v]) {
			vis[v] = 1;
			init(s, t, v, k + 1);
			vis[v] = 0;
			if (fl) return;
		}
	}
}
void dfs(int now, int t, ll sum) {
	if (sum > M) return;
	if (now == t) {
		M = sum;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && dis[now][i] <= k && now != i) {
			vis[i] = 1;
			dfs(i, t, sum + a[i]);
			vis[i] = 0;
		}
	}
}
void dfs2(int now, int t, ll sum) {
	if (fl) return;
	if (now == t) {
		p = sum;
		fl = 1;
		return;
	}
	for (int i = head[now]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (!vis[v]) {
			vis[v] = 1;
			dfs2(v, t, sum + a[v]);
			vis[v] = 0;
		}
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	if (k == 1) {
		for (int i = 1; i <= q; i++) {
			int s, t;
			scanf("%d %d", &s, &t);
			p = 0;
			fl = 0;
			memset(vis, 0, sizeof(vis));
			vis[s] = 1;
			dfs2(s, t, a[s]);
			printf("%lld\n", p);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			fl = 0;
			init(i, j, i, 0);
			dis[j][i] = dis[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		if (dis[s][t] <= k) {
			printf("%lld\n", a[s] + a[t]);
			continue;
		}
		M = 1e18;
		memset(vis, 0, sizeof(vis));
		vis[s] = 1;
		dfs(s, t, a[s]);
		printf("%lld\n", M);
	}
	return 0;
}
