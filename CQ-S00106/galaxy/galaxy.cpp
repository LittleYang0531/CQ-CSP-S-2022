#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1) 
#define MOD (1000000007)
#define MAXN (500005)
#define MAXM (500005)
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
int cnt;
int head[MAXN],to[MAXM],nxt[MAXM],ot[MAXN],in[MAXN];
void add(int u,int v)
{
	++cnt;
	to[cnt]=v;
	nxt[cnt]=head[u],head[u]=cnt;
}
vector<int> G[MAXN];
int n,m,q,sz,tot;
int dfn[MAXN],low[MAXN];
bool flg[MAXN],des[3005][3005],FF;
stack<int> St;
void dfs(int u,int fa)
{
	dfn[u]=++tot,low[u]=dfn[u];
	St.push(u);
	int fff=0;
	for(const auto v:G[u])
	{
		if(des[u][v]) continue;
		++fff;
		if(!(v^fa)) continue;
		if(dfn[v]) low[u]=min(low[u],dfn[v]);
		else dfs(v,u);
	} 
	if(!(low[u]^dfn[u]))
	{
		int tmp=0;
		while(!St.empty()) ++tmp,St.pop();
		sz=min(sz,tmp);
	}
	if(fff^1) FF=1;
}
void test1()
{
	read(q); 
	for(int i=1;i<=q;i++)
	{
		int t,u,v;
		read(t);
		if(!(t^1))
		{
			read(u),read(v);
			if(!des[u][v]) --ot[u],--in[v],des[u][v]=1;
		}
		if(!(t^2))
		{
			read(u);
			for(int j=head[u];j;j=nxt[j])
			{
				int v=to[j];
				if(!des[v][u]) --ot[v],des[v][u]=1;
			}
			flg[u]=1;
		}
		if(!(t^3))
		{
			read(u),read(v);
			if(des[u][v]) ++ot[u],++in[v],des[u][v]=0;
		}
		if(!(t^4))
		{
			read(u);
			for(int j=head[u];j;j=nxt[j])
			{
				int v=to[j];
				if(des[v][u]) ++ot[v],des[v][u]=0;
			}
			flg[u]=0;
		}
		bool Flg=1;tot=0,sz=INT_MAX,FF=0;
		memset(dfn,0,sizeof(dfn));
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,0);
			if((!(sz^1))||FF)
			{
				Flg=0;
				break;
			}
		}
		if(Flg) printf("YES\n");
		else printf("NO\n");
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		G[x].push_back(y);
		add(y,x);
		++ot[x],++in[y];
	}
	if(n<=1000&&m<=1000) test1();
	return 0;
}
