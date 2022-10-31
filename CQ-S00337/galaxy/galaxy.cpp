#include<bits/stdc++.h>
#define int long long
#define N ((int)2e3 + 2)
#define M ((int)1e4 + 2)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define INF ((int)1e18 + 2)
#define pii pair<int, int>
#define fir first
#define sec second
#define MP make_pair
#define eps 1e-8
#define db double
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i) 
using namespace std;
int n, m;
int con[N][N];
vector<int> vec[N];
int Q;
bool vis[N], fin;
inline void dfs (int u) {
	if (vis[u]) fin = true;
	if (fin) return;
	vis[u] = true;
	rep (i, 1, n) if (i != u && con[u][i]) dfs(i);
	vis[u] = false;
}
inline void solve () {
	rep (i, 1, n) {
		int cnt = 0;
		rep (j, 1, n) if (i != j && con[i][j]) ++cnt;
		if (cnt > 1) return printf("NO\n"), void();
	}
	rep (i, 1, n) {
		rep (i, 1, n) vis[i] = false;
		fin = false;
		dfs(i);
		if (!fin) return printf("NO\n"), void();
	}
	printf("YES\n");
}
inline void freo () {
	freopen("galaxy.in", "r", stdin), freopen("galaxy.out", "w", stdout); }
signed main () {
	freo();
	scanf("%lld%lld", &n, &m);
	int u, v;
	rep (i, 1, m) {
		scanf("%lld%lld", &u, &v);
		con[u][v] = 1, vec[v].emplace_back(u);
	}
	scanf("%lld", &Q);
	int opt;
	while (Q--) {
		scanf("%lld%lld", &opt, &u);
		if (opt == 1) {
			scanf("%lld", &v);
			con[u][v] = 0;
		}
		else if (opt == 2) {
			for (auto x : vec[u]) con[x][u] = 0;
		}
		else if (opt == 3) {
			scanf("%lld", &v);
			con[u][v] = 1;
		}
		else if (opt == 4) {
			for (auto x : vec[u]) con[x][u] = 1;
		}
		solve();
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
