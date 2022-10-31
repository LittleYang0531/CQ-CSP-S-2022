// De¡ýsert¡ü You
// You should look CQ-J00423
// STL give me power pls!(
// 20pts + 16pts + 8pts + 24pts
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
namespace yj{
const int MAXN = 200005;
struct edge {
	int to, nxt;
} edges[MAXN << 1];
int head[MAXN], tot;
void add(int u, int v) {
	edges[++tot].to = v; edges[tot].nxt = head[u]; head[u] = tot;
}
int n, k, q;
int v[MAXN];
namespace Sub1 {
	// n <= 200
	int dist[205][205];
	void dfs(int s, int u, int f, int d) {
		dist[s][u] = d; for (int i = head[u]; i; i = edges[i].nxt) {
			if (edges[i].to != f) dfs(s, edges[i].to, u, d + 1);
		}
	}
	void Dijk(int s, int t) {
		static long long dp[205]; static bool vis[205];
		for (int i = 1; i <= n; i++) vis[i] = 0, dp[i] = 0x3f3f3f3f3f3f3f3f;
		dp[s] = v[s]; priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
		pq.push(make_pair(v[s], s));
		while (pq.empty() == 0) {
			int u = pq.top().second; pq.pop(); if (vis[u]) continue; vis[u] = 1;
			for (int i = 1; i <= n; i++) {
				if (dist[u][i] <= k && dp[i] > dp[u] + v[i]) {
					dp[i] = dp[u] + v[i]; pq.push(make_pair(dp[i], i));
				}
			}
		}
		printf("%lld\n", dp[t]);
	}
	int main() {
		for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d %d", &u, &v); add(u, v); add(v, u);
		}
		for (int i = 1; i <= n; i++) dfs(i, i, i, 0);
		while (q--) {
			int a, b; scanf("%d %d", &a, &b); Dijk(a, b);
		}
		return 0;
	}
}
namespace Sub2 {
	// k == 1
	namespace lca {
		int fa[MAXN][19], dep[MAXN];
		void dfs(int u, int f) {
			fa[u][0] = f;
			for (int i = 1; i <= 18; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
			for (int i = head[u]; i; i = edges[i].nxt) {
				if (edges[i].to == f) continue;
				dep[edges[i].to] = dep[u] + 1;dfs(edges[i].to, u);
			}
		}
		int lca(int u, int v) {
			if (dep[u] < dep[v]) swap(u, v);
			for (int i = 18; ~i; i--) if (dep[u] - (1 << i) >= dep[v]) u = fa[u][i];
			if (u == v) return u;
			for (int i = 18; ~i; i--) if (fa[u][i] != fa[v][i]) u =fa[u][i], v = fa[v][i];
			return fa[u][0];
		}
	}
	long long dep[MAXN];
	void dfs(int u, int f) {
		for (int i = head[u]; i; i = edges[i].nxt) {
			if (edges[i].to == f) continue;
			dep[edges[i].to] = dep[u] + v[edges[i].to];
			dfs(edges[i].to, u);
		}
	}
	int main() {
		for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d %d", &u, &v); add(u, v); add(v, u);
		}
		lca::dfs(1, 1);
		dep[1] = v[1];
		dfs(1, 1);
		while (q--) {
			int a, b; scanf("%d %d", &a, &b);
			int l = lca::lca(a, b);
			if (l == 1) printf("%lld\n", dep[a] + dep[b] - dep[l]);
			else printf("%lld\n", dep[a] + dep[b] - dep[l] - dep[lca::fa[l][0]]);
		}
		return 0;
	}
}
namespace Sub3 {
	// k == 2
		struct wq {
			long long p[2][2]; int len;
			wq() {p[0][0] = p[0][1] = p[1][0] = p[1][1] = len = 0;}
			wq operator + (const wq&sec) const {
				wq res;
				if (len == 0) return sec;
				if (sec.len == 0) return *this;
				if (len == 1) {
					int num = p[0][1];
					if (sec.len == 1) {
						int num2 = sec.p[0][1];
						res.p[0][0] = num; res.p[0][1] = num + num2;
						res.p[1][0] = num2; res.p[1][1] = num2;
					}
					else {
						res.p[0][0] = num + min(sec.p[0][0], sec.p[0][1]);
						res.p[0][1] = num + min(sec.p[0][1], sec.p[1][1]);
						res.p[1][0] = sec.p[0][0]; res.p[1][1] = sec.p[0][1];
					}
				}
				else {
					if (sec.len == 1) {
						int nu2 = sec.p[0][1];
						res.p[0][0] = min(p[0][1], p[0][0] + nu2);
						res.p[0][1] = p[0][0] + nu2;
						res.p[1][0] = min(p[1][1], p[0][0] + nu2);
						res.p[1][1] = p[1][0] + nu2;
					}
					else {
					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							res.p[i][j] = min(p[i][0] + sec.p[0][j], p[i][1] + sec.p[1][j]);
						}
					}
				}
				}
					res.len = len + sec.len;
				return res;
			}
		};
	namespace sgt {
		wq dp[MAXN << 2];
		void pushup(int rt) {
			dp[rt] = dp[rt << 1 | 1] + dp[rt << 1];
		}
		void build(int rt, int l, int r, int *a) {
			if (l == r) {
//				printf("%d %d %d %d\n", rt, l, r, a[l]);
				dp[rt].p[0][1] = a[l];
				dp[rt].len = 1;
			}
			else {
				int mid = (l + r) >> 1;
				build(rt << 1, l, mid, a); build(rt << 1 | 1, mid + 1, r, a);
				pushup(rt);
			}
		}
		wq query(int rt, int l, int r, int x, int y) {
			if (x <= l && r <= y) {return dp[rt];
			}
			else {
				int mid = (l + r) >> 1;
				if (x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
				else if (y <= mid) return query(rt << 1, l, mid, x, y);
				else {
					wq a = query(rt << 1 | 1, mid + 1, r, x, y);
					wq b = query(rt << 1, l, mid, x, y);
					return a + b;
				}
			}
		}
	}
	namespace sgtinv {
		wq dp[MAXN << 2];
		void pushup(int rt) {
			dp[rt] = dp[rt << 1] + dp[rt << 1 | 1];
		}
		void build(int rt, int l, int r, int *a) {
			if (l == r) {
				dp[rt].p[0][1] = a[l];
				dp[rt].len = 1;
			}
			else {
				int mid = (l + r) >> 1;
				build(rt << 1, l, mid, a); build(rt << 1 | 1, mid + 1, r, a);
				pushup(rt);
			}
		}
		wq query(int rt, int l, int r, int x, int y) {
//			printf("%d %d %d %d %d\n", rt, l, r, x, y);
			if (x <= l && r <= y) {return dp[rt];
			}
			else {
				int mid = (l + r) >> 1;
				if (x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
				else if (y <= mid) return query(rt << 1, l, mid, x, y);
				else {
					wq a = query(rt << 1, l, mid, x, y);
					wq b = query(rt << 1 | 1, mid + 1, r, x, y);
					return a + b;
				}
			}
		}
	}
	int w[MAXN];
	namespace cut {
		int dep[MAXN], siz[MAXN], maxson[MAXN], fa[MAXN];
		void dfs(int u, int f) {
			fa[u] = f; siz[u] = 1; for (int i = head[u]; i; i = edges[i].nxt) {
				if (edges[i].to == f) continue; dep[edges[i].to] = dep[u] + 1; dfs(edges[i].to, u);
				siz[u] += siz[edges[i].to]; if (maxson[u] == 0 || siz[maxson[u]] < siz[edges[i].to]) maxson[u] = edges[i].to;
			}
		}
		int top[MAXN], dfn[MAXN], low[MAXN], times;
		void dfs2(int u, int tp) {
//			printf("%d %d\n", u, tp);
			top[u] = tp; dfn[u] = ++times; if (maxson[u]) dfs2(maxson[u], tp);
			w[dfn[u]] = v[u];
			for (int i = head[u]; i; i = edges[i].nxt) {
				if (edges[i].to == fa[u] || edges[i].to == maxson[u]) continue;
				dfs2(edges[i].to, edges[i].to);
			}
			low[u] = times;
		}
		long long lca(int u, int v) {
			wq pre, suf;
			while (top[u] != top[v]) {
//				printf("%d %d\n", u, v);
				if (dfn[top[u]] > dfn[top[v]]) {
					pre = pre + sgt::query(1, 1, n, dfn[top[u]], dfn[u]);
					u = fa[top[u]];
				}
				else {
					suf = sgtinv::query(1, 1, n, dfn[top[v]], dfn[v]) + suf;
					v = fa[top[v]];
				}
			}
			if (dfn[u] > dfn[v]) {
				pre = pre + sgt::query(1, 1, n, dfn[v], dfn[u]);
			}
			else {
				pre = pre + sgtinv::query(1, 1, n, dfn[u], dfn[v]);
			}
			return (pre + suf).p[0][1];
		}
	}
	int main() {
		for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d %d", &u, &v); add(u, v); add(v, u);
		}
		cut::dfs(1, 1); cut::dfs2(1, 1);
		sgt::build(1, 1, n, w);
		sgtinv::build(1, 1, n, w);
		while (q--) {
			int a, b; scanf("%d %d", &a, &b); printf("%lld\n", cut::lca(a, b));
		}
		return 0;
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &q, &k);
	if (k == 1) return Sub2::main();
	if (n <= 200) return Sub1::main();
	if (k == 2) return Sub3::main();
	return 0;
}
}
int main() {return yj::main();} // 28567kb

/*
7 114514 1
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
6 7

7 114514 2
1 2 4 8 16 32 64
1 2
2 3
3 4
4 5
5 6
6 7
*/
