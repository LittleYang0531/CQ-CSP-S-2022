#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
void chmn(int &x,int y){(x>y)&&(x=y);}
//char buf[(1<<21)+1],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,q,lim;
int MN[N];
int v[N];
struct matrix{
	int a[3][3];
	matrix(){memset(a,0x3f,sizeof a);}
	matrix operator*(const matrix&X)const{
		matrix b;
		For(i,0,lim)For(j,0,lim)For(k,0,lim)
			chmn(b.a[i][k],a[i][j]+X.a[j][k]);
		return b;
	}
	void re(){a[0][0]=a[1][1]=a[2][2]=0;}
	void build(int x){
		memset(a,0x3f,sizeof a);
		a[0][0]=a[1][0]=a[2][0]=v[x];
		a[0][1]=0;a[1][2]=0;
		if(lim==2)a[1][1]=MN[x];
	}
	void output(){
		For(i,0,lim){
			For(j,0,lim)cout<<a[i][j]<<" ";puts("");
		}puts("");
	}
}U[N],D[N];
vector<int>e[N];
int top[N],fa[N],dfn[N],sz[N],son[N],dep[N],re[N],idx;
void dfs1(int x,int f){
	dep[x]=dep[f]+1;fa[x]=f;MN[x]=v[f];
	for(int to:e[x])if(to!=f){
		dfs1(to,x);
		if(sz[to]>sz[son[x]])son[x]=to;
		MN[x]=min(MN[x],v[to]);
	}sz[x]++;
}
void dfs2(int x,int tp){
	U[x].build(x);D[x].build(x);
	if(tp!=x)U[x]=U[x]*U[fa[x]],D[x]=D[fa[x]]*D[x];
	top[x]=tp;dfn[x]=++idx;re[idx]=x;
	if(son[x])dfs2(son[x],tp);
	for(int to:e[x])if(to!=fa[x]&&to!=son[x])
		dfs2(to,to);
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
matrix t1[N<<2],t2[N<<2];
struct tree{
	#define ls p<<1
	#define rs p<<1|1
	void build(int p,int l,int r){
		if(l==r){
			t1[p].build(re[l]);
			t2[p].build(re[l]);
			return;
		}int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		t1[p]=t1[ls]*t1[rs];
		t2[p]=t2[rs]*t2[ls];
	}
	matrix get1(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return t1[p];
		int mid=(l+r)>>1;
		if(mid>=nl&&mid<nr)return get1(ls,l,mid,nl,nr)*get1(rs,mid+1,r,nl,nr);
		if(mid>=nl)return get1(ls,l,mid,nl,nr);
		if(mid<nr)return get1(rs,mid+1,r,nl,nr);
	}
	matrix get2(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return t2[p];
		int mid=(l+r)>>1;
		if(mid>=nl&&mid<nr)return get2(rs,mid+1,r,nl,nr)*get2(ls,l,mid,nl,nr);
		if(mid>=nl)return get2(ls,l,mid,nl,nr);
		if(mid<nr)return get2(rs,mid+1,r,nl,nr);
	}
}T;
void getup(matrix &ans,int x,int rt){
	while(top[x]!=top[rt]){
		ans=ans*U[x];
		x=fa[top[x]];
	}
	if(dep[x]>dep[rt])ans=ans*T.get2(1,1,n,dfn[rt]+1,dfn[x]);
}
void getdown(matrix &ans,int x,int rt){
	matrix res;res.re();
	while(top[x]!=top[rt]){
		res=D[x]*res;
		x=fa[top[x]];
	}
	if(dep[x]>dep[rt])res=T.get1(1,1,n,dfn[rt]+1,dfn[x])*res;
	ans=ans*res;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
//	system("fc transmit.out transmit4.ans");return 0;
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),lim=read()-1;v[0]=1e18;
	rep(i,n)v[i]=read();
	rep(i,n-1){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,0);dfs2(1,1);
	T.build(1,1,n);
	while(q--){
		int x=read(),y=read();
		int lca=LCA(x,y);
		matrix ans;ans.a[0][lim]=0;
		getup(ans,x,lca);
		matrix ppp;ppp.build(lca);
		ans=ans*ppp;
		getdown(ans,y,lca);
		printf("%lld\n",ans.a[0][0]);
	}
	return 0;
}


