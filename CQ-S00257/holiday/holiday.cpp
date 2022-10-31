#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 3e3 + 5, MAXM = 1e4 + 5;
int n, m, k, b[MAXN][MAXN];
long long a[MAXN], ans;
vector<int> g[MAXM];
struct node{
	int id, step;
};
struct node1{
	map<int, bool> flag;
	long long num;
}dp[MAXN][5];
inline void bfs(int x){
	queue<node> q;
	bool vis[MAXN] = {};
	q.push((node){x, 0});
	while(q.size()){
		node t = q.front();
		q.pop();
		if(vis[t.id])continue;
		vis[t.id] = 1;
		for(int i = 0; i < g[t.id].size(); i ++){
			if(vis[g[t.id][i]])continue;
			b[x][g[t.id][i]] = t.step;
			q.push((node){g[t.id][i], t.step + 1});
		}
	}
}
int main(){
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 2; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++)bfs(i);
	for(int i = 2; i <= n; i ++){
		for(int j = 1; j <= 4; j ++){
			for(int l = 2; l <= n; l ++){
				if(l == i)continue;
				if(b[l][i] <= k && !dp[l][j - 1].flag[l]){
					if(dp[l][j - 1].num + a[i] > dp[i][j].num){
						dp[i][j] = dp[l][j - 1];
						dp[i][j].num = dp[l][j - 1].num + a[i];
						dp[i][j].flag[l] = 1;
					}
				}
			}
		}
	}
	for(int i = 2; i <= n; i ++){
		if(b[i][1] <= k){
			ans = max(ans, dp[i][4].num);
		}
	}
	printf("%lld", ans);
	return 0; 
}
