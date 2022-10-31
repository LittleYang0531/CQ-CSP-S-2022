#include <bits/stdc++.h>
#define fi first 
#define se second

using std :: cin; 
using std :: cout; 
using std :: vector; 

constexpr int M = 5e5 + 5; 
constexpr int INF = 0x3f3f3f3f; 

typedef long long ll; 
typedef unsigned long long ull;  
typedef double db; 
typedef std :: pair < int, int > pii; 

inline int read() {
	int f = 1, s = 0; char ch = getchar(); 
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar(); 
	while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar(); 
	return f * s; 
}

namespace Solver {
	int n, m, q; 
	std :: set < int > mp[M], rem[M]; 
	struct E {
		int u, v; 
	} edg[M]; 
	vector < pii > adj[M]; 
	int out[M], ans, tot; 
	inline void upd(int x, int t) {
	    ans -= out[x] == 1;
	    out[x] += t, tot += t; 
	    ans += out[x] == 1; 
	}
	inline void mian() {
		n = read(), m = read(); 
		for(int i = 1; i <= m; ++i) {
			int u = read(), v = read(); 
			mp[u].insert(v), upd(u, 1); 
			rem[v].insert(u); 
		    adj[v].push_back(pii(u, i)); 
		} 
		q = read(); 
		while(q --) {
			int op = read(), x = read(), y; 
			if(op == 1) {
				y = read(); 
				mp[x].erase(mp[x].find(y)), rem[y].erase(rem[y].find(x));  
				upd(x, -1); 
			}
			if(op == 2) {
			    for(auto &z : rem[x]) upd(z, -1), mp[z].erase(mp[z].find(x)); 
			    rem[x].clear(); 
			}
			if(op == 3) {
				y = read(); 
				mp[x].insert(y), rem[y].insert(x); 
				upd(x, 1);
			}
			if(op == 4) {
				for(pii &e : adj[x]) if(mp[e.fi].find(x) == mp[e.fi].end()) mp[e.fi].insert(x), upd(e.fi, 1), rem[x].insert(e.fi); 
			}
			puts((ans == n && tot == n) ? "YES" : "NO"); 
		}
	}
} ; 

int main() 
{
    freopen("galaxy.in", "r", stdin); 
    freopen("galaxy.out", "w", stdout); 
    Solver :: mian(); 
    return 0; 
}
