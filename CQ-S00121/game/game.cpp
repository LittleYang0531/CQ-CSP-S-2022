#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int read();
const int MAXN = 100005;

int n, m, q, a[MAXN], b[MAXN];
void init() {
	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) b[i] = read();
}

struct rmq{
	int l;
	int data[MAXN][20];
	void setmax() { memset(data, 127, sizeof data); }
	void makermq(int nl) {
		l = nl;
		for (int i = 1, len = 2; len <= l; i++, len <<= 1) {
			for (int j = 1; j + len - 1 <= l; j++) {
				data[j][i] = min(data[j][i - 1], data[j + (len >> 1)][i - 1]);
			}
		}
	}
	int ask(int l, int r) {
		int len = r - l + 1, cnt = 0;
		while (len) {
			cnt ++;
			len >>= 1;
		}
		cnt -= 1;
		return min(data[l][cnt], data[r - (1 << cnt) + 1][cnt]);
	}
}amin, amax, bmin, bmax, azmin, afmax;

void rmq() {
	amin.setmax();
	amax.setmax();
	bmin.setmax();
	bmax.setmax();
	azmin.setmax();
	afmax.setmax();
	for (int i = 1; i <= n; i++) {
		amin.data[i][0] = a[i];
		if  (a[i] < 0) azmin.data[i][0] = 1000000000;
		else azmin.data[i][0] = a[i];
		
		amax.data[i][0] = -a[i];
		if  (a[i] > 0) afmax.data[i][0] = 1000000000;
		else afmax.data[i][0] = -a[i];
	}
	for (int i = 1; i <= m; i++) {
		bmin.data[i][0] = b[i];
		bmax.data[i][0] = -b[i];
	}
	amin.makermq(n);
	amax.makermq(n);
	azmin.makermq(n);
	afmax.makermq(n);
	bmin.makermq(m);
	bmax.makermq(m);
}

ll ans, add1, add2;
void solve() {
	int l1, r1, l2, r2;
	ll v1, v2, v3, v4;

	while (q--) {
		l1 = read(), r1 = read(), l2 = read(), r2 = read();
		v1 = -bmax.ask(l2, r2);
		v2 = bmin.ask(l2, r2);
		
		if (v1 <= 0) {
			v3 = amin.ask(l1, r1);
			if (v3 > 0) v1 = v2;
			ans = v1 * v3;
		} else if (v2 >= 0) {
			v3 = -amax.ask(l1, r1);
			if (v3 < 0) v2 = v1;
			ans = v2 * v3;
		} else {
			v3 = -afmax.ask(l1, r1);
			v4 = azmin.ask(l1, r1);
			add1 = v1 * v3;
			add2 = v2 * v4;
			ans = max(add1, add2);
		}
		printf("%lld\n", ans);
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	init();
	rmq();
	solve();
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
