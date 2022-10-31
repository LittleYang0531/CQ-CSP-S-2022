#include<bits/stdc++.h>
using namespace std;
int n,m,q,i,j,l1,l2,r1,r2,u,h,l=-1,r=99999999,x=99999999,p=99999999;
long long a[100001],b[100001];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)cin>>b[i];
	for(i=1;i<=q;i++)
	{
		cin>>l1>>r1>>l2>>r2;
		for(j=l1;j<=r1;j++)if(a[j]<0)u=1;
		for(j=l2;j<=r2;j++)if(b[j]<0)h=1;
		for(j=l1;j<=r1;j++)if(a[j]>=0&&a[j]<x)x=a[j];
		for(j=l2;j<=r2;j++)if(b[j]>=0&&b[j]<p)p=b[j];
		for(j=l1;j<=r1;j++)if(a[j]>=l)l=a[j];
		for(j=l2;j<=r2;j++)if(b[j]<=r)r=b[j];
		if(u==1&&h==1)cout<<x*r<<endl;
		else if(u==0&&h==1)cout<<x*r<<endl;
		else if(h==0)cout<<l*r<<endl;
		l=-1;
		r=99999999;
		x=99999999;
		p=99999999;
		u=0;
		h=0;
	}
	return 0;
}
