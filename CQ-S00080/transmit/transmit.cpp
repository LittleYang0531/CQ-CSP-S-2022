#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int avi;
	int val;
	int sum;
}mp[2005][2005];
int n,q,k,v[20005];
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mp[i][j].sum=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		mp[i][i].sum=v[i];
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		mp[a][b].avi=1;
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				
			}
		}
	}
	return 0;
}
