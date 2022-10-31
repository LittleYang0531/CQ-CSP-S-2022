#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
typedef long long ll;
const int N=1e3+5;
ll n,m,q,a[N],b[N],c[N][N],f[N][N][15],loger[N];
ll query(ll lie,ll l,ll r){
	ll k=loger[r-l+1];
	ll x=std::min(f[lie][l][k],f[lie][r-(1ll<<k)+1][k]);
	return x;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	loger[0]=-1;
	for(ll i=1;i<=m;i++) scanf("%lld",&b[i]),loger[i]=loger[i>>1ll]+1;
	for(ll i=1;i<=n;i++) for(int j=1;j<=m;j++) c[i][j]=a[i]*b[j];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++) f[i][j][0]=c[i][j];
		for(ll k=1,j;k<=loger[m];k++){
			for(j=1;j+(1ll<<k)-1<=m;j++) f[i][j][k]=std::min(f[i][j][k-1],f[i][j+(1ll<<k-1)][k-1]);
			while(j<=m) f[i][j][k]=f[i][j][k-1],j++;
		}
	}
	ll l1,r1,l2,r2;
	while(q--){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ll ans=-1e18;
		for(ll i=l1,cnt;i<=r1;i++){
			cnt=query(i,l2,r2);
			ans=std::max(ans,cnt);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
