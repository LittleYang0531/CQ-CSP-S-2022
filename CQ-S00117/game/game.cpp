#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
long long ans;
int n,m,q,a[N],b[N],fl;
int da[N][20],xb[N][20],ef[20];
void ycef()
{
	ef[0]=1;
	for(int i=1;i<=19;i++)
	{
		ef[i]=ef[i-1]*2;
	}
}
void ycdaxb()
{
	ycef();
	for(int i=1;i<=n;i++)
	{
		da[i][0]=a[i];
		xb[i][0]=b[i];
	}
	for(int i=1;i<=20;i++)
	{
		if(n-ef[i]<0)break;
		for(int j=1;j<=n-ef[i-1];j++)
		{
			da[j][i]=max(da[j][i-1],da[j+ef[i-1]][i-1]);
			xb[j][i]=min(xb[j][i-1],xb[j+ef[i-1]][i-1]);
		}
	}
}
int findxb(int x,int y)
{
	int gs=y-x+1,nc=1,ns=2,xim=0x7ffffff;
	if(gs&1)
	{
		xim=min(xim,xb[x][0]);
		x=x+1;
	}
	gs>>=1;
	while(gs)
	{
		if(gs&1)
		{
			xim=min(xim,xb[x][nc]);
			x=x+ns;
		}
		gs>>=1;
		ns*=ns;
		nc++;
	}
	return xim;
}
int findda(int x,int y)
{
	int gs=y-x+1,nc=1,ns=2,xim=0;
	if(gs&1)
	{
		xim=max(xim,da[x][0]);
		x=x+1;
	}
	gs>>=1;
	while(gs)
	{
		if(gs&1)
		{
			xim=max(xim,da[x][nc]);
			x=x+ns;
		}
		gs>>=1;
		ns*=ns;
		nc++;
	}
	return xim;
}
void happyans(int l1,int r1,int l2,int r2)
{
	int ma,mi;
	ma=findda(l1,r1);
	mi=findxb(l2,r2);
	ans=mi*ma;
	printf("%lld\n",ans);
}
void happy()
{
	int g1,g2,g3,g4;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&g1,&g2,&g3,&g4);
		happyans(g1,g2,g3,g4);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=0)fl=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]<=0)fl=1;
	}
	ycdaxb();
	if(!fl)
	{
		happy();
	}
	else
	{
		long long ans,su,g;
		int g1,g2,g3,g4;
		for(int i=1;i<=q;i++)
		{
			ans=-0x7fffffffffff,su=0x7fffffffffff;
			scanf("%d%d%d%d",&g1,&g2,&g3,&g4);
			for(int j=g1;j<=g2;j++)
			{
				su=0x7ffffff;
				for(int k=g3;k<=g4;k++)
				{
					g=a[i]*b[j];
					su=min(g,su);
				}
				ans=max(ans,su);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
