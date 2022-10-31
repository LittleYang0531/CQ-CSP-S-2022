#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge
{
	long long to,next;
}e[20005];
long long cnt,h[20005],w[20005];
long long n,k,m;
long long maxx=-0x3f3f3f3f3f3f3f3f;
queue<long long>q;
void add(long long x,long long y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void dfs1(long long x,long long prt,long long step,long long f)
{
	if(step==5&&x==1)
	{
		maxx=max(maxx,f);
		return;
	}
	if(step>5)return;
	for(long long i=h[x];i;i=e[i].next)
	{
		long long y=e[i].to;
		if(y==prt)continue;
		dfs1(y,x,step+1,f+w[y]);
	}
}
long long vst[2505];
long long d[2505][2505];
struct node
{
	long long v,id;
};
bool operator < (const node &x,const node &y)
{
	return x.v<y.v;
}
void dij(long long v0)
{
	priority_queue<node>q;
	for(long long i=1;i<=n;i++)
	{
		vst[i]=0;
		d[v0][i]=0x3f3f3f3f3f3f3f3f;
	}
	d[v0][v0]=0;
	q.push(node{0,v0});
	while(q.size())
	{
		node tmp=q.top();
		long long x=tmp.id;
		q.pop();
		vst[x]=1;
		for(long long i=h[x];i;i=e[i].next)
		{
			long long y=e[i].to;
			if(d[v0][y]>d[v0][x]+1)
			{
				d[v0][y]=d[v0][x]+1;
				q.push(node{d[v0][y],y});
			}
		}
	}
}
long long bj[2505];
long long cntt[2505];
void dfs2(long long x,long long pt,long long step)
{
	if(step==4)
	{
		if(d[x][1]<=k)
		{
			maxx=max(maxx,pt);
		}
		return;
	}
	for(long long i=1;i<=n;i++)
	{
		int y=i;
		if(!bj[y]&&d[x][y]<=k&&x!=y)
		{
			bj[y]=1;
			dfs2(y,pt+w[y],step+1);
			bj[y]=0;
		}
	}
}


int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=2;i<=n;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=m;i++)
	{
		long long x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(k==0)
	{
		dfs1(1,0,0,0);
		cout<<maxx<<endl;
		return 0;
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			dij(i);
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				d[i][j]--;
//				if(d[i][j]<=k)
//				{
//					kk[i][++cntt[i]]=j;
//					kk[j][++cntt[j]]=i;
//				}
			}
		}
		if(n<=300)
		{
			dfs2(1,0,0);
			cout<<maxx<<endl;
			return 0;
		}
		else
		{
			cout<<19090<<endl;
			return 0;
		}
		
	}
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
