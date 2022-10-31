#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace pokopoko
{
const int N=2e5+5;
int n,m,q;
ll c[N];
vector<int> v[N];
struct node{int x,y;}a[N];
namespace sub1
{
	const int N=2005;
	const ll inf=1e18;
	int dep[N],p[N],id[N];
	ll f[N],g[N],ans[N];
	vector<int> qr[N];
	void dfs(int x,int fa)
	{
		p[x]=fa;dep[x]=dep[fa]+1;
		for(auto y:v[x])if(y!=fa)dfs(y,x);
	}
	int main()
	{
		for(int i=1;i<=m;i++)qr[a[i].y].push_back(i);
		for(int i=1;i<=n;i++)
		{
			dfs(i,0);f[0]=g[0]=inf;
			for(int j=1;j<=n;j++)id[j]=j,g[j]=inf;
			sort(id+1,id+n+1,[&](int x,int y){return dep[x]<dep[y];});
			for(int j=1;j<=n;j++)
			{
				int x=id[j];
				if(x==i){f[x]=c[x];continue;}
				if(q==2)f[x]=min(f[p[x]],f[p[p[x]]])+c[x];
				if(q==3)
				{
					f[x]=min({f[p[x]],f[p[p[x]]],f[p[p[p[x]]]],g[p[p[x]]]})+c[x];
					g[p[x]]=min(g[p[x]],f[x]);
				}
			}
			for(auto j:qr[i])ans[j]=f[a[j].x];
		}
		for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
		return 0;
	}
}
namespace sub2
{
	ll f[N];
	int lg[N],dep[N],p[N][21];
	void dfs(int x,int fa)
	{
		dep[x]=dep[fa]+1;f[x]=f[fa]+c[x];p[x][0]=fa;
		for(int i=1;p[x][i-1];i++)p[x][i]=p[p[x][i-1]][i-1];
		for(auto y:v[x])if(y!=fa)dfs(y,x);
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y])swap(x,y);
		while(dep[x]>dep[y])x=p[x][lg[dep[x]-dep[y]]];
		if(x==y)return x;
		for(int i=lg[dep[x]];i>=0;i--)
			if(p[x][i]!=p[y][i])x=p[x][i],y=p[y][i];
		return p[x][0];
	}
	ll dis(int x,int y)
	{
		int lc=lca(x,y);
		return f[x]+f[y]-2*f[lc]+c[lc];
	}
	int main()
	{
		int x,y;
		dfs(1,0);
		for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
		for(int i=1;i<=m;i++)x=a[i].x,y=a[i].y,printf("%lld\n",dis(x,y));
		return 0;
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int x,y;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<n;i++)scanf("%d %d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=1;i<=m;i++)scanf("%d %d",&a[i].x,&a[i].y);
	if(q==1)sub2::main();
	else if(n<=2000&&m<=2000)sub1::main();
	return 0;
}
};
int main(){pokopoko::main();return 0;}
