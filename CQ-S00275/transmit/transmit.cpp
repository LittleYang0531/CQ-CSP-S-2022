#include<bits/stdc++.h> 
using namespace std;
#define rt register
int n,m,k,f,t,root[500010],idx,vis[500010],ans,a[200010],depth[200010],fa[500010][31],x,y;
long long dis[200010];
struct Scarlet{
	int to,pre;
}mp[500010];
inline int read()
{
	int platinum=0,lucadio=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') lucadio=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		platinum=(platinum<<1)+(platinum<<3)+(ch^48);
		ch=getchar();
	}
	return platinum*lucadio;
}
inline void add(int f,int t)
{
	mp[++idx].to=t;
	mp[idx].pre=root[f];
	root[f]=idx;
}
inline void dfs(int p,int father)
{
	for(rt int i=root[p];i;i=mp[i].pre)
	{
		int to=mp[i].to;
		if(to==father) continue;
		depth[to]=depth[p]+1;
		fa[to][0]=p;
		dis[to]=dis[p]+a[to];
		dfs(to,p);
	}
}
inline int lca(int x,int y)
{
	if(depth[x]<depth[y]) swap(x,y);
	for(rt int i=25;i>=0;i--)
	{
		if(depth[fa[x][i]]>=depth[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(rt int i=25;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);	
	n=read(),m=read(),k=read();
	for(rt int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(rt int i=1;i<=n-1;i++)
	{
		f=read(),t=read();
		add(f,t);
		add(t,f);
	}
	depth[1]=1;
	dis[1]=a[1];
	dfs(1,0);
	for(rt int i=1;(1<<i)<=n;i++)
	{
		for(rt int j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	for(rt int i=1;i<=m;i++)
	{
		x=read(),y=read();
		int anc=lca(x,y);
		if(k==1)
		{
			printf("%lld\n",dis[x]+dis[y]-2*dis[anc]+a[anc]);
			continue;
		} 
		else
		{
			if(depth[x]-depth[anc]+depth[y]-depth[anc]<=k)
			{
				printf("%lld\n",(long long)a[x]+a[y]);
				continue;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
