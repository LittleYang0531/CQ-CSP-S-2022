#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#define LL long long
#define uint unsigned int
#define uLL unsigned long long
#define mr make_pair
#define pr pair <LL, int>
using namespace std;
const int MAXN = 2505, MAXM = 1e4 + 5, MAXK = 105, inf = 0x3f3f3f3f;
const LL lof = 4e18 + 5;
int n, m, k;
LL a[MAXN];
int DP[MAXN][MAXN], que[MAXN], head, tail;
// 边权全为 1, bfs 
pr dp[MAXN][3];
// <val, id>
// 走了 k 步，到第 i 个点，经过 2 个取值点，最大、次大 
vector <int> v[MAXN];
void read(int &x) {
	x = 0; bool f = 1; char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') f = 0;
	for(; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = (f ? x : -x);
}
void bfs(int qd) {
	for(int i = 1; i <= n; i ++) DP[qd][i] = inf;
	DP[qd][qd] = -1; head = 1; tail = 0; que[++ tail] = qd;
	int x;
	while(head <= tail) {
		x = que[head ++];
		for(auto y : v[x]) {
			if(DP[qd][y] == inf) {
				DP[qd][y] = DP[qd][x] + 1; que[++ tail] = y;
			}
		}
	}
}
void Get(int x, int f, pr qwq) {
	for(int i = f; i <= 2; i ++) {
		if(qwq > dp[x][i]) swap(qwq, dp[x][i]);
	}
}
LL Max(LL x, LL y) { return x > y ? x : y; }
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	int x, y; read(n); read(m); read(k);
	for(int i = 2; i <= n; i ++) scanf("%lld", &a[i]);
	for(int i = 1; i <= m; i ++) {
		read(x); read(y); v[x].push_back(y); v[y].push_back(x);
	}
	for(int i = 0; i <= n; i ++) for(int u = 0; u <= 2; u ++) dp[i][u] = mr(-lof, 0);
	for(int i = 1; i <= n; i ++) {
		bfs(i);
	}
	for(int i = 2; i <= n; i ++) {
		for(int j = 2; j <= n; j ++) {
			if(i == j || DP[i][j] > k || DP[1][i] > k ) continue;
			pr pii = mr(a[i] + a[j], i); Get(j, 0, pii);
		}
	}
	LL ans = 0;
	for(int i = 2; i <= n; i ++) {
		for(int j = 2; j < i; j ++) {
			if(DP[i][j] > k) continue;
			for(int U = 0; U <= 2; U ++) {
				for(int V = 0; V <= 2; V ++) {
					if(dp[i][U].second != j && dp[i][U].second != dp[j][V].second
					&& dp[j][V].second != i) { ans = Max(ans, dp[i][U].first + dp[j][V].first); 
					}
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}

