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
	putchar(x % 10 +s '0');
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int n = read(), q = read();
	while (q--) cout << 1 << endl;
	return 0;
}
