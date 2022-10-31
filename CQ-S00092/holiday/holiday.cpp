#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

#define maxn 2505
#define maxm 10005
#define rc() getchar()

using namespace std;

int inf=(1<<30);
int bj[maxn],d[maxn],h[maxn],to[maxm<<1],nx[maxm<<1],cnt,n,m,k;
long long a[maxn],g[maxn][maxn],pre[maxn][maxn],suf[maxn][maxn];
int t[maxn][maxn];
struct node
{
	int x,c;
	inline bool operator < (const node &a) const {return c>a.c;}
};
priority_queue<node>q;

inline long long read()
{
	long long x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=rc();
	return x*b;
}

inline void mt(int x,int y)
{
	to[++cnt]=y;nx[cnt]=h[x];h[x]=cnt;
	to[++cnt]=x;nx[cnt]=h[y];h[y]=cnt;
}

inline void dij(int x)
{
	for(int i=1;i<=n;++i) d[i]=inf,bj[i]=0;
	d[x]=0;q.push((node){x,0});
	while(q.size())
	{
		int x=q.top().x,c=q.top().c;q.pop();
		if(bj[x]) continue;bj[x]=1;
		for(int i=h[x];i;i=nx[i])
		{
			if(d[x]+1<=d[to[i]])
			{
				d[to[i]]=d[x]+1;
				q.push((node){to[i],d[to[i]]});
			}
		}
	}
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;++i) a[i]=read();
	for(int i=1,x,y;i<=m;++i)
		x=read(),y=read(),mt(x,y);
	for(int i=1;i<=n;++i)
	{
		dij(i);
		for(int j=1;j<=n;++j)
			if(i!=j&&d[j]<=k+1) t[i][j]=t[j][i]=1;
	}
	for(int i=2;i<=n;++i)
	{
		if(!t[1][i]) continue;
		for(int j=2;j<=n;++j)
			if(t[i][j]) g[i][j]=a[i]+a[j];
	}
	long long ans=0;
	for(int i=2;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			if(!t[i][j]) continue;
			for(int k=2;k<=n;++k)
				if(k==i||k==j) pre[j][k]=pre[j][k-1];
				else pre[j][k]=max(pre[j][k-1],g[k][j]);
			for(int k=n;k>=2;--k)
				if(k==i||k==j) suf[j][k]=suf[j][k+1];
				else suf[j][k]=max(suf[j][k+1],g[k][j]);
			for(int k=2;k<=n;++k)
				if(t[k][i]&&k!=j) ans=max(ans,g[k][i]+max(pre[j][k-1],suf[j][k+1]));
		}
	printf("%lld",ans);
	return 0;
}
