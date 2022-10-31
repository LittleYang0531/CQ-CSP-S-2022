#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 2.5e3 + 5, Maxm = 1e4 + 5;
inline ll read() {
	ll sum = 0;
	int f = 1;
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
vector <int> G[Maxn];
struct node { 
	int v, id;
	friend bool operator < (node a, node b) {
		return a.v > b.v;
	}
};
int n, m, k, dis[Maxn][Maxn];
ll a[Maxn], ans;
bool vis[Maxn];
void dijkstra(int id) {
	memset(vis, 0, sizeof vis);
	memset(dis[id], 0x3f, sizeof dis[id]);
	dis[id][id] = 0;
	priority_queue <node> q;
	q.push((node){0, id});
	while(!q.empty()) {
		int p = q.top().id;
		q.pop();
		if(vis[p]) continue;
		vis[p] = 1;
		for(int i = 0;i < G[p].size(); ++i) {
			int to = G[p][i];
			if(dis[id][to] > dis[id][p] + 1) {
				dis[id][to] = dis[id][p] + 1;
				q.push((node){dis[id][to], to});
			}
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout); 
	n = read(), m = read(), k = read();
	k ++;
	for(int i = 2;i <= n; ++i) a[i] = read();
	for(int i = 1, x, y;i <= m; ++i) {
		x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	for(int i = 1;i <= n; ++i)
		dijkstra(i);
//	for(int i = 1;i <= n; ++i) {
//		for(int j = 1;j <= n; ++j) printf("%d ", dis[i][j]);
//		puts("");
//	}
	for(int i = 2;i <= n; ++i)
	if(dis[1][i] <= k) 
		for(int j = 2;j <= n; ++j) 
		if(i != j and dis[i][j] <= k)
			for(int l = 2;l <= n; ++l)
			if(i != l and j != l and dis[j][l] <= k)
				for(int t = 2;t <= n; ++t)
				if(i != t and j != t and l != t and dis[l][t] <= k and dis[t][1] <= k) 
					ans = max(ans, a[i] + a[j] + a[l] + a[t]);
	printf("%lld", ans);	
	return 0;
}
// 55pts:Ã¶¾Ù¾°µã 
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
