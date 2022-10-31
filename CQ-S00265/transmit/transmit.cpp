#include<bits/stdc++.h>
using namespace std;
unsigned long long ww;
unsigned long long n,m,k,l,a[200010],jy[200010],x,y,mi,t,pp = INT_MAX;
vector<int>b[200010];
void dfs(int w,int sum,int cs)
{
	if(cs > n) return;
	if(w == y)
	{
		jy[w] = sum;
	//	cout << sum << endl << endl;
		if(sum < mi || (sum == mi && cs < t))
			mi = sum,t = cs;
		return;
	}
	for(int i = 0;i < b[w].size();i++)
	{
		dfs(b[w][i],sum + a[b[w][i]],cs + 1);
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);	
		pp = min(pp,a[i]);
	}
	for(int i = 1;i < n;i++)
	{
		scanf("%d%d",&x,&y);	
		b[x].push_back(y);
		b[y].push_back(x);	
	}
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d",&x,&y);	
		mi = INT_MAX;
		dfs(x,a[x],0);
		if(t <= k)
			printf("%d\n",mi);	
		else
		{
			printf("%d\n",a[x] + a[y] + pp);		
		}
	}
	return 0;
}
/*
		10 10 3
	835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
	2 1
	3 2
	4 2
	5 3
	6 3
	7 2
	8 7
	9 1
	10 9
	1 7
	1 5
	2 1
	1 9
	10 5
	3 10
	2 9
	10 2
	1 4
	4 7

*/

