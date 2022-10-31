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

const int Maxn = 2500;
const LL Inf = 0x3f3f3f3f3f3f3f;

int n, m, k;
LL a[Maxn + 5];

vector <int> g[Maxn + 5];
void add (int x, int y) {
    g[x].push_back (y);
}
bool w[Maxn + 5][Maxn + 5];
void Augment (int s) {
    queue <int> q; q.push (s), w[s][s] = 1;
    rep (i, 1, k + 1) {
        for (int i = 1, len = q.size (); i <= len; i++) {
            int u = q.front (); q.pop ();
            for (auto v : g[u]) {
                if (w[s][v]) continue;
                q.push (v), w[s][v] = 1;
            }
        }
    }
}

pair <int, LL> dist1[3][Maxn + 5], dist2[3][Maxn + 5];
void Change1 (int i, LL x, int idx) {
    if (x > dist1[0][i].se) {
    	dist1[2][i] = dist1[1][i];
        dist1[1][i] = dist1[0][i];
        dist1[0][i] = MP (idx, x);
    }
    else if (x > dist1[1][i].se) {
    	dist1[2][i] = dist1[1][i];
        dist1[1][i] = MP (idx, x);
    }
    else if (x > dist1[2][i].se) {
    	dist1[2][i] = MP (idx, x);
	}
}
void Change2 (int i, LL x, int idx) {
    if (x > dist2[0][i].se) {
    	dist2[2][i] = dist2[1][i];
        dist2[1][i] = dist2[0][i];
        dist2[0][i] = MP (idx, x);
    }
    else if (x > dist2[1][i].se) {
    	dist2[2][i] = dist2[1][i];
        dist2[1][i] = MP (idx, x);
    }
    else if (x > dist2[2][i].se) {
    	dist2[2][i] = MP (idx, x);
	}
}

int main () {
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);

    read (n, m, k);
    rep (i, 2, n) read (a[i]);
    rep (i, 1, m) {
        int x, y; read (x, y);
        add (x, y), add (y, x);
    }

    rep (i, 1, n)
        Augment (i);
    
    rep (i, 2, n)
    	dist1[0][i] = dist1[1][i] = dist2[0][i] = dist2[1][i] = MP (-Inf, -1);
    rep (i, 2, n)
        rep (j, 2, n) {
        	if (i == j) continue;
            if (w[1][i] && w[i][j])
                Change1 (j, a[i] + a[j], i);
            if (w[i][j] && w[j][1])
                Change2 (i, a[i] + a[j], j);
        }
    
    LL res = 0;
    rep (i, 2, n)
        rep (j, 2, n) {
        	if (i == j) continue;
            rep (op1, 0, 2)
                rep (op2, 0, 2)
                    if (dist1[op1][i].fi != dist2[op2][j].fi && dist1[op1][i].fi != j && dist2[op2][j].fi != i)
                        res = Max (res, dist1[op1][i].se + dist2[op2][j].se);
        }
    write (res);
    return 0;
}