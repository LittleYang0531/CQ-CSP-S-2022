#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define LL long long
int n, m, q, l1, l2, r1, r2, a[MAXN+5], b[MAXN+5];
int cnta[MAXN+5][2], cntb[MAXN+5][2], dpa[MAXN+5][30][2][2], dpb[MAXN+5][30][2][2];
int querya(int x, int y, int l, int r) {
	int k = (int)log2(r - l + 1);
	if (y) return max(dpa[l][k][x][1], dpa[r - (1 << k) + 1][k][x][1]);
	else return min(dpa[l][k][x][0], dpa[r - (1 << k) + 1][k][x][0]);
}
int queryb(int x, int y, int l, int r) {
	int k = (int)log2(r - l + 1);
	if (y) return max(dpb[l][k][x][1], dpb[r - (1 << k) + 1][k][x][1]);
	else return min(dpb[l][k][x][0], dpb[r - (1 << k) + 1][k][x][0]);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		dpa[i][0][0][0] = ((a[i] <= 0) ? a[i] : INT_MAX);
		dpa[i][0][0][1] = ((a[i] <= 0) ? a[i] : INT_MIN);
		dpa[i][0][1][0] = ((a[i] >= 0) ? a[i] : INT_MAX);
		dpa[i][0][1][1] = ((a[i] >= 0) ? a[i] : INT_MIN);
		cnta[i][0] = cnta[i - 1][0] + (a[i] < 0);
		cnta[i][1] = cnta[i - 1][1] + (a[i] > 0);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		dpb[i][0][0][0] = ((b[i] <= 0) ? b[i] : INT_MAX);
		dpb[i][0][0][1] = ((b[i] <= 0) ? b[i] : INT_MIN);
		dpb[i][0][1][0] = ((b[i] >= 0) ? b[i] : INT_MAX);
		dpb[i][0][1][1] = ((b[i] >= 0) ? b[i] : INT_MIN);
		cntb[i][0] = cntb[i - 1][0] + (b[i] < 0);
		cntb[i][1] = cntb[i - 1][1] + (b[i] > 0);
	}
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			dpa[i][j][0][0] = min(dpa[i][j - 1][0][0], dpa[i + (1 << j - 1)][j - 1][0][0]);
			dpa[i][j][0][1] = max(dpa[i][j - 1][0][1], dpa[i + (1 << j - 1)][j - 1][0][1]);
			dpa[i][j][1][0] = min(dpa[i][j - 1][1][0], dpa[i + (1 << j - 1)][j - 1][1][0]);
			dpa[i][j][1][1] = max(dpa[i][j - 1][1][1], dpa[i + (1 << j - 1)][j - 1][1][1]);
		}
	}
	for (int j = 1; (1 << j) <= m; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
			dpb[i][j][0][0] = min(dpb[i][j - 1][0][0], dpb[i + (1 << j - 1)][j - 1][0][0]);
			dpb[i][j][0][1] = max(dpb[i][j - 1][0][1], dpb[i + (1 << j - 1)][j - 1][0][1]);
			dpb[i][j][1][0] = min(dpb[i][j - 1][1][0], dpb[i + (1 << j - 1)][j - 1][1][0]);
			dpb[i][j][1][1] = max(dpb[i][j - 1][1][1], dpb[i + (1 << j - 1)][j - 1][1][1]);
		}
	}
	while (q--) {
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int tpa = cnta[r1][1] - cnta[l1 - 1][1], tpb = cntb[r2][1] - cntb[l2 - 1][1];
		int tia = cnta[r1][0] - cnta[l1 - 1][0], tib = cntb[r2][0] - cntb[l2 - 1][0];
		if (!tpa) {
			if (!tpb) {
				printf("%lld\n", 1ll * querya(0, 0, l1, r1) * queryb(0, 1, l2, r2));
			} else {
				printf("%lld\n", 1ll * querya(0, 1, l1, r1) * queryb(1, 1, l2, r2));
			}
		} else {
			if (!tia) {
				if (!tpb) {
					printf("%lld\n", 1ll * querya(1, 0, l1, r1) * queryb(0, 0, l2, r2));
				} else {
					if (!tib) {
						printf("%lld\n", 1ll * querya(1, 1, l1, r1) * queryb(1, 0, l2, r2));
					} else {
						printf("%lld\n", 1ll * querya(1, 0, l1, r1) * queryb(0, 0, l2, r2));
					}
				}
			} else {
				if (!tpb) {
					printf("%lld\n", 1ll * querya(0, 0, l1, r1) * queryb(0, 1, l2, r2));
				} else {
					if (!tib) {
						printf("%lld\n", 1ll * querya(1, 1, l1, r1) * queryb(1, 0, l2, r2));
					} else {
						printf("%lld\n", max(1ll * querya(1, 0, l1, r1) * queryb(0, 0, l2, r2), 1ll * querya(0, 1, l1, r1) * queryb(1, 1, l2, r2)));
					}
				}
			}
		}
	}
	return 0;
}
