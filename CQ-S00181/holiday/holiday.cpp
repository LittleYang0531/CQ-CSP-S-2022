#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=300,M=1000*2+7;
int n,m,k,dist[N][N],st[N],p[N][N],data[N],ans;
int h[N],ne[M],e[M],idx;
vector<int> g[N];
void add(int x,int y)
{
	e[++idx]=y;
	ne[idx]=h[x];
	h[x]=idx;
}

struct node{
	int id,dist;
	bool operator < (const node &W) const
	{
		return dist<W.dist;
	}
};

node f(int x,int y)
{
	node TP;
	TP.id=x; TP.dist=y;
	return TP;
} 

void dji(int x)
{
	memset(st,0,sizeof st);
	
	priority_queue<node>q;
	dist[x][x]=0; q.push(f(x,0));
	
	while(!q.empty())
	{
//		cout<<dist[x][x]<<" ";
		int u=q.top().id; q.pop();
		if(st[u]) continue;
		
		st[u]=1;
		for(int i=h[u];i;i=ne[i])
		{
			int j=e[i];
			if((dist[x][j]>k && dist[x][j]>dist[x][u]+1) || (dist[x][j]<=k && p[x][j]<p[x][u]+data[u] && dist[x][u]+1<=k))
			{
				dist[x][j]=dist[x][u]+1;
				p[x][j]=p[x][u]+data[u];
				q.push(f(j,dist[x][j]));
			} 
		}
	}
} 

void _bfs(int x)
{
	memset(st,0,sizeof st);
	queue<int> q,w; q.push(x); w.push(1);
	while(!q.empty())
	{
		int u=q.front(),pos=w.front(); q.pop(); w.pop();
		if(pos==k+1) return ;
		if(st[u]==1) continue;
		
		st[u]=1;
		add(x,u),add(u,x);
		for(int i=0;i<(int)g[u].size();i++)
		{
			int j=g[u][i];
			q.push(j); w.push(pos+1);
		} 
	}
}

void bfs()
{
	for(int i=1;i<=n;i++) _bfs(i);
}

signed main()
{
	freopen("holiday1.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k); 
	k++;
	for(int i=2;i<=n;i++) scanf("%lld",&data[i]);
	if(k==1)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y; scanf("%lld%lld",&x,&y);
			add(x,y),add(y,x);
		}
		memset(dist,0x3f,sizeof dist);
		for(int i=1;i<=n;i++) dji(i) ;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				for(int c=2;c<=n;c++)
				{
					for(int u=2;u<=n;u++)
					{
						map<int,int> mp; mp[i]++,mp[j]++,mp[c]++,mp[u]++;
						if(mp[u]>1 || mp[i]>1||mp[j]>1||mp[c]>1) continue;
						if(dist[1][i]>k||dist[i][j]>k||dist[j][c]>k||dist[c][u]>k||dist[u][1]>k) continue;
						ans=max(ans,data[i]+data[j]+data[c]+data[u]);
					}
				}
			}
		}
		
		printf("%lld",ans);
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			int x,y; scanf("%lld%lld",&x,&y);
			g[x].push_back(y),g[y].push_back(x);
		}
		
		bfs();
		
		memset(dist,0x3f,sizeof dist);
		for(int i=1;i<=n;i++) dji(i) ;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				for(int c=2;c<=n;c++)
				{
					for(int u=2;u<=n;u++)
					{
						map<int,int> mp; mp[i]++,mp[j]++,mp[c]++,mp[u]++;
						if(mp[u]>1 || mp[i]>1||mp[j]>1||mp[c]>1) continue;
						if(dist[1][i]>k||dist[i][j]>k||dist[j][c]>k||dist[c][u]>k||dist[u][1]>k) continue;
						ans=max(ans,data[i]+data[j]+data[c]+data[u]);
					}
				}
			}
		}
		
		printf("%lld",ans);
	}
	return 0;
}

