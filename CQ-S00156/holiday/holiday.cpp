#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v;
	int num;
}a[500005];
int map1[2505][2505];
bool cmp(node x,node y)
{
	return x.v>y.v;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i].v;
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	int x,y;
	for(int i=1;i<=m;i++)
	{
	    cin>>x>>y;
		map1[x][y]=1;
		map1[y][x]=1;
	}
	for(int i=1;i<=n-1;i++)
	for(int j=1;j<=n-1;j++)
	for(int p=1;p<=n-1;p++)
	for(int q=1;q<=n-1;q++)
	{
		if(i!=j&&i!=p&&i!=p&&i!=q&&j!=p&&j!=q&&p!=q)
		{
			if(map1[1][a[i].num]==1&&map1[a[i].num][a[j].num]==1&&map1[a[j].num][a[p].num]==1&&map1[a[p].num][a[q].num]==1&&map1[a[q].num][1]==1)
		    {
		    	cout<<a[i].v+a[j].v+a[p].v+a[q].v;
		    	return 0;
			}
		}
	}
	return 0;
}
