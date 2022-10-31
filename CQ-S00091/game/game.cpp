#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    int n,m,q,a[100000],b[100000],flag1,flag2;
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
		int l1,r1,l2,r2,minn=1e9,maxn=-1e9;
		flag1=0,flag2=0;
		cin>>l1>>r1>>l2>>r2;
		for(int j=l2;j<=r2;j++)
			{
				if(minn>b[j])
				{
					minn=b[j];
				}
			}
		for(int z=l1;z<=r1;z++)
			{
				if(maxn<a[z])
				{
					maxn=a[z];
				}
			}	
		if(l1==r1)
		{
			cout<<minn*a[l1];
			continue;
		}
		if(l2==r2)
		{
			cout<<maxn*b[l2];
			continue;
		}
		cout<<minn*maxn<<endl;
	}
	return 0;
}
