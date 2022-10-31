#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+5,M=21;

int n,m,k,idx;
int head[N],f[N][M],depth[N],val[N];
ll cost[N][M];
struct edge
{
	int fr,to,ne;
}e[2*N];

void add(int x,int y)
{
	e[++idx].fr=x;
	e[idx].to=y;
	e[idx].ne=head[x];
	head[x]=idx;
}

void dfs(int u,int fa)
{
	depth[u]=depth[fa]+1,f[u][0]=fa;
	for(int j=1;j<M;j++)
	{
		f[u][j]=f[f[u][j-1]][j-1],cost[u][j]=cost[u][j-1]+cost[f[u][j-1]][j-1];
		if(f[u][j]==0)break;
	}
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].to;
		if(v!=fa)
		{
			cost[v][0]=val[u];
			dfs(v,u);
		}
	}
}

ll getlca(int u,int v)
{
	if(depth[u]<depth[v])swap(u,v);
	ll ans=val[u]+val[v];
	for(int j=20;j>=0;j--)
		if(depth[f[u][j]]>=depth[v])
			ans+=cost[u][j],u=f[u][j];
	if(u==v)return ans-val[v];
	for(int j=20;j>=0;j--)
		if(f[u][j]!=f[v][j])
			ans+=cost[u][j]+cost[v][j];
	u=f[u][0];
	ans+=val[u];
	return ans;
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",getlca(u,v));
	}
	return 0;
}
