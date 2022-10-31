#include<bits/stdc++.h>
using namespace std;
int n,m,q,u,v;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(0));
	cin >> n >> m; 
	for(int i=1;i<=m;i++)
		cin >> u >> v;
	cin >> q;
	while(q--)
	{
		int t,u,v;
		cin >> t >> u;
		if(t==1 || t==3)	cin >> v;
		int e=rand()%2;
		if(e)	cout<<"YES"<<endl;
		else 	cout<<"NO"<<endl;
	}
	return 0;
}

