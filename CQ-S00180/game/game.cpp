#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int A = 0, B = 1, Z = 0, F = 1, MAX = 0, MIN = 1;
int n, m, q, l1, r1, l2, r2, a[100005], b[100005], lg[100005], sum[2][100005], st[2][2][2][100005][18];
bool z, f, flag[2][2][2][100005][18];
ll ans;
void read(int& x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	x *= f;
}
void write(ll x) {
	static char buffer[20];
	int p = -1;
	if(!x) {
		putchar('0');
		return;
	}
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	while(x) {
		buffer[++p] = (x % 10) ^ 48;
		x /= 10;
	}
	while(~p) putchar(buffer[p--]);
}
bool check(int AB, int ZF, int MAXMIN, int l, int r) {
	const int k = lg[r - l + 1];
	return (flag[AB][ZF][MAXMIN][l][k] || flag[AB][ZF][MAXMIN][r - (1 << k) + 1][k]);
}
ll ask(int AB, int ZF, int MAXMIN, int l, int r) {
	const int k = lg[r - l + 1];
	if(MAXMIN == MAX) {
		return max(st[AB][ZF][MAXMIN][l][k], st[AB][ZF][MAXMIN][r - (1 << k) + 1][k]);
	}
	else {
		return min(st[AB][ZF][MAXMIN][l][k], st[AB][ZF][MAXMIN][r - (1 << k) + 1][k]);
	}
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	memset(st[A][Z][MAX], 0x8f, sizeof(st[A][Z][MAX]));
	memset(st[A][F][MAX], 0x8f, sizeof(st[A][F][MAX]));
	memset(st[B][Z][MAX], 0x8f, sizeof(st[A][Z][MAX]));
	memset(st[B][F][MAX], 0x8f, sizeof(st[A][F][MAX]));
	memset(st[A][Z][MIN], 0x7f, sizeof(st[A][Z][MIN]));
	memset(st[A][F][MIN], 0x7f, sizeof(st[A][F][MIN]));
	memset(st[B][Z][MIN], 0x7f, sizeof(st[A][Z][MIN]));
	memset(st[B][F][MIN], 0x7f, sizeof(st[A][F][MIN]));
	for(int i = 2; i <= 100000; ++i) lg[i] = lg[i >> 1] + 1;
	for(int i = 1; i <= n; ++i) {
		read(a[i]);
		sum[A][i] = sum[A][i - 1] + (a[i] == 0);
		if(a[i] > 0) {
			st[A][Z][MAX][i][0] = a[i];
			st[A][Z][MIN][i][0] = a[i];
			flag[A][Z][MAX][i][0] = true;
			flag[A][Z][MIN][i][0] = true;
		}
		if(a[i] < 0) {
			st[A][F][MAX][i][0] = a[i];
			st[A][F][MIN][i][0] = a[i];
			flag[A][F][MAX][i][0] = true;
			flag[A][F][MIN][i][0] = true;
		}
	}
	for(int i = 1; i <= m; ++i) {
		read(b[i]);
		sum[B][i] = sum[B][i - 1] + (b[i] == 0);
		if(b[i] > 0) {
			st[B][Z][MAX][i][0] = b[i];
			st[B][Z][MIN][i][0] = b[i];
			flag[B][Z][MAX][i][0] = true;
			flag[B][Z][MIN][i][0] = true;
		}
		if(b[i] < 0) {
			st[B][F][MAX][i][0] = b[i];
			st[B][F][MIN][i][0] = b[i];
			flag[B][F][MAX][i][0] = true;
			flag[B][F][MIN][i][0] = true;
		}
	}
	for(int i = 1; i <= lg[n]; ++i) {
		for(int j = 1; j <= n - (1 << i) + 1; ++j) {
			st[A][Z][MAX][j][i] = max(st[A][Z][MAX][j][i - 1], st[A][Z][MAX][j + (1 << (i - 1))][i - 1]);
			st[A][F][MAX][j][i] = max(st[A][F][MAX][j][i - 1], st[A][F][MAX][j + (1 << (i - 1))][i - 1]);
			st[A][Z][MIN][j][i] = min(st[A][Z][MIN][j][i - 1], st[A][Z][MIN][j + (1 << (i - 1))][i - 1]);
			st[A][F][MIN][j][i] = min(st[A][F][MIN][j][i - 1], st[A][F][MIN][j + (1 << (i - 1))][i - 1]);
			flag[A][Z][MAX][j][i] = flag[A][Z][MAX][j][i - 1] || flag[A][Z][MAX][j + (1 << (i - 1))][i - 1];
			flag[A][F][MAX][j][i] = flag[A][F][MAX][j][i - 1] || flag[A][F][MAX][j + (1 << (i - 1))][i - 1];
			flag[A][Z][MIN][j][i] = flag[A][Z][MIN][j][i - 1] || flag[A][Z][MIN][j + (1 << (i - 1))][i - 1];
			flag[A][F][MIN][j][i] = flag[A][F][MIN][j][i - 1] || flag[A][F][MIN][j + (1 << (i - 1))][i - 1];
		}
	}
	for(int i = 1; i <= lg[m]; ++i) {
		for(int j = 1; j <= m - (1 << i) + 1; ++j) {
			st[B][Z][MAX][j][i] = max(st[B][Z][MAX][j][i - 1], st[B][Z][MAX][j + (1 << (i - 1))][i - 1]);
			st[B][F][MAX][j][i] = max(st[B][F][MAX][j][i - 1], st[B][F][MAX][j + (1 << (i - 1))][i - 1]);
			st[B][Z][MIN][j][i] = min(st[B][Z][MIN][j][i - 1], st[B][Z][MIN][j + (1 << (i - 1))][i - 1]);
			st[B][F][MIN][j][i] = min(st[B][F][MIN][j][i - 1], st[B][F][MIN][j + (1 << (i - 1))][i - 1]);
			flag[B][Z][MAX][j][i] = flag[B][Z][MAX][j][i - 1] || flag[B][Z][MAX][j + (1 << (i - 1))][i - 1];
			flag[B][F][MAX][j][i] = flag[B][F][MAX][j][i - 1] || flag[B][F][MAX][j + (1 << (i - 1))][i - 1];
			flag[B][Z][MIN][j][i] = flag[B][Z][MIN][j][i - 1] || flag[B][Z][MIN][j + (1 << (i - 1))][i - 1];
			flag[B][F][MIN][j][i] = flag[B][F][MIN][j][i - 1] || flag[B][F][MIN][j + (1 << (i - 1))][i - 1];
		}
	}
	while(q--) {
		read(l1), read(r1), read(l2), read(r2);
		z = check(B, Z, MAX, l2, r2), f = check(B, F, MAX, l2, r2);
		if(z && f) {
			if(sum[A][r1] - sum[A][l1 - 1]) {
				puts("0");
			}
			else {
				ans = LONG_LONG_MIN;
				if(check(A, Z, MIN, l1, r1)) ans = ask(A, Z, MIN, l1, r1) * ask(B, F, MIN, l2, r2);
				if(check(A, F, MAX, l1, r1)) ans = max(ans, ask(A, F, MAX, l1, r1) * ask(B, Z, MAX, l2, r2));
				write(ans);
				putchar('\n');
			}
		}
		else if(z) {
			if(check(A, Z, MAX, l1, r1)) {
				if(sum[B][r2] - sum[B][l2 - 1]) {
					puts("0");
				}
				else {
					write(ask(A, Z, MAX, l1, r1) * ask(B, Z, MIN, l2, r2));
					putchar('\n');
				}
			}
			else if(sum[A][r1] - sum[A][l1 - 1]) {
				puts("0");
			}
			else {
				write(ask(A, F, MAX, l1, r1) * ask(B, Z, MAX, l2, r2));
				putchar('\n');
			}
		}
		else if(f) {
			if(check(A, F, MIN, l1, r1)) {
				if(sum[B][r2] - sum[B][l2 - 1]) {
					puts("0");
				}
				else {
					write(ask(A, F, MIN, l1, r1) * ask(B, F, MAX, l2, r2));
					putchar('\n');
				}
			}
			else if(sum[A][r1] - sum[A][l1 - 1]) {
				puts("0");
			}
			else {
				write(ask(A, Z, MIN, l1, r1) * ask(B, F, MIN, l2, r2));
				putchar('\n');
			}
		}
		else {
			puts("0");
		}
	}
	return 0;
}
