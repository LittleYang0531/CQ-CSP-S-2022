#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,q;
int a[N],b[N];
int f1[N][20][2],f2[N][20][2];//0 minv,1 maxv
int cl[N][20][2];//0负数 1正数 接近 0
int lg[N];
int solve(int a,int b)
{
	if(a<=0&&b<=0)return max(a,b);
	if(a<=0)return a;
	if(b<=0)return b;
	return min(a,b);
}
int solve2(int a,int b)
{
	if(a>=0&&b>=0)return min(a,b);
	if(a>=0)return a;
	if(b>=0)return b;
	return max(a,b);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int sum=2;
	for(int i=1;i<N;i++)
	{
		lg[i]=lg[i-1];
		if(i==sum)sum*=2,lg[i]++;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),f1[i][0][0]=f1[i][0][1]=cl[i][0][0]=cl[i][0][1]=a[i];
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),f2[i][0][0]=f2[i][0][1]=b[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			int k=i+(1<<(j-1));
			f1[i][j][0]=min(f1[i][j-1][0],f1[k][j-1][0]);
			f1[i][j][1]=max(f1[i][j-1][1],f1[k][j-1][1]);
			cl[i][j][0]=solve(cl[i][j-1][0],cl[k][j-1][0]);
			cl[i][j][1]=solve2(cl[i][j-1][1],cl[k][j-1][1]);
		}
	for(int j=1;(1<<j)<=m;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			int k=i+(1<<(j-1));
			f2[i][j][0]=min(f2[i][j-1][0],f2[k][j-1][0]);
			f2[i][j][1]=max(f2[i][j-1][1],f2[k][j-1][1]);
		}
	int l,r,l2,r2,t,t2,k,k2,f2max,f2min,x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&l,&r,&l2,&r2);
		t=lg[r-l+1],k=r-(1<<t)+1;
		t2=lg[r2-l2+1],k2=r2-(1<<t2)+1;
		f2max=max(f2[l2][t2][1],f2[k2][t2][1]);
		f2min=min(f2[l2][t2][0],f2[k2][t2][0]);
		if(f2min<0&&f2max>0)
		{
			x=solve(cl[l][t][0],cl[k][t][0]);
			y=solve2(cl[l][t][1],cl[k][t][1]);
			if(x==0||y==0)
			printf("%lld\n",0ll);
			else if(x<0&&y>0)
			printf("%lld\n",max(1ll*x*f2max,1ll*y*f2min));
			else if(x<0)
			printf("%lld\n",1ll*x*f2max);
			else if(x>0)
			printf("%lld\n",1ll*x*f2min);
		}
		else if(f2max<=0)
		{
			x=min(f1[l][t][0],f1[k][t][0]);
			if(x<=0)
			printf("%lld\n",1ll*x*f2max);
			else 
			printf("%lld\n",1ll*x*f2min);
		}
		else if(f2min>0)
		{
			x=max(f1[l][t][1],f1[k][t][1]);
			if(x>=0)
			printf("%lld\n",1ll*x*f2min);
			else 
			printf("%lld\n",1ll*x*f2max);
		}
	}
	return 0;
}
