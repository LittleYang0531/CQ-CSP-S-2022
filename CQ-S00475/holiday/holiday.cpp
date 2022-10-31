#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

void read(int& num) {
	num = 0;
	int g = 1;
	char x = getchar();
	while (x < '0' || x > '9') g = (x == '-' ? -1 : g), x = getchar();
	while (x >= '0' && x <= '9') num = (num << 1) + (num << 3) + (x ^ 48), x = getchar();
	num *= g;
}

int n, m, k, d[2505], to[20005], nxt[20005], head[2505], cnt, _to[6100005], _nxt[6100005], _head[2505], _cnt;
bool vis[2505];
int fg, ans;
struct node {
	int id, s;
};

void Add(int u, int v) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
void adi(int x, int y) {
	_nxt[++ _cnt] = _head[x];
	_head[x] = _cnt;
	_to[_cnt] = y;
}
void bfs() {
	queue<node> q;
	q.push((node) {fg, -1});
	while (q.size()) {
		node t = q.front();
		q.pop();
		if (t.s > k) continue;
		if (~ t.s) adi(fg, t.id);
		for (int i = head[t.id]; i; i = nxt[i]) if (!vis[to[i]]) {
			vis[to[i]] = 1;
			q.push((node) {to[i], t.s + 1});
		}
	}
}
void dfs(int now, int sum, int res) {
	if (sum == 4) {
		for (int i = _head[now]; i; i = _nxt[i]) {
			if (_to[i] == 1) {
				ans = max(ans, res);
				return;
			}
		}
		return;
	}
	for (int i = _head[now]; i; i = _nxt[i]) if (!vis[_to[i]]) {
		vis[_to[i]] = 1;
		dfs(_to[i], sum + 1, res + d[_to[i]]);
		vis[_to[i]] = 0;
	}
}

signed main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 2; i <= n; i++) read(d[i]);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		Add(u, v);
		Add(v, u);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) vis[j] = 0;
		vis[i] = 1;
		fg = i;
		bfs();
	}
	for (int i = 1; i <= n; i++) vis[i] = 0;
	vis[1] = 1;
	dfs(1, 0, 0);
	printf("%lld", ans);
	return 0;
}
