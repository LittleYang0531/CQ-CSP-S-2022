#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[10010],b[10010];
int MAXa=1e9,MINb=1e9;
int l1,l2,r1,r2;
int main() 
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    MAXa=min(MAXa,a[i]);
	}
    for(int i=1;i<=m;i++)
	{
	    cin>>b[i];
	    MINb=min(MINb,b[i]);
	}
    for(int i=1;i<=q;i++)
    {
    	cin>>l1>>r1>>l2>>r2;
    	long long sum,s;
		if(l1==r1)
    	{
    		sum=1e9;
			int x=a[l1];
    		for(int i=l2;i<=r2;i++)
    		{
    			int y=b[i];
    			s=x*y;
    			sum=min(sum,s);
			}
			cout<<sum<<endl;
		}
		else if(l2==r2)
    	{
    		sum=-1e9;
			int y=b[l2];
    		for(int i=l1;i<=r1;i++)
    		{
    			int x=a[i];
    			s=x*y;
    			sum=max(sum,s);
			}
			cout<<sum<<endl;
		}
		else if(MINb>=0&&MAXa>=0)
		{
			MAXa=0;
			MINb=1e9;
			for(int i=l1;i<=r1;i++)
			    MAXa=max(MAXa,a[i]);
			for(int i=l2;i<=r2;i++)
			    MINb=min(MINb,b[i]);
			long long sum=MAXa*MINb;
			cout<<sum<<endl;
		}
		else
		{
			long long MAXA=0;
			MINb=1e9;
			int x,y;
			for(int i=l1;i<=r1;i++)
			{
				for(int j=l2;j<=r2;j++)
				{
					if(i*j>MAXA)
					{
					    x=i;
					    MAXA=i*j;
					}
				}
			}
			for(int i=l2;i<=r2;i++)
			    MINb=min(MINb,b[i]);
			long long sum=MINb*x;
			cout<<sum<<endl;
		}
	}
	cout<<endl;
	return 0;
}
