#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 2555;

//char buf[1 << 23], *p1 = buf, *p2 = buf;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
ll read() {
	ll s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-')  w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
}

bool mem1;

vector<int> Edge[N], vec[N];
int dis[N][N];
ll w[N], ans;
int n, m, K;

bool vis[N];
void dfs(int dep, int now, ll res) {
	if(dep == 5) {
		if(dis[now][1] > K + 1) return;
		else ans = max(ans, res);
		return ;
	}
	for(int i = 2; i <= n; ++ i)
		if(!vis[i] && dis[now][i] <= K + 1) 
			vis[i] = 1, dfs(dep + 1, i, res + w[i]), vis[i] = 0;
}
void BF() {
	dfs(1, 1, 0);
	printf("%lld\n", ans);
}

bool cmp(int a, int b) {
	return w[a] > w[b];
}
void Solve() {
	for(int i = 2; i <= n; ++ i) if(dis[1][i] <= K + 1)
		for(int j = 2; j <= n; ++ j) if(i ^ j && dis[i][j] <= K + 1)
			vec[j].push_back(i);
	for(int i = 2; i <= n; ++ i)
		sort(vec[i].begin(), vec[i].end(), cmp);
	ll ans = 0;
	for(int i = 2; i <= n; ++ i) 
		for(int j = 2; j <= n; ++ j) if(i ^ j && dis[i][j] <= K + 1) {
			vector<int> a, b;
			for(int k = 0; k < min(3, (int)vec[i].size()); ++ k) a.push_back(vec[i][k]);
			for(int k = 0; k < min(3, (int)vec[j].size()); ++ k) b.push_back(vec[j][k]);
			for(int x = 0; x < (int)a.size(); ++ x) if(a[x] ^ j)
				for(int y = 0; y < (int)b.size(); ++ y) 
					if(a[x] ^ b[y] && b[y] ^ i) 
						ans = max(ans, w[i] + w[j] + w[a[x]] + w[b[y]]);
		}
	printf("%lld\n", ans);
}

bool mem2;

signed main() {
//		printf("Memory Cost is: %lf\n", (&mem2 - &mem1) / 1024. / 1024.);
//	cout << LLONG_MAX;
//	freopen("holiday3.in", "r", stdin);
	file();
	n = read(), m = read(), K = read();
	for(int i = 2; i <= n; ++ i) w[i] = read();
	for(int i = 1, u, v; i <= m; ++ i)
		u = read(), v = read(),
		Edge[u].push_back(v),
		Edge[v].push_back(u);
	
	memset(dis, -1, sizeof(dis));
	for(int i = 1; i <= n; ++ i) {
		queue<int> q;
		dis[i][i] = 0, q.push(i);
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int j = 0, v; j < (int)Edge[u].size(); ++ j) 
				if(dis[i][v = Edge[u][j]] == -1)
					dis[i][v] = dis[i][u] + 1, q.push(v);
		}
	}
	
	if(n <= 20) return BF(), 0;
	Solve();
	return 0;
}


//ll dp[6][N];
//void Rubbish() {
//	for(int i = 0; i <= 5; ++ i)
//		for(int j = 1; j <= n; ++ j)
//			dp[i][j] = -5e18;
//	dp[0][1] = 0;
//	for(int i = 0; i <= 4; ++ i)
//		for(int j = 1; j <= n; ++ j) {
//			if(dp[i][j] < -4e18) continue;
//			int lim = 1;
//			if(i ^ 4) ++ lim;
//			for(int k = lim; k <= n; ++ k) 
//				if(j ^ k && dis[j][k] <= K + 1) 
//					dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + w[k]);
//		}
//	
//	printf("%lld\n", dp[5][1]);
//}

