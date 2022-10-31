#include<bits/stdc++.h>

#define For(x, y, z) for (int x = y; x <= z; ++x)
#define Rof(x, y, z) for (int x = y; x >= z; --x)
#define Eor(x) for (int i = head[x]; i; i = nxt[i])

using namespace std;
using i64 = long long;

inline i64 read() {
	i64 x = 0, f = 0; char ch = getchar();
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

char qqq;
const int N = 1e5 + 10;
const int inf = 1e9 + 1;
int n, m, q;
struct SGE {
	#define mid ((l + r) >> 1)
	#define ls(x) (t[x].ls)
	#define rs(x) (t[x].rs)
	struct node {
		int w, ls, rs;
	}t[N << 6];
	int root[N], num;
	int New(int x) { return t[++num] = t[x], num; }
	void insert(int &x, int w, int l = -inf, int r = inf) {
		x = New(x), ++t[x].w; if (l == r) return;
		if (mid >= w) insert(ls(x), w, l, mid);
		else insert(rs(x), w, mid + 1, r);
	} 
	int ask_mil(int p, int q, int l = -inf, int r = inf) {
		if (t[q].w - t[p].w == 0) return inf; if (l == r) return l;
		if (t[ls(q)].w - t[ls(p)].w) return ask_mil(ls(p), ls(q), l, mid);
		return ask_mil(rs(p), rs(q), mid + 1, r);
	}
	int ask_mir(int p, int q, int l = -inf, int r = inf) {
		if (t[q].w - t[p].w == 0) return inf;
		if (l == r) return l; int ans = inf;
		if (mid + 1 <= 0 && t[rs(q)].w - t[rs(p)].w) 
			ans = ask_mir(rs(p), rs(q), mid + 1, r);
		if (ans == inf) ans = ask_mir(ls(p), ls(q), l, mid);
		return ans; 
	}
	int ask_mar(int p, int q, int l = -inf, int r = inf) {
		if (t[q].w - t[p].w == 0) return -inf; if (l == r) return l;
		if (t[rs(q)].w - t[rs(p)].w) return ask_mar(rs(p), rs(q), mid + 1, r);
		return ask_mar(ls(p), ls(q), l, mid);
	}
	int ask_mal(int p, int q, int l = -inf, int r = inf) {
		if (t[q].w - t[p].w == 0) return -inf;
		if (l == r) return l; int ans = -inf;
		if (mid >= 0 && t[ls(q)].w - t[ls(p)].w) 
			ans = ask_mal(ls(p), ls(q), l, mid);
		if (ans == -inf) ans = ask_mal(rs(p), rs(q), mid + 1, r);
		return ans; 
	}
	#undef mid
	#undef ls
	#undef rs
}f, g;
char qqqq;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out","w", stdout);
//	cerr << (&qqq - &qqqq) / 1024.0 / 1024.0;
	n = read(), m = read(), q = read();
	For(i, 1, n) f.insert(f.root[i] = f.root[i - 1], read());
	For(i, 1, m) g.insert(g.root[i] = g.root[i - 1], read());
	while (q--) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		
		i64 mil1 = f.ask_mil(f.root[l1 - 1], f.root[r1]);
		i64 mir1 = f.ask_mir(f.root[l1 - 1], f.root[r1]);
		i64 mal1 = f.ask_mal(f.root[l1 - 1], f.root[r1]);
		i64 mar1 = f.ask_mar(f.root[l1 - 1], f.root[r1]);
		
		i64 mil2 = g.ask_mil(g.root[l2 - 1], g.root[r2]);
		i64 mir2 = g.ask_mir(g.root[l2 - 1], g.root[r2]);
		i64 mal2 = g.ask_mal(g.root[l2 - 1], g.root[r2]);
		i64 mar2 = g.ask_mar(g.root[l2 - 1], g.root[r2]);
		
		i64 ans = -2e18, tmp = 2e18;
		if (mil1 != inf) { tmp = 2e18;
			if (mil2 != inf) tmp = min(tmp, mil1 * mil2);
			if (mir2 != inf) tmp = min(tmp, mil1 * mir2);
			if (mal2 != -inf) tmp = min(tmp, mil1 * mal2);
			if (mar2 != -inf) tmp = min(tmp, mil1 * mar2);
			if (tmp != 2e18) ans = max(ans, tmp);
		}
		if (mir1 != inf) { tmp = 2e18;
			if (mil2 != inf) tmp = min(tmp, mir1 * mil2);
			if (mir2 != inf) tmp = min(tmp, mir1 * mir2);
			if (mal2 != -inf) tmp = min(tmp, mir1 * mal2);
			if (mar2 != -inf) tmp = min(tmp, mir1 * mar2);
			if (tmp != 2e18) ans = max(ans, tmp);
		}
		if (mal1 != -inf) { tmp = 2e18;
			if (mil2 != inf) tmp = min(tmp, mal1 * mil2);
			if (mir2 != inf) tmp = min(tmp, mal1 * mir2);
			if (mal2 != -inf) tmp = min(tmp, mal1 * mal2);
			if (mar2 != -inf) tmp = min(tmp, mal1 * mar2);
			if (tmp != 2e18) ans = max(ans, tmp);
		}
		if (mar1 != -inf) { tmp = 2e18;
			if (mil2 != inf) tmp = min(tmp, mar1 * mil2);
			if (mir2 != inf) tmp = min(tmp, mar1 * mir2);
			if (mal2 != -inf) tmp = min(tmp, mar1 * mal2);
			if (mar2 != -inf) tmp = min(tmp, mar1 * mar2);
			if (tmp != 2e18) ans = max(ans, tmp);
		}
		put(ans), putchar('\n');
	}
	return 0;
}
