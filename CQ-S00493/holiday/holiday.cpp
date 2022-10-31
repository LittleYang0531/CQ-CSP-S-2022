#include <cstdio>
#include <queue>
#include <bitset>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 2505, MAXM = 20005;
const ll INF = 1e18;
int n, m, k;
ll a[MAXN], t[MAXN];
int head[MAXN], ver[MAXM], nxt[MAXM], tot;
ll dis[MAXN][MAXN];
bool vis[MAXN];
queue<int> q;
void add(int u, int v) {
	nxt[++tot] = head[u], head[u] = tot, ver[tot] = v;
}
void bfs(int s) {
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	dis[s][s] = 0;
	q.push(s);
	while (q.size()) {
		int u = q.front();
		q.pop();
		vis[u] = 1;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = ver[i];
			if (!vis[v]) {
				vis[v] = 1;
				dis[v][s] = dis[s][v] = dis[s][u] + 1;
				q.push(v);
			}
		}
	}
}
template <typename _Tp>inline void read(_Tp& x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar(); 
	}
	x *= f;
}
ll ans, maxv;
ll pre[MAXN];
void dfs(int u, int cnt, ll now) {
	if (pre[4 - cnt] + now <= ans)
		return ;
	if (cnt == 4) {
		if (dis[u][1] - 1 <= k)
			ans = max(ans, now);
		return ;
	}
	for (int i = 2; i <= n; i++)
		if (!vis[i]) {
			vis[i] = 1;
			if (dis[u][i] - 1 <= k)
				dfs(i, cnt + 1, now + a[i]);
			vis[i] = 0;
		}
}
bool cmp(ll x, ll y) {
	return x > y;
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 2; i <= n; i++)
		read(a[i]), maxv = max(maxv, a[i]), t[i] = a[i];
	sort(t + 1, t + n + 1, cmp);
	for (int i = 1; i <= 4; i++)
		pre[i] = pre[i - 1] + t[i];
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u), read(v);
		add(u, v), add(v, u);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = INF;
	for (int i = 1; i <= n; i++)
		bfs(i);
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	dfs(1, 0, 0);
	printf("%lld", ans);
	return 0;
}
