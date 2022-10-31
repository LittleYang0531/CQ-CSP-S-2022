#include <queue>
#include <cstdio>
#include <vector>

#define LL long long
#define uLL unsigned LL

LL rint() {
	LL x = 0, Fx = 1; char c = getchar();
	while (c < '0' || c > '9') { Fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	return Fx ? x : -x;
}

LL Max(LL u, LL v) { return (u > v) ? u : v; }
LL Min(LL u, LL v) { return (u < v) ? u : v; }

const int MAX_n = 2500;
const int MAX_m = 10000;
const int MAX_k = 100;

int n, m, k;
int idx[MAX_n + 5][5];
int dis[MAX_n + 5][MAX_n + 5];

LL w[MAX_n + 5];

std::vector<int> G[MAX_n + 5];

void Add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

void bfs(int S) {
	for (int i = 1; i <= n; i++)
		dis[S][i] = -2;
	dis[S][S] = -1;
	std::queue<int> q; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			if (dis[S][v] != -2) continue;
			dis[S][v] = dis[S][u] + 1;
			if (dis[S][v] < k) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
		dis[S][i] = (dis[S][i] >= 0);
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = rint(), m = rint(), k = rint();
	for (int i = 2; i <= n; i++)
		w[i] = rint();
	for (int i = 1, u, v; i <= m; i++)
		u = rint(), v = rint(), Add_edge(u, v);
	for (int i = 1; i <= n; i++) bfs(i);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf(" %d", dis[i][j]);
//		printf("\n");
//	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++)
			if (dis[1][j] && dis[j][i] && w[j] > w[idx[i][1]]) idx[i][1] = j;
		for (int j = 2; j <= n; j++)
			if (dis[1][j] && dis[j][i] && w[j] > w[idx[i][2]] && j != idx[i][1]) idx[i][2] = j;
		for (int j = 2; j <= n; j++)
			if (dis[1][j] && dis[j][i] && w[j] > w[idx[i][3]] && j != idx[i][1] && j != idx[i][2]) idx[i][3] = j;
	}
	LL res = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (dis[i][j]) {
				for (int x = 1; x <= 3 && idx[i][x]; x++)
					for (int y = 1; y <= 3 && idx[j][y]; y++)
						if (idx[i][x] != j && idx[i][x] != idx[j][y] && idx[j][y] != i)
							{ res = Max(res, w[idx[i][x]] + w[i] + w[j] + w[idx[j][y]]); break; }
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}

