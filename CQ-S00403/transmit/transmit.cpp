#include<bits/stdc++.h>
//Ô¤¼Æ£º64 
#define ll long long
using namespace std;
const ll N=1e6+2,INF=1e18,T=32;
ll dis[N],v[N],n,Q,k,d[N],t,f[N][T],dp[N][2];
ll hd[N],nxt[N],to[N],cnt,x,y;
void add(ll x,ll y){
	to[++cnt]=y;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
}
void dfs(ll x,ll fa){
	dis[x]=dis[fa]+v[x];
	d[x]=d[fa]+1;
	for(ll i=1;i<=t;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(ll i=hd[x];i;i=nxt[i]){
		ll y=to[i];
		if(y==fa) continue;
		f[y][0]=x;
		dfs(y,x);
	}
}
ll LCA(ll x,ll y){
	if(d[x]<d[y]) swap(x,y);
	for(ll i=t;i>=0;i--){
		if(d[f[x][i]]>=d[y]){
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(ll i=t;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i],y=f[x][i];
		}
	}
	return f[x][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&Q,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	for(ll i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y),add(y,x);
	}
	if(k==1){
		dfs(1,0);
		while(Q--){
			scanf("%lld%lld",&x,&y);
			ll lca=LCA(x,y);
			printf("%lld\n",dis[x]+dis[y]-2*dis[lca]+v[lca]);
		}
	}else/*if(k==2)*/{
		dfs(1,0);
		while(Q--){
			scanf("%lld%lld",&x,&y);
			ll lca=LCA(x,y);
			memset(dp,0,sizeof(dp));
			dp[x][0]=INF;dp[x][1]=v[x];
			dp[y][0]=INF;dp[y][1]=v[y];
			ll son=x;
			for(ll i=x;i;i=f[i][0]){
				if(i==x) continue;
				dp[i][0]=dp[son][1];
				dp[i][1]=min(dp[son][0],dp[son][1])+v[i];
				if(i==lca) break;
				son=i;
			}
			son=y;
			for(ll i=y;i;i=f[i][0]){
				if(i==y) continue;
				if(i==lca){
					dp[i][0]+=dp[son][1];
					dp[i][1]+=min(dp[son][0],dp[son][1]);
					break;
				}
				dp[i][0]=dp[son][1];
				dp[i][1]=min(dp[son][0],dp[son][1])+v[i];
				son=i;
			}
			if(lca==x||lca==y) printf("%lld\n",dp[lca][1]);
			else printf("%lld\n",min(dp[lca][0],dp[lca][1]));
		}
	}
	return 0;
}
