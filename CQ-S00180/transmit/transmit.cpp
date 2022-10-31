#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, k, a, b, LCA, cnt, tg, qwq[200005], qaq[200005], lg[200005], v[200005], dep[200005], fa[200005][20];
ll sum[200005], dp[200005];
vector<int> g[200005];
void read(int& x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	x *= f;
}
void write(ll x) {
	static char buffer[20];
	int p = -1;
	if(!x) {
		putchar('0');
		return;
	}
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	while(x) {
		buffer[++p] = (x % 10) ^ 48;
		x /= 10;
	}
	while(~p) putchar(buffer[p--]);
}
void dfs(int now, int father) {
	fa[now][0] = father, sum[now] = sum[father] + v[now], dep[now] = dep[father] + 1;
	for(int i = 1; i <= lg[n]; ++i) fa[now][i] = fa[fa[now][i - 1]][i - 1];
	const int LEN = g[now].size();
	for(int i = 0; i < LEN; ++i)
		if(g[now][i] != father) dfs(g[now][i], now);
}
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = lg[n]; i >= 0; --i)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void get(int x) {
	while(dep[x] > dep[LCA]) {
		qwq[++cnt] = v[x];
		x = fa[x][0];
	}
}
void teg(int x) {
	while(dep[x] > dep[LCA]) {
		qaq[++tg] = v[x];
		x = fa[x][0];
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n), read(q), read(k);
	for(int i = 1; i <= n; ++i) {
		read(v[i]);
	}
	for(int i = 2; i <= n; ++i) {
		lg[i] = lg[i >> 1] + 1;
		read(a), read(b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	while(q--) {
		read(a), read(b);
		LCA = lca(a, b);
		if(k == 1) {
			write(sum[a] + sum[b] - sum[LCA] - sum[fa[LCA][0]] + (LCA == 1 ? v[1] : 0));
			putchar('\n');
		}
		else {
			cnt = tg = 0;
			get(a);
			qwq[++cnt] = v[LCA];
			teg(b);
			for(int i = tg; i >= 1; --i) qwq[++cnt] = qaq[i];
//			for(int i = 1; i <= cnt; ++i) cerr << qwq[i] << " ";
//			cerr << endl;
			dp[1] = qwq[1];
			dp[2] = qwq[1] + qwq[2];
			dp[3] = qwq[1] + qwq[3];
			if(k == 2) {
				for(int i = 4; i <= cnt; ++i) {
					dp[i] = min(dp[i - 1], dp[i - 2]) + qwq[i];
				}
				write(dp[cnt]);
			}
			else {
				dp[4] = qwq[1] + qwq[4];
				for(int i = 5; i <= cnt; ++i) {
					dp[i] = min(dp[i - 1], min(dp[i - 2], dp[i - 3])) + qwq[i];
				}
				write(dp[cnt]);
			}
			putchar('\n');
		}
	}
	return 0;
}
