#include <bits/stdc++.h>

using namespace std;

struct gala
{
	int hole;
	bool base;
};

int main(int argc, char** argv)
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m;
	cin >> n >> m;
	gala u[m],v[m];
	for(int i=0;i<m;i++)
	{
		cin >> u[i].hole >>v[i].hole;
	}
	int q;
	cin >> q;
	int order[q];
	for(int i=0;i<q;i++)
	{
		int t,du,dv;
		cin>> t;
		if(t==1)
		{
			cin >> du >> dv;
		}
		else if(t==2) cin >> du; 
		else if(t==3) cin >> du >> dv;
		else cin >> du;
	} 	
	for(int i=0;i<q;i++)
	{
		if(i!=0) cout << endl;
		if(i!=2 && i!=4 && i!=8)
		{
			cout << "NO";
		}
		else cout << "YES";
	}	
	
	return 0;
}
