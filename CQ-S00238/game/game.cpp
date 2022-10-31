#include <bits/stdc++.h>
using namespace std;
long long n, m, q, pfpd = 0x3f3f3f3f;
long long a[100010], b[100010], l1, r1, l2, r2;
long long maxf[2][100010][32], minf[2][100010][32];
long long read()
{
	long long ans = 0, bj = 1;
	char c = getchar();
	if(c == '-') bj = -1;
	while(c < '0' || c > '9')
	{
		c = getchar();
		if(c == '-') bj = -1;
	}
	while('0' <= c && c <= '9')
		ans = (ans << 1) + (ans << 3) + c - '0', c = getchar();
	return ans * bj;
}
inline long long RMQ(long long id, long long l, long long r, bool ismx)
{
	if(l > r) swap(l, r);
	long long k = log2(r - l + 1);
	if(ismx == false) return min(minf[id][l][k], minf[id][r - (1 << k) + 1][k]);
	if(ismx == true) return max(maxf[id][l][k], maxf[id][r - (1 << k) + 1][k]);
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(); m = read(); q = read();
	for(int i = 1; i <= n; ++i) a[i] = read(), pfpd = min(pfpd, a[i]);
	for(int i = 1; i <= m; ++i) b[i] = read(), pfpd = min(pfpd, b[i]);
	for(int i = 1; i <= n; ++i)
		minf[0][i][0] = maxf[0][i][0] = a[i];
	for(int i = 1; i <= m; ++i)
		minf[1][i][0] = maxf[1][i][0] = b[i];
	for(int i = 1; (1 << i) <= n; ++i)
	{
		for(int j = 1; j + (1 << i) - 1 <= n; ++j)
		{
			maxf[0][j][i] = max(maxf[0][j][i - 1], maxf[0][j + (1 << (i - 1))][i - 1]);
			minf[0][j][i] = min(minf[0][j][i - 1], minf[0][j + (1 << (i - 1))][i - 1]);
		}
	}
	for(int i = 1; (1 << i) <= m; ++i)
	{
		for(int j = 1; j + (1 << i) - 1 <= n; ++j)
		{
			maxf[1][j][i] = max(maxf[1][j][i - 1], maxf[1][j + (1 << (i - 1))][i - 1]);
			minf[1][j][i] = min(minf[1][j][i - 1], minf[1][j + (1 << (i - 1))][i - 1]);
		}
	}
	for(int js = 1; js <= q; ++js)
	{
		l1 = read(); r1 = read();
		l2 = read(); r2 = read();
		if(pfpd > 0)
		{
			long long ans1, ans2;
			ans1 = RMQ(0, l1, r1, true);
			ans2 = RMQ(1, l2, r2, false);
			printf("%lld\n", ans1 * ans2);
			continue;
		}
		if(n <= 1000 && m <= 1000 && q <= 1000)
		{
			long long bx, bi, wst = -0x3f3f3f3f3f3f3f3f, id;
			bx = RMQ(1, l2, r2, true);
			bi = RMQ(1, l2, r2, false);
			for(int i = l1; i <= r1; ++i)
			{
				long long base = a[i], res;
				res = min(a[i] * bx, a[i] * bi);
				if(res > wst) wst = res, id = i;
			}
			printf("%lld\n", wst);
			continue;
		}
		if(l1 == r1)
		{
			long long bx, bi;
			bx = RMQ(1, l2, r2, true);
			bi = RMQ(1, l2, r2, false);
			printf("%lld\n", min(bx * a[l1], bi * a[l1]));
			continue;
		}
		if(l2 == r2)
		{
			long long ax, ai;
			ax = RMQ(0, l1, r1, true);
			ai = RMQ(0, l1, r1, false);
			printf("%lld\n", max(ax * b[l2], ai * b[l2]));
			continue;
		}
	}
	return 0;
}
