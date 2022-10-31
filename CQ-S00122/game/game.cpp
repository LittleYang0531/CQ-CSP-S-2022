#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,a[200005],b[200005],p[4][2][25][200005],lg[200005],c[200005],d[200005];
int ask(int l,int r,int f1,int f2)
{
	int k=lg[r-l+1];
	if(!f2)return min(p[f1][f2][k][l],p[f1][f2][k][r-(1<<k)+1]);
	else return max(p[f1][f2][k][l],p[f1][f2][k][r-(1<<k)+1]);
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&q);
	bool flag1=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),flag1|=(a[i]<=0),lg[i]=log2(i);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]),flag1|=(a[i]<=0);
	for(int i=1;i<=n;i++)if(a[i]>=0)c[i]=a[i],d[i]=-4e18;else c[i]=4e18,d[i]=a[i];
	for(int i=1;i<=n;i++)p[0][1][0][i]=p[0][0][0][i]=a[i],p[2][0][0][i]=c[i],p[3][1][0][i]=d[i];
	for(int i=1;i<=m;i++)p[1][0][0][i]=p[1][1][0][i]=b[i];
	for(int i=1;(1<<i)<=n;i++)for(int j=1;j<=n;j++)if(j+(1<<i)-1<=n)p[0][1][i][j]=max(p[0][1][i-1][j],p[0][1][i-1][j+(1<<i-1)]);
	for(int i=1;(1<<i)<=m;i++)for(int j=1;j<=m;j++)if(j+(1<<i)-1<=m)p[1][1][i][j]=max(p[1][1][i-1][j],p[1][1][i-1][j+(1<<i-1)]);
	for(int i=1;(1<<i)<=n;i++)for(int j=1;j<=n;j++)if(j+(1<<i)-1<=n)p[0][0][i][j]=min(p[0][0][i-1][j],p[0][0][i-1][j+(1<<i-1)]);
	for(int i=1;(1<<i)<=m;i++)for(int j=1;j<=m;j++)if(j+(1<<i)-1<=m)p[1][0][i][j]=min(p[1][0][i-1][j],p[1][0][i-1][j+(1<<i-1)]);
	for(int i=1;(1<<i)<=n;i++)for(int j=1;j<=n;j++)if(j+(1<<i)-1<=n)p[2][0][i][j]=min(p[2][0][i-1][j],p[2][0][i-1][j+(1<<i-1)]);
	for(int i=1;(1<<i)<=n;i++)for(int j=1;j<=n;j++)if(j+(1<<i)-1<=n)p[3][1][i][j]=max(p[3][1][i-1][j],p[3][1][i-1][j+(1<<i-1)]);
	if(!flag1)
	{
		while(q--)
		{
			int l1,r1,l2,r2;
			scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
			printf("%lld\n",ask(l1,r1,0,1)*ask(l2,r2,1,0));
		}
		return 0;
	}
	if(n<=1e3 && m<=1e3 && q<=1e3)
	{
		while(q--)
		{
			int l1,r1,l2,r2;
			scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
			bool flag3=0,flag4=0;
			for(int i=l2;i<=r2;i++)if(b[i]>=0)flag3=1;else flag4=1;
			if(flag3==1 && flag4==1)
			{
				int ans=-4e18;
				for(int i=l1;i<=r1;i++)if(a[i]>=0)ans=max(ans,a[i]*ask(l2,r2,1,0));else ans=max(ans,a[i]*ask(l2,r2,1,1));
				printf("%lld\n",ans);
			}
			else if(flag3==1 && flag4==0)
			{
				int x=ask(l1,r1,0,1);
				if(x>=0)printf("%lld\n",x*ask(l2,r2,1,0));
				else printf("%lld\n",x*ask(l2,r2,1,1));
			}
			else if(flag3==0 && flag4==1)
			{
				int x=ask(l1,r1,0,0);
				if(x>=0)printf("%lld\n",x*ask(l2,r2,1,0));
				else printf("%lld\n",x*ask(l2,r2,1,1));
			}
		}
		return 0;
	}
	while(q--)
	{
		int l1,r1,l2,r2;
		scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
		if(l1==r1 || l2==r2)
		{
			if(l1==r1)
			{
				if(a[l1]>0)printf("%lld\n",a[l1]*ask(l2,r2,1,0));
				else printf("%lld\n",a[l1]*ask(l2,r2,1,1));
			}
			else
			{
				if(b[l2]>0)printf("%lld\n",b[l2]*ask(l1,r1,0,1));
				else printf("%lld\n",b[l2]*ask(l1,r1,0,0));
			}
			continue;
		}
		bool flag3=0,flag4=0;
		for(int i=l2;i<=r2;i++)if(b[i]>=0)flag3=1;else flag4=1;
		if(flag3==1 && flag4==1)
		{
			int res=-4e18;
			int x=ask(l1,r1,2,0),y=ask(l1,r1,3,1);
			if(x!=4e18)res=max(res,ask(l2,r2,1,0)*x);
			if(y!=-4e18)res=max(res,ask(l2,r2,1,1)*y);
			printf("%lld\n",res);
		}
		else if(flag3==1 && flag4==0)
		{
			int x=ask(l1,r1,0,1);
			if(x>=0)printf("%lld\n",x*ask(l2,r2,1,0));
			else printf("%lld\n",x*ask(l2,r2,1,1));
		}
		else if(flag3==0 && flag4==1)
		{
			int x=ask(l1,r1,0,0);
			if(x>=0)printf("%lld\n",x*ask(l2,r2,1,0));
			else printf("%lld\n",x*ask(l2,r2,1,1));
		}
	}
	return 0;
}
