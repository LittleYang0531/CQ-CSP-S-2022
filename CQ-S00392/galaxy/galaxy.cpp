#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
const int maxn = 5e5 + 5;
int n, m, q;
vector<int> e[maxn];
namespace sub1 {
	vector<int> ne[maxn];
	int pa[maxn], vis[maxn], ans;
	int find(int x) {
		return x == pa[x] ? x : pa[x] = find(pa[x]);
	}
	bool merge(int u, int v) {
		// u ---> v
		if(!ans) {
			return 0;
		}
		int U = u;
		u = find(u), v = find(v);
		if(u == v) {
			if(vis[u]) {
				return 0;
			}
			if(u == U) {
				pa[u] = v;
				vis[v] = 1;
				return 1;
			}
			return 0;
		}
		if(vis[u] && vis[v]) {
			return 0;
		}
		if(!vis[u] && !vis[v]) {
			if(u == U) {
				pa[u] = v;
				return 1;
			}
			return 0;
		}
		if(vis[u]) {
			return 0;
		}
		if(u == U) {
			pa[u] = v;
			return 1;
		}
		return 0;
	}
	void solve() {
		for(int i = 1; i <= n; i++) {
			sort(e[i].begin(), e[i].end());
			ne[i] = e[i];
		}
		for(int t = 1; t <= q; t++) {
			int o, u, v;
			cin >> o >> u;
			if(o == 1) {
				cin >> v;
				ne[v].erase(lower_bound(ne[v].begin(), ne[v].end(), u));
			}
			if(o == 2) {
				ne[u].clear();
			}
			if(o == 3) {
				cin >> v;
				ne[v].insert(lower_bound(ne[v].begin(), ne[v].end(), u), u);
			}
			if(o == 4) {
				ne[u] = e[u];
			}
			ans = 1;
			for(int i = 1; i <= n; i++) {
				pa[i] = i;
				vis[i] = 0;
			}
			for(int u = 1; u <= n; u++) {
				for(int v : ne[u]) {
					ans &= merge(v, u);
					if(ans == 0) {
						break;
					}
				}
				if(ans == 0) {
					break;
				}
			}
			for(int i = 1; i <= n; i++) {
				if(i == find(i) && !vis[i]) {
					ans = 0;
					break;
				}
			}
			if(ans) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		e[v].pb(u);
	}
	cin >> q;
	sub1::solve();
	return 0;
}

