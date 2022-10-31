/*
wonwon~ wonderhoy!
Wonderhoy!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(!isdigit(c))	f=(c=='-'?-1:f),c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const LL inf=1e15;
LL n,K,q;
namespace Brute
{
	LL a[2005];
	LL dis[2005];
	struct Edge{
		LL t,w;
		Edge(LL T=0,LL W=0){t=T,w=W;}
		inline bool operator < (Edge ano) const {return w>ano.w;}
	};
	vector<LL> E[2005];
	vector<Edge> G[2005];
	LL vis[2005],d[2005];
	void Dijkstra(LL s)
	{
		memset(dis,63,sizeof dis);
		priority_queue<Edge> Q;
		Q.push(Edge(s,0));
		dis[s]=0;
		while(!Q.empty())
		{
			Edge now=Q.top();
			Q.pop();
			LL u=now.t,dnow=now.w;
			if(dnow>dis[u])	continue;
			for(auto ed:G[u])
			{
				LL v=ed.t,w=ed.w;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					Q.push(Edge(v,dis[v]));
				}
			}
		}
	}
	void main()
	{
		for(LL i=1;i<=n;++i)	a[i]=read();
		for(LL i=1;i<n;++i)
		{
			LL u=read(),v=read();
			E[u].push_back(v);
			E[v].push_back(u);
		}
		LL edc=0;
		auto bfs=[&](LL s)
		{
			queue<LL> Q;
			memset(vis,0,sizeof vis);
			memset(d,0,sizeof d);
			Q.push(s);
			vis[s]=true;
			while(!Q.empty())
			{
				LL u=Q.front();
				Q.pop();
				if(d[u]==K)	continue;
				for(LL v:E[u])
				{
					if(vis[v])	continue;
					d[v]=d[u]+1;
					vis[v]=true;
					Q.push(v);
				}
			}
			for(LL i=1;i<=n;++i)	if((i^s) && vis[i])	G[s].push_back(Edge(i,a[i])),++edc;
		};
		for(LL i=1;i<=n;++i)	bfs(i);
		fprintf(stderr,"%lld\n",edc);
		while(q-->0)
		{
			LL s=read(),t=read();
			Dijkstra(s);
			write(a[s]+dis[t]),puts("");
		}
	}
}
struct Matrix{
	LL a[3][3];
	inline LL* operator [] (LL x){return a[x];}
	Matrix operator * (Matrix ano) const
	{
		Matrix ret;
		memset(ret.a,63,sizeof ret.a);
		for(LL i=0;i<K;++i)	for(LL k=0;k<K;++k)	for(LL j=0;j<K;++j)	ret[i][j]=min(ret[i][j],a[i][k]+ano[k][j]);
		return ret;
	}
}P[200005];
void build(LL id,LL c)
{
	if(K==3)
	{
		P[id][0][0]=P[id][1][0]=P[id][2][0]=c;
		P[id][0][1]=P[id][1][2]=0;
		P[id][0][2]=P[id][1][1]=P[id][2][1]=P[id][2][2]=inf;
	}
	else if(K==2)
	{
		P[id][0][0]=P[id][1][0]=c;
		P[id][0][1]=P[id][1][1]=inf;
	}
	else	P[id][0][0]=c;
}
vector<LL> G[200005];
LL son[200005],siz[200005],fa[200005],dep[200005];
LL F[18][200005];
void dfs1(LL u,LL f)
{
	F[0][u]=fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	for(auto v:G[u])
	{
		if(v==f)	continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])	son[u]=v;
	}
}
LL dfn[200005],top[200005],sjc,rev[200005];
void dfs2(LL u,LL t)
{
	rev[dfn[u]=++sjc]=u;
	top[u]=t;
	if(son[u])	dfs2(son[u],t);
	for(auto v:G[u])
	{
		if(v==fa[u] || v==son[u])	continue;
		dfs2(v,v);
	}
}
LL LCA(LL u,LL v)
{
	while(top[u]^top[v])
	{
		if(dep[top[u]]<dep[top[v]])	swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
LL jmp(LL u,LL d)
{
	for(LL i=17;~i;--i)	if((d>>i)&1)	u=F[i][u];
	return u;
}
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define Mm LL mid=(l+r)>>1
Matrix pre[200005],suf[200005];
void build(LL l,LL r,LL now)
{
	if(l==r)
	{
		pre[now]=suf[now]=P[rev[l]];
		return ;
	}
	Mm;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
	pre[now]=pre[lc(now)]*pre[rc(now)]; // shang dao xia
	suf[now]=suf[rc(now)]*suf[lc(now)]; // xia dao shang
}
Matrix query(LL l,LL r,LL now,LL x,LL y,bool xd)
{
	if(x<=l && r<=y)	return xd?suf[now]:pre[now];
	Mm;
	if(x<=mid && mid<y)	return xd?query(mid+1,r,rc(now),x,y,xd)*query(l,mid,lc(now),x,y,xd):query(l,mid,lc(now),x,y,xd)*query(mid+1,r,rc(now),x,y,xd);
	if(x<=mid)	return query(l,mid,lc(now),x,y,xd);
	return query(mid+1,r,rc(now),x,y,xd);
}
Matrix getBase(LL id)
{
	Matrix ret;
	memset(ret.a,0,sizeof ret.a);
	ret[0][0]=P[id][0][0],ret[0][1]=ret[0][2]=inf;
	return ret;
}
void queryChain(LL u,LL v,bool xd,Matrix &ans)
{
	if(dep[u]<dep[v])	swap(u,v);
	vector<Matrix> Seq;
	while(top[u]^top[v])	Seq.push_back(query(1,n,1,dfn[top[u]],dfn[u],xd)),u=fa[top[u]];
	Seq.push_back(query(1,n,1,dfn[v],dfn[u],xd));
	if(!xd)	reverse(Seq.begin(),Seq.end());
	for(Matrix c:Seq)	ans=ans*c;
}
LL dc[200005];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),K=read();
	if(n<=200 || (n<=2000 && K!=1))
	{
		Brute::main();
		return 0;
	}
	for(LL i=1;i<=n;++i)	build(i,read());
	for(LL i=1;i<n;++i)
	{
		LL u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,0),dfs2(1,1);
	for(LL i=1;i<=n;++i)	++dc[dep[i]];
	LL pedc=0;
	for(LL i=1;i<=n;++i)	pedc+=dc[i]*dc[i-1]*dc[i+1];
	if(pedc<=10000 && K!=1)
	{
		Brute::main();
		return 0;
	}
	for(LL i=1;i<=17;++i)	for(LL j=1;j<=n;++j)	F[i][j]=F[i-1][F[i-1][j]];
	build(1,n,1);
	while(q-->0)
	{
		LL u=read(),v=read();
		if(u==v)
		{
			puts("0");
			continue;
		}
		LL lca=LCA(u,v);
		if(u==lca)
		{
			Matrix ans=getBase(u);
			LL d=dep[v]-dep[u]-1;
			LL l=jmp(v,d),r=v;
			queryChain(l,r,0,ans);
			write(ans[0][0]),puts("");
		}
		else if(v==lca)
		{
			Matrix ans=getBase(u);
			queryChain(v,u,1,ans);
			write(ans[0][0]),puts("");
		}
		else
		{
			Matrix ans=getBase(u);
			u=fa[u];
			queryChain(u,lca,1,ans);
			LL d=dep[v]-dep[lca]-1;
			LL l=jmp(v,d),r=v;
			queryChain(l,r,0,ans);
			write(ans[0][0]),puts("");
		}
	}
	return 0;
}
