#include<bits/stdc++.h>
using namespace std;
int n,m,k,h[2505],cnt,h1[2505],cnt1,dis[2505];
long long a[2505],d[2505],maxx;
bool flag[2505];
struct nn{
	int to,next;
}e[20005],e1[200005];
struct node{
	int id;
	long long d;
	bool operator<(const node &b)const
	{
		return d>b.d;
	}
}asdf;
struct node1{
	int id;
	long long d;
	bool operator<(const node1 &b)const
	{
		return d<b.d;
	}
}asdf1;
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void add1(int x,int y)
{
	e1[++cnt1].to=y;
	e1[cnt1].next=h1[x];
	h1[x]=cnt1;
}
void dijkstra(int x)
{
	memset(d,0x3f,sizeof(d));
	d[x]=0;
	memset(flag,0,sizeof(flag));
	priority_queue<node>pq;
	pq.push((node){x,0});
	while(!pq.empty())
	{
		asdf=pq.top();
		pq.pop();
		flag[asdf.id]=1;
		if(d[asdf.id]>k+1)break;
		for(int i=h[asdf.id];i;i=e[i].next)
		{
			int y=e[i].to;
			if(!flag[y]&&d[asdf.id]+1<d[y])
			{
				d[y]=d[asdf.id]+1;
				pq.push((node){y,d[y]});
			}
		}
	}
	for(int i=1;i<=n;i++)if(i!=x&&d[i]<=k+1)add1(x,i);
}
bool check(int x)
{
	for(int i=h1[x];i;i=e1[i].next)if(e1[i].to==1)return true;
	return false;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	priority_queue<node1>pq;
	memset(flag,0,sizeof(flag));
	memset(d,-0x3f,sizeof(d));
	d[1]=0;
	pq.push((node1){1,0});
	while(!pq.empty())
	{
		asdf1=pq.top();
		pq.pop();
		flag[asdf1.id]=1;
		if(dis[asdf1.id]==4)
		{
			if(check(asdf1.id))maxx=max(maxx,d[asdf1.id]);
			continue;
		}
		for(int i=h1[asdf1.id];i;i=e1[i].next)
		{
			int y=e1[i].to;
			if(!flag[y]&&d[asdf1.id]+a[y]>d[y])
			{
				d[y]=d[asdf1.id]+a[y];
				dis[y]=dis[asdf1.id]+1;
				pq.push((node1){y,d[y]});
			}
		}
	}
	cout<<maxx;
	return 0;
}
