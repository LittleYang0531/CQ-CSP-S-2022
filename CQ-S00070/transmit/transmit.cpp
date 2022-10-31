#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
typedef long long ll;
const int maxn=200002,mod=998244353;
const ll inf=(1ll<<60);
using namespace std;
int ask(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
struct str{
	int next,to;
}a[maxn*4];
int h[maxn],cnt;
void add(int x,int y)
{
	a[++cnt].to =y;
	a[cnt].next =h[x];
	h[x]=cnt;
}
int n,q,K;
int v[maxn],s[maxn],son[maxn],d[maxn],top[maxn],f[maxn],bh[maxn],xl[maxn],num;
void dfs(int x)
{
	s[x]=1;
	for(int i=h[x];i;i=a[i].next )
	{
		int y=a[i].to ;
		if(y!=f[x])
		{
			f[y]=x;
			d[y]=d[x]+1;
			dfs(y);
			s[x]+=s[y];
			if(!son[x]||s[son[x]]<s[y])son[x]=y;
		}
	}
}
void dfs1(int x,int u)
{
	top[x]=u;
	bh[x]=++num;
	xl[num]=x;
	if(son[x])dfs1(son[x],u);
	for(int i=h[x];i;i=a[i].next )
	{
		int y=a[i].to ;
		if(y!=f[x]&&y!=son[x])dfs1(y,y);
	}
}
struct node{
	ll f[4][4];
	node operator +(const node &b)
	{
		node c;
		for(int i=0;i<K;i++)for(int j=0;j<K;j++)c.f[i][j]=inf;
		for(int i=0;i<K;i++)
		{
			for(int k=0;k<K;k++)
			{
				for(int j=0;j<K;j++)
				{
					c.f[i][j]=min(c.f[i][j],f[i][k]+b.f[k][j]);
				}
			}
		}
		return c;
	}
}t[maxn*4],t1[maxn*4];
void make(int k,int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<K;i++)
		{
			for(int j=0;j<K;j++)
			{
				t[k].f[i][j]=inf;
				if(j==0)t[k].f[i][j]=v[xl[l]];
				else if(i==j-1)t[k].f[i][j]=0;
			}
		}
		t1[k]=t[k];
		return;
	}
	int mid=(l+r)>>1;
	make(2*k,l,mid);
	make(2*k+1,mid+1,r);
	t[k]=t[2*k]+t[2*k+1];
	t1[k]=t1[2*k+1]+t1[2*k];
}
node ask(int k,int l,int r,int sl,int sr)
{
	if(sl<=l&&sr>=r)return t[k];
	if(sr<l||sl>r)
	{
		node w;
		for(int i=0;i<K;i++)for(int j=0;j<K;j++)
		{
			w.f[i][j]=inf;
			if(i==j)w.f[i][j]=0;
		}
		return w;
	}
	int mid=(l+r)>>1;
	return ask(2*k,l,mid,sl,sr)+ask(2*k+1,mid+1,r,sl,sr);
}
node ask1(int k,int l,int r,int sl,int sr)
{
	if(sl<=l&&sr>=r)return t1[k];
	if(sr<l||sl>r)
	{
		node w;
		for(int i=0;i<K;i++)for(int j=0;j<K;j++)
		{
			w.f[i][j]=inf;
			if(i==j)w.f[i][j]=0;
		}
		return w;
	}
	int mid=(l+r)>>1;
	return ask1(2*k+1,mid+1,r,sl,sr)+ask1(2*k,l,mid,sl,sr);
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(d[x]<d[y])return x;
	return y;
}
bool vis[2002][2002];
ll dis[2002][2002];
void dfs2(int x,int p,int d,int rt)
{
	for(int i=h[x];i;i=a[i].next )
	{
		int y=a[i].to ;
		if(y!=p)
		{
			if(d<K)
			{
				vis[rt][y]=1;
				dfs2(y,x,d+1,rt);
			}
		}
	}
}
struct st{
	int i;
	ll v;
	bool operator <(const st &b)const
	{
		return v>b.v;
	}
};
priority_queue<st>que;
void dij(int s)
{
	while(que.size())que.pop();
	for(int i=1;i<=n;i++)dis[s][i]=inf,vis[s][i]=0;
	dis[s][s]=v[s];
	que.push(st{s,v[s]});
	while(!que.empty())
	{
		st w=que.top();
		que.pop();
		int x=w.i;
		vis[s][x]=1;
		for(int i=h[x];i;i=a[i].next )
		{
			int y=a[i].to ;
			if(!vis[s][y])
			{
				if(dis[s][y]>dis[s][x]+v[y])
				{
					dis[s][y]=dis[s][x]+v[y];
					que.push(st{y,dis[s][y]});
				}
			}
		}
		while(que.size()&&vis[s][que.top().i])que.pop();
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),K=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			dfs2(i,0,0,i);
		}
		cnt=0;
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		{
			if(vis[i][j])
			{
				add(i,j);
				add(j,i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			dij(i);
		}
		while(q--)
		{
			int s=read(),t=read();
			printf("%lld\n",dis[s][t]);
		}
		return 0;
	}
	dfs(1);
	dfs1(1,1);
	make(1,1,n);
	while(q--)
	{
		int s=read(),t=read();
		int p=lca(s,t);
		node ans,w;
		for(int i=0;i<K;i++)for(int j=0;j<K;j++)
		{
			ans.f[i][j]=inf;
			w.f[i][j]=inf;
			if(i==j)w.f[i][j]=0;
		}
		ans.f[0][K-1]=0;
		while(top[s]!=top[p])
		{
			node e=ask1(1,1,n,bh[top[s]],bh[s]);
			ans=ans+e;
			s=f[top[s]];
		}
		node e=ask1(1,1,n,bh[p],bh[s]);
		ans=ans+e;
		while(top[t]!=top[p])
		{
			node e=ask(1,1,n,bh[top[t]],bh[t]);
			w=e+w;
			t=f[top[t]];
		}
		if(t!=p)
		{
			e=ask(1,1,n,bh[p]+1,bh[t]);
			w=e+w;
		}
		ans=ans+w;
		printf("%lld\n",ans.f[0][0]);
	}
	return 0;
}
