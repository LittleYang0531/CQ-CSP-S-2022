#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1LL << 50;
constexpr i64 N = 2700;
constexpr i64 M = 10010;

i64 n, m, k;
i64 u, v;
i64 a[N];
struct Edge {
	i64 dis, nxt;
} edges[M << 1];
i64 head[N], siz;
void add(i64 from, i64 dis) {
	edges[++siz].dis = dis;
	edges[siz].nxt = head[from];
	head[from] = siz;
}
namespace subtask1 {
	i64 dis[N], vis[N], Vis[N];
	void dij() {
		std::priority_queue<std::pair<i64, i64> > q;
		q.push({0, 1});
		memset(dis, 0x3f, sizeof dis);
		dis[1] = 0;
		vis[1] = 1;
		while (q.size()) {
			i64 u = q.top().second;
			q.pop();
			for (i64 i = head[u]; i; i = edges[i].nxt) {
				i64 v = edges[i].dis;
				if (dis[u] + 1 < dis[v]) {
					dis[v] = dis[u] + 1;
					if (!vis[v]) {
						vis[v] = 1;
						q.push({-dis[v], v});
					}
				}
			}
		}
	}
	i64 dfs(i64 u, i64 uk, i64 ma, i64 is) {
		if (ma == 4) {
			if (dis[u] <= k + 1)
				return is;
			else
				return -1;
		}
	
		i64 ans= -inf;
		for (i64 i = head[u]; i; i = edges[i].nxt) {
			i64 v = edges[i].dis;
			if (uk + 1 <= k) ans = std::max(ans, dfs(v, uk + 1, ma, is));
			if (!Vis[v] && v != 1) {
				Vis[v] = 1;
				ans = std::max(ans, dfs(v, 0, ma + 1, is + a[v]));
				Vis[v] = 0;
			}
		}
		return ans;
	}
	void solve() {
		dij();
		std::cout << dfs(1, 0, 0, 0) << '\n';
		return;
	}
}

i64 f[5010][5010], vis[5010];
std::map<std::array<i64, 2>, i64> mp;

i64 dfs(i64 u, i64 ma, i64 is) {
	if (mp[{u, ma}]) {
		return mp[{u, ma}];
	}
	if (ma == 4) {
		return mp[{u, ma}] = is + a[u];
	}
	i64 ans = -(1LL << 60);
	for (i64 i = 2; i <= n; i++) {
		if (i != u && f[i][u] <= k + 1 && !vis[i]) {
			vis[i] = 1;
			ans = std::max(ans, dfs(i, ma + 1, is + a[u]));
			vis[i] = 0;
		}
	}
	return mp[{u, ma}] = ans;
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for (i64 i = 2; i <= n; i++) {
		scanf("%lld", a + i);
	}
	memset(f, 0x3f, sizeof f);
	for (i64 i = 1; i <= m; i++) {
		scanf("%lld%lld", &u, &v);
		add(u, v);
		add(v, u);
		f[u][v] = 1;
		f[v][u] = 1;
		f[i][i] = 0;
	}
	
//	if (n <= 10) {
//		subtask1::solve();
//		return 0;
//	}
	
	for (i64 k = 1; k <= n; k++) for (i64 i = 1; i <= n; i++) for (i64 j = 1; j <= n; j++)
		f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	
	printf("%lld\n", dfs(1, 0, 0));

	return 0;
}
