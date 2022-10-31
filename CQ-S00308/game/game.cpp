#include <bits/stdc++.h>


using namespace std;


int n, m, q, l1, r1, l2, r2;
int a[100003], b[100003];
int ST_min[19][100003], ST_max[19][100003];
int ST_leq_min[19][100003], ST_leq_max[19][100003], ST_geq_min[19][100003], ST_geq_max[19][100003];


int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++ i) scanf("%d", &b[i]);
	memset(ST_min, 0x3f, sizeof ST_min);
	memset(ST_max, -0x3f, sizeof ST_max);
	memset(ST_leq_min, 0x3f, sizeof ST_leq_min);
	memset(ST_leq_max, -0x3f, sizeof ST_leq_max);
	memset(ST_geq_min, 0x3f, sizeof ST_geq_min);
	memset(ST_geq_max, -0x3f, sizeof ST_geq_max);
	for (int i = 1; i <= n; ++ i) {
		if (a[i] >= 0) ST_geq_min[0][i] = ST_geq_max[0][i] = a[i];
		else ST_leq_min[0][i] = ST_leq_max[0][i] = a[i];
	}
	for (int i = 1; i <= m; ++ i) ST_min[0][i] = ST_max[0][i] = b[i];
	for (int i = 1; i <= log2(m) + 1; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			ST_min[i][j] = min(ST_min[i - 1][j], ST_min[i - 1][j + (1 << (i - 1))]);
			ST_max[i][j] = max(ST_max[i - 1][j], ST_max[i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 1; i <= log2(n) + 1; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			ST_geq_min[i][j] = min(ST_geq_min[i - 1][j], ST_geq_min[i - 1][j + (1 << (i - 1))]);
			ST_geq_max[i][j] = max(ST_geq_max[i - 1][j], ST_geq_max[i - 1][j + (1 << (i - 1))]);
			ST_leq_min[i][j] = min(ST_leq_min[i - 1][j], ST_leq_min[i - 1][j + (1 << (i - 1))]);
			ST_leq_max[i][j] = max(ST_leq_max[i - 1][j], ST_leq_max[i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 1; i <= q; ++ i) {
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		const int s2 = log2(r2 - l2 + 1), s1 = log2(r1 - l1 + 1);
		const int minv = min(ST_min[s2][l2], ST_min[s2][r2 - (1 << s2) + 1]), maxv = max(ST_max[s2][l2], ST_max[s2][r2 - (1 << s2) + 1]);
		const int leq_minv = min(ST_leq_min[s1][l1], ST_leq_min[s1][r1 - (1 << s1) + 1]), leq_maxv = max(ST_leq_max[s1][l1], ST_leq_max[s1][r1 - (1 << s1) + 1]);
		const int geq_minv = min(ST_geq_min[s1][l1], ST_geq_min[s1][r1 - (1 << s1) + 1]), geq_maxv = max(ST_geq_max[s1][l1], ST_geq_max[s1][r1 - (1 << s1) + 1]);
		long long ans = -0x3f3f3f3f3f3f3f3f;
		if (minv >= 0) {
			if (geq_maxv != -1044266559) ans = max(ans, (long long)(minv) * geq_maxv);
		} else if (geq_minv != 0x3f3f3f3f) ans = max(ans, (long long)(minv) * geq_minv);
		if (maxv >= 0) {
			if (leq_maxv != -1044266559) ans = max(ans, (long long)(maxv) * leq_maxv);
		} else if (leq_minv != 0x3f3f3f3f) ans = max(ans, (long long)(maxv) * leq_minv);
		printf("%lld\n", ans);
	}
	return 0;
}
