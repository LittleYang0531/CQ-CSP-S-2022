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

const int Maxn = 1e5;
const int Inf = 0x3f3f3f3f;

int n, m, q;
int a[Maxn + 5], b[Maxn + 5];

#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define l(p) (Tr[p].l)
#define r(p) (Tr[p].r)
#define mid(p) ((l (p) + r (p)) >> 1)
#define c(p,op) (Tr[p].x[op])
struct Node {
	int l, r;
	int x[5];

	Node () { l = 0, r = 0, x[0] = -Inf, x[2] = -Inf, x[1] = Inf, x[3] = Inf, x[4] = 0; }
	void Init () { l = 0, r = 0, x[0] = -Inf, x[2] = -Inf, x[1] = Inf, x[3] = Inf, x[4] = 0; }
	void Change (Node y) { x[0] = y.x[0], x[1] = y.x[1], x[2] = y.x[2], x[3] = y.x[3], x[4] = y.x[4]; }
};
struct Segment_Tree {
	int p; 
	Node Tr[(Maxn << 2) + 5];
	
	Node merge (Node x, Node y) {
		Node res;
		res.x[0] = Max (x.x[0], y.x[0]);
		res.x[1] = Min (x.x[1], y.x[1]);
		res.x[2] = Max (x.x[2], y.x[2]);
		res.x[3] = Min (x.x[3], y.x[3]);
		res.x[4] = x.x[4] | y.x[4];
		return res;
	}
	void Build (int op, int n) {
		p = 1; while (p < n + 2) p *= 2;
		rep (i, 1, n) {
			int x = (op == 1 ? a[i] : b[i]);
			if (x > 0) c (i + p, 2) = c (i + p, 3) = x;
			else if (x == 0) c (i + p, 4) = 1;
			else c (i + p, 0) = c (i + p, 1) = x;
		}
		per (i, 2 * p - 1, 1) {
			Tr[i >> 1].Change (merge (Tr[i >> 1], Tr[i]));
		}
	}
	Node Query (int l, int r) {
		Node res;
		for (l += p - 1, r += p + 1; (l ^ r) != 1; l >>= 1, r >>= 1) {
			if (!(l & 1)) res.Change (merge (res, Tr[l ^ 1]));
			if (r & 1) res.Change (merge (res, Tr[r ^ 1]));
		}
		return res;
	}
} Tr1, Tr2;

int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);

	read (n, m, q);
	rep (i, 1, n) read (a[i]);
	rep (i, 1, m) read (b[i]);
	Tr1.Build (1, n);
	Tr2.Build (0, m);

	while (q--) {
		int l1, r1, l2, r2; read (l1, r1, l2, r2);
		Node t1 = Tr1.Query (l1, r1), t2 = Tr2.Query (l2, r2);
		//有负数 x[0] != -Inf
		//有正数 x[2] != -Inf
		//有 0 x[5] = 1
		if (t2.x[0] != -Inf && t2.x[2] != -Inf) {
			//有负数和正数
			if (t1.x[4] == 1) {
				print (0, '\n');
			}
			else {
				print (Max ((LL)t1.x[0] * t2.x[2], (LL)t1.x[3] * t2.x[1]), '\n');
			}
		}
		else if (t2.x[0] != -Inf) {
			//有负数
			if (t1.x[0] != -Inf) {
				print ((LL)t1.x[1] * t2.x[0], '\n');
			}
			else {
				if (t1.x[4] == 1) print (0, '\n');
				else print ((LL)t1.x[3] * t2.x[1], '\n');
			}
		}
		else if (t2.x[2] != -Inf) {
			//有正数
			if (t1.x[2] != -Inf) {
				print ((LL)t1.x[2] * t2.x[3], '\n');
			}
			else {
				if (t1.x[4] == 1) print (0, '\n');
				else print ((LL)t1.x[0] * t2.x[2], '\n');
			}
		}
		else {
			print (0, '\n');
		}
	}
    return 0;
}