#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> inline void ckmin(T &x, T y) { x = x < y ? x : y; }
typedef long long ll;

const int N = 2e5 + 5, K = 4;
const ll INF = 1e16;
int n, q, c, val[N];
vector<int> G[N];
ll ans[N];
struct Matrix {
    ll mat[K][K];
    Matrix() { clear(); }
    ll *operator[](int i) { return mat[i]; }
    void clear() {
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                mat[i][j] = INF;
            }
        }
    }
    void makee() {
        for (int i = 0; i <= c; ++i) {
            for (int j = 0; j <= c; ++j) {
                mat[i][j] = INF;
            }
            mat[i][i] = 0;
        }
    }
    bool ise() {
        for (int i = 0; i <= c; ++i) {
            for (int j = 0; j <= c; ++j) {
                if (i == j && mat[i][j] != 0) return false;
                if (i != j && mat[i][j] != INF) return false;
            }
        }
        return true;
    }
    friend Matrix operator*(Matrix &x, Matrix &y) {
        Matrix z;
        for (int i = 0; i <= c; ++i) {
            for (int j = 0; j <= c; ++j) {
                for (int k = 0; k <= c; ++k) {
                    ckmin(z[i][j], x[i][k] + y[k][j]);
                }
            }
        }
        return z;
    }
}vm[N];

#define lc(o) t[o].ch[0]
#define rc(o) t[o].ch[1]
struct node {
    Matrix m;
    int ch[2];
    void clear() { ch[0] = ch[1] = 0, m.makee(); }
} t[N * 20];
int rt[N], tot = 0, buc[N * 20], bcnt = 0;
int newnode() { int id = bcnt ? buc[bcnt--] : ++tot; t[id].clear(); return id; }
void recycle(int x) { buc[++bcnt] = x; }
void doUpdate(int &k, int l, int r, int pos, int val) {
    if (!k) k = newnode();
    if (l == r) {
        t[k].m.clear();
        t[k].m[0][0] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) doUpdate(lc(k), l, mid, pos, val);
    else doUpdate(rc(k), mid + 1, r, pos, val);
}
void doModify(int k, Matrix &m) {
    if (k) {
        t[k].m = m * t[k].m;
    }
}
void pushdown(int k) {
    if (!t[k].m.ise()) {
        if (lc(k)) doModify(lc(k), t[k].m);
        if (rc(k)) doModify(rc(k), t[k].m);
        t[k].m.makee();
    }
}
int doMerge(int x, int y, int l, int r) {
    if (!x || !y) return x | y;
    if (l == r) {
        for (int i = 0; i <= c; ++i) {
            for (int j = 0; j <= c - i; ++j) {
                ckmin(ans[l], t[x].m[i][0] + t[y].m[j][0]);
            }
        }
        recycle(x);
        recycle(y);
        return 0;
    }
    pushdown(x);
    pushdown(y);
    int mid = (l + r) >> 1;
    lc(x) = doMerge(lc(x), lc(y), l, mid);
    rc(x) = doMerge(rc(x), rc(y), mid + 1, r);
    recycle(y);
    if (!lc(x) && !rc(x)) {
        recycle(x);
        return 0;
    }
    return x;
}

ll dp[N][K];
 
void dfs(int u, int fa) {
    for (int v : G[u]) if (v != fa) {
        dfs(v, u);
        doModify(rt[v], vm[u]);
        rt[u] = doMerge(rt[u], rt[v], 1, q);
    }
}

int main() {
    freopen("transmit.in", "r", stdin);
    freopen("transmit.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1, s, t; i <= q; ++i) {
        cin >> s >> t;
        doUpdate(rt[s], 1, q, i, val[s]);
        doUpdate(rt[t], 1, q, i, val[t]);
        ans[i] = INF;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            dp[i][j] = INF;
        }
        dp[i][0] = val[i];
    }
    for (int j = 1; j <= c; ++j) {
        for (int u = 1; u <= n; ++u) {
            for (int v : G[u]) {
                ckmin(dp[u][j], dp[v][j - 1]);
            }
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = 0; i <= c; ++i) {
            for (int j = 0; j <= c - i - 1; ++j) {
                vm[u][i][j] = dp[u][i];
            }
        }
        for (int i = 1; i <= c; ++i) vm[u][i][i - 1] = 0;
//        cerr << u << ":\n";
//        for (int i = 0; i <= c; ++i) {
//            for (int j = 0; j <= c; ++j) {
//                if (vm[u][i][j] < INF) cerr << vm[u][i][j] << ' ';
//                else cerr << "INF ";
//            }
//            cerr << '\n';
//        }
    }
    dfs(1, 0);
    assert(!rt[1]);
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
