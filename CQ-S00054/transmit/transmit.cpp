#include<bits/stdc++.h>
using namespace std;
int n,q,k,h[200005],cnt,p[17][200005],dep[200005];
struct nn{
	int to,next;
}e[400005];
long long v[200005],sum[200005],ans;
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x,int prt)
{
	p[0][x]=prt;
	for(int i=1;i<=16;i++)p[i][x]=p[i-1][p[i-1][x]];
	if(k==1)sum[x]=sum[prt]+v[x];
	if(k==2)sum[x]=sum[p[1][x]]+v[x];
	if(k==3)sum[x]=sum[p[0][p[1][x]]]+v[x];
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==prt)continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int k=log2(dep[x]-dep[y]);
	for(int i=k;i>=0;i--)if(dep[x]-(1<<i)>=dep[y])x=p[i][x];
	if(x==y)return x;
	k=log2(dep[y]);
	for(int i=k;i>=0;i--)if(p[i][x]!=p[i][y])x=p[i][x],y=p[i][y];
	return p[0][x];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%lld",v+i);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int t=lca(x,y);
		if(k==1)printf("%lld\n",sum[x]+sum[y]-2*sum[t]+v[t]);
		if(k==2)
		{
			if((dep[x]-dep[t])%2==0&&(dep[y]-dep[t])%2==0)printf("%lld\n",min(sum[x]+sum[y]-2*sum[t]+v[t],sum[p[0][x]]+sum[p[0][y]]-2*sum[p[0][t]]+v[x]+v[y]));
			if((dep[x]-dep[t])%2==1&&(dep[y]-dep[t])%2==0)printf("%lld\n",min(sum[x]-sum[p[0][t]]+sum[y]-sum[t]+v[t],min(sum[p[0][x]]+sum[y]-2*sum[t]+v[t]+v[x],sum[x]+sum[p[0][y]]-2*sum[p[0][t]]+v[y])));
			if((dep[x]-dep[t])%2==0&&(dep[y]-dep[t])%2==1)printf("%lld\n",min(sum[y]-sum[p[0][t]]+sum[x]-sum[t]+v[t],min(sum[p[0][y]]+sum[x]-2*sum[t]+v[t]+v[y],sum[y]+sum[p[0][x]]-2*sum[p[0][t]]+v[x])));
			if((dep[x]-dep[t])%2==1&&(dep[y]-dep[t])%2==1)printf("%lld\n",min(sum[x]+sum[y]-2*sum[p[0][t]],min(sum[p[0][x]]+sum[p[0][y]]-2*sum[t]+v[t]+v[x]+v[y],min(sum[p[0][x]]-sum[t]+v[t]+sum[y]-sum[p[0][t]],sum[p[0][y]]-sum[t]+v[t]-sum[x]-sum[p[0][t]]))));
		}
		if(k==3)printf("%lld\n",sum[x]+sum[y]-2*sum[t]+v[t]);
	}
	return 0;
}
