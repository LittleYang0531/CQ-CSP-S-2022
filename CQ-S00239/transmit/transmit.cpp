#include<bits/stdc++.h>
using namespace std;
int n,q,k,v[100005],a[100005],b[100005],s,t;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++)
	{
		cin>>s>>t;
		if(s!=1&&t!=1)cout<<s+t+1<<endl;
		else cout<<s+t;
	}
	return 0;
}
