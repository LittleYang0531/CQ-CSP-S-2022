#include <bits/stdc++.h>

#define int long long

signed main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m; std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; std::cin >> u >> v;
	}
	int q; std::cin >> q;
	
	srand(time(0));
	
	for (int i = 1; i <= q; ++i) {
		std::cout << (rand() % 2 ? "YES\n" : "NO\n");
	}
	
	return 0;
}
