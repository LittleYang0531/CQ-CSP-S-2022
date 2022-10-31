#include<bits/stdc++.h>
#define ll long long
const ll N=2e5+10;
const ll inf=10000000000000;
using namespace std;

ll n,q,k,a[N];
vector<ll>e[N];
ll f[N][20];
ll d[N],dep[N];
ll dp[N];

void dfs(ll x,ll fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(ll i=1;i<=18;++i)f[x][i]=f[f[x][i-1]][i-1];
	d[x]=d[fa]+a[x];
	for(ll y:e[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
}

ll LCA(ll x,ll y){
	if(dep[x]<dep[y])swap(x,y);
	for(ll i=18;i>=0;--i){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y)return x;
	for(ll i=18;i>=0;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

ll DP(ll s,ll lca,ll t){
	for(ll x=s;x!=lca;x=f[x][0])dp[x]=inf;
	for(ll x=t;x!=lca;x=f[x][0])dp[x]=inf;
	dp[lca]=inf;
	dp[s]=a[s];
	ll ans=0;
	for(ll x=s;x!=lca;x=f[x][0]){
		for(ll i=1,fa=f[x][0];i<=k;fa=f[fa][0],++i){
			dp[fa]=min(dp[fa],dp[x]+a[fa]);
		}
	}
	if(dp[lca]!=inf)ans=dp[lca];
	dp[lca]=inf;
	dp[t]=a[t];
	for(ll x=t;x!=lca;x=f[x][0]){
		for(ll i=1,fa=f[x][0];i<=k;fa=f[fa][0],++i){
			dp[fa]=min(dp[fa],dp[x]+a[fa]);
		}
	}
	if(dp[lca]!=inf)ans+=dp[lca]-a[lca];
	ll s1=s,s2=s;
	for(ll x=s;x!=lca;x=f[x][0]){
		s2=s1;
		s1=x;
	}
	ll t1=t,t2=t;
	for(ll x=t;x!=lca;x=f[x][0]){
		t2=t1;
		t1=x;
	}
	if(k==2){
		ans=min(ans,dp[s1]+dp[t1]);
	}
	if(k==3){
		ans=min(ans,dp[s2]+dp[t1]);
		ans=min(ans,dp[s1]+dp[t2]);
		ans=min(ans,dp[s1]+dp[t1]);
	}
	return ans;
}

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&q,&k);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<n;++i){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	while(q--){
		ll s,t;
		scanf("%lld%lld",&s,&t);
		ll lca=LCA(s,t);
		if(k==1){
			printf("%lld\n",d[s]+d[t]-2*d[lca]+a[lca]);
			continue;
		}
		ll ans=DP(s,lca,t);
		printf("%lld\n",ans);
	}
	
	return 0;
}
