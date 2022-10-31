#include<bits/stdc++.h> 
#define int long long

using namespace std;

const int inf=1e9;

int n,q,k;

int v[10000000];//传输时间 

int a[10005][10005];

int c[10000000];

int dfs(int x,int y,int k,int s)
{
	if(x==y)
	{
		return v[y];
	}
	else
	{
		if(c[x]==1&&a[x][1]==s)
		{
			return inf;
		} 
		
		int minn=inf;
		
		for(int i=1;i<=c[x];i++)
		{
			if(a[x][i]!=s)
			{
				int ans=dfs(a[x][i],y,k,x);
			
				if(ans!=inf)
				{
					minn=min(minn,ans+v[x]);
				}
			}	
		}

		return minn;
	}
}

signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<n;i++)//连接 
	{
		int x,y;
		cin>>x>>y;
		a[x][++c[x]]=y;
		a[y][++c[y]]=x;	
	}
	
	while(q--)
	{
		int A,B;
		cin>>A>>B;
		
		cout<<dfs(A,B,k,A)<<endl;
	}
	
	return 0;
}
