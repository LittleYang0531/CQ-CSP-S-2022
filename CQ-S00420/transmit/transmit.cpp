#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 2e5 + 5;
int n, m, k, a, b;
int dep[N], f[N][25];
LL c[N], sum[N];
vector<int> G[N];
inline void dfs(int u, int fa){
	for (int i = 1; i <= 20; i++)
		f[u][i] = f[f[u][i - 1]][i - 1];
	dep[u] = dep[fa] + 1;
	sum[u] = sum[fa] + c[u];
	for (int v : G[u]){
		if (v == fa) continue;
		f[v][0] = u;
		dfs(v, u);
	}
}
inline int LCA(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	if (x == y) return y;
	for (int i = 20; i >= 0; i--)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
int main(){
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &c[i]);
	for (int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 0);
	while(m--){
		scanf("%d %d", &a, &b);
		printf("%lld\n", sum[a] + sum[b] - sum[LCA(a, b)]);
	}
	return 0;
}
