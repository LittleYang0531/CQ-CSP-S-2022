#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int M = 2e4 + 5;
const int N = 3e3 + 5;
#define ll long long
int n, m, k, head[N], nxt[M], to[M], cnt;
ll dis[N][N], dp[N][10], pre[N][10][10], a[N], ans;
bool vis[N], f[N];
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
void dijkstra(int s) {
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
struct node2 {
	ll dis;
	int id, c;
};
queue<node2> q2;
void SPFA() {
	q2.push((node2){0, 1, 0});
	while(!q2.empty()) {
		int u = q2.front().id, c = q2.front().c;
		q2.pop();
		if(c == 4) continue;
		for(int i = 2; i <= n; i++) {
			if(i == u) continue;
			if(dis[u][i] > k + 1) continue;
			bool flag = true;
			for(int j = 1; j < c; j++) {
				if(i == pre[u][c][j]) {
					flag = false;
					break;
				}
			}
			if(!flag) continue;
			if(dp[i][c + 1] < dp[u][c] + a[i]) {
				dp[i][c + 1] = dp[u][c] + a[i];
				for(int j = 1; j < c; j++) pre[i][c + 1][j] = pre[u][c][j];
				pre[i][c + 1][c] = u;
				q2.push((node2){dp[i][c + 1], i, c + 1});
			}
		}
	}
}
void dfs(int step, int p, ll sum) {
	if(step == 5) {
		if(dis[p][1] > k + 1) return;
		ans = max(ans, sum);
		return;
	}
	for(int i = 2; i <= n; i++) {
		if(!f[i] && dis[p][i] <= k + 1) {
			f[i] = true;
			dfs(step + 1, i, sum + a[i]);
			f[i] = false;
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n), read(m), read(k);
	for(int i = 2; i <= n; i++) {
		read(a[i]);
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		read(u), read(v);
		add(u, v);
		add(v, u);
	}
	for(int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	if(n <= 100) {
		dfs(1, 1, 0);
		printf("%lld", ans);
	}
	else {
		SPFA();
		for(int i = 2; i <= n; i++) {
			if(dis[i][1] > k + 1) continue;
			if(dp[i][4] > ans) ans = dp[i][4];
		}
		printf("%lld", ans);
	}
	return 0;
}
