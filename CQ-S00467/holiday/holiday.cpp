#include<bits/stdc++.h> 
#define int long long

using namespace std;

int n,m,k;

struct aa{
	int cnt;
	int x[10000];
	int zhi;
}a[10000];

int dfs(int x,int k,int xx)
{
	if(xx==4)
	{
		for(int i=1;i<=a[x].cnt;i++)
		{
			if(a[x].x[i]==1)
			{
				return a[x].zhi;
			}
		}
		
		return 0;
	}
	else
	{
		int maxx=0;
		
		for(int i=1;i<=a[x].cnt;i++)
		{
			int ans=dfs(a[x].x[i],k,xx+1);
			
			if(ans)
			{
				ans+=a[x].zhi;
			}
			maxx=max(ans,maxx);
		}
		
		return maxx;
	}
}

signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i].zhi;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		
		a[x].x[++a[x].cnt]=y;
		a[y].x[++a[y].cnt]=x;
	}
	
	cout<<dfs(1,k,0);
	
	return 0;
}

/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
