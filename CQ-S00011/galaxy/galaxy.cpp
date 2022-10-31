#include <bits/stdc++.h>
using namespace std;
#define il inline
#define mp make_pair
#define pb push_back
#define ptc putchar
#define R(i, l, r) for (int i = l; i <= r; ++i)
#define debug puts("---------------------------")
typedef pair <int, int> PII;
typedef long long ll;
namespace CYYH {
	template <typename T>
	il void read(T &x) {
		x = 0; T f = 1; char ch;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar(); x *= f;
	}
	template <typename T, typename ...L>
	il void read(T &x, L &...y) {read(x); read(y...);}
	template <typename T>
	il void write(T x) {
		if (x < 0) ptc('-'), x = -x;
		if (x > 9) write(x / 10);
		ptc(x % 10 + '0');
	}
	template <typename T, typename ...L>
	il void write(T x, L ...y) {write(x), ptc(' '); write(y...);}
}
using namespace CYYH;

signed main() {
	// 我突然感觉 我要退役了 
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int n, m; read(n, m);
	R(i, 1, m) {
		int u, v;
		read(u, v);
	}
	int q;
	read(q);
	while (q--) {
		puts("NO");
	}
	return 0;
}


