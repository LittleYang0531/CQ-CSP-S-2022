#include<bits/stdc++.h>
using namespace std;
long long n, m, q, a[100010], b[100010];
long long l1, r1, l2, r2, ans, minn;
long long max(long long x, long long y) {
	if (x > y)
		return x;
	return y;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &b[i]);
	for (int l = 1; l <= q; l++) {
		ans = -1e18;
		scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		for (int i = l1; i <= r1; i++) {
			minn = 1e18;
			for (int j = l2; j <= r2; j++)
				minn = min(minn, a[i] * b[j]);
			ans = max(ans, minn);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
