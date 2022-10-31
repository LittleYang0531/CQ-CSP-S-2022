#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,a[100005],b[100005],tr1[400005],tr2[400005],i,l1,l2,r1,r2,ans;
void build(ll s,ll t,ll p){
	if(s==t){
		tr1[p] = tr2[p] = b[s];
		return ;
	}
	build(s,(s+t)/2,2*p);
	build((s+t)/2+1,t,2*p+1);
	tr1[p] = min(tr1[2*p],tr1[2*p+1]);
	tr2[p] = max(tr2[2*p],tr2[2*p+1]);
}
ll query1(ll l,ll r,ll s,ll t,ll p){
	if(l<=s&&t<=r) return tr1[p];
	ll ans = LLONG_MAX;
	if(l<=(s+t)/2) ans=min(ans,query1(l,r,s,(s+t)/2,2*p));
	if(r>(s+t)/2) ans=min(ans,query1(l,r,(s+t)/2+1,t,2*p+1));
	return ans;
}
ll query2(ll l,ll r,ll s,ll t,ll p){
	if(l<=s&&t<=r) return tr2[p];
	ll ans = LLONG_MIN;
	if(l<=(s+t)/2) ans=max(ans,query2(l,r,s,(s+t)/2,2*p));
	if(r>(s+t)/2) ans=max(ans,query2(l,r,(s+t)/2+1,t,2*p+1));
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	build(1,m,1);
	while(k--){
		ans = LLONG_MIN;
		cin>>l1>>r1>>l2>>r2;
		if(l2==r2){
			for(i=l1;i<=r1;i++) ans=max(ans,a[i]*b[l2]);
			cout<<ans<<endl;
			continue;
		}
		for(i=l1;i<=r1;i++){
			if(a[i]==0) ans=max(ans,0ll);
			else if(a[i]<0) ans=max(ans,a[i]*query2(l2,r2,1,m,1));
			else ans=max(ans,a[i]*query1(l2,r2,1,m,1));
		}
		cout<<ans<<endl;
	}
	return 0;
}

