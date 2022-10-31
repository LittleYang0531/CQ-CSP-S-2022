#include<stdio.h>
int n, m, q, a[100005], b[100005];
int max(int a, int b) {return a < b? b: a;}
int min(int a, int b) {return a > b? b: a;}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= q; i++)
	{
		int l1, l2, r1, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int z1 = 0, f1 = 0, z2 = 0, f2 = 0;
		bool ze1 = false, ze2 = false;
		for(int j = l2; j <= r2; j++)
		{
			if(b[j] == 0) ze2 = true;
			z2 = max(z2, b[j]);
			f2 = min(f2, b[j]);
		}
		for(int j = l1; j <= r1; j++)
		{
			if(a[j] == 0) ze1 = true;
			z1 = max(z1, a[j]);
			f1 = min(f1, a[j]);
		}
		if(z2 != 0 && f2 != 0)
		{
			if(ze1) printf("0\n");
			else printf("%d\n", max(z1 * f2, z2 * f1));
			continue;
		}
		if(ze2)
		{
			printf("0\n");
			continue;
		}
		if(z2 != 0)
		{
			printf("%d\n", z2 * max(z1, f1));
			continue;
		}
		if(f2 != 0)
		{
			printf("%d\n", f2 * min(z1, f1));
			continue;
		}
	}
	return 0;
}
