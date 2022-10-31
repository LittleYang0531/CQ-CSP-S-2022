#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[2][100001][17],g[2][100001][17];//1:max 0:min
int n,m,q,i,j,k,s,l,r,mn,mx;
bool h;
int work1(int l,int r,bool o)//1:max 0:min
{
	int j=log2(r-l+1);
	if(o)return max(g[1][l][j],g[1][r-(1<<j)+1][j]);
	return min(g[0][l][j],g[0][r-(1<<j)+1][j]);
}
int work2(int l,int r,bool o)//1:max 0:min
{
	int j=log2(r-l+1);
	if(o)return max(f[1][l][j],f[1][r-(1<<j)+1][j]);
	return min(f[0][l][j],f[0][r-(1<<j)+1][j]);
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(i=1;i<=n;i++) scanf("%lld",&k),g[1][i][0]=g[0][i][0]=k;
	for(i=1;i<=m;i++) scanf("%lld",&k),f[1][i][0]=f[0][i][0]=k;
	for(i=1;i<=n;i++)
		if(g[1][i][0]<=0)h=1;
	for(i=1;i<=m;i++)
		if(f[1][i][0]<=0)h=1;
	for(j=1;j<=log2(n);j++)
	{
		for(i=1;i<=n-(1<<j-1)+1;i++) g[0][i][j]=min(g[0][i][j-1],g[0][i+(1<<j-1)][j-1]),g[1][i][j]=max(g[1][i][j-1],g[1][i+(1<<j-1)][j-1]);
		for(i=n-(1<<j-1);i<=n;i++) g[0][i][j]=g[0][i][j-1],g[1][i][j]=g[1][i][j-1];
	}
	for(j=1;j<=log2(m);j++)
	{
		for(i=1;i<=m-(1<<j-1)+1;i++) f[0][i][j]=min(f[0][i][j-1],f[0][i+(1<<j-1)][j-1]),f[1][i][j]=max(f[1][i][j-1],f[1][i+(1<<j-1)][j-1]);
		for(i=m-(1<<j-1);i<=m;i++) f[0][i][j]=f[0][i][j-1],f[1][i][j]=f[1][i][j-1];
	}
	while(q--)
	{
		scanf("%lld%lld%lld%lld",&k,&s,&l,&r);
		//ks:g:a[i] lr:f:b[i]
		if(h&&k!=s&&l!=r)
		{puts("CSP-S2022 rp++");exit(0);
		}
		if(h)
		{
			if(k==s)mx=g[1][k][0],mn=work2(l,r,(mx<0 ? 1:0));
			else mn=f[0][k][0],mx=work1(k,s,(mn<0 ? 0:1));
		}
		else mn=work2(l,r,0),mx=work1(k,s,1);
		printf("%lld\n",mx*mn);
	}
	return 0;
}
/*
6 4 2
1 9 2 5 2 6
2 3 4 1
1 5 2 3
3 4 1 3
ans:
27
10
a<0则b越大a*b越小
*/
