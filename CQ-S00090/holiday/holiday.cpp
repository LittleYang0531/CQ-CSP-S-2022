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
}edge[20005];
struct node {
	int id, dis;
	bool operator < (const node &x) const {
		return dis > x.dis; 
	}
};
struct op {
	int len, a[2505];
	op () {len = -1;}
}dp[2505][4], ans;
int head[20005], cnt, n, m, k, dis[2505][2505], b[2505];
long long a[2505];
bool vis[2505];
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
op add(op a, long long P) {
	memset(b, 0, sizeof(b));
	int lenb = -1;
	while(P != 0) {
		b[++lenb] = P % 10;
		P /= 10;
	}
	int i = 0, j = 0, jw = 0;
	op c;
	while(i <= a.len || j <= lenb) {
		c.a[++c.len] = a.a[i++] + b[j++] + jw;
		jw = c.a[c.len] / 10;
		c.a[c.len] %= 10;
	}
	if(jw) c.a[++c.len] = jw;
	return c;
}
op Max(op a, op b) {
	if(a.len == b.len) {
		int Len = a.len;
		for(int i = Len; i >= 0; i--) {
			if(a.a[i] > b.a[i]) return a;
			else if(a.a[i] < b.a[i]) return b;
		}
		return a;
	}
	else {
		if(a.len > b.len) return a;
		else return b;
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	SF("%d%d%d", &n, &m, &k);
	for(int i = 2; i <= n; i++) SF("%lld", &a[i]);
	for(int i = 1; i <= m; i++) {
		int u, v;
		SF("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	for(int i = 1; i <= n; i++) Dijkstra(i);
	for(int i = 2; i <= n; i++) {
		if(dis[1][i] - 1 <= k) {
			long long p = a[i];
			while(p != 0) {
				dp[i][1].a[++dp[i][1].len] = p % 10;
				p /= 10;
			}
		}
		for(int j = 2; j <= 4; j++) {
			if(j >= i) break;
			if(j == 4) {
				if(dis[i][1] - 1 > k) break;
			}
			op maxn;
			for(int s = 2; s < i; s++) {
				if(dis[s][i] - 1 <= k) maxn = Max(maxn, dp[s][j - 1]);
			}
			dp[i][j] = add(maxn, a[i]);
		}
	}
	for(int i = 5; i <= n; i++) ans = Max(ans, dp[i][4]);
	for(int i = ans.len; i >= 0; i--) PF("%d", ans.a[i]);
	return 0;
} 
