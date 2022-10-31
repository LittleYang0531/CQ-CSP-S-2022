#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MAXN 200000
#define MAXM 17
#define INF 0x3f3f3f3f

struct node {
	int ed;
	node *next;
}*s[MAXN + 5];
long long Lca[MAXN + 5][MAXM + 5];
long long Lcav[MAXN + 5][MAXM + 5][4][4];
long long sv[MAXN + 5];
int sd[MAXN + 5];
int k;

void read (int &n) {
	n = 0;

	char c = getchar ();
	bool flag = 0;

	while (c < '0' || c > '9') {
		if (c == '-') {
			flag = 1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar ();
	}
	n = flag ? -n : n;
}
void push (int u, int v) {
	node *p = new node;
	
	p->ed = v;
	p->next = s[u];
	s[u] = p;
}

void dfs (int now, int fa) {
	if (fa) {
		Lca[now][0] = fa;
		for (int e1 = 0; e1 <= k; e1 ++) {
			for (int e2 = 0; e2 <= k; e2 ++) {
				Lcav[now][0][e1][e2] = INF;
			}
		}
		Lcav[now][0][0][0] = sv[now] + sv[fa];
		Lcav[now][0][0][1] = sv[fa];
		Lcav[now][0][1][0] = sv[now];
		Lcav[now][0][1][1] = 0;
		for (int i = 1; Lca[now][i - 1]; i ++) {
			Lca[now][i] = Lca[Lca[now][i - 1]][i - 1];
			for (int e1 = 0; e1 <= k; e1 ++) {
				for (int e2 = 0; e2 <= k; e2 ++) {
					Lcav[now][i][e1][e2] = INF;
				}
			}
			if (i < 2) {
				Lcav[now][i][0][1] = sv[fa] + sv[Lca[now][1]];
				Lcav[now][i][1][0] = sv[fa] + sv[now];
				Lcav[now][i][1][1] = sv[fa];
				Lcav[now][i][0][2] = sv[Lca[now][1]];
				Lcav[now][i][2][0] = sv[now];
				Lcav[now][i][2][2] = 0;
			}
			else {
				for (int j = 0; j <= k; j ++) {
					for (int e1 = 0; e1 <= k; e1 ++) {
						for (int e2 = 0; e2 <= k; e2 ++) {
							Lcav[now][i][e1][e2] = min (Lcav[now][i - 1][e1][j] + Lcav[Lca[now][i - 1]][i - 1][j][e2], Lcav[now][i][e1][e2]);
						}
					}
				}
			}
		}
	}
	for (node *i = s[now]; i; i = i->next) {
		if (i->ed == fa) {
			continue;
		}
		sd[i->ed] = sd[now] + 1;
		dfs (i->ed, now);
	}
}
long long lca (int u, int v) {
	if (sd[u] > sd[v]) {
		swap (u, v);
	}
	
	long long dp1[4][4] = {}, dp2[4][4] = {};
	
	for (int e1 = 0; e1 <= k; e1 ++) {
		for (int e2 = 0; e2 <= k; e2 ++) {
			dp1[e1][e2] = INF;
			dp2[e1][e2] = INF;
		}
	}
	dp1[0][0] = 0;
	dp2[0][0] = 0;
	for (int i = sd[v] - sd[u], j = 0; i; i >>= 1, j ++) {
		if (i & 1) {
			long long Dp1[4][4] = {};
			
			for (int e1 = 0; e1 <= k; e1 ++) {
				for (int e2 = 0; e2 <= k; e2 ++) {
					Dp1[e1][e2] = INF;
				}
			}
			for (int e = 0; e <= k; e ++) {
				for (int e1 = 0; e1 <= k; e1 ++) {
					for (int e2 = 0; e2 <= k; e2 ++) {
						Dp1[e1][e2] = min (Lcav[v][j][e1][e] + dp1[e][e2], Dp1[e1][e2]);
					}
				}
			}
			for (int e1 = 0; e1 <= k; e1 ++) {
				for (int e2 = 0; e2 <= k; e2 ++) {
					dp1[e1][e2] = Dp1[e1][e2];
				}
			}
			v = Lca[v][j];
		}
	}
	if (u != v) {
		int d = 0;
		
		for (int j = MAXM; j >= 0; j --) {
			if (Lca[u][j] != Lca[v][j]) {
				d += (1 << j);
				long long Dp1[4][4] = {}, Dp2[4][4] = {};
				
				for (int e1 = 0; e1 <= k; e1 ++) {
					for (int e2 = 0; e2 <= k; e2 ++) {
						Dp1[e1][e2] = INF;
						Dp2[e1][e2] = INF;
					}
				}
				for (int e = 0; e <= k; e ++) {
					for (int e1 = 0; e1 <= k; e1 ++) {
						for (int e2 = 0; e2 <= k; e2 ++) {
							Dp1[e1][e2] = min (Lcav[v][j][e1][e] + dp1[e][e2], Dp1[e1][e2]);
							Dp2[e1][e2] = min (Lcav[u][j][e1][e] + dp2[e][e2], Dp2[e1][e2]);
						}
					}
				}
				for (int e1 = 0; e1 <= k; e1 ++) {
					for (int e2 = 0; e2 <= k; e2 ++) {
						dp1[e1][e2] = Dp1[e1][e2];
						dp2[e1][e2] = Dp2[e1][e2];
					}
				}
				u = Lca[u][j];
				v = Lca[v][j];
			}
		}
		d ++;
		if (d <= 2) {
			dp1[2][2] = 0;
			dp2[2][2] = 0;
		}
		
		long long Dp1[4][4] = {}, Dp2[4][4] = {};
		
		for (int e1 = 0; e1 <= k; e1 ++) {
			for (int e2 = 0; e2 <= k; e2 ++) {
				Dp1[e1][e2] = INF;
				Dp2[e1][e2] = INF;
			}
		}
		for (int e = 0; e <= k; e ++) {
			for (int e1 = 0; e1 <= k; e1 ++) {
				for (int e2 = 0; e2 <= k; e2 ++) {
					Dp1[e1][e2] = min (Lcav[v][0][e1][e] + dp1[e][e2], Dp1[e1][e2]);
					Dp2[e1][e2] = min (Lcav[u][0][e1][e] + dp2[e][e2], Dp2[e1][e2]);
				}
			}
		}
		for (int e1 = 0; e1 <= k; e1 ++) {
			for (int e2 = 0; e2 <= k; e2 ++) {
				dp1[e1][e2] = Dp1[e1][e2];
				dp2[e1][e2] = Dp2[e1][e2];
			}
		}
		u = Lca[u][0];
		v = Lca[v][0];
		
		long long Dp[4][4] = {};
		
		for (int e1 = 0; e1 <= k; e1 ++) {
			for (int e2 = 0; e2 <= k; e2 ++) {
				Dp[e1][e2] = INF;
			}
		}
		for (int e = 0; e <= k; e ++) {
			for (int e1 = 0; e1 <= k; e1 ++) {
				for (int e2 = 0; e2 <= k; e2 ++) {
					Dp[e1][e2] = min (dp2[e1][e] + dp1[e][e2], Dp[e1][e2]);
				}
			}
		}
		
		return Dp[0][0];
	}
	else {
		return dp1[0][0];
	}
}

int main () {
	freopen ("transmit.in", "r", stdin);
	freopen ("transmit.out", "w", stdout);
	
	int n, q;
	
	read (n), read (q), read (k);
	for (int i = 1; i <= n; i ++) {
		scanf ("%lld", &sv[i]);
	}
	for (int i = 1; i < n; i ++) {
		int u, v;
		
		read (u), read (v);
		push (u, v);
		push (v, u);
	}
	dfs (1, 0);
	for (int i = 1; i <= q; i ++) {
		int h, t;
		
		read (h), read (t);
		printf ("%lld\n", lca(h, t));
	}

	return 0;
}


