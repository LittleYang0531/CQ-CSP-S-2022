/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

typedef long long LL;
using std::max;
using std::min;

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

const int MAXN = 1e5, MAXLG = 16, IINF = 0x3f3f3f3f;
int n, m, q, a[MAXN + 5], b[MAXN + 5], tmp[MAXN + 5], posc[MAXN + 5];

struct RMinQ {
    int st[MAXLG + 3][MAXN + 5];

    inline void build(const int len, int* ary) {
        memcpy(st[0], ary, len + 1 << 2);
        rep (i, 1, 31 - __builtin_clz(len)) {
            rep (j, 1, len - (1 << i) + 1) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i >> 1)]);
            }
        }
    }

    inline int ask(const int l, const int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

struct RMaxQ {
    int st[MAXLG + 3][MAXN + 5];

    inline void build(const int len, int* ary) {
        memcpy(st[0], ary, len + 1 << 2);
        rep (i, 1, 31 - __builtin_clz(len)) {
            rep (j, 1, len - (1 << i) + 1) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i >> 1)]);
            }
        }
    }

    inline int ask(const int l, const int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

RMaxQ amxp, amxn, bmx;
RMinQ amnp, amnn, bmn;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    n = rint(), m = rint(), q = rint();
    rep (i, 1, n) a[i] = rint();
    rep (i, 1, m) b[i] = rint();

    bmx.build(m, b), bmn.build(m, b);
    rep (i, 1, n) tmp[i] = a[i] >= 0 ? a[i] : -IINF;
    amxp.build(n, tmp);
    rep (i, 1, n) tmp[i] = a[i] < 0 ? a[i] : -IINF;
    amxn.build(n, tmp);
    rep (i, 1, n) tmp[i] = a[i] >= 0 ? a[i] : IINF;
    amnp.build(n, tmp);
    rep (i, 1, n) tmp[i] = a[i] < 0 ? a[i] : IINF;
    amnn.build(n, tmp);

    while (q--) {
        int l1 = rint(), r1 = rint(), l2 = rint(), r2 = rint();
        std::vector<int> A, B;
        A.push_back(amxp.ask(l1, r1)), A.push_back(amxn.ask(l1, r1));
        A.push_back(amnp.ask(l1, r1)), A.push_back(amnn.ask(l1, r1));
        B.push_back(bmx.ask(l2, r2)), B.push_back(bmn.ask(l2, r2));

        LL ans = -(1ll << 60);
        for (int u: A) if (u != IINF && u != -IINF) {
            LL cur = 1ll << 60;
            for (int v: B) cur = min(cur, 1ll * u * v);
            ans = max(ans, cur);
        }
        wint(ans), putchar('\n');
    }
    return 0;
}
