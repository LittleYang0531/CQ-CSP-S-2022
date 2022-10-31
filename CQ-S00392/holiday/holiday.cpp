#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
const int maxn = 2505;
const int inf = 1e9;
int n, m, k, dis[maxn], vis[maxn], id[maxn];
pair<ll, int> a[maxn];
vector<int> e[maxn];
bitset<maxn> g[maxn], t1, t2;
bool cmp(const pair<ll, int> &x, const pair<ll, int> &y) {
	return x.fi > y.fi;
}
void dijkstra(int s) {
	for(int i = 1; i <= n; i++) {
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[s] = 0;
	priority_queue<pair<int, int>> q;
	q.emplace(0, s);
	while(!q.empty()) {
		int u = q.top().se;
		q.pop();
		if(vis[u]) {
			continue;
		}
		vis[u] = 1;
		for(int v : e[u]) {
			if(dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				q.emplace(-dis[v], v);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(dis[i] <= k + 1 && s != i) {
			g[s][i] = 1;
		}
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 2; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 2, a + 1 + n, cmp);
	id[1] = 1;
	for(int i = 2; i <= n; i++) {
		id[a[i].se] = i;
	}
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		e[id[u]].pb(id[v]);
		e[id[v]].pb(id[u]);
	}
	for(int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	ll ans = 0;
	for(int i = 2; i <= n; i++) {
		if(!g[1][i]) {
			continue;
		}
		for(int j = 2; j <= n; j++) {
			if(i == j) {
				continue;
			}
			t1 = g[1] & g[j];
			t2 = g[i] & g[j];
			t1[i] = t1[j] = t1[1] = 0;
			t2[i] = t2[j] = t2[1] = 0;
			int p1 = t1._Find_first(), q1 = t2._Find_first(), p2 = n + 1, q2 = n + 1;
			if(p1 <= n) {
				t1[p1] = 0;
				p2 = t1._Find_first();
			}
			if(q1 <= n) {
				t2[q1] = 0;
				q2 = t2._Find_first();
			}
			if(p1 <= n && q1 <= n && p1 != q1) {
				ans = max(ans, a[i].fi + a[j].fi + a[p1].fi + a[q1].fi);
			}
			if(p1 <= n && q2 <= n && p1 != q2) {
				ans = max(ans, a[i].fi + a[j].fi + a[p1].fi + a[q2].fi);
			}
			if(p2 <= n && q1 <= n && p2 != q1) {
				ans = max(ans, a[i].fi + a[j].fi + a[p2].fi + a[q1].fi);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

