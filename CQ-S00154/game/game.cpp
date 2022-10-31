#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	int f=1;x=0;
	char c=getchar();
	if(c=='-') f=-1;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}
inline void print(long long x)
{
	if(x<0) putchar('-'),x=-x;
	char c[100];int tot=0;
	do{c[++tot]=x%10+'0',x/=10;}while(x);
	while(tot) putchar(c[tot--]);
	putchar('\n');
}
#define ls u<<1
#define rs u<<1|1
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
int n,m,q;
int a[2][N];
ll ans;
struct tree
{
	int l,r;
	int maxn,minn;
	bool had0;
	int d1,d2;
}t[2][4*N];
void calc(tree &T,tree L,tree R)
{
	T.maxn=max(L.maxn,R.maxn);
	T.minn=min(L.minn,R.minn);
	T.had0=(L.had0||R.had0);
	T.d1=max(L.d1,R.d1);
	T.d2=min(L.d2,R.d2);
}
void pushup(int id,int u)
{
	calc(t[id][u],t[id][ls],t[id][rs]);
}
void build(int id,int u,int l,int r)
{
	t[id][u]={l,r,-inf,inf,0,-inf,inf};
	if(l==r)
	{
		t[id][u].maxn=t[id][u].minn=a[id][l];
		if(a[id][l]==0) t[id][u].had0=1;
		else if(a[id][l]<0) t[id][u].d1=a[id][l];
		else t[id][u].d2=a[id][l];
		return;
	}
	int mid=(l+r)/2;
	build(id,ls,l,mid);
	build(id,rs,mid+1,r);
	pushup(id,u);
}
tree query(int id,int u,int l,int r)
{
	if(l<=t[id][u].l && t[id][u].r<=r)
		return t[id][u];
	int mid=(t[id][u].l+t[id][u].r)/2;
	if(l<=mid && mid<r)
	{
		tree res;
		tree res1=query(id,ls,l,r);
		tree res2=query(id,rs,l,r);
		calc(res,res1,res2);
		return res;
	}
	if(l<=mid) return query(id,ls,l,r);
	return query(id,rs,l,r);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);read(m);read(q);
	for(int i=1;i<=n;i++) read(a[0][i]);
	for(int i=1;i<=m;i++) read(a[1][i]);
	build(0,1,1,n);build(1,1,1,m);
	while(q--)
	{
		int l1,r1,l2,r2;
		read(l1);read(r1);read(l2);read(r2);
		tree res1=query(0,1,l1,r1);
		tree res2=query(1,1,l2,r2);
		if(res1.maxn<0)
		{
			if(res2.maxn<0)
				ans=(ll)res1.minn*res2.maxn;
			else
				ans=(ll)res1.maxn*res2.maxn;
		}
		else if(res1.minn>0)
		{
			if(res2.minn>0)
				ans=(ll)res1.maxn*res2.minn;
			else
				ans=(ll)res1.minn*res2.minn;
		}
		else
		{
			if(res2.maxn<0)
				ans=(ll)res1.minn*res2.maxn;
			else if(res2.minn>0)
				ans=(ll)res1.maxn*res2.minn;
			else
			{
				if(res1.had0)
					ans=0;
				else
				{
					if(res2.had0)
					{
						if(res2.maxn==0 || res2.minn==0)
							ans=0;
						else
							ans=max((ll)res1.d1*res2.maxn,(ll)res1.d2*res2.minn);
					}
					else
						ans=max((ll)res1.d1*res2.maxn,(ll)res1.d2*res2.minn);
				}
			}
		}
		print(ans);
	}
	return 0;
}
