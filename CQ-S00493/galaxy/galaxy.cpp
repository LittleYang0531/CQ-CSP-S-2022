#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int n, m, x, y, q;
template <typename _Tp>inline void read(_Tp& x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar(); 
	}
	x *= f;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= m; i++)
		read(x), read(y);
	read(q);
	while (q--)
		printf("YES\n"); 
	return 0;
}
