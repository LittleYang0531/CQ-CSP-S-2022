#include <bits/stdc++.h>

namespace IO {
	std::ostream& fmtout(const char* out) {
		while (*out) {
			if (*out == '{' && *(out + 1) == '}') {
				throw std::invalid_argument("???");
			}
			
			std::cout << *out;
			out++;
		}
		
		return std::cout;
	}
	
	template <class Fst, class... Nxt>
	std::ostream& fmtout(const char* out, const Fst& fst, const Nxt&... nxt) {
		while (*out) {
			if (*out == '{' && *(out + 1) == '}') {
				std::cout << fst;
				return fmtout(out + 2, nxt...);
			}
			
			std::cout << *out;
			out++;
		}
		
		throw std::invalid_argument("???");
	}
	
	std::ostream& fmterr(const char* out) {
		while (*out) {
			if (*out == '{' && *(out + 1) == '}') {
				throw std::invalid_argument("???");
			}
			
			std::cerr << *out;
			out++;
		}
		
		return std::cerr;
	}
	
	template <class Fst, class... Nxt>
	std::ostream& fmterr(const char* out, const Fst& fst, const Nxt&... nxt) {
		while (*out) {
			if (*out == '{' && *(out + 1) == '}') {
				std::cerr << fst;
				return fmterr(out + 2, nxt...);
			}
			
			std::cerr << *out;
			out++;
		}
		
		throw std::invalid_argument("???");
	}
}

namespace Solve {
	using namespace IO;
	
	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	
	int const N = 5e5 + 10;
	
	int n, m, q;
	std::vector<int> graph[N + 1];
	
	namespace BF {
		std::set<int> s1[N + 1];
		std::set<int> s2[N + 1];
		int d[N + 1];
		int cnt;
		
		void main() {
			for (int i = 1; i <= n; i++) {
				d[i] = graph[i].size();
				cnt += d[i] != 1;
				for (auto& to : graph[i]) {
					s1[to].insert(i);
				}
			}
			
			std::cin >> q;
			for (int i = 1; i <= q; i++) {
				int op;
				std::cin >> op;
				
				if (op == 1) {
					int u, v;
					std::cin >> u >> v;
					
					s1[v].erase(u);
					s2[v].insert(u);
					
					cnt -= d[u] != 1;
					d[u]--;
					cnt += d[u] != 1;
				}
				else if (op == 2) {
					int x;
					std::cin >> x;
					
					for (auto& v : s1[x]) {
						s2[x].insert(v);
						cnt -= d[v] != 1;
						d[v]--;
						cnt += d[v] != 1;
					}
					
					s1[x].clear();
				}
				else if (op == 3) {
					int u, v;
					std::cin >> u >> v;
					
					s2[v].erase(u);
					s1[v].insert(u);
					
					cnt -= d[u] != 1;
					d[u]++;
					cnt += d[u] != 1;
				}
				else {
					int x;
					std::cin >> x;
					
					for (auto& v : s2[x]) {
						s1[x].insert(v);
						cnt -= d[v] != 1;
						d[v]++;
						cnt += d[v] != 1;
					}
					
					s2[x].clear();
				}
				
				fmtout("{}\n", cnt == 0 ? "YES" : "NO");
			}
		}
	}
	
	namespace Sqrt {
		int const B = 1000;
		int const TB = (N + B - 1) / B;
		int const UB = std::max(B, TB);
		
		std::vector<int> s1[N + 1];
		std::vector<int> s2[N + 1];
		int d[N + 1];
		int dd[N + 1];
		int cnt;
		bool used[N + 1];
		int tot;
		int id[N + 1];
		std::vector<int> cont[N + 1];
		int rl[N + 1];
		int rr[N + 1];
		std::vector<int> rest[N + 1];
		bool is[N + 1];
		int last[N + 1];
		
		void add(int l, int r, int v) {
			if (l > r) {
				return;
			}
			
			cnt -= dd[l] == 0;
			dd[l] += v;
			cnt += dd[l] == 0;
			
			if (r + 1 <= n) {
				cnt -= dd[r + 1] == 0;
				dd[r + 1] -= v;
				cnt += dd[r + 1] == 0;
			}
		}
		
		void main() {
			for (int i = 1; i <= n; i++) {
				for (auto& to : graph[i]) {
					cont[to].push_back(i);
				}
			}
			
			for (int i = 1; i <= n; i++) {
				if ((int) cont[i].size() >= B) {
					is[i] = true;
					rl[i] = tot + 1;
					for (auto& to : cont[i]) {
						if (!used[to]) {
							tot++;
							id[to] = tot;
							used[to] = true;
						}
						else {
							rest[i].push_back(to);
						}
					}
					
					rr[i] = tot;
				}
			}
			
			for (int i = 1; i <= n; i++) {
				if (!used[i]) {
					used[i] = true;
					tot++;
					id[i] = tot;
				}
			}
			
			for (int i = 1; i <= n; i++) {
				d[id[i]] = graph[i].size();
			}
			
			for (int i = 1; i <= n; i++) {
				dd[i] = d[i] - d[i - 1];
				if (dd[i] == 0) {
					cnt++;
				}
			}
			
			std::cin >> q;
			for (int i = 1; i <= q; i++) {
				int op;
				std::cin >> op;
				
				if (op == 1) {
					int u, v;
					std::cin >> u >> v;
					
					s1[v].push_back(u);
					add(id[u], id[u], -1);
				}
				else if (op == 3) {
					int u, v;
					std::cin >> u >> v;
					
					s2[v].push_back(u);
					add(id[u], id[u], 1);
				}
				else if (op == 2) {
					int x;
					std::cin >> x;
					
					for (auto& v : s1[x]) {
						add(id[v], id[v], 1);
					}
					
					for (auto& v : s2[x]) {
						add(id[v], id[v], -1);
					}
					
					s1[x].clear();
					s2[x].clear();
					
					if (last[x] == 0) {
						if (is[x]) {
							add(rl[x], rr[x], -1);
							for (auto& v : rest[x]) {
								add(id[v], id[v], -1);
							}
						}
						else {
							for (auto& v : cont[x]) {
								add(id[v], id[v], -1);
							}
						}
						
						last[x] = 1;
					}
				}
				else {
					int x;
					std::cin >> x;
					
					for (auto& v : s1[x]) {
						add(id[v], id[v], 1);
					}
					
					for (auto& v : s2[x]) {
						add(id[v], id[v], -1);
					}
					
					s1[x].clear();
					s2[x].clear();
					
					if (last[x] == 1) {
						if (is[x]) {
							add(rl[x], rr[x], 1);
							for (auto& v : rest[x]) {
								add(id[v], id[v], 1);
							}
						}
						else {
							for (auto& v : cont[x]) {
								add(id[v], id[v], 1);
							}
						}
						
						last[x] = 0;
					}
				}
				
				if (dd[1] == 1 && cnt == n - 1) {
					fmtout("YES\n");
				}
				else {
					fmtout("NO\n");
				}
			}
		}
	}
	
	void main() {
		std::cin >> n >> m;
		
		for (int i = 1; i <= m; i++) {
			int x, y;
			std::cin >> x >> y;
			
			graph[x].push_back(y);
		}
		
//		BF::main();
		Sqrt::main();
	}
	
	void clear() {
		
	}
	
	void init() {
		
	}
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int t = 1;
//	std::cin >> t;
	
	Solve::init();
	for (; t; t--) {
		Solve::main();
		Solve::clear();
	}
}
