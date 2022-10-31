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

const int Maxn = 5 * 1e5;
const int Maxm = 5 * 1e5;

int n, m, q;

struct edge {
	int len, Head[Maxn + 5];
	int to[Maxm * 2 + 5], Next[Maxm * 2 + 5];

	edge () { len = 1, memset (Head, 0, sizeof Head); }
	void Init () { len = 1, memset (Head, 0, sizeof Head); }
	void add (int x, int y) {
		to[++len] = y;
		Next[len] = Head[x];
		Head[x] = len;
	}
}mp, unmp;

map <PII, int> s;
int d[Maxn + 5];
bool vis[Maxn + 5];

int main () {
	freopen ("galaxy.in", "r", stdin);
	freopen ("galaxy.out", "w", stdout);

	read (n, m);
	rep (i, 1, m) {
		int x, y; read (x, y);
		mp.add (x, y), unmp.add (y, x), d[x]++;
		s[MP (x, y)] = mp.len;
	}
	read (q);
	while (q--) {
		int op, x, y; read (op);
		if (op == 1) {
			read (x, y);
			if (!vis[s[MP (x, y)]])
				d[x]--, vis[s[MP (x, y)]] = 1;
		}
		else if (op == 2) {
			read (x);
			for (int i = unmp.Head[x]; i; i = unmp.Next[i]) {
				if (vis[i]) continue;
				vis[i] = 1;
				d[unmp.to[i]]--;
			}
		}
		else if (op == 3) {
			read (x, y);
			if (vis[s[MP (x, y)]])
				d[x]++, vis[s[MP (x, y)]] = 0;
		}
		else {
			read (x);
			for (int i = unmp.Head[x]; i; i = unmp.Next[i]) {
				if (!vis[i]) continue;
				vis[i] = 0;
				d[unmp.to[i]]++;
			}
		}
		bool fl = 1;
		rep (i, 1, n)
			if (d[i] != 1)
				fl = 0;
		if (fl) puts ("YES");
		else puts ("NO");
	}
    return 0;
}