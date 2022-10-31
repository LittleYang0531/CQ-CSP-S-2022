#include<bits/stdc++.h>
using namespace std;
struct hh{
	int lx;
	int rx;
	int ly;
	int ry;
}p[1005];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int ansa,ansb;
	int n,m,q;
	int a[1005],b[1005];
	int c[1005][1005];
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>p[i].lx>>p[i].rx>>p[i].ly>>p[i].ry; 
	}
	for(int i=1;i<=q;i++)
	{
		for(int k=p[i].lx;k<=p[i].rx;k++)
		{
			if(a[k]>ansa)
			{
				ansa=a[k];
			}
		}
		for(int k=p[i].ly;k<=p[i].ry;k++)
		{
			if(b[k]<ansb)
			{
				ansb=b[k];
			}
		}
		cout<<ansa*ansb;
	}
	return 0;
}
