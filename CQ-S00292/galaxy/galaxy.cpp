#include <bits/stdc++.h>
#define st first
#define nd second
#define db double
#define re register
#define pb push_back
#define mk make_pair
#define int long long
#define ull unsigned long long
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;
const int N = 1e3 + 10, INF = 1e9;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
int n, m, q, cnt, tot;
int dfn[N], low[N], tag[N];
stack<int> s;
vector<int> G[N], T[N], vec[N];
bool vis[N], del[N][N], rev[N][N];
inline void Tarjan(int u)
{
	low[u] = dfn[u] = ++cnt, vis[u] = true, s.push(u);
	for(re int to : G[u]){
		if(del[u][to]) continue; //±ß±»É¾³ý
		if(!dfn[to]) Tarjan(to), low[u] = min(low[u], low[to]);
		else if(vis[to]) low[u] = min(low[u], dfn[to]); 
	}
	if(low[u] == dfn[u]){
		int x, id = ++tot;
		do x = s.top(), s.pop(), vis[x] = false, vec[id].pb(x);
		while(x != u);
	}
}
inline void Sol(int u)
{
	tag[u] = 1;
	for(re int to : T[u])
		if(!rev[u][to] && !tag[to]) Sol(to);
}
signed main() //40pts 
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	n = read(), m = read();
	for(re int i = 1, x, y; i <= m; i++)
		x = read(), y = read(), G[x].pb(y), T[y].pb(x);
	q = read();
	while(q--){
		int op = read(), x = read(), y;
		if(op == 1) y = read(), del[x][y] = true, rev[y][x] = true;
		if(op == 2){
			for(re int to : T[x]) del[to][x] = true, rev[x][to] = true;
		}
		if(op == 3) y = read(), del[x][y] = false, rev[y][x] = false;
		if(op == 4){
			for(re int to : T[x]) del[to][x] = false, rev[x][to] = false;
		}
		bool flag = true;
		for(re int u = 1; u <= n; u++){
			int cnt = 0;
			for(re int to : G[u]) if(!del[u][to]) cnt += 1;
			if(cnt != 1) flag = false;
		}
		if(!flag) { puts("NO"); continue; }
		for(re int i = 1; i <= tot; i++) vec[i].clear();
		cnt = tot = 0;
		for(re int u = 1; u <= n; u++) low[u] = dfn[u] = tag[u] = 0;
		for(re int u = 1; u <= n; u++) if(!dfn[u]) Tarjan(u);
		for(re int i = 1; i <= tot; i++){
			if(vec[i].size() == 1) continue;
			for(re int x : vec[i]) Sol(x);
		}
		for(re int u = 1; u <= n; u++) if(!tag[u]) flag = false;
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
