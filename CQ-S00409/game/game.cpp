#include<bits/stdc++.h>
#define inl inline
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,Q,lg[N],aa[20][N],ai[20][N],ba[20][N],bi[20][N],mz[20][N],mf[20][N],b0[N];
inl int Read()
{
	int s=0,f=1; char c; while(!isdigit(c=getchar())) c=='-'&&(f=-f);
	for(;isdigit(c);c=getchar()) s=s*10+c-'0'; return s*f;
}
inl void Write(ll x)
{
	int c=0,s[20]; if(x<0) putchar('-'), x=-x; do s[++c]=x%10; while(x/=10);
	while(c) putchar(s[c--]+'0'); putchar('\n');
}
inl int Getaa(int l,int r) {int k=lg[r-l+1];return max(aa[k][l],aa[k][r-(1<<k)+1]); }
inl int Getai(int l,int r) {int k=lg[r-l+1];return min(ai[k][l],ai[k][r-(1<<k)+1]); }
inl int Getmz(int l,int r) {int k=lg[r-l+1];return min(mz[k][l],mz[k][r-(1<<k)+1]); }
inl int Getmf(int l,int r) {int k=lg[r-l+1];return max(mf[k][l],mf[k][r-(1<<k)+1]); }
inl int Getba(int l,int r) {int k=lg[r-l+1];return max(ba[k][l],ba[k][r-(1<<k)+1]); }
inl int Getbi(int l,int r) {int k=lg[r-l+1];return min(bi[k][l],bi[k][r-(1<<k)+1]); }
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=Read(); m=Read(); Q=Read(); lg[1]=0;
	for(int i=2,ed=max(n,m);i<=ed;++i) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;++i)
	{
		aa[0][i]=ai[0][i]=Read();
		mz[0][i]=aa[0][i]>=0?aa[0][i]:INT_MAX;
		mf[0][i]=aa[0][i]<=0?aa[0][i]:-INT_MAX;
	}
	for(int i=1;i<20;++i) for(int j=1;j<=n-(1<<i)+1;++j)
	{
		aa[i][j]=max(aa[i-1][j],aa[i-1][j+(1<<(i-1))]);
		ai[i][j]=min(ai[i-1][j],ai[i-1][j+(1<<(i-1))]);
		mz[i][j]=min(mz[i-1][j],mz[i-1][j+(1<<(i-1))]);
		mf[i][j]=max(mf[i-1][j],mf[i-1][j+(1<<(i-1))]);
	}
	for(int i=1;i<=m;++i) ba[0][i]=bi[0][i]=Read(), b0[i]=b0[i-1]+(!ba[0][i]);
	for(int i=1;i<20;++i) for(int j=1;j<=m-(1<<i)+1;++j)
	{
		ba[i][j]=max(ba[i-1][j],ba[i-1][j+(1<<(i-1))]);
		bi[i][j]=min(bi[i-1][j],bi[i-1][j+(1<<(i-1))]);
	}
	for(ll an;Q--;Write(an))
	{
		int la=Read(),ra=Read(),lb=Read(),rb=Read();
		int ba=Getba(lb,rb),bi=Getbi(lb,rb); an=(b0[rb]-b0[lb-1])?0:LONG_LONG_MAX;
		if(bi>=0) {int aa=Getaa(la,ra); an=min(an,1ll*(aa>0?bi:ba)*aa); continue; }
		if(ba<=0) {int ai=Getai(la,ra); an=min(an,1ll*(ai<0?ba:bi)*ai); continue; }
		an=min(an,max(1ll*bi*Getmz(la,ra),1ll*ba*Getmf(la,ra)));
	}
	return 0;
}
