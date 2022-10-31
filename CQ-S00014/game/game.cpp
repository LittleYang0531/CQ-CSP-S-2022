#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m,q,ans1,ans2,a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(ll i=1;i<=q;i++){
		ll l1,r1,l2,r2,ans;
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1){
			ans=LLONG_MAX;
			for(ll j=l2;j<=r2;j++)ans=min(ans,a[l1]*b[j]);
			printf("%lld\n",ans);
			continue;
		}
		if(l2==r2){
			ans=-LLONG_MAX;
			for(ll j=l1;j<=r1;j++)ans=max(ans,a[j]*b[l2]);
			printf("%lld\n",ans);
			continue;
		}
		for(ll j=l1;j<=r1;j++){
		ll minn=LLONG_MAX;
			for(ll ii=l2;ii<=r2;ii++){
				minn=min(minn,a[j]*b[ii]);
			}
			ans=max(ans,minn);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

