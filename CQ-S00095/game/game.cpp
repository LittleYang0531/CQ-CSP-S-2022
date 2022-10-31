#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, q, a[MAXN], b[MAXN], Min[MAXN], rmq2[MAXN][20], rmq3[MAXN][20], l1, l2, r1, r2;

long long getrmq2 (int l, int r) {
	int k = log2 (r - l + 1);
	return min (rmq2[l][k], rmq2[r - (1 << k) + 1][k]);
}

long long getrmq3 (int l, int r) {
	int k = log2 (r - l + 1);
	return max (rmq3[l][k], rmq3[r - (1 << k) + 1][k]);
}

int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= m; i ++)
		scanf ("%d", &b[i]), rmq2[i][0] = b[i], rmq3[i][0] = b[i];
	for (int j = 1; (1 << j) <= m; j ++)
		for (int i = 1; i + (1 << j) - 1 <= m; i ++)
			rmq2[i][j] = min (rmq2[i][j - 1], rmq2[i + (1 << j - 1)][j - 1]),
			rmq3[i][j] = max (rmq3[i][j - 1], rmq3[i + (1 << j - 1)][j - 1]);
	while (q --) {
		scanf ("%d %d %d %d", &l1, &r1, &l2, &r2);
		long long pos = 0, f = -inf;
		for (int i = l1; i <= r1; i ++) {
			long long minn = inf;
			for (int j = l2; j <= r2; j ++)
				minn = min ((long long)a[i] * b[j], minn);
			if (minn > f)
				f = minn, pos = i;
		}
		long long ans = (long long)a[pos];
		if (ans < 0)
			ans *= getrmq3 (l2, r2);
		else
			ans *= getrmq2 (l2, r2);
		printf ("%lld\n", ans);
	}
	return 0;
} 
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
