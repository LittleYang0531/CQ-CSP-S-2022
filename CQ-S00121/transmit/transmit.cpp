#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define ll long long
#define lowbit(x) (x & -x)
using namespace std;
int read();
const int MAXN = 200005, MAXM = 400005;

int n, t, k, u, v;
int head[MAXN], nxt[MAXM], to[MAXM], cnt;
void addEdge(int x, int y) {
	nxt[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y; 
}

ll val[MAXN];
void init() {
	n = read(), t = read(), k = read();
	for (int i = 1; i <= n; i++) scanf("%lld", &val[i]);
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		addEdge(u, v);
		addEdge(v, u);
	}
}

int fr[MAXN], way[MAXN], m;
queue<int> q;
void findpath(int x, int y) {
	m = 0;
	memset(fr, 0, sizeof fr);
	fr[x] = -1;
	q.push(x);
	int id;
	while (q.size()) {
		id = q.front();
		q.pop();
		for (int i = head[id]; i; i = nxt[i]) {
			if (fr[to[i]] == 0) {
				fr[to[i]] = id;
				q.push(to[i]);
			}
		}
	}
	int now = y;
	while (now != -1) {
		way[++m] = now;
		now = fr[now];
	}
	for (int i = 1; i <= m / 2; i++) {
		swap(way[i], way[m - i + 1]);
	}
}

ll dp[MAXN];
void Dp() {
	dp[1] = val[way[1]];
	for (int i = 2; i <= m; i++) {
		dp[i] = 1e17;
		for (int j = 1; j <= k && j < i; j++) {
			dp[i] = min(dp[i], dp[i - j]);
		}
		if (k >= 2 && i > 2) {
			for (int j = head[way[i - 1]]; j; j = nxt[j]) {
				dp[i] = min(dp[i], dp[i - 2] + val[to[j]]);
			}
		}
		dp[i] += val[way[i]];
	}
}

void solve() {
	while (t--) {
		u = read(), v = read();
		findpath(u, v);
		Dp();
		printf("%lld\n", dp[m]);
	}
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	init();
	solve();
	return 0;
}

int read() {
	char x = 0;
	int y = 0;
	while (x < '0' || x > '9')
		x = getchar();
	while (x >= '0' && x <= '9') {
		y = (y << 1) + (y << 3) + (x ^ 48);
		x = getchar();
	}
	return y;
}
