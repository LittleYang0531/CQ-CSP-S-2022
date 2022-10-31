#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= (int)n; ++i)
#define rep2(i, j, n) for (int i(j); i >= (int)n; --i)
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) f -= (ch == '-') << 1, ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
	x *= f;
}
inline int read() {int x; read(x); return x;}
template <typename T, typename ...L> inline void read(T &x, L &...y) {read(x); read(y...);}
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n, m, q, a[N], b[N];
bool flg = 0; 
struct node {int l, r, mxa, mia, mib, mxb;} t[N << 2];
inline int lson(int x) {return x << 1;}
inline int rson(int x) {return x << 1 | 1;}
inline void pushup(int x) {
	t[x].mxb = max(t[lson(x)].mxb, t[rson(x)].mxb);
	t[x].mib = min(t[lson(x)].mib, t[rson(x)].mib);
	t[x].mxa = max(t[lson(x)].mxa, t[rson(x)].mxa);
	t[x].mia = min(t[lson(x)].mia, t[rson(x)].mia);
}
inline void buildtree(int x, int l, int r) {
	t[x].l = l; t[x].r = r;
	if (l == r) {t[x].mib = t[x].mxb = b[l]; t[x].mxa = t[x].mia = a[l]; return ;}
	int mid = l + r >> 1;
	buildtree(lson(x), l, mid);
	buildtree(rson(x), mid + 1, r);
	pushup(x);
}
inline int querymx(int x, int L, int R, bool a) {
	if (t[x].l >= L && t[x].r <= R) return a ? t[x].mxa : t[x].mxb;
	int mid = t[x].l + t[x].r >> 1, res = -inf;
	if (L <= mid) res = max(res, querymx(lson(x), L, R, a));
	if (R > mid) res = max(res, querymx(rson(x), L, R, a));
	return res;
}
inline int querymi(int x, int L, int R, bool a) {
	if (t[x].l >= L && t[x].r <= R) return a ? t[x].mia : t[x].mib;
	int mid = t[x].l + t[x].r >> 1, res = inf;
	if (L <= mid) res = min(res, querymi(lson(x), L, R, a));
	if (R > mid) res = min(res, querymi(rson(x), L, R, a));
	return res;
}
signed main(void) {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n, m, q);
	rep1(i, 1, n) read(a[i]), flg |= (a[i] < 0);
	rep1(i, 1, m) read(b[i]), flg |= (b[i] < 0);
	if (!flg) {
		buildtree(1, 1, n);
		while (q--) {
			int l1, r1, l2, r2; read(l1, r1, l2, r2);
			printf("%lld\n", 1LL * querymi(1, l2, r2, 0) * querymx(1, l1, r1, 1));
		}
	} else {
		buildtree(1, 1, n);
		while (q--) {
			int l1, r1, l2, r2;
			read(l1, r1, l2, r2);
			long long ans = 0;
			if (l1 == r1) {
				int mx = querymx(1, l2, r2, 0), mi = querymi(1, l2, r2, 0);
				if (a[l1] < 0) ans = 1LL * mx * a[l1];
				else ans = 1LL * mi * a[l1];
			} else {
				int mx = querymx(1, l1, r1, 1), mi = querymi(1, l1, r1, 1);
				if (b[l2] < 0) ans = 1LL * mi * b[l2];
				else ans = 1LL * mx * b[l2];
			}
			printf("%lld\n", ans);
		}
	}
}
/*
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
*/
