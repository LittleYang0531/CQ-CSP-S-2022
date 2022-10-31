#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e5+10;
ll n,q,k;
ll val[maxn];
struct node{
	ll data,nxt;
}a[maxn];
ll first[maxn],cnt;
ll f[maxn][20],dp[maxn][20],dep[maxn];
void add(ll x,ll y){
	a[++cnt].data=y;
	a[cnt].nxt=first[x];
	first[x]=cnt;
}
void dfs(ll x,ll fa){
	for(ll i=1;i<=19;i++){
		f[x][i]=f[f[x][i-1]][i-1];
		dp[x][i]=dp[x][i-1]+dp[f[x][i-1]][i-1];
	}
	for(ll i=first[x];i;i=a[i].nxt){
		ll k=a[i].data;
		if(k==fa)continue;
		dep[k]=dep[x]+1;
		f[k][0]=x;
		dp[k][0]=val[k];
		dfs(k,x);
	}
}
ll LCA(ll x,ll y){
	if(dep[x]<dep[y])swap(x,y);
	ll ans=0;
	for(ll i=19;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			ans=ans+dp[x][i];
			x=f[x][i];
		}
	}
	if(x==y)return ans+dp[x][0];
	for(ll i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			ans=ans+dp[x][i]+dp[y][i];
			x=f[x][i],y=f[y][i];
		}
	}
	if(f[x][0]==1)return ans+dp[x][1]+dp[y][1]+val[f[x][0]];
	else return ans+dp[x][1]+dp[y][1]-val[f[x][0]];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(ll i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(ll i=1;i<n;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	if(k==1){
		dp[1][0]=val[1];
		for(ll i=1;i<=q;i++){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",LCA(x,y));
		}
	}
	return 0;
}

