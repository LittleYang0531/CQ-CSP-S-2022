#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[10001],b[10001],c[10001][10001],aa,bb,cc,dd,maxn;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			c[i][j] = a[i]*b[j];
		}
	}
	while(q--)
	{
		cin>>aa>>bb>>cc>>dd;
		maxn = 100000;
		int minn = 0;
		int flag = 1;
		for(int i = aa;i<=bb;i++)
		{
			flag = 1;
			for(int j = cc;j<=dd;j++)
			{
				if(c[i][j] <0)
				{
					flag = 0;
					continue;
				}
			}
			if(flag == 1)
			{
				for(int j = cc;j<=dd;j++)
				{
					maxn= min(maxn,c[i][j]);
				}
				minn = max(minn,maxn);
			}
			
		}
		cout<<maxn;
	}
	return 0;
}
