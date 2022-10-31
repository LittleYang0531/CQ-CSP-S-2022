#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e5+5;
int n,Q,K,val[N],son[N],fa[N],siz[N],tp[N],rk[N],dfn[N],num,dep[N],f[N][20];
ll dis[N],res[2005][2005];
vector<int>g[N];
int vis[2005];
vector<pair<int,int>>g2[N];
priority_queue<pair<ll,int>>q;
struct node{
	node(){memset(dp,0x3f,sizeof dp);}
	ll dp[2][2];
}t[N<<2];
bool check(node x){
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)if(x.dp[i][j]!=inf)return 0;
	return 1;
}
node merge(node x,node y){
	if(check(x))return y;if(check(y))return x;
	node z;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					if(j||k)z.dp[i][l]=min(z.dp[i][l],x.dp[i][j]+y.dp[k][l]);
				}
			}
		}
	}return z;
}
node rev(node x){
	swap(x.dp[1][0],x.dp[0][1]);
	return x;
}
node ask(int p,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return t[p];
	int mid=l+r>>1;
	if(qr<=mid)return ask(p<<1,l,mid,ql,qr);
	if(mid<ql)return ask(p<<1|1,mid+1,r,ql,qr);
    return merge(ask(p<<1,l,mid,ql,qr),ask(p<<1|1,mid+1,r,ql,qr));
}
void build(int p,int l,int r){
	if(l==r){
		t[p].dp[1][1]=val[rk[l]],t[p].dp[0][0]=0;
		return;
	}int mid=l+r>>1;build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	t[p]=merge(t[p<<1],t[p<<1|1]);
}
int Lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}return f[x][0];
}
void dfs(int u,int topf){
	dep[u]=dep[topf]+1,dis[u]=dis[topf]+val[u],f[u][0]=topf;
	for(int i=1;i<20;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v!=topf)dfs(v,u);
	}
}
void dfs2(int u,int topf){
	siz[u]=1,fa[u]=topf,dep[u]=dep[topf]+1;
	for(auto v:g[u]){
		if(v!=topf){
			dfs2(v,u),siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
	}
}
void dfs3(int u,int topf){
	tp[u]=topf,dfn[u]=++num,rk[num]=u;
	if(son[u])dfs3(son[u],topf);
	for(auto v:g[u]){
		if(!dfn[v])dfs3(v,v);
	}
}
void solve1(){
	dfs(1,0);
	for(int i=1;i<=Q;i++){
		int u,v,lca;cin>>u>>v,lca=Lca(u,v),cout<<dis[u]+dis[v]-2*dis[lca]+val[lca]<<"\n";
	}
}
ll qry(int x,int y){
	int fx=tp[x],fy=tp[y];node l,r;
	while(fx!=fy){
		if(dep[fx]>dep[fy])l=merge(l,rev(ask(1,1,n,dfn[fx],dfn[x]))),x=fa[fx];
		else r=merge(ask(1,1,n,dfn[fy],dfn[y]),r),y=fa[fy];
		fx=tp[x],fy=tp[y];
	}
	if(dfn[x]>dfn[y])l=merge(l,rev(ask(1,1,n,dfn[y],dfn[x])));
	else r=merge(ask(1,1,n,dfn[x],dfn[y]),r);
	return merge(l,r).dp[1][1];
}
void solve2(){
	dfs2(1,0),dfs3(1,1);
	build(1,1,n);
	for(int i=1;i<=Q;i++){
		int u,v;cin>>u>>v;
		cout<<qry(u,v)<<"\n";
	}
}
void solve3(){
	dfs(1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dep[i]+dep[j]-2*dep[Lca(i,j)]<=3){
				g2[i].pb(make_pair(j,val[j]));
			}
		}
	}memset(res,0x3f,sizeof res);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		q.push(make_pair(0,i)),res[i][i]=0;
		while(q.size()){
			int u=q.top().se;q.pop();
			if(vis[u])continue;vis[u]=1;
			for(auto v:g2[u]){
				if(res[i][u]+v.se<res[i][v.fi]){
					res[i][v.fi]=res[i][u]+v.se;
					q.push(make_pair(-res[i][v.fi],v.fi));
				}
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int u,v;cin>>u>>v;
		cout<<res[u][v]+val[u]<<"\n";
	}
}
int main(){
	freopen("transmit.in","r",stdin); 
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q>>K;for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v,g[u].pb(v),g[v].pb(u);
	}
	if(K==1)solve1();else if(K==2)solve2();else solve3();
}
