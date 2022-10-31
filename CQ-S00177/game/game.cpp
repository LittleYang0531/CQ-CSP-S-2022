#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= int(r); ++i)
#define rep2(i, l, r) for (int i = l; i >= int(r); --i)
#define fst first
#define snd second
#define mp make_pair
#define eb emplace_back
#define ptc putchar
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 1e5 + 10, INF = ~0U >> 1, inf = ~0U >> 2;
namespace stupid_lrc {
	template <typename T> il void read(T &x) {
		x = 0; int f = 1; char ch;
		while (!isdigit(ch = getchar())) if (ch == '-') f = -1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T, typename ...L> il void read(T &x, L &...y) {
		read(x); read(y...);
	}
};
using namespace stupid_lrc;
int n, m, q, a[MAXN], s1[MAXN], s2[MAXN];

struct setr {
	#define STZ MAXN << 2
	int maa[STZ], mii[STZ];
	
	il void pushup(int x) {
		maa[x] = max(maa[ls(x)], maa[rs(x)]);
		mii[x] = min(mii[ls(x)], mii[rs(x)]);
	}
	
	il void build(int x, int l, int r) {
		if (l == r) return maa[x] = mii[x] = a[l], void();
		int mid = l + r >> 1;
		build(ls(x), l, mid); build(rs(x), mid + 1, r);
		pushup(x);
	}
	
	il int query1(int x, int l, int r, int ql, int qr) {
		if (l > qr || r < ql) return -inf;
		if (l >= ql && r <= qr) return maa[x];
		int mid = l + r >> 1;
		return max(query1(ls(x), l, mid, ql, qr), query1(rs(x), mid + 1, r, ql, qr));
	}
	
	il int query2(int x, int l, int r, int ql, int qr) {
		if (l > qr || r < ql) return inf;
		if (l >= ql && r <= qr) return mii[x];
		int mid = l + r >> 1;
		return min(query2(ls(x), l, mid, ql, qr), query2(rs(x), mid + 1, r, ql, qr));
	}
} t, t1[2], t2[2];

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n, m, q);
	rep1(i, 1, n) read(s1[i]);
	rep1(i, 1, m) read(s2[i]);
	rep1(i, 1, m) a[i] = s2[i]; t.build(1, 1, m);
	rep1(i, 1, n) {
		if (s1[i] >= 0) a[i] = s1[i];
		else a[i] = inf;
	} t1[0].build(1, 1, n);
	rep1(i, 1, n) {
		if (s1[i] >= 0) a[i] = s1[i];
		else a[i] = -inf;
	} t1[1].build(1, 1, n);
	rep1(i, 1, n) {
		if (s1[i] < 0) a[i] = s1[i];
		else a[i] = inf;
	} t2[0].build(1, 1, n);
	rep1(i, 1, n) {
		if (s1[i] < 0) a[i] = s1[i];
		else a[i] = -inf;
	} t2[1].build(1, 1, n);
	
	while (q--) {
		int l1, r1, l2, r2;
		read(l1, r1, l2, r2);
		ll maa = t.query1(1, 1, m, l2, r2), mii = t.query2(1, 1, m, l2, r2);
		ll ans = LONG_LONG_MIN;
//		cout << "!!!" << maa << " " << mii << ' ' << ans << endl;
		if (maa >= 0 && maa != -inf) {
			int p = t2[1].query1(1, 1, n, l1, r1);
			if (p != -inf) ans = max(ans, maa * p);
//			cout << "!" << p << endl;
		} else if (maa != -inf) {
			int p = t2[0].query2(1, 1, n, l1, r1);
			if (p != inf) ans = max(ans, maa * p);
//			cout << "!!" << p << endl;
		}
		
		if (mii >= 0 && mii != inf) {
			int p = t1[1].query1(1, 1, n, l1, r1);
			if (p != -inf) ans = max(ans, mii * p);
//			cout << "!!!" << p << endl;
		} else if (mii != inf) {
			int p = t1[0].query2(1, 1, n, l1, r1);
			if (p != inf) ans = max(ans, mii * p);
//			cout << "!!!!" << p << endl;
		}
		
		printf("%lld\n", ans);
//		return 0;
	}
	return 0;
}
// lrc 数组没开够的惨案！！！！！ int maa[MAXN], mimi[MAXN] 
