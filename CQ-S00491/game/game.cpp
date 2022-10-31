#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l1,r1,l2,r2;
	int a[10000],b[10000];
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	while(q--)
	{
		int zi=0,zj=0,mmax=-100000,mmin=999999;
		cin>>l1>>r1>>l2>>r2;
		
		for(int i=l1;i<=r1;i++)
		{
			for(int j=l2;j<=r2;j++)
				mmin=min(mmin,a[i]*b[j]);
			if(mmin>=mmax)
			{
				mmax=mmin;
				zi=i;
			}
		}
		
		mmax=-10000000,mmin=99999999;
		
		for(int i=l2;i<=r2;i++)
		{
			for(int j=l1;j<=r1;j++)
				mmax=max(mmax,a[i]*b[j]);
			if(mmax<=mmin)
			{
				mmin=mmax;
				zj=i;
			}
		}
		cout<<a[zi]*b[zj]<<'\n';
	}
}
