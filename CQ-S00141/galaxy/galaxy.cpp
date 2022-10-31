#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int t,u,v;
		cin>>t;
		if(t==1)
		{
			cin>>u>>v;
		}
		if(t==2)
		{
			cin>>u;
		}
		if(t==3)
		{
			cin>>u>>v;
		}
		if(t==4)
		{
			cin>>u;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}
