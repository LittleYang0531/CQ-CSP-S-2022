#include <bits/stdc++.h>
using namespace std;
const int N=500005;
struct edge {int to,Next,id;}e[N],re[N],g[N];
int n,m,h[N],rh[N],cnt,q;
int sign,top,s[N],dfn[N],low[N],bl[N],num,sz[N];
int tot,hh[N],a[N],cd[N],rd[N];
bool v[N],Del[N],bj[N];
map<pair<int,int>,int>mp;
void Addedge(int x,int y,int id)
{
	e[++cnt]=(edge){y,h[x],id},h[x]=cnt;
	re[cnt]=(edge){x,rh[y],id},rh[y]=cnt;
}
void Addedge2(int x,int y) {g[++tot]=(edge){y,hh[x]},hh[x]=tot;}
void dfs(int x)
{
	dfn[x]=low[x]=++sign;
	s[++top]=x,v[x]=1;
	for(int i=h[x];i;i=e[i].Next)
	{
		if(Del[i]) continue;
		int y=e[i].to;
		if(!dfn[y])
		{
			dfs(y);
			low[x]=min(low[x],low[y]);
		}
		else if(v[y]) low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		int y;
		num++;
		do {y=s[top--],v[y]=0,bl[y]=num,sz[num]++;}while(y!=x);
	}
}
void topsort()
{
	queue<int>q;
	a[0]=0;
	for(int i=1;i<=num;i++)
		if(rd[i]==0) q.push(i);
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		a[++a[0]]=x;
		for(int i=hh[x];i;i=g[i].Next)
		{
			int y=g[i].to;
			if(--rd[y]==0) q.push(y);
		}
	}
	for(int i=1;i<=num;i++) bj[i]=0;
	for(int i=1;i<=num;i++)
	{
		int x=a[i];
		if(sz[x]>1) bj[x]=1;
		for(int j=hh[x];j;j=g[j].Next) bj[g[j].to]|=bj[x];
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		Addedge(x,y,i);
		mp[make_pair(x,y)]=i;
	}
	scanf("%d",&q);
	int op,x,y;
	while(q--)
	{
		scanf("%d %d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			Del[mp[make_pair(x,y)]]=1;
		}
		else if(op==3)
		{
			scanf("%d",&y);
			Del[mp[make_pair(x,y)]]=0;
		}
		else if(op==2)
		{
			for(int i=rh[x];i;i=re[i].Next) Del[re[i].id]=1;
		}
		else if(op==4)
		{
			for(int i=rh[x];i;i=re[i].Next) Del[re[i].id]=0;
		}
		for(int i=1;i<=n;i++) rd[i]=sz[i]=dfn[i]=low[i]=bl[i]=hh[i]=cd[i]=v[i]=0;
		sign=top=tot=num=0;
		for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
		for(int x=1;x<=n;x++)
			for(int i=h[x];i;i=e[i].Next)
			{
				if(Del[e[i].id]) continue;
				cd[x]++;
				int y=e[i].to;
				if(bl[x]!=bl[y]) Addedge2(bl[y],bl[x]),rd[bl[x]]++;
			}
		bool ok=1;
		for(int i=1;i<=n;i++) ok&=cd[i]==1;
		if(!ok) {puts("NO"); continue;}
		topsort();
		for(int i=1;i<=num;i++) ok&=bj[i];
		puts(ok?"YES":"NO");
	}
	return 0;
}
