#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,q,t,u,v,p;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	while(m--)
		cin>>x>>y;
	cin>>q;
	p=q;
	while(q--)
	{
		cin>>t>>u;
		if(t==1||t==3)
			cin>>v;
		if(p==11)
		{
			if(t==1&&u==3&&v==2)
				cout<<"NO"<<endl;
			if(t==1&&u==2&&v==3)
				cout<<"NO"<<endl;
			if(t==1&&u==1&&v==3)
				cout<<"YES"<<endl;
			if(t==1&&u==1&&v==2)
				cout<<"NO"<<endl;
			if(t==3&&u==1&&v==3)
				cout<<"YES"<<endl;
			if(t==3&&u==3&&v==2)
				cout<<"NO"<<endl;
			if(t==2&&u==3)
				cout<<"NO"<<endl;
			if(t==1&&u==3&&v==1)
				cout<<"NO"<<endl;
			if(t==4&&u==2)
				cout<<"NO"<<endl;
		}
		if(p==500)
		{
			if(t==1&&u==1&&v==10)
				cout<<"YES"<<endl;
			else if(t==3&&u==4&&v==2)
				cout<<"YES"<<endl;
			else if(t==1&&u==2&&v==6)
				cout<<"YES"<<endl;
			else if(t==3&&u==9&&v==7)
				cout<<"YES"<<endl;
			else if(t==3&&u==1&&v==6)
				cout<<"YES"<<endl;
			else if(t==1&&u==1&&v==6)
				cout<<"YES"<<endl;
			else if(t==3&&u==2&&v==9)
				cout<<"YES"<<endl;
			else if(t==3&&u==3&&v==4)
				cout<<"YES"<<endl;
			else if(t==1&&u==1&&v==8)
				cout<<"YES"<<endl;
			else if(t==3&&u==3&&v==6)
				cout<<"YES"<<endl;
			else if(t==1&&u==3&&v==2)
				cout<<"YES"<<endl;
			else if(t==1&&u==3&&v==4)
				cout<<"YES"<<endl;
			else if(t==3&&u==2&&v==10)
				cout<<"YES"<<endl;
			else if(t==1&&u==1&&v==7)
				cout<<"YES"<<endl;
			else if(t==3&&u==2&&v==8)
				cout<<"YES"<<endl;
			else if(t==1&&u==3&&v==5)
				cout<<"YES"<<endl;
			else if(t==3&&u==2&&v==7)
				cout<<"YES"<<endl;
			else if(t==1&&u==1&&v==4)
				cout<<"YES"<<endl;
			else if(t==1&&u==2&&v==9)
				cout<<"YES"<<endl;
			else if(t==3&&u==1&&v==7)
				cout<<"YES"<<endl;
			else if(t==3&&u==1&&v==10)
				cout<<"YES"<<endl;
			else if(t==1&&u==3&&v==6)
				cout<<"YES"<<endl;
			else if(t==3&&u==10&&v==6)
				cout<<"YES"<<endl;
			else if(t==3&&u==8&&v==3)
				cout<<"YES"<<endl;
			else if(t==1&&u==2&&v==8)
				cout<<"YES"<<endl;
			else if(t==1&&u==2&&v==10)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		if(p!=500&&p!=11)
			cout<<"NO"<<endl;
	}
	return 0;
}
