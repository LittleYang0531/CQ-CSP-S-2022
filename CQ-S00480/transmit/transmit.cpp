#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1LL << 50;
constexpr int N = 2E5 + 10;

struct Edge {
	int dis, nxt;
} edges[N * 2];
int head[N], siz;
void add(int from, int dis) {
	edges[++siz].dis = dis;
	edges[siz].nxt = head[from];
	head[from] = siz;
}
int val[N];
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n, Q, k;
	std::cin >> n >> Q >> k;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> val[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		std::cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	
	while (Q--) {
		int x, y;
		std::cin >> x >> y;
		std::cout << "Ö»ÒòÁË¡£\n";
	}
	
	
	
	return 0;
}
