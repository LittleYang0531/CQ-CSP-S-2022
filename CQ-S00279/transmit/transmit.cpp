#include<bits/stdc++.h>

#define For(x, y, z) for (int x = y; x <= z; ++x)
#define Rof(x, y, z) for (int x = y; x >= z; --x)
#define Eor(x) for (int i = head[x]; i; i = nxt[i])

using namespace std;
using i64 = long long;

inline int read() {
	int x = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
int __stk[62], __len;
inline void put(i64 x) {
	if (x < 0) putchar('-'), x = -x;
	do { __stk[++__len] = x % 10; } while (x /= 10);
	while (__len) putchar(__stk[__len--] + '0');
}

const int N = 2010;
int n, m, k, w[N];
vector<int> a[N], to[N];

void dfs(int f, int u, int d, int fa) {
	if (d > k) return; if (fa) to[f].push_back(u);
	for (int v : a[u]) if (v != fa) dfs(f, v, d + 1, u);
}
i64 d[N][N];

struct node {
	i64 x, w;
	bool operator <(const node &b) const {
		return w > b.w;
	}
};
priority_queue<node> q;
void dij(int s) {
	memset(d[i], 0x3f, sizeof d[i]);
	d[i][i] = val[i], q.push(i);
	while (!q.empty()) {
		int u = q.top(); q.pop();
		for (int v : to[u]) {
			if (d[i][u] + val[v] < d[i][v]) {
				d[i][v] = d[i][u] + val[v];
				q.push((node) {v, d[i][v]});
			}
		}
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out","w", stdout);
	n = read(), m = read(), k = read();
	For(i, 1, n) val[i] = read();
	For(i, 2, n) {
		int u = read(), v = read();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	For(i, 1, n) dfs(i, i, 0, 0);
	For(i, 1, n) dij(i);
	while (m--) {
		int s = read(), t = read();
		put(d[s][t]), puts("");
	}
	return 0;
}
