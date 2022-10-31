#include<bits/stdc++.h>
using namespace std;
const long long  maxn = 4e3 + 5;
long long n,m,q;
long long a[maxn],b[maxn],c[maxn][maxn],g[maxn];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for(int i = 1; i <= m; i++) scanf("%lld",&b[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			c[i][j] = a[i] * b[j];
		}
	}
	while(q--)
	{
		long long  l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&l2,&r1,&r2);
		if(l1 == l2 && r1 == r2) cout << c[l1][r1] << endl;
		else if(r1 == r2)
		{
			long long  maxx = -1e9 - 1,t = 0;
			for(int i = l1; i <= l2; i++)
			{
				if(c[i][r1] > maxx) maxx = c[i][r1],t = i;
			}
			cout << c[t][r1] << endl;
		}
		else if(l1 == l2)
		{
			long long  minn = 1e9 + 1,t = 0;
			for(int j = r1; j <= r2 ; j++)
			{
				if(c[l1][j] < minn) minn = c[l1][j],t = j;
			}
			cout << c[l1][t] << endl;
		}
		else
		{
			for(int i = l1; i <= l2; i++)
			{
				long long minn = 1e9 + 1,t = 0;
				for(int j = r1; j <= r2; j++)
				{
					if(c[i][j] < minn) minn = c[i][j],t = j;
				}
				g[i] = t;
			}
			long long maxx = -1e9 - 1,t = 0;
			for(int i = l1; i <= l2; i++)
			{
				if(c[i][g[i]] > maxx) maxx = c[i][g[i]],t = i;
			}
			long long  minnn = 1e9 + 1,t1 = 0;
			for(int j = r1; j <= r2; j++)
			{
				if(c[t][j] < minnn) minnn = c[t][j],t1 = j;
			}
			cout << c[t][t1] << endl;
		}
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
