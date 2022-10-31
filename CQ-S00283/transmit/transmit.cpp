#include<bits/stdc++.h>
#define int long long
#define INF 0x7fffffff
using namespace std;
const unsigned int N=2e5+15;
int n,q,k,w[N],v[N],pre[N];
int dep[N],fa[N];
int son[N],top[N],dfn[N],rnk[N],tot;
int num_edge,head[N];
struct Edge{
	int next;
	int to;
}e[N*3];
struct Segment_Tree{
	int l;
	int r;
	int val;
}a[N*4];
inline void read(int &x){
	x=0;
	int y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=y;
}
void add_edge(int from,int to){
	e[++num_edge].next=head[from];
	e[num_edge].to=to;
	head[from]=num_edge;
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	w[x]=1;
	for(register int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa[x])
		continue;
		dfs(v,x);
		w[x]+=w[v];
		if(w[v]>w[son[x]])
		v=son[x];
	}
}
void dfs2(int x,int ntop){
	dfn[x]=++tot;
	rnk[dfn[x]]=x;
	//printf("dfn[%d]=%d\n",x,dfn[x]);
	top[x]=ntop;
	if(son[x])
	dfs(son[x],ntop);
	for(register int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa[x]&&v!=son[x])
		dfs(v,v);
	}
}
void pushup(int x){
	a[x].val=min(a[x<<1].val,a[x<<1|1].val);
}
void build(int x,int l,int r){
	a[x].l=l;
	a[x].r=r;
	if(l==r){
		a[x].val=v[rnk[l]];
		//printf("%d=%d\n",l,v[rnk[l]]);
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
int query1(int x,int l,int r){
	if(l<=a[x].l&&r>=a[x].r)
	return a[x].val;
	int res=INF;
	int mid=(a[x].l+a[x].r)>>1;
	if(l<=mid)
	res=min(res,query1(x<<1,l,r));
	if(r>mid)
	res=min(res,query1(x<<1|1,l,r));
	return res;
}
int query(int x,int y){
	int res=INF;
	while(top[x]!=top[y]){
		if(dep[x]<dep[y])
		swap(x,y);
		res=min(res,query1(1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
	swap(x,y);
	res=min(res,query1(1,dfn[x],dfn[y]));
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n);
	read(q);
	read(k);
	for(register int i=1;i<=n;i++)
	read(v[i]);
	for(register int i=1;i<=n-1;i++){
		int u,v;
		read(u);
		read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dep[1]=0;
	dfs(1,1);
	dfs2(1,1);
	build(1,1,n);
	while(q--){
		int x,y;
		read(x);
		read(y);
		printf("%lld\n",query(x,y));
	}
	return 0;
}
//I Love XiaoTing!
