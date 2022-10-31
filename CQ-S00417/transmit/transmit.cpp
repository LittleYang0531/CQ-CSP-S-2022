#include<bits/stdc++.h>
using namespace std;
int n,d,k;
long long dis[1000000];
long long ad[1000000],ans,tot,bd[1000000],btot,f[1000000];
int dfn[1000000],fa[1000000];
struct edg
{
	int nxt,to;
}e[1000000];
int head[1000000],cnt;
void addd(int u,int v)
{
	e[++cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}
bool mark[1000000];
void dfs(int u,int step)
{
	dfn[u]=step;mark[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(mark[v])continue;
		fa[v]=u;
		dfs(v,step+1);
	}
}
deque<long long> q;
void dp()
{
	ans=0;
	while(!q.empty())q.pop_front();
	memset(f,0,sizeof(f));
	for(int i=1;i<=tot;i++)
	{
		if(i==1)
		{
			q.push_front(i);
			f[i]+=ad[i];
			continue;
		}
		if(!q.empty() and i-q.back()>k)q.pop_back();
		f[i]=f[q.back()]+ad[i];
		while(!q.empty() and f[i]<=f[q.front()])q.pop_front();
		q.push_front(i);
	}
}
void getlca(int u,int v)
{
	tot=0;btot=0;
	if(dfn[u]<dfn[v])swap(u,v);
	ad[++tot]=dis[u];
	while(dfn[u]>dfn[v])
	{
		u=fa[u];
		ad[++tot]=dis[u];
	}
	bd[++btot]=dis[v];
	while(u!=v)
	{
		u=fa[u];
		v=fa[v];
		ad[++tot]=dis[u];
		bd[++btot]=dis[v];
	}
	for(int i=btot-1;i>=1;i--)
	{
		ad[++tot]=bd[i];
	}
	dp();
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>dis[i];
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		addd(u,v);
		addd(v,u);
	}
	dfs(1,0);
	while(d--)
	{
		int u,v;
		cin>>u>>v;
		getlca(u,v);
		cout<<f[tot]<<endl;
	}
	return 0;
}
/*


*/
