#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define fi(s) freopen(s".in","r",stdin)
#define fo(s) freopen(s".out","w",stdout)
using namespace std;
typedef long long ll;
namespace tomorinao {
char arrs;int read() {
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;}
// 注意 V 的和要开 ll 
const int maxn = 2e5+10;
vector<pair<int,int> >ve[maxn];
vector<int>g[maxn];
int n,Q,K,V[maxn],ver[maxn],B[maxn],sz[maxn],v[maxn],mc,c,dfx,v0,FA[maxn],all;
ll f[maxn][4][4],pr[maxn];int cst[maxn][4];
void add(int x,int y) {g[x].push_back(y),g[y].push_back(x);}
void fin(int x,int fa) {sz[x]=1;int mx=0;
	for(int y:g[x]) if(y^fa&&!v[y]) fin(y,x),sz[x]+=sz[y],mx=max(mx,sz[y]);
	mx=max(mx,all-sz[x]);if(mx<mc) mc=mx,c=x;
}
void siz(int x,int fa) {sz[x]=1;
	for(int y:g[x]) if(y^fa&&!v[y]) siz(y,x),sz[x]+=sz[y];
}
void csh(int x,int t) {
	B[x]=dfx,ver[x]=v0;
	if(!v[x]) {
		for(int i=0;i<=K;i++)
			for(int j=0;j<=K;j++) f[x][i][j]=1e18;
		if(t<=K) f[x][0][t]=V[x];
	}
	for(int y:g[x]) if(y^FA[x]&&!v[y]) {
		if(v[x]) ++dfx;
		FA[y]=x,csh(y,t+1);
	}
	if(!v[x]&&t<=K) {
		for(int j=0;j<=K;j++) {
			for(int i=0;i<K;i++) {
				if(i+1<K) f[FA[x]][i+1][j]=min(f[FA[x]][i+1][j],f[x][i][j]);
			}
			for(int i=0;i<K;i++)
				for(int k=0;k<=i&&i+1+k<=K;k++)
					f[FA[x]][k][j]=min(f[FA[x]][k][j],f[x][i][j]+cst[FA[x]][k]);
		}
	}
}
void dfs(int x,int t) {
	if(!v[x]) {
		for(int j=0;j<=K;j++) {
			for(int i=0;i<K;i++) {
//				f[x][0][j]=min(f[x][0][j],f[FA[x]][i][j]+V[x]);
				if(i+1<K) f[x][i+1][j]=min(f[x][i+1][j],f[FA[x]][i][j]);
			}
			for(int i=0;i<K;i++)
				for(int k=0;k<=i&&i+1+k<=K;k++)
					f[x][k][j]=min(f[x][k][j],f[FA[x]][i][j]+cst[x][k]);
		}
	}
	for(int y:g[x]) if(y^FA[x]&&!v[y]) {
		if(v[x]) ++dfx;
		dfs(y,t+1);
	}
}
void sol(int x,int fa) {
	for(pair<int,int> y:ve[x]) if(ver[x]==v0&&ver[y.first]==v0&&B[x]!=B[y.first]) {
	// 我觉得只会进入一次 
		for(int i=0;i<=K;i++)
			for(int j=0;i+j<=K;j++) {
				pr[y.second]=min(pr[y.second],f[x][0][i]+f[y.first][0][j]+(!i||!j?V[c]:0));
//				if(x==7&&y.first==4) {
//					cerr<<i<<' '<<j<<' '<<f[x][0][i]<<" "<<f[y.first][0][j]<<' '<<f[x][0][i]+f[y.first][0][j]+(!i||!j?V[c]:0)<<'\n';
//				}
			}
	}
	for(int y:g[x]) if(y^fa&&!v[y]) sol(y,x);
}
void fiz(int x,int tot) {
	mc=INT_MAX,all=tot,fin(x,0),v[x=c]=1;
	FA[x]=0;
	for(int i=0;i<=K;i++)
		for(int j=0;j<=K;j++) f[x][i][j]=1e18;
	f[x][0][0]=0;
	++dfx,++v0,csh(x,0),dfs(x,0),sol(x,0);
	siz(x,0);
	for(int y:g[x]) if(!v[y]) fiz(y,sz[y]);
}
int rt;
void get(int x,int fa,int t) {
	cst[rt][t]=min(cst[rt][t],V[x]);
	if(t==1) return;
	for(int y:g[x]) if(y^fa) get(y,x,t+1);
}
//int vd[2010][5];ll fd[2010][5];int T;
//ll ser(int x,int d) {
//	if(x==T&&d==0) return 0;
//	if(vd[x][d]==dfx) return 1e18;
//	if(vd[x][d]==dfx+1) return fd[x][d];
//	vd[x][d]=dfx,fd[x][d]=1e18;ll ans=1e18;
//	for(int y:g[x]) {
//		if(d+1<K) ans=min(ans,ser(y,d+1));
//		ans=min(ans,ser(y,0)+V[y]);
//	}
//	vd[x][d]=dfx+1,fd[x][d]=ans;
//	return ans;
//}
char arrt;void Main() {
	cerr<<fixed<<setprecision(1)<<(&arrt-&arrs)/1024./1024<<'\n';
	file("transmit");
//	file("transmit3");
	n=read(),Q=read(),K=read();
	for(int i=1;i<=n;i++) V[i]=read();
	for(int i=1;i<n;i++) add(read(),read());
	
//	if(n<=2000&&Q<=2000) {
//		for(int i=1,x;i<=Q;i++) {
//			++dfx,++dfx;
//			x=read(),T=read();
//			cout<<ser(x,0)+V[x]<<'\n';
//		}return;
//	}
	
	// brute
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=K;j++) cst[i][j]=INT_MAX;
		get(rt=i,0,0);
	}
	
	for(int i=1,x,y;i<=Q;i++) {
		pr[i]=LONG_LONG_MAX;
		x=read(),y=read();
//		ve[x].push_back(make_pair(y,i));
		ve[y].push_back(make_pair(x,i));
	}
	fiz(1,n);
	for(int i=1;i<=Q;i++) cout<<pr[i]<<'\n';
}}signed main() {tomorinao::Main();}
