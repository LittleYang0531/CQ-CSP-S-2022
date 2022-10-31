#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <bitset>
using namespace std;
inline int read()
{
	int ans = 0;
	char i;
	while (i=getchar(), i>'9'||i<'0')
	{
		
	}
	ans = i-'0';
	while (i=getchar(), i>='0'&&i<='9')
	{
		ans*=10;
		ans+=i-'0';
	}
	return ans;
}
int n, m, q, size[500005], sum;
vector<int> v[500005], u[500005];
bitset<500005> temp;
int main()
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	n = read(), m = read();
	for (int p=1;p<=m;p++)
	{
		int x, y;
		x = read(), y = read();
		size[x]++;
		v[y].push_back(x);
		u[y].push_back(1);
		sum++;
	}
	for (int p=1;p<=n;p++)
	{
		if (size[p]!=1)
		{
			temp[p] = 1;
		}
		stable_sort(v[p].begin(), v[p].end());
	}
	q = read();
	for (int zqw=1;zqw<=q;zqw++)
	{
		int t;
		t = read();
		if (t==1)
		{
			int x, y;
			x = read(), y = read();
			int place = lower_bound(v[y].begin(), v[y].end(), x)-v[y].begin();
			sum--;
			u[y][place] = 0;
			size[x]--;
			if (size[x]==1)
			{
				temp[x] = 0;
			}
			else
			{
				temp[x] = 1;
			}
		}
		if (t==2)
		{
			int x;
			x = read();
			for (int p=0;p<u[x].size();p++)
			{
				if (u[x][p])
				{
					u[x][p] = 0;
					sum--;
					size[v[x][p]]--;
					if (size[v[x][p]]==1)
					{
						temp[v[x][p]] = 0;
					}
					else
					{
						temp[v[x][p]] = 1;
					}
				}
			}
		}
		if (t==3)
		{
			int x, y;
			x = read(), y = read();
			int place = lower_bound(v[y].begin(), v[y].end(), x)-v[y].begin();
			sum++;
			u[y][place] = 1;
			size[x]++;
			if (size[x]==1)
			{
				temp[x] = 0;
			}
			else
			{
				temp[x] = 1;
			}
		}
		if (t==4)
		{
			int x;
			x = read();
			for (int p=0;p<u[x].size();p++)
			{
				if (!u[x][p])
				{
					u[x][p] = 1;
					sum++;
					size[v[x][p]]++;
					if (size[v[x][p]]==1)
					{
						temp[v[x][p]] = 0;
					}
					else
					{
						temp[v[x][p]] = 1;
					}
				}
			}
		}
		if (sum!=n)
		{
			puts("NO");
		}
		else
		{
			if (temp==0)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
	}
	return 0;
}
