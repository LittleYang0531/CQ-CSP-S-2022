#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q,a[100005],b[100005],l1,l2,r1,r2,ans,mn1,mn2,mx1,mx2;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=m;i++)scanf("%lld",&b[i]);
	while(q--){
		bool f=0,f1=0;
		ans=0,mn1=10000000005ll,mn2=mn1,mx1=-10000000005ll,mx2=mx1;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		for(ll i=l2;i<=r2;i++){
			if(b[i]<0)f=1;
			else f1=1;
			mx1=max(b[i],mx1);
			mn1=min(b[i],mn1);
		}
		if(f&&f1){
			ll ans1=10000000005ll,ans2=10000000005ll,c1=0,c2=0;
			bool ff=0,fff=0;
			for(ll i=l1;i<=r1;i++){
				if(a[i]>0){if(a[i]<ans1)ans1=a[i],c1=a[i],ff=1;}
				else if(abs(a[i])<ans2)ans2=abs(a[i]),c2=a[i],fff=1;
			}
			if(ff&&fff)ans=max(c1*mn1,c2*mx1);
			else if(ff)ans=c1*mn1;
			else ans=c2*mx1;
		}
		else if(f){
			bool ff=0,fff=0;
			ll mnn=10000000005ll;
			for(ll i=l1;i<=r1;i++)mnn=min(mnn,a[i]);
			ans=min(mnn*mx1,mnn*mn1);
		}
		else {
			for(ll i=l1;i<=r1;i++)mx2=max(mx2,a[i]);
			ans=mx2*mn1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
