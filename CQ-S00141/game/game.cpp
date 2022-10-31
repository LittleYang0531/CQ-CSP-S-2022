#include<bits/stdc++.h>
using namespace std;
long long n,m,q;
long long a[100005],b[100005];
long long bja[100005],bjb[100005];
long long l1,l2,r1,r2;
struct ka
{
	long long l,r,maxx,minn;
}ka[100005],kb[100005];
long long cnta,cntb;
long long maxxa(long long l,long long r)
{
	if(bja[l]==bja[r])
	{
		long long maxx=-0x3f3f3f3f3f3f3f3f;
		for(long long i=l;i<=r;i++)
		{
			maxx=max(maxx,a[i]);
		}
		return maxx;
	}
	long long maxx=-0x3f3f3f3f3f3f3f3f;
	for(long long i=l;i<=ka[bja[l]].r;i++)
	{
		maxx=max(maxx,a[i]);
	}
	for(long long i=bja[l]+1;i<=bja[r]-1;i++)
	{
		maxx=max(maxx,ka[i].maxx);
	}
	for(long long i=ka[bja[r]].l;i<=r;i++)
	{
		maxx=max(maxx,a[i]);
	}
	return maxx;
}
long long minna(long long l,long long r)
{
	if(bja[l]==bja[r])
	{
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(long long i=l;i<=r;i++)
		{
			minn=min(minn,a[i]);
		}
		return minn;
	}
	long long minn=0x3f3f3f3f3f3f3f3f;
	for(long long i=l;i<=ka[bja[l]].r;i++)
	{
		minn=min(minn,a[i]);
	}
	for(long long i=bja[l]+1;i<=bja[r]-1;i++)
	{
		minn=min(minn,ka[i].minn);
	}
	for(long long i=ka[bja[r]].l;i<=r;i++)
	{
		minn=min(minn,a[i]);
	}
	return minn;
}
long long maxxb(long long l,long long r)
{
	if(bjb[l]==bjb[r])
	{
		long long maxx=-0x3f3f3f3f3f3f3f3f;
		for(long long i=l;i<=r;i++)
		{
			maxx=max(maxx,b[i]);
		}
		return maxx;
	}
	long long maxx=-0x3f3f3f3f3f3f3f3f;
	for(long long i=l;i<=kb[bjb[l]].r;i++)
	{
		maxx=max(maxx,b[i]);
	}
	for(long long i=bjb[l]+1;i<=bjb[r]-1;i++)
	{
		maxx=max(maxx,kb[i].maxx);
	}
	for(long long i=kb[bjb[r]].l;i<=r;i++)
	{
		maxx=max(maxx,b[i]);
	}
	return maxx;
}
long long minnb(long long l,long long r)
{
	if(bjb[l]==bjb[r])
	{
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(long long i=l;i<=r;i++)
		{
			minn=min(minn,b[i]);
		}
		return minn;
	}
	long long minn=0x3f3f3f3f3f3f3f3f;
	for(long long i=l;i<=kb[bjb[l]].r;i++)
	{
		minn=min(minn,b[i]);
	}
	for(long long i=bjb[l]+1;i<=bjb[r]-1;i++)
	{
		minn=min(minn,kb[i].minn);
	}
	for(long long i=kb[bjb[r]].l;i<=r;i++)
	{
		minn=min(minn,b[i]);
	}
	return minn;
}



int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long k=sqrt(n);
	for(long long i=1;i<=k;i++)
	{
		ka[++cnta].l=(i-1)*k+1;
		ka[cnta].r=i*k;
	}
	if(ka[cnta].r<n)
	{
		ka[++cnta].l=ka[cnta-1].r+1;
		ka[cnta].r=n;
	}
	for(long long i=1;i<=cnta;i++)
	{
		long long maxx=-0x3f3f3f3f3f3f3f3f;
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(long long j=ka[i].l;j<=ka[i].r;j++)
		{
			bja[j]=i;
			maxx=max(maxx,a[j]);
			minn=min(minn,a[j]);
		}
		ka[i].maxx=maxx;
		ka[i].minn=minn;
	}
	
	for(long long i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	k=sqrt(m);
	for(long long i=1;i<=k;i++)
	{
		kb[++cntb].l=(i-1)*k+1;
		kb[cntb].r=i*k;
	}
	if(kb[cntb].r<m)
	{
		kb[++cntb].l=kb[cntb-1].r+1;
		kb[cntb].r=m;
	}
	for(long long i=1;i<=cntb;i++)
	{
		long long maxx=-0x3f3f3f3f3f3f3f3f;
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(long long j=kb[i].l;j<=kb[i].r;j++)
		{
			bjb[j]=i;
			maxx=max(maxx,b[j]);
			minn=min(minn,b[j]);
		}
		kb[i].maxx=maxx;
		kb[i].minn=minn;
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>l1>>r1>>l2>>r2;
	
		if(l1==r1)
		{
			if(a[l1]==0)
			{
				cout<<0<<endl;
			}
			else
			{
				if(a[l1]<0)
				{
					cout<<a[l1]*maxxb(l2,r2)<<endl;
				}
				else
				{
					if(a[l1]>0)
					{
						cout<<a[l1]*minnb(l2,r2)<<endl;
					}
				}
			}
		}
		else if(l2==r2)
		{
			if(b[l2]==0)
			{
				cout<<0<<endl;
			}
			else
			{
				if(b[l2]<0)
				{
					cout<<b[l2]*minna(l1,r1)<<endl;
				}
				else
				{
					if(b[l2]>0)
					{
						cout<<b[l2]*maxxa(l1,r1)<<endl;
					}
					else
					{
						cout<<0<<endl;
					}
				}
			}
		}
		else
		{
			long long fu=0;
			long long maxxz=-0x3f3f3f3f3f3f3f3f;
			long long maxxf=-0x3f3f3f3f3f3f3f3f;
			long long minnz=0x3f3f3f3f3f3f3f3f;
			long long minnf=0x3f3f3f3f3f3f3f3f;
			long long mab=-0x3f3f3f3f3f3f3f3f;
			long long mib=0x3f3f3f3f3f3f3f3f;
			for(long long i=l2;i<=r2;i++)
			{
				mab=max(b[i],mab);
				mib=min(b[i],mib);
			}
			long long za=0,fa=0;
			long long ans=-0x3f3f3f3f3f3f3f3f;
			for(long long i=l1;i<=r1;i++)
			{
				if(a[i]>=0)za=1;
				if(a[i]<=0)fa=1;
				if(a[i]>=0&&a[i]>maxxz)maxxz=a[i];
				if(a[i]<=0&&a[i]>maxxf)maxxf=a[i];
				if(a[i]>=0&&a[i]<minnz)minnz=a[i];
				if(a[i]<=0&&a[i]<minnf)minnf=a[i];
			}
			if(za==1)
			{
				//ักีýสý
				if(mib<0)
				{
					ans=max(ans,minnz*mib);
				}
				if(mib>0)
				{
					ans=max(ans,maxxz*mib);
				}
				if(mib==0)
				{
					ans=max(ans,0ll);
				}
			}
			if(fa==1)
			{
				if(mab>0)
				{
					ans=max(ans,maxxf*mab);
				}
				if(mab<0)
				{
					ans=max(ans,minnf*mab);
				}
				if(mab==0)
				{
					ans=max(ans,0ll);	
				} 
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 4 4
5 5 1 4
1 4 2 2
6 6 3 4
2 5 3 3

3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
