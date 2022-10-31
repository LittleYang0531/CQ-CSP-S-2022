#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
int a[3000];
int d[3000];
int e[3000];
int vis[3000],c;
int f[3000][4];
int dis[3000][3000];
int head[3000],nex[30000],ver[30000],tot;
void add(int u,int v){nex[++tot]=head[u];ver[tot]=v;head[u]=tot;}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1,u,v;i<=m;i++)
	scanf("%lld%lld",&u,&v),add(u,v),add(v,u);
	d[1]=1;
	queue<int>q,p;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x!=1&&d[x]-2<=k)
		{
			vis[x]=++c;
			e[x]=1;
			dis[x][0]=1;
			p.push(x);
			while(!p.empty())
			{
				int y=p.front();
				p.pop();
				dis[x][y]=1;
				if(y!=1&&y!=x&&e[y]-2<=k)
				{
					f[y][3]=x;
					if(a[f[y][3]]>a[f[y][2]])
					swap(f[y][3],f[y][2]);
					if(a[f[y][2]]>a[f[y][1]])
					swap(f[y][2],f[y][1]);
					if(a[f[y][1]]>a[f[y][0]])
					swap(f[y][1],f[y][0]);
				}
				if(e[y]-2<k)
				for(int i=head[y];i;i=nex[i])
				if(vis[ver[i]]!=c)
				vis[ver[i]]=c,e[ver[i]]=e[y]+1,p.push(ver[i]);
			}
		}
		if(d[x]-2<k)
		for(int i=head[x];i;i=nex[i])
		if(!d[ver[i]])
		d[ver[i]]=d[x]+1,q.push(ver[i]);
	}
	for(int x=2,u,v,w;x<=n;x++)
	{
		if(!dis[x][0])
		{
			vis[x]=++c;
			e[x]=1;
			dis[x][0]=1;
			p.push(x);
			while(!p.empty())
			{
				int y=p.front();
				p.pop();
				dis[x][y]=1;
				if(e[y]-2<k)
				for(int i=head[y];i;i=nex[i])
				if(vis[ver[i]]!=c)
				vis[ver[i]]=c,e[ver[i]]=e[y]+1,p.push(ver[i]);
			}
		}
		for(int y=x+1;y<=n;y++)
		if(dis[x][y])
		{
			u=f[x][0]==y;
			v=f[y][0]==x;
			if(f[x][u]!=f[y][v]&&f[x][u]&&f[y][v])
			ans=max(ans,a[x]+a[y]+a[f[x][u]]+a[f[y][v]]);
			else
			{
				w=++u;
				w+=f[x][w]==y;
				if(f[x][w]&&f[y][v])
				ans=max(ans,a[x]+a[y]+a[f[x][w]]+a[f[y][v]]);
				w=++v;
				w+=f[y][w]==x;
				if(f[x][u]&&f[y][w])
				ans=max(ans,a[x]+a[y]+a[f[x][u]]+a[f[y][w]]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
