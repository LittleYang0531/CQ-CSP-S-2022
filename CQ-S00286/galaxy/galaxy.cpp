#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int read() {
	int p = 0, flg = 1;
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
void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 2e2 + 5;
int mp[N][N], s[N][N];
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		//mp[x][y]++;
		//s[x][y]++;
	}
	int q = read();
	while (q--) {
//		int t = read(), x = read(), y;
//		if (t % 2) y = read();
//		if (t == 1) {
//			mp[x][y]--;
//		}
//		else if (t == 2) {
//			for (int i = 1; i <= n; i++) {
//				mp[x][i] = 0;
//			}
//		}
//		else if (t == 3) {
//			mp[x][y]++;
//		}
//		else {
//			for (int i = 1; i <= n; i++) {
//				if (s[x][i]) mp[x][i]++;
//			}
//		}
//		bool flg = false;
//		for (int i = 1; i <= n; i++) {
//			int sum = 0;
//			for (int j = 1; j <= n; j++) {
//				if (mp[i][j] == 1) sum++;
//			}
//			if (sum != 1) {
//				flg = 1;
//				break;
//			}
//		}
		puts("NO");
	}
	return 0;
}
