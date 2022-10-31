#include <bits/stdc++.h>
#include <limits.h>
#define rep1(i, j, n) for (int i(j); i <= (int)n; ++i)
#define rep2(i, j, n) for (int i(j); i >= (int)n; --i)
#define int long long
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) f -= (ch == '-') << 1, ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
	x *= f;
}
inline int read() {int x; read(x); return x;}
template <typename T, typename ...L> inline void read(T &x, L &...y) {read(x); read(y...);}
const int inf = 0x3f3f3f3f;
const int N = 2505, M = 1e4 + 5, K = 105;
int n, m, k, head[N], nex[M << 1], tot, a[N];
struct E {int to, nxt;} edge[M << 1];
inline void add(int x, int y) {edge[++tot] = (E) {x, y}; nex[tot] = head[x]; head[x] = tot;}
bool to1[N];
int dis[N][N];
bool vis[N];
inline int fmx(int x, int fa, int num) {
	if (num == 4) return 0;
	int ans = -LLONG_MAX;
	for (int i = head[x]; i; i = nex[i]) {
		int v = edge[i].nxt;
		if (v == fa) continue;
		if (num == 3 && !to1[v]) continue;
		ans = max(ans, a[v] + fmx(v, x, num + 1));
	} return ans;
}
inline void bfs(int root) {
	queue <int> q;
	memset(vis, 0, sizeof vis);
	q.push(root);
	vis[root] = 1;
	dis[root][root] = -1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = nex[i]) {
			int v = edge[i].nxt;
			if (vis[v]) continue;
			dis[root][v] = dis[root][u] + 1;
			vis[v] = 1;
			q.push(v);
		}
	}
}
vector <int> co[N];
signed main(void) {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n, m, k);
	rep1(i, 2, n) read(a[i]);
	rep1(i, 1, m) {
		int u, v; read(u, v);
		add(u, v); add(v, u);
	} 
	if (!k) {
		for (int i = head[1]; i; i = nex[i]) {
			int v = edge[i].nxt;
			to1[v] = 1;
		}
		int ans = 0;
		for (int i = head[1]; i; i = nex[i]) {
			int v = edge[i].nxt;
			ans = max(ans, a[v] + fmx(v, 1, 1));
		}
		printf("%lld", ans);
	} else {
		rep1(i, 1, n) {
			bfs(i);
			rep1(j, 1, n) if (dis[i][j] <= k) co[i].emplace_back(j);
		}
		int ans = 0;
		for (auto i : co[1]) {
			if (i == 1) continue;
			for (auto j : co[i]) {
				if (j == 1 || j == i) continue;
				for (auto K : co[j]) {
					if (K == j || K == i || K == 1) continue;
					for (auto p : co[K]) {
						if (p == 1 || p == K || p == i || p == j) continue;
						if (dis[1][p] > k) continue;
						ans = max(ans, a[i] + a[j] + a[K] + a[p]);
					}
				}
			}
		}
		printf("%lld", ans);
	}
}
/*
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
*/
