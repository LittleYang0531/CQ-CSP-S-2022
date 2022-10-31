#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << "=" << x << endl
using namespace std;

namespace True_False {
	// gcd
	template <class T>
	T gcd(T x, T y) {
		if (!y) return x;
		return gcd(y, x % y);
	}
	// read
	template <class T>
	void read(T& x) {
		x = 0; static char ch; static bool some;
		some = 0;
		while ((ch = getchar()) < '0' || ch > '9') some = ch == '-';
		while (ch >= '0' && ch <= '9')
			x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
		if (some) x = -x;
	}
	template <class T, class... Args>
	void read(T& x, Args& ...args) { read(x), read(args...); }
	// write
	template <class T>
	void fwrite(T x) {
		if (x > 9) fwrite(x / 10);
		putchar(x % 10 + 48);
	}
	template <class T>
	void write(T x) {
		if (x < 0) putchar('-'), x = -x;
		fwrite(x);
	}
	void write(char x) { putchar(x); }
	template <class T, class... Args>
	void write(T x, Args ...args) { write(x), write(args...); }
}
using namespace True_False;

const int inf = 1e3 + 5;

int n, m, q, b[inf][inf], a[inf][inf], g[inf], h[inf];

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n, m);
	for (int i = 1, u, v; i <= m; ++i) {
		read(u, v);
		a[u][v] = 1;
		b[u][v] = 1;
		++g[u];
	}
	read(q);
	while (q--) {
		int t, u, v;
		read(t);
		if (t == 1) {
			read(u, v);
			a[u][v] = 0;
			--g[u];
		} else if (t == 2) {
			read(u);
			for (int i = 1; i <= n; ++i) {
				if (a[i][u]) {
					a[i][u] = 0;
					--g[i];
				}
			}
		} else if (t == 3) {
			read(u, v);
			a[u][v] = 1;
			++g[u];
		} else {
			read(u);
			for (int i = 1; i <= n; ++i) {
				if (b[i][u] && !a[i][u]) {
					a[i][u] = 1;
					++g[i];
				}
			}
		}
		bool flag = 0;
		for (int i = 1; i <= n; ++i) flag |= g[i] != 1;
		if (flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
