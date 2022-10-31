#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 998244353;
constexpr int N = 500010;
struct Edge {
	int dis, nxt;
} edges[N];
int head[N], siz;
void add(int from, int dis) {
	edges[++siz].dis = dis;
	edges[siz].nxt = head[from];
	head[from] = siz;
}
int n, m, u, v;
int ok[1010][1010], vis[N];
int f, is[N];
int in[N];
void dfs(int u) {
	if (vis[u]) {
		f = 1;
		return;
	}
	vis[u] = 1;
	if (f) {
		return;
	}
	for (int i = head[u]; i; i = edges[i].nxt) {
		dfs(edges[i].dis);
	}
}
bool check() {
	// 是否可以实现反击 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[j] = 0;
		}
		f = 0;
		dfs(i);
		if (!f) {
			return false;
		}
	}
	// 是否可以实现连续穿梭
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = head[i]; j; j = edges[j].nxt) {
			if (!ok[i][edges[j].dis]) {
				continue;
			}
			res++;
		}
		if (res != 1) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);	
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		add(u, v);
		ok[u][v] = 1;
		is[v] = 1;
	}
	
	int q;
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int u, v;
			scanf("%d%d", &u, &v);
			ok[u][v] = 0;
		}
		if (op == 2) {
			int u;
			scanf("%d", &u);
			for (int i = 1; i <= n; i++) {
				ok[i][u] = 0;
			}
		}
		if (op == 3) {
			int u, v;
			scanf("%d%d", &u, &v);
			ok[u][v] = 1;
		}
		if (op == 4) {
			int u;
			scanf("%d", &u);
			for (int i = 1; i <= n; i++) {
				ok[i][u] = 1;
			}
		}
		printf("%s\n", check() ? "YES" : "NO");
	}
		
	return 0;
}
