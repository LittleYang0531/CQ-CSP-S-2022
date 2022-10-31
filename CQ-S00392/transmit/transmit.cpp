#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
const int maxn = 2e5 + 5;
const ll inf = 1e16;
int n, q, k, a[maxn];
vector<int> e[maxn];
int dfntimes, dfn[maxn], top[maxn], sz[maxn], son[maxn], pot[maxn], fa[maxn], dep[maxn];
void ckmin(ll &x, ll y) {
	x = y < x ? y : x;
}
struct matrix {
	ll a[3][3];
	matrix() {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				a[i][j] = inf;
			}
		}
	}
	friend matrix operator * (const matrix &x, const matrix &y) {
		matrix z;
		for(int i = 0; i < k; i++) {
			for(int p = 0; p < k; p++) {
				for(int j = 0; j < k; j++) {
					ckmin(z.a[i][j], x.a[i][p] + y.a[p][j]);
				}
			}
		}
		return z;
	}
} I;
struct node {
	matrix sl, sr;
	node() {
		sl = sr = matrix();
	}
	friend node operator + (const node &x, const node &y) {
		node z;
		z.sl = x.sl * y.sl;
		z.sr = y.sr * x.sr;
		return z;
	}
} t[maxn * 4];
void dfs1(int u, int from) {
	fa[u] = from;
	dep[u] = dep[from] + 1;
	sz[u] = 1;
	for(int v : e[u]) {
		if(v == from) {
			continue;
		}
		dfs1(v, u);
		sz[u] += sz[v];
		if(sz[son[u]] < sz[v]) {
			son[u] = v;
		}
	}
}
void dfs2(int u, int from) {
	dfn[u] = ++dfntimes;
	pot[dfntimes] = u;
	if(son[u]) {
		top[son[u]] = top[u];
		dfs2(son[u], u);
	}
	for(int v : e[u]) {
		if(v == from || v == son[u]) {
			continue;
		}
		top[v] = v;
		dfs2(v, u);
	}
}
#define lc (x << 1)
#define rc (x << 1 | 1)
#define mid ((l + r) >> 1)
void push_up(int x) {
	t[x] = t[lc] + t[rc];
}
void build(int x, int l, int r) {
	if(l == r) {
		t[x].sl = t[x].sr = matrix();
		for(int i = 0; i < k - 1; i++) {
			t[x].sl.a[i + 1][i] = t[x].sr.a[i + 1][i] = 0;
		}
		for(int i = 0; i < k; i++) {
			t[x].sl.a[i][k - 1] = t[x].sr.a[i][k - 1] = a[pot[l]];
		}
//		for(int i = 0; i < k; i++) {
//			for(int j = 0; j < k; j++) {
//				cout << t[x].sl.a[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	push_up(x);
}
node query(int x, int l, int r, int L, int R) {
	if(l >= L && r <= R) {
		return t[x];
	}
	if(mid >= L && mid < R) {
		return query(lc, l, mid, L, R) + query(rc, mid + 1, r, L, R);
	}
	else if(mid >= L) {
		return query(lc, l, mid, L, R);
	}
	else {
		return query(rc, mid + 1, r, L, R);
	}
}
#undef lc
#undef rc
#undef mid
ll query(int x, int y) {
	matrix res;
	node A, B;
	res.a[0][0] = 0;
	A.sl = B.sl = A.sr = B.sr = I;
	while(top[x] != top[y]) {
		if(dep[top[x]] > dep[top[y]]) {
			A = query(1, 1, n, dfn[top[x]], dfn[x]) + A;
			x = fa[top[x]];
		}
		else {
			B = query(1, 1, n, dfn[top[y]], dfn[y]) + B;
			y = fa[top[y]];
		}
	}
	if(dep[x] < dep[y]) {
		B = query(1, 1, n, dfn[x], dfn[y]) + B;
	}
	else {
		A = query(1, 1, n, dfn[y], dfn[x]) + A;
	}
	res = res * A.sr;
	res = res * B.sl;
	return res.a[0][k - 1];
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> k;
	for(int i = 0; i < k; i++) {
		I.a[i][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1, 0);
	top[1] = 1;
	dfs2(1, 0);
	build(1, 1, n);
	for(int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		cout << query(u, v) << '\n';
	}
	return 0;
}

