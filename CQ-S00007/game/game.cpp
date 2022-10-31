#include<bits/stdc++.h>
using namespace std;
#define N 1010 
int n,m,a[N],b[N],c[N][N],q;
double p[N];
int x1,x2,y11,y2;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
	for(int i=1;i<=n;i++)
	{
		int tt=INT_MAX;
		for(int j=1;j<=m;j++)
			tt=min(tt,c[i][j]);
		p[i]=tt;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<c[i][j]<<" ";
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++)
//		cout<<p[i]<<endl;
	for(int i=1;i<=q;i++)
	{
		cin>>x1>>x2>>y11>>y2;
		if(x1==x2)
		{
			int lie2=y11,t3=c[x1][y11];
			for(int j=y11+1;j<=y2;j++)
				if(c[x1][j]<t3)
					t3=c[x1][j],lie2=j;
			cout<<c[x1][lie2]<<endl;
		}
		else if(y11==y2)
		{
			int line2=x1,t4=c[x1][y11];
			for(int j=x1+1;j<=x2;j++)
				if(c[j][y11]>t4)
					t4=c[j][y11],line2=j;
			cout<<c[line2][y11]<<endl;
		}
		else
		{
			int t=p[x1];
			int line=x1;
			for(int j=x1+1;j<=x2;j++)
				if(p[j]>t)
					t=p[j],line=j;
			int lie=y11;
			int t2=c[line][y11];
			for(int j=y11+1;j<=y2;j++)
				if(c[line][j]<t2)
					t2=c[line][j],lie=j;
			cout<<c[line][lie]<<endl;			
		}
	}
	return 0;
}
