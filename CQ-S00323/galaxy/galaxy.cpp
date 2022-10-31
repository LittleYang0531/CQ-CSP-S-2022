#include <bits/stdc++.h>
#define re(i, x, y) for (int i = (x); i < (y); ++i)
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define vii vector<pii>
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define lowbit(x) ((x) & (-(x)))

using namespace std;
template<typename T> void chkmx(T &x, const T &y) {
	x = x < y ? y : x;
}
template<typename T> void chkmn(T &x, const T &y) {
	x = x > y ? y : x;
}

const int maxn = 5e5 + 5;
int n, m, q, cnt;
int u[maxn], v[maxn], vis[maxn];
int a[maxn];

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf("%d%d", &u[i], &v[i]);
	}
	scanf("%d", &q);
	if (n <= 1000 && m <= 10000 && q <= 1000) {
		cnt = m;
		int o, x, y;
		rep(i, 1, q) {
			scanf("%d%d", &o, &x);
			if (o == 1) {
				scanf("%d", &y);
				rep(j, 1, m) {
					if (u[j] == x && v[j] == y) {
						vis[j] = 1;
						--cnt;
						break ; 
					}
				}
			} 
			else if (o == 2) {
				rep(j, 1, m) {
					if (v[j] == x && !vis[j]) {
						vis[j] = 1;
						--cnt;
					}
				}
			}
			else if (o == 3) {
				scanf("%d", &y);
				rep(j, 1, m) {
					if (u[j] == x && v[j] == y) {
						vis[j] = 0;
						++cnt;
						break ; 
					}
				}
			}
			else {
				rep(j, 1, m) {
					if (v[j] == x && vis[j]) {
						vis[j] = 0;
						++cnt;
					}
				}
			}
			if (cnt != n) {
				puts("NO");
				continue ;
			} 
			memset(a, 0, sizeof(a));
			bool fl = 1;
			rep(j, 1, m) {
				if (vis[j]) {
					continue ;
				}
				if (a[u[j]]) {
					fl = 0;
					break ;
				}
				++a[u[j]];
			}
			puts(fl ? "YES" : "NO"); 
		}
		return 0;
	}
	rep(i, 1, m) {
		if (a[u[i]] == 1) {
			--cnt;
		}
		if (a[u[i]] == 0) {
			++cnt;
		}
		++a[u[i]];
	}
	int o, x, y;
	rep(i, 1, q) {
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1) {
			if (a[x] == 2) {
				++cnt;
			}
			if (a[x] == 1) {
				--cnt;
			} 
			--a[x];
		}
		else {
			if (a[x] == 0) {
				++cnt;
			}
			if (a[x] == 1) {
				--cnt;
			}
			++a[x];
		} 
		puts(cnt == n ? "YES" : "NO");
	}
	return 0;
} 
