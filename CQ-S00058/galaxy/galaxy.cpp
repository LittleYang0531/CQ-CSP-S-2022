#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= (int)n; ++i)
#define rep2(i, j, n) for (int i(j); i >= (int)n; --i)
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) f -= (ch == '-') << 1, ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
	x *= f;
}
inline int read() {int x; read(x); return x;}
template <typename T, typename ...L> inline void read(T &x, L &...y) {read(x); read(y...);}
const int inf = 0x3f3f3f3f;
const int N = 5e5 + 5;
int n, m, q;
int Pout[N], vPout[N], cnt[N];
set <int> s[2][N];
signed main(void) {
	freopen("galaxy.in", "r", stdin); 
	freopen("galaxy.out", "w", stdout);
	read(n, m);
	int sum = m;
	rep1(i, 1, m) {
		int u, v; read(u, v);
		++Pout[u]; ++vPout[u];
		s[0][v].insert(u); //0表示未被删除的边 
	}
	rep1(i, 1, n) ++cnt[vPout[i]];
	int q = read();
	rep1(i, 1, q) {
		int op = read();
		if (op == 1) {
			int u = read(), v = read();
			--cnt[vPout[u]]; ++cnt[--vPout[u]];
			--sum;
			s[1][v].insert(u);
			s[0][v].erase(s[0][v].find(u));
		} else if (op == 2) {
			int u = read();
			for (auto p : s[0][u]) {
				--cnt[vPout[p]];
				++cnt[--vPout[p]];
				--sum;
				s[1][u].insert(p);
			}
			s[0][u].clear();
		} else if (op == 3) {
			int u = read(), v = read();
			--cnt[vPout[u]]; ++cnt[++vPout[u]];
			++sum;
			s[0][v].insert(u);
			s[1][v].erase(s[1][v].find(u));
		} else {
			int u = read();
			for (auto p : s[1][u]) {
				--cnt[vPout[p]];
				++cnt[++vPout[p]];
				++sum;
				s[0][u].insert(p);
			} s[1][u].clear();
		}
		puts(cnt[1] == n && sum == n ? "YES" : "NO");
	}
}
/*
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
我爱 CCF
*/
