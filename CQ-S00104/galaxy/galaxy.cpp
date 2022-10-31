#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,q,t,l,r,a[3003][3003],b[10001],o;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=3003;i++)
		for (int j=1;j<=3003;j++)
			a[i][j]=1;
	for (int i=1;i<=n;i++)
	{
		b[i]=1;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		a[u][v]=1;
	}
	cin>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>u>>v;
			a[u][v]=0;
			b[u]-1;
		}
		else if(t==2)
		{
			cin>>u;
			b[u]=0;
		}
		else if(t==3)
		{
			cin>>u>>v; 
			a[u][v]=1;
			b[u]+1;
		}
		else if(t==4)
		{
			cin>>u;
			b[u]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				o++;
			}
			if(o%2==0&&b[j]==1)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
 } 
