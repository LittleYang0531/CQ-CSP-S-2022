#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
typedef long long ll;
const int maxm=20002,maxn=2505,mod=998244353;
const int inf=(1<<30);
const ll INF=(1ll<<60);
using namespace std;
int ask(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
struct str{
	int next,to;
}a[maxm*2];
int h[maxn],cnt;
void add(int x,int y)
{
	a[++cnt].to =y;
	a[cnt].next =h[x];
	h[x]=cnt;
}
bool e[maxn][maxn];
int n,m,k;
int d[maxn],vis[maxn];
ll mx[maxn][4];
int g[maxn][4];
ll v[maxn];
void bfs(int s)
{
	for(int i=1;i<=n;i++)d[i]=inf,vis[i]=0;
	queue<int>q;
	d[s]=0;
	q.push(s);
	vis[s]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		if(d[x]<=k)
		{
			if(x!=s);
			e[s][x]=1;
		}else continue;
		for(int i=h[x];i;i=a[i].next )
		{
			int y=a[i].to ;
			if(!vis[y])
			{
				vis[y]=1;
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read()+1;
	for(int i=2;i<=n;i++)v[i]=read();
	v[0]=v[1]=-INF;
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(e[1][i])vis[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		mx[i][0]=mx[i][1]=mx[i][2]=-INF;
		for(int j=2;j<=n;j++)
		{
			if(vis[j]&&e[i][j]&&j!=i)
			{
				if(v[j]>mx[i][0])
				{
					mx[i][2]=mx[i][1];
					g[i][2]=g[i][1];
					mx[i][1]=mx[i][0];
					g[i][1]=g[i][0];
					mx[i][0]=v[j];
					g[i][0]=j;
				}else if(v[j]>mx[i][1])
				{
					mx[i][2]=mx[i][1];
					g[i][2]=g[i][1];
					mx[i][1]=v[j];
					g[i][1]=j;
				}else if(v[j]>mx[i][2])
				{
					mx[i][2]=v[j];
					g[i][2]=j;
				}
			}
		}
	}
	ll ans=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(e[i][j])
			{
				ll w=0;
				for(int x=0;x<3;x++)
				{
					for(int y=0;y<3;y++)
					{
						if(g[i][x]==j||g[j][y]==i||g[i][x]==g[j][y])continue;
						if(v[g[i][x]]+v[g[j][y]]>w)
						{
							w=v[g[i][x]]+v[g[j][y]];
						}
					}
				}
				ans=max(ans,v[i]+v[j]+w);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
