#include<bits/stdc++.h>
using namespace std;

struct op
{
	int l,r;
	long long minn;
}t[1014][5010];
int n,g,q;	
long long a[1014],b[1014],c[1014][1014];

void biuld(int l, int r, int m, int x)
{
	if(l>=r)
	{
		t[x][m].l=l;
		t[x][m].r=r;
		t[x][m].minn=c[x][l];
		return;
	}
	t[x][m].l=l;
	t[x][m].r=r;
	int mid=(l+r)>>1;
	biuld(l,mid,m<<1,x);
	biuld(mid+1,r,m<<1|1,x);
	t[x][m].minn=min(t[x][m<<1].minn,t[x][m<<1|1].minn);
}

long long fin(int x, int l, int r, int m)
{
	if(l<=t[x][m].l&&r>=t[x][m].r)
	{
//	if(x==1)printf("%d %d %d %d\n",t[x][m].minn,m,t[x][m].l,t[x][m].r);
		return t[x][m].minn;
	}
	int mid=t[x][m].l+t[x][m].r>>1;
	if(mid>=r) return fin(x,l,r,m<<1);
	else if(mid+1<=l) return fin(x,l,r,m<<1|1);
	return min(fin(x,l,r,m<<1),fin(x,l,r,m<<1|1));
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&g,&q);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<=g; i++) scanf("%lld",&b[i]);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=g; j++)
		{
			c[i][j]=a[i]*b[j];
//			printf("%lld ", c[i][j]);
		}
//		printf("e\n");
	}
	for(int i=1; i<=n; i++) biuld(1,g,1,i);
	int l1,r1,l2,r2;
//		printf("eeeeeeeeeeeeee\n");
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long minn=-0x3f3f3f3f3f3f3f3f;
		for(int i=l1; i<=r1; i++)
		{
			minn=max(fin(i,l2,r2,1),minn);
		}
		printf("%lld\n",minn);
	}
	return 0;
}
