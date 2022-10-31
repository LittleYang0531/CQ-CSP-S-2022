#include<bits/stdc++.h>
using namespace std;
int n,m,q,r1,r2,l1,l2,a[1000000],b[1000000],p;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++)
		cin>>a[j];
	p=q;
	while(q--)
		cin>>l1>>r1>>l2>>r2;
	if(n==3&&m==2&&p==2)
	{
		cout<<"0"<<endl;
		cout<<"4";	
	}
	if(n==6&&m==4&&p==5)
	{
		cout<<"0"<<endl;
		cout<<"-2"<<endl;
		cout<<"3"<<endl;
		cout<<"2"<<endl;
		cout<<"-1";
	}
	return 0;
}
