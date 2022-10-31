#include <bits/stdc++.h>


using namespace std;


struct Edge {
	int enode, enext;
} edge[200003];

int elast[2503], cntEdge = 0;

void addEdge(int u, int v) {
	edge[++ cntEdge].enode = v;
	edge[cntEdge].enext = elast[u];
	elast[u] = cntEdge;
}


int n, m, K, x, y;
long long a[2503], ans = 0;


bool mark[2503], Visit[2503], temp[2503];
int maxx[2][2];


void DFS(int u, int d) {
	mark[u] = true;
	if (d == K + 1) return;
	for (int i = elast[u]; i; i = edge[i].enext)
		if (!mark[edge[i].enode]) DFS(edge[i].enode, d + 1);
}

void DFS2(int u, int d, int rt1, int rt2) {
	Visit[u] = true;
	if (mark[u] && u != rt1 && u != rt2) {
		if (a[maxx[0][0]] <= a[u]) {
			maxx[0][1] = maxx[0][0];
			maxx[0][0] = u;
		} else if (a[maxx[0][1]] <= a[u]) {
			maxx[0][1] = u;
		}
	}
	if (d == K + 1) return;
	for (int i = elast[u]; i; i = edge[i].enext)
		if (!Visit[edge[i].enode]) DFS2(edge[i].enode, d + 1, rt1, rt2);
}


void DFS3(int u, int d, int rt1, int rt2) {
	temp[u] = true;
	if (mark[u] && u != rt1 && u != rt2) {
		if (a[maxx[1][0]] <= a[u]) {
			maxx[1][1] = maxx[1][0];
			maxx[1][0] = u;
		} else if (a[maxx[1][1]] <= a[u]) {
			maxx[1][1] = u;
		}
	}
	if (d == K + 1) return;
	for (int i = elast[u]; i; i = edge[i].enext)
		if (!temp[edge[i].enode]) DFS3(edge[i].enode, d + 1, rt1, rt2);
}


int flag[2503];


int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &K);
	for (register int i = 2; i <= n; ++ i) scanf("%lld", &a[i]);
	for (register int i = 1; i <= m; ++ i) {
		scanf("%d %d", &x, &y);
		addEdge(x, y), addEdge(y, x);
	}

	if (n <= 300)  {
		DFS(1, 0);
		mark[1] = false;
		for (int i = 2; i <= n; ++ i) {
			for (int j = 2; j <= n; ++ j) {
				if (i == j) continue;
				memset(maxx, 0, sizeof maxx);
				memset(Visit, false, sizeof Visit);
				DFS2(i, 0, i, j);
				if (!Visit[j]) continue;
				memset(temp, false, sizeof temp);
				DFS3(j, 0, i, j);
				if (maxx[0][0] == 0 || maxx[1][0] == 0) continue;
				if (maxx[0][0] != maxx[1][0]) ans = max(a[maxx[0][0]] + a[maxx[1][0]] + a[i] + a[j], ans);
				else {
					if (maxx[1][1]) ans = max(a[maxx[0][0]] + a[maxx[1][1]] + a[i] + a[j], ans);
					if (maxx[0][1]) ans = max(a[maxx[0][1]] + a[maxx[1][0]] + a[i] + a[j], ans);
				}
			}
		}
		printf("%lld", ans);
	} else {
		if (K == 0) {
			for (int i = elast[1]; i; i = edge[i].enext)
				mark[edge[i].enode] = true;
			for (int i = 2; i <= n; ++ i) {
				int cnt = 0;
				for (int j = elast[i]; j; j = edge[j].enext)
					if (mark[edge[j].enode]) {
						++ cnt;
						if (flag[i] == 0 || a[flag[i]] < a[edge[j].enode])
							flag[i] = edge[j].enode;
					}
				if (cnt >= 2) flag[i] = -flag[i];
			}
			for (int i = 2; i <= n; ++ i) {
				for (int j = elast[i]; j; j = edge[j].enext) {
					if (j == 1) continue;
					if ((flag[i] != 0 && (flag[i] < 0 || flag[i] != edge[j].enode)) && (flag[edge[j].enode] != 0 && (flag[edge[j].enode] < 0 || flag[edge[j].enode] != i))) {
						ans = max(ans, a[i] + a[edge[j].enode] + a[abs(flag[i])] + a[abs(flag[edge[j].enode])]);
					}
				}
			}
			printf("%lld", ans);
		} else {
			DFS(1, 0);
			mark[1] = false;
			for (int i = 2; i <= n; ++ i) {
				for (int j = 2; j <= n; ++ j) {
					if (i == j) continue;
					memset(maxx, 0, sizeof maxx);
					memset(Visit, false, sizeof Visit);
					DFS2(i, 0, i, j);
					if (!Visit[j]) continue;
					memset(temp, false, sizeof temp);
					DFS3(j, 0, i, j);
					if (maxx[0][0] == 0 || maxx[1][0] == 0) continue;
					if (maxx[0][0] != maxx[1][0]) ans = max(a[maxx[0][0]] + a[maxx[1][0]] + a[i] + a[j], ans);
					else {
						if (maxx[1][1]) ans = max(a[maxx[0][0]] + a[maxx[1][1]] + a[i] + a[j], ans);
						if (maxx[0][1]) ans = max(a[maxx[0][1]] + a[maxx[1][0]] + a[i] + a[j], ans);
					}
				}
			}
			printf("%lld", ans);
		}
	}
	return 0;
}
