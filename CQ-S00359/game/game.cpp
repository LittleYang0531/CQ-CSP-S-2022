#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
struct segment {
	int n, a[N], ls[N], rs[N], nd, rt, c_[N], c[N];
	struct seg {int l, r, mx1, mn1, mx0, mn0;} T[N];
	void P_up(int x) {
		T[x].mx1 = max(T[ls[x]].mx1, T[rs[x]].mx1);
		T[x].mx0 = max(T[ls[x]].mx0, T[rs[x]].mx0);
		T[x].mn1 = min(T[ls[x]].mn1, T[rs[x]].mn1);
		T[x].mn0 = min(T[ls[x]].mn0, T[rs[x]].mn0);
	}
	void Build(int &x, int l, int r) {
		x = ++nd;
		T[x] = (seg) {l, r, -inf, inf, -inf, inf};
		if(l == r) {
			if(a[l] >= 0) T[x].mx1 = T[x].mn1 = a[l];
			if(a[l] <= 0) T[x].mx0 = T[x].mn0 = -a[l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(ls[x], l, mid), Build(rs[x], mid + 1, r);
		P_up(x);
	}
	int op_, op;
	int Ask(int x, int l, int r) {
		if(l <= T[x].l && T[x].r <= r) {
			if(op_) {return op ? T[x].mx1 : T[x].mn1;}	//zheng
			else {return op ? T[x].mx0 : T[x].mn0;}	 //fu
		}
		int mid = (T[x].l + T[x].r) >> 1;
		if(l <= mid) {
			if(r > mid) {return op ? max(Ask(ls[x], l, r), Ask(rs[x], l, r)) : min(Ask(ls[x], l, r), Ask(rs[x], l, r));}
			else return Ask(ls[x], l, r);
		}
		else {return Ask(rs[x], l, r);}
	}
	int Sign(int l, int r) {
		if(!(c[r] - c[l - 1])) return -1;
		if(!(c_[r] - c_[l - 1])) return 1;
		return 0;
	}
	void init() {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			c[i] = c[i - 1] + (a[i] >= 0);
			c_[i] = c_[i - 1] + (a[i] <= 0);
		}
		Build(rt, 1, n);
	}
}A, B;


int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	int q;
	scanf("%d%d%d", &A.n, &B.n, &q);
	A.init(); B.init();
	for(int i = 1; i <= q; i++) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int sa = A.Sign(l1, r1), sb = B.Sign(l2, r2);
//		printf("*sa=%d sb=%d\n", sa, sb);
		ll ans = -1e18;
		if(sa != -1) {	//A有正 
//			puts("A+");
			A.op_ = 1;
			if(sb == 1) {
				A.op = 1; B.op = 0; B.op_ = 1; ans = max(ans, 1ll * A.Ask(1, l1, r1) * B.Ask(1, l2, r2));
//				printf("+  %d * %d\n", A.Ask(1, l1, r1), B.Ask(1, l2, r2));
			}
			else {
				A.op = 0; B.op = 1; B.op_ = 0; ans = max(ans, -1ll * A.Ask(1, l1, r1) * B.Ask(1, l2, r2));
//				printf("-  %d(%d) * %d(%d)\n", A.Ask(1, l1, r1), mn, B.Ask(1, l2, r2), mx);
			} 
		}
		if(sa != 1) {	//A有负 
//			puts("A-");
			A.op_ = 0;
			if(sb == -1) {
				A.op = 1; B.op = 0; B.op_ = 0; ans = max(ans, 1ll * A.Ask(1, l1, r1) * B.Ask(1, l2, r2));
//				printf("+  %d * %d\n", A.Ask(1, l1, r1), B.Ask(1, l2, r2));
			}
			else {
				A.op = 0; B.op = 1; B.op_ = 1; ans = max(ans, -1ll * A.Ask(1, l1, r1) * B.Ask(1, l2, r2));
//				printf("-  %d * %d\n", A.Ask(1, l1, r1), B.Ask(1, l2, r2));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

//6 4 5
//3 -1 -2 1 2 0
//1 2 -1 -3
//1 6 1 4
//1 5 1 4
//1 4 1 2
//2 6 3 4
//2 5 2 3

