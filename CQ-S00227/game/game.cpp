#include <bits/stdc++.h>

using std :: cin; 
using std :: cout; 
using std :: vector; 

constexpr int M = 1e5 + 5; 
constexpr int INF = 0x3f3f3f3f; 

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
	int n, m, q; 
	int lg[M]; 
	inline int max(int a, int b) {
		return a > b ? a : b; 
	}
	inline int min(int a, int b) {
		return a < b ? a : b; 
	}
	int b[2][4]; 
	struct ST {
		int a[M], n; 
	    int fp[M][18][2], fn[M][18][2]; 
	    inline void init() {
	        for(int i = 1; i <= n; ++i) 
	            for(int j = 0; j < 18; ++j) fp[i][j][0] = -1, fp[i][j][1] = INF, fn[i][j][0] = -INF, fn[i][j][1] = 1; 
	    	for(int i = 1; i <= n; ++i) 
	    	    if(a[i] >= 0) fp[i][0][0] = fp[i][0][1] = a[i]; 
	    	    else fn[i][0][0] = fn[i][0][1] = a[i]; 
	    	for(int j = 1; j < 18; ++j) 
	    	    for(int i = 1; i + (1 << j) - 1 <= n; ++i) 
	    	        for(int op = 0; op < 2; ++op) 
					    if(!op) fp[i][j][op] = max(fp[i][j - 1][op], fp[i + (1 << j - 1)][j - 1][op]), fn[i][j][op] = max(fn[i][j - 1][op], fn[i + (1 << j - 1)][j - 1][op]); 
					    else fp[i][j][op] = min(fp[i][j - 1][op], fp[i + (1 << j - 1)][j - 1][op]), fn[i][j][op] = min(fn[i][j - 1][op], fn[i + (1 << j - 1)][j - 1][op]); 
		}
		inline void Qry(int l, int r, int &s1, int &s2, int &s3, int &s4) {
		    int k = lg[r - l + 1]; 
		    s1 = max(fp[l][k][0], fp[r - (1 << k) + 1][k][0]), s2 = std :: min(fp[l][k][1], fp[r - (1 << k) + 1][k][1]); 
		    s3 = max(fn[l][k][0], fn[r - (1 << k) + 1][k][0]), s4 = std :: min(fn[l][k][1], fn[r - (1 << k) + 1][k][1]); 
		}
	} A, B;
	inline void mian() {
		n = read(), m = read(), q = read(), A.n = n, B.n = m; 
		lg[0] = -1; for(int i = 1; i <= std :: max(n, m); ++i) lg[i] = lg[i >> 1] + 1; 
		for(int i = 1; i <= n; ++i) A.a[i] = read(); 
		for(int i = 1; i <= m; ++i) B.a[i] = read(); 
		A.init(), B.init(); 
		while(q --) {
			int l1 = read(), r1 = read(), l2 = read(), r2 = read(); 
			A.Qry(l1, r1, b[0][0], b[0][1], b[0][2], b[0][3]); 
			B.Qry(l2, r2, b[1][0], b[1][1], b[1][2], b[1][3]); 
			ll ans = -1e18; 
			if(b[0][0] >= 0) {
				if(b[1][3] < 0) ans = std :: max(ans, (ll)b[0][1] * b[1][3]); 
			    else ans = std :: max(ans, (ll)b[0][0] * b[1][1]); 
			}
		    if(b[0][3] < 0) {
		    	if(b[1][0] >= 0) ans = std :: max(ans, (ll)b[1][0] * b[0][2]); 
		    	else ans = std :: max(ans, (ll)b[0][3] * b[1][2]); 
			}
			cout << ans << '\n'; 
		}
	}
} ; 

int main() 
{
    freopen("game.in", "r", stdin); 
    freopen("game.out", "w", stdout); 
    Solver :: mian(); 
    return 0; 
}
