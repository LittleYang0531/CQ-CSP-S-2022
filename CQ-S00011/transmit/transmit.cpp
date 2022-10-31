#include <bits/stdc++.h>
using namespace std;
#define il inline
#define mp make_pair
#define pb push_back
#define ptc putchar
#define R(i, l, r) for (int i = l; i <= r; ++i)
#define debug puts("---------------------------")
typedef pair <int, int> PII;
typedef long long ll;
namespace CYYH {
	template <typename T>
	il void read(T &x) {
		x = 0; T f = 1; char ch;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar(); x *= f;
	}
	template <typename T, typename ...L>
	il void read(T &x, L &...y) {read(x); read(y...);}
	template <typename T>
	il void write(T x) {
		if (x < 0) ptc('-'), x = -x;
		if (x > 9) write(x / 10);
		ptc(x % 10 + '0');
	}
	template <typename T, typename ...L>
	il void write(T x, L ...y) {write(x), ptc(' '); write(y...);}
}
using namespace CYYH;
#define int ll
const int N = 2005;
int n, q, k, val[N], dis[N][N];
vector <int> E[N];
bool vis[N];
void bfs(int root) {
	memset(vis, 0, sizeof vis);
	queue <PII> q;
	q.push(mp(root, 0));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		if (y > k) continue;
		if (x ^ root) dis[root][x] = dis[x][root] = val[root] + val[x];
		for (auto v : E[x]) {
			q.push(mp(v, y + 1));
		}
	}
}
signed main() {
//	freopen("transmit3.in", "r", stdin);
//	freopen("my4.out", "w", stdout);
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n, q, k);
	R(i, 1, n) read(val[i]);
	R(i, 1, n) {
		R(j, 1, n) {
			if (i ^ j) dis[i][j] = INT_MAX;
		}
	}
	R(i, 1, n - 1) {
		int u, v; read(u, v);
		E[u].pb(v), E[v].pb(u);
	}
	R(i, 1, n) bfs(i);
//	R(i, 1, n) {
//		R(j, 1, n) cout << i << ' ' << j << ' ' << dis[i][j] << endl;
//	}
	R(K, 1, n) {
		R(i, 1, n) {
			R(j, 1, n) {
				dis[i][j] = min(dis[i][K] + dis[K][j], dis[i][j]);
			}
		}
	}
	while (q--) {
		int u, v;
		read(u, v);
		write(dis[u][v] + val[u] + val[v] >> 1), ptc('\n');
	}
	return 0;
}


