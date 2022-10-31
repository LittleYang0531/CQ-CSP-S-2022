#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[2010][2010];
int n,m,k,l,r,l1,r1;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld\n",&a[i]);
	}
	for(int i = 1;i <= m;i++)
	{
		scanf("%lld\n",&b[i]);		
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			c[i][j] = a[i] * b[j];		
		}
	}
	for(int i = 1;i <= k;i++)
	{
		scanf("%d%d%d%d",&l,&r,&l1,&r1);
		long long rb = 92233720368547758,sum = -92233720368547758;
		for(int i = l;i <= r;i++)
		{
			rb = l1;
			for(int j = l1;j <= r1;j++)
			{
				if(c[i][j] < c[i][rb])
					rb = j;		
			}
			sum = max(sum,c[i][rb]);
		}
		printf("%lld\n",sum);		
	}
	return 0;
}
/*
	3 2 2
	0 1 -2
	-3 4
	1 3 1 2
	2 3 2 2
*/

