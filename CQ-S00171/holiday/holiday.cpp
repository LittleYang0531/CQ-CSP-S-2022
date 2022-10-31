/*
给定一张无向图，求包含了 1 和四个不同点 且 长度不超过 5 * k + 5 的路径的最大权值和。 

淦，读错题了 ！！！ 

谢谢你！！  

*/


#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 2005;
int n, m, K, dis[N][N];
ll w[N], ans = -1;
void read(int &x) {
	x = 0;
	int f= 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-') f = -1;
		s = getchar();
	}
	while(s <= '9' && s >= '0') {
		x = x * 10 + s - '0';
		s = getchar();
	} 
	x *= f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10), x %= 10;
	putchar(x + '0');
}

int tot = 1, head[N], cur[N], nex[N << 1], to[N << 1];
void add(int x, int y) {
	to[++tot] = y, nex[tot] = head[x], head[x] = tot;
}

bool vis[N];
void dfs(int x, int dep, ll num) {
	if(dep == 4) {
		if(dis[x][1] - 1 <= K) ans = max(ans, num);
		return;
	}
	int ver;
	for(int i = 2; i <= n; i ++) {
		if(vis[i] || dis[x][i] - 1 > K) continue;
		vis[i] = 1;
		dfs(i, dep + 1, num + w[i]);
		vis[i] = 0;
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	read(n), read(m), read(K);
	for(int i = 2; i <= n; i ++) scanf("%lld", &w[i]);
	int u, v;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= m; i ++) {
		read(u), read(v);
		dis[u][v] = dis[v][u] = 1;
	}
	
	if(K) {
		for(int k = 1; k <= n; k ++) {
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= n; j ++) {
			//		if(dis[i][j] - 1 <= K) break;
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
	
	
	
//	for(int i = 1; i <= n; i ++) {
//		for(int j = 1; j <= n; j ++) {
//			if(i != j) 
//		}
//	}
	
	dfs(1, 0, 0);
	printf("%lld", ans);
	
	return 0;
} 


/*

8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1


*/
