#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[100001],b[100001];
long long k1[100001],k2[100001];
long long l1,l2,r1,r2;
int main()
{
	freopen("game.in","r",stdin);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	freopen("game.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		k1[i]=k1[i-1];
		if(a[i]<0)
		{
			k1[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
		k2[i]=k2[i-1];
		if(b[i]<0)
		{
			k2[i]++;
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long a1=k1[r1]-k1[l1-1],a2=k2[r2]-k2[l2-1];
		if(a1==r1-l1+1&&a2==r2-l2+1||a1!=r1-l1+1&&a1!=0&&a2==r2-l2+1)
		{
			long long Min=1e9,Max=-1e9;
			for(int j=l1;j<=r1;j++)
			{
				Min=min(Min,a[j]);
			}
			for(int j=l2;j<=r2;j++)
			{
				Max=max(Max,b[j]);
			}
			printf("%lld\n",Min*Max);
		}
		else if(a1==0&&a2==0||a1!=r1-l1+1&&a1!=0&&a2==0)
		{
			long long Min=1e9,Max=-1e9;
			for(int j=l2;j<=r2;j++)
			{
				Min=min(Min,b[j]);
			}
			for(int j=l1;j<=r1;j++)
			{
				Max=max(Max,a[j]);
			}
			printf("%lld\n",Min*Max);
		}
		else if(a1==0&&a2==r2-l2+1||a1==0&&a2!=r2-l2+1&&a2!=0)
		{
			long long Min1=1e9,Min2=1e9;
			for(int j=l2;j<=r2;j++)
			{
				Min1=min(Min1,b[j]);
			}
			for(int j=l1;j<=r1;j++)
			{
				Min2=min(Min2,a[j]);
			}
			printf("%lld\n",Min1*Min2);
		}
		else if(a1==r1-l1+1&&a2!=r2-l2+1&&a2!=0||a1==r1-l1+1&&a2==0)
		{
			long long Max1=-1e9,Max2=-1e9;
			for(int j=l2;j<=r2;j++)
			{
				Max1=max(Max1,b[j]);
			}
			for(int j=l1;j<=r1;j++)
			{
				Max2=max(Max2,a[j]);
			}
			printf("%lld\n",Max1*Max2);
		}
		else
		{
			long long Min=1e9,Max=-1e9;
			for(int j=l1;j<=r1;j++)
			{
				if(Min>a[j]&&a[j]>=0)
				{
					Min=a[j];
				}
				if(Max<a[j]&&a[j]<0)
				{
					Max=a[j];
				}
			}
			long long Min1=1e9,Max1=-1e9;
			for(int j=l2;j<=r2;j++)
			{
				if(Min1>b[j]&&b[j]<0)
				{
					Min1=b[j];
				}
				if(Max1<b[j]&&b[j]>=0)
				{
					Max1=b[j];
				}
			}
			Min=max(Min*Min1,Max*Max1);
			printf("%lld\n",Min);
		}
	}
	return 0;
}
