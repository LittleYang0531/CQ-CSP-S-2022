#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll M=5000+50;
ll n,m,q;
ll c[M][M],a[M],b[M];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=m;i++)scanf("%lld",&b[i]);
	while(q--){
		ll l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ll ans=-0x3f3f3f3f3f3f3f3f;
		for(ll i=l1;i<=r1;i++){
			ll minn=0x3f3f3f3f3f3f3f3f;
			for(ll j=l2;j<=r2;j++){
				minn=min(minn,a[i]*b[j]);
			}
			ans=max(ans,minn);
		}
		printf("%lld\n",ans);
	}
} 
