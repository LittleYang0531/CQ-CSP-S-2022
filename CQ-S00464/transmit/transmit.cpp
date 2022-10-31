#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define inf 1e18
#define ll long long
#define pii pair <int, int>
#define mp make_pair
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
int n, Q, k;
int a[200005];
vector <int> G[200005];
int dep[200005], Fa[200005], siz[200005], son[200005];
ll s[200005];
void dfs1(int x, int fa) {
	s[x] = s[fa] + a[x]; 
	Fa[x] = fa, dep[x] = dep[fa] + 1;
	siz[x] = 1;
	for(auto y : G[x]) {
		if(y == fa) continue;
		dfs1(y, x);
		if(!son[x] || siz[y] > siz[son[x]]) son[x] = y;
		siz[x] += siz[y];
	}
}
int top[200005];
void dfs2(int x) {
	int fa = Fa[x];
	if(son[fa] == x) top[x] = top[fa];
	else top[x] = x;
	if(son[x]) dfs2(son[x]);
	for(auto y : G[x]) if(!top[y]) dfs2(y);
}
inline int LCA(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = Fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	return x;
}
namespace _2 {
	struct Matrix {
		ll a[2][2];
		Matrix () {
			a[0][0] = a[0][1] = a[1][0] = a[1][1] = inf;
		}
		Matrix (ll A, ll B, ll C, ll D) {
			a[0][0] = A, a[0][1] = B, a[1][0] = C, a[1][1] = D;
		}
	};
	inline Matrix operator *(const Matrix &A, const Matrix &B) {
		Matrix C;
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) C.a[i][j] = min(C.a[i][j], A.a[i][k] + B.a[k][j]);
		return C;
	}
	int fa[200005][21];
	Matrix b[200005], f[200005][21];
	void dfs3(int x) {
		fa[x][0] = Fa[x];
		f[x][0] = b[x];
		for(int i = 1; i <= 20; i++) {
			fa[x][i] = fa[fa[x][i-1]][i-1];
			f[x][i] = f[x][i-1] * f[fa[x][i-1]][i-1];
		}
		for(auto y : G[x]) {
			if(y == Fa[x]) continue;
			dfs3(y);	
		}
	}
	void init() {
		for(int i = 1; i <= n; i++) b[i] = Matrix(a[i], a[Fa[i]], 0, a[Fa[i]]);
		dfs3(1);
	}
	ll get_ans(int x, int y) {
		if(dep[x] > dep[y]) swap(x, y);
		if(x == y) return a[x];
		int lca = LCA(x, y);
		if(x == lca) {
			Matrix fir = Matrix(inf, a[y], inf, inf);
			for(int i = 20; i >= 0; i--) {
				if(dep[fa[y][i]] >= dep[x]) {
					fir = fir * f[y][i];
					y = fa[y][i];
				}
			}
			return fir.a[0][1];
		}
		else {
			Matrix firx = Matrix(inf, a[x], inf, inf), firy = Matrix(inf, a[y], inf, inf);
			for(int i = 20; i >= 0; i--) {
				if(dep[fa[x][i]] >= dep[lca]) {
					firx = firx * f[x][i];
					x = fa[x][i];
				}
			}
			for(int i = 20; i >= 0; i--) {
				if(dep[fa[y][i]] >= dep[lca]) {
					firy = firy * f[y][i];
					y = fa[y][i];
				}
			}
			return min(firx.a[0][1] + firy.a[0][1] - a[lca], firx.a[0][0] + firy.a[0][0]);
		}
		return inf;
	}
	void solve() {
		init();
		while(Q--) {
			int x = read(), y = read();
			write(get_ans(x, y)), putchar('\n');
		}
	} 
};
namespace _3 {
	struct Matrix {
		ll a[3][3];
		Matrix () {
			a[0][0] = a[0][1] = a[0][2] = a[1][0] = a[1][1] = a[1][2] = a[2][0] = a[2][1] = a[2][2] = inf;
		}
		Matrix (ll A1, ll A2, ll A3, ll A4, ll A5, ll A6, ll A7, ll A8, ll A9) {
			a[0][0] = A1, a[0][1] = A2, a[0][2] = A3;
			a[1][0] = A4, a[1][1] = A5, a[1][2] = A6;
			a[2][0] = A7, a[2][1] = A8, a[2][2] = A9;
		}
	};
	inline Matrix operator *(const Matrix &A, const Matrix &B) {
		Matrix C;
		for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) C.a[i][j] = min(C.a[i][j], A.a[i][k] + B.a[k][j]);
		return C;
	}
	int fa[200005][21], c[200005];
	Matrix b[200005], f[200005][21];
	void dfs3(int x) {
		fa[x][0] = Fa[x];
		f[x][0] = b[x];
		for(int i = 1; i <= 20; i++) {
			fa[x][i] = fa[fa[x][i-1]][i-1];
			f[x][i] = f[x][i-1] * f[fa[x][i-1]][i-1];
		}
		for(auto y : G[x]) {
			if(y == Fa[x]) continue;
			dfs3(y);	
		}
	}
	void init() {
		a[0] = 1e9;
		for(int i = 0; i <= n; i++) {
			c[i] = 1e9;
			for(auto x : G[i]) if(x != Fa[i]) c[i] = min(c[i], a[x]);
		}
		for(int i = 1; i <= n; i++) b[i] = Matrix(c[i], a[i], a[Fa[i]], 0, c[Fa[i]], a[Fa[i]], inf, 0, c[Fa[Fa[i]]]);
		dfs3(1);
	}
	ll get_ans(int x, int y) {
		if(dep[x] > dep[y]) swap(x, y);
		if(x == y) return a[x];
		int lca = LCA(x, y);
		if(x == lca) {
			if(dep[x] + 3 >= dep[y]) return a[x] + a[y];
			Matrix fir = Matrix(inf, inf, a[y], inf, inf, inf, inf, inf, inf);
			for(int i = 20; i >= 0; i--) {
				if(dep[fa[y][i]] >= dep[x] + 1) {
					fir = fir * f[y][i];
					y = fa[y][i];
				}
			}
			return min(min(fir.a[0][0], fir.a[0][1]), fir.a[0][2]) + a[x];
		}
		else {
			Matrix firx = Matrix(inf, inf, a[x], inf, inf, inf, inf, inf, inf), firy = Matrix(inf, inf, a[y], inf, inf, inf, inf, inf, inf);
			for(int i = 20; i >= 0; i--) {
				if(dep[fa[x][i]] >= dep[lca] + 1) {
					firx = firx * f[x][i];
					x = fa[x][i];
				}
			}
			for(int i = 20; i >= 0; i--) {
				if(dep[fa[y][i]] >= dep[lca] + 1) {
					firy = firy * f[y][i];
					y = fa[y][i];
				}
			}
			ll Ans = inf;
			Ans = min(min(firx.a[0][0], firx.a[0][1]), firx.a[0][2]) + a[lca] + min(min(firy.a[0][0], firy.a[0][1]), firy.a[0][2]);
			Ans = min(Ans, firx.a[0][2] + firy.a[0][2]);
			Ans = min(Ans, firx.a[0][1] + firy.a[0][2]);
			Ans = min(Ans, firx.a[0][2] + firy.a[0][1]);
			Ans = min(Ans, firx.a[0][1] + firy.a[0][1] + min(c[lca], a[Fa[lca]]));
			Ans = min(Ans, firx.a[0][2] + firy.a[0][0] + c[y]);
			Ans = min(Ans, firx.a[0][0] + firy.a[0][2] + c[x]);
			return Ans;
		}
		return inf;
	}
	void solve() {
		init();
		while(Q--) {
			int x = read(), y = read();
			write(get_ans(x, y)), putchar('\n');
		}
	} 
};
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	n = read(), Q = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0), dfs2(1);
	if(k == 1) {
		while(Q--) {
			int x = read(), y = read();
			int lca = LCA(x, y);
			write(s[x] + s[y] - 2 * s[lca] + a[lca]), putchar('\n');
		}
	}
	if(k == 2) _2 :: solve();
	if(k == 3) _3 :: solve();
	return 0;
}
/*
k = 1 差分
k = 2 动态 dp
k = 3 时可能去绕路 

只要 k = 1 不挂。。。 
*/
