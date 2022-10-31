#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= (int)n; ++i)
#define rep2(i, j, n) for (int i(j); i >= (int)n; --i)
#define int long long
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) f -= (ch == '-') << 1, ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
	x *= f;
}
inline int read() {int x; read(x); return x;}
template <typename T, typename ...L> inline void read(T &x, L &...y) {read(x); read(y...);}
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int n, q, k, head[N], nex[N << 1], tot;
int val[N];
struct E {int to, nxt;} edge[N << 1];
inline void add(int x, int y) {edge[++tot] = (E) {x, y}; nex[tot] = head[x]; head[x] = tot;}
bool vis[N];
int dis[N];
vector <int> G[N];
inline void build(int root) {
	queue <pair <int, int> > q;
	q.push(make_pair(root, 0));
	memset(vis, 0, sizeof vis);
	vis[root] = 1;
	while (!q.empty()) {
		int u = q.front().first, w = q.front().second; q.pop();
		G[root].push_back(u);
		if (w == k) continue;
		for (int i = head[u]; i; i = nex[i]) {
			int v = edge[i].nxt;
			if (vis[v]) continue;
			vis[v] = 1;
			q.push(make_pair(v, w + 1));
		}
	}
}
inline int dijkstra(int s, int t) {
	priority_queue <pair <int, int> > q;
	rep1(i, 1, n) dis[i] = LLONG_MAX;
	memset(vis, 0, sizeof vis);
	dis[s] = val[s];
	q.push(make_pair(-dis[s], s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (auto v : G[u]) {
			if (dis[v] > dis[u] + val[v]) {
				dis[v] = dis[u] + val[v];
				q.push(make_pair(-dis[v], v));
			}
		}
	}
	return dis[t];
}
signed main(void) {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n, q, k);
	rep1(i, 1, n) read(val[i]);
	rep1(i, 1, n - 1) {
		int u = read(), v = read();
		add(v, u); add(u, v);
	}
	rep1(i, 1, n) build(i);
	while (q--) {
		int s = read(), t = read();
		printf("%lld\n", dijkstra(s, t));
	}
}
/*
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
*/
