#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
#define md(a) a=(a%mod+mod)%mod
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
const int N=100005;
int n,m,Q,a[N],b[N];
struct num{int l1,r1,l2,r2;}q[N];
bool Task1()
{
	for(int i=1;i<=n;i++)if(a[i]<=0)return false;
	for(int i=1;i<=m;i++)if(b[i]<=0)return false;
	return true;
}
bool Task2()
{
	for(int i=1;i<=Q;i++)if(q[i].l1!=q[i].r1&&q[i].l2!=q[i].r2)return false;
	return true;
}
namespace Ans1
{
	int calc(int l1,int r1,int l2,int r2)
	{
		int mx=-1e18;
		for(int i=l1;i<=r1;i++)
		{
			int mn=1e18;
			for(int j=l2;j<=r2;j++)mn=min(mn,a[i]*b[j]);
			mx=max(mx,mn);
		}
		return mx;
	}
	void solve()
	{
		for(int i=1;i<=Q;i++)printf("%lld\n",calc(q[i].l1,q[i].r1,q[i].l2,q[i].r2));
	}
};
namespace Ans2
{
	int Lg[N],f[N][21],g[N][21];
	void init()
	{
		for(int i=1;i<=max(n,m);i++)Lg[i]=(int)(log2(i));
		for(int i=1;i<=n;i++)f[i][0]=a[i];
		for(int i=1;i<=m;i++)g[i][0]=b[i];
		for(int j=1;(1<<j)<=n;j++)for(int i=1;i<=n;i++)f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		for(int j=1;(1<<j)<=m;j++)for(int i=1;i<=m;i++)g[i][j]=min(g[i][j-1],g[i+(1<<j-1)][j-1]);
	}
	int askmx(int l,int r)
	{
		int nmax=Lg[r-l+1];
		return max(f[l][nmax],f[r-(1<<nmax)+1][nmax]);
	}
	int askmn(int l,int r)
	{
		int nmax=Lg[r-l+1];
		return min(g[l][nmax],g[r-(1<<nmax)+1][nmax]);
	}
	void solve()
	{
		init();
		for(int i=1;i<=Q;i++)
		{
			printf("%lld\n",askmx(q[i].l1,q[i].r1)*askmn(q[i].l2,q[i].r2));
		}
	}
};
namespace Ans3
{
	int Lg[N],f1[2][N][21],f2[2][N][21],g1[2][N][21],g2[2][N][21];
	void init()
	{
		for(int i=1;i<=max(n,m);i++)Lg[i]=(int)(log2(i));
		for(int i=1;i<=n;i++)f1[0][i][0]=f1[1][i][0]=a[i],f2[0][i][0]=f2[1][i][0]=-a[i];
		for(int i=1;i<=m;i++)g1[0][i][0]=g1[1][i][0]=b[i],g2[0][i][0]=g2[1][i][0]=-b[i];
		for(int j=1;(1<<j)<=n;j++)for(int i=1;i<=n;i++)
		{
			f1[0][i][j]=max(f1[0][i][j-1],f1[0][i+(1<<j-1)][j-1]);
			f1[1][i][j]=min(f1[1][i][j-1],f1[1][i+(1<<j-1)][j-1]);
			f2[0][i][j]=max(f2[0][i][j-1],f2[0][i+(1<<j-1)][j-1]);
			f2[1][i][j]=min(f2[1][i][j-1],f2[1][i+(1<<j-1)][j-1]);
		}
		for(int j=1;(1<<j)<=m;j++)for(int i=1;i<=m;i++)
		{
			g1[0][i][j]=max(g1[0][i][j-1],g1[0][i+(1<<j-1)][j-1]);
			g1[1][i][j]=min(g1[1][i][j-1],g1[1][i+(1<<j-1)][j-1]);
			g2[0][i][j]=max(g2[0][i][j-1],g2[0][i+(1<<j-1)][j-1]);
			g2[1][i][j]=min(g2[1][i][j-1],g2[1][i+(1<<j-1)][j-1]);
		}
	}
	int dat(int op,int a,int b){if(op==0)return max(a,b);return min(a,b);}
	int askf1(int op,int l,int r){int nmax=Lg[r-l+1];return dat(op,f1[op][l][nmax],f1[op][r-(1<<nmax)+1][nmax]);}
	int askf2(int op,int l,int r){int nmax=Lg[r-l+1];return dat(op,f2[op][l][nmax],f2[op][r-(1<<nmax)+1][nmax]);}
	int askg1(int op,int l,int r){int nmax=Lg[r-l+1];return dat(op,g1[op][l][nmax],g1[op][r-(1<<nmax)+1][nmax]);}
	int askg2(int op,int l,int r){int nmax=Lg[r-l+1];return dat(op,g2[op][l][nmax],g2[op][r-(1<<nmax)+1][nmax]);}
	int sl1(int x,int l2,int r2)
	{
		if(a[x]==0)return 0;
		if(a[x]>0)return min(-a[x]*askg2(0,l2,r2),a[x]*askg1(1,l2,r2));
		else return min(a[x]*askg1(0,l2,r2),-a[x]*askg2(1,l2,r2));
	}
	int sl2(int x,int l1,int r1)
	{
		if(b[x]==0)return 0;
		if(b[x]>0)return max(b[x]*askf1(0,l1,r1),-b[x]*askf2(1,l1,r1));
		else return max(-b[x]*askf2(0,l1,r1),b[x]*askf1(1,l1,r1));
	}
	int calc(int l1,int r1,int l2,int r2)
	{
		if(l1==r1)return sl1(l1,l2,r2);
		else return sl2(l2,l1,r1);
	}
	void solve()
	{
		init();
		for(int i=1;i<=Q;i++)printf("%lld\n",calc(q[i].l1,q[i].r1,q[i].l2,q[i].r2));
	}
	void solve2()
	{
		init();
		for(int i=1;i<=Q;i++)
		{
			int l1=q[i].l1,r1=q[i].r1,l2=q[i].l2,r2=q[i].r2,ans=-1e18;
			for(int j=l1;j<=r1;j++)ans=max(ans,sl1(j,l2,r2));
			printf("%lld\n",ans);
		}
	}
};
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=Q;i++)scanf("%lld%lld%lld%lld",&q[i].l1,&q[i].r1,&q[i].l2,&q[i].r2);
	if(n<=200&&m<=200&&Q<=200)Ans1::solve();
	else if(Task1())Ans2::solve();
	else if(Task2())Ans3::solve();
	else Ans3::solve2();
	return 0;
}
