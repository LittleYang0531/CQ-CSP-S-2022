// % dottle

#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, q, sum[3][N];
ll a[N], b[N];

int lg2[N];
ll mx[2][N][20], mn[2][N][20], mxx[N][20], mnx[N][20];
void init(int n, int m) {
	for (int i = 2; i <= max(n, m); i++) lg2[i] = lg2[i >> 1] + 1;
	for (int j = 1; j < 18; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			mx[0][i][j] = max(mx[0][i][j - 1], mx[0][i + (1 << j - 1)][j - 1]);
			mn[0][i][j] = min(mn[0][i][j - 1], mn[0][i + (1 << j - 1)][j - 1]);
			mxx[i][j] = max(mxx[i][j - 1], mxx[i + (1 << j - 1)][j - 1]);
			mnx[i][j] = min(mnx[i][j - 1], mnx[i + (1 << j - 1)][j - 1]);
		}
	for (int j = 1; j < 18; j++)
		for (int i = 1; i + (1 << j) - 1 <= m; i++) mx[1][i][j] = max(mx[1][i][j - 1], mx[1][i + (1 << j - 1)][j - 1]), mn[1][i][j] = min(mn[1][i][j - 1], mn[1][i + (1 << j - 1)][j - 1]);
}
ll query(int l, int r, int t1, int t2, int fl) {
	int k = lg2[r - l + 1];
	if (fl) {
		if (!t2) return max(mxx[l][k], mxx[r - (1 << k) + 1][k]);
		return min(mnx[l][k], mnx[r - (1 << k) + 1][k]);
	}
	if (!t2) return max(mx[t1][l][k], mx[t1][r - (1 << k) + 1][k]);
	return min(mn[t1][l][k], mn[t1][r - (1 << k) + 1][k]);
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), mx[0][i][0] = mn[0][i][0] = a[i];
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]), mx[1][i][0] = mn[1][i][0] = b[i];
	for (int i = 1; i <= n; i++) {
		sum[0][i] = sum[0][i - 1] + (!a[i]);
		sum[1][i] = sum[1][i - 1] + (a[i] > 0);
		sum[2][i] = sum[2][i - 1] + (a[i] < 0);
		if (a[i] < 0) mxx[i][0] = a[i];
		else mxx[i][0] = -1e18;
		if (a[i] > 0) mnx[i][0] = a[i];
		else mnx[i][0] = 1e18;
	}
	init(n, m);
	while (q--) {
		int l1, r1, l2, r2;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		ll mx0 = query(l1, r1, 0, 0, 0), mn0 = query(l1, r1, 0, 1, 0), mx1 = query(l2, r2, 1, 0, 0), mn1 = query(l2, r2, 1, 1, 0), mnsc1 = -1e18, mnsc2 = -1e18, mnsc3 = -1e18;
		if (sum[2][r1] > sum[2][l1 - 1]) {
			if (mx1 < 0) mnsc1 = mn0 * mx1;
			if (!mx1) mnsc1 = 0;
			if (mx1 > 0) mnsc1 = query(l1, r1, 0, 0, 1) * mx1;
		}
		if (sum[1][r1] > sum[1][l1 - 1]) {
			if (mn1 < 0) mnsc2 = query(l1, r1, 0, 1, 1) * mn1;
			if (!mn1) mnsc2 = 0;
			if (mn1 > 0) mnsc2 = mx0 * mn1;
		}
		if (sum[0][r1] > sum[0][l1 - 1]) mnsc3 = 0;
		printf("%lld\n", max(max(mnsc1, mnsc2), mnsc3));
	}
	return 0;
}
