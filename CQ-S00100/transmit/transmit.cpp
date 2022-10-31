#include<bits/stdc++.h>
using namespace std;
long long n,q,k,v[200005],x,y,xx,yy;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>xx>>yy;
		cout<<v[xx]+v[yy]<<"\n";
	}
	return 0;
}

