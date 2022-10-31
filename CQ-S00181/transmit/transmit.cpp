#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N= 2000 +7,M=N*2;
int n,m,q,k,a[N],dist[N][N],st[N];
int h[N],ne[M],w[M],e[M],idx;
vector<int> g[N];
void add(int x,int y,int z)
{
	e[++idx]=y;
	w[idx]=z;
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

void _bfs(int x)
{
	memset(st,0,sizeof st);
	queue<int> q,w; q.push(x); w.push(0);
	while(!q.empty())
	{
		int u=q.front(),pos=w.front(); q.pop(); w.pop();
		if(pos==k+1) return ;
		if(st[u]==1) continue;
		
		st[u]=1;
		add(x,u,a[u]),add(u,x,a[x]);
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

void dji(int x)
{
	memset(st,0,sizeof st);
	
	priority_queue<node>q;
	dist[x][x]=0; q.push(f(x,0));
	
	while(!q.empty())
	{
		int u=q.top().id; q.pop();
		if(st[u]) continue;
		
		st[u]=1;
		for(int i=h[u];i;i=ne[i])
		{
			int j=e[i];
			if(dist[x][j]>dist[x][u]+w[i])
			{
				dist[x][j]=dist[x][u]+w[i];
				q.push(f(j,dist[x][j]));
			} 
		}
	}
} 

signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) 
	{
		int x,y; cin>>x>>y;
		g[x].push_back(y),g[y].push_back(x);
	}
	
	bfs();
	memset(dist,0x3f3f3f3f,sizeof dist);
	for(int i=1;i<=n;i++) dji(i);
	
	while(q--)
	{
		int x,b; cin>>x>>b;
		cout<<dist[x][b]+a[x]<<endl;
	}
	
	return 0;
}

