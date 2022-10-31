#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const ll inf = 1e18;
int a[N], nxt[N], fa[N][19], lg[N], dep[N], to[N], head[N], ecnt;
ll dis[N], dp[N];
void add_edge(int u, int v) {nxt[++ecnt] = head[u]; to[ecnt] = v; head[u] = ecnt;}
void dfs(int u) {
	for(int i = head[u]; i; i = nxt[i]) {
		int v = to[i]; if(v == fa[u][0]) continue;
		fa[v][0] = u; dep[v] = dep[u] + 1; dis[v] = dis[u] + a[v];
		for(int j = 1; j <= lg[dep[v]]; j++) fa[v][j] = fa[fa[v][j - 1]][j - 1];
		dfs(v);
	}
}

int LCA(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int k = dep[u] - dep[v]; for(int i = 0; i <= lg[k]; i++) if((1 << i) & k) u = fa[u][i];
	if(u == v) return u;
	for(int i = lg[dep[u]]; i >= 0; i--) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int st[N];

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
	
	int n, Q, k;
	scanf("%d%d%d", &n, &Q, &k);
	lg[1] = 0; for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v); add_edge(u, v), add_edge(v, u);
	}
	dfs(1);
	while(Q--) {
		int s, t, c;
		scanf("%d%d", &s, &t);
//		printf("!%d %d\n", s, t);
		c = LCA(s, t);
//		printf("!C=%d\n", c);
		if(k == 1) {printf("%lld\n", dis[s] + dis[t] - 2 * dis[c] + a[c]);}
		int cnt = dep[s] + dep[t] - 2 * dep[c] + 1, tt = 0, lst = cnt;
		while(s != c) {
			st[++tt] = s;
			s = fa[s][0];
		}
		st[++tt] = c;
		while(t != c) {
			st[lst--] = t;
			t = fa[t][0];
		}
//		for(int i = 1; i <= cnt; i++) {printf("%d ", st[i]);}
//		puts("");
		dp[1] = a[st[1]]; 
//		printf("%lld ", a[st[1]]);
		for(int i = 2; i <= cnt; i++) {
			int x = st[i];
			dp[i] = dp[i - 1];
			for(int t = 2; t <= k; t++) {
				if(t < i) dp[i] = min(dp[i], dp[i - t]);
			}
			dp[i] += a[x];
//			printf("!dp[%d]=%lld val=%lld\n", i, dp[i], a[x]);
		}
		printf("%lld\n", dp[cnt]);
	}
	return 0;
}
//10 10 3
//835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
//2 1
//3 2
//4 2
//5 3
//6 3
//7 2
//8 7
//9 1
//10 9
//
//10 5

