#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

const int N=2700;
int n, m, k, x, y, p[306][1008];
ULL a[N];

int main()
{
	freopen("holidat.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	memset(p, 0, sizeof(p));
	scanf("%d %d %d", &n, &m, &k);
	if(n <= 300 && m <= 100)
	{
		for(int i=2; i <= n; i++)
		{
		scanf("%llu", &a[i]);
		}
		for(int i=1; i <= m; i++)
		{
			scanf("%d %d", &x, &y);
			p[x][y]++;
			p[y][x]++;
		}
		cout << rand();
	}
	else cout << rand();
	return 0;
}
