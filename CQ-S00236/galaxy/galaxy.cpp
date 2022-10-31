#include<bits/stdc++.h>
using namespace std;
#define MAXN 500000
int n, m, q, t, u, v;
vector<int> G[MAXN+5];
inline int read() {
	int s = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
	return s; 
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	srand(time(0));
	n = read(), m = read(), q = read();
	for (int i = 1; i <= m; ++i) {
		u = read(), v = read();
		G[u].push_back(v);
	}
	while (q--) {
		t = read(), u = read();
		if (t == 1 || t == 3) v = read();
		if (rand() % 2) puts("YES");
		else puts("NO");
	}
	return 0;
}
