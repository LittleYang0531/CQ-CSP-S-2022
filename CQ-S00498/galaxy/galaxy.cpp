#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define pa make_pair 
const int N = 5e5 + 10;
void read(int &x) {
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') f |= c == '-', c = getchar();
	x = 0;
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	x = f ? -x : x;
}
int n, m, q, cnt;
int head[N], ver[N], nxt[N];
int a[N], b[N];
int vis[N];
map<pair<int, int>, int> f;

void add(int u, int v) {
	ver[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u), read(v);
		add(u, v), f[pa(u, v)] = 1;
		a[i] = u, b[i] = v;
	}
	read(q);
	for (int i = 1; i <= q; i++) {
		int t, u, v;
		read(t), read(u);
		if (t == 1 || t == 3) 
			read(v);
		if (t == 1) 
			f[pa(u, v)] = 2;
		else if (t == 2) {
			for (int j = 1; j <= n; j++) 
				if (f[pa(j, u)] == 1) f[pa(j, u)] = 2; 
		} else if (t == 3) {
			f[pa(u, v)] = 1;
		} else {
			for (int j = 1; j <= n; j++) 
				if (f[pa(j, u)] == 2) f[pa(j, u)] = 1;
		}
		bool flag = 0;
		for (int j = 1; j <= m; j++) {
			if (f[pa(a[j], b[j])] == 1) vis[a[j]]++;
		}
		for (int j = 1; j <= n; j++) {
			if (vis[j] != 1) {
				flag = 1;
			}
			vis[j] = 0;
		}
		if (flag == 1) puts("NO");
		else {
			puts("YES");
		}
	}
	
	return 0;
} 


