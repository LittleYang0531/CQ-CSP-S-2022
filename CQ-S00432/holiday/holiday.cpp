#include <bits/stdc++.h>
#define Inf 0x7fffffff / 2
using namespace std;
const int N = 2505;

int Max(int a, int b) {
	return a > b ? a : b;
}

struct G {
	int to, pre;
} g[N << 1];

struct node {
	int dis, to;
	int operator < (const node &b) const {
		return dis > b.dis;
	}
};

int n, m, k, cnt, ans;
bool vis[N][N];
int dis[N][N], v[N], val[N], f[N][N];
vector<int> from[N], w[N];

void add(int a, int b) {
	g[++cnt].to = b;
	g[cnt].pre = v[a];
	v[a] = cnt;
	return ;
}  

void work() {
	bool ok[N];
	for(int i = 2; i <= n; ++i) {
		if(dis[1][i] - 1 <= k) {
			
			for(int l = 2; l <= n; ++l) {
				
				if(i == l) continue;
				
				if(dis[i][l] - 1 <= k) {
					
					from[l].push_back(i);
					
					w[l].push_back(val[i] + val[l]);
					
					ok[l] = true;
				} 
			}
		}
	}
	for(int i = 2; i <= n; ++i) {
		if(!ok[i]) continue;
			for(int j = 2; j <= n; ++j) {
				if(i == j) continue;
				if(!ok[j]) continue;
				if(dis[i][j] - 1 > k) continue;
				for(int b = 0; b < from[j].size(); ++b) {
					for(int a = 0; a < from[i].size(); ++a) {
						if(from[i][a] == from[j][b]) continue;
						if(from[i][a] == j) continue;
						if(from[j][b] == i) continue;
						
						ans = max(ans, w[i][a] + w[j][b]);
					}
				}
		}	
	}
	return ;
}

void dij(int s) {
	priority_queue<node> q;
	for(int i = 1; i <= n; ++i)
		dis[s][i] = Inf;
	dis[s][s] = 0;
	vis[s][s] = true;
	q.push(node{0, s});
	while(!q.empty()) {
		node t = q.top();
		
		q.pop();
		
		int p = t.to;
		
		for(int i = v[p]; i; i = g[i].pre) {
			int to = g[i].to;
			
			if(dis[s][p] + 1 < dis[s][to]) {
				
				dis[s][to] = dis[s][p] + 1;
				
				if(!vis[s][to]) {
					
					vis[s][to] = true;
					
					q.push(node{dis[s][to], to});
				}
			}
		}
	}
	return ;
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 2; i <= n; ++i)
		scanf("%d", &val[i]);
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	for(int i = 1; i <= n; ++i)
		dij(i);
	work();
	printf("%d\n", ans);
	return 0;
}
