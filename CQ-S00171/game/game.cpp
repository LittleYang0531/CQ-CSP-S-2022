#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

void read(int &x) {
	x = 0;
	int f= 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-') f = -1;
		s = getchar();
	}
	while(s <= '9' && s >= '0') {
		x = x * 10 + s - '0';
		s = getchar();
	} 
	x *= f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10), x %= 10;
	putchar(x + '0');
}

int n, m, q, A[N], B[N];


#define ls k << 1
#define rs k << 1 | 1

struct Tree {
	int mx[N << 2], mn[N << 2];
	
	void update(int k) {
		mx[k] = max(mx[k], max(mx[ls], mx[rs]));
		mn[k] = min(mn[k], min(mn[ls], mn[rs]));
	}
	
	void build(int *a, int k, int l, int r) {
		if(l == r) {
			mx[k] = mn[k] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(a, ls, l ,mid), build(a, rs, mid + 1, r);
		update(k);
	}
	
	int query_mn(int k, int l, int r, int st, int ed) {
		if(st <= l && ed >= r) return mn[k];
		int mid = (l + r) >> 1, res = 1e9;
		if(st <= mid) res = query_mn(ls, l, mid, st, ed);
		if(ed > mid) res = min(res, query_mn(rs, mid + 1, r, st, ed));
		return res;
	}
	
	int query_mx(int k, int l, int r, int st, int ed) {
		if(st <= l && ed >= r) return mx[k];
		int mid = (l + r) >> 1, res = -1e9;
		if(st <= mid) res = query_mx(ls, l, mid, st, ed);
		if(ed > mid) res = max(res, query_mx(rs, mid + 1, r, st, ed));
		return res;
	}
}t[2];

ll ans;

ll find(int a, int b, int c, int d, int e, int f, int g, int h) {
	int x = A[a], y = B[c];
	ll tmp, mn = 1e18, mx = -1e18;
	for(int i = a; i <= b; i ++) { // 最小值最大, 次数最多 
		if(!A[i]) return 0;
		tmp = min(A[i] * g, A[i] * h);
		if(tmp > mx) x = A[i];
	}
	for(int i = c; i <= d; i ++) {
		if(!B[i]) return 0;
		tmp = max(B[i] * e, B[i] * f);
		if(tmp < mn) y = B[i];
	}
	return x * y;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &q);
	
	for(int i = 1; i <= n; i ++) read(A[i]);
	for(int i = 1; i <= m; i ++) read(B[i]);
	
	t[0].build(A, 1, 1, n);
	t[1].build(B, 1, 1, m);
	
	int a, b, c, d, la, lb, ra, rb, tx, ty;
	while(q --) {
		scanf("%d %d %d %d", &la, &ra, &lb, &rb);
		a = t[0].query_mn(1, 1, n, la, ra);
		b = t[0].query_mx(1, 1, n, la, ra);// L
		
		c = t[1].query_mn(1, 1, m, lb, rb);
		d = t[1].query_mx(1, 1, m, lb, rb);// Q
		
		if(a >= 0 && c >= 0) ans = b * c;
		if(a >= 0 && d <= 0) ans = a * c;
		
		if(b <= 0 && c >= 0) ans = b * d;
		if(b <= 0 && d <= 0) ans = a * d;
		
		if(a <= 0 && b >= 0) {
			if(c >= 0) ans = b * c;
			else if(d <= 0) ans = a * d;
			else {
				ans = find(la, ra, lb, rb, a, b, c, d);
			} 
		}
		
		if(c <= 0 && d >= 0) {
			if(a >= 0) ans = c * a;
			if(b <= 0) ans = d * b;
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


6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

脑子不够了 

*/
