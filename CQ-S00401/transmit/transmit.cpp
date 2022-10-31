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
} const van MaxN = 2e5 + 10;
van n, q, k;
van v[MaxN];
vector<van> g[MaxN];
van dp[MaxN][4];
van fa[MaxN], dep[MaxN]; 
bool used[MaxN];
van sum[MaxN];
void DFS(van now = 1) {
	used[now] = 1; sum[now] += v[now];
	for (int i = 0; i < g[now].size(); i++) {
		van nxt = g[now][i];
		if (used[nxt]) continue;
		fa[nxt] = now; dep[nxt] = dep[now] + 1;
		sum[nxt] = sum[now]; DFS(nxt); 
	} used[now] = 0;
}
void DFS2(van now) {
	used[now] = 1;
	van minv = 1e18;
	for (int i = 0; i < g[now].size(); i++) {
		van nxt = g[now][i];
		if (used[nxt]) continue;
		minv = min(minv, v[nxt]);
	}
	for (int i = 0; i < g[now].size(); i++) {
		van nxt = g[now][i];
		if (used[nxt]) continue;
		for (int j = 1; j <= k; j++) {
			// 如果不选取下一个点
			if (j != 1) dp[nxt][j - 1] = min(dp[nxt][j - 1], dp[now][j]);
			dp[nxt][k] = min(dp[nxt][k], dp[now][j] + v[nxt]);
		}
		DFS2(nxt);
	}
	for (int i = 0; i < g[now].size(); i++) {
		van nxt = g[now][i];
		if (used[nxt]) continue;
		for (int j = 1; j <= k; j++) {
			// 如果不选取下一个点
			if (j != 1) dp[now][j - 1] = min(dp[now][j - 1], dp[nxt][j]);
			dp[now][k] = min(dp[now][k], dp[nxt][j] + v[now]);
		}
	}
	if (k == 3) dp[now][2] = min(dp[now][2], dp[now][1] + minv);
	used[now] = 0;
	return;
}
namespace solve1 {
	void main() {
		for (int qq = 1; qq <= q; qq++) {
//			cerr << qq << endl;
			van st, en; read(st), read(en);
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= k; j++) dp[i][j] = 1e18;
			dp[st][k] = v[st]; DFS2(en);
			print(dp[en][k]), putchar('\n');
		}
	}
}
namespace solve2 {
	van up[MaxN][22];
	van LCA(van a, van b) {
		if (dep[a] < dep[b]) swap(a, b);
		for (int i = 20; i >= 0; i--)
			if (dep[up[a][i]] >= dep[b]) a = up[a][i];
		if (a == b) return a;
		for (int i = 20; i >= 0; i--) 
			if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
		return up[a][0];
	}
	void main() {
		for (int i = 1; i <= n; i++) up[i][0] = fa[i];
		for (int j = 1; j <= 20; j++) {
			for (int i = 1; i <= n; i++) up[i][j] = up[up[i][j - 1]][j - 1];
		}
		for (int i = 1; i <= q; i++) {
			van a, b; read(a), read(b);
			van lca = LCA(a, b);
			van ans = sum[a] + sum[b];
			ans -= sum[lca] + sum[fa[lca]];
			print(ans), putchar('\n');
		}
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n), read(q), read(k);
	for (int i = 1; i <= n; i++) read(v[i]);
	for (int i = 1; i < n; i++) {
		van a, b; read(a), read(b);
		g[a].push_back(b);
		g[b].push_back(a);
	} dep[1] = 1; DFS();
	if (n <= 2000 && q <= 2000) solve1::main();
	else solve2::main();
	return 0;
}

