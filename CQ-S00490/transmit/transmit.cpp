#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,k,lg[N];
ll v[N];
struct EDGE{
	int to,nt,w;
}edge[N<<1];
int cnt,head[N];
void add(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].nt=head[u];
	head[u]=cnt;
}

int fa[N],dep[N];
int ft[N][18];
ll g[N][18];
void dfs(int u,int f)
{
	fa[u]=f;
	dep[u]=dep[f]+1;
	ft[u][0]=f;
	g[u][0]=v[f];
	for(int i=1;i<=lg[dep[u]];i++)
	{
		ft[u][i]=ft[ft[u][i-1]][i-1];
		g[u][i]=g[u][i-1]+g[ft[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=edge[i].nt)
		if(edge[i].to!=f) dfs(edge[i].to,u);
}

vector<int> vec1,vec2;
ll dp[N];
void LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	vec1.push_back(x);
	while(dep[x]!=dep[y])
	{
		x=fa[x];
		vec1.push_back(x);
	}
	if(x==y) return;
	vec2.push_back(y);
	while(fa[x]!=fa[y])
	{
		x=fa[x];
		y=fa[y];
		vec1.push_back(x);
		vec2.push_back(y);
	}
	vec1.push_back(fa[x]);
}
void solve1()
{
	for(int i=0;i<=n;i++)
		dp[i]=1e17;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		LCA(x,y);
		for(int i=vec2.size()-1;i>=0;i--)
			vec1.push_back(vec2[i]);
		dp[0]=v[vec1[0]];
		for(int i=0;i<vec1.size();i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(i+j>=vec1.size()) break;
				dp[i+j]=min(dp[i+j],dp[i]+v[vec1[i+j]]);
			}
		}
		printf("%lld\n",dp[vec1.size()-1]);
		for(int i=0;i<vec1.size();i++)
			dp[i]=1e17;
		vec1.clear();
		vec2.clear();
	}
}

ll LCA2(int x,int y)
{
	ll vl,vr,sum=0;
	if(dep[x]<dep[y]) swap(x,y);
	vl=v[x],vr=v[y];
	while(dep[x]!=dep[y])
	{
		sum+=g[x][lg[dep[x]-dep[y]]];
		x=ft[x][lg[dep[x]-dep[y]]];
	}
	if(x==y) return sum+vl;
	for(int i=lg[dep[x]];i>=0;i--)
		if(ft[x][i]!=ft[y][i])
		{
			sum+=g[x][i]+g[y][i];
			x=ft[x][i];
			y=ft[y][i];
		}
	sum+=vl+vr+v[fa[x]];
	return sum;
}

void solve2()
{
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",LCA2(x,y));
	}
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	dfs(1,0);
	if(n<=2000||(n<=2e5&&k!=1))	solve1();
	else solve2();
	return 0;
}
