#include<bits/stdc++.h>
#define pr pair<ll,ll>
#define fi first
#define ll long long
using namespace std;
const ll N=2505,M=1e4+5,INF=1e9;
ll n,m,k;
ll val[N];
ll head[N],cnt,ans;
struct node{
	ll nxt,v;
}tree[N<<1];
void add(ll x,ll y){
	tree[++cnt].v=y,tree[cnt].nxt=head[x],head[x]=cnt;
}
bool vis[N];
void dfs(ll x,ll now,ll cntt,ll num){
	if(now>k||cntt>4) return;
	if(x==1&&cntt==4){
		ans=max(ans,num);
		return ;
	}
	for(ll i=head[x],y;i;i=tree[i].nxt){
		y=tree[i].v;
		if(!vis[y]&&y!=1){
			vis[y]=1,dfs(y,0,cntt+1,num+val[y]),vis[y]=0;
		}
		dfs(y,now+1,cntt,num);
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=2;i<=n;++i) scanf("%lld",&val[i]);
	for(ll i=1,u,v;i<=m;++i) scanf("%lld%lld",&u,&v),add(u,v),add(v,u);
	dfs(1,0,0,0);
	printf("%lld\n",ans);
	
	return 0;
}

