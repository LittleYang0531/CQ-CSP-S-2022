#include<bits/stdc++.h>
typedef long long ll;
#define int ll
using namespace std;
const int N=500005;
int n,qus,k;
namespace Chain{
	int h[N],cnt;
	struct Edge{int next,to;}e[N<<1];
	void AddEdge(int c,int d){e[++cnt]=(Edge){h[c],d}; h[c]=cnt;}
}
using namespace Chain;
int v[N];
namespace ts{
	int top[N],prt[N],siz[N],sum[N],dep[N],son[N];
	void dfs(int r,int fa,int d,int s)
	{
		siz[r]=1; prt[r]=fa; dep[r]=d; sum[r]=s;
		for(int i=h[r];i;i=e[i].next)
		{
			int y=e[i].to;
			if(y==fa) continue;
			dfs(y,r,d+1,s+v[y]);
			siz[r]+=siz[y];
			if(!son[r] || siz[son[r]]<siz[y]) son[r]=y;
		}
	}
	void pre(int r,int tp)
	{
		top[r]=tp;
		if(son[r]) pre(son[r],tp);
		for(int i=h[r];i;i=e[i].next)
		{
			int y=e[i].to;
			if(y==prt[r] || y==son[r]) continue;
			pre(y,y);
		}
	}
	int lca(int x,int y)
	{
		int f1=top[x],f2=top[y];
		while(f1!=f2)
		{
			if(dep[f1]<dep[f2]) swap(f1,f2),swap(x,y);
			x=prt[f1],f1=top[x];
		}
		return dep[x]>dep[y]?y:x;
	}
}
using namespace ts;
namespace subk1{
	void solve()
	{
		int l,r;
		while(qus--)
		{
			scanf("%lld %lld",&l,&r);
			int lc=lca(l,r);
			printf("%lld\n",sum[l]+sum[r]-2*sum[lc]+v[lc]);
		}
	}
}
namespace subsmall{
	int f[200005][4];
	bitset<N> vst;
	queue<int> q;
	void bfs(int st)
	{
		vst.reset();
		q.push(st);
		while(q.size())
		{
			int r=q.front(); q.pop();
			if(vst[r]) continue;
			vst[r]=true;
			for(int i=h[r];i;i=e[i].next)
			{
				int y=e[i].to;
				f[y][0]=min(f[y][0],min(f[r][0],min(f[r][1],f[r][2]))+v[y]);
				f[y][1]=min(f[y][1],f[r][0]);
				if(k==3) f[y][2]=min(f[y][2],f[r][1]);
				q.push(y);
			}
		}
	}
	void solve()
	{
		int l,r;
		while(qus--)
		{
			memset(f,0x3f,sizeof(f));
			scanf("%lld %lld",&l,&r);
			f[l][0]=v[l];
			for(int tm=1;tm<=10;++tm) bfs(l);
			printf("%lld\n",f[r][0]);
		}
	}
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld %lld %lld",&n,&qus,&k);
	for(int i=1;i<=n;i++) scanf("%lld",v+i);
	for(int i=1,x,y;i<n;i++) scanf("%lld %lld",&x,&y),AddEdge(x,y),AddEdge(y,x);
	dfs(1,-1,0,v[1]),pre(1,1);
	if(k==1) subk1::solve();
	else subsmall::solve();
	return 0;
}
