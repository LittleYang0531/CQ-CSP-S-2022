#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 5, maxv = 2505;
struct node {
	int v, nxt;
} e[maxn << 1];
int n, m, k, head[maxv], cnt, vis[maxv];
ll val[maxn], ans = -1;
void add_edge(int u, int v) {
	e[++cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void dfs(int now, int num, int cnt, ll sum) {
	//cout << now << " " << num << " " << cnt << " " << sum << endl;
	if (cnt == 5) {
		if (now == 1) ans = max(ans, sum);
		return;
	}
	for (int i = head[now]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (num < k) 
			dfs(v, num + 1, cnt, sum);
		if (!vis[v]) {
			vis[v] = 1;
			dfs(v, 0, cnt + 1, sum + val[v]);
			vis[v] = 0;
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 2; i <= n; i++) {
		scanf("%lld", &val[i]);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(1, 0, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
