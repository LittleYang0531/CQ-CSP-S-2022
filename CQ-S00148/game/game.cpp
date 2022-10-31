#include<iostream>
#include<cstring>
#include<algorithm>

template<typename T>
inline void read(T &a)
{
	char c;
	bool flag=0;
	while(!isdigit(c=getchar()))
		flag|=(c=='-');
	a=0;
	for(a=c-'0';isdigit(c=getchar());a=a*10+c-'0');
	flag&&(a=-a);
}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10;
int n,m,q;
int a[N];

struct Node{
	int l,r;
	bool pos;
	int posmax,posmin,negmax,negmin;
};
struct Tree{
	Node tr[N<<2];
	inline void pushup(Node &u,Node ls,Node rs)
	{
		u.pos=ls.pos|rs.pos;
		u.posmax=max(ls.posmax,rs.posmax);
		u.posmin=min(ls.posmin,rs.posmin);
		u.negmax=max(ls.negmax,rs.negmax);
		u.negmin=min(ls.negmin,rs.negmin);
	}
	inline void pushup(int u){	pushup(tr[u],tr[u<<1],tr[u<<1|1]);
	}
	void build(int u,int l,int r)
	{
		tr[u]={l,r,a[l]>=0};
		if(l==r)
		{
			if(a[l]>=0)
			{
				tr[u].posmax=tr[u].posmin=a[l];
				tr[u].negmax=-2e9,tr[u].negmin=0;
			}else{
				tr[u].negmax=tr[u].negmin=a[l];
				tr[u].posmax=-1,tr[u].posmin=2e9;
			}
		}else{
			int mid=(l+r)>>1;
			build(u<<1,l,mid),build(u<<1|1,mid+1,r);
			pushup(u);
		}
	}
	Node query(int u,int l,int r)
	{
		if(l<=tr[u].l&&tr[u].r<=r)	return tr[u];
		Node tmp={l,r,0,-1,(int)2e9,(int)-2e9,0};
		int mid=(tr[u].l+tr[u].r)>>1;
		if(l<=mid)	tmp=query(u<<1,l,r);
		if(mid<r)	pushup(tmp,tmp,query(u<<1|1,l,r));
		return tmp;
	}
}T1,T2;

int main()
{
//	freopen("C:\\Users\\HF01\\Desktop\\CSP-S\\CSP-S\\game\\game4.in","r",stdin);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++)	read(a[i]);
	T1.build(1,1,n);
	for(int i=1;i<=m;i++)	read(a[i]);
	T2.build(1,1,m);
	while(q--)
	{
		int l1,r1,l2,r2;
		read(l1),read(r1),read(l2),read(r2);
		Node L=T1.query(1,l1,r1),Q=T2.query(1,l2,r2);
		ll ans=-2e18;
		if(Q.negmin==0)	//Q没有负数 
		{
			if(L.posmax==-1)	//L没有非负数 
				ans=1ll*L.negmax*Q.posmax;
			else	ans=1ll*L.posmax*Q.posmin;
		}else if(Q.posmax==-1)	//Q没有正数
		{
			if(L.negmin==0)
				ans=1ll*L.posmin*Q.negmin;
			else
				ans=1ll*L.negmin*Q.negmax;
		}else	//Q有正有负 
		{
			if(L.posmax!=-1)
				ans=1ll*L.posmin*Q.negmin;
			if(L.negmin!=0)
				ans=max(ans,1ll*L.negmax*Q.posmax);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

