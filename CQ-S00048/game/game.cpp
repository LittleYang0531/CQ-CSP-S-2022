#include <cstdio>
#include <cmath>
#define ll long long
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
const int MAXN = 1e5 + 5, INF = 2e9;
int n, m, q, dp[MAXN][10][2][2], dpp[MAXN][10][2][2];
ll mx[2], mi[2], ans = INF;
void MakeRMQ () {
	for (int j = 1; j < 10; j++)
		for (int i = 1; i <= n; i++) {
			dpp[i][j][0][0] = max(dpp[i][j - 1][0][0], dpp[i + (1 << j - 1)][j - 1][0][0]);
			dpp[i][j][0][1] = min(dpp[i][j - 1][0][1], dpp[i + (1 << j - 1)][j - 1][0][1]);
			dp[i][j][0][0] = min(dp[i][j - 1][0][0], dp[i + (1 << j - 1)][j - 1][0][0]);
			dp[i][j][0][1] = max(dp[i][j - 1][0][1], dp[i + (1 << j - 1)][j - 1][0][1]);
		}
	for (int j = 1; j < 10; j++)
		for (int i = 1; i <= m; i++) {
			dpp[i][j][1][0] = max(dpp[i][j - 1][1][0], dpp[i + (1 << j - 1)][j - 1][1][0]);
			dpp[i][j][1][1] = min(dpp[i][j - 1][1][1], dpp[i + (1 << j - 1)][j - 1][1][1]);
			dp[i][j][1][0] = min(dp[i][j - 1][1][0], dp[i + (1 << j - 1)][j - 1][1][0]);
			dp[i][j][1][1] = max(dp[i][j - 1][1][1], dp[i + (1 << j - 1)][j - 1][1][1]);
		}
}
int Get (int l, int r, int t, int opt) {
	int k = log2(r - l + 1);
//	printf("%d %d %d\n", k, dp[l][k][t][0], dp[r - (1 << k) + 1][k][t][0]);
	if (opt == 0) return min(dp[l][k][t][0], dp[r - (1 << k) + 1][k][t][0]);
	if (opt == 1) return max(dp[l][k][t][1], dp[r - (1 << k) + 1][k][t][1]);
}
int GetClose (int l, int r, int t, int opt) {
	int k = log2(r - l + 1);
//	printf("%d %d %d\n", k, dp[l][k][t][0], dp[r - (1 << k) + 1][k][t][0]);
	if (opt == 0) return max(dpp[l][k][t][0], dpp[r - (1 << k) + 1][k][t][0]);
	if (opt == 1) return min(dpp[l][k][t][1], dpp[r - (1 << k) + 1][k][t][1]);
}
int main () {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1, in; i <= n; i++)
		scanf("%d", &in), dp[i][0][0][0] = dp[i][0][0][1] = in, dpp[i][0][0][0] = in <= 0 ? in : -INF, dpp[i][0][0][1] = in >= 0 ? in : INF;
	for (int i = 1, in; i <= m; i++)
		scanf("%d", &in), dp[i][0][1][0] = dp[i][0][1][1] = in, dpp[i][0][1][0] = in <= 0 ? in : -INF, dpp[i][0][1][1] = in >= 0 ? in : INF;
	MakeRMQ();
//	printf("=%d\n", Have0(1, 5, 0));
//	printf("%d", Get(1, 2, 1, 1));
//	printf("%d\n", GetClose(1, 5, 0, 1));
	while (q--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (l1 == r1) {
			if (dp[l1][0][0][0] < 0)
				printf("%lld\n", 1ll * dp[l1][0][0][0] * Get(l2, r2, 1, 1));
			else
				printf("%lld\n", 1ll * dp[l1][0][0][0] * Get(l2, r2, 1, 0));
		} else if (l2 == r2) {
			if (dp[l2][0][1][0] < 0)
				printf("%lld\n", 1ll * dp[l2][0][1][0] * Get(l1, r1, 0, 0));
			else
				printf("%lld\n", 1ll * dp[l2][0][1][0] * Get(l1, r1, 0, 1));
		} else {
			mx[0] = Get(l1, r1, 0, 1), mx[1] = Get(l2, r2, 1, 1);
			mi[0] = Get(l1, r1, 0, 0), mi[1] = Get(l2, r2, 1, 0);
//			printf("%d %d %d %d\n", mi[0], mx[0], mi[1], mx[1]);
			if (mx[0] < 0) {
//				ans = mx[0] * mi[1];
//				continue;
//	printf("1-");
				if (mx[1] > 0) {
//	printf("1-");
					if (mi[1] < 0) {
//	printf("1-");
						ans = mx[0] * mx[1];
						
					} else {
//	printf("2-");
//						if (GetClose(l2, r2, 1, 0) == 0) {
//							puts("0");
//							continue;
//						}
						ans = mx[0] * mx[1];
					}
				} else {
//	printf("2-");
					if (GetClose(l2, r2, 1, 0) == 0) {
						puts("0");
						continue;
					}
					ans = mi[0] * mx[1];
				}
//				ans = mx[0] * mi[1];
			} else {
//	printf("2-");
				if (mi[0] < 0) {
//	printf("1-");
					if (mx[1] > 0) {
//	printf("1-");
						if (mi[1] < 0) {
//	printf("1-");
							ans = max(GetClose(l1, r1, 0, 1) * mi[1], GetClose(l1, r1, 0, 0) * mx[1]);
							
						} else {
//	printf("2-");
							if (GetClose(l2, r2, 1, 0) == 0) {
								puts("0");
								continue;
							}
							ans = mx[0] * mi[1];
						}
					} else {
//	printf("2-");
						if (GetClose(l2, r2, 1, 0) == 0) {
							puts("0");
							continue;
						}
						ans = mi[0] * mx[1];
					}
				} else {
//	printf("2-");
					if (mx[1] > 0) {
//	printf("1-");
						if (mi[1] < 0) {
//	printf("1-");
							if (GetClose(l1, r1, 0, 0) == 0) {
								puts("0");
								continue;
							}
							ans = mi[0] * mi[1];
						} else {  //ÌØÊâÐÔÖÊ1 
//	printf("2-");
							ans = mx[0] * mi[1];
						}
					} else {
//	printf("2-");
						ans = mi[0] * mi[1];
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
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
