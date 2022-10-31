#include <cstdio>
#include <algorithm>
#define LL long long

inline void read1(int &t) {
	t = 0; char ch = getchar(); int a = 1;
	while (ch < 48 || ch > 57) { if (ch == '-') a = -1; ch = getchar(); }
	while (ch >= 48 && ch <= 57) { t = (t << 1) + (t << 3) + (ch ^ 48); ch = getchar(); }
	t *= a;
}

inline void read2(LL &t) {
	t = 0; char ch = getchar(); LL a = 1;
	while (ch < 48 || ch > 57) { if (ch == '-') a = -1; ch = getchar(); }
	while (ch >= 48 && ch <= 57) { t = (t << 1) + (t << 3) + (ch ^ 48); ch = getchar(); }
	t *= a;
}

inline void write(LL t) {
	if (t < 0) { putchar('-'); t *= -1; }
	if (t >= 10) write(t / 10);
	putchar(t % 10 + 48);
}

using namespace std;

const int N = 1e5 + 5, P = 35;

int n, m, q, log1[N], l1, r1, l2, r2;
LL a, st1[N][P][5], st2[N][P][5], ans; // 0负数最小 1负数最大 2正数最小 3正数最大

inline LL get_min1(int l, int r, int s) {
	int k = log1[r - l + 1];
	return min(st1[l][k][s], st1[r - (1 << k) + 1][k][s]);
}

inline LL get_max1(int l, int r, int s) {
	int k = log1[r - l + 1];
	return max(st1[l][k][s], st1[r - (1 << k) + 1][k][s]);
}

inline LL get_min2(int l, int r, int s) {
	int k = log1[r - l + 1];
	return min(st2[l][k][s], st2[r - (1 << k) + 1][k][s]);
}

inline LL get_max2(int l, int r, int s) {
	int k = log1[r - l + 1];
	return max(st2[l][k][s], st2[r - (1 << k) + 1][k][s]);
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read1(n), read1(m), read1(q);
	for (int i = 1; i <= n; i++) {
		read2(a);
		if (a > 0)
			st1[i][0][0] = 2e9, st1[i][0][1] = -2e9, st1[i][0][2] = st1[i][0][3] = a;
		else
			st1[i][0][0] = st1[i][0][1] = a, st1[i][0][2] = 2e9, st1[i][0][3] = -2e9;
	}
	for (int i = 1; i <= m; i++) {
		read2(a);
		if (a > 0)
			st2[i][0][0] = 2e9, st2[i][0][1] = -2e9, st2[i][0][2] = st2[i][0][3] = a;
		else
			st2[i][0][0] = st2[i][0][1] = a, st2[i][0][2] = 2e9, st2[i][0][3] = -2e9;
	}
	for (int i = 2; i <= max(n, m); i++)
		log1[i] = log1[i >> 1] + 1;
	for (int j = 1; j <= log1[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st1[i][j][0] = min(st1[i][j - 1][0], st1[i + (1 << j - 1)][j - 1][0]);
			st1[i][j][1] = max(st1[i][j - 1][1], st1[i + (1 << j - 1)][j - 1][1]);
			st1[i][j][2] = min(st1[i][j - 1][2], st1[i + (1 << j - 1)][j - 1][2]);
			st1[i][j][3] = max(st1[i][j - 1][3], st1[i + (1 << j - 1)][j - 1][3]);
		}
	for (int j = 1; j <= log1[m]; j++)
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			st2[i][j][0] = min(st2[i][j - 1][0], st2[i + (1 << j - 1)][j - 1][0]);
			st2[i][j][1] = max(st2[i][j - 1][1], st2[i + (1 << j - 1)][j - 1][1]);
			st2[i][j][2] = min(st2[i][j - 1][2], st2[i + (1 << j - 1)][j - 1][2]);
			st2[i][j][3] = max(st2[i][j - 1][3], st2[i + (1 << j - 1)][j - 1][3]);
		}
	while (q--) {
		read1(l1), read1(r1), read1(l2), read1(r2);
		LL a1 = get_min1(l1, r1, 0), a2 = get_max1(l1, r1, 1), a3 = get_min1(l1, r1, 2), a4 = get_max1(l1, r1, 3);
		LL b1 = get_min2(l2, r2, 0), b2 = get_max2(l2, r2, 1), b3 = get_min2(l2, r2, 2), b4 = get_max2(l2, r2, 3);
		if (a1 <= 0ll && a4 >= 0ll) {
			if (b1 <= 0ll && b4 >= 0ll)
				ans = max(a2 * b4, a3 * b1);
			else if (b1 <= 0ll)
				ans = a1 * b2;
			else
				ans = a4 * b3;
		} else if (a1 <= 0ll) {
			if (b1 <= 0ll && b4 >= 0ll)
				ans = a2 * b4;
			else if (b1 <= 0ll)
				ans = a1 * b2;
			else
				ans = a2 * b4;
		} else {
			if (b1 <= 0ll && b4 >= 0ll)
				ans = a3 * b1;
			else if (b1 <= 0)
				ans = a3 * b1;
			else
				ans = a4 * b3;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
