#include<bits/stdc++.h>
#define inf 2e9
#define N 100005
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int A,B,C,D,E,mmin,mmax,n,m,q,a[N],b[N],l1,r1,l2,r2,s[N];
ll ans;
inline int chmax(int x,int y){return x<y?y:x;}
inline int chmin(int x,int y){return x<y?x:y;}
struct seg
{
	int mx[N<<2],mn[N<<2],mn2[N<<2],mx2[N<<2];
	inline void pushup(int node)
	{
		mx[node]=chmax(mx[node<<1],mx[node<<1|1]);
		mn[node]=chmin(mn[node<<1],mn[node<<1|1]);
		mx2[node]=chmax(mx2[node<<1],mx2[node<<1|1]);
		mn2[node]=chmin(mn2[node<<1],mn2[node<<1|1]);
	}
	inline void build(int l,int r,int node,int pd)
	{
		mx[node]=mx2[node]=-inf;
		mn[node]=mn2[node]=inf;
		if(l==r) 
		{
			if(!pd)
			{
				mx[node]=mn[node]=a[l];
				if(a[l]>0) mn2[node]=a[l];
				if(a[l]<0) mx2[node]=a[l];	
			}
			else
			{
				mx[node]=mn[node]=b[l];
				if(b[l]>0) mn2[node]=b[l];
				if(b[l]<0) mx2[node]=b[l];
			}
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,node<<1,pd);
		build(mid+1,r,node<<1|1,pd);
		pushup(node);
	}
	inline int query_mx(int l,int r,int node,int x,int y)
	{
		if(r<x||l>y) return -inf;
		if(x<=l&&r<=y) return mx[node];
		int mid=(l+r)>>1;
		return chmax(query_mx(l,mid,node<<1,x,y),query_mx(mid+1,r,node<<1|1,x,y));
	}
	inline int query_mx2(int l,int r,int node,int x,int y)
	{
		if(r<x||l>y) return -inf;
		if(x<=l&&r<=y) return mx2[node];
		int mid=(l+r)>>1;
		return chmax(query_mx2(l,mid,node<<1,x,y),query_mx2(mid+1,r,node<<1|1,x,y));
	}
	inline int query_mn(int l,int r,int node,int x,int y)
	{
		if(r<x||l>y) return inf;
		if(x<=l&&r<=y) return mn[node];
		int mid=(l+r)>>1;
		return chmin(query_mn(l,mid,node<<1,x,y),query_mn(mid+1,r,node<<1|1,x,y));
	}
	inline int query_mn2(int l,int r,int node,int x,int y)
	{
		if(r<x||l>y) return inf;
		if(x<=l&&r<=y) return mn2[node];
		int mid=(l+r)>>1;
		return chmin(query_mn2(l,mid,node<<1,x,y),query_mn2(mid+1,r,node<<1|1,x,y));
	}
}T1,T2;
inline void write(ll x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		s[i]=s[i-1]+(!a[i]);
	}
	T1.build(1,n,1,0);
	for(int i=1;i<=m;i++) b[i]=read();
	T2.build(1,m,1,1);
	while(q--)
	{
		l1=read();r1=read();l2=read();r2=read();
		A=T1.query_mx(1,n,1,l1,r1);
		B=T1.query_mn2(1,n,1,l1,r1);
		C=T1.query_mn(1,n,1,l1,r1);
		D=T1.query_mx2(1,n,1,l1,r1);
		E=s[r1]-s[l1-1];
		if(E) ans=0;
		else ans=-2e18;
		mmin=T2.query_mn(1,m,1,l2,r2);mmax=T2.query_mx(1,m,1,l2,r2);
	//	cout<<mmin<<"¡¡"<<mmax<<endl; 
		if(A>0) ans=max(ans,1ll*A*mmin);
		else ans=max(ans,1ll*A*mmax);
		if(B!=inf) 
		{
			if(B>0) ans=max(ans,1ll*B*mmin);
			else ans=max(ans,1ll*B*mmax);
		}
		if(C>0) ans=max(ans,1ll*C*mmin);
		else ans=max(ans,1ll*C*mmax);
		if(D!=-inf) 
		{
			if(D>0) ans=max(ans,1ll*D*mmin);
			else ans=max(ans,1ll*D*mmax);
		}
		//printf("%lld\n",ans);
		if(ans<0) putchar('-'),ans=-ans;
		write(ans);puts("");
	}
	return 0;
}
