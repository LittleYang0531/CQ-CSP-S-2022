#include <bits/stdc++.h>
using namespace std;
const int maxn = 2506;
int n, cnt, a[maxn], b[maxn][maxn];
long long ans;
void dfs(int now, int dep, long long sum)
{
	if (dep == 6)
	{
		if (now == 1) ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++)
		if (b[now][i])
			dfs(i, dep + 1, sum + a[i]);
}
int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	int m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 2; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		b[u][v] = b[v][u] = 1;
	}
	dfs(1, 1, 0);
	printf("%lld\n", ans);
	return 0;
}
