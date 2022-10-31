#include <cstdio>
#include <algorithm>
#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n, m, q;
long long a[MAXN], b[MAXN];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
	}
	for (int i = 1; i <= q; i++) {
		int l1, r1, l2, r2;
		long long ans = -INF;
		long long ans1 = INF, ans2 = INF, ans3 = -INF, ans4 = -INF;
		long long tot1 = INF, tot2 = INF, tot3 = -INF, tot4 = -INF;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		
		for (int x = l1; x <= r1; x++) {
			if (a[x] >= 0) ans1 = min(ans1, a[x]);
			else ans2 = min(ans2, a[x]);
			if (a[x] >= 0) ans3 = max(ans3, a[x]);
			else ans4 = max(ans4, a[x]);
		}
		
		for (int y = l2; y <= r2; y++) {
			if (b[y] >= 0) tot1 = min(tot1, b[y]);
			else tot2 = min(tot2, b[y]);
			if (b[y] >= 0) tot3 = max(tot3, b[y]);
			else tot4 = max(tot4, b[y]);
		}
		
//		printf("%d %d %d %d\n%d %d %d %d\n", ans1, ans2, ans3, ans4, tot1, tot2, tot3, tot4);
		
		if (ans1 != INF) {
			if (tot2 != INF) {
				ans = max(ans, ans1 * tot2);
//				printf("%d\n", ans1 * tot2);
			} else {
				ans = max(ans, ans1 * tot1);
//				printf("%d\n", ans1 * tot1);
			}
		}
		if (ans2 != INF) {
			if (tot3 != -INF) {
				ans = max(ans, ans2 * tot3);
//				printf("%d\n", ans2 * tot3);
			} else {
				ans = max(ans, ans2 * tot4);
//				printf("%d\n", ans2 * tot4);
			}
		}
		if (ans3 != -INF) {
			if (tot2 != INF) {
				ans = max(ans, ans3 * tot2);
//				printf("%d\n", ans3 * tot2);
			} else {
				ans = max(ans, ans3 * tot1);
//				printf("%d\n", ans3 * tot1);
			}
		}
		if (ans4 != -INF) {
			if (tot3 != -INF) {
				ans = max(ans, ans4 * tot3);
//				printf("%d\n", ans4 * tot3);
			} else {
				ans = max(ans, ans4 * tot4);
//				printf("%d\n", ans4 * tot4);
			}
		}
		
		
		printf("%lld\n", ans);
	}
	return 0;
}
