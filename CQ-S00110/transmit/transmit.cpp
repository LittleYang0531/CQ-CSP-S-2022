/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
*/
#include <bits/stdc++.h>
using namespace std;

#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define Check(a) freopen(a".in", "r", stdin), freopen(a".ans", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t i7;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int mod = 1e9 + 7;
inline void mi(int &x, int y) {x += y, x >= mod && (x -= mod);}
inline void ad(int &x, int y) {x -= y, x < 0 && (x += mod);}

const int N = 2e5 + 7, K = 2006;
const ll INF = 1e16;

int n, q, k, fst[N], tot;
struct edge {int nxt, to;} e[N << 1];
ll a[N];

#define add(u, v) (e[++tot] = (edge) {fst[u], v}, fst[u] = tot)

int de[N], fa[N][20]; ll le[N];

inline void dfs(int u, int f) {
	de[u] = de[f] + 1; le[u] = le[f] + a[u];
	for (int i = 1; i < 20; ++i) 
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = fst[u], v; i; i = e[i].nxt) 
		(v = e[i].to) ^ f && (fa[v][0] = u, dfs(v, u), 1);
}

inline int lca(int u, int v) {
	de[u] < de[v] && (u ^= v ^= u ^= v);
	
	for (int i = 19; ~i; --i) 
		de[fa[u][i]] >= de[v] && (u = fa[u][i]);
	if (u == v) return u;
	
	for (int i = 19; ~i; --i) 
		fa[u][i] ^ fa[v][i] && (u = fa[u][i], v = fa[v][i]);
	return fa[u][0];
}

vector<int> g[K];
ll di[K][K]; bool vi[K];

inline void find(int u, int cur, int zs, int f) {
	if (cur < 0) return ;
	for (int i = fst[u], v; i; i = e[i].nxt)
		(v = e[i].to) ^ f && (find(v, cur - 1, zs, u), g[zs].push_back(v), 1);
}

inline void dijkstra(ll *dis, int s) {
	for (int i = 1; i <= n; ++i) dis[i] = INF, vi[i] = 0;
	priority_queue<pii> q;
	dis[s] = a[s]; q.push(mp(-dis[s], s));
	
	while (!q.empty()) {
		int u = q.top().se; q.pop();
		if (vi[u]) continue;
		vi[u] = 1;
		
		for (int v : g[u]) dis[v] > dis[u] + a[v] && (
			dis[v] = dis[u] + a[v], !vi[v] && (q.push(mp(-dis[v], v)), 1));
	}
}

inline void sub1() {
	for (int i = 1; i <= n; ++i) find(i, k, i, 0);
	for (int i = 1; i <= n; ++i) dijkstra(di[i], i);
	while (q--) {
		int u, v; cin >> u >> v; cout << di[u][v] << "\n";
	}
}

inline void sub2() {
	dfs(1, 0);
	while (q--) {
		int u, v, lc; cin >> u >> v; lc = lca(u, v);
		cout << le[u] + le[v] - le[lc] * 2 + a[lc] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	File("transmit");
	
	cin >> n >> q >> k; --k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1, u, v; i < n; ++i) 
		cin >> u >> v, add(u, v), add(v, u);
		
	if (k == 0) return sub2(), 0;
	if (n <= 2000) return sub1(), 0;
	
	return 0;
}
