#include <cstdio>
#include <algorithm>

#define LL long long

using namespace std;

const LL N = 1e5 + 5;
const LL INF = 1e18 + 5;

LL n, m;
LL T;
LL a[N], b[N];

int main ()
{
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	
	scanf ("%lld %lld %lld", &n, &m, &T);
	for (LL i = 1; i <= n; i ++)
		scanf ("%lld", &a[i]);
	for (LL i = 1; i <= m; i ++)
		scanf ("%lld", &b[i]);
	
	while (T --)
	{
		LL l1, l2, r1, r2, ans = -INF;
		scanf ("%lld %lld %lld %lld", &l1, &r1, &l2, &r2);
		
		for (LL i = l1; i <= r1; i ++)
		{
			LL minn = INF;
			for (LL j = l2; j <= r2; j ++)
				minn = min (minn, a[i] * b[j]);
			ans = max (ans, minn);
		}
		
		printf ("%lld\n", ans);
	}
	
	return 0;
}

