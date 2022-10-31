#include<bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define ft first
#define sd second
#define mkp make_pair
const int N = 1e5 + 10, inf = 1.1e18;
using namespace std;
int n, m, q, a[N], b[N];
struct node {
	int mx, mi, cmx, cmi, flg;
} ta[N << 2], tb[N << 2], emp;
int ls(int x) {return x << 1;}
int rs(int x) {return x << 1 | 1;}
void pushup(node &x, node l, node r) {
	x.mx = max(l.mx, r.mx); x.cmx = max(l.cmx, r.cmx);
	x.mi = min(l.mi, r.mi); x.cmi = min(l.cmi, r.cmi);
	x.flg = l.flg | r.flg;
}
void build1(int sub, int l, int r) {
	if(l == r) {
		int k = a[l]; ta[sub].mx = ta[sub].mi = k;
		ta[sub].cmx = k < 0 ? k : -inf;
		ta[sub].cmi = k > 0 ? k : inf;
		ta[sub].flg = !k; return ;
	} int mid = (l + r) >> 1;
	build1(ls(sub), l, mid);
	build1(rs(sub), mid + 1, r);
	pushup(ta[sub], ta[ls(sub)], ta[rs(sub)]);
}
void build2(int sub, int l, int r) {
	if(l == r) {
		int k = b[l]; tb[sub].mx = tb[sub].mi = k;
		tb[sub].cmx = k < 0 ? k : -inf;
		tb[sub].cmi = k > 0 ? k : inf;
		tb[sub].flg = !k; return ;
	} int mid = (l + r) >> 1;
	build2(ls(sub), l, mid);
	build2(rs(sub), mid + 1, r);
	pushup(tb[sub], tb[ls(sub)], tb[rs(sub)]);
}
node query(int sub, int l, int r, int x, int y, int p) {
	if(l > y || r < x) return emp;
	if(l >= x && r <= y) return p ? ta[sub] : tb[sub];
	int mid = (l + r) >> 1;
	if(y <= mid) return query(ls(sub), l, mid, x, y, p);
	if(x > mid) return query(rs(sub), mid + 1, r, x, y, p);
	node a = query(ls(sub), l, mid, x, y, p);
	node b = query(rs(sub), mid + 1, r, x, y, p);
	node ans; pushup(ans, a, b); return ans;
}
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &q);
	emp.cmi = emp.mi = inf; emp.cmx = emp.mx = -inf;
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for(int i = 1; i <= m; ++i) scanf("%lld", b + i);
	build1(1, 1, n); build2(1, 1, m);
	for(int i = 1; i <= q; ++i) {
		int l1, l2, r1, r2; scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		node A = query(1, 1, n, l1, r1, 1);
		node B = query(1, 1, m, l2, r2, 0);
		if(B.cmx == -inf) {
			if(A.mx >= 0) printf("%lld\n", A.mx * B.mi);
			else printf("%lld\n", A.mx * B.mx);
		}
		else if(B.cmi == inf) {
			if(A.mi <= 0) printf("%lld\n", A.mi * B.mx);
			else printf("%lld\n", A.mi * B.mi);
		}
		else if(B.cmx != -inf && B.cmi != inf) {
			if(A.flg) puts("0");
			else {
				int k1 = -inf, k2 = -inf;
				if(A.cmi != inf) k1 = A.cmi * B.mi;
				if(A.cmx != -inf) k2 = A.cmx * B.mx;
				printf("%lld\n", max(k1, k2));
			}
		}
		else puts("0");
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/
