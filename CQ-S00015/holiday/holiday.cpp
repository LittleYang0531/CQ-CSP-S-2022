//POYE's Code
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int n,m,k,cnt,p[2505],h[2505],dis[2505];
ll ans,val[2505],f[2505][5];
bool vis[2505];
vector<int> v;
struct node {int next,to;} a[40005];
inline void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}

inline void dfs(int x,int prt)
{
	if(int(v.size())>5*k+5) return;
	if((int)v.size()&&x==1)
	{
		int tot=v.size();
		if(tot<5) return;
		for(int i=0;i<tot;i++) p[i+1]=v[i];
		for(int i=0;i<=tot;i++)
			for(int j=1;j<=4;j++) f[i][j]=0;
		for(int i=2;i<=tot;i++)
		{
			f[i][1]=val[p[i]];
			for(int j=0;j<=k;j++)
			{
				if(i-j-1>=2) f[i][2]=max(f[i][2],f[i-j-1][1]+val[p[i]]);
				if(i-j-1>=3) f[i][3]=max(f[i][3],f[i-j-1][2]+val[p[i]]);
				if(i-j-1>=4) f[i][4]=max(f[i][4],f[i-j-1][3]+val[p[i]]);
			}
		}
		for(int i=0;i<=k;i++)
			ans=max(ans,f[tot-i][4]);
	}
	v.push_back(x);
	vis[x]=1;
	for(int i=h[x];i;i=a[i].next)
	{
		int y=a[i].to;
		if(y==prt||y!=1&&vis[y]) continue;
		dfs(y,x);
	}
	v.pop_back();
	vis[x]=0;
}

inline void bfs(int s)
{
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=-1;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=h[x];i;i=a[i].next)
		{
			int y=a[i].to;
			if(dis[y]==-1)
			{
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
}

inline void Solve()
{
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			for(int t=2;t<=n;t++)
				for(int l=2;l<=n;l++)
				{
					if(i==j||i==t||i==l||j==t||j==l||t==l) continue;
					bfs(1);
					if(dis[i]>k+1) continue;
					bfs(i);
					if(dis[j]>k+1) continue;
					bfs(j);
					if(dis[t]>k+1) continue;
					bfs(t);
					if(dis[l]>k+1) continue;
					bfs(l);
					if(dis[1]>k+1) continue;
					ans=max(ans,val[i]+val[j]+val[t]+val[l]);
				}
	printf("%lld",ans);
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",val+i);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	if(n<=20) {Solve();return 0;}
	dfs(1,0);
	printf("%lld",ans);
	
	return 0;
}
