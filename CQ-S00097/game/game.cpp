#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x7fffffffffffffff/2ll
#define N 100005
#define LL long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n,m,Q,l1,l2,r1,r2,l,k;
LL fax[N][55],fbx[N][55],fan[N][55],fbn[N][55],a[N],b[N],ax,an,bx,bn,maxn,minn;
bool flag1=1;
void ST()
{
	for(int i=1;i<=n;i++)
	{
		fax[i][0]=a[i];
		fan[i][0]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		fbx[i][0]=b[i];
		fbn[i][0]=b[i];
	}
	l=log2(n);
	for(int j=1;j<=l+1;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			fax[i][j]=max(fax[i][j-1],fax[i+(1<<(j-1))][j-1]);
			fan[i][j]=min(fan[i][j-1],fan[i+(1<<(j-1))][j-1]);
		}
	}
	l=log2(m);
	for(int j=1;j<=l+1;j++)
	{
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			fbx[i][j]=max(fbx[i][j-1],fbx[i+(1<<(j-1))][j-1]);
			fbn[i][j]=min(fbn[i][j-1],fbn[i+(1<<(j-1))][j-1]);
		}
	}
}
LL Askax(int l,int r)
{
	k=log2(r-l+1);
	ax=max(fax[l][k],fax[r-(1<<k)+1][k]);
	return ax;
}
LL Askan(int l,int r)
{
	k=log2(r-l+1);
	an=min(fan[l][k],fan[r-(1<<k)+1][k]);
	return an;
}
LL Askbx(int l,int r)
{
	k=log2(r-l+1);
	bx=max(fbx[l][k],fbx[r-(1<<k)+1][k]);
	return bx;
}
LL Askbn(int l,int r)
{
	k=log2(r-l+1);
	bn=min(fbn[l][k],fbn[r-(1<<k)+1][k]);
	return bn;
}
void solve1()
{
	scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
	printf("%lld\n",Askax(l1,r1)*Askbn(l2,r2));
}
void solve()
{
	scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
	if(l1==r1)
	{
//		cout<<l1<<' '<<r1<<endl;
		if(a[l1]==0)
		{
			printf("0\n");
		}
		else if(a[l1]>0)
		{
			printf("%lld\n",a[l1]*Askbn(l2,r2));
		}
		else
		{
			printf("%lld\n",a[l1]*Askbx(l2,r2));
		}
	}
	else
	{
//		cout<<b[l2]<<endl;
		if(b[l2]==0)
		{
			printf("0\n");
		}
		else if(b[l2]>0)
		{
			printf("%lld\n",b[l2]*Askax(l1,r1));
		}
		else
		{
			printf("%lld\n",b[l2]*Askan(l1,r1));
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]<=0)
		{
			flag1=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
		if(b[i]<=0)
		{
			flag1=0;
		}
	}
	ST();
	if(flag1)
	{
		while(Q--)
		{
			solve1();
		}
		return 0;
	}
	while(Q--)
	{
		solve();
	}
	return 0;
}
/*
6 4 5
5 4 2 6 2 1
4 2 7 3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/

