#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[10001][10001];
int n,m,q,bigger = 999999999999999999999,smaller = -9999999999999999999999,ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	int qq = 0;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	for(int j = 1;j<=m;j++)
		cin>>b[j];
	while(qq<q)
	{
		int l1,l2,r1,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1 == r1)
		{
			int maxm = -99999999;
			for(int i = 1;i<m;i++)
				if(b[i]>maxm)
					maxm = b[i];
			cout<<a[l1]*maxm;
			return 0;
		}
		if(r2 == l2)
		{
			int maxm = -99999999;
			for(int i = 1;i<m;i++)
				if(a[i]>maxm)
					maxm = a[i];
			cout<<b[l1]*maxm;
			return 0;
		}
	}
	return 0;
}
