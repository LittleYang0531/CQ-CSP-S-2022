#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define LL long long
#define PII pair <int, int>
#define MP(x,y) (make_pair (x, y))
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define per(i,j,k) for (int i = (j); i >= (k); i--)

template <typename T>
void read (T &x) {
	x = 0; T f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar ();
	}
	x *= f;
}
template <typename T, typename... Args>
void read (T &x, Args &...args) {
	read (x), read (args...);
}
int Tp_For_Print, Stack_For_Print[100];
template <typename T>
void write (T x) {
	if (x == 0) {
		putchar ('0');
		return;
	}
	if (x < 0) {
		putchar ('-');
		write (-x);
		return;
	}
	Tp_For_Print = 0;
	while (x)
		Stack_For_Print[++Tp_For_Print] = x % 10, x /= 10;
	while (Tp_For_Print >= 1)
		putchar (Stack_For_Print[Tp_For_Print--] + '0');
}
template <typename T>
void print (T x, char ch) {
	write (x), putchar (ch);
}
template <typename T> T Max (T x, T y) { return x > y ? x : y; }
template <typename T> T Min (T x, T y) { return x < y ? x : y; }
template <typename T> T Abs (T x) { return x > 0 ? x : -x; }

const int Maxn = 2 * 1e5;
const LL Inf = 0x3f3f3f3f3f3f3f3f;

int n, q, k;
LL a[Maxn + 5];

vector <int> g[Maxn + 5];
void add (int x, int y) {
	g[x].push_back (y);
}

struct Matrix {
	int n, m;
	LL c[4][4];
	bool flag;

	Matrix () { flag = 1, n = k, m = k; memset (c, 0x3f, sizeof c); }
}b[Maxn + 5];
Matrix operator * (Matrix x, Matrix y) {
	if (x.flag) return y;
	if (y.flag) return x;
	Matrix res; res.flag = 0, res.n = x.n, res.m = y.m;
	rep (i, 1, res.n)
		rep (j, 1, res.m)
			rep (k, 1, x.m)
				res.c[i][j] = Min (res.c[i][j], x.c[i][k] + y.c[k][j]);
	return res;
}

int Size[Maxn + 5], Son[Maxn + 5], fa[Maxn + 5], depth[Maxn + 5];
void dfs1 (int u, int _fa) {
	Size[u] = 1;
	for (auto v : g[u]) {
		if (v == _fa) continue;
		depth[v] = depth[u] + 1, fa[v] = u, dfs1 (v, u);
		Size[u] += Size[v];
		if (Size[v] > Size[Son[u]])
			Son[u] = v;
	}
}
int timestamp, dfn[Maxn + 5], tp[Maxn + 5];
void dfs2 (int u, int _fa, int _tp) {
	dfn[u] = ++timestamp, tp[u] = _tp;
	if (Son[u]) dfs2 (Son[u], u, _tp);
	for (auto v : g[u]) {
		if (v == _fa) continue;
		if (v == Son[u]) continue;
		dfs2 (v, u, v);
	}
}

struct Segment_Tree {
	int p; 
	Matrix Tr[(Maxn << 2) + 5], Tr_Inv[(Maxn << 2) + 5];
	
	void Build (int n) {
//		Matrix I_AK_IOI = b[2] * b[1];
//		Matrix I_CE_IOI = b[4] * b[2];
//		Matrix I_TLE_IOI = b[1] * b[2];
//		Matrix I_WA_IOI = b[2] * b[4];
		p = 1; while (p < n + 2) p *= 2;
		rep (i, 1, n) {
			Tr[dfn[i] + p] = b[i];
			Tr_Inv[dfn[i] + p] = b[i];
		}
		per (i, p, 1) {
//			if (i == 9)
//				printf ("I AK IOI!");
			Tr[i] = Tr[i << 1] * Tr[i << 1 | 1];
			Tr_Inv[i] = Tr_Inv[i << 1 | 1] * Tr_Inv[i << 1];
		}
	}
	Matrix Query (int l, int r) {
		queue <int> q1;
		stack <int> q2;
		Matrix res;
		for (l += p - 1, r += p + 1; (l ^ r) != 1; l >>= 1, r >>= 1) {
			if (!(l & 1)) q1.push (l ^ 1);
			if (r & 1) q2.push (r ^ 1);
		}
		while (q2.size ()) q1.push (q2.top ()), q2.pop ();
		while (q1.size ()) res = res * Tr[q1.front ()], q1.pop ();
		return res;
	}
	Matrix Query_Inv (int l, int r) {
		queue <int> q1;
		stack <int> q2;
		Matrix res;
		for (l += p - 1, r += p + 1; (l ^ r) != 1; l >>= 1, r >>= 1) {
			if (!(l & 1)) q2.push (l ^ 1);
			if (r & 1) q1.push (r ^ 1);
		}
//		Matrix I_AK_IOI = b[2] * b[1];
//		Matrix I_CE_IOI = b[4] * b[2];
//		Matrix I_TLE_IOI = b[1] * b[2];
//		Matrix I_WA_IOI = b[2] * b[4];
		while (q2.size ()) q1.push (q2.top ()), q2.pop ();
		while (q1.size ()) 
			res = res * Tr_Inv[q1.front ()], q1.pop ();
		return res;
	}
} Tr;

Matrix Query (int x, int y) {
	queue <int> q1;
	stack <int> q2;
	Matrix res;
	while (tp[x] != tp[y]) {
		if (depth[tp[x]] >= depth[tp[y]]) {
			q1.push (x);
			x = fa[tp[x]];
		}
		else {
			q2.push (y);
			y = fa[tp[y]];
		}
	}
//	Matrix I_AK_IOI = b[10] * b[9] * b[1] * b[2] * b[3] * b[5];
//	Matrix I_CE_IOI = b[4] * (b[2] * b[1]);
	while (q1.size ()) res = res * Tr.Query_Inv (dfn[tp[q1.front ()]], dfn[q1.front ()]), q1.pop ();
	if (depth[y] < depth[x]) res = res * Tr.Query_Inv (dfn[y], dfn[x]);
	else res = res * Tr.Query (dfn[x], dfn[y]);
	while (q2.size ()) 
		res = res * Tr.Query (dfn[tp[q2.top ()]], dfn[q2.top ()]), q2.pop ();
	return res;
}
//LL dp[Maxn + 5];
//LL Jump (int x, int y) {
//	queue <int> q1;
//	stack <int> q2;
//	int tot = 0;
//	while (x != y) {
//		tot++;
//		if (depth[x] >= depth[y]) {
//			q1.push (x);
//			x = fa[x];
//		}
//		else {
//			q2.push (y);
//			y = fa[y];
//		}
//		if (tot >= 5) return -1;
//	}
//	while (q2.size ()) q1.push (q2.top ()), q2.pop ();
//	for (int i = 1, len = q1.size (); i <= len; i++) {
//		dp[i] = Inf;
//		rep (j, Max (i - k, 0), i - 1) {
//			dp[i] = Min (dp[i], dp[j] + a[q1.front ()]);
//		}
//		q1.pop ();
//	}
//	return 1;
//}

int main () {
	freopen ("transmit.in", "r", stdin);
	freopen ("transmit.out", "w", stdout);

	read (n, q, k);
	rep (i, 1, n) {
		read (a[i]);
		b[i].n = b[i].m = k, b[i].flag = 0;
		rep (l, 1, k - 1)
			rep (j, 1, k) {
				if (j == l + 1) b[i].c[j][l] = 0;
				else b[i].c[j][l] = Inf;
			}
		rep (j, 1, k)
			b[i].c[j][k] = a[i];
	}
	rep (i, 1, n - 1) {
		int x, y; read (x, y);
		add (x, y), add (y, x);
	}
	depth[1] = 1, dfs1 (1, -1), dfs2 (1, -1, 1);
	Tr.Build (n);
	
//	Matrix I_CE_IOI, I_AK_IOI = b[4] * b[2] * b[1] * b[3] * b[7];
//	I_CE_IOI.n = 1, I_CE_IOI.m = 3, I_CE_IOI.flag = 0;
//	I_CE_IOI.c[1][1] = 0, I_CE_IOI.c[1][2] = Inf, I_CE_IOI.c[1][3] = Inf;
//	Matrix I_TLE_IOI = I_CE_IOI;
//	I_TLE_IOI = I_TLE_IOI * b[4];
//	I_TLE_IOI = I_TLE_IOI * b[2];
//	I_TLE_IOI = I_TLE_IOI * b[1];
//	I_TLE_IOI = I_TLE_IOI * b[3];
//	I_TLE_IOI = I_TLE_IOI * b[7];
//	Matrix I_WA_IOI = I_CE_IOI * b[4] * b[2] * b[1] * b[3] * b[7];
//	I_CE_IOI = I_CE_IOI * I_AK_IOI;
//	Matrix tmp = b[4] * (b[2] * b[1]) * (b[3] * b[7]);
	while (q--) {
		int x, y; read (x, y);
//		int res = 0;
//		if ((res = Jump (x, y)) != -1) {
//			print (res, '\n');
//			continue;
//		}
		Matrix t; t.n = 1, t.m = 3, t.flag = 0;
		t.c[1][1] = 0, t.c[1][2] = Inf, t.c[1][3] = Inf;
		Matrix s = Query (x, y);
		t = t * s;
		print (t.c[1][3], '\n');
	}
    return 0;
}