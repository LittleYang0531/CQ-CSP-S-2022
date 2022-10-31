#include <stdio.h>
#include <assert.h>
#include <set>
#include <vector>
using Pr = std::pair<int, int>;
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

const int kMaxN = 500100;
int n, m;
std::set<int> adj[kMaxN];
std::vector<int> F[kMaxN];

bool chk() {
    rep(i,1,n)
        if (adj[i].size() != 1U) return 0;
    return 1;
}

signed main() {
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);
    n = rint(), m = rint();
    for (int i=1,u,v; i<=m; ++i) {
        u = rint(), v = rint();
        adj[u].insert(v);
        F[v].push_back(u);
    }
    for (int q=rint(),t,u; q--;) {
        t = rint(), u = rint();
        if (t == 1) {
            int v = rint();
            assert(adj[u].count(v));
            adj[u].erase(v);
        } else if (t == 2) {
            for (auto v : F[u])
                adj[v].erase(u);
        } else if (t == 3) {
            adj[u].insert(rint());
        } else if (t == 4) {
            for (auto v : F[u])
                adj[v].insert(u);
        }
        if (chk()) puts("YES");
        else puts("NO");
    }
}
/*
16:44, 这个睿智的暴力过了前三个样例
hope for 40 pts
*/