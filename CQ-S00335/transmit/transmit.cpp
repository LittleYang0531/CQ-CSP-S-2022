#include<bits/stdc++.h>
using namespace std;
int n,q,ll;
int v[200005];
struct node
{
	int tar,nxt;
	bool flg;
}arr[400005];
int fst[200005],cnt;
int vis[2005];
void adds(int x,int y)
{
	arr[++cnt].tar=y,arr[cnt].nxt=fst[x],fst[x]=cnt;
}
void addss(int x,int y)
{
	arr[++cnt].tar=y,arr[cnt].nxt=fst[x],fst[x]=cnt,arr[cnt].flg=1;
}
void dfs(int x,int dep,int st)
{
	vis[x]=1;
	for(int i=fst[x];i;i=arr[i].nxt)
	{
		int j=arr[i].tar;
		if(arr[i].flg) continue;
		if(vis[j]) continue;
		if(dep<ll)
		{
			addss(st,j);
			dfs(j,dep+1,st);
		}
	}
}
long long dis[2005];
queue<int> p,qq;
long long bfs(int st,int e)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	while(!p.empty()) p.pop(),qq.pop();
	p.push(st),qq.push(v[st]);
	dis[st]=v[st];
	while(!p.empty())
	{
		int x=p.front(),y=qq.front();
		vis[x]=0;
		p.pop(),qq.pop();
		for(int i=fst[x];i;i=arr[i].nxt)
		{
			int j=arr[i].tar;
			if(1ll*v[j]+dis[x]<dis[j])
			{
				dis[j]=1ll*v[j]+dis[x];
				if(vis[j]) continue;
				vis[j]=1;
				p.push(j);
				qq.push(y+v[j]);
			}
		}
	}
	return dis[e];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&ll);
	for(int i=1;i<=n;++i) scanf("%d",&v[i]);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adds(u,v);
		adds(v,u);
	}
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,0,i);
	}
	while(q--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		printf("%lld\n",bfs(s,t));
	}
	return 0;
}

