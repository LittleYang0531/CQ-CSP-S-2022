#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, q, k;
int g[N][N];
long long val[N];
bool vis[N];
vector<int> edge[N];

void DFS1(int s, int u, int prt, int dep) {
	if (dep > k)
		return;
	g[s][u] = g[u][s] = 1;
	for (auto v : edge[u])
		if (v != prt)
			DFS1(s, v, u, dep + 1);
}

void Init1() {
	for (int i = 1; i <= n; i++)
		DFS1(i, i, 0, 0);
}

void Init2() {
	
}

void Solve1() {
	while (q--) {
		
	}
}

void Solve2() {
	
}

void Read() {
	cin >> n >> q >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	Read();
	if (n <= 3000) {
		Init1();
		Solve1();
	}
	else {
		Init2();
		Solve2();
	}

	return 0;
}
