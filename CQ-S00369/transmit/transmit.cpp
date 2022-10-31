#include<bits/stdc++.h>

using namespace std;

const int N = 200000 + 10;

long long n, q, k;
long long Head[N], End[N * 2], Nex[N * 2], tot = 0;
long long v[N];
long long d[N], f[N][30], g[N][30];

void Add(long long x, long long y)
{
	End[++tot] = y, Nex[tot] = Head[x], Head[x] = tot;
}

DFS(long long x, long long fa)
{
	d[x] = d[fa] + 1;
	f[x][0] = fa;
	g[x][0] = v[x] + v[fa];
	for(long long i = 1; i <= 25; ++i)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
		g[x][i] = g[x][i - 1] + g[f[x][i - 1]][i - 1] - v[f[x][i - 1]];
	}
	
	for(long long i = Head[x]; i; i = Nex[i])
	{
		if(End[i] != fa) DFS(End[i], x); 
	}
	
}

long long LCA(long long s, long long t)
{
	if(d[s] < d[t]) swap(s, t);
	
	long long ans = v[s] + v[t];  
	for(long long i = 25; i >= 0; --i)
	{
		if(d[s] >= d[t])
		{
			ans += g[s][i] - v[s];
			s = f[s][i];
		}
	}
	if(s == t) return ans;
	
	for(long long i = 25; i >= 0; --i)
	{
		if(f[s][i] != f[t][i])
		{
			ans += g[s][i] + g[t][i] - v[s] - v[t];
			s = f[s][i];
			t = f[t][i];
		}
	}
	
	ans += g[s][0] + g[t][0] - v[s] - v[t];
	return ans; 
}

int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &q, &k);
	
	for(long long i = 1; i <= n; ++i) scanf("%lld", &v[i]);
	
	for(long long i = 1; i < n; ++i)
	{
		long long x, y;
		scanf("%lld%lld", &x, &y);
		Add(x, y), Add(y, x);
	}
	
	DFS(1, 0);
	
	while(q--)
	{
		long long s, t;
		scanf("%lld%lld", &s, &t);
		printf("%lld\n", LCA(s, t));
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
