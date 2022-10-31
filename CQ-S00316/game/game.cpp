#include <stdio.h>
#include <functional>
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

const int kMaxN = 100100;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
int n, m, q, a[kMaxN], b[kMaxN], lgs[kMaxN];
int pra[kMaxN], prb[kMaxN], pra0[kMaxN], prb0[kMaxN];
bool tag[kMaxN];

inline int myabs(int x) {
    return x > 0 ? x : -x;
}

struct segment {
#define mid ((l+r)/2)
    int _n;
    int mx[kMaxN*4], mn[kMaxN*4];
    void upd(int p) {
        mx[p] = std::max(mx[p*2], mx[p*2+1]);
        mn[p] = std::min(mn[p*2], mn[p*2+1]);
    }
    void build(int n, int a[], bool tag[]){
        _n = n;
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                if (tag[l]) mn[p] = mx[p] = myabs(a[l]);
                else mn[p] = inf, mx[p] = -inf;
            } else {
                build(p*2, l, mid), build(p*2+1, mid+1, r), upd(p);
            }
        }; build(1, 1, _n);
    }
    int get_max(int l, int r) { return get_max(l, r, 1, 1, _n); }
    int get_min(int l, int r) { return get_min(l, r, 1, 1, _n); }
    int get_max(int fr, int ba, int p, int l, int r) {
        if (l > ba || r < fr) return -inf;
        if (l >= fr && r <= ba) return mx[p];
        return std::max(get_max(fr, ba, p*2, l, mid), get_max(fr, ba, p*2+1, mid+1, r));
    }
    int get_min(int fr, int ba, int p, int l, int r) {
        if (l > ba || r < fr) return inf;
        if (l >= fr && r <= ba) return mn[p];
        return std::min(get_min(fr, ba, p*2, l, mid), get_min(fr, ba, p*2+1, mid+1, r));
    }
} sgta_pos, sgta_neg, sgtb_pos, sgtb_neg;

signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    n = rint(), m = rint(), q = rint();
    rep(i,1,n) a[i] = rint();
    rep(i,1,m) b[i] = rint();
    rep(i,1,n) tag[i] = a[i] > 0;
    sgta_pos.build(n, a, tag);
    rep(i,1,n) tag[i] = a[i] < 0;
    sgta_neg.build(n, a, tag);
    rep(i,1,m) tag[i] = b[i] > 0;
    sgtb_pos.build(m, b, tag);
    rep(i,1,m) tag[i] = b[i] < 0;
    sgtb_neg.build(m, b, tag);
    rep(i,1,n)
        if (a[i] < 0) pra[i] = 1;
        else if (a[i] == 0) pra0[i] = 1;
    rep(i,1,m)
        if (b[i] < 0) prb[i] = 1;
        else if (b[i] == 0) prb0[i] = 1;
    rep(i,1,n)
        pra[i] += pra[i-1], pra0[i] += pra0[i-1];
    rep(i,1,m)
        prb[i] += prb[i-1], prb0[i] += prb0[i-1];
    for (int l1,r1,l2,r2; q--;) {
        l1 = rint(), r1 = rint();
        l2 = rint(), r2 = rint();
        long long ans = -llinf;
        if (pra[r1]-pra[l1-1] == 0) {
            if (prb[r2]-prb[l2-1] == 0)
                ans = (long long)sgta_pos.get_max(l1, r1)*sgtb_pos.get_min(l2, r2);
            else if (prb[r2]-prb[l2-1] == r2-l2+1)
                ans = -(long long)sgta_pos.get_min(l1, r1)*sgtb_neg.get_max(l2, r2);
            else
                ans = -(long long)sgta_pos.get_min(l1, r1)*sgtb_neg.get_max(l2, r2);
        } else if (pra[r1]-pra[l1-1] == r1-l1+1) {
            if (prb[r2]-prb[l2-1] == r2-l2+1)
                ans = (long long)sgta_neg.get_max(l1, r1)*sgtb_neg.get_min(l2, r2);
            else if (prb[r2]-prb[l2-1] == 0)
                ans = -(long long)sgta_neg.get_min(l1, r1)*sgtb_pos.get_max(l2, r2);
            else
                ans = -(long long)sgta_neg.get_min(l1, r1)*sgtb_pos.get_max(l2, r2);
        } else {
            if (prb[r2]-prb[l2-1] == 0)
                ans = (long long)sgta_pos.get_max(l1, r1)*sgtb_pos.get_min(l2, r2);
            else if (prb[r2]-prb[l2-1] == r2-l2+1)
                ans = (long long)sgta_neg.get_max(l1, r1)*sgtb_neg.get_min(l2, r2);
            else
                ans = std::max(-(long long)sgta_pos.get_min(l1, r1)*sgtb_neg.get_max(l2, r2),
                               -(long long)sgta_neg.get_min(l1, r1)*sgtb_pos.get_max(l2, r2));
        }
        if (pra0[r1]-pra0[l1-1] > 0 && ans < 0) ans = 0;
        if (prb0[r2]-prb0[l2-1] > 0 && ans > 0) ans = 0;
        printf("%lld\n", ans);
    }
}
/*
1. 两边全正
  P1 取 max, P2 取 min
3. P1 全正 P2 全负
  P1 取 min, P2 取绝对值 max
7. P1 全正 P2 混杂
  P1 取 min, P2 取负数中绝对值 max
  
2. 两边全负
  P1 取绝对值 max, P2 取绝对值 min
4. P1 全负 P2 全正
  P1 取绝对值 min, P2 取 max
8. P1 全负 P2 混杂
  P1 取绝对值 min, P2 取正数中 max

5. P1 混杂 P2 全正
  P1 取正数中 max, P2 取 min
6. P1 混杂 P2 全负
  P1 取负数中绝对值 max, P2 取绝对值 min
9. P1 P2 混杂
  P1 取正数中 min, P2 取负数中绝对值 max
  P1 取负数中绝对值 min, P2 取正数中 max
 两种情况取 max

- P1 有 0
  如果上述结果 < 0, 则 P1 取 0
- P2 有 0
  如果上述结果 > 0, 则 P2 取 0

维护:
  正数一棵线段树, 负数一棵线段树, 特判 0

现在是 15: 38, 我过了所有样例
hope for 100 pts
*/