#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q,k;
int v[N];
int h[N],e[2*N],ne[2*N],idx;
int dep[N],dp[N][20],f[N][20];
int sum[N];
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dfs(int u,int fa)
{
	sum[u]=sum[fa]+v[u];
	dep[u]=dep[fa]+1,f[u][0]=fa;
	for(int i=1;i<20;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=e[i];
		if(v==fa)continue;
		dfs(v,u);
	}
}
int lca(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	for(int i=19;i>=0;i--)
		if(dep[f[a][i]]>=dep[b])
			a=f[a][i];
	if(a==b)return a;
	for(int i=19;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&v[i]);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%lld%lld",&a,&b);
		add(a,b),add(b,a);
	}
	if(k==1)
	{
		dfs(1,0);
		int u,v;
		for(int i=1;i<=q;i++)
		{
			scanf("%lld%lld",&u,&v);
			if(dep[u]>dep[v])swap(u,v);
			int l=lca(u,v);
			printf("%lld\n",sum[u]+sum[v]-sum[l]-sum[f[l][0]]);
		}
	}
	return 0;
}
