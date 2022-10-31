#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 5e5 + 5;
int n, m, q, x, y, opt;
bool f[MAXN], vis[MAXN];

struct node {
	set <int> to, st;
	int t, s;
} G[MAXN];

set <int> st[MAXN], to[MAXN];

bool dfs (int x) {
	for (set <int> :: iterator it = G[x].st.begin(); it != G[x].st.end(); it ++) {
		if (vis[(*it)])
			return 1;
		vis[(*it)] = 1;
		if (dfs (*it))
			return 1;
	}
	return 0;
}

bool check () {
	for (int i = 1; i <= n; i ++) {
		if (!f[i])
			continue;
		memset (vis, 0, sizeof vis);
		if (!dfs (i) || G[i].s > 1)
			return 0;
	}
	return 1;
}

int main () {
	freopen ("galaxy.in", "r", stdin);
	freopen ("galaxy.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++)
		f[i] = 1;
	for (int i = 1; i <= m; i ++)
		scanf ("%d %d", &x, &y), G[x].st.insert(y), G[y].to.insert(x), G[x].s ++, G[y].t ++,
		st[x].insert(y), to[y].insert(x);
	scanf ("%d", &q);
	while (q --) {
		scanf ("%d", &opt);
		if (opt == 1) {
			scanf ("%d %d", &x, &y);
			G[x].st.erase(y), G[y].to.erase(x);
			G[x].s --, G[y].t --;
		} else if (opt == 2) {
			scanf ("%d", &x);
			f[x] = 0;
			for (set <int> :: iterator it = G[x].to.begin(); it != G[x].to.end(); it ++) {
				G[(*it)].st.erase(x), G[(*it)].s --;
			}
			G[x].to.clear(), G[x].s = 0;
		} else if (opt == 3) {
			scanf ("%d %d", &x, &y);
			G[x].st.insert(y), G[y].to.insert(x), G[x].s ++, G[y].t ++, f[x] = f[y] = 1;
		} else {
			scanf ("%d", &x);
			f[x] = 1, G[x].st = st[x], G[x].to = to[x], G[x].s = st[x].size(), G[x].t = to[x].size();
		} 
		if (check ())
			puts ("YES");
		else
			puts ("NO");
	}
	return 0;
} 
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
