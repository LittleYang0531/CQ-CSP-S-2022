#include <bits/stdc++.h>
#define int long long
#define re register
using namespace std;
const int maxn = 3e2 + 2;
int n, m, k;
int ans = -1;
int vis[maxn];
int f[maxn][maxn];
int pnt[maxn];
inline void dfs(int x, int cnt, int sum) {
	if(cnt > 5) return ;
	if(cnt == 5 && f[x][1] <= k + 1) {
		ans = max(ans, sum);
		return ;
	}
	for(re int i = 2; i <= n; ++ i) {
		if(!vis[i] && f[x][i] <= k + 1) {
			vis[i] = true;
			dfs(i, cnt + 1, sum + pnt[i]);
			vis[i] = false;
		}
	}
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
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(re int i = 2; i <= n; ++ i) pnt[i] = read();
	memset(f, 0x3f, sizeof(f));
	for(re int i = 1; i <= n; ++ i) f[i][i] = 0;
	for(re int i = 1; i <= m; ++ i) {
		int u = read(), v = read();
		f[u][v] = f[v][u] = 1;
	}
	for(re int p = 1; p <= n; ++ p) {
		for(re int i = 1; i <= n; ++ i) {
			for(re int j = 1; j <= n; ++ j) {
				f[i][j] = min(f[i][j], f[i][p] + f[p][j]);
			}
		} 
	} 
	dfs(1, 1, 0);
	printf("%d", ans);
	return 0;
} 
