#include<bits/stdc++.h>

using namespace std;

const int N = 2500 + 5, M = 5000 + 10;

long long n, m, k;
long long v[N];
long long Head[N], End[2 * M], Nex[2 * M], tot = 0;
bool b[N], c[N];
long long ans = 0;

void Add(long long x, long long y)
{
	End[++tot] = y, Nex[tot] = Head[x], Head[x] = tot;
}

void DFS(long long x, long long y, long long z)
{
	if(z == 4)
	{
		if(c[x])
		{
			ans = max(ans, y);
		}
		return;
	}
	
	for(long long i = Head[x]; i; i = Nex[i])
	{
		if(!b[End[i]])
		{
			b[End[i]] = true;
			DFS(End[i], y + v[End[i]], z + 1);
			b[End[i]] = false;
		}
	}
}

int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	
	for(long long i = 2; i <= n; ++i)
	{
		scanf("%lld", &v[i]);
	}
	
	for(long long i = 1; i <= m; ++i)
	{
		long long x, y;
		scanf("%lld%lld", &x, &y);
		if(x == 1) c[y] = true;
		if(y == 1) c[x] = true;
		Add(x, y), Add(y, x);
	}
	
	if(k == 0)
	{
		DFS(1, 0, 0);
		printf("%lld\n", ans);
	}else{
		if(k > n)
		{
			sort(v + 2, v + n + 2);
			ans += v[n] + v[n - 1] + v[n - 2] + v[n - 3];
			printf("%lld\n", ans);
		}
	}
	
	return 0;
}
