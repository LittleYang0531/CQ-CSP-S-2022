#include<bits/stdc++.h>
using namespace std;
int n,m,q,d[500005];
struct edge
{
	int next,to;
}e[500005];
int h[500005],cnt;
bool v[500005];
void addedge(int x,int y)
{
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
pair<int,int>e1[500005];
struct abc
{
	int op,x,y;
}a[500005];
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d %d",&e1[i].first,&e1[i].second);
	scanf("%d",&q);
	if(n<=1e3 && q<=1e3)
	{
		for(int i=1;i<=m;i++)addedge(e1[i].second,e1[i].first),d[e1[i].first]++;
		int cnt=0;
		for(int i=1;i<=m;i++)cnt+=(d[i]==1);
		while(q--)
		{
			int op,x,y;
			scanf("%d %d",&op,&x);
			if(op==1)
			{
				scanf("%d",&y);
				for(int i=h[y];i;i=e[i].next)
				{
					int z=e[i].to;
					if(z==x)v[i]=1;
				}
				d[x]--;
				if(d[x]==0)cnt--;
				if(d[x]==1)cnt++;
				if(cnt==n)printf("YES\n");
				else printf("NO\n");
			}
			else if(op==2)
			{
				for(int i=h[x];i;i=e[i].next)
				{
					int y=e[i].to;
					if(v[i])continue;
					v[i]=1;
					d[y]--;
					if(d[y]==0)cnt--;
					if(d[y]==1)cnt++;
				}
				if(cnt==n)printf("YES\n");
				else printf("NO\n");
			}
			else if(op==3)
			{
				scanf("%d",&y);
				for(int i=h[y];i;i=e[i].next)
				{
					int z=e[i].to;
					if(z==x)v[i]=0;
				}
				d[x]++;
				if(d[x]==2)cnt--;
				if(d[x]==1)cnt++;
				if(cnt==n)printf("YES\n");
				else printf("NO\n");
			}
			else
			{
				for(int i=h[x];i;i=e[i].next)
				{
					int y=e[i].to;
					if(!v[i])continue;
					v[i]=0;
					d[y]++;
					if(d[y]==2)cnt--;
					if(d[y]==1)cnt++;
				}
				if(cnt==n)printf("YES\n");
				else printf("NO\n");
			}
		}
		return 0;
	}
	bool flag1=0;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&a[i].op,&a[i].x);
		if(q[i].op%2==1)scanf("%d",&a[i].y);
		else flag1=1;
	}
	if(!flag1)
	{
		for(int i=1;i<=m;i++)d[e1[i].first]++;
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=(d[i]==1);
		for(int i=1;i<=q;i++)
		{
			if(a[i].op==1)
			{
				d[a[i].x]--;
				if(d[a[i].x]==0)cnt--;
				if(d[a[i].x]==1)cnt++;
			}
			else
			{
				d[a[i].x]++;
				if(d[a[i].x]==2)cnt--;
				if(d[a[i].x]==1)cnt++;
			}
			if(cnt==n)printf("YES\n");
			else printf("NO\n");
		}
		return 0;
	}
	return 0;
}
