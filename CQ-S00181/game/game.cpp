#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N= 1e5 +7;
int n,m,tesk,q,a[N],b[N];
struct node{
	int l1,r1,l2,r2;
}p[N];
struct tree{
	struct pist{
		int l,r,data1,data2;
	}tr[N<<2];
	
	void push_up(int u)
	{
		tr[u].data1=max(tr[u<<1].data1,tr[u<<1|1].data1);
		tr[u].data2=min(tr[u<<1].data2,tr[u<<1|1].data2);
	}
	
	void build(int u,int l,int r,int p[])
	{
		tr[u].l=l,tr[u].r=r;
		if(l==r)
		{
			tr[u].data1=tr[u].data2=p[l];
			return ;
		}
		
		int mid=l+r>>1;
		build(u<<1,l,mid,p);
		build(u<<1|1,mid+1,r,p);
		push_up(u);
	}
	
	int query1(int l,int r,int u)
	{
		if(l<=tr[u].l && tr[u].r<=r) return tr[u].data1;
		
		int mid=tr[u].l+tr[u].r>>1,ret=-0x3f3f3f3f;
		if(l<=mid) ret=query1(l,r,u<<1);
		if(r>mid)  ret=max(ret,query1(l,r,u<<1|1));
		return ret; 
	} 
	
	int query2(int l,int r,int u)
	{
		if(l<=tr[u].l && tr[u].r<=r) return tr[u].data2;
		
		int mid=tr[u].l+tr[u].r>>1,ret=0x3f3f3f3f;
		if(l<=mid) ret=query2(l,r,u<<1);
		if(r>mid)  ret=min(ret,query2(l,r,u<<1|1));
		return ret; 
	} 
}A,B;

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=q;i++) scanf("%lld%lld%lld%lld",&p[i].l1,&p[i].r1,&p[i].l2,&p[i].r2);
	A.build(1,1,n,a); B.build(1,1,n,b);
	for(int i=1;i<=q;i++)
	{
		if(p[i].l1==p[i].r1) printf("%lld\n",a[p[i].l1]*B.query2(p[i].l2,p[i].r2,1));
		else if(p[i].l2==p[i].r2)
		{
			int tp=b[p[i].l2];
			if(tp<0) printf("%lld\n",A.query2(p[i].l1,p[i].r1,1)*tp);
			else printf("%lld\n",tp*A.query1(p[i].l1,p[i].r1,1));
		}
		else
		{
			printf("%lld\n",B.query2(p[i].l2,p[i].r2,1)*A.query1(p[i].l1,p[i].r1,1));
		}
	}
	
	
	return 0;
}

