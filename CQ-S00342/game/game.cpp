#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ppp;
const int N=100005;
const int inf=1e9+7;
ll anss;
bool flag=1;
int n,m,q,l1,r1,l2,r2;
int a[N],b[N],st[2][30][N];
int sta[2][30][N],stf[2][30][N];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
void init()
{
	for(int k=0;k<=1;k++)
	{
		for(int i=1;i<=m;i++)
		st[k][0][i]=b[i];
		for(int i=1;i<=n;i++)
		{
			sta[k][0][i]=a[i];
			if(k==0)
			{
				if(a[i]<=0) stf[k][0][i]=a[i];
				else stf[k][0][i]=-inf;	
			}
			else if(k==1)
			{
				if(a[i]>0) stf[k][0][i]=a[i];
				else stf[k][0][i]=inf;
			}
		}
	}
	for(int k=0;k<=1;k++)
	for(int j=1;j<=25;j++)
	{
		for(int i=1;i<=m&&i+(1<<j)-1<=m;i++)
		{
			if(k==0) st[k][j][i]=max(st[k][j-1][i],st[k][j-1][i+(1<<(j-1))]);
			else st[k][j][i]=min(st[k][j-1][i],st[k][j-1][i+(1<<(j-1))]);
		}
		for(int i=1;i<=n&&(i+(1<<j)-1)<=n;i++)
		{
			if(k==0) sta[k][j][i]=max(sta[k][j-1][i],sta[k][j-1][i+(1<<(j-1))]);
			else sta[k][j][i]=min(sta[k][j-1][i],sta[k][j-1][i+(1<<(j-1))]);
		}
		for(int i=1;i<=n&&(i+(1<<j)-1)<=n;i++)
		{
			if(k==0) stf[k][j][i]=max(stf[k][j-1][i],stf[k][j-1][i+(1<<(j-1))]);
			else stf[k][j][i]=min(stf[k][j-1][i],stf[k][j-1][i+(1<<(j-1))]);
		}
	}
}
int query(int l,int r,int opt)
{
	int lg=log(r-l+1)/log(2);
	if(opt==1) return min(st[opt][lg][l],st[opt][lg][r-(1<<lg)+1]);
	else return max(st[opt][lg][l],st[opt][lg][r-(1<<lg)+1]);
}
int querya(int l,int r,int opt)
{
	int lg=log(r-l+1)/log(2);
	if(opt==1) return min(sta[opt][lg][l],sta[opt][lg][r-(1<<lg)+1]);
	else return max(sta[opt][lg][l],sta[opt][lg][r-(1<<lg)+1]);
}
int queryf(int l,int r,int opt)
{
	int lg=log(r-l+1)/log(2);
	if(opt==1) return min(stf[opt][lg][l],stf[opt][lg][r-(1<<lg)+1]);
	else return max(stf[opt][lg][l],stf[opt][lg][r-(1<<lg)+1]);
}
bool pppp;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	//cout<<(&pppp-&ppp)/1024.0/1024.0;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<0) flag=0;
	}
	for(int i=1;i<=m;i++)
	{
		b[i]=read();
		if(b[i]<0) flag=0;
	}
	init();
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(n<=1000&&m<=1000&&q<=1000)
		{
			ll ans=-1e18;
			for(int i=l1;i<=r1;i++)
			{
				ll res;
				if(a[i]>=0) res=1ll*a[i]*query(l2,r2,1);
				else res=1ll*a[i]*query(l2,r2,0);
				ans=max(ans,res);
			}
			printf("%lld\n",ans);
		}
		else
		{
			ll ans=-1e18;
			if(flag)
			{
				ans=1ll*querya(l1,r1,0)*query(l2,r2,1);
				printf("%lld\n",ans);
			}
			else
			{
				int qmin=query(l2,r2,1),qmax=query(l2,r2,0);
				int qamx=querya(l1,r1,0),qamn=querya(l1,r1,1);
				int qaf=queryf(l1,r1,0),qaz=queryf(l1,r1,1);
				if(qamx>=0) 
				{
					if(qmin>=0) ans=max(ans,1ll*qamx*qmin);
					else ans=max(ans,1ll*qaz*qmin);
				}
				if(qaf>-inf) 
				{
					if(qmax>=0) ans=max(ans,1ll*qaf*qmax);
					else ans=max(ans,1ll*qamn*qmax);
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
