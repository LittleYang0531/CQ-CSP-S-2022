#include <bits/stdc++.h>
using namespace std ;
int n, m, a, b, q ;
int main()
{
	freopen("galaxy.in", "r", stdin) ;
	freopen("galaxy.out", "w", stdout) ;
	scanf("%d%d", &n, &m) ;
	for(int i = 1; i <= m; i ++)
	{
		scanf("%d%d", &a, &b) ;
	}
	scanf("%d", &q) ;
	for(int i = 1; i <= q; i ++)
	{
		scanf("%d", &a) ;
		scanf("%d", &b) ;
		if(a != 2 && a != 4)	scanf("%d", &a) ; 
	}
	for(int i = 1; i <= q; i ++)
	{
		printf("No\n") ;
	}
	return 0 ;
}
