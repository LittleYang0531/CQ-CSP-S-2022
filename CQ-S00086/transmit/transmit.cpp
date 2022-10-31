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
	
	int const N = 2e5 + 10;
	int const LGN = 18;
	int const K = 4;
	
	struct Matrix {
		int d[K][K];
		int n, m;
		
		Matrix() {
			init(0, 0);
		}
		
		Matrix(int n, int m) {
			init(n, m);
		}
		
		void init(int n, int m) {
			this->n = n;
			this->m = m;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					d[i][j] = INF;
				}
			}
		}
		
		int* operator[](int x) {
			return d[x];
		}
		
		const int* operator[](int x) const {
			return d[x];
		}
		
		Matrix operator*(const Matrix& rhs) const {
			assert(m == rhs.n);
			
			Matrix res(n, rhs.m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (d[i][j] == INF) {
						continue;
					}
					
					int v = d[i][j];
					for (int k = 0; k < rhs.m; k++) {
						if (rhs[j][k] != INF) {
							res[i][j] = std::min(res[i][j], v + rhs[j][k]);
						}
					}
				}
			}
			
			return res;
		}
	};
	
	using Val = Matrix;
	
	Val vplus(const Val& a, const Val& b) {
		return a * b;
	}
	
	struct SegmentTree {
		struct Node {
			int l, r;
			Val v;
		};
		
		Node nd[4 * N + 1];
		
		void build(int x, int l, int r, Matrix* t) {
			nd[x].l = l;
			nd[x].r = r;
			
			if (l == r) {
				nd[x].v = t[l];
			}
			else {
				int mid = (l + r) >> 1;
				build(2 * x, l, mid, t);
				build(2 * x + 1, mid + 1, r, t);
				
				pushup(x);
			}
		}
		
		void pushup(int x) {
			nd[x].v = vplus(nd[2 * x].v, nd[2 * x + 1].v);
		}
		
		Val prod(int x, int l, int r) {
			if (nd[x].l >= l && nd[x].r <= r) {
				return nd[x].v;
			}
			else {
				int mid = (nd[x].l + nd[x].r) >> 1;
				
				if (r <= mid) {
					return prod(2 * x, l, r);
				}
				else if (l > mid) {
					return prod(2 * x + 1, l, r);
				}
				else {
					return vplus(prod(2 * x, l, r), prod(2 * x + 1, l, r));
				}
			}
		}
	};
	
	int n, q, k;
	SegmentTree seg;
	std::vector<int> tree[N + 1];
	int v[N + 1];
	int fa[LGN + 1][N + 1];
	int prt[N + 1];
	int size[N + 1];
	int dep[N + 1];
	int hson[N + 1];
	int top[N + 1];
	int st[N + 1];
	int vsum[N + 1];
	Matrix t[N + 1];
	int tot;
	
	void dfs(int x, int fa) {
		prt[x] = fa;
		dep[x] = dep[fa] + 1;
		size[x] = 1;
		vsum[x] = vsum[fa] + v[x];
		Solve::fa[0][x] = fa;
		
		for (auto& to : tree[x]) {
			if (to != fa) {
				dfs(to, x);
				
				size[x] += size[to];
				if (size[to] > size[hson[x]]) {
					hson[x] = to;
				}
			}
		}
	}
	
	void make_top(int x, int v) {
		top[x] = v;
		tot++;
		st[x] = tot;
		if (hson[x]) {
			make_top(hson[x], v);
		}
		
		for (auto& to : tree[x]) {
			if (to != prt[x] && to != hson[x]) {
				make_top(to, to);
			}
		}
	}
	
	int lca(int x, int y) {
		while (top[x] != top[y]) {
			if (dep[top[x]] < dep[top[y]]) {
				std::swap(x, y);
			}
			
			x = prt[top[x]];
		}
		
		if (dep[x] > dep[y]) {
			std::swap(x, y);
		}
		
		return x;
	}
	
	void prepare() {
		for (int i = 1; (1 << i) <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fa[i][j] = fa[i - 1][fa[i - 1][j]];
			}
		}
	}
	
	int jump(int x, int d) {
		for (int i = LGN; i >= 0; i--) {
			if (dep[fa[i][x]] >= d) {
				x = fa[i][x];
			}
		}
		
		return x;
	}
	
	Matrix prod(int u, int v) {
		Matrix res;
		bool init = false;
		while (top[u] != top[v]) {
			if (!init) {
				res = seg.prod(1, st[top[u]], st[u]);
			}
			else {
				res = seg.prod(1, st[top[u]], st[u]) * res;
			}
			
			u = prt[top[u]];
		}
		
		if (!init) {
			res = seg.prod(1, st[v], st[u]);
		}
		else {
			res = seg.prod(1, st[v], st[u]) * res;
		}
		
		return res;
	}
	
	int get(int u, int v) {
		auto t = prod(u, v);
		if (k == 2) {
			Matrix tt(2, 1);
			tt[0][0] = Solve::v[u];
			tt[1][0] = INF;
			t = t * tt;
			return t[0][0];
		}
	}
	
	void main() {
		std::cin >> n >> q >> k;
		
		for (int i = 1; i <= n; i++) {
			std::cin >> v[i];
		}	
		
		for (int i = 2; i <= n; i++) {
			int x, y;
			std::cin >> x >> y;
			
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		
		dfs(1, 0);
		make_top(1, 1);
		
		if (k == 1) {
			for (int i = 1; i <= q; i++) {
				int u, v;
				std::cin >> u >> v;
				
				int anc = lca(u, v);
				fmtout("{}\n", vsum[u] + vsum[v] - vsum[anc] - vsum[prt[anc]]);
			}
			
			return;
		}
		
		if (k == 2) {
			for (int i = 1; i <= n; i++) {
				t[st[i]].init(2, 2);
				t[st[i]][0][0] = v[prt[i]];
				t[st[i]][0][1] = INF;
				t[st[i]][1][0] = v[prt[prt[i]]];
				t[st[i]][1][1] = INF;
			}
			
			seg.build(1, 1, n, t);
			
			for (int i = 1; i <= q; i++) {
				int u, v;
				std::cin >> u >> v;
				
				int anc = lca(u, v);
				
				int ans = get(u, anc) + get(v, anc) - Solve::v[anc];
				
				int t1 = jump(u, dep[anc] + 1);
				int t2 = jump(v, dep[anc] + 1);
				if (dep[t1] <= dep[u] && dep[t2] <= dep[v]) {
					ans = std::min(ans, get(u, t1) + get(v, t2));
				}
				
				fmtout("{}\n", ans);
			}
		}
	}
	
	void clear() {
		
	}
	
	void init() {
		
	}
}

signed main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
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
