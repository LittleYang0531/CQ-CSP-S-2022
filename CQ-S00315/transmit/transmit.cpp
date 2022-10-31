#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200003;
int n,q,k,val[maxn],head[maxn],cnt,ch[maxn<<2][2];
long long sum[maxn<<2];
struct node{int next,to;}e[maxn<<1];
void addedge(int x,int y){e[++cnt]=(node){head[x],y},head[x]=cnt;}
int fa[maxn],top[maxn],son[maxn],dep[maxn],siz[maxn],num[maxn];
void dfs_1(int x,int pre){
	fa[x]=pre,dep[x]=dep[pre]+1,siz[x]=1;
	for(int i=head[x],v;v=e[i].to,i;i=e[i].next)if(v!=fa[x]){
		dfs_1(v,x),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
void dfs_2(int x,int topp){
	top[x]=topp,num[x]=++cnt;
	if(son[x]) dfs_2(son[x],topp);
	for(int i=head[x],v;v=e[i].to,i;i=e[i].next)
		if(v!=son[x]&&v!=fa[x]) dfs_2(v,v);
}
void pushup(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
void build(int x,int lef,int rig){
	if(lef==rig) return sum[x]=val[lef],void();
	int mid=lef+rig>>1;
	build(x<<1,lef,mid),build(x<<1|1,mid+1,rig);
	pushup(x);
}
long long ask(int x,int u,int v,int lef,int rig){
	if(rig<u||lef>v) return 0;
	if(u<=lef&&rig<=v) return sum[x];
	int mid=lef+rig>>1;
	return ask(x<<1,u,v,lef,mid)+ask(x<<1|1,u,v,mid+1,rig);
}
long long query(int u,int v){
	long long ans=0;
	while(top[num[u]]!=top[num[v]]){
		if(dep[u]<dep[v]) swap(u,v);
		ans+=ask(1,num[top[u]],num[u],1,n);
		u=fa[top[u]];
	}if(dep[u]<dep[v]) swap(u,v);
	return ans+ask(1,num[u],num[v],1,n);
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;++i) scanf("%d",&val[i]);
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),addedge(u,v),addedge(v,u);
	cnt=0,dfs_1(1,0),dfs_2(1,1);build(1,1,n);
	while(q--){
		int s,t;scanf("%d%d",&s,&t);
		cout<<query(s,t)<<'\n';
	}
	return 0;
}
