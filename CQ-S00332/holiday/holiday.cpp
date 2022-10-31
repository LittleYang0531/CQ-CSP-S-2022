#include <bits/stdc++.h>
using namespace std;

const int N = 2510, M = 2e4 + 10;
typedef long long LL;

bool vis[M];
int dis[N][N], poi[M], nx[M], head[M], q[M], pos[N][3], tot;
LL val[N], sc[N][3];

void add_edge(int u, int v) {
	++tot;
	poi[tot] = v;
	nx[tot] = head[u];
	head[u] = tot;
}

void read(int &x) {
	x = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		c = getchar();
	} 
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
}

void Read(LL &x) {
	x = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		c = getchar();
	} 
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	int n, m, k, a, b;
	read(n), read(m), read(k);
	for(int i = 2; i <= n; ++i) {
		Read(val[i]);
	}
	for(int i = 1; i <= m; ++i) {
		read(a), read(b);
		add_edge(a, b);
		add_edge(b, a);
	}
	for(int j = 1; j <= n; ++j) {
		for(int i = 1; i <= n; ++i) {
			vis[i] = false;
		}
		vis[j] = true;
		int l = 1, r = 1;
		q[1] = j;
		while(l <= r) {
			int u = q[l++];
			for(int i = head[u]; i; i = nx[i]) {
				int v = poi[i];
				if(!vis[v]) {
					dis[j][v] = dis[j][u] + 1;
					vis[v] = true;
					q[++r] = v;
				}	
			}
		}
	}
	for(int i = 2; i <= n; ++i) {
		if(dis[1][i] <= k + 1) {
			for(int j = 2; j <= n; ++j) {
				if(i != j && dis[i][j] <= k + 1) {
					if(sc[j][0] < val[i]) {
						sc[j][2] = sc[j][1];
						pos[j][2] = pos[j][1];
						sc[j][1] = sc[j][0];
						pos[j][1] = pos[j][0];
						sc[j][0] = val[i];
						pos[j][0] = i;
					} else if(sc[j][1] < val[i]) {
						sc[j][2] = sc[j][1];
						pos[j][2] = pos[j][1];
						sc[j][1] = val[i];
						pos[j][1] = i;
					} else if(sc[j][2] < val[i]) {
						sc[j][2] = val[i];
						pos[j][2] = i;
					}
				}
			}
		}
	}
	LL ans = 0;
	for(int i = 2; i <= n; ++i) {
		if(sc[i][0]) {
			for(int j = 2; j <= n; ++j) {
				if(sc[j][0] && i != j && dis[i][j] <= k + 1) {
					if(pos[i][0] != j && pos[i][0] != pos[j][0] && i != pos[j][0]) {
						ans = max(ans, sc[i][0] + sc[j][0] + val[i] + val[j]);
					} else {
						LL sum = val[i] + val[j];
						for(int x = 0; x <= 2; ++x) {
							for(int y = 0; y <= 2; ++y) {
								if(pos[i][x] != j && pos[i][x] != pos[j][y] && i != pos[j][y]) {
									ans = max(ans, sc[i][x] + sc[j][y] + sum);
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
