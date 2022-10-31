#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ppp;
const int N=2502,M=10005;
bool vis[N],vi[N];
int n,m,k,u,v,cnt,dis[N];
ll s[2505],f[N][5],ans;
int nxt[M<<1],head[N],to[M<<1];
vector<int> e[N];
struct node{
	int d,p;
};
bool operator <(const node &x,const node &y)
{
	return x.d>y.d;
}
priority_queue<node> qu;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dij(int S)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	qu.push((node){0,S});
	dis[S]=0;
	while(!qu.empty())
	{
		node xx=qu.top();
		qu.pop();
		int x=xx.p;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(dis[y]>dis[x]+1&&dis[x]+1<=k+1)
			dis[y]=dis[x]+1,qu.push((node){dis[y],y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		//printf("%d ",dis[i]);
		if(dis[i]<=k+1&&i!=S)
		e[S].push_back(i);
	}
	if(dis[1]<=k+1) vi[S]=1;//printf("\n");
}
void dfs(int x,int k)
{
	//printf("---%d---\n",x);
	vis[x]=1;
	if(k==4)
	{
		if(vi[x]==1) ans=max(ans,f[x][4]);//,cout<<"qaq"<<ans<<"\n";
		return;
	}
	//cout<<e[x].size()<<"\n";
	for(int i=0;i<e[x].size();i++)
	{
		int y=e[x][i];//printf("%d\n",y);
		if(vis[y]) continue;
		if(f[x][k]+s[y]>f[y][k+1]) 
		f[y][k+1]=f[x][k]+s[y],vis[y]=1,dfs(y,k+1),vis[y]=0;
	}
}
bool pppp;
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	scanf("%lld",&s[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++) dij(i);
	memset(vis,0,sizeof vis);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
