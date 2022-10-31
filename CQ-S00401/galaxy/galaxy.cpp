#include<bits/stdc++.h>
using namespace std;
typedef long long van;
template<typename T> inline
void read(T& x) {
	T f = 1, b = 0; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	} while (isdigit(ch))
		b *= 10, b += ch - '0', ch = getchar();
	x = f * b; return;
}
template<typename T> inline
void print(T x, int jz = 10) {
	if (x == 0) return putchar('0'), void();
	if (x < 0) putchar('-'), x = -x;
	van st[129] = {0}, k = 0;
	while (x) st[++k] = x % jz, x /= jz;
	for (int i = k; i; i--) putchar(st[i] + '0');
} const van MaxN = 5e5 + 10;
vector<pair<van, van> > edge;
map<pair<van, van>, van> id;
van fa[MaxN], out[MaxN];
vector<van> g[MaxN];
van n, m, q; bool e[MaxN];
van aa[MaxN], bb[MaxN];
namespace solve1 {
	void main() {
		for (int qq = 1; qq <= q; qq++) {
//			if (qq % 1000 == 0) cerr << qq / 1000 << endl;
			van op, a, b; read(op), read(a);
			if (op == 1 || op == 3) read(b);
			if (op == 1) {
				van wh = id[{a, b}];
				e[wh] = 0;
			}
			if (op == 2) {
				for (int i = 0; i < m; i++)
					if (bb[i] == a) e[i] = 0;
			}
			if (op == 3) {
				van wh = id[{a, b}];
				e[wh] = 1;
			}
			if (op == 4) {
				for (int i = 0; i < m; i++) 
					if (bb[i] == a) e[i] = 1;
			}
			for (int i = 1; i <= n; i++) {
				van num = 0;
				for (int j = 0; j < g[i].size(); j++) {
					num += e[g[i][j]]; 
					fa[i] = edge[g[i][j]].second;
				}
				if (num != 1) {
					puts("NO");
					goto haha;
				}
			}
			puts("YES");
			haha: continue;
		}
	}
}
namespace solve2 {
	van num = 0;
	void main() {
		for (int i = 0; i < m; i++) out[aa[i]]++;
		for (int i = 0; i < m; i++) if (out[i] != 1) num++;
		for (int qq = 1; qq <= q; qq++) {
//			if (qq % 1000 == 0) cerr << qq / 1000 << endl;
			van op, a, b; read(op), read(a);
			if (op == 1 || op == 3) read(b);
			if (op == 1) {
				if (out[a] == 1) num--;
				out[a]--;
				if (out[a] == 1) num++;
			}
			if (op == 3) {
				if (out[a] == 1) num--;
				out[a]++;
				if (out[a] == 1) num++;
			}
			puts(num == 0 ? "YES" : "NO");
		}
	}
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n), read(m);
	for (int i = 0; i < m; i++) {
		van a, b; read(a), read(b);
		edge.push_back({a, b});
		g[a].push_back(i);
		id[{a, b}] = i;
		e[i] = 1;
		aa[i] = a, bb[i] = b;
	}
	read(q);
	if (n <= 1000 && m <= 10000 && q <= 1000) solve1::main();
	else solve2::main(); 
	return 0;
}

