#include <bits/stdc++.h>
using namespace std;
int a[200006], fa[200006], dep[200006];
vector <int> e[200006];
int find(int x)
{
	while (x != fa[x]) x = fa[x];
	return x;
}
void dfs(int x, int f)
{
	dep[x] = dep[f] + 1;
	for (int i = 0; i < e[x].size(); i++)
		if (e[x][i] != f)
			dfs(e[x][i], x);
}
int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int n, q, k;
	scanf("%d%d%d", &n, &q, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), fa[i] = i;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
		fa[v] = u;
	}
	dfs(find(1), 0);
	while (q--)
	{
		int x, y;
		long long ans = 0;
		scanf("%d%d", &x, &y);
		if (dep[x] < dep[y]) swap(x, y);
		while (dep[x] != dep[y])
			ans += a[x], x = fa[x];
		while (x != y)
		{
			ans += a[x], x = fa[x];
			ans += a[y], y = fa[y];
		}
		ans += a[x];
		printf("%lld\n", ans);
	}
	return 0;
}
