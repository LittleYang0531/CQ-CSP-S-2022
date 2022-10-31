#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
ll read() {
	ll p = 0, flg = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') flg = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p = p * 10 + c - '0';
		c = getchar();
	}
	return p * flg;
}
void write(ll x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 1005;
ll s[N], h[N], mp[N * N], dp[N];
struct Node {
	ll sum;
} edge[N * N * 4];
ll tag[N * N * 4];
void build(ll x, ll l, ll r) {
	//cout << x << endl;
	if (l == r) {
		edge[x].sum = mp[l];
		//if (x == 5) cout << mp[l] << " " << r << endl;
		return;
	}
	ll mid = (l + r) >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	edge[x].sum = min(edge[x * 2].sum, edge[x * 2 + 1].sum);
}

ll query(ll x, ll l, ll r, ll L, ll R) {
	if (L > r || R < l) return 0x7f7f7f7f7f7f7f7f;
	if (L <= l && R >= r) {
		//cout << x << " " << l << " " << r << " " << L << " " << R << " " << edge[x].sum << endl;
		return edge[x].sum;
	}
	ll mid = (l + r) >> 1, ans = 0x7f7f7f7f7f7f7f7f;
	if (L <= mid) ans = min(ans, query(x * 2, l, mid, L, R));
	if (R > mid) ans = min(ans, query(x * 2 + 1, mid + 1, r, L, R));
	//cout << x << " " << l << " " << r << " " << L << " " << R << " " << ans << endl;
	return ans;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ll n = read(), m = read(), q = read();
	for (ll i = 1; i <= n; i++) {
		s[i] = read();
	}
	for (ll i = 1; i <= m; i++) {
		h[i] = read();
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			mp[(i - 1) * m + j] = s[i] * h[j];
		}
	}
	build(1, 1, n * m);
//	for (int i = 1; i <= n * m; i++) {
//		cout << mp[i] << " ";
//	}
//	puts("");
	while (q--) {
		memset(dp, -0x7f, sizeof(dp));
		ll l1 = read(), r1 = read(), l2 = read(), r2 = read();
		ll ans = 0;
		for (ll i = l1; i <= r1; i++) {
			ll sum = 0x7f7f7f7f7f7f7f7f;
			//cout << (i - 1) * m + 1 << " " << (i - 1) * m + m << endl;
			dp[i] = query(1, 1, n * m, (i - 1) * m + l2, (i - 1) * m + r2);
			//cout << dp[i] << " ";
			if (dp[i] > dp[ans]) ans = i;
		}
		//cout << endl;
		write(dp[ans]), puts("");
	}
	return 0;
}
