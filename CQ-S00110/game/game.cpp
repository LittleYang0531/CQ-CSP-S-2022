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
#include <bits/stdc++.h>
using namespace std;

#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define Check(a) freopen(a".in", "r", stdin), freopen(a".ans", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t i7;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int mod = 1e9 + 7;
inline void mi(int &x, int y) {x += y, x >= mod && (x -= mod);}
inline void ad(int &x, int y) {x -= y, x < 0 && (x += mod);}

const int N = 2e5 + 7;
const ll INF = 1e10, IIN = 2e18;

int n, m, q, pa[N], pb[N]; ll a[N];

struct seg {
	ll mx[N << 2], mn[N << 2], MN[N << 2], MX[N << 2];
	
	#define ls (x << 1)
	#define rs (x << 1 | 1)
	
	inline void build(int x, int l, int r) {
		if (l == r) {
			if (a[l] >= 0) MN[x] = a[l]; else MN[x] = INF;
			if (a[l] <= 0) MX[x] = a[l]; else MX[x] = -INF;
			mx[x] = mn[x] = a[l]; return ;
		}
		
		int mid = (l + r) >> 1;
		build(ls, l, mid); build(rs, mid + 1, r);
		mx[x] = max(mx[ls], mx[rs]); MX[x] = max(MX[ls], MX[rs]);
		mn[x] = min(mn[ls], mn[rs]); MN[x] = min(MN[ls], MN[rs]);
	}
	
	inline ll MAX(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) return mx[x];
		
		int mid = (l + r) >> 1; ll re = -INF, rt = -INF;
		L <= mid && (re = MAX(ls, l, mid, L, R));
		R > mid && (rt = MAX(rs, mid + 1, r, L, R));
		return max(re, rt);
	}
	
	inline ll MIN(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) return mn[x];
		
		int mid = (l + r) >> 1; ll re = INF, rt = INF;
		L <= mid && (re = MIN(ls, l, mid, L, R));
		R > mid && (rt = MIN(rs, mid + 1, r, L, R));
		return min(re, rt);
	}
	
	inline ll _MAX(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) return MX[x];
		
		int mid = (l + r) >> 1; ll re = -INF, rt = -INF;
		L <= mid && (re = _MAX(ls, l, mid, L, R));
		R > mid && (rt = _MAX(rs, mid + 1, r, L, R));
		return max(re, rt);
	}
	
	inline ll _MIN(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) return MN[x];
		
		int mid = (l + r) >> 1; ll re = INF, rt = INF;
		L <= mid && (re = _MIN(ls, l, mid, L, R));
		R > mid && (rt = _MIN(rs, mid + 1, r, L, R));
		return min(re, rt);
	}
} S, T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	File("game");
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i], pa[i] = pa[i - 1] + (a[i] == 0);
	S.build(1, 1, n);
	for (int i = 1; i <= m; ++i) cin >> a[i], pb[i] = pb[i - 1] + (a[i] == 0);
	T.build(1, 1, m);
	
	int l1, r1, l2, r2;
	while (q--) {
		cin >> l1 >> r1 >> l2 >> r2;
		ll mx = S.MAX(1, 1, n, l1, r1), mn = S.MIN(1, 1, n, l1, r1), m0 = pa[r1] - pa[l1 - 1];
		ll Mx = T.MAX(1, 1, m, l2, r2), Mn = T.MIN(1, 1, m, l2, r2), M0 = pb[r2] - pb[l2 - 1];
//		cout << mx << " " << mn << " " << Mx << " " << Mn << " ";
		if (Mx <= 0) {
			if (mn <= 0) cout << mn * Mx << "\n";
			else cout << mn * Mn << "\n";
		}
		else if (Mn > 0) {
			if (mx > 0) cout << mx * Mn << "\n";
			else cout << mx * Mx << "\n";
		}
		else {
			if (m0) cout << "0\n";
			else {
				ll _mn = S._MIN(1, 1, n, l1, r1), _mx = S._MAX(1, 1, n, l1, r1);
				ll re = -IIN, rt = -IIN;
				if (_mn != INF) re = _mn * Mn;
				if (_mx != -INF) rt = _mx * Mx;
				cout << max(re, rt) << "\n";
			}
		}
	}
	
	return 0;
}
