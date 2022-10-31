#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1) 
#define MOD (1000000007)
#define MAXN (200005)
#define debug(x) cerr<<#x<<" = "<<x;
using namespace std;
void read(int &x)
{
	char ch=0;bool f=0;x=0;
	while(ch<'0'||ch>'9'){f|=!(ch^'-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
void read(ll &x)
{
	char ch=0;bool f=0;x=0;
	while(ch<'0'||ch>'9'){f|=!(ch^'-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
int n,q,k;
int cnt,tot;
int head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
int fa[MAXN],dep[MAXN],son[MAXN],siz[MAXN];
int dfn[MAXN],top[MAXN];
ll w[MAXN];
void add(int u,int v)
{
	++cnt;
	to[cnt]=v;
	nxt[cnt]=head[u],head[u]=cnt;
}
void dfs1(int u)
{
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v^fa[u])
		{
			fa[v]=u,dep[v]=dep[u]+1,w[v]+=w[u];
			dfs1(v);
			siz[u]+=siz[v],son[u]=siz[v]>siz[son[u]]?v:son[u];
		}
	}
}
void dfs2(int u,int st)
{
	dfn[u]=++tot,top[u]=st;
	if(son[u]) dfs2(son[u],st);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if((v^fa[u])&&(v^son[u]))
			dfs2(v,v);
	}
	return;
}
int LCA(int x,int y)
{
	while(top[x]^top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
void test2()
{
	while(q--)
	{
		int s,t;
		read(s),read(t);
		printf("%lld\n",w[s]+w[t]-w[LCA(s,t)]);
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n),read(q),read(k);
	for(int i=1;i<=n;i++)
		read(w[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u),read(v);
		add(u,v),add(v,u);
	}
	dfs1(1),dfs2(1,1);
	test2();
	return 0;
}
