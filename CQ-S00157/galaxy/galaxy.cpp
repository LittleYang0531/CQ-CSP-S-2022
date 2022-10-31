#include<bits/stdc++.h>
using namespace std;
int n,m,q,t,p1;
int a[100][100],b[100],c[100];
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		b[x]=1;
		b[y]=1;
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>t;
		int x,y;
		if(t==1)
		{
			cin>>x>>y;
			a[x][y]=2;
		}
		if(t==2)
		{
			cin>>x;
			b[x]=2;
		}
		if(t==3)
		{
			cin>>x>>y;
			a[x][y]=1;
		}
		if(t==4)
		{
			cin>>x;
			b[x]=1;
		}
		for(int j1=1;j1<=n;j1++)
		c[j1]=0;
		for(int j1=1;j1<=n;j1++)
		for(int j2=1;j2<=n;j2++)
		{
			if(a[j1][j2]==1&&b[j1]==1&&b[j2]==1)
			c[j1]++;
		}
		int p=0; 
		for(int j1=1;j1<=n;j1++)
		{
			//cout<<c[j1]<<endl;
			if(c[j1]!=1)
			p=1;
		}
		p1=0;
		for(int j1=1;j1<=n;j1++)
		for(int j2=1;j2<=n;j2++)
		for(int j3=1;j3<=n;j3++)		
		{
			if(a[j1][j2]==1&&a[j2][j1]==1)
			p1=1;
			if(a[j1][j2]==1&&a[j2][j3]==1&&a[j3][j1]==1)
			p1=1;
		}
		//cout<<p1<<" "<<p<<endl; 
		if(p1==1&&p==0)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl; 
	}
	return 0;
}
