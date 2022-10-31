#include<bits/stdc++.h>
#define inl inline
using namespace std;
typedef long long ll;
const int N=2e5+5; const ll inf=1ll<<60;
struct E {int ne,to; }e[N*2];
int n,m,K,ec,h[N],va[N],dep[N],st[20][N];
struct mat
{
	int n,m; ll s[3][3];
	inl mat operator *(const mat &t)
	{
		mat at={n,t.m,{{0}}};
		for(int i=0;i<at.n;++i) for(int j=0;j<at.m;++j) at.s[i][j]=inf;
		for(int i=0;i<at.n;++i) for(int k=0;k<m;++k) for(int j=0;j<at.m;++j)
			at.s[i][j]=min(at.s[i][j],s[i][k]+t.s[k][j]);
		return at;
	}
}an,I,a[N],up[20][N],dw[20][N];
inl int Read()
{
	int s=0; char c; while(!isdigit(c=getchar()));
	for(;isdigit(c);c=getchar()) s=s*10+c-'0'; return s;
}
inl void Write(ll x)
{
	int c=0,s[20]; do s[++c]=x%10; while(x/=10);
	while(c) putchar(s[c--]+'0'); putchar('\n');
}
inl void Add(int x,int y)
{
	e[++ec]=(E){h[x],y}; h[x]=ec; e[++ec]=(E){h[y],x}; h[y]=ec;
}
inl void DFS(int p,int fr)
{
	dep[p]=dep[fr]+1;
	if(K==3) for(int i=h[p];i;i=e[i].ne)
		a[p].s[1][1]=min(a[p].s[1][1],1ll*va[e[i].to]);
	st[0][p]=fr; up[0][p]=a[fr]; dw[0][p]=a[p];
	for(int i=1;i<20;++i)
	{
		st[i][p]=st[i-1][st[i-1][p]];
		up[i][p]=up[i-1][st[i-1][p]]*up[i-1][p];
		dw[i][p]=dw[i-1][p]*dw[i-1][st[i-1][p]];
	}
	for(int i=h[p];i;i=e[i].ne) if(e[i].to!=fr) DFS(e[i].to,p);
}
inl mat Get(int x,int y)
{
	mat atx=I,aty=I;
	if(dep[x]>dep[y]) for(int i=19;i>=0;--i)
		if(dep[st[i][x]]>=dep[y]) atx=up[i][x]*atx, x=st[i][x];
	if(dep[y]>dep[x]) for(int i=19;i>=0;--i)
		if(dep[st[i][y]]>=dep[x]) aty=aty*dw[i][y], y=st[i][y];
	if(x==y) return aty*atx;
	for(int i=19;i>=0;--i) if(st[i][x]!=st[i][y])
		atx=up[i][x]*atx, aty=aty*dw[i][y], x=st[i][x], y=st[i][y];
	return aty*dw[0][y]*up[0][x]*atx;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=Read(); m=Read(); K=Read(); I=(mat){K,K,{{0,inf,inf},{inf,0,inf},{inf,inf,0}}};
	for(int i=1;i<=n;++i)
	{
		va[i]=Read(); a[i].n=a[i].m=K;
		for(int j=0;j<K;++j) a[i].s[0][j]=va[i];
		for(int j=1;j<K;++j) for(int k=0;k<K;++k) a[i].s[j][k]=k+1==j?0:inf;
	}
	for(int i=1;i<n;++i) Add(Read(),Read());
	for(DFS(1,0);m--;)
	{
		int x=Read(),y=Read(); an={K,1,{{va[x]},{inf},{inf}}};
		Write((Get(x,y)*an).s[0][0]);
	}
	return 0;
}
