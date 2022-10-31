#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//int lowbit(int x) { return x & -x; }
const int Maxn = 4e5 + 5;
inline int read() {
	int sum = 0, f = 1;
	char ch = getchar();
	while(ch < '0' or ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar(); 
	}
	while(ch >= '0' and ch <= '9') {
		sum = sum * 10 + ch - '0';
		ch = getchar();
	}
	return sum * f;
}
int n, q, k, a[Maxn], dis[Maxn];
vector <int> G[Maxn];
bool vis[Maxn];
struct node {
	ll v;
	int id;
	friend bool operator < (node a, node b) { return a.v > b.v; }
};
ll dijkstra(int id, int en) {
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	dis[id] = a[id];
	priority_queue <node> q;
	q.push((node){dis[id], id});
	while(!q.empty()) {
		int p = q.top().id;
		q.pop();
		if(vis[p]) continue;
		vis[p] = 1;
		for(int i = 0;i < G[p].size(); ++i) {
			int to = G[p][i];
			if(dis[to] > dis[p] + a[to]) {
				dis[to] = dis[p] + a[to];
				q.push((node){dis[to], to});
			}
		}
	}
	return dis[en];
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	n = read(), q = read(), k = read();
	for(int i = 1;i <= n; ++i) a[i] = read();
	for(int i = 1, x, y;i < n; ++i) {
		x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	while(q--) {
		int x = read(), y = read();
		if(k == 1) printf("%lld\n", dijkstra(x, y));
	}
	return 0;
}
// 6~7 k=1 8pts 
