#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1145141919
int n,m,q;
const int maxn=114514;
int a[maxn],b[maxn];
int amx[21][maxn],amn[21][maxn],bmx[21][maxn],bmn[21][maxn],f[21][maxn],g[21][maxn];
inline int rmq_amx(int l,int r)
{
	int k=log2(r-l+1);
	return max(amx[k][l],amx[k][r-(1<<k)+1]);
}
inline int rmq_bmx(int l,int r)
{
	int k=log2(r-l+1);
	return max(bmx[k][l],bmx[k][r-(1<<k)+1]);
}
inline int rmq_amn(int l,int r)
{
	int k=log2(r-l+1);
	return min(amn[k][l],amn[k][r-(1<<k)+1]);
}
inline int rmq_bmn(int l,int r)
{
	int k=log2(r-l+1);
	return min(bmn[k][l],bmn[k][r-(1<<k)+1]);
}
inline int rmq_f(int l,int r)
{
	int k=log2(r-l+1);
	return min(f[k][l],f[k][r-(1<<k)+1]);
}
inline int rmq_g(int l,int r)
{
	int k=log2(r-l+1);
	return max(g[k][l],g[k][r-(1<<k)+1]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)	scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
	{
		amx[0][i]=amn[0][i]=a[i];
		if(a[i]>=0)	f[0][i]=a[i];
		else	f[0][i]=INF;
		if(a[i]<=0)	g[0][i]=a[i];
		else	g[0][i]=-INF;
	}
	for(int i=1;i<=m;++i)	bmx[0][i]=bmn[0][i]=b[i];
	for(int i=1;i<=19;++i)
	{
		for(int j=1;j+(1<<i)-1<=n;++j)
		{
			amx[i][j]=max(amx[i-1][j],amx[i-1][j+(1<<(i-1))]);
			amn[i][j]=min(amn[i-1][j],amn[i-1][j+(1<<(i-1))]);
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
			g[i][j]=max(g[i-1][j],g[i-1][j+(1<<(i-1))]);
		}
		for(int j=1;j+(1<<i)-1<=m;++j)
		{
			bmx[i][j]=max(bmx[i-1][j],bmx[i-1][j+(1<<(i-1))]);
			bmn[i][j]=min(bmn[i-1][j],bmn[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=1,l1,r1,l2,r2;i<=q;++i)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ll Amx=(ll)rmq_amx(l1,r1),Amn=(ll)rmq_amn(l1,r1);
		ll Bmx=(ll)rmq_bmx(l2,r2),Bmn=(ll)rmq_bmn(l2,r2);
		ll F=(ll)rmq_f(l1,r1),G=(ll)rmq_g(l1,r1);
		ll ans=-1ll*INF*INF;
		if(Bmn>=0)
		{
			if(Amx>=0)	ans=1ll*Amx*Bmn;
			else	ans=1ll*Amx*Bmx;
		}
		else	if(Bmx<=0)
		{
			if(Amn<=0)	ans=1ll*Amn*Bmx;
			else	ans=1ll*Amn*Bmn;
		}
		else
		{
			if(F!=INF)	ans=max(1ll*F*Bmn,ans);
			if(G!=-INF)	ans=max(ans,1ll*G*Bmx);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//long long !!!
/*

10 0 5
1 9 1 9 8 1 0 -2 3 9
3 6 
5 8
1 10 
7 9
5 10


*/
