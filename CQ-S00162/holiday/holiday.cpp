#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[2505],f[2505][10],maxx=-1; 
int head[2505],cnt,vis[2505][2505],flag[2505];
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
	vis[s][s]=-1;
	q.push((node){s,-1});
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
void dfs(int x,int num,long long sum)
{
	if(num==4)
	{
		dfs(1,5,sum);
		maxx=max(maxx,sum);
		return ;
	}
	if(num==3)
	{
		for(int i=1;i<=n;i++)
		{
			if(!flag[i] && vis[i][1]<=k && vis[x][i]<=k)
			{
				flag[i]=1;
				dfs(i,4,sum+a[i]);
				flag[i]=0;
			}
		}
	}
	if(num<3)
	{
		for(int i=1;i<=n;i++)
		{
			if(!flag[i] && vis[x][i]<=k)
			{
				flag[i]=1;
				dfs(i,num+1,sum+a[i]);
				flag[i]=0;
			}
		}
	}
	return ;
}
int main ()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(vis,0x3f,sizeof(vis));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
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
	flag[1]=1;
	dfs(1,0,0);
	printf("%lld",maxx);
	return 0;
}
