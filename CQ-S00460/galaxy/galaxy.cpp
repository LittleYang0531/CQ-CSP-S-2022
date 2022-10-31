#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
const int N = 5e5, M = 5e5, inf = 0x3f3f3f3f;
int n, m, q;
std::set<int> adj[N + 5];
std::set<int> revadj[N + 5];
std::set<int> adj2[N + 5];
inline void addEdge(const int &u, const int &v) {
	adj2[u].insert(v);
	return;
}
inline void remEdge(const int &u, const int &v) {
	adj2[u].erase(v);
	return;
}
inline bool check() {
	for (int i = 1; i <= n; i++)
		if (adj2[i].size() != 1)
			return false;
	return true;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x].insert(y);
		revadj[y].insert(x);
	}
	for (int i = 1; i <= n; i++)
		adj2[i] = adj[i];
	std::cin >> q;
	for (int i = 0; i < q; i++) {
		int t, x, y;
		std::cin >> t;
		if (t == 1) {
			std::cin >> x >> y;
			remEdge(x, y);
		}
		else if (t == 2) {
			std::cin >> x;
			for (std::set<int>::iterator it = revadj[x].begin(); it != revadj[x].end(); it++)
				remEdge(*it, x);
		}
		else if (t == 3) {
			std::cin >> x >> y;
			addEdge(x, y);
		}
		else if (t == 4) {
			std::cin >> x;
			for (std::set<int>::iterator it = revadj[x].begin(); it != revadj[x].end(); it++)
				addEdge(*it, x);
		}
		std::cout << (check() ? "YES" : "NO") << '\n';
	}
	return 0;
}
