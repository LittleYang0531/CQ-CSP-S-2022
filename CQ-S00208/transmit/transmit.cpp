#include<bits/stdc++.h>
#define ll long long
const ll N=2e5+5,INF=1e18;
using namespace std;
ll n,q,k,v[N],tt;
ll head[N],cnt;
struct node{
	ll nxt,v;
}tree[N<<1];
void add(ll x,ll y){
	tree[++cnt].v=y,tree[cnt].nxt=head[x],head[x]=cnt;
}
ll dis[N],fa[N][20],depth[N];
void dfs(ll x){
	for(ll i=1;i<=tt;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(ll i=head[x],y;i;i=tree[i].nxt){
		if((y=tree[i].v)==fa[x][0]) continue;
		depth[y]=depth[x]+1,fa[y][0]=x,dfs(y);
	}
}
ll lca(ll x,ll y){
	if(depth[x]>depth[y]) swap(x,y);
	for(ll i=tt;i>=0;--i) if(depth[fa[y][i]]>=depth[x]) y=fa[y][i];
	if(x==y) return x;
	for(ll i=tt;i>=0;--i) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
ll dp[N],st[N],top,son[N],ccnt;
void solve(ll x,ll y,ll l){
//	cout<<"--------"<<x<<" "<<y<<" "<<l<<endl;
	if(depth[x]<depth[y]) swap(x,y);
	ll s=x,t=y;
	top=0;
	while(1){
		dp[x]=(x==s?v[x]:INF);
		for(ll i=0;i<k&&top-i>=1;++i) dp[x]=min(dp[x],dp[st[top-i]]+v[x]);
		st[++top]=x;
//		cout<<x<<" "<<dp[x]<<endl;
		if(x==l) break;
		x=fa[x][0];
	}
	if(y==l){
		printf("%lld\n",dp[l]);
		return;
	}
	while(y!=l) son[++ccnt]=y,y=fa[y][0]; 
	for(ll id=ccnt;id;--id){
		y=son[id];
		dp[y]=INF;
		for(ll i=0;i<k&&top-i>=i;++i) dp[y]=min(dp[y],dp[st[top-i]]+v[y]);
//		cout<<y<<" "<<dp[y]<<endl;
		st[++top]=y;
	}
	printf("%lld\n",dp[y]);
}
int main(){//long long!!!!!!!!!!!
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k),tt=log2(n);
	for(ll i=1;i<=n;++i) scanf("%lld",&v[i]);
//	cout<<2222222222<<endl;
	for(ll i=1,u,v;i<n;++i) scanf("%lld%lld",&u,&v),add(u,v),add(v,u);
	dis[1]=v[1],dfs(1);
//	cout<<1111111<<endl;
	for(ll i=1,x,y;i<=q;++i){
		scanf("%lld%lld",&x,&y);
		ll l=lca(x,y);
		if(depth[x]+depth[y]-(depth[l]<<1)<=k){	
			printf("%lld\n",v[x]+v[y]);
			continue;
		}
		solve(x,y,l);
	}
	return 0;
}

