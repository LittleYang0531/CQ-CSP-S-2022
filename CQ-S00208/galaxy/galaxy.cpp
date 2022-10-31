#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m;
ll head[N],cnt,use[N];
struct node{
	ll nxt,v,val;
}tree[N];
vector<ll> d[N],dd[N];
void add(ll x,ll y){
	tree[++cnt].v=y,d[y].push_back(cnt),dd[y].push_back(x),tree[cnt].val=1,++use[x],tree[cnt].nxt=head[x],head[x]=cnt;
}
void ud(ll x,ll y,ll val){
	use[x]+=(val?1:-1);
	for(ll i=head[x];i;i=tree[i].nxt) if(tree[i].v==y){ tree[i].val=val; return; }
}
void fx(ll x,ll val){
	for(ll i=0;i<d[x].size();++i){
		if(tree[d[x][i]].val&&!val) --use[dd[x][i]];
		if(!tree[d[x][i]].val&&val) ++use[dd[x][i]];
		tree[d[x][i]].val=val;
	}
}
ll dfn[N],low[N],ins[N],tot,sta[N],cntt;
ll scc,c[N],num[N];
void tarjan(ll x){
	dfn[x]=low[x]=++tot;
	ins[x]=true,sta[++cntt]=x;
	for(ll i=head[x],y;i;i=tree[i].nxt){
		if(!tree[i].val) continue;
		if(!dfn[y=tree[i].v]) tarjan(y),low[x]=min(low[x],low[y]);
		else if(ins[y]) low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		ll y; ++scc;
		do{
			y=sta[cntt--],c[y]=scc,++num[scc];
		}while(y!=x);
	}
}
void ck(){
	bool flag=false;
	for(ll i=1;i<=n;++i){
		dfn[i]=low[i]=ins[i]=num[i]=0;
		if(use[i]!=1){
			printf("NO\n");
			return ;
		}
	}
	tot=cntt=scc=0;
	for(ll i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	for(ll x=1;x<=n&&!flag;++x)
		if(num[c[x]]==1){
			
			ll now=0;
			for(ll i=head[x];i;i=tree[i].nxt){
				now+=tree[i].val;
				if(now>1){
					flag=true,printf("NO\n");
					return ;
				}
			}
		}
	printf("YES\n");
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1,u,v;i<=m;++i) scanf("%lld%lld",&u,&v),add(u,v);
	ll q,t,u,v; scanf("%lld",&q);
	while(q--){
		scanf("%lld%lld",&t,&u);
		if(t==1) scanf("%lld",&v),ud(u,v,0);
		if(t==2) fx(u,0);
		if(t==3) scanf("%lld",&v),ud(u,v,1);
		if(t==4) fx(u,1);
		ck();
	}
	return 0;
}

