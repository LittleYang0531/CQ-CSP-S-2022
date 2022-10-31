#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> inline void ckmin(T &x, T y) { x = x < y ? x : y; }
typedef long long ll;

const int N = 1e5 + 5, INF = 2e9;
const ll INFLL = 2e18;
int n, m, q;
namespace SGTA {
    #define lc (k << 1)
    #define rc ((k << 1) | 1)
    int a[N];
    struct node {
        int mn, mx, mn2, mx2;
        node() { mn = mn2 = INF, mx = mx2 = -INF; }
        node(int mn, int mx, int mn2, int mx2) : mn(mn), mx(mx), mn2(mn2), mx2(mx2) {}
        friend node operator+(const node &x, const node &y) {
            return node(min(x.mn, y.mn), max(x.mx, y.mx), min(x.mn2, y.mn2), max(x.mx2, y.mx2));
        }
    } t[N << 2];
    void pushup(int k) { t[k] = t[lc] + t[rc]; }
    void doBuild(int k, int l, int r) {
        if (l == r) {
            t[k].mx = t[k].mn = a[l];
            if (a[l] <= 0) t[k].mx2 = a[l];
            if (a[l] >= 0) t[k].mn2 = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        doBuild(lc, l, mid);
        doBuild(rc, mid + 1, r);
        pushup(k);
    }
    node doQuery(int k, int l, int r, int L, int R) {
        if (l > R || r < L) return node();
        if (l >= L && r <= R) return t[k];
        int mid = (l + r) >> 1;
        return doQuery(lc, l, mid, L, R) + doQuery(rc, mid + 1, r, L, R);
    }
    #undef lc
    #undef rc
}
namespace SGTB {
    #define lc (k << 1)
    #define rc ((k << 1) | 1)
    int a[N];
    struct node {
        int mn, mx;
        node() { mn = INF, mx = -INF; }
        node(int mn, int mx) : mn(mn), mx(mx) {}
        friend node operator+(const node &x, const node &y) {
            return node(min(x.mn, y.mn), max(x.mx, y.mx));
        }
    } t[N << 2];
    void pushup(int k) { t[k] = t[lc] + t[rc]; }
    void doBuild(int k, int l, int r) {
        if (l == r) {
            t[k].mx = t[k].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        doBuild(lc, l, mid);
        doBuild(rc, mid + 1, r);
        pushup(k);
    }
    node doQuery(int k, int l, int r, int L, int R) {
        if (l > R || r < L) return node();
        if (l >= L && r <= R) return t[k];
        int mid = (l + r) >> 1;
        return doQuery(lc, l, mid, L, R) + doQuery(rc, mid + 1, r, L, R);
    }
    #undef lc
    #undef rc
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cin >> SGTA::a[i];
    for (int i = 1; i <= m; ++i) cin >> SGTB::a[i];
    SGTA::doBuild(1, 1, n);
    SGTB::doBuild(1, 1, m);
    for (int l1, r1, l2, r2; q; --q) {
        cin >> l1 >> r1 >> l2 >> r2;
        auto x = SGTA::doQuery(1, 1, n, l1, r1);
        auto y = SGTB::doQuery(1, 1, m, l2, r2);
        ll ans = -INFLL;
        ckmax(ans, min((ll)x.mx * y.mx, (ll)x.mx * y.mn));
        ckmax(ans, min((ll)x.mn * y.mx, (ll)x.mn * y.mn));
        if (x.mx2 > -INF) ckmax(ans, min((ll)x.mx2 * y.mx, (ll)x.mx2 * y.mn));
        if (x.mn2 < INF) ckmax(ans, min((ll)x.mn2 * y.mx, (ll)x.mn2 * y.mn));
        cout << ans << '\n';
    }
    return 0;
}
