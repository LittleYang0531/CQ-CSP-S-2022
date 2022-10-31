//sto mzh2022 orz bless me AC
#include<bits/stdc++.h>
using namespace std;
struct node{
	int nxt,to,dis;
}e[4000005];
int n,m,k,ne,u,v,sz,l,r;
int a[2005],h[2005],dep[2005];
bool vis[2005];
queue<int> q;
long long ans,dis[2005][2005];
priority_queue<pair<long long,int> > qu;
vector<int> ve[2005];
inline int read()
{
	int x(0);char ch(getchar());
	while(ch<48||ch>57) ch=getchar();
	while(ch>=48&&ch<=57) x=x*10+(ch^48),ch=getchar();
	return x;
}
void add(int x,int y,int z)
{
	e[++ne].nxt=h[x];
	e[ne].to=y,e[ne].dis=z,h[x]=ne;
}
void bfs(int x)
{
	memset(dep,0,sizeof(dep));
	q.push(x),dep[x]=1;
	while(!q.empty())
	{
		u=q.front();q.pop();
		for(int i=h[u];i;i=e[i].nxt)
		{
			v=e[i].to;
			if(!dep[v])
			{
				dep[v]=dep[u]+1;
				if(dep[v]<=k+1) 
				{
					if(dep[v]!=2)ve[x].push_back(v);
					q.push(v);
				}
			}
		}
	}
}
void dij(int x)
{
	memset(vis,0,sizeof(vis));
	qu.push(make_pair(0,x));dis[x][x]=0;
	while(!qu.empty())
	{
		u=qu.top().second;qu.pop();
		if(vis[u]) continue;vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			v=e[i].to;
			if(dis[x][v]>dis[x][u]+e[i].dis)
			{
				dis[x][v]=dis[x][u]+e[i].dis;
				qu.push(make_pair(-dis[x][v],v));
			}
		}
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++) 
	{
		u=read(),v=read();
		add(u,v,a[v]),add(v,u,a[u]);
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=1;i<=n;i++)
	{
		sz=ve[i].size();
		for(int j=0;j<sz;j++)
			add(i,ve[i][j],a[ve[i][j]]);
	}
	memset(dis,0x3f,sizeof(dis));
	while(m--)
	{
		l=read(),r=read();
		if(dis[l][r]==dis[0][0]) dij(l);
		ans=dis[l][r]+a[l];
		printf("%lld\n",ans);
	}
	return 0;
}

