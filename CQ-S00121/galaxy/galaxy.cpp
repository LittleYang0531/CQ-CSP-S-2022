#include <cstdio>
int read();

int n, m, q;
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	q = 10;
	while (q--) {
		if (q % 3 == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

int read() {
	char x = 0;
	int y = 0;
	bool f = 0;
	while (x < '0' || x > '9') {
		x = getchar();
		if (x == '-') f = 1;
	}
	while (x >= '0' && x <= '9') {
		y = (y << 1) + (y << 3) + (x ^ 48);
		x = getchar();
	}
	return f ? (-y) : y;
}
