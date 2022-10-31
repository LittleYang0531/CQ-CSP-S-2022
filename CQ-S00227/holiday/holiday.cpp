#include <bits/stdc++.h>

using std :: cin; 
using std :: cout; 
using std :: vector; 

constexpr int M = 2505; 
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
	int n, m, k; 
	ll a[M]; bool vis[M]; 
	int dis[M][M]; 
	vector < int > adj[M], P[M];
	std :: queue < int > q; 
	inline void bfs(int t) {
		q.push(t), memset(vis, 0, sizeof(vis)), dis[t][t] = 0;
		while(!q.empty()) {
			int x = q.front(); q.pop(); 
			for(int &y : adj[x]) if(!vis[y]) vis[y] = 1, dis[t][y] = dis[t][x] + 1, q.push(y); 
		}
	}
	inline void mian() {
		n = read(), m = read(), k = read() + 1;   
		for(int i = 2; i <= n; ++i) scanf("%lld", &a[i]); 
		for(int i = 1; i <= m; ++i) {
			int u = read(), v = read(); 
			adj[u].push_back(v), adj[v].push_back(u); 
		}
		for(int i = 1; i <= n; ++i) bfs(i); 
		for(int i = 2; i <= n; ++i) {
		    for(int j = 2; j <= n; ++j) if(i != j && dis[i][j] <= k && dis[1][j] <= k) P[i].push_back(j); 
		    std :: sort(P[i].begin(), P[i].end(), [](int x, int y) {return a[x] > a[y];}); 
		}
		ll ans = 0; 
		for(int x = 2; x <= n; ++x) 
		    for(int y = x + 1; y <= n; ++y) {
		    	if(dis[x][y] > k) continue ; 
		    	const int s1 = P[x].size(), s2 = P[y].size(); 
		    	for(int i = 0; i <= std :: min(s1 - 1, 2); ++i) 
		    	    for(int j = 0; j <= std :: min(s2 - 1, 2); ++j) if(P[x][i] != y && P[y][j] != x && P[x][i] != P[y][j]) ans = std :: max(ans, a[x] + a[y] + a[P[x][i]] + a[P[y][j]]); 
			}
		cout << ans; 
	} 
} ; 

int main() 
{
    freopen("holiday.in", "r", stdin); 
    freopen("holiday.out", "w", stdout); 
    Solver :: mian(); 
    return 0; 
}
