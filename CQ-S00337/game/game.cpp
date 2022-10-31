#include<bits/stdc++.h>
#define int long long
#define N ((int)2e5 + 2)
#define INF ((int)1e18 + 2)
#define eps 1e-8
#define db double
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i) 
using namespace std;
int n, m, Q;
int a[N], b[N];
struct Seg_tree {
	int obmx[N << 2], obmn[N << 2], nemx[N << 2], nemn[N << 2], zero_[N << 2];
	inline void pushup (int rt) {
		obmx[rt] = max(obmx[rt << 1], obmx[rt << 1 | 1]);
		obmn[rt] = min(obmn[rt << 1] == 0 ? INF : obmn[rt << 1], obmn[rt << 1 | 1] == 0 ? INF : obmn[rt << 1 | 1]);
		nemx[rt] = max(nemx[rt << 1] == 0 ? - INF : nemx[rt << 1], nemx[rt << 1 | 1] == 0 ? -INF : nemx[rt << 1 | 1]);
		nemn[rt] = min(nemn[rt << 1], nemn[rt << 1 | 1]);
		zero_[rt] = zero_[rt << 1] | zero_[rt << 1 | 1];
	}
	inline void build (int rt, int l, int r, int *p) {
		if (l == r) {
			if (p[l] > 0) {
				obmx[rt] = obmn[rt] = p[l]; }
			else if (p[l] < 0) {
				nemx[rt] = nemn[rt] = p[l]; }
			else if (p[l] == 0) zero_[rt] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(rt << 1, l, mid, p), build(rt << 1 | 1, mid + 1, r, p);
		pushup(rt);
	}
	inline int query_obmx (int rt, int l, int r, int a, int b) {
		if (a <= l && r <= b) return obmx[rt];
		int mid = (l + r) >> 1;
		int ret = 0;
		if (a <= mid) ret = max(ret, query_obmx(rt << 1, l, mid, a, b));
		if (b > mid) ret = max(ret, query_obmx(rt << 1 | 1, mid + 1, r, a, b));
		return ret;
	}
	inline int query_obmn (int rt, int l, int r, int a, int b) {
		if (a <= l && r <= b) return (obmn[rt] == 0 ? INF : obmn[rt]);
		int mid = (l + r) >> 1;
		int ret = INF;
		if (a <= mid) ret = min(ret, query_obmn(rt << 1, l, mid, a, b));
		if (b > mid) ret = min(ret, query_obmn(rt << 1 | 1, mid + 1, r, a, b));
		return ret;
	}
	inline int query_nemx (int rt, int l, int r, int a, int b) {
		if (a <= l && r <= b) return (nemx[rt] == 0 ? -INF : nemx[rt]);
		int mid = (l + r) >> 1;
		int ret = -INF;
		if (a <= mid) ret = max(ret, query_nemx(rt << 1, l, mid, a, b));
		if (b > mid) ret = max(ret, query_nemx(rt << 1 | 1, mid + 1, r, a, b));
		return ret;
	}
	inline int query_nemn (int rt, int l, int r, int a, int b) {
		if (a <= l && r <= b) return nemn[rt];
		int mid = (l + r) >> 1;
		int ret = 0;
		if (a <= mid) ret = min(ret, query_nemn(rt << 1, l, mid, a, b));
		if (b > mid) ret = min(ret , query_nemn(rt << 1 | 1, mid + 1, r, a, b));
		return ret;
	}
	inline int query_zero (int rt, int l, int r, int a, int b) {
		if (a <= l && r <= b) return zero_[rt];
		int mid = (l + r) >> 1;
		int ret = 0;
		if (a <= mid) ret |= query_zero(rt << 1, l, mid, a, b);
		if (b > mid) ret |= query_zero(rt << 1 | 1, mid + 1, r, a, b);
		return ret;
	}
}seg_tree_a, seg_tree_b;
inline void freo () {
	freopen("game.in", "r", stdin), freopen("game.out", "w", stdout); }
signed main () {
	freo();
	scanf("%lld%lld%lld", &n, &m, &Q);
	rep (i, 1, n) scanf("%lld", &a[i]);
	rep (i, 1, m) scanf("%lld", &b[i]);
	seg_tree_a.build(1, 1, n, a), seg_tree_b.build(1, 1, m, b);
	int l1, r1, l2, r2;
	while (Q--) {
		int ans = -INF;
		scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		int obup = seg_tree_a.query_obmx(1, 1, n, l1, r1);
		int obdn = seg_tree_a.query_obmn(1, 1, n, l1, r1);
		int neup = seg_tree_a.query_nemx(1, 1, n, l1, r1);
		int nedn = seg_tree_a.query_nemn(1, 1, n, l1, r1);
		int zero_a = seg_tree_a.query_zero(1, 1, n, l1, r1);
		int tmp = seg_tree_b.query_nemn(1, 1, m, l2, r2);
		int mn = min(tmp == 0 ? INF : tmp, seg_tree_b.query_obmn(1, 1, m, l2, r2));
		tmp = seg_tree_b.query_obmx(1, 1, m, l2, r2);
		int mx = max(tmp == 0 ? -INF : tmp, seg_tree_b.query_nemx(1, 1, m, l2, r2));
		int zero_b = seg_tree_b.query_zero(1, 1, m, l2, r2);
		/*cout << obup << " " << obdn << " " << neup << " " << nedn<<'\n';
		cout<<mn<<" "<<mx<<'\n';
		cout<<zero_a<<" "<<zero_b<<'\n';*/
		if (obup != 0) {
			if (mn != INF) {
				if (mn > 0 && zero_b) ans = max(ans, 0ll);
				else ans = max(ans, obup * mn);
			}
			else if (zero_b) ans = max(ans, 0ll);
		}
		if (obdn != INF) {
			if (mn != INF) {
				if (mn > 0 && zero_b) ans = max(ans, 0ll);
				else ans = max(ans, obdn * mn);
			}
			else if (zero_b) ans = max(ans, 0ll);
		}
		if (zero_a) ans = max(ans, 0ll);
		if (neup != -INF) {
			if (mx != -INF) {
				if (mx < 0 && zero_b) ans = max(ans, 0ll);
				else ans = max(ans, neup * mx);
			}
			else if (zero_b) ans = max(ans, 0ll);
		}
		if (nedn != 0) {
			if (mx != -INF) {
				if (mx < 0 && zero_b) ans = max(ans, 0ll);
				else ans = max(ans, nedn * mx);
			}
			else if (zero_b) ans = max(ans, 0ll);
		}
		printf("%lld\n", ans);
	}
return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2 
*/
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
