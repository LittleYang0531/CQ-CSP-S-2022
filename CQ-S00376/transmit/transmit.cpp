#include<bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define i64 long long

const int N = 2e5 + 5, inf = 0x3f3f3f3f, P = 998244353;

i64 a[N], aa[N], aaa[N];
int first[N], nex[N << 1], to[N << 1], num;
inline void Add(int u, int v)
{
	nex[++num] = first[u];
	first[u] = num;
	to[num] = v;
	aa[u] = min(aa[u], a[v]);
}

int dep[N], fa[N], siz[N], son[N];
inline void dfs1(int u)
{
	siz[u] = 1, son[u] = -1;
	for (re int i = first[u]; i; i = nex[i])
	{
		int v = to[i];
		if (v == fa[u]) continue;
		fa[v] = u, dep[v] = dep[u] + 1;
		dfs1(v);
		siz[u] += siz[v];
		if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}
int top[N];
inline void dfs2(int u, int tp)
{
	top[u] = tp;
	if (son[u] == -1) return;
	dfs2(son[u], tp);
	for (re int i = first[u]; i; i = nex[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

inline int LCA(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

int b[N], c[N];

struct
{
	inline void solve(int n)
	{
		i64 ans = 0;
		for (re int i = 1; i <= n; ++i) ans += a[b[i]];
		cout << ans << '\n';	
	}
}K1;

struct
{
	i64 f[N][2];
	inline void solve(int n)
	{
		if (n <= 2) return cout << a[b[1]] + a[b[2]] << '\n', void();
		f[1][0] = a[b[1]], f[1][1] = 1e15;
		f[2][0] = a[b[1]] + a[b[2]], f[2][1] = a[b[1]];
		for (re int i = 3; i < n; ++i)
		{
			f[i][0] = min(f[i - 1][0], f[i - 1][1]) + a[b[i]];
			f[i][0] = min(f[i][0], f[i - 2][0] + aa[b[i - 1]] + a[b[i]]);
			f[i][1] = f[i - 1][0];
		}
		f[n][0] = min(f[n - 1][0], f[n - 1][1]) + a[b[n]];
		f[n][0] = min(f[n][0], f[n - 2][0] + aa[b[n - 1]] + a[b[n]]);
		cout << f[n][0] << '\n';
	}
}K2;

struct
{
	i64 f[N][2][2];
	inline void solve(int n)
	{
		if (n <= 2) return cout << a[b[1]] + a[b[2]] << '\n', void();
		f[2][0][0] = a[b[2]] + a[b[1]], f[2][0][1] = 1e15;
		f[2][1][0] = a[b[2]], f[2][1][1] = 1e15;
		for (re int i = 3; i < n; ++i)
		{
			f[i][0][0] = min(f[i - 1][0][0], f[i - 1][0][1]) + a[b[i]];
			f[i][0][1] = min(f[i - 1][1][0], f[i - 1][1][1]) + a[b[i]];
			f[i][1][0] = min(f[i - 1][0][0], f[i - 1][0][1]);
			f[i][1][1] = f[i - 1][1][0];
		}
		f[n][0][0] = min(f[n - 1][0][0], f[n - 1][0][1]) + a[b[n]];
		f[n][0][1] = min(f[n - 1][1][0], f[n - 1][1][1]) + a[b[n]];
		cout << min(f[n][0][0], f[n][0][1]) << '\n';
	}
}K3;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	File("transmit");
	int n, T, K; cin >> n >> T >> K;
	for (re int i = 1; i <= n; ++i) cin >> a[i], aaa[i] = aa[i] = a[i];
	for (re int i = 1; i < n; ++i)
	{
		int u, v; cin >> u >> v;
		Add(u, v), Add(v, u);
	}
	for (re int u = 1; u <= n; ++u)
		for (re int i = first[u]; i; i = nex[i])
			aaa[u] = min(aaa[u], aa[to[i]]);
	dfs1(1), dfs2(1, 1);
	
	while (T--)
	{
		int u, v; cin >> u >> v;
		int lca = LCA(u, v);
		int cnt = 0, tmp = 0;
		while (u != lca) b[++cnt] = u, u = fa[u];
		b[++cnt] = lca;
		while (v != lca) c[++tmp] = v, v = fa[v];
		for (re int i = tmp; i; --i) b[++cnt] = c[i];
		
		if (K == 1) K1.solve(cnt);
		else if (K == 2) K2.solve(cnt);
		else K3.solve(cnt);
	}
	
	return 0;
}

/*
479806606 51944511

*/
