#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2505,M=1e4+5,inf=0x3f3f3f3f;
int n,m,k,e,x,y,head[N],to[2*M],nxt[2*M],dis[N][N],mx[N][3];
long long A[N],ans;
bool vis[N];
queue<int> q;
void add_edge(int x,int y)
{
	to[++e]=y;
	nxt[e]=head[x];
	head[x]=e;
}
void bfs(int x)
{
	memset(vis,0,sizeof(vis));
	dis[x][x]=0;
	vis[x]=1;
	q.push(x);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(dis[x][t]==k+1) continue;
		for(int a=head[t];a>0;a=nxt[a])
		{
			int s=to[a];
			if(vis[s]==0)
			{
				vis[s]=1;
				dis[x][s]=dis[x][t]+1;
				q.push(s);
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int a=2;a<=n;a++) scanf("%lld",&A[a]);
	for(int a=1;a<=m;a++)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int a=1;a<=n;a++) bfs(a);
	for(int a=2;a<=n;a++)
	{
		for(int b=2;b<=n;b++)
		{
			if(dis[a][b]==inf||dis[1][b]==inf||a==b) continue;
			if(A[b]>A[mx[a][0]]) mx[a][2]=mx[a][1],mx[a][1]=mx[a][0],mx[a][0]=b;
			else if(A[b]>A[mx[a][1]]) mx[a][2]=mx[a][1],mx[a][1]=b;
			else if(A[b]>A[mx[a][2]]) mx[a][2]=b;
		}
	}
	for(int a=2;a<=n;a++)
	{
		for(int b=2;b<=n;b++)
		{
			if(dis[a][b]==inf||a==b) continue;
			ll tot=A[a]+A[b];
			for(int c=0;c<3;c++)
			{
				if(mx[a][c]==b||mx[a][c]==0) continue;
				for(int d=0;d<3;d++)
				{
					if(mx[b][d]==a||mx[b][d]==0) continue;
					if(mx[a][c]!=mx[b][d])
					{
						ans=max(ans,tot+A[mx[a][c]]+A[mx[b][d]]);
					}
				}
			}
		}
	}
	printf("%lld",ans);
}
