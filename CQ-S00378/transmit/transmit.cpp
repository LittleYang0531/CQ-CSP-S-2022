#include<bits/stdc++.h>//JZM yyds!!
#define ll long long
#define lll __int128
#define uns unsigned
#define fi first
#define se second
#define IF (it->fi)
#define IS (it->se)
#define lowbit(x) ((x)&-(x))
#define END putchar('\n')
#define inline jzmyyds
using namespace std;
const int MAXN=2e5+5;
const ll INF=1e18;
ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
int ptf[50],lpt;
void print(ll x,char c='\n'){
	if(x<0)putchar('-'),x=-x;
	ptf[lpt=1]=x%10;
	while(x>9)x/=10,ptf[++lpt]=x%10;
	while(lpt)putchar(ptf[lpt--]^48);
	if(c>0)putchar(c);
}
int n,m,K;
ll val[MAXN],mv[MAXN];
vector<int>G[MAXN];
int fa[MAXN],siz[MAXN],hs[MAXN],dep[MAXN];
int hd[MAXN],IN,tp[MAXN];
struct mat{
	ll a[3][3];mat(){}
	mat(ll x){
		for(int i=0;i<K;i++)for(int j=0;j<K;j++)a[i][j]=INF;
		for(int i=0;i<K;i++)a[i][i]=x;
	}
	mat operator*(const mat&b)const{
		mat c(INF);
		for(int i=0;i<K;i++)
			for(int k=0;k<K;k++)if(a[i][k]<INF)
				for(int j=0;j<K;j++)
					c.a[i][j]=min(c.a[i][j],a[i][k]+b.a[k][j]);
		return c;
	}
}cg[MAXN],g[MAXN];//ix
struct zkw{
	mat f[MAXN*3];int p;
	void init(int n){
		for(p=1;p<n+2;p<<=1);
		for(int i=1;i<=n;i++)f[p^i]=cg[i];
		for(int i=(p^n)>>1;i;i--)f[i]=f[i<<1|1]*f[i<<1];
	}
	mat query(int l,int r){
		mat rl(0),rr=rl;
		for(l=p^(l-1),r=p^(r+1);l^1^r;l>>=1,r>>=1){
			if(~l&1)rl=f[l^1]*rl;
			if(r&1)rr=rr*f[r^1];
		}return rr*rl;
	}
}T;
void dfs1(int x){
	siz[x]=1,hs[x]=0,mv[x]=val[x],dep[x]=dep[fa[x]]+1;
	for(int v:G[x]){
		mv[x]=min(mv[x],val[v]);
		if(v==fa[x])continue;
		fa[v]=x,dfs1(v),siz[x]+=siz[v];
		if(siz[v]>siz[hs[x]])hs[x]=v;
	}
}
void dfs2(int x){
	hd[x]=++IN;
	mat in(INF);
	in.a[0][0]=in.a[1][0]=in.a[2][0]=val[x];
	in.a[0][1]=in.a[1][2]=0;
	if(K>2)in.a[1][1]=mv[x];
	cg[hd[x]]=in;
	if(x==hs[fa[x]])tp[x]=tp[fa[x]],g[x]=in*g[fa[x]];
	else tp[x]=x,g[x]=in;
	if(hs[x])dfs2(hs[x]);
	for(int v:G[x])if(v!=fa[x]&&v!=hs[x])dfs2(v);
}
ll getans(int u,int v){
	mat ru(INF),rv(INF);
	ru.a[0][K-1]=rv.a[0][K-1]=0;
	while(tp[u]^tp[v]){
		if(dep[tp[u]]>dep[tp[v]])ru=ru*g[u],u=fa[tp[u]];
		else rv=rv*g[v],v=fa[tp[v]];
	}
	if(dep[u]>dep[v])ru=ru*T.query(hd[v],hd[u]);
	else rv=rv*T.query(hd[u],hd[v]);
	ll res=INF+INF;
	for(int i=0;i<K;i++)
		for(int j=K-i-1;j>=0;j--)
			res=min(res,ru.a[0][i]+rv.a[0][j]);
	return res;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs1(1),dfs2(1),T.init(n);
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		print(getans(u,v));
	}
	return 0;
}
