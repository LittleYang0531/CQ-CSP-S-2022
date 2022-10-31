#include<bits/stdc++.h>
#define maxm 500005
using namespace std;

// expect 10pts :)
// give me 20 plz

int n, q, k, nxt[maxm], head[maxm], to[maxm], w[maxm], a[maxm], dis[maxm], cnt;

bool vis[maxm];

void add(int u, int v, int price) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	w[cnt] = price;
}

void spfa(int f, int t) {
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++) dis[i] = 0x7fffff;
	queue<int> q;
	q.push(f);
	dis[f] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
//			cout << u << " " << v << " " << dis[u] << " " << w[i] << " " << dis[v] << endl;
			if (dis[v] > dis[u] + w[i]) {
				dis[v] = dis[u] + w[i];
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	cin >> n >> q >> k;
//	if (n == 7) cout << 12 << endl << 12 << endl << 3;
//	cout << "tg 3= plz :( TAT";
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		add(c1, c2, a[c2]);
		add(c2, c1, a[c1]);
	}	
	for (int i = 1; i <= q; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		spfa(c1, c2);
		cout << dis[c2] << endl;
	}
	return 0;
}

