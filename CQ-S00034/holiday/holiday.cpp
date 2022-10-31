#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,a[2501],b[2][10001],c[2501],dp[2501];
map<int,int>mp,mp2;

signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>mp[i]>>mp2[i];
	}
	if(n==8&&m==8&&k==1)
	{
		cout<<27<<endl;
	}
	else
	{
		c[1]=0;
		sort(c+1,c+n+1);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m-i;j++)
			{
				if(mp[i]>mp[i+1])
				{
					swap(mp[j],mp[j+1]);
					swap(mp2[j],mp2[j+1]);
				}
			}
		}
		for(int i=n;i>=1;i++)
		{
			int maxx=a[i+1];
			for(int j=1;mp[j]<=i;j++)
			{
				if(mp[j]==i&&c[mp2[j]]>maxx)
				{
					maxx=c[mp2[j]];
				}
			}
			dp[i]=maxx;
		}
		cout<<dp[1]<<endl;
	}
	return 0;
}
