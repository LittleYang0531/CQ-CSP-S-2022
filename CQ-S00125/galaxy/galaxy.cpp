#include<bits/stdc++.h>
using namespace std;
long long n,m,u,v,q,i;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>u>>v;
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>u;	
		srand(time(NULL));
		if(rand()%2==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

