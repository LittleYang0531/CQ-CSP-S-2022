#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#define ull unsigned long long
using namespace std;
ull read() {
	ull p = 0, flg = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') flg = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p = p * 10 + c - '0';
		c = getchar();
	}
	return p * flg;
}
void write(ull x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 2505, M = 2e4 + 5;
int fir[N], nex[M], to[M], cnt;
void add(int x, int y) {
	cnt++;
	nex[cnt] = fir[x];
	to[cnt] = y;
	fir[x] = cnt;
}
ull s[N], dp[N], vis[N], ans = 0;
void dfs(ull x, ull k) {
	if (k == 5 && x == 1) {
		ull sum = 0;
		for (ull i = 1; i <= 4; i++) {
			//cout << dp[i] << " ";
			sum += s[dp[i]];
		}
		//cout << sum;
		//cout << endl;
		ans = max(ans, sum);
	}
	for (ull i = fir[x]; i; i = nex[i]) {
		if (!vis[to[i]]) {
			dp[k + 1] = to[i];
			vis[to[i]] = 1;
			dfs(to[i], k + 1);
			vis[to[i]] = 0;
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	ull n = read(), m = read(), k = read();
	for (ull i = 2; i <= n; i++) {
		s[i] = read();
	}
	for (ull i = 1; i <= m; i++) {
		ull x = read(), y = read();
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	if (k != 0) {
		sort(s + 2, s + 1 + n);
		cout << s[n] + s[n - 1] + s[n - 2] + s[n - 3] << endl;
	}
	else cout << ans << endl;
	//for (int i = 1; i <= n; i++) write(siz[i]), putchar(32);
	return 0;
}
// ? md就我做不出来是吧
