#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>

#define maxn 100005
#define rc() getchar()

using namespace std;

int inf=(1<<30);
long long inf_ll=(1ll<<60);
int a[maxn],b[maxn];

struct tree
{
	int minn[maxn<<2],maxx[maxn<<2],c[maxn],bj[maxn];
	inline void build(int x,int l,int r)
	{
		if(l==r)
		{
			if(bj[l]) return minn[x]=inf,maxx[x]=-inf,void();
			else return minn[x]=maxx[x]=c[l],void();
		}
		int mid=l+r>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);
		minn[x]=min(minn[x<<1],minn[x<<1|1]);maxx[x]=max(maxx[x<<1],maxx[x<<1|1]);
	}
	inline int qmax(int x,int l,int r,int nl,int nr)
	{
		if(nl<=l&&r<=nr) return maxx[x];
		if(r<nl||nr<l) return -inf;int mid=l+r>>1;
		return max(qmax(x<<1,l,mid,nl,nr),qmax(x<<1|1,mid+1,r,nl,nr));
	}
	inline int qmin(int x,int l,int r,int nl,int nr)
	{
		if(nl<=l&&r<=nr) return minn[x];
		if(r<nl||nr<l) return inf;int mid=l+r>>1;
		return min(qmin(x<<1,l,mid,nl,nr),qmin(x<<1|1,mid+1,r,nl,nr));
	}
	
}t1,t2,t3;

inline int read()
{
	int x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=rc();
	return x*b;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int n=read(),m=read(),q=read();
	int n1=0,n2=0;
	for(int i=1;i<=n;++i)
	{
		int a=read();
		if(a==0) t1.c[i]=t2.c[i]=0;
		else if(a>0) t1.c[i]=a,t2.bj[i]=1;
		else if(a<0) t2.c[i]=a,t1.bj[i]=1;
	}
	for(int i=1;i<=m;++i) t3.c[i]=read();
	t1.build(1,1,n);t2.build(1,1,n);t3.build(1,1,m);
	for(int i=1;i<=q;++i)
	{
		int l1=read(),r1=read(),l2=read(),r2=read();
		long long ans=-inf_ll;
		int amin1=t1.qmin(1,1,n,l1,r1),amin2=t2.qmin(1,1,n,l1,r1);
		int amax1=t1.qmax(1,1,n,l1,r1),amax2=t2.qmax(1,1,n,l1,r1);
		int bmin=t3.qmin(1,1,m,l2,r2),bmax=t3.qmax(1,1,m,l2,r2);
		if(amin1!=inf) ans=max(ans,1ll*amin1*bmin);
		if(amax1!=-inf) ans=max(ans,1ll*amax1*bmin);
		if(amin2!=inf) ans=max(ans,1ll*amin2*bmax);
		if(amax2!=-inf) ans=max(ans,1ll*amax2*bmax);
		printf("%lld\n",ans);
	}
	return 0;
}
