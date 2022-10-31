#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int n, m, k;
long long w[N];
int ma[N][N];
void floyd()
{
	for(int k = 1; k <= n; k ++ )
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= n; j ++ )
				ma[i][j] = min(ma[i][k] + ma[k][j] + 1, ma[i][j]); 
}
bool st[N];
long long ans = 0;
void dfs(int t, int last, long long sum)
{
	if(t == 4)
	{
		if(ma[1][last] <= k)
			ans = max(ans, sum);
	}
	else for(int i = 2; i <= n; i ++ )
		if(!st[i] && ma[i][last] <= k)
		{
			st[i] = 1;
			dfs(t + 1, i, sum + w[i]);
			st[i] = 0;
		}
}
int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 2; i <= n; i ++ )
		scanf("%lld", &w[i]);
	memset(ma, 0x3f, sizeof ma);
	for(int i = 1; i <= m; i ++ )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ma[x][y] = ma[y][x] = 0;
	}
	floyd();
	st[1] = 1;
	dfs(0, 1, 0);
	printf("%lld", ans);	
	return 0;
}
