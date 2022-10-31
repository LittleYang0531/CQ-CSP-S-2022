#include<bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(x) begin(x), end(x)
#define int long long

using namespace std;

const int N = 2e5 + 5, LOG = 21, inf = 1e16;
int n, q, K, a[N];
int head[N], nex[N << 1], e[N << 1], tot = 1;
int dep[N], dis[N], fa[N][LOG];

void add(int x, int y) {
	nex[++tot] = head[x];
	head[x] = tot;
	e[tot] = y;
}

void dfs(int x, int f) {
	fa[x][0] = f;
	for(int i = 1; i < LOG; ++i) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	dep[x] = dep[f] + 1;
	dis[x] = dis[f] + a[x];
	for(int i = head[x]; i; i = nex[i]) {
		int y = e[i];
		if(y == f) continue;
		dfs(y, x);
	}
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = LOG - 1; i >= 0; --i) {
		if(dep[fa[x][i]] >= dep[y]) {
			x = fa[x][i];
			if(x == y) return x;
		}
	}
	for(int i = LOG - 1; i >= 0; --i) {
		if(fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}

int dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}

signed main() {
	File("transmit");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q >> K;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	if(K == 1) {
		while(q--) {
			int s, t;
			cin >> s >> t;
			int lca = LCA(s, t);
			cout << dis[s] + dis[t] - dis[lca] - dis[fa[lca][0]] << "\n";
		}
	} else {
		vector<vector<int>> reach(n + 1);
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				if(dist(i, j) <= K) {
					reach[i].push_back(j);
					reach[j].push_back(i);
				}
			}
		}
		while(q--) {
			int s, t;
			cin >> s >> t;
			queue<int> q;
			q.push(s);
			vector<int> f(n + 1, inf), vis(n + 1, 0);
			f[s] = a[s];
			vis[s] = 1;
			while(!q.empty()) {
				int x = q.front();
				q.pop();
				for(auto y : reach[x]) {
					if(vis[y] && dist(x, y) <= K) {
						f[x] = min(f[x], f[y] + a[x]);
					}
				}
				if(x == t) {
					break;
				}
				for(int i = head[x]; i; i = nex[i]) {
					int y = e[i];
					if(!vis[y]) {
						q.push(y);
						vis[y] = 1;
					}
				}
			}
			cout << f[t] << "\n";
		}
	}
	return 0;
}
/*
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606

479806606 51944511 835701672 912572995 368308854 251245604

939363946
731052210
*/
