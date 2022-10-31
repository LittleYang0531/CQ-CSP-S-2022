/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

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

const int MAXN = 5e5, MAXSN = 712;
int n, m, ideg[MAXN + 5], odeg[MAXN + 5];
int cnt, ord[MAXN + 5], seq[MAXN + 5], ref[MAXN + 5];
int lef[MAXN + 5], rig[MAXN + 5], sup[MAXN + 5];
bool maj[MAXN + 5];
std::vector<int> adj[MAXN + 5];
std::unordered_map<int, bool> exi[MAXN + 5];

int bsiz, bel[MAXN + 5], tag[MAXSN + 5];
std::unordered_map<int, int> buc[MAXSN + 5];
std::vector<int> oth[MAXN + 5];
std::unordered_set<int> dif[MAXN + 5];

inline void brkSig(const int s, const int t) {
    if (sup[s] != t) {
        bool& sta = exi[t][s];
        if (sta) {
            --buc[bel[ref[s]]][odeg[s]--], ++buc[bel[ref[s]]][odeg[s]];
            sta = false;
        }
    } else {
        if (maj[t] && dif[t].find(s) == dif[t].end()) {
            dif[t].insert(s);
            --buc[bel[ref[s]]][odeg[s]--], ++buc[bel[ref[s]]][odeg[s]];
        } else if (!maj[t] && dif[t].find(s) != dif[t].end()) {
            dif[t].erase(s);
            --buc[bel[ref[s]]][odeg[s]--], ++buc[bel[ref[s]]][odeg[s]];
        }
    }
}

inline void fixSig(const int s, const int t) {
    if (sup[s] != t) {
        bool& sta = exi[t][s];
        if (!sta) {
            --buc[bel[ref[s]]][odeg[s]++], ++buc[bel[ref[s]]][odeg[s]];
            sta = true;
        }
    } else {
        if (!maj[t] && dif[t].find(s) == dif[t].end()) {
            dif[t].insert(s);
            --buc[bel[ref[s]]][odeg[s]++], ++buc[bel[ref[s]]][odeg[s]];
        } else if (maj[t] && dif[t].find(s) != dif[t].end()) {
            dif[t].erase(s);
            --buc[bel[ref[s]]][odeg[s]++], ++buc[bel[ref[s]]][odeg[s]];
        }
    }
}

inline void shift(const int l, const int r, const int k) {
    if (l > r) return ;
    if (bel[l] == bel[r]) {
        rep (i, l, r) {
            --buc[bel[l]][odeg[seq[i]]], ++buc[bel[l]][odeg[seq[i]] += k];
        }
    } else {
        rep (i, l, bel[l] * bsiz){
            --buc[bel[l]][odeg[seq[i]]], ++buc[bel[l]][odeg[seq[i]] += k];
        }
        rep (i, (bel[r] - 1) * bsiz + 1, r) {
            --buc[bel[r]][odeg[seq[i]]], ++buc[bel[r]][odeg[seq[i]] += k];
        }
        rep (i, bel[l] + 1, bel[r] - 1) tag[i] += k;
    }
}

inline void brkAll(const int t) {
    for (int s: oth[t]) brkSig(s, t);
    if (maj[t]) {
        auto tmp(dif[t]);
        for (int s: tmp) fixSig(s, t);
        shift(lef[t], rig[t], -1), maj[t] = false;
    } else {
        auto tmp(dif[t]);
        for (int s: dif[t]) brkSig(s, t);
    }
    dif[t].clear();
}

inline void fixAll(const int t) {
    for (int s: oth[t]) fixSig(s, t);
    if (!maj[t]) {
        for (int s: dif[t]) brkSig(s, t);
        shift(lef[t], rig[t], 1), maj[t] = true;
    } else {
        for (int s: dif[t]) fixSig(s, t);
    }
    dif[t].clear();
}

inline bool check() {
    for (int l = 1, r, id = 1; l <= n; l = r + 1, ++id) {
        r = std::min(l + bsiz - 1, n);
        if (buc[id][1 - tag[id]] != r - l + 1) return false;
    }
    return true;
}

int main() {
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);

    n = rint(), m = rint();
    rep (i, 1, m) {
        int s = rint(), t = rint();
        ++ideg[t], ++odeg[s], adj[t].push_back(s);
    }

    std::iota(ord + 1, ord + n + 1, 1);
    std::sort(ord + 1, ord + n + 1,
        [](const int u, const int v) { return ideg[u] > ideg[v]; }
    );
    rep (i, 1, n) {
        int u = ord[i];
        lef[u] = cnt + 1;
        for (int v: adj[u]) {
            if (ref[v]) oth[u].push_back(v);
            else ++cnt, ref[seq[cnt] = v] = cnt, sup[v] = u;
        }
        rig[u] = cnt, maj[u] = true;
    }
    rep (i, 1, n) if (!ref[i]) ++cnt, ref[seq[cnt] = i] = cnt;
    rep (i, 1, n) for (int j: adj[i]) if (sup[j] != i) exi[i][j] = true;

    bsiz = ceil(sqrt(n));
    rep (i, 1, n) bel[i] = (i - 1) / bsiz + 1;
    rep (i, 1, n) ++buc[bel[i]][odeg[seq[i]]];

    for (int q = rint(), op, u; q--;) {
        op = rint(), u = rint();
        fprintf(stderr, "%d?\n", u);
        if (op == 1) brkSig(u, rint());
        else if (op == 2) brkAll(u);
        else if (op == 3) fixSig(u, rint());
        else fixAll(u);
        puts(check() ? "YES" : "NO");
    }

#ifdef RYBY
    fprintf(stderr, "%f(s)\n", double(clock()) / CLOCKS_PER_SEC);
#endif
    return 0;
}
