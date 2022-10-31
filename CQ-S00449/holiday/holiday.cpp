#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5005,MAXN=9223372036854775807;
ll n,m,f[M],dp[M][M],k,val[M],dis[M],h[M],cnt,ans=-1;
bool vis[M],b[M];
priority_queue<pair<int,int>,vector<pair<int,int> > > q;
struct node
{
	ll to,next,w=1;
}e[500005];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=h[u];
	h[u]=cnt;
}
void dij(ll s)
{
	for(int i=1;i<=n;i++)
	dis[i]=INT_MAX;
	dis[1]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		ll x=q.top().second,d=q.top().first;
		q.pop();
		if(vis[x])
		continue;
		vis[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].w)
			{
				dis[y]=dis[x]+e[i].w;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
void dfs(ll num,ll sum,ll x,ll t)
{	
	if(num>=4)
	{
		if(x==1)
		{
			if(ans<=sum)
			ans=sum;
		}
		else
		{
			if(dis[x]<=k+1)
			{
				if(ans<=sum)
				ans=sum;
				return;
			}
		}
		return;
	}
	if(t>=k)
	{
		for(int i=h[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if(!b[y]&&y!=1)
			{
				b[y]=1;
				dfs(num+1,sum+val[y],y,0);
				b[y]=0;
			}
		}
		return;
	}
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(!b[y]&&y!=1)
		{
			b[y]=1;
			dfs(num+1,sum+val[y],y,0);
			b[y]=0;
		}
		dfs(num,sum,y,t+1);
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	cin>>val[i];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dij(1);
	dfs(0,0,1,0);
	cout<<ans;
	return 0;
}
