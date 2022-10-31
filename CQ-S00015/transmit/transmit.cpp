//POYE's Code
#include<cstdio>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
int n,Q,k,cnt,h[200005],p[200005],dis[200005];
ll ans,val[200005];
bool vis[200005];
struct node {int next,to;} a[400005];
inline void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}

inline bfs(int s)
{
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=-1;
	dis[s]=0;
	q.push(s);
	while(q.empty())
	{
		int x=q.front();q.pop();
		for(int i=h[x];i;i=a[i].next)
		{
			int y=a[i].to;
			if(dis[y]==-1)
			{
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
}

inline void dfs(int x,int lim)
{
	if(x==lim)
	{
		ll sum=0;
		for(int i=2;i<=lim;i++)
		{
			bfs(p[i-1]);
			if(dis[p[i]]>k) return;
		}
		for(int i=1;i<=lim;i++) sum+=val[p[i]];
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			p[x]=i;
			dfs(x+1,lim);
			vis[i]=0;
		}
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;i++) scanf("%lld",val+i);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int o=1;o<=Q;o++)
	{
		ans=1e18;
		int s,t;
		scanf("%d%d",&s,&t);
		for(int i=2;i<=n;i++)
		{
			vis[s]=vis[t]=1;
			p[i-1]=0;
			p[1]=s,p[i]=t;
			dfs(2,i);
		}
		vis[s]=vis[t]=0;
		printf("%lld\n",ans);
	}

	return 0;
}
