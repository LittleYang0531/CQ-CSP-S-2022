#include<bits/stdc++.h>
using namespace std;

// WA(0) :(

bool vis[5005];
long long head[25005], to[25005], w[25005], nxt[25005], a[25005], ans;
int cnt, n, m, k;

void add(int u, int v, long long price) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	w[cnt] = price;
}

struct node {
	long long sc, trans, ans, step;
	node (long long _sc, long long _trans, long long _ans, long long _step) {
		sc = _sc, trans = _trans, ans = _ans, step = _step;
	}
};


int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		add(c1, c2, a[c2]);
		add(c2, c1, a[c1]);
	}
	queue<node> q;
	q.push(node(1, 0, 0, 1));
	while (!q.empty()) {
		node p = q.front();
		if (p.trans == k) {
			if (p.step != 4) {
				// get to the sc
				long long mx = 0;
				for (int i = head[p.sc]; i; i = nxt[i]) {
					mx = max(mx, w[i]);
				}
				for (int i = head[p.sc]; i; i = nxt[i]) {
					if (w[i] == mx) q.push(node(to[i], 0, ans + mx, p.step + 1));
				}
			}
			else {
				long long mx = 0;
				for (int i = head[p.sc]; i; i = nxt[i]) {
					mx = max(mx, w[i]);
				}
				ans = max(ans, mx + p.ans);
			}
		}
		else {
			for (int i = head[p.sc]; i; i = nxt[i]) {
				int v = to[i];
				q.push(node(v, p.trans + 1, ans, p.step));
			}
		}
	}
	cout << ans;
	return 0;
}

