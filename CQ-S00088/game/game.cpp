#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[2001],b[2001],c[201][201];
int mah[201],mil[201];
int main()
{
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
cin>>n>>m>>q;
for(int i=1;i<=n;i++)
	cin>>a[i];
for(int i=1;i<=m;i++)
	cin>>b[i];
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		c[i][j]=a[i]*b[j];
		mil[j]=min(mil[j],c[i][j]);
		mah[i]=max(c[i][j],mah[i]);
	}	
}
for(int i=1;i<=q;i++)
{
	int l1,l2,r1,r2;
	cin>>l1>>r1>>l2>>r2;
	if(l1==r1)
	{
		int mi=2100000000;
		for(int j=1;j<=m;j++)
			mi=min(mi,c[l1][j]);
		cout<<mi<<endl;
	}
	if(l2==r2)
	{
		int ma=-2100000000;
		for(int j=1;j<=n;j++)
			ma=max(ma,c[j][l2]);
		cout<<ma<<endl;
	}
	else
	{
		int aa=0,a1;
		for(int i=l1;i<=r1;i++)
		{
			if(aa<mah[i])
			{
				a1=i;
				aa=max(mah[i],aa);
			}	
		}	
		int bb=0,b1;
		for(int i=l2;i<=r2;i++)
		{
			if(bb<mil[i])
			{
				b1=i;
				bb=min(mil[i],bb);
			}
		}			
		cout<<c[a1][b1]<<endl;
	}
}
	return 0;
}
