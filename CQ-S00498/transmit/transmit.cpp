#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 4e5 + 10;
void read(int &x) {
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') f |= c == '-', c = getchar();
	x = 0;
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	x = f ? -x : x;
}

int n, q, k, s, t, cnt, sum;
int head[N], ver[N], nxt[N];
int f[N], v[N], a[N];
long long dp[N];
bool vis[N];

void add(int u, int v) {
	ver[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs(int u, int step) {
	f[step] = u;
	if (u == t) {
		sum = step;
		return;
	}
	for (int i = head[u]; i; i = nxt[i]) {
		int v = ver[i];
		if (vis[v] == 0) {
			vis[v] = 1, dfs(v, step + 1);
		}
	}
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n), read(q), read(k);
	for (int i = 1; i <= n; i++) 
		read(v[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u), read(v);
		add(u, v), add(v, u);
	}
	for (int i = 1; i <= q; i++) {
		sum = 0, memset(vis, 0, sizeof vis);
		memset(dp, 127, sizeof dp);
		read(s), read(t);
		vis[s] = 1, dfs(s, 0);
//		puts("");
		if (sum <= k)  {
			printf("%d\n", v[s] + v[t]);
		} else {
//			puts("");
//			for (int i = 1; i <= sum; i++) 
//				printf("%d ", a[i]);
			for (int i = 1; i <= k; i++) {
				dp[i] = v[s] + v[a[i]];
			}
			for (int i = k + 1; i <= sum; i++) {
				for (int j = i - 1; j >= i - k; j--) {
					dp[i] = min(dp[i], dp[j] + v[a[i]]);
				}
			}
			printf("%d\n", dp[sum]);
		}
	}
	
	return 0;
}


