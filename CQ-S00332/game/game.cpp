#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 1e9 + 7;
typedef long long LL;

int tr[2][N << 2][2][2], ans[2][2][2], num[2][N];

void build(int Now, int l, int r, int opt) {
	if(l == r) {
		if(num[opt][l] > 0) {
			tr[opt][Now][0][0] = INF;
			tr[opt][Now][0][1] = -INF;
			tr[opt][Now][1][0] = tr[opt][Now][1][1] = num[opt][l];
		} else if(num[opt][l] < 0) {
			tr[opt][Now][0][0] = tr[opt][Now][0][1] = num[opt][l];
			tr[opt][Now][1][0] = INF;
			tr[opt][Now][1][1] = -INF;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(Now << 1, l, mid, opt);
	build(Now << 1 | 1, mid + 1, r, opt);
	tr[opt][Now][0][0] = min(tr[opt][Now << 1][0][0], tr[opt][Now << 1 | 1][0][0]);
	tr[opt][Now][1][0] = min(tr[opt][Now << 1][1][0], tr[opt][Now << 1 | 1][1][0]);
	tr[opt][Now][0][1] = max(tr[opt][Now << 1][0][1], tr[opt][Now << 1 | 1][0][1]);
	tr[opt][Now][1][1] = max(tr[opt][Now << 1][1][1], tr[opt][Now << 1 | 1][1][1]);
}

void query(int Now, int l, int r, int x, int y, int opt) {
	if(x <= l && r <= y) {
		ans[opt][0][0] = min(ans[opt][0][0], tr[opt][Now][0][0]);
		ans[opt][0][1] = max(ans[opt][0][1], tr[opt][Now][0][1]);
		ans[opt][1][0] = min(ans[opt][1][0], tr[opt][Now][1][0]);
		ans[opt][1][1] = max(ans[opt][1][1], tr[opt][Now][1][1]);
		return;
	} 
	int mid = (l + r) >> 1;
	if(x <= mid) {
		query(Now << 1, l, mid, x, y, opt);
	}
	if(y > mid) {
		query(Now << 1 | 1, mid + 1, r, x, y, opt);
	}
}

void read(int &x) {
	x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	} 
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x = x * f;
}

void print(LL x) {
	if(x <= 9) {
		putchar(x + '0');
		return;
	} 
	print(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, q, l1, r1, l2, r2;
	read(n), read(m), read(q);
	for(int i = 1; i <= n; ++i) {
		read(num[0][i]);
	}
	for(int j = 1; j <= m; ++j) {
		read(num[1][j]);
	}
	build(1, 1, n, 0);
	build(1, 1, m, 1);
	for(int i = 1; i <= q; ++i) {
		read(l1), read(r1), read(l2), read(r2);
		ans[0][0][0] = ans[0][1][0] = ans[1][0][0] = ans[1][1][0] = INF;
		ans[0][0][1] = ans[0][1][1] = ans[1][0][1] = ans[1][1][1] = -INF;
		query(1, 1, n, l1, r1, 0);
		query(1, 1, m, l2, r2, 1);
		LL sol = 0;
		if(ans[1][1][0] == INF) {
			int x = min(ans[0][0][0], ans[0][1][0]);
			if(x > 0) {
				sol = (LL)x * ans[1][0][0];
			} else {
				sol = (LL)x * ans[1][0][1];
			}
		} else if(ans[1][0][0] == INF) {
			int x = max(ans[0][0][1], ans[0][1][1]);
			if(x > 0) {
				sol = (LL)x * ans[1][1][0];
			} else {
				sol = (LL)x * ans[1][1][1];
			}
		} else {
			if(ans[0][0][0] == INF) {
				sol = (LL)ans[0][1][0] * ans[1][0][0];
			} else if(ans[0][1][0] == INF) {
				sol = (LL)ans[0][0][1] * ans[1][1][1];
			} else {
				sol = max((LL)ans[0][1][0] * ans[1][0][0], (LL)ans[0][0][1] * ans[1][1][1]);
			}
		}
		if(sol < 0) {
			putchar('-');
			sol = -sol;
		}
		print(sol);
		puts("");
	}
	return 0;
}
