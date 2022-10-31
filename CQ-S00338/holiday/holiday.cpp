#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,ans,a[2505];
bool f[2505][2505],ff,fff[2505];
void zc(ll x,ll fi,ll kk) {
	if(kk<-1)return;
	if(x==fi) {
		ff=1;
		return;
	}
	for(ll i=1; i<=n; i++)if(f[i][x])zc(i,fi,kk-1);
}
void dfs(ll x,ll k,ll cnt,ll s) {
	if(cnt==4) {
		ff=0;
		zc(x,1,k);
		if(ff)ans=max(ans,s);
		return;
	}
	for(ll i=2; i<=n; i++) {
		if(fff[i])continue;
		ff=0;
		zc(x,i,k);
		if(ff) {
			fff[i]=1;
			dfs(i,k,cnt+1,s+a[i]);
			fff[i]=0;
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=2; i<=n; i++)scanf("%lld",&a[i]);
	for(ll i=1; i<=m; i++) {
		ll x,y;
		scanf("%lld%lld",&x,&y);
		f[x][y]=1;
		f[y][x]=1;
	}
	dfs(1,k,0,0);
	printf("%lld",ans);
	return 0;
}

