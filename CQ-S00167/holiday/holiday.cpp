#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2505, MaxM = 1e4 + 5;

int n, m, k;
vector<int> edge1[MaxN], edge2[MaxN];
int g[MaxN][MaxN];
long long f[MaxN][10];
int f2[MaxN][10];
long long val[MaxN];
long long ans;
bool vis[MaxN];

int dis[MaxN];
queue<int> q;

void BFS(int i) {
	memset(dis, 0x3f, sizeof dis);
	q.push(i);
	dis[i] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : edge1[u])
			if (dis[v] == 0x3f3f3f3f) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
//	cout << "edge2: " << i << "-> ";
	for (int j = 1; j <= n; j++)
		if (dis[j] <= k && j != i) {
			g[i][j] = g[j][i] = 1;
			edge2[i].push_back(j);
//			cout << j << ' ';
		}
//	cout << '\n';
}

void GetMax(int i) {
	memset(vis, 0, sizeof vis);
	for (auto v : edge2[i]) {
		if (!g[v][1] || vis[v])
			continue;
		vis[v] = 1;
		if (val[v] >= f[i][0]) {
			f[i][2] = f[i][1], f2[i][2] = f2[i][1];
			f[i][1] = f[i][0], f2[i][1] = f2[i][0];
			f[i][0] = val[v], f2[i][0] = v;
		} else if (val[v] >= f[i][1]) {
			f[i][2] = f[i][1], f2[i][2] = f2[i][1];
			f[i][1] = val[v], f2[i][1] = v;
		} else if (val[v] >= f[i][2]) {
			f[i][2] = val[v], f2[i][2] = v;
		}
	}
//	cout << "#" << i << ' ' << '\n';
//	cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
//	cout << f2[i][0] << ' ' << f2[i][1] << ' ' << f2[i][2] << '\n';
//	cout << "--------------------------\n";
}

void Read() {
	cin >> n >> m >> k;
	for (int i = 2; i <= n; i++)
		cin >> val[i];
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge1[u].push_back(v);
		edge1[v].push_back(u);
	}
}

void Init() {
	for (int i = 1; i <= n; i++)
		BFS(i);
	for (int i = 1; i <= n; i++)
		GetMax(i);
}

void Solve() {
	for (int u = 1; u <= n; u++) {
		for (auto v : edge2[u]) {
			if (v <= u)
				continue;
//			cout << "ans: " << u << "->" << v << '\n';
			for (int a = 0; a < 3; a++)
				for (int b = 0; b < 3; b++) {
					int k = f2[u][a], l = f2[v][b];
					if (k == l || k == v || l == u || k <= 1 || l <= 1)
						continue;
					ans = max(ans, val[u] + val[v] + val[k] + val[l]);
				}
//			cout << "nowans: " << ans << '\n';
		}
	}

	cout << ans << '\n';
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	Read();
	Init();
	Solve();

	return 0;
}

/*
input:
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

output:
27
*/
