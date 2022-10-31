#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define inf 1e9
#define Inf 1e18
#define ll __int128
#define pii pair <ll, int>
#define mp make_pair
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
int n, m, mx;
vector <int> G[2505];
int dis[2505][2505];
void bfs(int s) {
	for(int i = 1; i <= n; i++) dis[s][i] = inf;
	queue <int> Q;
	dis[s][s] = 0;
	Q.push(s);
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(auto y : G[x]) {
			if(dis[s][y] > dis[s][x] + 1) {
				dis[s][y] = dis[s][x] + 1;
				Q.push(y);
			}
		}
	}
}
ll f[2505][10];
ll a[2505];
pii val[10][2505];
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = read(), m = read(), mx = read() + 1;
	for(int i = 2; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		G[u].push_back(v), G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) bfs(i);
//	printf("%d %d %d %d %d\n", dis[1][8], dis[8][2], dis[2][3], dis[3][5], dis[5][1]);
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= n; j++) {
			if(i == j) continue;
			if(dis[1][j] <= mx && dis[i][j] <= mx) {
				pii now = mp(a[j], j);
				if(now > val[1][i]) val[3][i] = val[2][i], val[2][i] = val[1][i], val[1][i] = now;
				else if(now > val[2][i]) val[3][i] = val[2][i], val[2][i] = now;
				else if(now > val[3][i]) val[3][i] = now;
			}
		} 
	}
	ll Ans = -Inf;
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= n; j++) {
			if(i == j || dis[i][j] > mx) continue;
			for(int k1 = 1; k1 <= 3; k1++) {
				if(!val[k1][i].second || val[k1][i].second == j) continue;
				for(int k2 = 1; k2 <= 3; k2++) {
					if(!val[k2][j].second || val[k2][j].second == i || val[k2][j].second == val[k1][i].second) continue;
					Ans = max(Ans, a[i] + a[j] + val[k1][i].first + val[k2][j].first);
				}
			}
		}
	}
	write(Ans), putchar('\n');
	return 0;
}
/*
居然要求景点不同，第一题不 会 了 
*/
