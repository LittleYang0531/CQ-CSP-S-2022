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
	
	int const N = 1e5 + 10;
	int const LGN = 18;
	
	struct Val {
		int mi, mx;
	};
	
	Val vinit(int v) {
		if (v == INF) {
			return { INF, NINF };
		}
		
		return { v, v };
	}
	
	Val vplus(const Val& a, const Val& b) {
		return { std::min(a.mi, b.mi), std::max(a.mx, b.mx) };
	}
	
	struct SparseTable {
		Val st[LGN + 1][N + 1];
		int lg[N + 1];
		
		void init(int* v, int n) {
			for (int i = 1; i <= n; i++) {
				st[0][i] = vinit(v[i]);
			}
			
			for (int i = 1; (1 << i) <= n; i++) {
				for (int j = 1; j + (1 << i) - 1 <= n; j++) {
					st[i][j] = vplus(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
				}
			}
			
			for (int i = 2; i <= n; i++) {
				lg[i] = lg[i / 2] + 1;
			}
		}
		
		Val ask(int l, int r) {
			assert(l <= r);
			
			int t = lg[r - l + 1];
			return vplus(st[t][l], st[t][r - (1 << t) + 1]);
		}
	};
	
	int a[N + 1];
	int b[N + 1];
	int v[N + 1];
	SparseTable pa, na, pb, nb;
	int n, m, q;
	
	void main() {
		std::cin >> n >> m >> q;
		
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		
		for (int i = 1; i <= m; i++) {
			std::cin >> b[i];
		}
		
		memset(v, 0, sizeof v);
		for (int i = 1; i <= n; i++) {
			if (a[i] >= 0) {
				v[i] = a[i];
			}
			else {
				v[i] = INF;
			}
		}
		pa.init(v, n);
		
		memset(v, 0, sizeof v);
		for (int i = 1; i <= n; i++) {
			if (a[i] <= 0) {
				v[i] = a[i];
			}
			else {
				v[i] = INF;
			}
		}
		na.init(v, n);
		
		memset(v, 0, sizeof v);
		for (int i = 1; i <= m; i++) {
			if (b[i] >= 0) {
				v[i] = b[i];
			}
			else {
				v[i] = INF;
			}
		}
		
		pb.init(v, m);
		
		memset(v, 0, sizeof v);
		for (int i = 1; i <= m; i++) {
			if (b[i] <= 0) {
				v[i] = b[i];
			}
			else {
				v[i] = INF;
			}
		}
		nb.init(v, m);
		
		for (int i = 1; i <= q; i++) {
			int al, ar;
			int bl, br;
			std::cin >> al >> ar >> bl >> br;
			
			auto tpa = pa.ask(al, ar);
			auto tna = na.ask(al, ar);
			auto tpb = pb.ask(bl, br);
			auto tnb = nb.ask(bl, br);
			
			int ans = NINF;
			if (tpa.mi != INF) {
				int cur = INF;
				if (tnb.mi != INF) {
					cur = tpa.mi * tnb.mi;
				}
				else {
					assert(tpb.mi != INF);
					cur = tpa.mx * tpb.mi;
				}
				
				ans = std::max(ans, cur);
			}
			
			if (tna.mi != INF) {
				int cur = INF;
				if (tpb.mi != INF) {
					cur = tna.mx * tpb.mx;
				}
				else {
					assert(tnb.mi != INF);
					cur = tna.mi * tnb.mx;
				}
				
				ans = std::max(ans, cur);
			}
			
			fmtout("{}\n", ans);
		}
	}
	
	void clear() {
		
	}
	
	void init() {
		
	}
}

signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
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
