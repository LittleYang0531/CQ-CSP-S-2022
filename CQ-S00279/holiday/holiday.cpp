#include<bits/stdc++.h>

#define For(x, y, z) for (int x = y; x <= z; ++x)
#define Rof(x, y, z) for (int x = y; x >= z; --x)
#define Eor(x, u) for (int x = head[u]; x; x = nxt[x])

using namespace std;
using i64 = long long;
using ull = unsigned long long;

inline ull read() {
	ull x = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int __stk[62], __len;
inline void put(ull x) {
	do { __stk[++__len] = x % 10; } while (x /= 10);
	while (__len) putchar(__stk[__len--] + '0');
}

const int N = 2510, M = 10100;
int n, m, k;
int head[N], nxt[M <<1], to[M << 1], cnt;
void add(int u, int v) {
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
	to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt;
} 
int d[N][N], p[N][N], len[N];
queue<int> q;
ull val[N], ans;
inline bool cmp(int x, int y) { return val[x] > val[y]; }
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out","w", stdout);
	n = read(), m = read(), k = read() + 1;
	For(i, 2, n) val[i] = read();
	For(i, 1, m) add(read(), read());
	memset(d, 0x3f, sizeof d);
	For(i, 1, n) { 
		d[i][i] = 0, q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (d[i][u] >= k) continue;
			Eor(j, u) if (d[i][u] + 1 < d[i][to[j]]) {
				d[i][to[j]] = d[i][u] + 1, q.push(to[j]); }
		}
	}
	For(i, 2, n) For(j, 2, n) if (i != j && d[i][j] <= k && d[j][1] <= k) p[i][++len[i]] = j;
	For(i, 2, n) sort(p[i] + 1, p[i] + len[i] + 1, cmp);
	For(i, 2, n) For(j, i + 1, n) {
		if (d[i][j] > k) continue;
		int l = min(len[i], 3), r = min(3, len[j]);
		For(a, 1, l) For(b, 1, r) {
			int x = p[i][a], y = p[j][b];
			if (i != y && x != j && x != y) 
				ans = max(ans, val[i] + val[j] + val[x] + val[y]); 
		}
	}
	put(ans);
	return 0;
}

