#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,INF=0x3f3f3f3f;
int n,m,q;
int mx[N][25],mi[N][25],pmx[N][25],pmi[N][25],nmx[N][25],nmi[N][25],LG[N];
int askmax(int l,int r) {int x=LG[r-l+1]; return max(mx[l][x],mx[r-(1<<x)+1][x]);}
int askmin(int l,int r) {int x=LG[r-l+1]; return min(mi[l][x],mi[r-(1<<x)+1][x]);}
int askmaxp(int l,int r) {int x=LG[r-l+1]; return max(pmx[l][x],pmx[r-(1<<x)+1][x]);}
int askminp(int l,int r) {int x=LG[r-l+1]; return min(pmi[l][x],pmi[r-(1<<x)+1][x]);}
int askmaxn(int l,int r) {int x=LG[r-l+1]; return max(nmx[l][x],nmx[r-(1<<x)+1][x]);}
int askminn(int l,int r) {int x=LG[r-l+1]; return min(nmi[l][x],nmi[r-(1<<x)+1][x]);}
inline void read(int &x)
{
	x=0;
	int t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	x*=t;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=max(n,m);i++) LG[i]=log2(i);
	for(int i=1,x;i<=n;i++)
	{
		read(x);
		if(x>=0)
		{
			pmx[i][0]=pmi[i][0]=x;
			if(x>0) nmx[i][0]=-INF,nmi[i][0]=INF;
		}
		if(x<=0)
		{
			nmx[i][0]=nmi[i][0]=x;
			if(x<0) pmx[i][0]=-INF,pmi[i][0]=INF;
		}
	}
	for(int i=1,x;i<=m;i++) read(x),mx[i][0]=mi[i][0]=x;
	for(int j=1;1<<j<=m;j++)
		for(int i=1;i<=m-(1<<j)+1;i++)
		{
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<j-1)][j-1]);
		}
	for(int j=1;1<<j<=n;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			pmx[i][j]=max(pmx[i][j-1],pmx[i+(1<<j-1)][j-1]);
			pmi[i][j]=min(pmi[i][j-1],pmi[i+(1<<j-1)][j-1]);
			nmx[i][j]=max(nmx[i][j-1],nmx[i+(1<<j-1)][j-1]);
			nmi[i][j]=min(nmi[i][j-1],nmi[i+(1<<j-1)][j-1]);
		}
	int l1,r1,l2,r2;
	ll ans;
	while(q--)
	{
		ans=-1e18;
		read(l1),read(r1),read(l2),read(r2);
		ll Max=askmax(l2,r2),Min=askmin(l2,r2);
		if(Min>=0)
		{
			ll Maxx=askmaxp(l1,r1);
			if(Maxx!=-INF) ans=max(ans,1ll*Maxx*Min);
		}
		else
		{
			ll Minn=askminp(l1,r1);
			if(Minn!=INF) ans=max(ans,1ll*Minn*Min);
		}
		if(Max<=0)
		{
			ll Minn=askminn(l1,r1);
			if(Minn!=INF) ans=max(ans,1ll*Max*Minn);
		}
		else
		{
			ll Maxx=askmaxn(l1,r1);
			if(Maxx!=-INF) ans=max(ans,1ll*Max*Maxx);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
