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
const int N = 2e5 + 10, INF = 1e16;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
struct node{
	int v, p;
	bool operator < (const node &x) const { return v > x.v; }
};
int n, Q, k, cnt;
int id[N], up[N], siz[N], son[N], dfn[N], top[N], out[N], dep[N];
int a[N], dis[N], sum[N];
bool vis[N];
vector<int> G[N], T[N];
inline void DFS(int u, int fa)
{
	siz[u] = 1, up[u] = fa, dep[u] = dep[fa] + 1;
	for(re int to : G[u]){
		if(to == fa) continue;
		DFS(to, u), siz[u] += siz[to];
		if(siz[to] > siz[son[u]]) son[u] = to;
	}
}
inline void Pre(int u, int tp){
	dfn[u] = ++cnt, id[cnt] = u, top[u] = tp;
	if(son[u]) Pre(son[u], tp);
	for(re int to : G[u])
		if(to != up[u] && to != son[u]) Pre(to, to);
	out[u] = cnt;
}
inline int query(int x, int y)
{
	int res = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		res = res + sum[dfn[x]] - sum[dfn[top[x]] - 1], x = up[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	return res + sum[dfn[x]] - sum[dfn[y] - 1];
}
priority_queue<node> q;
inline void build(int u, int fa, int rt, int dep)
{
	if(dep > k) return;
	if(u != rt) T[rt].pb(u);
	for(re int to : G[u])
		if(to != fa) build(to, u, rt, dep + 1);
}
signed main() //52pts
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	n = read(), Q = read(), k = read();
	for(re int i = 1; i <= n; i++) a[i] = read();
	for(re int i = 1, x, y; i < n; i++)
		x = read(), y = read(), G[x].pb(y), G[y].pb(x);
	DFS(1, 0), Pre(1, 1);
	for(re int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[id[i]]; 
	if(k > 1){
		for(re int u = 1; u <= n; u++) build(u, 0, u, 0);
	}
	while(Q--){
		int s = read(), t = read();
		if(k == 1) printf("%lld\n", query(s, t));
		else{
			for(re int i = 1; i <= n; i++)
				dis[i] = INF, vis[i] = false;
			while(!q.empty()) q.pop();
			q.push((node){a[s], s}), dis[s] = a[s];
			while(!q.empty()){
				node u = q.top(); q.pop();
				if(vis[u.p]) continue;
				if(u.p == t) break;
				for(re int to : T[u.p])
					if(u.v + a[to] < dis[to])
						dis[to] = u.v + a[to], q.push((node){dis[to], to});
			}
			printf("%lld\n", dis[t]);
		}
	} 
	return 0;
}
