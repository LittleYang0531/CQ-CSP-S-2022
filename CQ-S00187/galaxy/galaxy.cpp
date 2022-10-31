#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct f
{
	int u,v;
}a[10000];
struct f1
{
	int t,u,v;
}b[10000];
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v;
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>b[i].t>>b[i].u>>b[i].v;
		
	return 0;
}
