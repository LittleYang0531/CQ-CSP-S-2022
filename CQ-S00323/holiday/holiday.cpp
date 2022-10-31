#include <bits/stdc++.h>
#define re(i, x, y) for (int i = (x); i < (y); ++i)
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
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

const int maxn = 2.5e3 + 5;
const LL INF = 1e18;
int n, m, K;
int dis[maxn][maxn], p[maxn];
vi g[maxn];
LL s[maxn], f[maxn][4]; 
queue<int> q;
mt19937 rnd(114514);

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &K);
	++K;
	rep(i, 2, n) {
		scanf("%lld", &s[i]);
	}
	int u, v;
	rep(i, 1, m) {
		scanf("%d%d", &u, &v);
		g[u].eb(v);
		g[v].eb(u);
	}
	rep(i, 1, n) {
		fill(dis[i] + 1, dis[i] + n + 1, n + 1);
		dis[i][i] = 0;
		q.emplace(i);
		for ( ; !q.empty(); ) {
			int u = q.front();
			q.pop();
			for (auto v : g[u]) {
				if (dis[i][v] > n) {
					dis[i][v] = dis[i][u] + 1;
					q.emplace(v);
				}
			}
		}
	}
	LL ans = 0;
	if (n <= 20) {
		rep(i, 2, n) {
			if (dis[1][i] <= K) {
				rep(j, 2, n) {
					if (i != j && dis[i][j] <= K) {
						rep(k, 2, n) {
							if (i != k && j != k && dis[j][k] <= K) {
								rep(t, 2, n) {
									if (t != i && t != j && t != k && dis[k][t] <= K && dis[t][1] <= K) {
										chkmx(ans, s[i] + s[j] + s[k] + s[t]);
									}
								}	
							}
						} 
					}
				}
			}
		}
	}
	else {
		iota(p + 2, p + n + 1, 2);
		for ( ; ; ) {
			if (clock() > 1800) {
				break ;
			}
			shuffle(p + 2, p + n + 1, rnd);
			rep(j, 2, n) {
				f[j][0] = dis[1][p[j]] <= K ? s[p[j]] : -INF;
				f[j][1] = f[j][2]  = f[j][3] = -INF;
 				re(k, 2, j) {
					if (dis[p[j]][p[k]] <= K) {
						chkmx(f[j][1], f[k][0] + s[p[j]]);
						chkmx(f[j][2], f[k][1] + s[p[j]]);
						chkmx(f[j][3], f[k][2] + s[p[j]]);
					}
				}
				if (dis[p[j]][1] <= K) {
					chkmx(ans, f[j][3]);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
} 
