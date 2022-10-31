#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 1e5 + 5;
inline ll read() {
	ll sum = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' or ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar(); 
	}
	while(ch >= '0' and ch <= '9') {
		sum = sum * 10 + ch - '0';
		ch = getchar();
	}
	return sum * f;
}
ll maxn[Maxn][20][2], minn[Maxn][20][2]; // 0 是 a 
int n, m, q;
int geta(int x, int y, bool f, bool c) { // f=1最大值 c=1在a 
	int k = log2(y - x + 1);
	if(f) {
		if(c) return max(maxn[x][k][0], maxn[y - (1 << k) + 1][k][0]);
		else return max(maxn[x][k][1], maxn[y - (1 << k) + 1][k][1]);
	}
	else {
		if(c) return min(minn[x][k][0], minn[y - (1 << k) + 1][k][0]);
		else return min(minn[x][k][1], minn[y - (1 << k) + 1][k][1]);
	}
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout); 
	n = read(), m = read(), q = read();
	for(int i = 1;i <= n; ++i) maxn[i][0][0] = minn[i][0][0] = read(); 
	for(int i = 1;i <= m; ++i) maxn[i][0][1] = minn[i][0][1] = read(); 
	for(int j = 1;(1 << j) <= n; ++j)
		for(int i = 1;i + (1 << j) - 1 <= n; ++i)
			maxn[i][j][0] = max(maxn[i][j - 1][0], maxn[i + (1 << (j - 1))][j - 1][0]),
			maxn[i][j][1] = max(maxn[i][j - 1][1], maxn[i + (1 << (j - 1))][j - 1][1]),
			minn[i][j][0] = min(minn[i][j - 1][0], minn[i + (1 << (j - 1))][j - 1][0]),
			minn[i][j][1] = min(minn[i][j - 1][1], minn[i + (1 << (j - 1))][j - 1][1]);
	for(int k = 1;k <= q; ++k) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		ll ans;
		if(n * q <= 2e7) {
			ans = -1e18;
			for(int i = l1;i <= r1; ++i)
			ans = max(ans, min(maxn[i][0][0] * geta(l2, r2, 1, 0), maxn[i][0][0] * geta(l2, r2, 0, 0)));
			printf("%lld\n", ans);
		}
		else if(l1 == r1) {
			ans = min(maxn[l1][0][0] * geta(l2, r2, 1, 0), maxn[l1][0][0] * geta(l2, r2, 0, 0));
			printf("%lld\n", ans);
		}
		else if(l2 == r2) {
			ans = max(maxn[l2][0][1] * geta(l1, r1, 1, 1), maxn[l2][0][1] * geta(l1, r1, 0, 1));
			printf("%lld\n", ans);
		}
		else {
			ans = -1e18;
			for(int i = l1;i <= r1; ++i)
			ans = max(ans, min(maxn[i][0][0] * geta(l2, r2, 1, 0), maxn[i][0][0] * geta(l2, r2, 0, 0)));
			printf("%lld\n", ans);
		}
	}
	return 0;
}
// 1.a正大 b最小
// 2.a正小 b最小
// 3.a负大 b正大/负小 
// 还有1小时，先打60+15分 
// 性质2:15
//  1~12:60 
// 
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
