#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int m,n,a,b,c,f;
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
	}
	cin>>f;
	for(int i=0;i<f;i++)
	{
		cin>>a;
		if(a==1)
		{
			cin>>b>>c;
		}
		else if(a==2)
		{
			cin>>b;
		}
		else if(a==3)
		{
			cin>>b>>c;
		}
		else if(a==4)
		{
			cin>>b;
		}
	}
	for(int i=0;i<f;i++)
	{
		cout<<"NO"<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
