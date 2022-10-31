#include <iostream>
typedef long long ll;
#define ls (u << 1)
#define rs (u << 1 | 1)
const ll N = 1e5;
const ll INF = 1e18;
ll n, m, q;
struct Tree
{
	ll a[N + 5];
	ll min[4 * N + 5][2], max[4 * N + 5][2];
	void push_up(ll u)
	{
		min[u][0] = std :: min(min[ls][0], min[rs][0]);
		min[u][1] = std :: min(min[ls][1], min[rs][1]);
		max[u][0] = std :: max(max[ls][0], max[rs][0]);
		max[u][1] = std :: max(max[ls][1], max[rs][1]);
	}
	void build(ll u, ll l, ll r)
	{
		if (l == r)
		{
			min[u][0] = min[u][1] = INF;
			max[u][0] = max[u][1] = -INF;
			if (a[l] >= 0) min[u][0] = max[u][0] = a[l];
			if (a[l] <= 0) min[u][1] = max[u][1] = a[l];
			return ;
		}
		ll mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		push_up(u);
	}
	ll query_min(ll u, ll l, ll r, ll L, ll R, ll opt)
	{
		if (L <= l && r <= R) return min[u][opt];
		ll res = INF;
		ll mid = l + r >> 1;
		if (L <= mid) res = std :: min(res, query_min(ls, l, mid, L, R, opt));
		if (mid < R) res = std :: min(res, query_min(rs, mid + 1, r, L, R, opt));
		return res;
	}
	ll query_max(ll u, ll l, ll r, ll L, ll R, ll opt)
	{
		if (L <= l && r <= R) return max[u][opt];
		ll res = -INF;
		ll mid = l + r >> 1;
		if (L <= mid) res = std :: max(res, query_max(ls, l, mid, L, R, opt));
		if (mid < R) res = std :: max(res, query_max(rs, mid + 1, r, L, R, opt));
		return res;
	}
} tr[2];
ll ans[N + 5];
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &q);
	for (ll i = 1; i <= n; i ++ ) scanf("%lld", &tr[0].a[i]);
	for (ll i = 1; i <= m; i ++ ) scanf("%lld", &tr[1].a[i]);
	tr[0].build(1, 1, n);
	tr[1].build(1, 1, m);
	for (ll i = 1; i <= q; i ++ )
	{
		ll res = -INF;
		ll l1, r1, l2, r2;
		scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		ll p, q;
		p = std :: min(tr[1].query_min(1, 1, m, l2, r2, 0), tr[1].query_min(1, 1, m, l2, r2, 1));
		if (p < 0) q = tr[0].query_min(1, 1, n, l1, r1, 0);
		else q = tr[0].query_max(1, 1, n, l1, r1, 0);
		if (q != INF && q != -INF) res = std :: max(res, p * q);
		p = std :: max(tr[1].query_max(1, 1, m, l2, r2, 0), tr[1].query_max(1, 1, m, l2, r2, 1));
		if (p < 0) q = tr[0].query_min(1, 1, n, l1, r1, 1);
		else q = tr[0].query_max(1, 1, n, l1, r1, 1);
		if (q != INF && q != -INF) res = std :: max(res, p * q);
		printf("%lld\n", res);
	}
	return 0;
}
