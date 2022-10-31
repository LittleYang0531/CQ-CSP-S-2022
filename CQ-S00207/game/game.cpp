#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5;
long long n, m, q, a[100005], b[100005], f[N][N][15], Logn[N];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &q);
	if (n >= N) {
		for (long long i = 1;i <= n;i++) {
			scanf("%lld", &a[i]);
		}
		for (long long i = 1;i <= m;i++) {
			scanf("%lld", &b[i]);
		}
		long long l1, r1, l2, r2;
		while(q--) {
			scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
			long long ans = LLONG_MIN;
			for (long long i = l1;i <= r1;++i) {
				long long minn = LLONG_MAX;
				for (long long j = l2;j <= r2;++j) {
					minn = min(minn, a[i] * b[j]);
				}
				ans = max(ans, minn);
			}
			printf("%lld\n", ans);
			return 0;
		}
		return 0;
	}
	Logn[2] = 1;
	long long nn = max(n, m);
	for (long long i = 3;i <= nn;i++) {
		Logn[i] = Logn[i >> 1] + 1;
	} 
	for (long long i = 1;i <= n;i++) {
		scanf("%lld", &a[i]);
	}
	for (long long i = 1;i <= m;i++) {
		scanf("%lld", &b[i]);
	}
	for (long long k = 1;k <= n;k++) {
		for (long long i = 1;i <= m;i++) {
			f[k][i][0] = a[k] * b[i];
		}
		for (long long j = 1;j <= Logn[m];j++) {
			for (long long i = 1;i + (1 << j) - 1 <= m;i++) {
				f[k][i][j] = min(f[k][i][j - 1], f[k][i + (1 << j - 1)][j - 1]);
			}
		}
	}
	long long l1, r1, l2, r2;
	while(q--) {
		scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		long long ans = LLONG_MIN;
		for (long long i = l1;i <= r1;i++) {
			long long lala = Logn[r2 - l2 + 1];
			ans = max(ans, min(f[i][l2][lala], f[i][r2 - (1 << lala) + 1][lala]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
