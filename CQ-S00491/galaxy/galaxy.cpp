#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a>>a;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a;
		cin>>a;
		int s,b;
		if(a==1||a==3)
			cin>>s>>s;
		else
			cin>>b;
		if((s+b+a)%4==0)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}

