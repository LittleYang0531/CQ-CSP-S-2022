// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢？那是因为德丽莎很可爱！
// 没有力量的理想是空虚，没有理想的力量是戏言
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define repd(i, l, r) for(int i = (l); i >= (r); i--)
bool o1;
const int N = 1e6 + 5, inf = 1e18;
int n, m, q, a[N], b[N];
class segment{
  public:
  int mx[N], mn[N];
  int ls(int p) {  return p << 1; }
  int rs(int p) {  return p << 1 | 1;  }
  void pushup(int p) {
    mx[p] = max(mx[ls(p)], mx[rs(p)]);
    mn[p] = min(mn[ls(p)], mn[rs(p)]);
  }
  void build(int p,int l,int r,int *t) {
    if (l == r) {  mx[p] = mn[p] = t[l];  return;  }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid, t);
    build(rs(p), mid + 1, r, t);
    pushup(p);  
  }
  void change(int p,int l,int r,int pos,int val) {
    if (l == r) {  mx[p] = mn[p] = val;  return;  }
    int mid = (l + r) >> 1;
    if (pos <= mid)  change(ls(p), l, mid, pos, val);
    else  change(rs(p), mid + 1, r, pos, val);
    pushup(p);
  }
  int askmn(int p,int l,int r,int nx,int ny) {
    if (nx <= l && r <= ny)  return mn[p];
    int ans = inf, mid = (l + r) >> 1;
    if (nx <= mid)  ans = min(ans, askmn(ls(p), l, mid, nx, ny));
    if (ny > mid)  ans = min(ans, askmn(rs(p), mid + 1, r, nx, ny));
    return ans;
  }
  int askmx(int p,int l,int r,int nx,int ny) {
    if (nx <= l && r <= ny)  return mx[p];
    int mid = (l + r) >> 1, ans = -inf;
    if (nx <= mid)  ans = max(ans, askmx(ls(p), l, mid, nx, ny));
    if (ny > mid)  ans = max(ans, askmx(rs(p), mid + 1, r, nx, ny));
    return ans;
  }
} B, A1, A2, A3, A4;
int cnt[N];
void solve() {
  cin >> n >> m >> q;
  rep (i, 1, n)  cin >> a[i];
  rep (i, 1, m)  cin >> b[i];
  if (n <= 1000 && m <= 1000 && q <= 1000) {
    rep (i, 1, q) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      int mx = -inf, mn = inf;
      rep (j, l2, r2)  mx = max(mx, b[j]), mn = min(mn, b[j]);
      int nowans = -inf;
      rep (j, l1, r1) {
        int now = min(a[j] * mx, a[j] * mn);
        nowans = max(nowans, now);
      }
      cout << nowans << "\n";
    }
    return;
  } else {
    B.build(1, 1, m, b);
    rep (i, 1, n) {
      // A1  +mx
      // A4  +mn
      // A2 - mx
      // A3 - mn
      if (a[i] < 0) {
        A2.change(1, 1, n, i, a[i]);
        A3.change(1, 1, n, i, a[i]);
        A4.change(1, 1, n, i, inf);
      } else if (a[i] > 0) {
        A1.change(1, 1, n, i, a[i]);
        A4.change(1, 1, n, i, a[i]);
        A2.change(1, 1, n, i, -inf);
      } else if (a[i] == 0) {
        cnt[i] ++;
        A4.change(1, 1, n, i, inf);
        A2.change(1, 1, n, i, -inf);
      }
    }
    rep (i, 1, n)  cnt[i] += cnt[i - 1];
    rep (i, 1, q) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      int bmn = B.askmn(1, 1, m, l2, r2);
      int bmx = B.askmx(1, 1, m, l2, r2);
      int azmn = A4.askmn(1, 1, n, l1, r1);
      int azmx = A1.askmx(1, 1, n, l1, r1);
      int afmn = A3.askmn(1, 1, n, l1, r1);
      int afmx = A2.askmx(1, 1, n, l1, r1);
      int ans = -inf;
      if (azmx != 0)  ans = max(ans, bmn * azmn);
      if (azmx != 0)  ans = max(ans, bmn * azmx);
      if (afmn != 0)  ans = max(ans, bmx * afmn);
      if (afmn != 0)  ans = max(ans, bmx * afmx);
      if (cnt[r1] - cnt[l1 - 1] > 0) {
        ans = max(ans, 0ll);
      }
      cout << ans << "\n";
    }
  }
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

0
-2
3
2
-1

*/
bool o2;
#define LOCAL_DEFINE
signed main () {
#ifdef LOCAL_DEFINE
//  cerr << "Memory used :" << (double) 1.0 * (&o1 - &o2) / 1024 / 1024 << ".Mib\n";
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
#endif
  ios :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  while (T--)  solve();
#ifdef LOCAL_DEFINE
//  cerr << "Time used : " << 1.0 * clock() / CLOCKS_PER_SEC << ".s\n";
#endif
  return 0;
}

