#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N,Q,K,dfn[200005],sz[200005],Son[200005],tot,dep[200005],Up[200005],Fa[200005];
vector <int> road[200005];
ll Cost[200005],sum[200005];
void dfs1(int u,int fa){
	sz[u]=1;Son[u]=-1;
	for(int v:road[u])
	 if(v!=fa){
	 	dep[v]=dep[u]+1;
	 	sum[v]=sum[u]+Cost[v];
	 	Fa[v]=u;
	 	dfs1(v,u);
	 	sz[u]+=sz[v];
	 	if(Son[u]==-1 || sz[Son[u]] <= sz[v])Son[u]=v;
	 }
	return ;
}
void dfs2(int u,int V){
	dfn[u]=++tot;Up[u]=V;
	if(Son[u]!=-1)dfs2(Son[u],V);
	for(int v:road[u])
	 if(!dfn[v])dfs2(v,v);
}
int LCA(int u,int v){
    while(Up[u]!=Up[v]){
    	if(dep[Up[u]]<dep[Up[v]])swap(u,v);
    	u=Fa[Up[u]];
	}
    if(dep[u]>dep[v])swap(u,v);
    return u;
}
int maxsize;
ll Min[200005];
void solve1(){
	sum[1]=Cost[1];
	dep[1]=1;dfs1(1,-1);
	dfs2(1,1);
	while(Q--){
		int S,T;
		scanf("%d%d",&S,&T);
		int P=LCA(S,T);
		printf("%lld\n",sum[S]+sum[T]-sum[P]-sum[Fa[P]]);
	}
}
const ll Inf=1e15;
struct Dot{
	ll a[3][3];
	void init(){
		for(int i=0;i<maxsize;++i)
		 for(int j=0;j<maxsize;++j)a[i][j]=Inf;
	}
}A[200005],B[200005];
Dot operator*(Dot a,Dot b){
	Dot c;c.init();
	for(int i=0;i<maxsize;++i)
	 for(int k=0;k<maxsize;++k)
	  for(int j=0;j<maxsize;++j)c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
	return c;
}
Dot res;
struct SEGMENT_TREE{
	Dot Sum[1600005],Sum1[1600005];
	void pushup(int p){
		Sum[p]=Sum[p<<1]*Sum[p<<1|1];
		Sum1[p]=Sum1[p<<1|1]*Sum1[p<<1];
	}
	void build(int p,int l,int r){
	     Sum[p].init();Sum1[p].init();
	     if(l==r){
	     	Sum[p]=Sum1[p]=B[l];
	     	return ;
		 }
		 int mid=l+r>>1;
		 build(p<<1,l,mid);
		 build(p<<1|1,mid+1,r);
		 pushup(p);
		 return ;
    }
    void Query1(int p,int l,int r,int a,int b){
    	if(a<=l&&r<=b){
    		res=res*Sum[p];
    		return ;
		}
		int mid=l+r>>1;
		if(a<=mid)Query1(p<<1,l,mid,a,b);
		if(b>mid)Query1(p<<1|1,mid+1,r,a,b);
		return ;
	}
	void Query2(int p,int l,int r,int a,int b){
		if(a<=l&&r<=b){
			res=res*Sum1[p];
			return ;
		}
		int mid=l+r>>1;
		if(b>mid)Query2(p<<1|1,mid+1,r,a,b);
		if(a<=mid)Query2(p<<1,l,mid,a,b);
		return ;
	}
}Tree;
struct Qujian{int l,r;}C[200005],C1[200005];
ll calc(int u,int v){
	res.init();
	res.a[0][0]=Cost[u];
	int Now=dfn[u];
	int Tot=0,tot1=0;
	while(Up[u]!=Up[v]){
		if(dep[Up[u]]>dep[Up[v]]){
			C[++Tot]=Qujian{dfn[Up[u]],dfn[u]};
			u=Fa[Up[u]];
		}else{
			C1[++tot1]=Qujian{dfn[Up[v]],dfn[v]};
			v=Fa[Up[v]];
		}
	}
	if(dep[u]<dep[v])C1[++tot1]=Qujian{dfn[u],dfn[v]};
	else C[++Tot]=Qujian{dfn[v],dfn[u]};
	for(int i=1;i<=Tot;++i){
		if(C[i].l>Now || C[i].r<Now)Tree.Query2(1,1,N,C[i].l,C[i].r);
		else{
			if(C[i].l==C[i].r)continue;
			if(C[i].l==Now)Tree.Query2(1,1,N,C[i].l+1,C[i].r);
			else Tree.Query2(1,1,N,C[i].l,C[i].r-1);
		}
	}
	for(int i=tot1;i>=1;--i){
		if(C1[i].l>Now || C1[i].r<Now)Tree.Query1(1,1,N,C1[i].l,C1[i].r);
		else{
			if(C1[i].l==C1[i].r)continue;
			if(C1[i].l==Now)Tree.Query1(1,1,N,C1[i].l+1,C1[i].r);
			else Tree.Query1(1,1,N,C1[i].l,C1[i].r-1);
		}
	}
	return res.a[0][0];
}
void solve2(){
	maxsize=K;
    for(int i=1;i<=N;++i){
    	if(K==2){
    		A[i].a[0][0]=A[i].a[1][0]=Cost[i];
    		A[i].a[0][1]=0LL;A[i].a[1][1]=Inf;
		}else{
			A[i].a[0][0]=A[i].a[1][0]=A[i].a[2][0]=Cost[i];
			A[i].a[0][1]=0LL;A[i].a[0][2]=Inf;
			A[i].a[1][1]=Min[i];A[i].a[1][2]=0LL;
			A[i].a[2][1]=A[i].a[2][2]=Inf;
		}
	}
	dep[1]=1;
	dfs1(1,-1);
	dfs2(1,1);
	for(int i=1;i<=N;++i)B[dfn[i]]=A[i];
	Tree.build(1,1,N);
	while(Q--){
		int U,V;
		scanf("%d%d",&U,&V);
		printf("%lld\n",calc(U,V));
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
    scanf("%d%d%d",&N,&Q,&K);
    for(int i=1;i<=N;++i)Min[i]=1e15;
    for(int i=1;i<=N;++i)scanf("%lld",&Cost[i]);
    for(int i=1;i<N;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		road[a].push_back(b);
		road[b].push_back(a);
		Min[a]=min(Min[a],Cost[b]);
		Min[b]=min(Min[b],Cost[a]);
	}
    if(K==1)solve1();
    else solve2();
	return 0;
}
