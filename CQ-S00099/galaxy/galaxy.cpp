#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int x,y;
int t,u,v;
int b[1010],c[1010];
int a[1010][1010];
int main() 
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>x>>y;
    	a[x][y]=1;
    	a[y][x]=1;
    	b[y]++;
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>u>>v;
			b[u]--;
			a[u][v]=-1;
		}
		if(t==2)
		{
			cin>>u;
			for(int j=1;j<=n;j++)
			{
				if(a[j][u]==1)
				{
					a[u][j]=-1;
					a[j][u]=-1;
					if(b[j]>0)
					    b[j]--;
				}
			}
		}
		if(t==3)
		{
			cin>>u>>v;
			b[u]++;
			a[u][v]=1;
		}
		if(t==4)
		{
			cin>>u;
			for(int j=1;j<=n;j++)
			{
				if(a[j][u]==-1)
				{
					a[u][j]=1;
					a[j][u]=1;
					b[u]++;
				}
			}
		}
		int t=0;
		for(int j=1;j<=n;j++)
		    if(b[j]!=1)
		    {
		    	t=1;
		    	break;
			}
		if(t==0)
		    cout<<"YES"<<endl;
		else
		    cout<<"NO"<<endl;
	}
	cout<<endl;
	return 0;
}
