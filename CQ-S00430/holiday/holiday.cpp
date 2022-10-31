#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define LL long long
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)

const int Maxn = 2500;


int n, m, k;
LL val[Maxn + 5], dp[Maxn + 5][3][2];
int lk[Maxn + 5][Maxn + 5], vis[Maxn + 5], fm[Maxn + 5][2];

vector < int > G[Maxn + 5];

struct Node {
	int u, stp;
	Node () {}
	Node (int x, int y) {
		u = x, stp = y;
	}
} ;
queue < Node > Que;

void Readint (int &x) {
	x = 0; int f = 1; char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1; c = getchar ();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar ();
	}
	x *= f;
}

void Readll (LL &x) {
	x = 0; LL f = 1; char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1; c = getchar ();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar ();
	}
	x *= f;
}

void Bfs (int p) {
	Que.push (Node (p, 0));
	rep (i, 1, n) vis[i] = 0;
	vis[p] = 1;
	while (Que.size ()) {
		Node u = Que.front ();
		Que.pop ();
		if (u.stp > k) continue;
		for (int i = 0; i < (int) G[u.u].size (); i ++) {
			int v = G[u.u][i];
			if (vis[v]) continue;
			vis[v] = lk[p][v] = 1;
			Que.push (Node (v, u.stp + 1));
		}
	}
	lk[p][p] = 0;
}

bool Check (int a, int b, int c, int d) {
	return (a != d) && (b != c) && (c != d);
}

int main () {
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);

	Readint (n), Readint (m), Readint (k);
	
	rep (i, 2, n) {
		Readll (val[i]);
	}
	
	rep (i, 1, m) {
		int u, v;
		Readint (u), Readint (v);
		G[u].push_back (v);
		G[v].push_back (u);
	}
	
	rep (i, 1, n) {
		Bfs (i);
//		rep (j, 1, n) {
//			if (lk[i][j])
//			printf ("[%d %d]\n", i, j);
//		}
	}
	
	//k = 1
	rep (i, 2, n) {
		if (!lk[1][i]) continue;
		dp[i][1][0] = val[i];
	}
	//k = 2
	rep (i, 2, n) {
		rep (j, 2, n) {
			if (i == j || !lk[i][j]) continue;
			LL Max = dp[i][1][0] + val[j];
			if (Max >= dp[j][2][0]) {
				fm[j][1] = fm[j][0];
				fm[j][0] = i;
				dp[j][2][1] = dp[j][2][0];
				dp[j][2][0] = Max;
			} else {
				if (Max > dp[j][2][1]) fm[j][1] = i;
				dp[j][2][1] = max (dp[j][2][1], Max);
			}
		}
	}
	
//	rep (i, 1, n) {
//		printf ("%d : %lld(%d) %lld(%d)\n", i, dp[i][2][0], fm[i][0], dp[i][2][1], fm[i][1]);
//	}

	LL ans = 0;
	rep (i, 2, n) {
		rep (j, i + 1, n) {
			if (lk[i][j] == 0) continue;
			if (Check (i, j, fm[i][0], fm[j][0])) {
				ans = max (ans, dp[i][2][0] + dp[j][2][0]);
			} else {
				if (Check (i, j, fm[i][0], fm[j][1])) {
					ans = max (ans, dp[i][2][0] + dp[j][2][1]);
				}
				if (Check (i, j, fm[i][1], fm[j][0])) {
					ans = max (ans, dp[i][2][1] + dp[j][2][0]);
				}
				if (Check (i, j, fm[i][1], fm[j][1])) {
					ans = max (ans, dp[i][2][1] + dp[j][2][1]);
				}
			}
		}
	}
	
	printf ("%lld", ans);
	return 0;
}

