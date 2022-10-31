#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m;
vector<int> edge[N];
int vis[N][N];
bool flag;
bool aaa;
int col, cc[N];
bool vv[N];

void DFS(int u, int prt, int c) {
	int sum = 0;
	vv[u] = 1;
	cc[u] = c;
	for (auto v : edge[u])
		if (v != prt && vis[u][v] == 1) {
			if (vv[u] && cc[v] == c) {
				aaa = 1;
				return;
			}
			if (vv[v] && cc[v]) {
				return;
			}
			DFS(v, u, c);
		} 
	if (sum != 1) {
		flag = 0;
	}
}

void Check() {
	memset(vv, 0, sizeof vv);
	memset(cc, 0, sizeof cc);
	col = 0;
	flag = 1;
	for (int i = 1; i <= n; i++) {
		if (!vv[i]) {
			aaa = 0;
			DFS(i, 0, ++col);
			if (!aaa) {
				flag = 0;
				return;
			}
		}
		if (!flag)
			return;
	}
}
 
void Read() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		vis[u][v] = 1;
	}
}

void Solve() {
	int q;
	cin >> q;
	while (q--) {
		int op, u, v;
		cin >> op;
		if (op == 1) {
			cin >> u >> v;
			vis[u][v] = -1;
		}
		if (op == 2) {
			cin >> u;
			for (int i = 1; i <= n; i++)
				if (vis[i][u])
					vis[i][u] = -1;
		}
		if (op == 3) {
			cin >> u >> v;
			vis[u][v] = 1;
		}
		if (op == 4) {
			cin >> u;
			for (int i = 1; i <= n; i++)
				if (vis[i][u])
					vis[i][u] = 1;
		}
		Check();
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	Read();
	Solve();

	return 0;
}
