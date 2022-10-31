#include <bits/stdc++.h>
using namespace std;
const int N = 2505, M = 10005;
int n, m, k, a[N], f[4][N];

struct Edge {
	int to, next;
} g[M << 1];

int cnt = 0, ans = 0, head[N], trans[N][N], ver[N];

void add(int u, int v) {
	g[++ cnt].next = head[u];
	g[cnt].to = v;
	head[u] = cnt;
}

// 转车
void dijskra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > h;
	for (int i = 1; i <= n; i ++) ver[i] = 0;
	for (int i = 1; i <= n; i ++) trans[s][i] = 0x3f;
	
	trans[s][s] = 0;
	h.push(make_pair(trans[s][s], s));
	
	while (! h.empty()) {
		int t = h.top().second; h.pop();
		
		for (int i = head[t]; i; i = g[i].next) {
			int j = g[i].to;
			
			if (trans[s][j] > trans[s][t] + 1) {
				trans[s][j] = trans[s][t] + 1;
				h.push(make_pair(trans[s][j], j));
			}
		}
		
		ver[t] = 1;
	}
	
	for (int i = 1; i <= n; i ++) trans[s][i] --;
}

int vis[N], path[10];

// 暴力
void dfs(int step, int u, int sum) {
	if (step == 4) {
		if (trans[1][u] > k) return ;
		ans = max(ans, sum);
		return ;
	}
	
	for (int i = 1; i <= n; i ++) {
		if (vis[i]) continue;
		if (trans[i][u] > k) continue;
		
		vis[i] = 1;
		path[step + 1] = i;
		dfs(step + 1, i, sum + a[i]);
		vis[i] = 0;
	}
}

int main() {
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 2; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	
	for (int i = 1; i <= n; i ++)
		dijskra(i);
	if (n < 20) {
		vis[1] = 1;
		dfs(0, 1, 0);
		printf("%d\n", ans);
	} else {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++)
				cout << trans[i][j] << ' ';
			cout << endl;
		}
		for (int i = 1; i <= 4; i ++)
			for (int j = 1; j <= n; j ++)
				for (int k = 1; k <= n; k ++)
					if (j != k && (trans[j][k] <= k))
						f[i][j] = max(f[i][j], f[i - 1][k] + a[j]);

		for (int i = 1; i <= n; i ++)
			if (trans[1][i] <= k)
				ans = max(ans, f[4][i]);
	}
	

	return 0;
}
/*
我写到这里已经筋疲力尽了
*/
