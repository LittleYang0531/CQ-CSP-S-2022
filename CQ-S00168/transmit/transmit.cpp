#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=2e5+5,M=N*2,K=20;
const LL inf=0x3f3f3f3f3f3f3f3f;

int n,k,q;
LL w[N];
int la[N],ne[M],en[M],idx;
int fa[N][K],dep[N];
LL dis[N];
LL x[N],y[N],cx,cy;
LL f[N][5];

void add(int a,int b)
{
	idx++;
	ne[idx]=la[a];
	la[a]=idx;
	en[idx]=b;
}

void dfs(int u)
{
	for(int i=la[u];i;i=ne[i])
	{
		int v=en[i];
		if(v!=fa[u][0])
		{
			fa[v][0]=u;
			for(int j=1;j<K;j++)fa[v][j]=fa[fa[v][j-1]][j-1];
			dep[v]=dep[u]+1;
			dis[v]=dis[u]+w[v];
			dfs(v);
		}
	}
}

int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	for(int i=K-1;i>=0;i--)
		if(dep[fa[v][i]]>=dep[u])
			v=fa[v][i];
	if(u==v)return u;
	for(int i=K-1;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

LL query(int u,int v)
{
	int w=lca(u,v),res=0;
	res=dis[u]+dis[v]-dis[w];
	if(fa[w][0])res-=dis[fa[w][0]];
	return res;
}

LL dfs1(int u,int p,int t)
{
	if(p==t)return w[u];
	LL res=w[u];
	for(int i=la[u];i;i=ne[i])res=min(res,dfs1(en[i],p+1,t));
	return res;
}

LL get(int u,int v)
{
	cx=cy=0;
	if(dep[u]>dep[v])swap(u,v);
	while(dep[v]>dep[u])
	{
		x[++cx]=v;
		v=fa[v][0];
	}
	while(u!=v)
	{
		x[++cx]=v;
		y[++cy]=u;
		v=fa[v][0];
		u=fa[u][0];
	}
	x[++cx]=v;
	for(int i=cy;i>0;i--)
		x[++cx]=y[i];
	
	memset(f,0x3f,sizeof f);
	f[1][1]=f[1][2]=f[1][3]=w[x[1]];
	for(int i=2;i<=cx;i++)
	{
		int a=dfs1(x[i],1,2),b=dfs1(x[i],1,3);
		for(int j=i-1;j>0&&i-j<=k;j--)
			f[i][k]=min(f[i][k],f[j][i-j]+w[x[i]]);
		if(k==2)
		{
			f[i][1]=min(f[i][2],f[i-1][2]+a);
		}
		else
		{
			f[i][2]=min(f[i][3],f[i-1][2]+a);
			f[i][1]=f[i][2];
			if(i>2)
			{
				f[i][2]=min(f[i][2],f[i-2][3]+a);
				f[i][1]=min(f[i][1],f[i-1][3]+b);
			}
		}
	}
			
	return f[cx][k];
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dep[1]=1;
	dis[1]=w[1];
	dfs(1);
	if(k==1)
		while(q--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(a,b));
		}
	else
		while(q--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",get(a,b));
		}
	return 0;
}
