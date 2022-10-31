#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int M = 1e3 + 5;
const int N = 1e3 + 5;
#define ll long long
int n, Q, k, head[N], nxt[M], to[M], cnt;
ll dis[N][N], dp[N], a[N], ans;
bool vis[N];
template <class T>
void read(T &x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ '0');
		ch = getchar();
	}
	x *= f;
}
void add(int u, int v) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
struct node {
	ll dis;
	int id;
	bool operator<(node a)const {
		return dis > a.dis;
	}
};
priority_queue<node> q;
void dijkstra1(int s) {
	for(int i = 1; i <= n; i++) dis[s][i] = 0x3f3f3f3f3f3f3f3f, vis[i] = false;
	dis[s][s] = 0;
	q.push((node){0, s});
	while(!q.empty()) {
		int u = q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if(dis[s][v] > dis[s][u] + 1) {
				dis[s][v] = dis[s][u] + 1;
				q.push((node){dis[s][v], v});
			}
		}
	}
}
ll dijkstra2(int s, int t) {
	for(int i = 1; i <= n; i++) dp[i] = 0x3f3f3f3f3f3f3f3f, vis[i] = false;
	dp[s] = a[s];
	q.push((node){a[s], s});
	while(!q.empty()) {
		int u = q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if(dis[u][v] > k) continue;
			if(dp[v] > dp[u] + a[v]) {
				dp[v] = dp[u] + a[v];
				q.push((node){dp[v], v});
			}
		}
	}
	return dp[t];
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n), read(Q), read(k);
	for(int i = 1; i <= n; i++) {
		read(a[i]);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		read(u), read(v);
		add(u, v);
		add(v, u);
	}
	for(int i = 1; i <= n; i++) {
		dijkstra1(i);
	}
	while(Q--) {
		int s, t;
		read(s), read(t);
		printf("%lld\n", dijkstra2(s, t));
	}
	return 0;
}

