#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[200005];
int f[200005];
int head[200005],nex[400005],ver[400005],tot;
void add(int u,int v){nex[++tot]=head[u];ver[tot]=v;head[u]=tot;}

int n,q,k,u,v;
void dfs(int x,int y,int z)
{
	if(x==v)
	{
		printf("%lld\n",f[x]);
		return;
	}
	for(int i=head[x];i;i=nex[i])
	if(ver[i]!=y)
	{
		f[ver[i]]=f[x]+t[ver[i]];
		if(k>=2&&y)
		f[ver[i]]=min(f[ver[i]],f[y]+t[ver[i]]);
		if(k>=3&&z)
		f[ver[i]]=min(f[ver[i]],f[z]+t[ver[i]]);
		dfs(ver[i],x,y);
	}
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++)
	scanf("%lld",&t[i]);
	for(int i=1;i<n;i++)
	scanf("%lld%lld",&u,&v),add(u,v),add(v,u);
	while(q--)
	{
		scanf("%lld%lld",&u,&v);
		f[u]=t[u];
		dfs(u,0,0);
	}
	return 0;
}
