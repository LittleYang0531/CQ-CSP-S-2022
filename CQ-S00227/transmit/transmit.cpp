#include <bits/stdc++.h>

using std :: cin; 
using std :: cout; 
using std :: vector; 

constexpr int M = 2e5 + 5; 
constexpr long long INF = 1e16; 

typedef long long ll; 
typedef unsigned long long ull;  
typedef double db; 

inline int read() {
	int f = 1, s = 0; char ch = getchar(); 
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar(); 
	while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar(); 
	return f * s; 
}

namespace Solver {
	int n, q, D; 
	ll val[M], s[M]; 
	int f[M][18], d[M]; 
	vector < int > adj[M]; 
	inline void chkmn(ll &x, const ll&y) {
		if(x > y) x = y; 
	}
	struct mat {
		ll a[3][3]; 
		mat() {for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) a[i][j] = INF;} 
		inline void I() {
			for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) if(i == j) a[i][j] = 0; else a[i][j] = INF; 
		}
		inline ll *operator[](int x) {return a[x];} 
		inline void set(int x) {
			if(D == 1) a[0][0] = val[x]; 
			else if(D == 2) a[1][0] = 0, a[0][1] = a[1][1] = val[x];  
			else a[1][0] = a[2][1] = 0, a[0][2] = a[1][2] = a[2][2] = val[x]; 
		}
		inline mat operator * (const mat &rhs) const {
		    mat ret; 
		    for(int i = 0; i < D; ++i) 
		        for(int k = 0; k < D; ++k) {
		        	const ll v = a[i][k]; if(v >= INF) continue ; 
		        	for(int j = 0; j < D; ++j) chkmn(ret.a[i][j], v + rhs.a[k][j]); 
				}
		    return ret; 
		}
	} up[M][18], down[M][18]; 
	inline void dfs(int x, int fa, int dep) {
		d[x] = dep, f[x][0] = fa, s[x] = s[fa] + val[x]; 
		for(int i = 1; i < 18; ++i) f[x][i] = f[f[x][i - 1]][i - 1], up[x][i] = up[x][i - 1] * up[f[x][i - 1]][i - 1], down[x][i] = down[f[x][i - 1]][i - 1] * down[x][i - 1]; 
		for(int &y : adj[x]) if(y ^ fa) dfs(y, x, dep + 1); 
	}
	inline int lca(int x, int y) {
		if(d[x] < d[y]) std :: swap(x, y); 
		for(int i = 17; ~i; --i) if(d[x] - (1 << i) >= d[y]) x = f[x][i]; 
		if(x == y) return x; 
	    for(int i = 17; ~i; --i) if(f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i]; 
	    return f[x][0]; 
	} 
	inline int kth(int x, int k) {
		for(int i = 17; ~i; --i) if(k & (1 << i)) x = f[x][i]; 
		return x; 
	}
	inline ll Qv(int x, int y) {
		int l = lca(x, y); 
		return s[x] + s[y] - s[l] - s[f[l][0]]; 
	}
	inline mat Qry(int x, int y, int typ) { // typ = 0 : up ; typ = 1 : down
	    if(d[x] < d[y]) std :: swap(x, y); 
	    int k = d[x] - d[y] + 1; 
	    mat ans; ans.I(); 
	    for(int i = 17; ~i; --i) if(k & (1 << i)) {
	    	if(!typ) ans = ans * up[x][i]; 
	    	else ans = down[x][i] * ans; 
	    	x = f[x][i]; 
		}
		return ans; 
	}
	inline void solve1() {
		while(q --) { 
		    int x = read(), y = read(); if(d[x] < d[y]) std :: swap(x, y); 
		    int anc = lca(x, y), dis = d[x] + d[y] - 2 * d[anc]; 
		    if(dis <= D) {printf("%lld\n", val[x] + val[y]); continue ;} 
		    if(anc == y) {
		    	mat ans = Qry(f[x][0], y, 0); ll s = 1e17; 
		    	for(int i = 0; i < D; ++i) chkmn(s, ans[i][D - 1]); 
		    	printf("%lld\n", s + val[x]);  
		    	continue ; 
			}
			mat ans = Qry(f[x][0], anc, 0); 
			int ny = kth(y, d[y] - d[anc] - 1); 
			ans = ans * Qry(ny, y, 1); ll s = 1e17; 
			for(int i = 0; i < D; ++i) chkmn(s, ans[i][D - 1]); 
			printf("%lld\n", s + val[x]);  
		}
	}
	ll dp[M], mn[M]; 
	int ord[M]; 
	inline void mian() {
		n = read(), q = read(), D = read(); 
		for(int i = 1; i <= n; ++i) val[i] = read(), up[i][0].set(i), down[i][0].set(i); 
		for(int i = 1; i < n; ++i) {
			int u = read(), v = read();  
			adj[u].push_back(v), adj[v].push_back(u); 
		}
		dfs(1, 0, 1); 
		if(D <= 2) return solve1(), void(); 
		memset(dp, 0x3f, sizeof(dp)); 
		while(q --) {
			int x = read(), y = read(), anc = lca(x, y); 
			int m = 0; 
			int ux = x, uy = y; while(ux ^ anc) ord[++m] = ux, ux = f[ux][0]; ord[++m] = anc; 
			m += d[y] - d[anc]; int v = 0; while(uy ^ anc) ord[m - v] = uy, uy = f[uy][0], ++v; 
			dp[x] = val[x];
			for(int i = 1; i <= m; ++i) {
			    int u = ord[i]; mn[u] = INF; 
			    for(int j = 1; j <= 3; ++j) {
			    	if(i - j >= 1) {
			    	    chkmn(dp[u], dp[ord[i - j]] + val[u]); 
			    	    if(j ^ 3) chkmn(dp[u], mn[ord[i - j]] + val[u]); 
					}
				}
			    for(int &v : adj[u]) {
			        chkmn(dp[v], dp[u] + val[v]); 
			        if(i - 1 >= 1) chkmn(dp[v], dp[ord[i - 1]] + val[v]), chkmn(dp[v], mn[ord[i - 1]] + val[v]); 
			        if(i - 2 >= 1) chkmn(dp[v], dp[ord[i - 2]] + val[v]); 
			        chkmn(mn[u], dp[v]); chkmn(dp[u], dp[v] + val[u]);
				}
			}
			printf("%lld\n", dp[y]); 
			for(int i = 1; i <= m; ++i) {
			    int u = ord[i]; dp[u] = mn[u] = INF;
			    for(int &v : adj[u]) dp[v] = INF; 
			}
		}
	}
} ; 

int main() 
{
    freopen("transmit.in", "r", stdin); 
    freopen("transmit.out", "w", stdout); 
    Solver :: mian(); 
    return 0; 
}
