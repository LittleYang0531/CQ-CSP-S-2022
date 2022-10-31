#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e4+507,Maxm=2510;
ll n,m,k,head[Maxn],tot,w[Maxn],ans,f[Maxn<<2],cnt,A[Maxn];
ll head1[Maxn<<1],tot1;
bool Map[Maxm][Maxm],vis[Maxn];
struct Edge1{
	ll v,Next;
}Edge[Maxn<<1],Edge1[Maxn<<1];
inline void add(ll u,ll v){
	Edge[++tot].Next=head[u];
	Edge[tot].v=v;
	head[u]=tot;
}
inline void NewAdd(ll u,ll v){
	Edge1[++tot1].Next=head1[u];
	Edge1[tot1].v=v;
	head1[u]=tot1;
}
void build(ll u,ll K,ll p){
	if(!Map[p][u]&&!Map[u][p]&&u!=p) add(p,u),add(u,p);
	Map[p][u]=Map[u][p]=1;
	if(K==0) return ;
	for(ll i=head1[u];i;i=Edge1[i].Next)		
		build(Edge1[i].v,K-1,p);
}
void dfs(ll u,ll L,ll W){
	if(L==0){
		memset(vis,0,sizeof vis);ll dif=0;
		for(ll i=1;i<=cnt;i++) 
			if(!vis[A[i]]) vis[A[i]]=1,dif++;
		if(dif==4) ans=max(ans,W);
		return ;
	}
	for(ll j=head[u];j;j=Edge[j].Next)
		if(L!=1)A[++cnt]=Edge[j].v,dfs(Edge[j].v,L-1,W+w[Edge[j].v]),--cnt;
		else if(Edge[j].v==1) dfs(Edge[j].v,0ll,W);		
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);	
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=2;i<=n;i++) scanf("%lld",&w[i]);
	for(ll i=1,u,v;i<=m;i++) 
		scanf("%lld%lld",&u,&v),NewAdd(u,v),NewAdd(v,u),
		Map[u][v]=Map[v][u]=1,add(u,v),add(v,u);
	for(ll i=1;i<=n;i++) build(i,k+1,i);
	dfs(1,5,0);
	printf("%lld",ans);
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
