#include<bits/stdc++.h>
using namespace std;
struct hh{
	int tou;
	int wei;
}p[10005];
int mian()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout); 
	int n,m,k;
	int ans=0;
	int a[2505]; 
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].tou>>p[i].wei;
	}
	if(k<=0)
	{
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(p[i].wei==p[j].tou)
			ans+=a[p[j].wei];
		}	
	}
	cout<<ans;
	return 0;
}
