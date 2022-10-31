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
	#define int long long
	
	using namespace IO;
	
	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	
	int const N = 3010;
	
	struct Vid {
		int v, id;
		
		bool operator<(const Vid& rhs) const {
			return v == rhs.v ? id < rhs.id : v < rhs.v;
		}
	};
	
	struct Val {
		Vid fst, snd;
		
		void insert(const Vid& v) {
			if (fst < v) {
				snd = fst;
				fst = v;
			}
			else if (snd < v) {
				snd = v;
			}
		}
	};
	
	Val merge(Val a, const Val& b) {
		a.insert(b.fst);
		a.insert(b.snd);
		return a;
	}
	
	int v[N + 1];
	std::vector<int> graph[N + 1];
	bool edge[N + 1][N + 1];
	Val vv[N + 1][N + 1];
	bool on[N + 1];
	int t[N + 1];
	int tot;
	Val pre[N + 1];
	Val suf[N + 1];
	int dis[N + 1];
	int n, m, k;
	
	void bfs(int x) {
		std::queue<int> que;
		std::fill(dis + 1, dis + n + 1, INF);
		dis[x] = -1;
		que.push(x);
		
		while (!que.empty()) {
			int t = que.front();
			que.pop();
			
			if (dis[t] > k) {
				return;
			}
			
			edge[x][t] = true;
			for (auto& to : graph[t]) {
				if (dis[to] == INF) {
					dis[to] = dis[t] + 1;
					que.push(to);
				}
			}
		}
	}
	
	void main() {
		std::cin >> n >> m >> k;
		for (int i = 2; i <= n; i++) {
			std::cin >> v[i];
		}
		
		for (int i = 1; i <= m; i++) {
			int x, y;
			std::cin >> x >> y;
			
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		
		for (int i = 1; i <= n; i++) {
			bfs(i);
		}
		
		for (int i = 2; i <= n; i++) {
			tot = 0;
			memset(t, 0, sizeof t);
			memset(pre, 0, sizeof pre);
			memset(suf, 0, sizeof suf);
			memset(on, 0, sizeof on);
			
			for (int j = 2; j <= n; j++) {
				if (j == i) {
					continue;
				}
				
				if (edge[1][j] && edge[j][i]) {
					tot++;
					t[tot] = j;
					on[j] = true;
				}
			}
			
			for (int i = 1; i <= tot; i++) {
				pre[i] = merge(pre[i - 1], { { v[t[i]], t[i] } });
			}
			
			for (int i = tot; i >= 1; i--) {
				suf[i] = merge(suf[i + 1], { { v[t[i]], t[i] } });
			}
			
			for (int j = 1; j <= tot; j++) {
				vv[i][t[j]] = merge(pre[j - 1], suf[j + 1]);
			}
			
			for (int j = 2; j <= n; j++) {
				if (!on[j]) {
					vv[i][j] = pre[tot];
				}
			}
		}
		
		int ans = 0;
		for (int c = 2; c <= n; c++) {
			for (int d = 2; d <= n; d++) {
				if (c == d || !edge[c][d]) {
					continue;
				}
				
				auto t1 = vv[c][d];
				auto t2 = vv[d][c];
				
				auto check = [&](const Vid& a, const Vid& b) {
					if (a.id != b.id && a.id && b.id) {
						ans = std::max(ans, v[c] + v[d] + a.v + b.v);
					}
				};
				
				check(t1.fst, t2.fst);
				check(t1.snd, t2.snd);
				check(t1.fst, t2.snd);
				check(t1.snd, t2.fst);
			}
		}
		
		fmtout("{}\n", ans);
	}
	
	void clear() {
		
	}
	
	void init() {
		
	}
}

signed main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
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
