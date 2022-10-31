#include<bits/stdc++.h>
#define INF 1e9+1 
#define ls 2*p
#define rs 2*p+1
using namespace std;
void read(int &x)
{
	x=0;
	char s=getchar();
	int f=1;
	while(s<'0'||s>'9')
	{
		if(s=='-')
		{
			f*=-1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x*10)+(s-'0');
		s=getchar();
	}
	x*=f;
	return;
}
const int MAXN=1e5+5;
struct Seg_node{
	int mindate;
	int maxdate;
	int l,r;
};
int A[MAXN][2];
int B[MAXN][2];
int n,m,q,x,l1,r1,l2,r2;
struct Seg{
	Seg_node Tree[MAXN*4];
	int Tagx;
	int Tagy;
	void push_up(int p)
	{
		Tree[p].maxdate=max(Tree[ls].maxdate,Tree[rs].maxdate);
		Tree[p].mindate=min(Tree[ls].mindate,Tree[rs].mindate);
	}
	void Build(int p,int l,int r)
	{
		Tree[p].l=l;
		Tree[p].r=r;
		if(l==r)
		{
			if(Tagx==0)
			{
				if(A[l][Tagy]==INF)
				{
					Tree[p].maxdate=-INF;
					Tree[p].mindate=INF;
				}
				else
				{
					Tree[p].maxdate=Tree[p].mindate=A[l][Tagy];
				}
				
			}
			else
			{
				if(B[l][Tagy]==INF)
				{
					Tree[p].maxdate=-INF;
					Tree[p].mindate=INF;
				}
				else
				{
					Tree[p].maxdate=Tree[p].mindate=B[l][Tagy];
				}
			}
			return;
		}
		int mid=(l+r)>>1;
		Build(ls,l,mid);
		Build(rs,mid+1,r);
		push_up(p);
	}
	int Query_max(int p,int l,int r)
	{
		if(Tree[p].l>=l&&Tree[p].r<=r)
		{
			return Tree[p].maxdate;
		}
		int mid=(Tree[p].l+Tree[p].r)>>1;
		int Res=-INF;
		if(l<=mid)
		{
			Res=max(Res,Query_max(ls,l,r));
		}
		if(r>mid)
		{
			Res=max(Res,Query_max(rs,l,r)); 
		}
		return Res;
	}
	int Query_min(int p,int l,int r)
	{
		if(Tree[p].l>=l&&Tree[p].r<=r)
		{
			return Tree[p].mindate;
		}
		int mid=(Tree[p].l+Tree[p].r)>>1;
		int Res=INF;
		if(l<=mid)
		{
			Res=min(Res,Query_min(ls,l,r));
		}
		if(r>mid)
		{
			Res=min(Res,Query_min(rs,l,r)); 
		}
		return Res;
	}
}tree[2][2];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			tree[i][j].Tagx=i;
			tree[i][j].Tagy=j;
		}
	}
	read(n);
	read(m);
	read(q);
	for(int i=1;i<=n;i++)
	{
		read(x);
		if(x>0)
		{
			A[i][0]=x;
			A[i][1]=INF;
		 } 
		 else if(x<0)
		 {
		 	A[i][1]=x;
		 	A[i][0]=INF;
		 }
		 else
		 {
		 	A[i][0]=x;
			A[i][1]=x;
		 }
	}
	for(int i=1;i<=m;i++)
	{
		read(x);
		if(x>0)
		{
			B[i][0]=x;
			B[i][1]=INF;
		 } 
		 else if(x<0)
		 {
		 	B[i][1]=x;
		 	B[i][0]=INF;
		 }
		 else
		 {
		 	B[i][0]=x;
			B[i][1]=x;
		 }
	}
	tree[0][0].Build(1,1,n);
	tree[0][1].Build(1,1,n);
	tree[1][0].Build(1,1,m);
	tree[1][1].Build(1,1,m);
	while(q--)
	{
		read(l1);
		read(r1);
		read(l2);
		read(r2);
		int Dx1=tree[0][1].Query_min(1,l1,r1);
		int Dx2=tree[1][1].Query_min(1,l2,r2);
		int Dy2=tree[1][0].Query_max(1,l2,r2);
		int Dy1=tree[0][0].Query_max(1,l1,r1);
		if(Dx2>=0)
		{
			if(Dy1<=0)
			{
				printf("%lld\n",(long long)tree[0][1].Query_max(1,l1,r1)*tree[1][0].Query_max(1,l2,r2));
			}
			else
			{
				printf("%lld\n",(long long)tree[0][0].Query_max(1,l1,r1)*tree[1][0].Query_min(1,l2,r2));
			}
		}
		else
		{
			if(Dy2<=0)
			{
				if(Dx1>=0)
				{
					printf("%lld\n",(long long)tree[0][0].Query_min(1,l1,r1)*tree[1][1].Query_min(1,l2,r2));
				}
				else
				{
					printf("%lld\n",(long long)tree[0][1].Query_min(1,l1,r1)*tree[1][1].Query_max(1,l2,r2));
				}
			}	
			else
			{
				printf("%lld\n",max((long long)tree[0][1].Query_max(1,l1,r1)*tree[1][0].Query_max(1,l2,r2),(long long)tree[0][0].Query_min(1,l1,r1)*tree[1][1].Query_min(1,l2,r2)));
			}
		}
	}
	return 0;
}
