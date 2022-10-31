#include <bits/stdc++.h>
typedef long long LL;

using namespace std;

const int N=100008;
int n, m, q, a[N], b[N], l1, r1, l2, r2;

LL c(int xx, int yy)
{
	LL cc=a[xx] * b[yy];
	return cc;
}

struct tool
{
	LL value;
	int number;
};

LL comp(tool xx, tool yy)
{
	return xx.value > yy.value;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &q);
	for(int i=1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i=1; i <= m; i++)
		scanf("%d", &b[i]);
		
	for(int click=1; click <= q; click++)
	{
		tool mi[N];
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		int flag1, flag2;
		
		for(int x=l1; x <= r1; x++)
		{
			LL minn=LONG_LONG_MAX;
			for(int y=l2; y <= r2; y++)
			{
				if(c(x, y) < minn)
				{
					minn=c(x, y);
				}
			}
			mi[x].value = minn;
			mi[x].number = x;
		}
		
		sort(mi+l1, mi+r1+1, comp);
		flag1=mi[l1].number;
		
		LL minn=LONG_LONG_MAX;
		for(int y=l2; y <= r2; y++)
		{
			if(c(flag1, y) < minn)
			{
				minn=c(flag1, y);
				flag2=y;
			}
		}
		
		printf("%lld\n", c(flag1, flag2));
	}
	return 0;
}
