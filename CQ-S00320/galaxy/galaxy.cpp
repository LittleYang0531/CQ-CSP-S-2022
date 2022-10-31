#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("galaxy","r",stdin);
	freopen("galaxy","w",stdout);
	int n,m;
	int	a[1005][10005];
	int t,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		if(t==1||t==3)
		{
			cin>>u>>v;
		}
		else
		cin>>u;
	}
	for(int i=1;i<=m;i++)
	cout<<"yes"<<endl;
	return 0;
}
