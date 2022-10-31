#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n, q, tl, now, w[2005], fa[2005], dep[2005], dfn[2005], st[2005], en[2005], tot;
long long dp[2005][2005];
vector<int> v[2005];
void d(int i)
{
	dfn[++tot] = i;
	st[i] = tot;
	for (int p=0;p<v[i].size();p++)
	{
		if (v[i][p]!=fa[i])
		{
			fa[v[i][p]] = i;
			dep[v[i][p]] = dep[i]+1;
			d(v[i][p]);
		}
	}
	en[i] = tot;
	return ;
}
long long dfs(int i, int j)
{
	if (dep[i]>dep[j])
	{
		swap(i, j);
	}
	if (dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if (i==j)
	{
		return dp[i][j]=-w[i];
	}
	long long ans = 1e18;
	if (tl>=1&&dep[j]>=1)
	{
		ans = min(ans, dfs(i, fa[j])+w[fa[j]]);
	}
	if (tl>=2)
	{
		int temp = fa[fa[j]];
		if (dep[j]>=2)
		{
			ans = min(ans, dfs(i, temp)+w[temp]);
		}
		if (dep[j]>=1)
		{
			temp = fa[j];
			if (st[i]>=st[temp]&&st[i]<=en[temp])
			{
				for (int p=0;p<v[temp].size();p++)
				{
					if (v[temp][p]!=fa[temp]&&st[i]>=st[v[temp][p]]&&st[i]<=en[v[temp][p]])
					{
						ans = min(ans, dfs(i, v[temp][p])+w[v[temp][p]]);
					}
				}
			}
		}
	}
	if (tl>=3)
	{
		int temp = fa[fa[fa[j]]];
		if (dep[j]>=3)
		{
			ans = min(ans, dfs(i, temp)+w[temp]);
		}
		if (dep[j]>=2)
		{
			temp = fa[fa[j]];
			for (int p=0;p<v[temp].size();p++)
			{
				ans = min(ans, dfs(i, v[temp][p])+w[v[temp][p]]);
			}
		}
		if (dep[j]>=1)
		{
			temp = fa[j];
			for (int p=0;p<v[temp].size();p++)
			{
				if (v[temp][p]!=fa[temp]&&st[i]>=st[v[temp][p]]&&st[i]<=en[v[temp][p]])
				{
					int g = v[temp][p];
					for (int k=0;k<v[g].size();k++)
					{
						if (v[g][k]!=fa[g]&&st[i]>=st[v[g][k]]&&st[i]<=en[v[g][k]])
						{
							ans = min(ans, dfs(i, v[g][k])+w[v[g][k]]);
						}
					}
				} 
			}
		}
	}
	return dp[i][j]=ans;
}
int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &q, &tl);
	for (int p=1;p<=n;p++)
	{
		scanf("%d", &w[p]);
	}
	for (int p=1;p<n;p++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d(1);
	for (int zqw=1;zqw<=q;zqw++)
	{
		int s, t;
		scanf("%d %d", &s, &t);
		printf("%lld\n", dfs(s, t)+w[s]+w[t]);
	}
	return 0;
}
