#include<bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1,*p2;
//#define getchar (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
const long long INF=0x7fffffffffffffffll;
const int N=200000;
struct Edge{
	int self,next;
}edge[2*N+5];
struct Node{
	int prt;
	int depth;
	int value;
	long long value_sum;
	int climb[5][20];
	long long jump[5][20];
}node[N+5];
int n,q,k;
int to[N+5],o;
//long long dp[2005][2005];
void add_edge(int x,int y)
{
	edge[++o].self=y;
	edge[o].next=to[x];
	to[x]=o;
}
void dfs(int x)
{
	node[x].depth=node[node[x].prt].depth+1;
	node[x].value_sum=node[node[x].prt].value_sum+node[x].value;
	for(int i=to[x];i;i=edge[i].next)
	{
		int y=edge[i].self;
		if(y==node[x].prt)continue;
		node[y].prt=x;
		dfs(y);
	}
}
int lca(int x,int y)
{
	if(node[x].depth>node[y].depth)swap(x,y);
	int cnt=node[y].depth-node[x].depth;
	for(int i=0;cnt;++i)
	{
		if(cnt&1)y=node[y].climb[2][i];
		cnt>>=1;
	}
	assert(node[x].depth==node[y].depth);
	if(x==y)return x;
	cnt=log2(node[x].depth);
	while(cnt>=0)
	{
		if(node[x].climb[2][cnt]!=node[y].climb[2][cnt])
		{
			x=node[x].climb[2][cnt];
			y=node[y].climb[2][cnt];
		}
		--cnt;
	}
	return node[x].prt;
}
int kth(int x,int cnt)
{
//	cerr<<"DEBUG "<<cnt<<'\n';
	for(int i=0;cnt;++i)
	{
		if(cnt&1)x=node[x].climb[2][i];
		cnt>>=1;
	}
	return x;
}
long long calc2(int x,int y)
{
	int x2=node[x].prt;
	long long va=0,va2=node[x].value;
	int cnt=node[x].depth-node[y].depth;
	for(int i=0;cnt;++i)
	{
		if(cnt&1)
		{
			long long nv,nv2;
			nv=min(va+node[x].jump[2][i],va2+node[x2].jump[1][i]);
			nv2=min(va+node[x].jump[3][i],va2+node[x2].jump[2][i]);
			x=node[x].climb[2][i];
			x2=node[x2].climb[2][i];
			va=nv;
			va2=nv2;
		}
		cnt>>=1;
	}
	return va;
}
long long calc(int x,int y)
{
	if(node[x].depth>node[y].depth)swap(x,y);
	int fa=lca(x,y);
	if(k==1)
	{
		return node[x].value_sum+node[y].value_sum-node[fa].value_sum-node[node[fa].prt].value_sum;
	}
	else if(k==2)
	{
		if(fa==x)return calc2(y,x)+node[x].value;
		else
		{
			int fa2=kth(x,node[x].depth-node[fa].depth-1);
			int fa3=kth(y,node[y].depth-node[fa].depth-1);
			long long answer=calc2(x,fa)+calc2(y,fa)+node[fa].value;
			answer=min(answer,calc2(x,fa2)+node[fa2].value+node[fa3].value+calc2(y,fa3));
			return answer;
		}
	}
	else
	{
		
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	read(n),read(q),read(k);
	for(int i=1;i<=n;++i)read(node[i].value);
	for(int i=1;i<n;++i)
	{
		int x,y;
		read(x),read(y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs(1);
	if(k==1)
	{
		for(int x=1;x<=n;++x)
		{
			node[x].climb[2][0]=node[x].prt;
			node[x].jump[2][0]=node[x].value;
		}
		for(int i=1;i<=log2(n);++i)
		{
			for(int x=1;x<=n;++x)
			{
				node[x].climb[2][i]=node[node[x].climb[2][i-1]].climb[2][i-1];
				node[x].jump[2][i]=node[node[x].climb[2][i-1]].jump[2][i-1]+node[x].jump[2][i-1];
			}
		}
	}
	else if(k==2)
	{
		for(int x=1;x<=n;++x)
		{
			node[x].climb[1][0]=x;
			node[x].jump[1][0]=0;
			node[x].climb[3][0]=node[node[x].prt].prt;
			node[x].jump[3][0]=node[x].value;
			node[x].climb[2][0]=node[x].prt;
			node[x].jump[2][0]=node[x].value;
		}
		for(int i=1;i<=log2(n);++i)
		{
			for(int x=1;x<=n;++x)
			{
				node[x].climb[2][i]=node[node[x].climb[2][i-1]].climb[2][i-1];
				node[x].jump[2][i]=min(node[node[x].climb[2][i-1]].jump[2][i-1]+node[x].jump[2][i-1],
					node[node[x].climb[3][i-1]].jump[1][i-1]+node[x].jump[3][i-1]);
				node[x].climb[1][i]=node[node[x].climb[2][i-1]].climb[1][i-1];
				node[x].jump[1][i]=min(node[node[x].climb[2][i-1]].jump[1][i-1]+node[x].jump[2][i-1],
					node[node[x].climb[1][i-1]].jump[2][i-1]+node[x].jump[1][i-1]);
				node[x].climb[3][i]=node[node[x].climb[2][i-1]].climb[3][i-1];
				node[x].jump[3][i]=min(node[node[x].climb[2][i-1]].jump[3][i-1]+node[x].jump[2][i-1],
					node[node[x].climb[3][i-1]].jump[2][i-1]+node[x].jump[3][i-1]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		read(x),read(y);
		cout<<calc(x,y)<<'\n';
	}
	return 0;
}
