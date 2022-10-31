#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3 + 5;
ll Min(ll x, ll y) { return x < y ? x : y; }
struct node {
	int l, r;
	ll mi;
} t[maxn][maxn << 2];
int n, m, q;
ll a[maxn], b[maxn], c[maxn][maxn];
void build(int line, int i, int l, int r) {
	t[line][i].l = l, t[line][i].r = r;
	if (l == r) {
		t[line][i].mi = c[line][l];
		return;
	}
	int mid = l + r >> 1;
	build(line, i << 1, l, mid);
	build(line, i << 1 | 1, mid + 1, r);
	t[line][i].mi = Min(t[line][i << 1].mi, t[line][i << 1 | 1].mi);
}
ll query(int line, int i, int l, int r) {
	if (l <= t[line][i].l && t[line][i].r <= r) 
		return t[line][i].mi;
	ll ans = 1e18;
	if (t[line][i << 1].r >= l) ans = Min(ans, query(line, i << 1, l, r));
	if (t[line][i << 1 | 1].l <= r) ans = Min(ans, query(line, i << 1 | 1, l, r));
	return ans;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout); 
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c[i][j] = a[i] * b[j];
	for (int i = 1; i <= n; i++)
		build(i, 1, 1, m);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= 2 * m; j++)
//			printf("%d %d %d %lld\n", i, t[i][j].l, t[i][j].r, t[i][j].mi);
	for (int i = 1; i <= q; i++) {
		int l1, r1, l2, r2, pos;
		ll M = -1e18;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		for (int j = l1; j <= r1; j++)
			M = max(M, query(j, 1, l2, r2));
		printf("%lld\n", M);
	}
}

