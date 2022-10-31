#include<bits/stdc++.h>
using namespace std;
long long n,m,q,x,y,c[10000][10000],a[100000],b[100000],l1,l2,r1,r2;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int j=1;j<=m;j++)
	    cin>>b[j];
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        c[i][j]=a[i]*b[j];
	for(int i=1;i<=q;i++)
	{
		cin>>l1>>r1>>l2>>r2;
		if(l2==r2)
		{
			long long s;
			s=c[l1][l2];
			for(int i=l1;i<=r1;i++)
			   if(c[i][l2]>s)
			       s=c[i][l2];
			cout<<s<<endl;
		}
        else if(l1==r1)
        {
        	long long s;
        	s=c[l1][l2];
        	for(int i=l2;i<=r2;i++)
        	    if(c[l1][i]<s)
        	        s=c[l1][i];
        	cout<<s<<endl;
		}
		else
		{
		    long long s;
			s=c[l1][l2];
		    for(int i=l1;i<=r1;i++)
		        for(int j=l2;j<=r2;j++)
		           if(c[i][j]<s)
		               s=c[i][j];
		    for(int i=l1;i<=r1;i++)
			{
			    int f;
				f=c[i][l2];
				for(int j=l2;j<=r2;j++)
				{
					if(c[i][j]<f)
					    f=c[i][j];
				}
				if(f>s)
				    s=f;
			}
			cout<<s<<endl;
		}
    }
    return 0;
}
