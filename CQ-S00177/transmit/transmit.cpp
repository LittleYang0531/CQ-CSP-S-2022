#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= int(r); ++i)
#define rep2(i, l, r) for (int i = l; i >= int(r); --i)
#define fst first
#define snd second
#define mp make_pair
#define eb emplace_back
#define ptc putchar
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 2e5 + 10, INF = ~0U >> 1, inf = ~0U >> 2;
const int LOGN = log2(MAXN) + 1;
namespace stupid_lrc {
	template <typename T> il void read(T &x) {
		x = 0; int f = 1; char ch;
		while (!isdigit(ch = getchar())) if (ch == '-') f = -1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T, typename ...L> il void read(T &x, L &...y) {
		read(x); read(y...);
	}
};
using namespace stupid_lrc;
int n, q, k, v[MAXN], f[MAXN][LOGN + 5], d[MAXN]; vector <int> lnk[MAXN];
ll sum[MAXN];

il void dfs(int x, int p) {
	d[x] = d[p] + 1; f[x][0] = p; sum[x] = v[x] + sum[p];
	for (auto v : lnk[x]) if (v ^ p) dfs(v, x);
}

il int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	rep2(i, LOGN, 0) if (d[u] - d[v] >= 1 << i) u = f[u][i];
	if(u==v)return u;
	rep2(i, LOGN, 0) if (f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n, q, k); rep1(i, 1, n) read(v[i]);
	rep1(i, 1, n - 1) {
		int u, v; read(u, v); lnk[u].eb(v); lnk[v].eb(u);
	}
	dfs(1, 0);
	rep1(j, 1, LOGN) rep1(i, 1, n) f[i][j] = f[f[i][j - 1]][j - 1];
	while (q--) {
		int s, t; read(s, t); int p = lca(s, t);
		ll ans = sum[s] + sum[t] - sum[p] - sum[f[p][0]];
		printf("%lld\n", ans);
	}
	return 0;
}

