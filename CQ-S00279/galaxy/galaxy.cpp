#include<bits/stdc++.h>

#define For(x, y, z) for (int x = y; x <= z; ++x)
#define Rof(x, y, z) for (int x = y; x >= z; --x)
#define Eor(i, x) for (int i = head[x]; i; i = nxt[i])

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

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

const int N = 5e5 + 10;
int n, m, q;
int head[N], nxt[N << 1], to[N << 1], cur;
bool w[N << 1];
map<pii, int> mp;
int d[N], cnt;
vector<int> a[N];

inline void inc(int u) { cnt -= (d[u] == 1), ++d[u], cnt += (d[u] == 1); }
inline void del(int u) { cnt -= (d[u] == 1), --d[u], cnt += (d[u] == 1); }
inline void add(int u, int v) { 
	mp[pii(u, v)] = ++cur, a[v].push_back(u), inc(u);
	to[cur] = v, nxt[cur] = head[u], head[u] = cur;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out","w", stdout);
	n = read(), m = read();
	For(i, 1, m) { int u = read(), v = read(); add(u, v); }
	q = read();
	while (q--) { 
		int op = read(), u = read(), v = 0;
		if (op & 1) v = read();
		if (op == 1) w[mp[pii(u, v)]] = 1, del(u);
		if (op == 3) w[mp[pii(u, v)]] = 0, inc(u);
		if (op == 2) { for (int y : a[u]) { int x = mp[pii(y, u)]; 
			if (!w[x]) w[x] = 1, del(y); } }
		if (op == 4) { for (int y : a[u]) { int x = mp[pii(y, u)];
			if (w[x]) w[x] = 0, inc(y); } }
		puts(cnt == n ? "YES" : "NO");
	}
	return 0;
}
