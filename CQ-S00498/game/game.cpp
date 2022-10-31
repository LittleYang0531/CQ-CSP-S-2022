#include <cstdio>
#include <algorithm> 
using namespace std;
#define int long long
const int N = 1010, M = 30;
void read(int &x) {
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') f |= c == '-', c = getchar();
	x = 0;
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	x = f ? -x : x;
}

int n, m, q;
int a[N], b[N], c[N][N], dp[N][N][M];
int l1, r1, l2, r2;

void RMQ() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[i][j][0] = c[i][j];
	for (int k = 1; k <= n; k++) {
		for (int j = 1; (1 << j) <= m; j++) {
			for (int i = 1; i + (1 << j) - 1 <= m; i++) {
				dp[k][i][j] = min(dp[k][i][j - 1], dp[k][i + (1 << j - 1)][j - 1]);
			}
		}
	}	
}

signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= m; i++) read(b[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = a[i] * b[j];
//			printf("%d ", c[i][j]);
		}
//		puts("");
	}
	RMQ();
	while (q--) {
		scanf("%lld %lld %lld %lld", &l1, &r1, &l2, &r2);
		int sum[N], stp = 0;
		for (int i = l1; i <= r1; i++)  {
			if (l2 == r2) {
				sum[++stp] = c[i][l2];
			} else {
				int k = log2(r2 - l2 + 1);
				int t = min(dp[i][l2][(1 << k - 1)], dp[i][r2 - (1 << k - 1)][(1 << k - 1)]);
				sum[++stp] = t;
			}
		}
		int Max = sum[1];
		for (int i = 2; i <= stp; i++) {
			Max = max(Max, sum[i]);
		}
		printf("%lld\n", Max);
	}
	
	return 0;
}




