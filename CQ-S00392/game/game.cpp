#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 1e9 + 1;
int n, m, q, a[maxn], b[maxn];
struct SGT {
	#define lc (x << 1)
	#define rc (x << 1 | 1)
	#define mid ((l + r) >> 1)
	int mx[maxn * 4], mn[maxn * 4];
	void build(int x, int l, int r) {
		mx[x] = -inf;
		mn[x] = inf;
		if(l == r) {
			return;
		}
		build(lc, l, mid);
		build(rc, mid + 1, r);
	}
	void push_up(int x) {
		mn[x] = min(mn[lc], mn[rc]);
		mx[x] = max(mx[lc], mx[rc]);
	}
	void modify(int x, int l, int r, int p, int v) {
		if(l == r) {
			mn[x] = mx[x] = v;
			return;
		}
		mid >= p ? modify(lc, l, mid, p, v) : modify(rc, mid + 1, r, p, v);
		push_up(x);
	}
	int query_min(int x, int l, int r, int L, int R) {
		if(l >= L && r <= R) {
			return mn[x];
		}
		int res = inf;
		if(mid >= L) {
			res = min(res, query_min(lc, l, mid, L, R));
		}
		if(mid < R) {
			res = min(res, query_min(rc, mid + 1, r, L, R));
		}
		return res;
	}
	int query_max(int x, int l, int r, int L, int R) {
		if(l >= L && r <= R) {
			return mx[x];
		}
		int res = -inf;
		if(mid >= L) {
			res = max(res, query_max(lc, l, mid, L, R));
		}
		if(mid < R) {
			res = max(res, query_max(rc, mid + 1, r, L, R));
		}
		return res;
	}
	#undef lc
	#undef rc
	#undef mid
} A, B, C;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	A.build(1, 1, n);
	B.build(1, 1, n);
	C.build(1, 1, m);
	for(int i = 1; i <= n; i++) {
		if(a[i] >= 0) {
			A.modify(1, 1, n, i, a[i]);
		}
		else {
			B.modify(1, 1, n, i, a[i]);
		}
	}
	for(int i = 1; i <= m; i++) {
		C.modify(1, 1, m, i, b[i]);
	}
	while(q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		ll ans = -1e18;
		int mn = C.query_min(1, 1, m, l2, r2), mx = C.query_max(1, 1, m, l2, r2);
		if(mn != inf && mn < 0) {
			int t = A.query_min(1, 1, n, l1, r1);
			if(t != inf) {
				ans = max(ans, 1ll * t * mn);
			}
		}
		if(mn != inf && mn >= 0) {
			int t = A.query_max(1, 1, n, l1, r1);
			if(t != -inf) {
				ans = max(ans, 1ll * t * mn);
			}
		}
		if(mx != -inf && mx < 0) {
			int t = B.query_min(1, 1, n, l1, r1);
			if(t != inf) {
				ans = max(ans, 1ll * t * mx);
			}
		}
		if(mx != -inf && mx >= 0) {
			int t = B.query_max(1, 1, n, l1, r1);
			if(t != -inf) {
				ans = max(ans, 1ll * t * mx);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

