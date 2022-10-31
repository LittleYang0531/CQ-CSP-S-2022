#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
#define N 200005
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<class T>void write(T x) {
	if(x<0)putchar('-'),x=-x;int s[20],top=0;
	while(s[++top]=x%10,x/=10);
	while(top)putchar(s[top--]+'0');putchar(' ');
}
template<class T,class...Ts>void write(T arg,Ts...args){write(arg);write(args...);}
template<class...Ts>void print(Ts...args){write(args...);putchar('\n');}
void cer(){cerr << '\n';}
template<class T,class...Ts>void cer(T arg,Ts...args){cerr << arg << ' ';cer(args...);}
namespace MAIN{
char _st;
int n,m,K;
ll mn[N],v[N];
const ll inf = 1e18;
struct Matrix {
	ll M[3][3];
	Matrix(){for(int i=0; i<3; ++i)for(int j=0; j<3; ++j)M[i][j] = inf;}
	ll* operator [](const int &x){return M[x];}
	Matrix operator * (Matrix b)const {
		Matrix c;
		for(int i=0; i<K; ++i)
			for(int k=0; k<K; ++k)
				for(int j=0; j<K; ++j)
					c[i][j] = min(c[i][j],M[i][k]+b[k][j]);
		return c;
	}
	void out() {
		for(int i=0; i<K; ++i,putchar('\n'))
			for(int j=0; j<K; ++j)write(M[i][j]);
	}
}A[N],I,SL[N<<2],SR[N<<2];
vector<int>e[N];
int siz[N],dep[N],fa[N],top[N],son[N],dfn[N],idx,fp[N];
void dfs1(int x,int F) {
	siz[x] = 1;dep[x] = dep[F]+1;fa[x] = F;
	for(int y:e[x])if(y != F) {
		dfs1(y,x);siz[x] += siz[y];
		if(siz[y] > siz[son[x]])son[x] = y;
	}
}
void pushup(int v) {
	SL[v] = SL[v<<1]*SL[v<<1|1];
	SR[v] = SR[v<<1|1]*SR[v<<1];
}
void build(int v,int l,int r) {
	if(l == r)return SL[v] = SR[v] = A[fp[l]],void();
	int mid = l+r>>1;build(v<<1,l,mid);build(v<<1|1,mid+1,r);
	pushup(v);
}
Matrix queryL(int v,int l,int r,int L,int R) {
	if(R < l || r < L)return I;
	if(L <= l && r <= R)return SL[v];
	int mid = l+r>>1;
	return queryL(v<<1,l,mid,L,R)*queryL(v<<1|1,mid+1,r,L,R);
}
Matrix queryR(int v,int l,int r,int L,int R) {
	if(R < l || r < L)return I;
	if(L <= l && r <= R)return SR[v];
	int mid = l+r>>1;
	return queryR(v<<1|1,mid+1,r,L,R)*queryR(v<<1,l,mid,L,R);
}
void dfs2(int x,int tp) {
	top[x] = tp;dfn[x] = ++idx;fp[idx] = x;
	if(son[x])dfs2(son[x],tp);
	for(int y:e[x])if(!top[y])dfs2(y,y);
}
char _ed;
int main() {
	cer("Memory:",(&_st-&_ed)>>20);
	file("transmit");
	read(n);read(m);read(K);
	for(int i=1; i<=n; ++i)read(v[i]);
	for(int i=1,x,y; i<n; ++i)read(x),read(y),e[x].push_back(y),e[y].push_back(x);
	for(int i=1; i<=n; ++i) {
		mn[i] = 1e18;
		for(int y:e[i])mn[i] = min(mn[i],v[y]);
	}
	for(int i=0; i<K; ++i)I[i][i] = 0;
	for(int i=1; i<=n; ++i) {
		if(K == 1)A[i][0][0] = v[i];
		if(K == 2)A[i][0][0] = v[i],A[i][0][1] = 0,A[i][1][0] = v[i],A[i][1][1] = inf;
		if(K == 3){
			A[i][0][0] = v[i],A[i][0][1] = 0,A[i][0][2] = inf;
			A[i][1][0] = v[i],A[i][1][1] = mn[i],A[i][1][2] = 0;
			A[i][2][0] = v[i],A[i][2][1] = inf,A[i][2][2] = inf;
		}
	}
	dfs1(1,0);dfs2(1,1);build(1,1,n);
	while(m--) {
		int x,y;read(x);read(y);
		Matrix u = I,v = I;
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) {
				v = queryL(1,1,n,dfn[top[y]],dfn[y])*v;
				y = fa[top[y]];
			}
			else {
				u = u*queryR(1,1,n,dfn[top[x]],dfn[x]);
				x = fa[top[x]];
			}
		}
		if(x != y) {
			if(dep[x] > dep[y])u = u*queryR(1,1,n,dfn[y],dfn[x]);
			else v = queryL(1,1,n,dfn[x],dfn[y])*v;
		}else u = u*A[x];
		print((u*v)[K-1][0]);
	}
	return 0;
}
}
int main(){return MAIN::main();}
