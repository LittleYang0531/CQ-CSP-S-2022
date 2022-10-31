#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005, INF = 100000000000000001;
ll n, m, q;
ll a[N], b[N];
ll c[N][N];
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &q);
	for(ll i = 1; i <= n; i ++ )
		scanf("%lld", &a[i]);
	for(ll i = 1; i <= m; i ++ )
		scanf("%lld", &b[i]);
	for(ll i = 1; i <= n; i ++ )
		for(ll j = 1; j <= m; j ++ )
			c[i][j] = a[i] * b[j];
	while(q -- )
	{
		ll l1, l2, r1, r2;
		scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		ll ma = -INF;
		for(ll i = l1; i <= r1; i ++ )
		{
			ll mi = INF;
			for(ll j = l2; j <= r2; j ++ )
				mi = min(mi, c[i][j]);
			ma = max(ma, mi);
		}
		printf("%lld\n", ma);
	}
	return 0;
}

