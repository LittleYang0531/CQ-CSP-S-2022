#include<stdio.h>
#include<memory.h>
int n, m, q, degree[500005], f[500005], last[500005];
struct e
{
	int to, next;
	bool zt/*ÊÇ·ñÍêºÃ*/;
};
e edge[500005];
bool vis[500005];
int line(int u, int v, bool flag)
{
	int cnt = 0;
	for(int id = last[u]; id != -1; id = edge[id].next)
	{
		if(edge[id].to == v)
		{
			if(edge[id].zt != flag) cnt++;
			edge[id].zt = flag;
			break;
		}
	}
	return cnt;
}
void point(int u, bool flag)
{
	int cnt;
	for(int i = 1; i <= n; i++)
	{
		cnt = line(i, u, flag);
		if(flag) degree[i] += cnt;
		else degree[i] -= cnt;
	}
}
bool dfs(int pos)
{
	if(f[pos] != -1) return f[pos];
	for(int id = last[pos]; id != -1; id = edge[id].next)
	{
		if(!edge[id].zt) continue;
		if(vis[edge[id].to])
		{
			f[pos] = 1;
			return true;
		}
		vis[edge[id].to] = true;
		if(dfs(edge[id].to))
		{
			f[pos] = 1;
			return true;
		}
	}
	f[pos] = 0;
	return false;
}
bool check()
{
	for(int i = 1; i <= n; i++)
	{
		if(degree[i] != 1) return false;
	}
	for(int i = 1; i <= n; i++) f[i] = -1;
	for(int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof vis);
		vis[i] = true;
		if(!dfs(i)) return false;
	}
	return true;
}
int main()
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) last[i] = -1;
	for(int i = 1, u, v; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		edge[i] = {v, last[u], true};
		last[u] = i;
		degree[u]++;
	}
	scanf("%d", &q);
	while(q--)
	{
		int t, u, v;
		scanf("%d%d", &t, &u);
		if(t == 1)
		{
			scanf("%d", &v);
			int r = line(u, v, false);
			degree[u] -= r;
		}
		else if(t == 2) point(u, false);
		else if(t == 3)
		{
			scanf("%d", &v);
			int r = line(u, v, true);
			degree[u] += r;
		}
		else point(u, true);
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
