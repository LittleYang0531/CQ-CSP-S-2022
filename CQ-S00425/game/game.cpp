#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1e5+5;
const int inf=0x3f3f3f3f;

int n,m,q;
int a[N],b[N],sum1[N][2],sum2[N][2];
struct SegmentTree
{
	struct Tree
	{
		int l,r,dat1,dat2,dat11,dat22;
	}t[4*N];
	
	void build(int p,int l,int r)
	{
		t[p].l=l,t[p].r=r,t[p].dat1=t[p].dat11=inf,t[p].dat2=t[p].dat22=-inf;
		if(l==r)return;
		int mid=l+r>>1;
		build(p*2,l,mid),build(p*2+1,mid+1,r);
	}
	
	void update(int p,int x,int d)
	{
		if(t[p].l==t[p].r)
		{
			t[p].dat1=t[p].dat2=d;
			if(d>0)t[p].dat11=d;
			if(d<0)t[p].dat22=d;
			return;
		}
		int mid=t[p].l+t[p].r>>1;
		if(x<=mid)update(p*2,x,d);
		else update(p*2+1,x,d);
		t[p].dat1=min(t[p*2].dat1,t[p*2+1].dat1);
		t[p].dat2=max(t[p*2].dat2,t[p*2+1].dat2);
		t[p].dat11=min(t[p*2].dat11,t[p*2+1].dat11);
		t[p].dat22=max(t[p*2].dat22,t[p*2+1].dat22);
	}
	
	int query1(int p,int l,int r)
	{
		if(l<=t[p].l&&t[p].r<=r)return t[p].dat1;
		int mid=t[p].l+t[p].r>>1,ret=inf;
		if(l<=mid)ret=min(ret,query1(p*2,l,r));
		if(r>mid)ret=min(ret,query1(p*2+1,l,r));
		return ret;
	}
	
	int query2(int p,int l,int r)
	{
		if(l<=t[p].l&&t[p].r<=r)return t[p].dat2;
		int mid=t[p].l+t[p].r>>1,ret=-inf;
		if(l<=mid)ret=max(ret,query2(p*2,l,r));
		if(r>mid)ret=max(ret,query2(p*2+1,l,r));
		return ret;
	}
	
	int query11(int p,int l,int r)
	{
		if(l<=t[p].l&&t[p].r<=r)return t[p].dat11;
		int mid=t[p].l+t[p].r>>1,ret=inf;
		if(l<=mid)ret=min(ret,query11(p*2,l,r));
		if(r>mid)ret=min(ret,query11(p*2+1,l,r));
		return ret;
	}
	
	int query22(int p,int l,int r)
	{
		if(l<=t[p].l&&t[p].r<=r)return t[p].dat22;
		int mid=t[p].l+t[p].r>>1,ret=-inf;
		if(l<=mid)ret=max(ret,query22(p*2,l,r));
		if(r>mid)ret=max(ret,query22(p*2+1,l,r));
		return ret;
	}
	
}seg[2];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum1[i][0]=sum1[i-1][0],sum1[i][1]=sum1[i-1][1];
		if(a[i]>0)sum1[i][0]++;
		else if(a[i]<0)sum1[i][1]++;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		sum2[i][0]=sum2[i-1][0],sum2[i][1]=sum2[i-1][1];
		if(b[i]>0)sum2[i][0]++;
		else if(b[i]<0)sum2[i][1]++;
	}
	seg[0].build(1,1,n),seg[1].build(1,1,m);
	//puts("qwq");
	for(int i=1;i<=n;i++)
	{
		seg[0].update(1,i,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		seg[1].update(1,i,b[i]);
	}
	while(q--)
	{
		int l,r,ll,rr;
		LL ans;
		scanf("%d%d%d%d",&l,&r,&ll,&rr);
		if(sum1[r][0]-sum1[l-1][0]==r-l+1)
		{
			if(sum2[rr][0]-sum2[ll-1][0]==rr-ll+1)
			{
				ans=1ll*seg[0].query2(1,l,r)*seg[1].query1(1,ll,rr);
			}
			else if(sum2[rr][1]-sum2[ll-1][1]==rr-ll+1)
			{
				ans=1ll*seg[0].query1(1,l,r)*seg[1].query1(1,ll,rr);
			}
			else
			{
				ans=1ll*seg[0].query1(1,l,r)*seg[1].query1(1,ll,rr);
			}
		}
		else if(sum1[r][1]-sum1[l-1][1]==r-l+1)
		{
			if(sum2[rr][0]-sum2[ll-1][0]==rr-ll+1)
			{
				ans=1ll*seg[0].query2(1,l,r)*seg[1].query2(1,ll,rr);
			}
			else if(sum2[rr][1]-sum2[ll-1][1]==rr-ll+1)
			{
				ans=1ll*seg[0].query1(1,l,r)*seg[1].query2(1,ll,rr);
			}
			else
			{
				ans=1ll*seg[0].query2(1,l,r)*seg[1].query2(1,ll,rr);
			}
		}
		else if(sum1[r][1]-sum1[l-1][1]+sum1[r][0]-sum1[l-1][0]==r-l+1)
		{
			if(sum2[rr][0]-sum2[ll-1][0]==rr-ll+1)
			{
				ans=1ll*seg[0].query2(1,l,r)*seg[1].query1(1,ll,rr);
			}
			else if(sum2[rr][1]-sum2[ll-1][1]==rr-ll+1)
			{
				ans=1ll*seg[0].query1(1,l,r)*seg[1].query2(1,ll,rr);
			}
			else
			{
				ans=max(1ll*seg[0].query11(1,l,r)*seg[1].query1(1,ll,rr),1ll*seg[0].query22(1,l,r)*seg[1].query2(1,ll,rr));
			}
		}
		else
		{
			if(sum2[rr][0]-sum2[ll-1][0]==rr-ll+1)
			{
				ans=1ll*seg[0].query2(1,l,r)*seg[1].query1(1,ll,rr);
			}
			else if(sum2[rr][1]-sum2[ll-1][1]==rr-ll+1)
			{
				ans=1ll*seg[0].query1(1,l,r)*seg[1].query2(1,ll,rr);
			}
			else
			{
				ans=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/


/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
