#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5+10, K=1e3, LIM = 1e6;
int n, m, q;
long long a[N], b[N];
void Read() {
	scanf ("%lld%lld%lld", &n, &m, &q);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%lld", &b[i]);
	}
}
int Log[LIM];
long long c[LIM];
long long f_mi[20][LIM], f_mx[20][LIM];
void ST() {
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			c[++cnt] = a[j]*b[i];
		}
	}
	Log[0]=-1;
	for (int i = 1; i <= cnt; ++i) {
		Log[i]=Log[i>>1]+1;
//		printf ("%d ", c[i]);
		f_mi[0][i] = c[i], f_mx[0][i] = c[i];
	}
	for (int i = 1; i <= Log[cnt]; ++i) {
		for (int j = 1; j + (1  << (i - 1)) <= cnt; ++j) {
			f_mi[i][j] = min(f_mi[i-1][j], f_mi[i-1][j+(1<<(i-1))]);
			f_mx[i][j] = max(f_mx[i-1][j], f_mx[i-1][j+(1<<(i-1))]);
		}
	}
}
inline long long rmq1(const int &op, const int &l, const int &r) {
	int ll = (op-1)*n+l;
	int rr = (op-1)*n+r;
	int k=Log[rr+ll-1];
	return max(f_mx[k][ll], f_mx[k][rr-(1<<k)+1]);
}
inline long long rmq2(const int &l, const int &r, const int &op) {
	int ll = (l-1)*n+op;
	int rr = (r-1)*n+op;
	int k=Log[rr+ll-1];
	return min(f_mi[k][ll], f_mi[k][rr-(1<<k)+1]);
}
void Solve() {
//	if (1ll*n*m*q<=1e8) {
//		solve();
//		return;
//	}
	ST();
	int l1, l2, r1, r2;
	while (q--) {
		scanf ("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		if (l1==r1) {
			printf ("%lld\n", rmq2(l2, r2, l1));
		}
		else {
			printf ("%lld\n", rmq1(l2, l1, r1));
		}
	}
}
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	Read();
	Solve();
//	while(1);
	return 0;
}

