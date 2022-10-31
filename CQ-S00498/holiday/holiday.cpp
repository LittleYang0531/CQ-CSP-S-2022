#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define U unsigned long long
const int N = 2510, M = 2e4 + 10;
void read(int &x) {
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') f |= c == '-', c = getchar();
	x = 0;
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	x = f ? -x : x;
}
void read1(U &x) {
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') f |= c == '-', c = getchar();
	x = 0;
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	x = f ? -x : x;
}

U ans, ans1, score[N];
int n, m, k, cnt, dis[N][N], a[5];
int head[N], ver[M], nxt[M], edge[M];
bool vis[N], v[5];

void add(int u, int v, int w) {
	ver[++cnt] = v;
	nxt[cnt] = head[u];
	edge[cnt] = w;
	head[u] = cnt;
}

struct node {
	int val, id;
	node (int x, int y) {
		val = x, id = y;
	}
};
priority_queue<node> q; 
priority_queue<int> p;
bool operator<(node x, node y) {
	return x.val > y.val;
}
void dijkstra(int s) {
	memset(vis, 0, sizeof vis);
	dis[s][s] = 0;
	while (q.size()) q.pop();
	q.push(node(0, s));
	while (q.size()) {
		int u = q.top().id;
		q.pop();
		if (vis[u]) 
			continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = ver[i], w = dis[s][u] + edge[i];
			if (dis[s][v] > w)
				dis[s][v] = w, q.push(node(dis[s][v], v));
		}
	}
}

void dfs(int step) {
	if (step == 5) {
		if (dis[a[4]][1] <= k + 1) {
			U sum = 0;
			for (int i = 1; i <= 4; i++) {
				sum += score[a[i]];
			}
			ans = max(ans, sum);
		}
		return;
	}
	for (int i = 2; i <= n; i++) {
		if (!v[i] && step == 1 && dis[1][i] <= k + 1) {
			a[step] = i;
			v[i] = 1, dfs(step + 1), v[i] = 0; //
		} else if (!v[i] && dis[a[step - 1]][i] <= k + 1 && dis[i][1] <= (k + 1) * (4 - step + 1)) {
			a[step] = i;
			v[i] = 1, dfs(step + 1), v[i] = 0;
		}
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 2; i <= n; i++) 
		read1(score[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u), read(v);
		add(u, v, 1), add(v, u, 1);
	} 
	memset(dis, 127, sizeof dis);
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	dfs(1);
	printf("%llu", ans);
	
	return 0;
}


