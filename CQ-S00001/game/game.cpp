#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=2e5+5;

ll a[maxn],b[maxn];
ll f1[maxn][20],f2[maxn][20];
ll f3[maxn][20],f4[maxn][20];
ll f5[maxn][20],f6[maxn][20];//>=0&&<=0

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n,m,q;
	cin>>n>>m>>q;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=m;i++) cin>>b[i];
	for(ll i=1;i<=2*n;i++) {
		for(int j=0;j<20;j++) f1[i][j]=f5[i][j]=2e9,f2[i][j]=f6[i][j]=-2e9;
	}
	for(ll i=1;i<=2*m;i++) {
		for(int j=0;j<20;j++) f3[i][j]=2e9,f4[i][j]=-2e9;
	}
	for(ll i=1;i<=n;i++) f1[i][0]=f2[i][0]=a[i];
	for(ll i=1;i<=m;i++) f3[i][0]=f4[i][0]=b[i];
	for(ll i=1;i<=n;i++) {
		if(a[i]>=0) f5[i][0]=a[i];
		if(a[i]<=0) f6[i][0]=a[i];
	}
	for(ll j=1;(1<<j)<=n;j++) {
		for(ll i=1;i<=n;i++) {
			f1[i][j]=min(f1[i][j-1],f1[i+(1<<j-1)][j-1]);
			f2[i][j]=max(f2[i][j-1],f2[i+(1<<j-1)][j-1]);
			f5[i][j]=min(f5[i][j-1],f5[i+(1<<j-1)][j-1]);
			f6[i][j]=max(f6[i][j-1],f6[i+(1<<j-1)][j-1]);
		}
	}
	for(ll j=1;(1<<j)<=m;j++) {
		for(ll i=1;i<=m;i++) {
			f3[i][j]=min(f3[i][j-1],f3[i+(1<<j-1)][j-1]);
			f4[i][j]=max(f4[i][j-1],f4[i+(1<<j-1)][j-1]);
		}
	}
	for(ll i=1,l1,l2,r1,r2;i<=q;i++) {
		cin>>l1>>r1>>l2>>r2;
		ll k1=log2(r1-l1+1),k2=log2(r2-l2+1);
		ll ans=-2e18;
		ll mna=min(f1[l1][k1],f1[r1-(1<<k1)+1][k1]);
		ll mxa=max(f2[l1][k1],f2[r1-(1<<k1)+1][k1]);
		ll mnb=min(f3[l2][k2],f3[r2-(1<<k2)+1][k2]);
		ll mxb=max(f4[l2][k2],f4[r2-(1<<k2)+1][k2]);
		ll mn2a=min(f5[l1][k1],f5[r1-(1<<k1)+1][k1]);
		ll mx2a=max(f6[l1][k1],f6[r1-(1<<k1)+1][k1]);
		if(mxb<=0) {
			if(mna>=0) ans=mna*mnb;
			else ans=mna*mxb;
		}else if(mnb>=0) {
			if(mxa<=0) ans=mxa*mxb;
			else ans=mxa*mnb;
		}else {
			if(mn2a>=0) ans=max(ans,mn2a*mnb);
			if(mx2a<=0) ans=max(ans,mx2a*mxb);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

