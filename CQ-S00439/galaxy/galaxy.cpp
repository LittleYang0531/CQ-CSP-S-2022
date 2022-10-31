#include <bits/stdc++.h>
#define int long long
#define re register
using namespace std;
const int maxn = 1e3 + 2;
int n, m, q;
int od[maxn];
vector<int> a[maxn];
vector<int> g[maxn];
int f[maxn][maxn]; 
int vis[maxn];
inline bool dfs(int x) {
	for(re int i = 0; i < g[x].size(); ++ i) {
		int v = g[x][i];
		if(vis[v]) return true;
		vis[v] = true;
	}
	return false;
}
inline bool check() {
	bool a = true;
	bool b = true;
	for(re int i = 1; i <= n; ++ i) {
		if(od[i] != 1) a = false;
	} 
	for(re int i = 1; i <= n; ++ i) {
		memset(vis, 0, sizeof(vis));
		b = b && dfs(i);
	}
	if(a == 1 && b == 1) return true;
	return false;
}
inline int read() {
	int sum = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		sum = (sum << 3) + (sum << 1) + (c ^ 48);
		c = getchar();
	}
	return f * sum;
}
signed main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	n = read(), m = read();
	for(re int i = 1; i <= m; ++ i) {
		int u = read(), v = read();
		++ od[u];
		a[v].push_back(u);
		g[u].push_back(v);
		f[u][v] = 1;
	}
	int q = read();
	for(re int i = 1; i <= q; ++ i) {
		int t = read();
		if(t == 1) {
			int u = read(), v = read();
			if(f[u][v]) {
				f[u][v] = 1;
				-- od[u];
			}
		}else if(t == 2) {
			int u = read();
			for(re int i = 0; i < a[u].size(); ++ i) {
				int v = a[u][i];
				if(f[v][u]) {
					f[v][u] = 0;
					-- od[v];
				}
			}
		}else if(t == 3) {
			int u = read(), v = read();
			if(!f[u][v]) {
				f[u][v] = 1;
				++ od[u];
			}
		}else{
			int u = read();
			for(re int i = 0; i < a[u].size(); ++ i) {
				int v = a[u][i];
				if(!f[v][u]) {
					f[v][u] = 1;
					++ od[v];
				}
			}
		}
		if(check()) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}
	} 
	return 0;
} 

