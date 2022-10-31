#include <cstdio>
#include <cmath>
const long long inf = 1e9 + 1;
const int MAXN = 1e5 + 5, Log2_MAXN = 16 + 5;
long long maxna[2][MAXN][Log2_MAXN], minna[2][MAXN][Log2_MAXN], maxnb[MAXN][Log2_MAXN], minnb[MAXN][Log2_MAXN];
int n, m;

long long Max(long long x, long long y) {
	return x > y ? x : y;
}

long long Min(long long x, long long y) {
	return x < y ? x : y;
}

long long Abs(long long x, long long y) {
	return x < 0 ? -x : x;
}

long long fMax(long long dp[][Log2_MAXN], int l, int r) {
	int t = log2(r - l + 1);
	return Max(dp[l][t], dp[r - (1 << t) + 1][t]);
}

long long fMin(long long dp[][Log2_MAXN], int l, int r) {
	int t = log2(r - l + 1);
	return Min(dp[l][t], dp[r - (1 << t) + 1][t]);
}

long long read() {
	long long x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return f ? -x : x;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int T, t, l1, r1, l2, r2, a;
	scanf("%d %d %d", &n, &m, &T);
	for (int i = 1; i <= n; i++) {
		a = read();
		if (a < 0) {
			maxna[0][i][0] = minna[0][i][0] = a;
			maxna[1][i][0] = -inf, minna[1][i][0] = inf;
		} else {
			maxna[1][i][0] = minna[1][i][0] = a;
			maxna[0][i][0] = -inf, minna[0][i][0] = inf;
		}
	}
	t = log2(n);
	for (int j = 1; j <= t; j++)
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			maxna[0][i][j] = Max(maxna[0][i][j - 1], maxna[0][i + (1 << j - 1)][j - 1]);
			minna[0][i][j] = Min(minna[0][i][j - 1], minna[0][i + (1 << j - 1)][j - 1]);
			maxna[1][i][j] = Max(maxna[1][i][j - 1], maxna[1][i + (1 << j - 1)][j - 1]);
			minna[1][i][j] = Min(minna[1][i][j - 1], minna[1][i + (1 << j - 1)][j - 1]);
		}
	for (int i = 1; i <= m; i++)
		maxnb[i][0] = minnb[i][0] = read();
	t = log2(m);
	for (int j = 1; j <= t; j++)
		for (int i = 1; i <= m - (1 << j) + 1; i++) {
			maxnb[i][j] = Max(maxnb[i][j - 1], maxnb[i + (1 << j - 1)][j - 1]);
			minnb[i][j] = Min(minnb[i][j - 1], minnb[i + (1 << j - 1)][j - 1]);
		}
	while (T--) {
		l1 = read(), r1 = read(), l2 = read(), r2 = read();
		if (fMin(minnb, l2, r2) >= 0) {
			if (fMax(maxna[1], l1, r1) != -inf)
				printf("%lld\n", 1ll * fMax(maxna[1], l1, r1) * fMin(minnb, l2, r2));
			else
				printf("%lld\n", 1ll * fMax(maxna[0], l1, r1) * fMax(maxnb, l2, r2));
		} else if (fMax(maxnb, l2, r2) <= 0) {
			if (fMin(minna[0], l1, r1) != inf)
				printf("%lld\n", 1ll * fMin(minna[0], l1, r1) * fMax(maxnb, l2, r2));
			else
				printf("%lld\n", 1ll * fMin(minna[1], l1, r1) * fMin(minnb, l2, r2));
		} else {
			long long ans1 = (-1ll) * inf * inf, ans2 = (-1ll) * inf * inf;
			if (fMax(maxna[0], l1, r1) != -inf)
				ans1 = 1ll * fMax(maxna[0], l1, r1) * fMax(maxnb, l2, r2);
			if (fMin(minna[1], l1, r1) != inf)
				ans2 = 1ll * fMin(minna[1], l1, r1) * fMin(minnb, l2, r2);
			printf("%lld\n", ans1 > ans2 ? ans1 : ans2);
		}
	}
	return 0;
}

