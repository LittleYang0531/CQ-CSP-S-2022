#include<bits/stdc++.h> 
#define int long long

using namespace std;

int n,m;

int q; 

int r[10000005],c[10000005];
int a[10005][10005];

void aa(int x,int y)
{
	a[x][y]=1;
	
	c[x]--;
	r[y]--;
}

void bb(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i][x]==2)
		{
			a[i][x]=1;
			
			c[i]--;
			r[x]--;
		}
	}
}

void cc(int x,int y)
{
	a[x][y]=2;
	
	c[x]++;
	r[y]++;
}

void dd(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i][x]==1)
		{
			a[i][x]=2;
			
			c[i]++;
			r[x]++;
		}
	}
}

bool dfs()
{
	int ans=0;
	
	for(int i=1;i<=n;i++)
	{	
		if(c[i]==0)
		{
			return 0;
		}
	
		if(c[i]!=1)
		{
			return 0;
		}
	}
	
	return 1;
}

signed main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)//ÊäÈë 
	{
		int u,v;
		cin>>u>>v;
		
		a[u][v]=2;//´æ·Å 
		r[v]++;
		c[u]++;
	}
	
	cin>>q;
	
	while(q--)
	{
		int t,x,y;
		
		cin>>t;
		
		if(t==1)
		{
			cin>>x>>y;
			aa(x,y); 
		}
		else
		{
			if(t==2)
			{
				cin>>x;
				bb(x);
			}
			else
			{
				if(t==3)
				{
					cin>>x>>y;
					cc(x,y);
				}
				else
				{
					cin>>x;
					dd(x);
				}
			}
		}
		
		if(dfs()==1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return 0;
}
