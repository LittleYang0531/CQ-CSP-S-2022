#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c))	
		x=x*10+c-'0',c=getchar();
	return x*f;
}
const int MAXN=1e3+5;
long long n,m,q,ans,a[MAXN],b[MAXN],c[MAXN][MAXN];
struct segment_tree{
	#define mid ((l+r)>>1)
	#define ls (x<<1)
	#define rs ((x<<1)|1)
	long long tree[MAXN<<2],w[MAXN];
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			tree[x]=w[l];
			return ;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
		tree[x]=min(tree[ls],tree[rs]);
	}
	long long q(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		return tree[x];
		if(L>mid)
		return q(rs,mid+1,r,L,R);
		else if(R<=mid)
		return q(ls,l,mid,L,R);
		else
		return min(q(ls,l,mid,L,mid),q(rs,mid+1,r,mid+1,R));
	}
}seg[MAXN];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			seg[i].w[j]=a[i]*b[j];
		
		}
		
		seg[i].build(1,1,n);
		
	}
	
	while(q--)
	{
		int l1,r1,l2,r2;
		l1=read(),r1=read(),l2=read(),r2=read();
		long long ans=-1e9;
		for(int i=l1;i<=r1;i++)
		ans=max(ans,seg[i].q(1,1,n,l2,r2));
		cout<<ans<<endl;
	}
	return 0;
}
