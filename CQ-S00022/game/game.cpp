#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 5;
int n, m, q, l1, r1, l2, r2, a[MAXN], b[MAXN], aMi[MAXN][MAXN], bMi[MAXN][MAXN], aMa[MAXN][MAXN], bMa[MAXN][MAXN];
int f1, f2;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= 0)
			f1 = 1;
	}
	for (int i = 1; i <= n; i++) {
		int Ma = -0x3f3f3f3f, Mi = 0x3f3f3f3f;
		for (int j = 1; j <= i; j++) {
			Ma = max(Ma, a[j]);
			Mi = min(Mi, a[j]);
			aMa[j][i] = Ma;
			aMi[j][i] = Mi;
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		if (b[i] <= 0)
			f1 = 1;
	}
	for (int i = 1; i <= n; i++) {
		int Ma = -0x3f3f3f3f, Mi = 0x3f3f3f3f;
		for (int j = 1; j <= i; j++) {
			Ma = max(Ma, b[j]);
			Mi = min(Mi, b[j]);
			bMa[j][i] = Ma;
			bMi[j][i] = Mi;
		}
	}
	if (f1 == 1) {
		while (q--) {
			scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
			printf("%lld\n", max((long long) aMa[l1][r1] * bMi[l2][r2], (long long) aMi[l1][r1] * bMi[l2][r2]));
		} 
		return 0;
	}
	while (q--) {
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		long long ans = -1e18;
		for (int i = l1; i <= r1; i++) {
			long long sum = 1e18;
			for (int j = l2; j <= r2; j++) {
				sum = min((long long) a[i] * b[j], sum);
			}
			ans = max(sum, ans);
		}
		printf("%lld\n", ans);
	}
	
	return 0; 
} 

