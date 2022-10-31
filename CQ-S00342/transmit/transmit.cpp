#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ppp;
const int N=2005;
int n,Q,k,u,v,cnt,dep[N],fa[N];
ll val[N],f[N];
int q[N],p[N];
int nxt[N<<1],head[N],to[N<<1];
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dfs(int x,int f)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==f) continue;
		dep[y]=dep[x]+1;fa[y]=x;
		dfs(y,x);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]!=dep[v]) u=fa[u];
	while(u!=v) u=fa[u],v=fa[v];
	return u;
}
bool pppp;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	//cout<<(&pppp-&ppp)/1024.0/1024.0;
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,0);
	while(Q--)
	{
		scanf("%d%d",&u,&v);
		
		int w=lca(u,v),cnt=0,cnt2=0;//cout<<w<<"\n";
		for(int x=u;x!=w;x=fa[x])
		q[++cnt]=x;
		for(int x=v;x!=w;x=fa[x])
		p[++cnt2]=x;
		q[++cnt]=w;int m=cnt+cnt2;//cout<<cnt<<" "<<cnt2<<"\n";
		for(int i=cnt2;i>=1;i--) q[cnt+(cnt2-i+1)]=p[i];
		
		if(k==1)
		{
			ll ans=0;
			for(int i=1;i<=m;i++)
			ans+=val[q[i]];
			printf("%lld\n",ans);
			continue;
		}
		//for(int i=1;i<=m;i++) printf("%d ",q[i]);printf("\n");
		
		
		memset(f,0x3f,sizeof f);
		f[1]=val[q[1]];//cout<<m<<"\n";
		for(int i=2;i<=m;i++)
		{
			for(int j=max(1,i-k);j<i;j++)
			f[i]=min(f[j]+val[q[i]],f[i]);//,cout<<j<<" "<<f[j]+val[q[i]]<<"\n";
			//cout<<f[i]<<"\n";
		}
		
		printf("%lld\n",f[m]);
		
	}
	return 0;
}

/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2 
*/
