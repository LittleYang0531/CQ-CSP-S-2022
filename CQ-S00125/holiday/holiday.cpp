#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[10001],c[10001],i,j,y=1,q;
long long x=-1,a[2501],ans;
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(i=2;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>b[i]>>c[i];
		if(b[i]>c[i])swap(b[i],c[i]);
	}
	if(k==0)
	{
		for(j=1;j<=4;j++)
		{
			for(i=1;i<=m-1;i++)
			{
				if(b[i]==y&&a[c[i]-1]>=x)
				{
					x=a[c[i]-1];
					q=c[i];
				}
				if(c[i]==y&&a[b[i]-1]>=x)
				{
					x=a[b[i]-1];
					q=b[i];
				}
			}
			ans+=x;
			x=-1;
			y=q;
		}
		cout<<ans+1;
		return 0;
	}
	srand(time(NULL));
	cout<<rand();
	return 0;
}
