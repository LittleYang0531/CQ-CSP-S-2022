#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n, m, zqw;
bool book[305][305];
long long a[305], u1[305][305], temp[305][305][305], ans;
vector<int> v[305];
struct e
{
	int i, u;
}t1, t2;
void bfs(int s)
{
	queue<e> q;
	q.push({s, 0});
	book[s][s] = 1;
	while (!q.empty())
	{
		t1 = q.front();
		q.pop();
		if (t1.u==zqw+1)
		{
			continue;
		}
		for (int p=0;p<v[t1.i].size();p++)
		{
			if (!book[s][v[t1.i][p]])
			{
				book[s][v[t1.i][p]] = 1;
				q.push({v[t1.i][p], t1.u+1});
			}
		}
	}
	return ;
}
int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &zqw);
	for (int p=2;p<=n;p++)
	{
		scanf("%lld", &a[p]);
	}
	for (int p=1;p<=m;p++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int p=1;p<=n;p++)
	{
		bfs(p);
	}
	for (int p=2;p<=n;p++)
	{
		if (book[1][p])
		{
			for (int k=2;k<=n;k++)
			{
				if (k!=p&&book[p][k])
				{
					u1[p][k] = a[p]+a[k];
				}
			}
		}
	}
	for (int p=2;p<=n;p++)
	{
		for (int l=2;l<=n;l++)
		{
			for (int r=l;r<=n;r++)
			{
				temp[p][l][r] = max(temp[p][l][r-1], u1[r][p]);
			}
		}
	}
	for (int p=2;p<=n;p++)
	{
		for (int k=2;k<=n;k++)
		{
			if (p!=k)
			{
				for (int i=2;i<=n;i++)
				{
					if (p!=i&&k!=i&&book[k][i])
					{
						if (p>k)
						{
							ans = max(ans, u1[p][k]+max(temp[i][2][k-1], max(temp[i][k+1][p-1], temp[i][p+1][n])));
						}
						else
						{
							ans = max(ans, u1[p][k]+max(temp[i][2][p-1], max(temp[i][p+1][k-1], temp[i][k+1][n])));
						}
					}
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
