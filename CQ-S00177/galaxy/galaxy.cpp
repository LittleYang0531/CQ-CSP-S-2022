#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= int(r); ++i)
#define rep2(i, l, r) for (int i = l; i >= int(r); --i)
#define fst first
#define snd second
#define mp make_pair
#define eb emplace_back
#define ptc putchar
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 5e5 + 10, INF = ~0U >> 1, inf = ~0U >> 2;
namespace stupid_lrc {
	template <typename T> il void read(T &x) {
		x = 0; int f = 1; char ch;
		while (!isdigit(ch = getchar())) if (ch == '-') f = -1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T, typename ...L> il void read(T &x, L &...y) {
		read(x); read(y...);
	}
	
	il int read() {
		int x; read(x); return x;
	}
};
using namespace stupid_lrc;
int n, m, f[MAXN], dfn[MAXN], low[MAXN], idx[MAXN], siz[MAXN], tot, cnt;
bool vis[MAXN]; stack <int> st;
set <int> lnk[MAXN][2]; vector <int> lnk2[MAXN];

il void dfs(int x) {
	low[x] = dfn[x] = ++tot;
	vis[x] = true; st.push(x);
	for (auto v : lnk[x][1]) {
		if (!dfn[v]) dfs(v);
		if (vis[v]) low[x] = min(low[x], low[v]);
	}
	if (low[x] == dfn[x]) {
		vis[x] = false; idx[x] = ++cnt;
		while (st.top() ^ x) {
			int p = st.top(); st.pop();
			vis[p] = false; idx[p] = cnt;
		} st.pop();
	}
}

il int dp(int x) {
	if (~f[x]) return f[x];
	f[x] = siz[x] > 1;
	for (auto v : lnk2[x]) f[x] |= dp(v);
	return f[x];
}

il bool check1() {
	rep1(i, 1, cnt) if (!dp(i)) return false;
	return true;
}

il bool check2() {
	rep1(i, 1, n) if (lnk[i][1].size() ^ 1) return false;
	return true;
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n, m);
	rep1(i, 1, m) {
		int u, v; read(u, v);
		lnk[u][1].insert(v);
	}
	for (int T = read(), t, u, v; T--; ) {
		read(t); tot = cnt = 0;
		rep1(i, 1, n) lnk2[i].clear(), vis[i] = 0, f[i] = -1, idx[i] = dfn[i] = low[i] = siz[i] = 0;
		while (st.size()) st.pop();
//		puts("sbsb");
		if (t == 1) read(u, v), lnk[u][1].erase(v), lnk[u][0].insert(v);
		else if (t == 2) {
			read(u);
			rep1(i, 1, n) {
				if (lnk[i][1].find(u) != lnk[i][1].end()) {
					lnk[i][1].erase(u); lnk[i][0].insert(u);
				}
			}
		} else if (t == 3) read(u, v), lnk[u][0].erase(v), lnk[u][1].insert(v);
		else {
			read(u);
			rep1(i, 1, n) {
				if (lnk[i][0].find(u) != lnk[i][0].end()) {
					lnk[i][0].erase(u); lnk[i][1].insert(u);
				}
			}
		}
		rep1(i, 1, n) if (!dfn[i]) dfs(i);
//		puts("sbsb");
		rep1(i, 1, n) ++siz[idx[i]];
		rep1(i, 1, n) {
			for (auto v : lnk[i][1]) if (idx[i] ^ idx[v]) lnk2[idx[i]].eb(idx[v]);
		}
		if (check2() && check1()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

