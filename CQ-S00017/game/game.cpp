#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 1e5 + 5;
const LL INF = 1e18;

template<typename T>
void read(T& x) {
  x = 0; int f = 1; char c = getchar(); while (c > '9' || c < '0') { if (c == '-') f = -f; c = getchar(); }
  while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); } x *= f;
}
template<typename T>
T Max(T x, T y) { return x > y ? x : y; }
template<typename T>
T Min(T x, T y) { return x < y ? x : y; }
template<typename T>
T Abs(T x) { return x < 0 ? -x : x; }

int n, m, q;
LL a[MAXN], b[MAXN], c[MAXN];

struct Data {
  LL neg0, neg1, pos0, pos1;
  Data operator + (const Data& oth) const {
    return Data {
      Min(neg0, oth.neg0),
      Max(neg1, oth.neg1),
      Min(pos0, oth.pos0),
      Max(pos1, oth.pos1)
    };
  }
};

int check(Data x) {
  if (x.neg0 == INF) return 1;
  else if (x.pos0 == INF) return 2;
  else return 3;
}
struct SegmentTree {
  struct Node {
    int l, r;
    Data dat;
  } s[MAXN << 2];
  void push_up(int p) { s[p].dat = s[p << 1].dat + s[p << 1 | 1].dat; }
  void build(int p, int l, int r) {
    s[p].l = l, s[p].r = r;
    if (l == r) {
      if (c[l] < 0) s[p].dat = Data{c[l], c[l], INF, -INF};
      else s[p].dat = Data{INF, -INF, c[l], c[l]};
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    push_up(p);
  }
  Data query(int p, int l, int r) {
    if (s[p].l >= l && s[p].r <= r) return s[p].dat;
    int mid = (s[p].l + s[p].r) >> 1; Data res = {INF, -INF, INF, -INF};
    if (l <= mid) res = res + query(p << 1, l, r);
    if (r > mid) res = res + query(p << 1 | 1, l, r);
    return res;
  }
} sega, segb;

int main() {

  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);

  read(n), read(m), read(q);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= m; i++) read(b[i]);

  for (int i = 1; i <= n; i++) c[i] = a[i];
  sega.build(1, 1, n);
  for (int i = 1; i <= n; i++) c[i] = b[i];
  segb.build(1, 1, n);

  for (int i = 1, l1, l2, r1, r2; i <= q; i++) {
    read(l1), read(r1), read(l2), read(r2);
    LL res = 0;

    Data x = sega.query(1, l1, r1);
    Data y = segb.query(1, l2, r2);

    // printf("x : %lld %lld %lld %lld\n", x.neg0, x.neg1, x.pos0, x.pos1);
    // printf("y : %lld %lld %lld %lld\n", y.neg0, y.neg1, y.pos0, y.pos1);

    int opty = check(y), optx = check(x);
    // printf("%d\n", opt);
    if (opty == 1) {
      if (optx == 1 || optx == 3) res = x.pos1 * y.pos0;
      if (optx == 2) res = x.neg1 * y.pos1;
    }
    if (opty == 2) {
      if (optx == 1) res = x.pos0 * y.neg0;
      if (optx == 2 || optx == 3) res = x.neg0 * y.neg1;
    }
    if (opty == 3) {
      if (optx == 1) res = x.pos0 * y.neg0;
      if (optx == 2) res = x.neg1 * y.pos1;
      if (optx == 3) res = Max(x.pos0 * y.neg0, x.neg1 * y.pos1);
    }

    printf("%lld\n", res);

  }

  return 0;
}