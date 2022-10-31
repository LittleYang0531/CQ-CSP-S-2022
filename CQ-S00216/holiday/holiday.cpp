#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 5 , MAXM = 2e4 + 5;
#define ll long long
template<typename item> 
void read(item &x) {
	x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= f;
}
int dis[MAXN][MAXN] , n , m , k , head[MAXN] , st , cnt;
ll dp[MAXN][6] , s[MAXN] , ans;
bool vis[MAXN] , used[MAXN][5][MAXN];
struct node{
	int to , nxt;
}a[MAXM];
void add(int u , int v) {
	a[++ cnt].to = v;
	a[cnt].nxt = head[u];
	head[u] = cnt;
}
struct node2{
	int id , w;
	node2(int iid , int ww) {
		id = iid;
		w = ww;
	}
	friend bool operator<(node2 x , node2 y) {
		return x.w > y.w;
	}
};
void dijkstra(int s) {
	dis[s][s] = 0;
	priority_queue<node2> q;
	q.push(node2(s , 0));
	for (int i = 1 ; i <= n ; i ++) vis[i] = 0;
	while(!q.empty()) {
		int u = q.top().id;
		q.pop();
		if (vis[u]) continue;
		for (int i = head[u] ; i ; i = a[i].nxt) {
			int v = a[i].to;
			if (dis[s][u] + 1 < dis[s][v]) {
				dis[s][v] = dis[s][u] + 1;
				q.push(node2(v , dis[s][v]));
			}
		}
	}
}
int main() {
	freopen("holiday.in" , "r" , stdin);
	freopen("holiday.out" , "w" , stdout);
	read(n);read(m);read(k);
	for (int i = 2 ; i <= n ; i ++) {
		read(s[i]);
	} 
	for (int i = 1 , u , v ; i <= m ; i ++) {
		read(u);read(v);
		add(u , v);
		add(v , u);
	}
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			dis[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1 ; i <= n ; i ++) {
		dijkstra(i);
	}
	memset(dp , -0x1f , sizeof(dp));
	for (int i = 1 ; i <= n ; i ++) {
		if (dis[1][i] - 1 <= k) dp[i][1] = s[i] , used[i][1][i] = used[i][1][1] = 1;
	}
	for (int p = 2 ; p <= 4 ; p ++) {
		for (int i = 1 ; i <= n ; i ++) {
			int tmp;
			for (int j = 1 ; j <= n ; j ++) {
				if (i == j) continue;
				if (dis[j][i] - 1 <= k && !used[j][p - 1][i]) {
					if (dp[j][p - 1] + s[i] > dp[i][p]) {
						dp[i][p] = dp[j][p - 1] + s[i];
						tmp = j;
					} 
				}
			}
			for (int j = 1 ; j <= n ; j ++) used[i][p][j] = used[tmp][p - 1][j];
			used[i][p][i] = 1;	
		} 
	} 	
	for (int i = 2 ; i <= n ; i ++) {
		if (dis[i][1] - 1 <= k) {
			int tmp = 0;
			for (int j = 1 ; j <= n ; j ++) {
				tmp += used[i][4][j];
			}
			if (tmp == 5) ans = max(ans , dp[i][4]);
		}
	}
	printf("%lld", ans);
	return 0;
}
