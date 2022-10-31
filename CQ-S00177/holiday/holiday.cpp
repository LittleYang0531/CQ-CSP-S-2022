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
const int MAXN = 2.5e3 + 10, INF = ~0U >> 1, inf = ~0U >> 2;
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
};
using namespace stupid_lrc;
int n, m, k, d[MAXN][MAXN]; ll w[MAXN], ans;
bool vis[MAXN]; vector <int> lnk[MAXN], cus[MAXN];

il void solve(int s, int *d) {
	queue <int> q; memset(vis, 0, sizeof vis);
	rep1(i, 1, n) d[i] = INF;
	d[s] = 0; q.push(s);
	while (q.size()) {
		int now = q.front(); q.pop();
		if (vis[now]) continue;
		vis[now] = true;
		for (auto v : lnk[now]) if (d[v] > d[now] + 1) d[v] = d[now] + 1, q.push(v);
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n, m, k); rep1(i, 2, n) read(w[i]);
	rep1(i, 1, m) {
		int u, v; read(u, v);
		lnk[u].eb(v); lnk[v].eb(u);
	}
	rep1(i, 1, n) solve(i, d[i]);
//	rep1(i, 1, n) rep1(j, 1, n) {
//		cout << i << ' ' << j << ": " << d[i][j] << endl;
//	}
	rep1(i, 1, n) rep1(j, 1, n) if (i ^ j && d[i][j] <= k + 1 && d[1][j] <= (k + 1) * 2) cus[i].eb(j);
//	int len = cus[1].size();
	for (auto i : cus[1]) for (auto j : cus[1]) {
		if (i == j) continue;
		for (auto v1 : cus[i]) for (auto v2 : cus[j]) {
			if (v1 == v2 || v1 == 1 || v2 == 1 || v2 == i || v1 == j || d[v1][v2] > k + 1) continue;
			ans = max(ans, w[i] + w[j] + w[v1] + w[v2]);
//			cout << i << ' ' << j << ' ' << v1 << ' ' << v2 << ' ' << w[i] + w[j] + w[v1] + w[v2] << endl;
		}
	} cout << ans << endl;
	return 0;
}

