#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 2505;
const int inf = 0x3f3f3f3f;
struct edge{
	int v, w;
	bool operator <(const edge &x) const{
		return x.w < w;
	}
};
int n, m, k, pos[N][2], dis[N][N];
int dep1[N], dep2[N], cnt1, cnt2;
LL a[N], f[N][2], ans;
bool vis[N][N], vis1[N], vis2[N];
priority_queue<edge> pq;
vector<int> G[N];
inline void dijkstra(int u){
	for (int i = 1; i <= n; i++)
		if (i != u) dis[u][i] = inf;
	pq.push(edge{u, 0});
	while(!pq.empty()){
		int s = pq.top().v;
		pq.pop();
		if (vis[u][s]) continue;
		vis[u][s] = 1;
		for (int t : G[s]){
			if (!vis[u][t] && dis[u][t] > dis[u][s] + 1){
				dis[u][t] = dis[u][s] + 1;
				pq.push(edge{t, dis[u][s] + 1});
			}
		}
	}
} 
int main(){
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	k++;
	for (int i = 2; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1, u, v; i <= m; i++){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) dijkstra(i);
	for (int i = 2; i <= n; i++)
		if (dis[1][i] <= k && !vis1[i]) 
			dep1[++cnt1] = i, vis1[i] = 1;
	for (int i = 1; i <= cnt1; i++){
		int u = dep1[i];
		for (int j = 2; j <= n; j++){
			if (u == j) continue;
			if (dis[u][j] <= k){
				if (!vis2[j]) vis2[j] = 1, dep2[++cnt2] = j;
				if (a[u] + a[j] > f[j][0]){
					f[j][1] = f[j][0], pos[j][1] = pos[j][0];
					f[j][0] = a[u] + a[j], pos[j][0] = u;
				}
				else if (a[u] + a[j] > f[j][1]){
					f[j][1] = a[u] + a[j];
					pos[j][1] = u;
				}
			}
		}
	}
	for (int i = 1; i <= cnt2; i++){
		for (int j = 1; j <= cnt2; j++){
			if (i == j) continue;
			int u = dep2[i], v = dep2[j];
			if (dis[u][v] <= k){
				if (pos[u][0] != pos[v][0] && u != pos[v][0] && v != pos[u][0]) 
					ans = max(ans, f[u][0] + f[v][0]);
				if (pos[u][0] != pos[v][1] && u != pos[v][1] && v != pos[u][0]) 
					ans = max(ans, f[u][0] + f[v][1]);
				if (pos[u][1] != pos[v][0] && u != pos[v][0] && v != pos[u][1]) 
					ans = max(ans, f[u][1] + f[v][0]);
				if (pos[u][1] != pos[v][1] && u != pos[v][1] && v != pos[u][1]) 
					ans = max(ans, f[u][1] + f[v][1]);
			}
		}
	}
	printf("%lld", ans);
	return 0;
} 
