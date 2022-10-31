#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<typename T> void chkmn(T &a, const T &b)
{
	(a > b) && (a = b);
}
template<typename T> void chkmx(T &a, const T &b)
{
	(a < b) && (a = b);
}
const LL INF = 1e15;
const int N = 2e5 + 5;
const int F = 31;
int n, Q, k, w[N];
int idx, h[N], e[2 * N], ne[2 * N];
int fath[N][F], depth[N];
LL presum[N];
int g[N], gcnt, _g[N], _gcnt;
LL f[N][2];

void add(int a, int b)
{
	idx++;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
}
void dfs(int u, int fa)
{
	fath[u][0] = fa;
	presum[u] += w[u];
	depth[u] = depth[fa] + 1;
	for(int i = 1; i < F; ++i)
		fath[u][i] = fath[fath[u][i - 1]][i - 1];
	for(int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if(v == fa)
			continue;
		presum[v] = presum[u];
		dfs(v, u);
	}
}
int LCA(int x, int y)
{
	if(depth[x] < depth[y])
		swap(x, y);
	for(int i = F - 1; i >= 0; --i)
		if(depth[fath[x][i]] >= depth[y])
			x = fath[x][i];
	if(x == y) return x;
	for(int i = F - 1; i >= 0; --i)
		if(fath[x][i] ^ fath[y][i])
			x = fath[x][i], y = fath[y][i];
	return fath[x][0];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d", &n, &Q, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for(int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		add(a, b);
		add(b, a);
	}
//	puts("KSHMR");
	dfs(1, 0);
//	puts("AVICII");
	if(k == 1) // Ê÷ÉÏÇ°×ººÍ 
	{
		while(Q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			int lca = LCA(x, y);
			printf("%lld\n", presum[x] + presum[y] - presum[lca] - presum[fath[lca][0]]);
		}
		return 0;
	}
	if(k == 2)
	{
		while(Q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			int lca = LCA(x, y);
			gcnt = _gcnt = 0;
			while(x != lca)
			{
				g[++gcnt] = x;
				x = fath[x][0];
			}
			_g[++_gcnt] = y;
			while(y != lca)
			{
				y = fath[y][0];
				_g[++_gcnt] = y;
			}
			for(int i = _gcnt; i >= 1; --i)
				g[++gcnt] = _g[i];
			for(int i = 0; i <= gcnt; ++i)
				f[i][0] = f[i][1] = INF;
			f[1][1] = w[g[1]];
			for(int i = 2; i <= gcnt; ++i)
			{
				f[i][0] = f[i - 1][1];
				f[i][1] = min(f[i - 1][0], f[i - 1][1]) + w[g[i]];
			}
			printf("%lld\n", f[gcnt][1]);
		}
		return 0;
	}
	return 0;
}
