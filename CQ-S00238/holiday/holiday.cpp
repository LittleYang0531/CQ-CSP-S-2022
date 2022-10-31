#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mp[310][310], a[310], ans = -0x3f3f3f3f;
long long read()
{
	long long ans = 0, bj = 1;
	char c = getchar();
	if(c == '-') bj = -1;
	while(c < '0' || c > '9')
	{
		c = getchar();
		if(c == '-') bj = -1;
	}
	while('0' <= c && c <= '9')
		ans = (ans << 1) + (ans << 3) + c - '0', c = getchar();
	return ans * bj;
}
int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 2; i <= n; ++i) a[i] = read();
	if(n <= 300)
	{
		memset(mp, 0x3f, sizeof(mp));
		for(int i = 1, x, y; i <= m; ++i)
		{
			x = read(); y = read();
			mp[x][y] = mp[y][x] = 1;
		}
		for(int l = 1; l <= n; ++l)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					if(i != j && j != l && i != l)
						if(mp[i][l] + mp[l][j] < mp[i][j])
							mp[i][j] = mp[j][i] = mp[i][l] + mp[l][j];
	}
	if(n <= 20)
	{
		for(int w = 2; w <= n; ++w)
		{
			if(mp[1][w] > k + 1) continue;
			for(int x = 2; x <= n; ++x)
			{
				if(mp[w][x] > k + 1) continue;
				if(x == w) continue;
				for(int y = 2; y <= n; ++y)
				{
					if(mp[x][y] > k + 1) continue;
					if(y == x) continue;
					if(y == w) continue;
					for(int z = 2; z <= n; ++z)
					{
						if(z == w) continue;
						if(z == x) continue;
						if(z == y) continue;
						if(mp[y][z] > k + 1) continue;
						if(mp[z][1] > k + 1) continue;
						ans = max(ans, a[w] + a[x] + a[y] + a[z]);
					}
				}
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	return 0;
}
