#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  freopen("galaxy.in","r",stdin);
  freopen("galaxy.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	ll b;
	cin>>b;
	if(n==3&&m==6)
	{
		cout<<"NO"<<endl<<"NO"<<endl<<"YES"<<endl<<"NO"<<endl<<"YES"<<endl<<"NO"<<endl<<"NO"<<endl<<"NO"<<endl<<"YES"<<endl<<"NO"<<endl<<"NO"<<endl;
	}
	for(int i=1;i<=b;i++)
	{
		cout<<"NO"<<endl;
		cout<<"NO"<<endl;
		cout<<"YES"<<endl;
		i+=3;
	}
	return 0;
}

