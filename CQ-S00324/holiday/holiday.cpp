#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MAXN 2500
#define MAXK 100
#define INF 0x3f3f3f3f3f3f3f3f

long long sv[MAXN + 5];
struct node {
	node *next;
	int ed;
}*s[MAXN + 5], *sn[MAXN + 5], *fn[MAXN + 5];
int sl[MAXN + 5][MAXN + 5];
long long dp[MAXN + 5][3];
int dpk[MAXN + 5][3];

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
void push (node **s, int u, int v) {
	node *p = new node;
	
	p->ed = v;
	p->next = s[u];
	s[u] = p;
}
bool check (pair <int, int> a, pair<int, int> b, pair<int, int> c) {
	return ((a.first == b.first || a.first == b.second) && (a.first == c.first || a.first == c.second)) || ((a.second == b.first || a.second == b.second) && (a.second == c.first || a.second == c.second));
}

int main () {
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);
	
	int n, m;
	int k;
	
	read (n), read (m), read (k);
	for (int i = 2; i <= n; i ++) {
		scanf ("%lld", &sv[i]);
	} 
	for (int i = 1; i <= m; i ++) {
		int u, v;
		
		read (u), read (v);
		push (s, u, v);
		push (s, v, u);
	}
	
	queue<pair<int, int> > q;
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			sl[i][j] = n + 1;
		}
	}
	for (int i = 1; i <= n; i ++) {
		q.push(make_pair (i, i));
		sl[i][i] = 0;
	}
	while (!q.empty()) {
		pair <int, int> v = q.front();
		
		q.pop();
		if (sl[v.first][v.second] >= k + 1) {
			continue;
		}
		for (node *i = s[v.second]; i; i = i->next) {
			if (sl[v.first][i->ed] > sl[v.first][v.second] + 1) {
				sl[v.first][i->ed] = sl[v.first][v.second] + 1;
				q.push(make_pair(v.first, i->ed));
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (sl[i][j] < n + 1 && i != j) {
				push (sn, i, j);
			}
		}
		for (int j = n; j >= 1; j --) {
			if (sl[i][j] < n + 1 && i != j) {
				push (fn, i, j);
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		dp[i][0] = -INF;
		dp[i][1] = -INF;
		dp[i][2] = -INF;
	}
	
	long long ans = -INF;
	
	for (int i = 2; i <= n; i ++) {
		for (node *j = sn[i]; j; j = j->next) {
			if (j->ed == 1) {
				continue;
			}
			if (sl[1][j->ed] >= n + 1) {
				continue;
			}
			if (sv[j->ed] + sv[i] > dp[i][0]) {
				dp[i][2] = dp[i][1];
				dp[i][1] = dp[i][0];
				dp[i][0] = sv[j->ed] + sv[i];
				dpk[i][2] = dpk[i][1];
				dpk[i][1] = dpk[i][0];
				dpk[i][0] = j->ed;
			}
			else if (sv[j->ed] + sv[i] > dp[i][1]) {
				dp[i][2] = dp[i][1];
				dp[i][1] = sv[j->ed] + sv[i];
				dpk[i][2] = dpk[i][1];
				dpk[i][1] = j->ed;
			}
			else if (sv[j->ed] + sv[i] > dp[i][2]) {
				dp[i][2] = sv[j->ed] + sv[i];
				dpk[i][2] = j->ed;
			}
		}
	}
	for (int i = 2; i <= n; i ++) {
		long long Dp[2] = {-INF, -INF};
		int Dpk[2] = {0, 0};
		
		for (node *j = sn[i]; j; j = j->next) {
			if (j->ed == 1) {
				continue;
			}
			if (sl[1][j->ed] < n + 1) {
				if (Dp[0] > -INF && Dpk[0] != j->ed) {
					ans = max (ans, Dp[0] + sv[i] + sv[j->ed]);
				}
				else if (Dp[1] > -INF && Dpk[1] != j->ed) {
					ans = max (ans, Dp[1] + sv[i] + sv[j->ed]);
				}
			}
			for (int e = 0; e <= 2; e ++) {
				if (dpk[j->ed][e] == i) {
					continue;
				}
				if (dp[j->ed][e] > Dp[0]) {
					if (Dpk[0] != dpk[j->ed][e]) {
						Dp[1] = Dp[0];
						Dpk[1] = Dpk[0];
					}
					Dp[0] = dp[j->ed][e];
					Dpk[0] = dpk[j->ed][e];
				}
				else if (Dpk[0] != dpk[j->ed][e]) {
					if (dp[j->ed][e] > Dp[1]) {
						Dp[1] = dp[j->ed][e];
						Dpk[1] = dpk[j->ed][e];
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i ++) {
		long long Dp[2] = {-INF, -INF};
		int Dpk[2] = {0, 0};
		
		for (node *j = fn[i]; j; j = j->next) {
			if (j->ed == 1) {
				continue;
			}
			if (sl[1][j->ed] < n + 1) {
				if (Dp[0] > -INF && Dpk[0] != j->ed) {
					ans = max (ans, Dp[0] + sv[i] + sv[j->ed]);
				}
				else if (Dp[1] > -INF && Dpk[1] != j->ed) {
					ans = max (ans, Dp[1] + sv[i] + sv[j->ed]);
				}
			}
			for (int e = 0; e <= 2; e ++) {
				if (dpk[j->ed][e] == i) {
					continue;
				}
				if (dp[j->ed][e] > Dp[0]) {
					if (Dpk[0] != dpk[j->ed][e]) {
						Dp[1] = Dp[0];
						Dpk[1] = Dpk[0];
					}
					Dp[0] = dp[j->ed][e];
					Dpk[0] = dpk[j->ed][e];
				}
				else if (Dpk[0] != dpk[j->ed][e]) {
					if (dp[j->ed][e] > Dp[1]) {
						Dp[1] = dp[j->ed][e];
						Dpk[1] = dpk[j->ed][e];
					}
				}
			}
		}
	}
	printf ("%lld", ans);
	
	return 0;
}


