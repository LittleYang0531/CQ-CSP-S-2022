#include <bits/stdc++.h>
using namespace std;
long long n, q, k, v[200010], h[200010], cnt, pr[200010];
struct edge {long long to, next;} e[400010];
inline void add(long long x, long long y)
{e[++cnt].to = y, e[cnt].next = h[x], h[x] = cnt;}
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
long long a[400010], dep[400010], sign, l[200010];
long long minf[400010][32], minid[400010][32];
void predfs(long long now, long long prt, long long depth)
{
	pr[now] = prt;
	dep[now] = depth;
	a[++sign] = now;
	for(int i = h[now]; i; i = e[i].next)
	{
		long long to = e[i].to;
		if(to == prt) continue;
		predfs(to, now, depth + 1);
		a[++sign] = now;
	}
}
inline void makeLCA()
{
	for(int i = 1; i <= sign; ++i)
		if(l[a[i]] == 0)
			l[a[i]] = i;
	for(int i = 1; i <= sign; ++i)
		minf[i][0] = dep[a[i]], minid[i][0] = a[i];
	for(int i = 1; (1 << i) <= sign; ++i)
	{
		for(int j = 1; j + (1 << i) - 1 <= sign; ++j)
		{
			if(minf[j][i - 1] <= minf[j + (1 << (i - 1))][i - 1])
				minf[j][i] = minf[j][i - 1], minid[j][i] = minid[j][i - 1];
			else
			{
				minf[j][i] = minf[j + (1 << (i - 1))][i - 1];
				minid[j][i] = minid[j + (1 << (i - 1))][i - 1];
			}
		}
	}
}
inline long long LCA(long long x, long long y)
{
	if(l[x] > l[y]) swap(x, y);
	long long k = log2(l[y] - l[x] + 1);
	if(minf[l[x]][k] < minf[l[y] - (1 << k) + 1][k])
		return minid[l[x]][k];
	else return minid[l[y] - (1 << k) + 1][k];
}
long long hav[200010], bj = 0, bfbj;
long long dp[200010];
int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	n = read(); q = read(); k = read();
	for(int i = 1; i <= n; ++i) v[i] = read();
	for(int i = 1, x, y; i < n; ++i)
	{
		x = read(); y = read();
		add(x, y); add(y, x);
	}
	predfs(1, -1, 1);
	makeLCA();
	for(int js = 1; js <= q; ++js)
	{
		bj = 0;
		long long s = read(), t = read();
		long long p = LCA(s, t);
		while(s != p)
		{
			hav[++bj] = s;
			s = pr[s];
		}
		hav[++bj] = p;
		bfbj = bj + dep[t] - dep[p];
		while(t != p)
		{
			hav[bj + dep[t] - dep[p]] = t;
			t = pr[t];
		}
		bj = bfbj;
		for(int i = 1; i <= bj; ++i) dp[i] = 0x3f3f3f3f3f3f3f3f;
		dp[1] = v[hav[1]];
		for(int i = 2; i <= bj; ++i)
			for(int j = 1; j <= k; ++j)
				if(i - j >= 1)
					dp[i] = min(dp[i], dp[i - j] + v[hav[i]]);
		printf("%lld\n", dp[bj]);
	}
	return 0;
}
