#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, q, k, ans, v[N],  ansss, ans_id[N], dp[N];
bool vis[N];
vector<long long> G[N];
void js(long long kk, long long len, long long anss, long long kong) {
	if (kk > len) {
		ansss = min(anss, ansss);
		return ;
	}
	if (anss >= ansss) return ;
	if (!kong) {
		js(kk + 1, len, anss + v[ans_id[kk]], k);
	} else {
		js(kk + 1, len, anss, kong - 1);
		js(kk + 1, len, anss + v[ans_id[kk]], k);
	}
}
void dfs(long long x, long long e, long long kk) {
	if (x == e) {
		ansss = LLONG_MAX;
		js(1, kk, 0, k);
		ans = min(ansss, ans);
		return ;
	}
	long long len = G[x].size();
	for (long long i = 0;i < len;i++) {
		if (!vis[G[x][i]]) {
			vis[G[x][i]] = 1;
			ans_id[kk] = G[x][i];
			dfs(G[x][i], e, kk + 1);
			vis[G[x][i]] = 0;
		}
	} 
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	cin >> n >> q >> k;
	for (long long i = 1;i <= n;i++) {
		scanf("%lld", &v[i]);
	}
	for (long long i = 1, x, y;i < n;i++) {
		scanf("%lld%lld", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	while(q--) {
		long long s, t;ans = LLONG_MAX;
		scanf("%lld%lld", &s, &t);
		dfs(s, t, 1);
		printf("%lld\n", ans + v[s] + v[t]);
	}
	return 0;
}
