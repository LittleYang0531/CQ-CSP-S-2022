#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> inline void ckmin(T &x, T y) { x = x < y ? x : y; }
typedef long long ll;

const int N = 5e5 + 5;
int n, m, q, d[N], vic = 0;
set<int> fr[N], ot[N];
struct query {
    int op, u, v;
} qr[N];
namespace Brute_Force {
    void inc(int u, int x) {
        if (d[u] == 1) ++vic;
        d[u] += x;
        if (d[u] == 1) --vic;
    }
    void del(int u, int v) {
        fr[v].erase(u);
        ot[v].insert(u);
        inc(u, -1);
    }
    void add(int u, int v) {
        ot[v].erase(u);
        fr[v].insert(u);
        inc(u, 1);
    }
    void attack(int u) {
        for (int x : fr[u]) {
            inc(x, -1);
            ot[u].insert(x);
        }
        fr[u].clear();
    }
    void rebuild(int u) {
        for (int x : ot[u]) {
            inc(x, 1);
            fr[u].insert(x);
        }
        ot[u].clear();
    }
    void solve() {
        for (int tt = 1; tt <= q; ++tt) {
            switch(qr[tt].op) {
                case 1: {
                    del(qr[tt].u, qr[tt].v);
                    break;
                }
                case 2: {
                    attack(qr[tt].u);
                    break;
                }
                case 3: {
                    add(qr[tt].u, qr[tt].v);
                    break;
                }
                case 4: {
                    rebuild(qr[tt].u);
                }
            }
            cout << (vic == 0 ? "YES" : "NO") << '\n';
        }
    }
}
int main() {
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        fr[v].insert(u);
        ++d[u];
    }
    vic = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] != 1) {
            ++vic;
        }
    }
    cin >> q;
    bool flag = 1;
    for (int i = 1; i <= q; ++i) {
        cin >> qr[i].op >> qr[i].u;
        if (qr[i].op & 1) cin >> qr[i].v;
        if (qr[i].op == 4) flag = 0;
    }
    
    if ((n <= 1000 && m <= 10000 && q <= 1000) || flag) {
        Brute_Force::solve();
        return 0;
    }
    Brute_Force::solve(); 
    return 0;
}
