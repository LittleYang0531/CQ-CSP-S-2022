#include <bits/stdc++.h>
#define int long long
#define inf 2000000000
using namespace std;

void read(int& num) {
	num = 0;
	int g = 1;
	char x = getchar();
	while (x < '0' || x > '9') g = (x == '-' ? -1 : g), x = getchar();
	while (x >= '0' && x <= '9') num = (num << 1) + (num << 3) + (x ^ 48), x = getchar();
	num *= g;
}
void write(int num) {
	if (num < 0) {
		putchar('-');
		write(-num);
		return;
	}
	if (num > 9) write(num / 10);
	putchar(num % 10 + 48);
}

int n, m, q, Log[100005], aRMQ[5][100005][20], bRMQ[3][100005][20], l1, r1, l2, r2, Bmax, Bmin, ans;
// 1: 正min, 2: 正max, 3: 负min, 4: 负max 

void GetLog() {
	for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
}
int Geta(int ty, int l, int r) {
	int t = Log[r - l + 1];
	return (ty & 1) ? min(aRMQ[ty][l][t], aRMQ[ty][r - (1 << t) + 1][t]) : max(aRMQ[ty][l][t], aRMQ[ty][r - (1 << t) + 1][t]);
}
int Getb(int ty, int l, int r) {
	int t = Log[r - l + 1];
	return (ty & 1) ? min(bRMQ[ty][l][t], bRMQ[ty][r - (1 << t) + 1][t]) : max(bRMQ[ty][l][t], bRMQ[ty][r - (1 << t) + 1][t]);
}

signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	GetLog();
	for (int i = 1, u; i <= n; i++) {
		read(u);
		if (u >= 0) aRMQ[1][i][0] = aRMQ[2][i][0] = u;
		else aRMQ[1][i][0] = inf, aRMQ[2][i][0] = -inf;
		if (u <= 0) aRMQ[3][i][0] = aRMQ[4][i][0] = u;
		else aRMQ[3][i][0] = inf, aRMQ[4][i][0] = -inf;
	}
	for (int j = 1; j <= Log[n]; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			aRMQ[1][i][j] = min(aRMQ[1][i][j - 1], aRMQ[1][i + (1 << j - 1)][j - 1]);
			aRMQ[2][i][j] = max(aRMQ[2][i][j - 1], aRMQ[2][i + (1 << j - 1)][j - 1]);
			aRMQ[3][i][j] = min(aRMQ[3][i][j - 1], aRMQ[3][i + (1 << j - 1)][j - 1]);
			aRMQ[4][i][j] = max(aRMQ[4][i][j - 1], aRMQ[4][i + (1 << j - 1)][j - 1]);
		}
	}
	for (int i = 1, u; i <= m; i++) {
		read(u);
		bRMQ[1][i][0] = bRMQ[2][i][0] = u;
	}
	for (int j = 1; j <= Log[m]; j++) {
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			bRMQ[1][i][j] = min(bRMQ[1][i][j - 1], bRMQ[1][i + (1 << j - 1)][j - 1]);
			bRMQ[2][i][j] = max(bRMQ[2][i][j - 1], bRMQ[2][i + (1 << j - 1)][j - 1]);
		}
	}
	while (q--) {
		ans = LONG_LONG_MIN;
		read(l1), read(r1), read(l2), read(r2);
		Bmax = Getb(2, l2, r2);
		Bmin = Getb(1, l2, r2);
		if (Bmax > 0 && Geta(4, l1, r1) != -inf) ans = max(ans, Geta(4, l1, r1) * Bmax);
		else if (Bmax <= 0 && Geta(3, l1, r1) != inf) ans = max(ans, Geta(3, l1, r1) * Bmax);
		if (Bmin > 0 && Geta(2, l1, r1) != -inf) ans = max(ans, Geta(2, l1, r1) * Bmin);
		else if (Bmin <= 0 && Geta(1, l1, r1) != inf) ans = max(ans, Geta(1, l1, r1) * Bmin);
		write(ans), putchar('\n');
	}
	return 0;
}
