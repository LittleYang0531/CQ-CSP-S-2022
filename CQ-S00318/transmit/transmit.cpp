/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

typedef long long LL;
#define fi first
#define se second

inline char fgc() {
    static char buf[1 << 17], *p = buf, *q = buf;
    return p == q && (q = buf + fread(p = buf, 1, 1 << 17, stdin), p == q)
      ? EOF : *p++;
}

template <typename Tp = int>
inline Tp rint() {
    Tp x = 0, f = 1, s = fgc();
    for (; s < '0' || '9' < s; s = fgc()) f = s == '-' ? -f : f;
    for (; '0' <= s && s <= '9'; s = fgc()) x = x * 10 + (s ^ '0');
    return x * f;
}

template <typename Tp>
inline void wint(Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (9 < x) wint(x / 10);
    putchar(x % 10 ^ '0');
}

const int MAXN = 2e5, MAXLG = 17;
const LL LINF = 1ll << 60;
int n, q, k, a[MAXN + 5];
std::vector<int> adj[MAXN + 5];

namespace K1 {

int dep[MAXN + 5], fa[MAXLG + 2][MAXN + 5];
LL dis[MAXN + 5];

inline void init(const int u) {
    dep[u] = dep[fa[0][u]] + 1, dis[u] = dis[fa[0][u]] + a[u];
    for (int v: adj[u]) if (v != fa[0][u]) fa[0][v] = u, init(v);
}

inline int lca(int u, int v) {
    static int H = 31 - __builtin_clz(n);
    if (dep[u] < dep[v]) std::swap(u, v);
    per (i, H, 0) if (dep[fa[i][u]] >= dep[v]) u = fa[i][u];
    if (u == v) return u;
    per (i, H, 0) if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}

inline void main() {
    init(1);
    rep (i, 1, 31 - __builtin_clz(n)) {
        rep (j, 1, n) {
            fa[i][j] = fa[i - 1][fa[i - 1][j]];
        }
    }
    while (q--) {
        int s = rint(), t = rint(), w = lca(s, t);
        wint(dis[s] + dis[t] - 2 * dis[w] + a[w]), putchar('\n');
    }
}

} // namespace K1

namespace Small {

const int PN = 200;
LL w[PN + 5][PN + 5];

inline void link(const int u, const int fa, const int d, const int s) {
    if (s != u) w[s][u] = a[u];
    if (d == k) return ;
    for (int v: adj[u]) if (v != fa) link(v, u, d + 1, s);
}

inline void main() {
    rep (i, 1, n) rep (j, 1, n) w[i][j] = LINF;
    rep (i, 1, n) w[i][i] = 0, link(i, 0, 0, i);
    rep (k, 1, n) rep (i, 1, n) rep (j, 1, n) {
        w[i][j] = std::min(w[i][j], w[i][k] + w[k][j]);
    }
    while (q--) {
        int s = rint(), t = rint();
        wint(w[s][t] + a[s]), putchar('\n');
    }
}

} // namespace Small

int main() {
    freopen("transmit.in", "r", stdin);
    freopen("transmit.out", "w", stdout);

    n = rint(), q = rint(), k = rint();
    rep (i, 1, n) a[i] = rint();
    rep (i, 2, n) {
        int u = rint(), v = rint();
        adj[u].push_back(v), adj[v].push_back(u);
    }

    if (k == 1) K1::main();
    else Small::main();
    return 0;
}

