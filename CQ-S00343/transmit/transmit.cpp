#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5; 

//char buf[1 << 23], *p1 = buf, *p2 = buf;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-')  w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
}

int val[N], s[N], t[N];
vector<int> Edge[N]; 
vector<int> can[N];
int dis[2006][2006], ans[2006][2006];
int n, q, k;
bool vis[2006];

void BF() {
	memset(dis, -1, sizeof(dis));
	for(int i = 1; i <= n; ++ i) {
		queue<int> q;
		dis[i][i] = 0, q.push(i);
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int j = 0, v; j < (int)Edge[u].size(); ++ j) 
				if(dis[i][v = Edge[u][j]] == -1)
					dis[i][v] = dis[i][u] + 1, q.push(v);
		}
	}
	
	for(int i = 1; i <= n; ++ i)	
		for(int j = 1; j <= n; ++ j)
			if(i ^ j && dis[i][j] <= k)
				can[i].push_back(j);
	
	memset(ans, 127, sizeof(ans));
//	cout << ans[1][1] << endl;
	for(int i = 1; i <= n; ++ i) {
		memset(vis, 0, sizeof(vis));
		priority_queue<pii, vector<pii>, greater<pii> > q;
		q.push(pii(0, i)), ans[i][i] = val[i];
		while(q.size()) {
			int u = q.top().se; q.pop();
			if(vis[u]) continue; vis[u] = 1;
			for(int j = 0, v; j < (int)can[u].size(); ++ j) {
				v = can[u][j];
				if(ans[i][v] > ans[i][u] + val[v])
					ans[i][v] = ans[i][u] + val[v],
					q.push(pii(ans[i][v], v));
			}
		}
	}
	
	for(int i = 1; i <= q; ++ i) 
		printf("%lld\n", ans[s[i]][t[i]]);
}

int siz[N], son[N], dep[N], f[N], top[N], sum[N];
void dfs1(int u) {
	for(int i = 0; i < (int)Edge[u].size(); ++ i) {
		int v = Edge[u][i];
		if(v == f[u]) continue;
		sum[v] = sum[u] + val[v];
		dep[v] = dep[f[v] = u] + (siz[v] = 1), dfs1(v);
		siz[u] += siz[v], (siz[v] > siz[son[u]] && (son[u] = v, 1));
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	if(son[u]) dfs2(son[u], tp);
	for(int i = 0; i < (int)Edge[u].size(); ++ i) {
		int v = Edge[u][i];
		if(v ^ f[u] && v ^ son[u])
			dfs2(v, v);
	}
}
int lca(int u, int v) {
	while(top[u] ^ top[v])
		dep[top[u]] < dep[top[v]] ? v = f[top[v]] : u = f[top[u]];
	return dep[u] < dep[v] ? u : v;
}
int ask(int u, int v ) {
	int l = lca(u, v);
	return sum[u] + sum[v] - sum[l] - sum[f[l]];
}
void SP1() {
	sum[1] = val[1], dfs1(siz[1] = 1), dfs2(1, 1);
	for(int i = 1; i <= q; ++ i)
		printf("%lld\n", ask(s[i], t[i]));
}

int dp[N][3], mn[N][3], up[N][3], pre[N][3], suf[N][3], bfn[N], st[N], ed[N];

void bfs() {
	int tim = 0;
	queue<int>q; q.push(1), bfn[1] = tim = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < (int)Edge[u].size(); ++ i) {
			int v = Edge[u][i];
			if(bfn[v]) continue;
			bfn[v] = ++ tim, q.push(v);
			if(st[u] == 0) st[u] = tim;
			ed[u] = tim;
		}
	}
}

void dfs3(int u) {
	mn[u][0] = up[N][0] = val[u];
	for(int i = 0; i < (int)Edge[u].size(); ++ i) {
		int v = Edge[u][i];
		if(v == f[u]) continue;
		dfs3(v);
		mn[u][1] = min(mn[u][1], mn[v][0]);
		mn[u][2] = min(mn[u][2], mn[v][1]);
		pre[bfn[v]][1] = mn[u][1];
		pre[bfn[v]][2] = mn[u][2];
	}
	int mn1 = 1e18, mn2 = 1e18;
	reverse(Edge[u].begin(), Edge[u].end());
	for(int i = 0; i < (int)Edge[u].size(); ++ i) {
		int v = Edge[u][i];
		if(v == f[u]) continue;
		mn1 = min(mn1, mn[v][0]);
		mn2 = min(mn2, mn[v][1]);
		suf[bfn[v]][1] = mn1;
		suf[bfn[v]][2] = mn2;
	}
}
void dfs4(int u) {
	for(int i = 0; i < (int)Edge[u].size(); ++ i) {
		int v = Edge[u][i];
		if(v == f[u]) continue;
		int mn = 1e18;
		if(bfn[v] != st[u]) mn = min(mn, pre[bfn[v] - 1][1]);
		if(bfn[v] != ed[u]) mn = min(mn, suf[bfn[v] + 1][1]);
 		up[v][2] = min(up[u][1], mn);
		up[v][1] = val[u];
		
		dfs4(v);
	}
}

int calc(int u, int b1, int b2, int d) {
	if(d == 0) return val[u];
//	cout << u << " " << d << endl;
	bool fg1 = (f[b1] == u);
	bool fg2 = (f[b2] == u);
	if(fg1 && fg2) {
		int mn = up[u][d];
		if(d == 1) {
			for(int i = 0; i < (int)Edge[u].size(); ++ i) {
				int v = Edge[u][i];
				if(v == f[u] || v == b1 || v == b2) continue;
				mn = min(mn, val[v]);
			}
		} else {
			for(int i = 0; i < (int)Edge[u].size(); ++ i) {
				int v = Edge[u][i];
				if(v == f[u] || v == b1 || v == b2) continue;
				for(int i = 0; i < (int)Edge[v].size(); ++ i) {
					int w = Edge[u][i];
					if(w == f[v]) continue;
					mn = min(mn, val[w]);
				}
			}
		}
		return mn;
	}
	else {
		int v = (fg1 ? b1 : b2), mn = 1e18;
		if(bfn[v] != st[u]) mn = min(mn, pre[bfn[v] - 1][d]);
		if(bfn[v] != ed[u]) mn = min(mn, suf[bfn[v] + 1][d]);
		return mn;
	} 
}

int solve(vector<int> a) {
	int V = a.size();
	for(int i = 1; i <= V; ++ i) 
		for(int j = 0; j <= 2; ++ j) dp[i][j] = 1e18;
//	for(int i = 0; i < (int)a.size(); ++ i)
//		cout << a[i] << " "; puts(""); 
	a.push_back(0);
	dp[1][0] = val[a[0]], dp[1][1] = mn[a[0]][1], dp[1][2] = mn[a[0]][2];
	for(int i = 1; i < V; ++ i) 
		for(int d = 0; d <= 2; ++ d)
			for(int j = 1; d + j <= k && i + j <= V; ++ j)
				for(int now = 0; now <= 2; ++ now)  if(d + now + j <= k)
					dp[i + j][now] = min(dp[i + j][now], dp[i][d] + calc(a[i + j - 2], a[i + j - 1], a[i + j], now));
	return dp[V][0];
}
void BF2() {
	for(int i = 1; i <= n; ++ i) for(int j = 0; j <= 2; ++ j) 
		mn[i][j] = up[i][j] = pre[i][j] = suf[i][j] = 1e18;
	bfs(), sum[1] = val[1], dfs1(siz[1] = 1), dfs2(1, 1), dfs3(1), dfs4(1);
	
	for(int i = 1; i <= q; ++ i) {
		int u = s[i], v = t[i], l = lca(s[i], t[i]);
		vector<int> a, b;
		while(u != l) a.push_back(u), u = f[u];
		while(v != l) b.push_back(v), v = f[v];
		reverse(b.begin(), b.end());
		a.push_back(l);
		for(int j = 0; j < (int)b.size(); ++ j)
			a.push_back(b[j]);
		printf("%lld\n", solve(a)); 
	}
}

signed main() {
	file();
//	freopen("transmit1.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
	n = read(), q = read(), k = read();
	for(int i = 1; i <= n; ++ i) val[i] = read();
	for(int i = 1, u, v; i < n; ++ i)
		u = read(), v = read(),
		Edge[u].push_back(v),
		Edge[v].push_back(u);
	for(int i = 1; i <= q; ++ i)
		s[i] = read(), t[i] = read();
		
	if(n <= 2000 && q <= 2000) return BF(), 0;
	if(k == 1) return SP1(), 0;
	BF2(); 
	return 0;
}
