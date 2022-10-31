#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define SF scanf
#define PF printf
struct Edge {
	int to, next;
}edge[4005];
struct node {
	int id, dis;
	bool operator < (const node &x) const {
		return dis > x.dis; 
	}
};
int head[4005], cnt, n, k, dis[2005][2005], up, vp;
long long a[2005], ans = 1e18;
bool vis[2005], f[2005];
void add(int u, int v) {
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}
void Dijkstra(int s) {
	for(int i = 1; i <= n; i++) {
		dis[s][i] = 0x3f3f3f3f;
		vis[i] = 0;
	}
	dis[s][s] = 0;
	vis[s] = 1;
	priority_queue<node> q;
	q.push((node){s, 0});
	while(!q.empty()) {
		node tmp = q.top();
		q.pop();
		for(int i = head[tmp.id]; i; i = edge[i].next) {
			int j = edge[i].to;
			if(dis[s][j] > dis[s][tmp.id] + 1) {
				dis[s][j] = dis[s][tmp.id] + 1;
				if(!vis[j]) {
					vis[j] = 1;
					q.push((node){j, dis[s][j]});
				}
			}
		} 
	}
}
void dfs(int now, long long sum) {
	if(now == vp) {
		ans = min(ans, sum);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!f[i]) {
			if(dis[now][i] <= k) {
				f[i] = 1;
				dfs(i, sum + a[i]);
				f[i] = 0;
			}
		}
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int q;
	SF("%d%d%d", &n, &q, &k);
	for(int i = 1; i <= n; i++) SF("%lld", &a[i]);
	for(int i = 1; i < n; i++) {
		int u, v;
		SF("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	for(int i = 1; i <= n; i++) Dijkstra(i);
	while(q--) {
		SF("%d%d", &up, &vp);
		memset(f, 0, sizeof(f));
		f[up] = 1;
		ans = 1e18;
		dfs(up, a[up]);
		PF("%lld\n", ans);
	}
	return 0;
} 
