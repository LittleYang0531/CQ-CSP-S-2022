#include<stdio.h>
#include<memory.h>
int n, m, k, cnt[2505], va[2505], dis[2505][2505];
bool vis[2505];
long long ans;
template<typename t>
t max(t a, t b) {return a < b? b: a;}
template<typename t>
t min(t a, t b) {return a > b? b: a;}
void dfs(int pos, int id, long long sum)
{
	if(id == 4)
	{
		if(dis[pos][1] - 1 <= k) ans = max(ans, sum);
		return;
	}
	if(cnt[pos] == 0) return;
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i] && dis[pos][i] - 1 <= k)
		{
			vis[i] = true;
			dfs(i, id + 1, sum + va[i]);
			vis[i] = false;
		}
	}
}
int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	memset(dis, 0x3f, sizeof dis);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 2; i <= n; i++) scanf("%d", &va[i]);
	for(int i = 1, u, v; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		dis[u][v] = dis[v][u] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int s = 1; s <= n; s++)
			{
				dis[j][s] = min(dis[j][s], dis[j][i] + dis[i][s]);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if(dis[i][j] - 1 <= k) cnt[i]++;
		}
	}
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
