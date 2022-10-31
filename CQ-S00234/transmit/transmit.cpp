#include <stdio.h>
#include <math.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct {
	int nxt;
	int end;
} Edge;

int cnt = 0;
int v[200007], deg[200007], head[200007], depth[200007], fa[200007][18], path1[200007], path2[200007], path[200007];
ll sum[200007], dis[2007][2007], dp[200007][7];
bool vis[2007][2007];
Edge edge[400007];
priority_queue<pair<ll, int> > q;
vector<int> vec[200007];

inline void init(int n){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = 0x7fffffffffffffffll;
		}
	}
}

inline void add_edge(int start, int end){
	cnt++;
	edge[cnt].nxt = head[start];
	head[start] = cnt;
	edge[cnt].end = end;
}

void dfs(int u, int father){
	depth[u] = depth[father] + 1;
	int t = log2(depth[u]);
	fa[u][0] = father;
	for (int i = 1; i <= t; i++){
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	sum[u] = sum[father] + v[u];
	for (int i = head[u]; i != 0; i = edge[i].nxt){
		int x = edge[i].end;
		if (x != father) dfs(x, u);
	}
}

inline int lca(int u, int v){
	if (depth[u] < depth[v]) swap(u, v);
	while (depth[u] > depth[v]) u = fa[u][(int)log2(depth[u] - depth[v])];
	if (u == v) return u;
	for (int i = log2(depth[u]); i >= 0; i--){
		if (fa[u][i] != fa[v][i]){
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

void dijkstra(int start, int n){
	dis[start][start] = v[start];
	q.push(make_pair(-v[start], start));
	while (!q.empty()){
		int cur = q.top().second;
		q.pop();
		if (vis[start][cur]) continue;
		vis[start][cur] = true;
		for (int x : vec[cur]){
			ll y = dis[start][cur] + v[x];
			if (dis[start][x] > y){
				dis[start][x] = y;
				q.push(make_pair(-y, x));
			}
		}
	}
}

typedef struct {
	ll a[2][2];
} Matrix;

int min_val[200007], near2[200007];
Matrix ama[200007], up[200007][18], down[200007][18];

Matrix operator *(Matrix a, Matrix b){
	Matrix ans;
	ans.a[0][0] = min(a.a[0][0] + b.a[0][0], a.a[0][1] + b.a[1][0]);
	ans.a[0][1] = min(a.a[0][0] + b.a[0][1], a.a[0][1] + b.a[1][1]);
	ans.a[1][0] = min(a.a[1][0] + b.a[0][0], a.a[1][1] + b.a[1][0]);
	ans.a[1][1] = min(a.a[1][0] + b.a[0][1], a.a[1][1] + b.a[1][1]);
	return ans;
}

void dfs_mat(int u){
	int t = log2(depth[u]);
	Matrix mat1;
	mat1.a[0][0] = mat1.a[1][0] = v[u];
	mat1.a[0][1] = 0;
	mat1.a[1][1] = 1e18;
	ama[u] = up[u][0] = down[u][0] = mat1;
	for (int i = 1; i <= t; i++){
		up[u][i] = up[u][i - 1] * up[fa[u][i - 1]][i - 1];
		down[u][i] = down[fa[u][i - 1]][i - 1] * down[u][i - 1];
	}
	for (int i = head[u]; i != 0; i = edge[i].nxt){
		int x = edge[i].end;
		if (x != fa[u][0]) dfs_mat(x);
	}
}

Matrix get_up(int u, int v){
	Matrix ans;
	ans.a[0][0] = ans.a[1][1] = 0;
	ans.a[0][1] = ans.a[1][0] = 1e18;
	while (depth[u] > depth[v]){
		int x = log2(depth[u] - depth[v]);
		ans = ans * up[u][x];
		u = fa[u][x];
	}
	if (u == v) ans = ans * ama[u];
	return ans;
}

Matrix get_down(int u, int v){
	Matrix ans;
	ans.a[0][0] = ans.a[1][1] = 0;
	ans.a[0][1] = ans.a[1][0] = 1e18;
	while (depth[u] > depth[v] + 1){
		int x = log2(depth[u] - depth[v] - 1);
		ans = down[u][x] * ans;
		u = fa[u][x];
	}
	if (depth[u] > depth[v]) ans = ama[u] * ans;
	return ans;
}

int main(){
	int n, q, k;
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		min_val[i] = near2[i] = 0x7fffffff;
	}
	for (int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		min_val[a] = min(min_val[a], v[b]);
		min_val[b] = min(min_val[b], v[a]);
		deg[a]++;
		deg[b]++;
		add_edge(a, b);
		add_edge(b, a);
	}
	for (int i = 1; i <= n; i++){
		for (int j = head[i]; j != 0; j = edge[j].nxt){
			int x = edge[j].end;
			near2[x] = min(near2[x], min_val[i]);
		}
	}
	dfs(1, 0);
	if (k == 1){
		for (int i = 1; i <= q; i++){
			int s, t;
			scanf("%d %d", &s, &t);
			printf("%lld\n", sum[s] + sum[t] - sum[fa[lca(s, t)][0]] * 2);
		}
	} else if (n <= 200){
		init(n);
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				if (depth[i] + depth[j] - depth[lca(i, j)] * 2 <= k){
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}
		for (int i = 1; i <= n; i++){
			dijkstra(i, n);
		}
		for (int i = 1; i <= q; i++){
			int s, t;
			scanf("%d %d", &s, &t);
			printf("%lld\n", dis[s][t]);
		}
	} else if (k == 2){
		dfs_mat(1);
		for (int i = 1; i <= q; i++){
			int s, t;
			scanf("%d %d", &s, &t);
			int cur_lca = lca(s, t);
			Matrix mat;
			if (cur_lca == s){
				mat.a[0][0] = mat.a[1][1] = 0;
				mat.a[0][1] = mat.a[1][0] = 1e18;
			} else {
				mat = get_up(fa[s][0], cur_lca);
			}
			if (cur_lca != t) mat = mat * get_down(t, cur_lca);
			printf("%lld\n", mat.a[0][0] + v[s]);
		}
	} else {
		for (int i = 1; i <= q; i++){
			int s, t;
			scanf("%d %d", &s, &t);
			int cur_lca = lca(s, t);
			int tot1 = 0, tot2 = 0, tot = 0;
			for (int j = s; j != cur_lca; j = fa[j][0]){
				path1[++tot1] = j;
			}
			for (int j = t; j != cur_lca; j = fa[j][0]){
				path2[++tot2] = j;
			}
			for (int j = 1; j <= tot1; j++){
				path[++tot] = path1[j];
			}
			path[++tot] = cur_lca;
			for (int j = tot2; j >= 1; j--){
				path[++tot] = path2[j];
			}
			dp[1][0] = v[s];
			dp[1][1] = dp[1][2] = 1e18;
			for (int j = 2; j <= tot; j++){
				for (int p = 0; p <= 2; p++){
					dp[j][p] = 1e18;
					for (int k = 1; k <= min(j - 1, 3); k++){
						for (int q = 0; p + q + k <= 3; q++){
							dp[j][p] = min(dp[j][p], dp[j - k][q]);
						}
					}
					if (p == 0) dp[j][p] += v[path[j]];
					else if (p == 1) dp[j][p] += min_val[path[j]];
					else dp[j][p] += near2[path[j]];
				}
			}
			printf("%lld\n", dp[tot][0]);
		}
	}
	return 0;
}
