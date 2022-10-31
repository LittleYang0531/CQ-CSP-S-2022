#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for (int i(a); i<=(b); ++i)
#define drep(i,b,a) for (int i(b); i>=(a); --i)
inline int rint() {
    int n(0), f(1);
    char s(getchar());
    for (; s<'0'||s>'9'; s=getchar())
        if (s == '-') f = -1;
    for (; s>='0'&&s<='9'; s=getchar())
        n = n*10+s-48;
    return n*f;
}

const int kMaxN = 200100;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
int n, q, K, val[kMaxN];
int Fa[20][kMaxN], par[kMaxN], dep[kMaxN];
long long sum[kMaxN];
std::vector<int> adj[kMaxN];

void dfs(int u, int fa) {
    sum[u] = sum[fa]+val[u];
    dep[u] = dep[Fa[0][u] = par[u] = fa]+1;
    rep(i,1,19)
        Fa[i][u] = Fa[i-1][Fa[i-1][u]];
    for (auto v : adj[u])
        if (v != fa) dfs(v, u);
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    drep(i,19,0)
        if (dep[Fa[i][u]] >= dep[v])
            u = Fa[i][u];
    if (u == v) return u;
    drep(i,19,0)
        if (Fa[i][u] != Fa[i][v])
            u = Fa[i][u], v = Fa[i][v];
    return par[u];
}

namespace K1 {
    void solve() {
        dfs(1, 0);
        for (int u,v; q--;) {
            u = rint(), v = rint();
            int l = lca(u, v);
            printf("%lld\n", sum[u]+sum[v]-2*sum[par[l]]-val[l]);
        }
    }
}

namespace KG {
    int seq[kMaxN], tot;
    long long dp[kMaxN];

    void get_seq(int u, int v) {
        tot = 0;
        int l = lca(u, v);
        while (u != l) seq[++tot] = u, u = par[u];
        std::vector<int> tmp;
        tmp.reserve(dep[v]-dep[l]);
        seq[++tot] = l;
        while (v != l) tmp.emplace_back(v), v = par[v];
        tmp.shrink_to_fit();
        for (auto it=tmp.rbegin(); it!=tmp.rend(); ++it)
            seq[++tot] = *it;
    }

    void solve() {
        for (int u,v; q--;) {
            u = rint(), v = rint();
            get_seq(u, v);
            dp[1] = val[seq[1]];
            for (int i=2; i<=tot; ++i) {
                dp[i] = llinf;
                for (int t=1; t<=K; ++t)
                    if (i-t >= 1)
                        dp[i] = std::min(dp[i], dp[i-t]+val[seq[i]]);
            }
            printf("%lld\n", dp[tot]);
        }
    }
}

signed main() {
    freopen("transmit.in", "r", stdin);
    freopen("transmit.out", "w", stdout);
    n = rint(), q = rint(), K = rint();
    rep(i,1,n) val[i] = rint();
    for (int i=1,u,v; i<n; ++i) {
        u = rint(), v = rint();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    if (K == 1) K1::solve();
    else KG::solve();
}
/*
k = 1 等价于 Path Sum
k > 1:
    放到序列上看
    dp[i] = min(dp[j])+a[i], |i-j| <= k
先打吧, , ,
这样例 #2 啥玩意儿啊, 怎么都凑不出来吧, , ,
润, [8, 52] pts
*/