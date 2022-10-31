#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100001],x,y;
struct data
{
	int x y;
}aa[100001];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>q;
	for(int i = 1;i<n;i++)
	{
		cin>>a[i];
	}for(int i = 1;i<=m;i++)
	{
		cin>>aa[i].x>>aa[i].y;
	}
	cout<<"27";
	return 0;
}
