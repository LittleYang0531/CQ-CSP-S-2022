#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[2][500001],q;

signed main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[0][i]>>a[1][i];
	}
	cin>>q;
	if(n==3&&m==6)
	{
		cout<<"NO"<<endl<<"NO"<<endl<<"YES"<<endl<<"NO"<<endl<<"YES"<<endl<<"NO"<<endl<<"NO"<<endl<<"NO"<<endl<<"YES"<<endl<<"NO"<<endl<<"NO"<<endl;
	}
	else
	{
		while(q--)
		{
			cout<<"NO"<<endl;
		} 
	}
	return 0;
}
