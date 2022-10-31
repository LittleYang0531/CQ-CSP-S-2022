#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
#define md(a) a=(a%mod+mod)%mod
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
const int N=1005;
int G[N][N],t[N][N];
int n,m,Q;
void Rem(int x,int y){t[x][y]=0;}
void Del(int x){for(int i=1;i<=n;i++)t[i][x]=0;}
void Reb(int x,int y){t[x][y]=1;}
void Add(int x){for(int i=1;i<=n;i++)t[i][x]=G[i][x];}
namespace Tarjan
{
	vector<int>v[N],v2[N];
	map<pair<int,int>,bool>mp;
	int dfn[N],low[N],scc,ins[N],st[N],top;
	int sign,sz[N],rd[N],f[N],bl[N];
	void dfs(int x)
	{
		dfn[x]=low[x]=++sign,ins[x]=1,st[++top]=x;
		for(int y:v[x])
		{
			if(!dfn[y])dfs(y),low[x]=min(low[x],low[y]);
			else if(ins[y])low[x]=min(low[x],low[y]);
		}
		if(dfn[x]==low[x])
		{
			int t;scc++;
			do{t=st[top--],ins[t]=0,sz[scc]++,bl[t]=scc;}while(t!=x);
		}
	}
	void init()
	{
		mp.clear(),sign=scc=top=0;
		for(int i=1;i<=n;i++)v[i].clear(),v2[i].clear();
		for(int i=1;i<=n;i++)dfn[i]=low[i]=ins[i]=st[i]=0;
		for(int i=1;i<=n;i++)sz[i]=rd[i]=f[i]=bl[i]=0;
	}
	void tpsort()
	{
		queue<int>q;while(!q.empty())q.pop();
		for(int i=1;i<=scc;i++)if(!rd[i])q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			if(sz[x]>1)f[x]=1;
			for(int y:v2[x])
			{
				f[y]|=f[x];
				rd[y]--;if(!rd[y])q.push(y);
			}
		}
	}
	bool Fight()
	{
		init();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(t[i][j])v[i].push_back(j);
		for(int i=1;i<=n;i++)if(v[i].size()!=1)return false;
		for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
		for(int x=1;x<=n;x++)
		{
			for(int y:v[x])
			{
				int a=y,b=x,p=bl[y],q=bl[x];
				if(p==q||mp[{p,q}])continue;
				rd[q]++,v2[p].push_back(q),mp[{p,q}]=1;
			}
		}
		tpsort();
		for(int i=1;i<=scc;i++)if(!f[i])return false;
		return true;
	}
}
signed main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){int x,y;scanf("%d%d",&x,&y),G[x][y]=1,t[x][y]=1;}
	cin>>Q;
	while(Q--)
	{
		int op,x,y;scanf("%d%d",&op,&x);
		if(op==1)scanf("%d",&y),Rem(x,y);
		else if(op==2)Del(x);
		else if(op==3)scanf("%d",&y),Reb(x,y);
		else Add(x);
		if(Tarjan::Fight())puts("YES");
		else puts("NO");
	}
	return 0;
}
