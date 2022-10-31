#include <bits/stdc++.h>
#define re(i, x, y) for (int i = (x); i < (y); ++i)
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define pe(i, x, y) for (int i = (x) - 1; i >= (y); --i)
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<pii>
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define lowbit(x) ((x) & (-(x)))

using namespace std;
typedef long long LL;
template<typename T> void chkmx(T &x, const T &y) {
	x = x < y ? y : x;
}
template<typename T> void chkmn(T &x, const T &y) {
	x = x > y ? y : x;
}

const int maxn = 2e5 + 5;
const LL INF = 1e18;
int n, q, k;
int a[maxn], dep[maxn];
LL f1[maxn][18], f2[maxn][18], F[maxn][18], G[maxn][18], H[maxn][18];
//LL R[maxn][18], T[maxn][18], U[maxn][18];
vi g[maxn];

namespace case_1 {
	LL dis[maxn];
	int fa[maxn][18];
	void dfs(int u) {
		dep[u] = dep[fa[u][0]] + 1;
		dis[u] = dis[fa[u][0]] + a[u];
		re(i, 1, 18) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		} 
		for (auto v : g[u]) {
			if (v ^ fa[u][0]) {
				fa[v][0] = u;
				dfs(v);
			}
		}
	}
	int lca(int x, int y) {
		if (dep[x] < dep[y]) {
			swap(x, y);
		}
		pe(i, 18, 0) {
			if (dep[fa[x][i]] >= dep[y]) {
				x = fa[x][i];
			}
		} 
		if (x == y) {
			return x;
		}
		pe(i, 18, 0) {
			if (fa[x][i] ^ fa[y][i]) {
				x = fa[x][i], y = fa[y][i];
			}
		}
		return fa[x][0];
	}
	void solve() {
		dfs(1);
		int u, v;
		rep(i, 1, q) {
			scanf("%d%d", &u, &v);
			int l = lca(u, v);
			printf("%lld\n", dis[u] + dis[v] - dis[l] - dis[fa[l][0]]);
		}
	}
} 
namespace case_2 {
	void dfs(int u) {
		dep[u] = dep[f1[u][0]] + 1;
		f1[u][1] = f1[f1[u][0]][0];
		f2[u][0] = u, f2[u][1] = f1[u][0];
		re(i, 2, 18) {
			f1[u][i] = f1[f1[u][i - 1]][i - 1];
			f2[u][i] = f2[f1[u][i - 1]][i - 1];
		} 
		F[u][0] = F[u][1] = a[u];
		G[u][1] = a[u];
		H[u][0] = a[u], H[u][1] = a[u] + min(a[f1[u][0]], a[f1[u][1]]);
		re(i, 2, 18) {
			G[u][i] = min(G[u][i - 1] + F[f2[u][i - 1]][i - 1], F[u][i - 1] + G[f1[u][i - 1]][i - 1]);
			H[u][i] = min(H[u][i - 1] + F[f1[f1[u][i - 1]][0]][i - 1], F[u][i - 1] + H[f1[u][i - 1]][i - 1]);
			F[u][i] = min(F[u][i - 1] + F[f1[u][i - 1]][i - 1], G[u][i - 1] + H[f2[u][i - 1]][i - 1]);
		}
		for (auto v : g[u]) {
			if (v ^ f1[u][0]) {
				f1[v][0] = u;
				dfs(v);
			}
		}
	}
	void solve() {
		dfs(1); 
		int u, v;
		LL p1[2], p2[2], p3[2];
		rep(i, 1, q) {
			scanf("%d%d", &u, &v);
			if (u == v) {
				printf("%d\n", a[u]);
				continue ;
			}
			p1[0] = p2[0] = 0;
			if (dep[u] < dep[v]) {
				swap(u, v);
			}
			p1[1] = a[u];
			p2[1] = a[v];
			pe(j, 18, 0) {
				if (dep[f1[u][j]] >= dep[v]) {
					p3[0] = min(F[u][j] + p1[0], G[f1[u][0]][j] + p1[1]);
					p3[1] = min(H[u][j] + p1[0], F[f1[u][0]][j] + p1[1]);
					p1[0] = p3[0], p1[1] = p3[1];
					u = f1[u][j];
				}
			} 
			if (u == v) {
				printf("%lld\n", min(p1[0] + a[u], u == 1 ? INF : p1[1] + a[f1[u][0]] + a[u]));
				continue ;
			}
			pe(j, 18, 0) {
				if (f1[u][j] ^ f1[v][j]) {
					p3[0] = min(F[u][j] + p1[0], G[f1[u][0]][j] + p1[1]);
					p3[1] = min(H[u][j] + p1[0], F[f1[u][0]][j] + p1[1]);
					p1[0] = p3[0], p1[1] = p3[1];
					p3[0] = min(F[v][j] + p2[0], G[f1[v][0]][j] + p2[1]);
					p3[1] = min(H[v][j] + p2[0], F[f1[v][0]][j] + p2[1]);
					p2[0] = p3[0], p2[1] = p3[1];
					u = f1[u][j], v = f1[v][j];
				}
			}
			printf("%lld\n", min(p1[0] + p2[0] + a[u] + a[v], p1[1] + p2[1] + a[f1[u][0]])); 
		}
	}
}
namespace case_3 {
//	int mn[maxn];
//	void dfs(int u) {
//		dep[u] = dep[f1[u][0]] + 1;
//		f1[u][1] = f1[f1[u][0]][0];
//		f2[u][0] = u, f2[u][1] = f1[u][0];
//		re(i, 2, 18) {
//			f1[u][i] = f1[f1[u][i - 1]][i - 1];
//			f2[u][i] = f2[f1[u][i - 1]][i - 1];
//		} 
//		F[u][0] = F[u][1] = F[u][2] = a[u];
//		F[u][2] += min({a[f1[u][1]], a[f2[u][1]], mn[f1[u][1]]});
//		G[u][1] = G[u][2] = a[u];
//		H[u][0] = H[u][1] = H[u][2] = a[u];
//		H[u][2] += min({a[f1[u][1]], a[f2[u][1]], F[f1[u][0]][2] - a[f1[u][0]] + mn[f1[u][1]]});
//		T[u][2] = a[u]; 
//		U[u][0] = U[u][2] = a[u];
//		U[u][1] = F[u][2];
//		U[u][2] += min({a[f2[u][1]], H[f1[u][0]] - a[f1[u][0]] + mn[f1[u][1]], F[f1[u][1]]});
//		R[u][0] = R[u][1] = R[u][2] = a[u]; 
//		R[u][2] += min({a[f1[u][1]], a[f2[u][1]], mn[f1[u][1]] + min(mn[f2[u][0]], a[f1[u][2]])});
//		
//		re(i, 3, 18) {
//			G[u][i] = min({min(G[u][i - 1], R[u][i - 1]) + F[f2[u][i - 1]][i - 1], F[u][i - 1] + G[f1[u][i - 1]][i - 1], 
//				T[u][i - 1] + H[f2[f2[u][i - 2]][i - 2]][i - 1]
//			});
//			H[u][i] = min({H[u][i - 1] + F[f1[f1[u][i - 1]][0]][i - 1], F[u][i - 1] + H[f1[u][i - 1]][i - 1], 
//				min(min(G[u][i - 1], R[u][i - 1]) + U[f2[u][i - 1]][i - 1]);
//			});
//			T[u][i] = min({G[u][i - 1] + G[f2[u][i - 1]][i - 1], T[u][]});
//			U[u][i] = min({}); 
//			F[u][i] = min({F[u][i - 1] + F[f1[u][i - 1]][i - 1], min(G[u][i - 1], R[u][i - 1]) + H[f2[u][i - 1]][i - 1], 
//				H[u][i - 1] + G[f1[f1[u][i - 1]][0]][i - 1]
//			});
//		}
//		mn[u] = INF;
//		for (auto v : g[u]) {
//			if (v ^ f1[u][0]) {
//				f1[v][0] = u;
//				chkmn(mn[u], a[v]); 
//				dfs(v);
//			}
//		}
//	}
	LL dis[2005];
	int fa[maxn][18];
	void dfs(int u) {
		dep[u] = dep[fa[u][0]] + 1;
		re(i, 1, 18) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		} 
		for (auto v : g[u]) {
			if (v ^ fa[u][0]) {
				fa[v][0] = u;
				dfs(v);
			}
		}
	}
	int lca(int x, int y) {
		if (dep[x] < dep[y]) {
			swap(x, y);
		}
		pe(i, 18, 0) {
			if (dep[fa[x][i]] >= dep[y]) {
				x = fa[x][i];
			}
		} 
		if (x == y) {
			return x;
		}
		pe(i, 18, 0) {
			if (fa[x][i] ^ fa[y][i]) {
				x = fa[x][i], y = fa[y][i];
			}
		}
		return fa[x][0];
	}
	int dd[2005][2005]; 
	priority_queue<pair<LL, int>> pq; 
	bool vis[2005];
	void solve() {
		dfs(1);
		rep(i, 1, n) {
			rep(j, 1, n) {
				int l = lca(i, j);
				dd[i][j] = dep[i] + dep[j] - dep[l] * 2;
			}
		}
		int x, y;
		rep(i, 1, q) {
			scanf("%d%d", &x, &y);
			memset(vis, 0, sizeof(vis));
			memset(dis, 0x3f, sizeof(dis));
			dis[x] = a[x];
			pq.emplace(-dis[x], x);
			for ( ; !pq.empty(); ) {
				int u = pq.top().second;
				pq.pop();
				if (u == y) {
					printf("%lld\n", dis[u]);
					break ;
				}
				if (vis[u]) {
					continue ;
				}
				vis[u] = 1;
				rep(j, 1, n) {
					 if (dd[u][j] <= k && dis[j] > dis[u] + a[j]) {
					 	 dis[j] = dis[u] + a[j];
					 	 pq.emplace(-dis[j], j); 
					 }
				}
			}
			for ( ; !pq.empty(); pq.pop()) ; 
		}
	}
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
	scanf("%d%d%d", &n, &q, &k);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
	}
	int u, v;
	re(i, 1, n) {
		scanf("%d%d", &u, &v);
		g[u].eb(v), g[v].eb(u);
	}
	if (k == 1) {
		case_1::solve();
	}
	else if (n <= 200 && q <= 200) {
		case_3::solve();
	} 
	else if (k == 2) {
		case_2::solve();
	}
	else {
		case_3::solve();
	}
	return 0;
} 
