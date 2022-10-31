#include<bits/stdc++.h>
using namespace std;
int n, m, q;
int main()
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++ )
	{
		int x, y;
		scanf("%d%d", &x, &y);
	}
	scanf("%d", &q);
	while(q -- )
	{
		int x, u, v;
		scanf("%d%d", &x, &u);
		if(x == 1 | x == 3)
		{
			scanf("%d", &v);
			if((u + v) & 1)puts("NO");
			else puts("YES");
		}
		else
		{
			if(u & 1)puts("NO");
			else puts("YES");
		}
	}
	return 0;
}

