#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 100005 ;
int n, m, q, l1, r1, l2, r2 ;
long long a[MAXN], b[MAXN], INF = 0x7f7f7f7f7f7f7f ;
long long Ans = -INF, Sum = INF ;
long long read()
{
	long long x = 0, f = 1 ;
	char c = getchar() ;
	while(c < '0' || c > '9')
	{
		if(c == '-')	f = -1 ;
		c = getchar() ;
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0' ;
		c = getchar() ;
	}
	return x * f ;
}
int main()
{
	freopen("game.in", "r", stdin) ;
	freopen("game.out", "w", stdout) ;
	n = (int)read(), m = (int)read(), q = (int)read() ;
	for(int i = 1; i <= n; i ++)	a[i] = read() ;
	for(int i = 1; i <= m; i ++)	b[i] = read() ;
	for(int i = 1; i <= q; i ++)
	{
		l1 = read(), r1 = read(), l2 = read(), r2 = read() ;
		Ans = -INF ;
		for(int l = l1; l <= r1; l ++)
		{
			Sum = INF ;
			for(int r = l2; r <= r2; r ++)
			{
				Sum = min(Sum, a[l] * b[r]) ;
			}
			Ans = max(Ans, Sum) ;
		}
		printf("%lld\n", Ans) ;
	}
	return 0 ;
}
