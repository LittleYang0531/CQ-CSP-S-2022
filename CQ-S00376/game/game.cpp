#include<bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define i64 long long

const int N = 2e5 + 5, inf = 0x3f3f3f3f, P = 998244353;

int lg[N];

struct st
{
	int n, mn[18][N], mx[18][N];
	inline void built(int _n)
	{
		n = _n;
		for (re int i = 1; i <= lg[n]; ++i)
			for (re int j = 1; j + (1 << i) - 1 <= n; ++j)
				mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]),
				mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << i - 1)]);
	}
	inline int askmn(int l, int r)
	{
		int k = lg[r - l + 1];
		return min(mn[k][l], mn[k][r - (1 << k) + 1]);
	}
	inline int askmx(int l, int r)
	{
		int k = lg[r - l + 1];
		return max(mx[k][l], mx[k][r - (1 << k) + 1]);
	}
}px, nx, py, ny;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	File("game");
	int n, m, q; cin >> n >> m >> q;
	const int lim = max(n, m);
	
	for (re int i = 2; i <= lim; ++i)
		lg[i] = lg[i >> 1] + 1;
	
	for (re int i = 1; i <= n; ++i)	
		px.mn[0][i] = inf, px.mx[0][i] = -inf,
		nx.mn[0][i] = inf, nx.mx[0][i] = -inf;
	for (Re int i = 1; i <= m; ++i)
		py.mn[0][i] = inf, py.mx[0][i] = -inf,
		ny.mn[0][i] = inf, ny.mx[0][i] = -inf;
	
	for (re int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		if (x >= 0) px.mn[0][i] = px.mx[0][i] = x;
		else nx.mn[0][i] = nx.mx[0][i] = -x;
	}
	
	for (re int i = 1; i <= m; ++i)
	{
		int x; cin >> x;
		if (x >= 0) py.mn[0][i] = py.mx[0][i] = x;
		else ny.mn[0][i] = ny.mx[0][i] = -x;
	}
	
	px.built(n), nx.built(n), py.built(m), ny.built(m);
	
	for (re int i = 1; i <= q; ++i)
	{
		int lx, rx, ly, ry;
		cin >> lx >> rx >> ly >> ry;
		int X[4] = {px.askmn(lx, rx), px.askmx(lx, rx), -nx.askmn(lx, rx), -nx.askmx(lx, rx)};
		int Y[4] = {py.askmn(ly, ry), py.askmx(ly, ry), -ny.askmn(ly, ry), -ny.askmx(ly, ry)};
		i64 ans = -2e18;
		for (re int j = 0; j < 4; ++j)
			if (X[j] != inf && X[j] != -inf)
			{
				i64 res = 2e18;
				for (re int k = 0; k < 4; ++k)
					if (Y[k] != inf && Y[k] != -inf)
						res = min(res, 1ll * X[j] * Y[k]);
				ans = max(ans, res);
			}
		cout << ans << '\n';
	}
	
	return 0;
}
