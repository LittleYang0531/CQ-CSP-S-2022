#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define LL long long
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)

const int Maxn = 5e5;

int n, m, q, tot;
int Out[Maxn + 5], vis[Maxn + 5], Ok[Maxn + 5], used[Maxn + 5];

vector < int > arr;

struct Vec {
	int tot;
	int head[Maxn + 5], ver[Maxn + 5], nxt[Maxn + 5];
	
	void Init () {
		tot = 0;
	}
	
	void Link (int u, int v) {
		ver[++ tot] = v;
		nxt[tot] = head[u], head[u] = tot;
	}
} z, f;

struct Edge {
	int u, v;
} edg[Maxn + 5];

map < pair < int , int > , int > mp;

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

void Dfs (int u) {
	used[u] = 1;
	if (Ok[u]) {
		for (int j = 0; j < (int) arr.size (); j ++) {
			int v = arr[j];
			Ok[v] = 1;
		}
		return ;
	}
	arr.push_back (u);
	for (int i = z.head[u]; i; i = z.nxt[i]) {
		int v = z.ver[i];
		if (vis[i]) continue; 
		if (used[v]) {
			for (int j = 0; j < (int) arr.size (); j ++) {
				int v = arr[j];
				Ok[v] = 1;
			}
			continue;
		}
		Dfs (v);
	}
	arr.pop_back ();
}

int main () {
	freopen ("galaxy.in", "r", stdin);
	freopen ("galaxy.out", "w", stdout);
	Readint (n), Readint (m);
	
	z.Init (), f.Init ();
	rep (i, 1, m) {
		int u, v;
		Readint (u), Readint (v);
		z.Link (u, v);
		f.Link (v, u);
		Out[u] ++;
		edg[i].u = u, edg[i].v = v;
		mp[make_pair(u, v)] = i;
	}
	
	Readint (q);
	
	rep (ttt, 1, q) {
//		printf ("%d: ", ttt);
		int t, u, v;
		Readint (t);
		if (t == 1) {
			Readint (u), Readint (v);
			vis[mp[make_pair (u, v)]] = 1;
			Out[u] --;
		} else if (t == 2) {
			Readint (u);
			for (int i = f.head[u]; i; i = f.nxt[i]) {
				if (vis[i] == 1) continue;
				vis[i] = 1;
				Out[edg[i].u] --;
			}
		} else if (t == 3) {
			Readint (u), Readint (v);
			vis[mp[make_pair (u, v)]] = 0;
			Out[u] ++;
		} else {
			Readint (u);
			for (int i = f.head[u]; i; i = f.nxt[i]) {
				if (vis[i] == 0) continue;
				vis[i] = 0;
				Out[edg[i].u] ++;
			}
		}
		int flag = 1;
		rep (i, 1, n) {
			if (Out[i] != 1) {
				flag = 0; break;
			}
		}
		if (!flag) {
			printf ("NO\n");
			continue;
		}
		flag = 1;
		rep (i, 1, n) {
			used[i] = Ok[i] = 0;
		}
		arr.clear ();
		rep (i, 1, n) {
			if (!used[i]) {
				Dfs (i);
			}
		}
		rep (i, 1, n) {
			if (!Ok[i]) {
				flag = 0; break;
			}
		}
		if (!flag) {
			printf ("NO\n");
			continue;
		}
		printf ("YES\n");
	}
	return 0;
}

