#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[200005],b[200005],c[2005][2005],l1,r1,l2,r2,cj[200005];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	if(n*m*q<=5e7)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				c[i][j]=a[i]*b[j];
				//cout<<c[i][j]<<" ";
			}
			//cout<<"\n";
		}
		while(q--)
		{
			cin>>l1>>l2>>r1>>r2;
			long long maxx=-0x3f3f3f3f3f3f3f3f,maxi=0,l;
			for(int i=l1;i<=l2;i++)
			{
				long long minn=0x3f3f3f3f3f3f3f3f;
				for(int j=r1;j<=r2;j++)
				{
					minn=min(minn,c[i][j]);
				}
				if(minn>maxx)
				{
					maxx=minn;
					maxi=i;
				}
			}
			l=maxi;
			long long minn=0x3f3f3f3f3f3f3f3f;
			for(int i=r1;i<=r2;i++)
			{
				minn=min(minn,c[l][i]);
			}
			cout<<minn<<"\n";
		}
	}
	else
	{
		while(q--)
		{
			//memset(cj,0,sizeof(cj));
			cin>>l1>>l2>>r1>>r2;
			long long maxx=-0x3f3f3f3f3f3f3f3f,minn=0x3f3f3f3f3f3f3f3f,ans=-0x3f3f3f3f3f3f3f3f;
			for(int i=r1;i<=r2;i++)
			{
				maxx=max(maxx,b[i]);
				minn=min(minn,b[i]);
			}
			for(int i=l1;i<=l2;i++)
			{
				if(a[i]>=0)
				{
					cj[i]=a[i]*minn;
				}
				if(a[i]<0)
				{
					cj[i]=a[i]*maxx;
				}
				//cout<<cj[i]<<" ";
			}
			for(int i=l1;i<=l2;i++)
			{
				ans=max(ans,cj[i]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

