//sto moyujiang orz bless me AC
#include<bits/stdc++.h>
using namespace std;
struct node{
	int nxt,to;
}e[20005];
int n,m,k,ne,u,v,dk;
int h[2505],dis[2505][2505];
long long res,ans,a[2505];
queue<int> q;
vector<int> ve[2505];
pair<int,int> dep[2505],g[2505];
inline int read()
{
	int x(0);char ch(getchar());
	while(ch<48||ch>57) ch=getchar();
	while(ch>=48&&ch<=57) x=x*10+(ch^48),ch=getchar();
	return x;
}
inline long long lread()
{
	long long x(0);char ch(getchar());
	while(ch<48||ch>57) ch=getchar();
	while(ch>=48&&ch<=57) x=x*10+(ch^48),ch=getchar();
	return x;
}
void add(int x,int y)
{
	e[++ne].nxt=h[x];
	e[ne].to=y,h[x]=ne;
}
void bfs()
{
	q.push(1);
	dep[1].first=dep[1].second=1;
	while(!q.empty())
	{
		u=q.front();q.pop();
		for(int i=h[u];i;i=e[i].nxt)
			if(!dep[e[i].to].first) {dep[e[i].to].first=dep[u].first+1;q.push(e[i].to);}
	}
}
void calc(int x)
{
	dis[x][x]=0;
	for(int i=h[x];i;i=e[i].nxt)
	{
		v=e[i].to,dis[x][v]=dis[v][x]=1;
		if(dep[v].first==dep[x].first+1||dep[v].first==dep[x].first)
		{
			for(int j=n;j>x&&dep[j].first>=dep[x].first;j--)
				dis[dep[x].second][dep[j].second]=min(dis[dep[x].second][dep[j].second],dis[v][dep[j].second]+1);
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	n=read(),m=read(),k=read();dk=k<<1|1;
	for(int i=2;i<=n;i++) a[i]=lread(),dep[i].second=i;
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	bfs();
	sort(dep+1,dep+1+n);
	while(dep[n].first-2>dk) n--;
	for(int i=n;i>1;i--) calc(i);
	for(int i=2;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dis[i][j]<=k)
			{
				if(a[g[i].first]<=a[j]) g[i].second=g[i].first,g[i].first=j;
				else if(a[g[i].second]<=a[j]) g[i].second=j;
			}
		}
	}
	for(int i=2;i<=n&&dep[i].first-2<=k;i++)
	{
		for(int j=2;j<i;j++)
		{
			res=a[dep[i].second]+a[dep[j].second];
			if(g[i].first!=g[j].first) res+=a[g[i].first]+a[g[j].first];
			else res+=max(a[g[i].first]+a[g[j].second],a[g[i].second]+a[g[j].first]);
			ans=max(ans,res);
		}
	}
	printf("%lld",ans);
	return 0;
}

