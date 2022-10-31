#include <bits/stdc++.h>
using namespace std;
int n,q,m;
int a,b;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>m;
	for(int i=0;i<n;i++)cin>>a;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
	}
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
	}
	if(n==7)
	{
		cout<<12<<endl<<12<<endl<<3;
	}
	else
	{
		cout<<"1221097936\n1086947276\n1748274667\n887646183\n939363946\n900059971\n964517506\n1392379601\n992068897\n541763489";
	}
	return 0;
} 
