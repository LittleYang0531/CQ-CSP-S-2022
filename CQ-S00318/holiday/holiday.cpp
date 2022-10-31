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

const int MAXN = 2.5e3, MAXM = 1e4, MAXK = 100, IINF = 0x3f3f3f3f;
int n, m, k, dis[MAXN + 5][MAXN + 5];
LL a[MAXN + 5];
std::vector<int> adj[MAXN + 5];
std::pair<LL, int> top[MAXN + 5][3];

inline void bfs(const int s, int* res) {
    static int hd, tl, que[MAXN + 5];
    memset(res, 0x3f, n + 1 << 2);
    res[que[hd = tl = 1] = s] = 0;
    while (hd <= tl) {
        int u = que[hd++];
        for (int v: adj[u]) if (res[v] == IINF) {
            res[que[++tl] = v] = res[u] + 1;
        }
    }
}

int main() {
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);

    n = rint(), m = rint(), k = rint() + 1;
    rep (i, 2, n) a[i] = rint<LL>();
    rep (i, 1, m) {
        int u = rint(), v = rint();
        adj[u].push_back(v), adj[v].push_back(u);
    }

    rep (i, 1, n) bfs(i, dis[i]);

    rep (i, 2, n) {
        rep (j, 2, n) if (i != j && dis[1][j] <= k && dis[i][j] <= k) {
            std::pair<LL, int> cur = { a[j], j };
            if (cur > top[i][0]) {
                top[i][2] = top[i][1], top[i][1] = top[i][0], top[i][0] = cur;
            } else if (cur > top[i][1]) {
                top[i][2] = top[i][1], top[i][1] = cur;
            } else if (cur > top[i][2]) {
                top[i][2] = cur;
            }
        }
    }

    LL ans = 0;
    rep (i, 2, n) rep (j, 2, n) if (i != j && dis[i][j] <= k) {
        rep (p, 0, 2) rep (q, 0, 2) {
            if (top[i][p].se && top[j][q].se && top[i][p].se != j
              && top[j][q].se != i && top[i][p].se != top[j][q].se) {
                ans = std::max(ans, top[i][p].fi + a[i] + a[j] + top[j][q].fi);
                // printf("%d %d <-%d-> %d %d: %lld\n",
                //   top[i][p].se, i, dis[i][j], j, top[j][q].se,
                //   top[i][p].fi + a[i] + a[j] + top[j][q].fi);
            }
        }
    }
    wint(ans), putchar('\n');
    return 0;
}

