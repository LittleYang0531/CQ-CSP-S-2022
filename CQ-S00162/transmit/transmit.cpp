#include <bits/stdc++.h>
using namespace std;
int n,Q,k;
long long a[2505],f[2505][10],minn=1e18,flag[2505]; 
int head[2505],cnt,vis[2505][2505];
struct mp{
	int nxt,t,z;
}e[20005];
void add(int x,int y,int z)
{
	e[++cnt]={head[x],y,z};
	head[x]=cnt;
}
struct node{
	int id,v;
	friend bool operator < (node a,node b)
	{
		return a.v>b.v;
	}
};
priority_queue<node> q;
void dijkstra(int s)
{
	vis[s][s]=0;
	q.push((node){s,0});
	while(!q.empty())
	{
		node tp=q.top();
		q.pop();
		int nowid=tp.id,nowv=tp.v;
		for(int i=head[nowid];i;i=e[i].nxt)
		{
			if(nowv+e[i].z<vis[s][e[i].t])
			{
				vis[s][e[i].t]=nowv+e[i].z;
				q.push((node){e[i].t,vis[s][e[i].t]});
			}
		}
	}
}
void dfs(int x,int y,long long sum)
{
	if(sum>=minn)
	{
		return ;
	}
	if(x==y)
	{
		minn=sum;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[x][i]<=k && flag[i]>sum+a[i])
		{
			flag[i]=sum+a[i];
			dfs(i,y,sum+a[i]);
		}
	}
	return ;
}
int main ()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(vis,0x3f,sizeof(vis));
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
	}
	for(int i=1;i<=Q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		memset(flag,0x3f,sizeof(flag));
		if(vis[x][y]<=k)
		{
			printf("%lld\n",a[x]+a[y]);
			continue;
		}
		minn=1e18;
		flag[x]=a[x];
		dfs(x,y,a[x]);
		printf("%lld\n",minn);
	}
	return 0;
}
