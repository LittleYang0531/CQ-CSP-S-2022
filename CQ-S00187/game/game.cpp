#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[10001],b[10001],c[10001][10001],l1,r1,l2,r2,d[100001][2],x,y;
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
		for(int j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	while(q--)
	{	
		x=0,y=0,d[100001][2]={};
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1&&l2==r2)
		{
			cout<<c[l1][r2]<<endl;
			break;
		}
		else
		if(l2==r2)
		{
			int h=0;
			for(int i=1;i<=n;i++)
				h=max(h,c[i][l1]);
			cout<<h<<endl;
			break;
		}
		for(int i=1;i<=r1-l1+1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				d[i][1]=max(d[i][1],c[i][j]);
				d[i][2]=min(d[i][2],c[i][j]);
			}
		}
		
		for(int i=1;i<=r1-l1+1;i++)
			cout<<d[i][1]<<" ";
		cout<<endl;		
		for(int i=1;i<=r1-l1+1;i++)
			cout<<d[i][2]<<" ";
		cout<<endl;	
		
		for(int i=1;i<=max(r1-l1,r2-l2);i++)
			for(int j=i+1;j>1;j--)
				if(d[j-1][1]<d[j][1])
					swap(d[j][1],d[j-1][1]);
		for(int i=1;i<=max(r1-l1,r2-l2);i++)
			for(int j=i+1;j>1;j--)
				if(d[j-1][2]<d[j][2])
					swap(d[j-1][2],d[j][2]);
					
		for(int i=1;i<=max(r1-l1+1,r2-l2+1);i++)
			cout<<d[i][1]<<" ";
		cout<<endl;		
		for(int i=1;i<=max(r1-l1+1,r2-l2+1);i++)
			cout<<d[i][2]<<" ";
		cout<<endl;	
		
		if(l1==r1)
		{
			cout<<d[l1][1]<<endl;
			break;
		}
		else cout<<d[1][2]<<endl;
	}
	return 0;
}

