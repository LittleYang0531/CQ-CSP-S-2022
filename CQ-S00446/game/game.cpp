#include<bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1,*p2;
//#define getchar (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void read(int &x)
{
	x=0;
	char ch=getchar();
	int flag=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=flag;
}
const int inf=0x7fffffff;
const int N=100000;
int n,m,q;
int a[N+5],b[N+5];
struct SegmentTree{
	struct Node{
		int pmax,pmin;
		int nmax,nmin;
		Node(int pmax=-inf,int pmin=inf,int nmax=-inf,int nmin=inf):pmax(pmax),pmin(pmin),nmax(nmax),nmin(nmin){
			
		}
		Node operator +(const Node &ano)const
		{
			return Node(max(pmax,ano.pmax),min(pmin,ano.pmin),max(nmax,ano.nmax),min(nmin,ano.nmin));
		}
	}node[N*4+5];
	void build(int num,int l,int r,int *s)
	{
		if(l==r)
		{
			if(s[l]>0)node[num]=Node(s[l],s[l]);
			else if(s[l]==0)node[num]=Node(0,0,0,0);
			else node[num]=Node(-inf,inf,s[l],s[l]);
			return ;
		}
		int mid=l+r>>1;
		build(num*2,l,mid,s);
		build(num*2+1,mid+1,r,s);
		node[num]=node[num*2]+node[num*2+1];
	}
	Node query(int num,const int &l,const int &r,int nl,int nr)
	{
		if(nl>=l&&nr<=r)return node[num];
		int mid=nl+nr>>1;
		if(r<=mid)return query(num*2,l,r,nl,mid);
		if(l>mid)return query(num*2+1,l,r,mid+1,nr);
		return query(num*2,l,r,nl,mid)+query(num*2+1,l,r,mid+1,nr);
	}
}tree[2];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	read(n),read(m),read(q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]);
	tree[0].build(1,1,n,a);
	tree[1].build(1,1,m,b);
	while(q--)
	{
		int l1,r1,l2,r2;
		read(l1),read(r1),read(l2),read(r2);
		auto x=tree[0].query(1,l1,r1,1,n);
		auto y=tree[1].query(1,l2,r2,1,m);
		long long answer=0;
		if(y.nmax==-inf)
		{
			if(x.pmax==-inf)answer=(long long)x.nmax*y.pmax;
			else answer=(long long)x.pmax*y.pmin;
		}
		else if(y.pmax==-inf)
		{
			if(x.nmin==inf)answer=(long long)x.pmin*y.nmin;
			else answer=(long long)x.nmin*y.nmax;
		}
		else
		{
			if(x.pmin==inf)answer=(long long)x.nmax*y.pmax;
			else if(x.nmax==-inf)answer=(long long)x.pmin*y.nmin;
			else answer=max((long long)x.nmax*y.pmax,(long long)x.pmin*y.nmin);
		}
		cout<<answer<<'\n';
	}
	return 0;
}
