#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 305, INF = 1e9;
const LL INF_ = 1e18;

int n, Q, K, v[N], f[N][N], s, t;
vector<int> p[N];
bitset<N> vis;
LL dp[N][N];

LL dfs(int now) {
	if (now == t) return 0;
	LL ans = INF_;
	for (auto x : p[now])
		if (!vis[x]) {
			vis[x] = 1;
			ans = min(ans, v[x] + dfs(x));
			vis[x] = 0;
		}
	return ans;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &Q, &K);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = i == j ? INF : 0;
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (K == 1) p[a].push_back(b), p[b].push_back(a);
		f[a][b] = f[b][a] = 1;
	}
	if (K == 1) {
		while (Q--) {
			scanf("%d %d", &s, &t);
			printf("%lld\n", v[s] + dfs(s));
		}
		return 0;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][j] <= K) dp[i][j] = i == j ? 0 : v[j];
			else dp[i][j] = INF_;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (f[i][k] <= K && f[k][j] <= K) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	while (Q--) {
		scanf("%d %d", &s, &t);
		printf("%lld\n", v[s] + dp[s][t]);
	}
	// The solution can't work. I just want to get some points with this code.
	// Grass, I know how to program for T1! Maybe I can get 200+ pts, which is still poor & tiny, though. But I don't have enough time to program..... 
	// 延续一下去年传统，祝大家以梦为马，不负韶华（） 
	return 0;
}
