#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, u, v, front, back, q[2500005][2], f[2505], mx[2505][3], e[2505][2505];
ll ans, s[2505], dp[2505][3];
vector<int> g[2505];
void dfs(const int& S, int now, int step) {
	if(now != S) {
		e[S][++e[S][0]] = now;
	}
	f[now] = step;
	++step;
	if(step > k) return;
	const int LEN = g[now].size();
	for(int i = 0; i < LEN; ++i)
		if(step < f[g[now][i]]) dfs(S, g[now][i], step);
}
void calc(int A, int B, int C, int D) {
	if(mx[A][B] != mx[C][D] && mx[A][B] != C && mx[C][D] != A) ans = max(ans, dp[A][B] + dp[C][D]);
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 2; i <= n; ++i) {
		scanf("%lld", &s[i]);
	}
	while(m--) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i][1] = dp[i][2] = -(1ll << 61);
		memset(f, 0x3f, sizeof(f));
		f[i] = -1;
		front = 0, back = -1;
		++back, q[back][0] = i, q[back][1] = -1;
		while(front <= back) {
			u = q[front][0], v = q[front][1];
			++front;
			if(v == f[u]) {
				if(u != i) {
					e[i][++e[i][0]] = u;
				}
				if(f[u] + 1 > k) continue;
				const int LEN = g[u].size();
				for(int j = 0; j < LEN; ++j)
					if(f[u] + 1 < f[g[u][j]]) {
						++back, q[back][0] = g[u][j], q[back][1] = f[u] + 1;
						f[g[u][j]] = f[u] + 1;
					}
				f[u] = -114514;
			}
		}
//		dfs(i, i, -1);
	}
//	for(int i = 1; i <= n; ++i) {
//		cerr << i << ":\n";
//		for(int j = 1; j <= e[i][0]; ++j)
//			cerr << e[i][j] << " ";
//		cerr << endl;
//	}
	for(int i = 1; i <= e[1][0]; ++i) {
		u = e[1][i];
		for(int j = 1; j <= e[u][0]; ++j) {
			v = e[u][j];
			if(v != 1) {
				if(dp[v][0] < s[u] + s[v]) {
					dp[v][2] = dp[v][1];
					dp[v][1] = dp[v][0];
					dp[v][0] = s[u] + s[v];
					mx[v][2] = mx[v][1];
					mx[v][1] = mx[v][0];
					mx[v][0] = u;
				}
				else if(dp[v][1] < s[u] + s[v]) {
					dp[v][2] = dp[v][1];
					dp[v][1] = s[u] + s[v];
					mx[v][1] = u;
				}
				else if(dp[v][2] < s[u] + s[v]) {
					mx[v][2] = u;
					dp[v][2] = s[u] + s[v];
				}
			}
		}
	}
//	for(int i = 1; i <= n; ++i) cerr << i << ":" << mx[i] << "," << dp[i][0] << "," << dp[i][1] << endl;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= e[i][0]; ++j) {
			v = e[i][j];
			calc(i, 0, v, 0);
			calc(i, 0, v, 1);
			calc(i, 0, v, 2);
			calc(i, 1, v, 0);
			calc(i, 1, v, 1);
			calc(i, 1, v, 2);
			calc(i, 2, v, 0);
			calc(i, 2, v, 1);
			calc(i, 2, v, 2);
//			if(dp[v][0] >= 0) {
//				if(mx[i] != mx[v]) {
//					if(dp[i][0] + dp[v][0] > ans) {
//						ans = dp[i][0] + dp[v][0];
//						cerr << i << "|0-" << v << "|0\n";
//					}
//				}
//				else {
//					if(dp[i][1] >= 0) {
//						if(dp[i][1] + dp[v][0] > ans) {
//							ans = dp[i][1] + dp[v][0];
//							cerr << i << "|1-" << v << "|0\n";
//						}
//					}
//					if(dp[v][1] >= 0) {
//						if(dp[i][0] + dp[v][1] > ans) {
//							ans = dp[i][0] + dp[v][1];
//							cerr << i << "|0-" << v << "|1\n";
//						}
//					}
//				}
//			}
		}
	}
	printf("%lld", ans);
	return 0;
}
