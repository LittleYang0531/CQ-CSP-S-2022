#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1005, inf = 0x3f3f3f3f;
long long n, m, q, a[MAXN], b[MAXN];
long long maxza[MAXN][MAXN], maxzb[MAXN][MAXN], minza[MAXN][MAXN], minzb[MAXN][MAXN], minfa[MAXN][MAXN], minfb[MAXN][MAXN], maxfa[MAXN][MAXN], maxfb[MAXN][MAXN];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &b[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j <= n; j++) {
			maxza[i][j] = -0x3f3f3f3f;
			maxfa[i][j] = -0x3f3f3f3f;
			minza[i][j] = 0x3f3f3f3f;
			minfa[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i - 1; j <= m; j++) {
			maxzb[i][j] = -0x3f3f3f3f;
			maxfb[i][j] = -0x3f3f3f3f;
			minzb[i][j] = 0x3f3f3f3f;
			minfb[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[j] >= 0) {
				maxza[i][j] = max(maxza[i][j-1], a[j]);
				minza[i][j] = min(minza[i][j-1], a[j]);
			} else {
				maxfa[i][j] = max(maxfa[i][j-1], a[j]);
				minfa[i][j] = min(minfa[i][j-1], a[j]);
			}
			maxza[i][j] = max(maxza[i][j], maxza[i][j-1]);
			maxfa[i][j] = max(maxfa[i][j], maxfa[i][j-1]);
			minza[i][j] = min(minza[i][j], minza[i][j-1]);
			minfa[i][j] = min(minfa[i][j], minfa[i][j-1]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			if (b[j] >= 0) {
				maxzb[i][j] = max(maxzb[i][j-1], b[j]);
				minzb[i][j] = min(minzb[i][j-1], b[j]);
			} else {
				maxfb[i][j] = max(maxfb[i][j-1], b[j]);
				minfb[i][j] = min(minfb[i][j-1], b[j]);
			}
			maxzb[i][j] = max(maxzb[i][j], maxzb[i][j-1]);
			maxfb[i][j] = max(maxfb[i][j], maxfb[i][j-1]);
			minzb[i][j] = min(minzb[i][j], minzb[i][j-1]);
			minfb[i][j] = min(minfb[i][j], minfb[i][j-1]);
//			if (i == 2) printf("\n%d\n", maxzb[2][2]);
		}
	}
//	printf("\n%d\n", maxzb[2][2]);
//	for (int i = 1; i <= n; i++) {
//		printf("\n");
//		for (int j = i; j <= n; j++) printf("%d---%d---%d---%d ", maxza[i][j], maxfa[i][j], minza[i][j], minfa[i][j]);
//	}
//printf("%d\n", maxfb[2][2]);
	for (int i = 1; i <= q; i++) {
		long long l1, r1, l2, r2;
		scanf("%lld %lld %lld %lld", &l1, &r1, &l2, &r2);
//		printf("\n%d***%d***%d***%d\n", maxzb[l2][r2], maxfb[l2][r2], minzb[l2][r2], minfb[l2][r2]);
		if (minza[l1][r1] != inf && maxfa[l1][r1] != -inf && minzb[l2][r2] != inf && maxfb[l2][r2] != -inf)
			printf("%lld\n", max(maxfa[l1][r1] * maxzb[l2][r2], minza[l1][r1] * minfb[l2][r2]));
		else if (maxza[l1][r1] == -inf && minfa[l1][r1] != inf) {
			if (maxzb[l2][r2] == -inf) printf("%lld\n", minfa[l1][r1] * maxfb[l2][r2]);
			else printf("%lld\n", maxfa[l1][r1] * maxzb[l2][r2]);
		} else if (minfa[l1][r1] == inf && maxza[l1][r1] != -inf) {
			if (minfb[l2][r2] == inf) printf("%lld\n", maxza[l1][r1] * minzb[l2][r2]);
			else printf("%lld\n", minza[l1][r1] * minfb[l2][r2]);
		} else {
			if (minzb[l2][r2] == inf) printf("%lld\n", minfa[l1][r1] * maxfb[l2][r2]);
			else printf("%lld\n", maxza[l1][r1] * minzb[l2][r2]);
		}
	}
	return 0;
}
