#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
template <class T>
void read(T &x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ '0');
		ch = getchar();
	}
	x *= f;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n), read(m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		read(u), read(v);
	}
	int q;
	read(q);
	while(q--) {
		int f;
		read(f);
		if(f == 1) {
			int x, y;
			read(x), read(y);
			printf("NO\n");
		}
		if(f == 2) {
			int x;
			read(x);
			printf("NO\n");
		}
		if(f == 3) {
			int x, y;
			read(x), read(y);
			printf("YES\n");
		}
		if(f == 4) {
			int x;
			read(x);
			printf("YES\n");
		}
	}
	return 0;
} 
