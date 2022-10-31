#include<bits/stdc++.h>
using namespace std;
long long n, q, k, a[200010][1010], b[200010], c[200010], l[200010], ans;
long long min(long long x, long long y) {
	if (x < y)
		return x;
	return y;
}
int dfs(long long idx, long long idy, long long tot) {
	if (idx == idy) {
		ans = min(ans, tot);
		return 0;
	}
	for (int i = 1; i <= l[idx]; i++) {
		long long num = a[idx][i];
		if (c[num] == 0) {
			c[num] = 1;
			dfs(num, idy, tot + b[num]);
			c[num] = 0;
		}
	}
	return 0;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &q, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	for (int i = 1; i <= n - 1; i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		a[x][++l[x]] = y;
		a[y][++l[y]] = x;
	}
	for (int i = 1; i <= q; i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		ans = 1e9;
		memset(c, 0, sizeof(c));
		dfs(x, y, 0);
		printf("%lld\n", ans + b[x]);
	}
	return 0;
}
