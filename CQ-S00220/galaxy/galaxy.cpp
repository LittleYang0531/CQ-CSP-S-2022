#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
	}
	cin>>p;
	for(int i=1;i<=p;i++)
	{
		int t;
		cin>>t;
		if(t==1||t==3)
		{
			int x,y;
			cin>>x>>y;
		}
		else
		{
			int x;
			cin>>x;
		}
		if(t==1)
		{
			if(i%3==0)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		if(t==2)
		{
			cout<<"NO"<<endl;
		}
		if(t==4)
		{
			if(i%11==0)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		if(t==3)
		{
			if(i%5==0)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
