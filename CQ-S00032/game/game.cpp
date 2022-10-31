#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const int N=1e5+5;
int n,m,Q;
ll a[N],b[N];
ll a_max[N][25],a_min[N][25],b_min[N][25],b_max[N][25];
ll a_minn[N][25],a_maxn[N][25];//a中正整数的最小值，a中负整数的最大值 
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a_max[i][0]=a_min[i][0]=a[i];
		if(a[i]>=0){
			a_minn[i][0]=a[i];
			a_maxn[i][0]=-INF;
		}
		else{
			a_minn[i][0]=INF;
			a_maxn[i][0]=a[i];
		}
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		b_max[i][0]=b_min[i][0]=b[i];
	}
	for(ll j=1;j<=log2(n);j++){
		for(ll i=1;i<=n;i++){
			a_max[i][j]=max(a_max[i][j-1],a_max[i+(1<<(j-1))][j-1]);
			a_min[i][j]=min(a_min[i][j-1],a_min[i+(1<<(j-1))][j-1]);
			a_maxn[i][j]=max(a_maxn[i][j-1],a_maxn[i+(1<<(j-1))][j-1]);
			a_minn[i][j]=min(a_minn[i][j-1],a_minn[i+(1<<(j-1))][j-1]);
		}
	}
	for(ll j=1;j<=log2(m);j++){
		for(ll i=1;i<=m;i++){
			b_max[i][j]=max(b_max[i][j-1],b_max[i+(1<<(j-1))][j-1]);
			b_min[i][j]=min(b_min[i][j-1],b_min[i+(1<<(j-1))][j-1]);
		}
	}
	while(Q--){
		ll l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ll k1=log2(r1-l1+1),k2=log2(r2-l2+1);
		ll maxn1=max(a_max[l1][k1],a_max[r1-(1<<k1)+1][k1]);
		ll minn1=min(a_min[l1][k1],a_min[r1-(1<<k1)+1][k1]);
		ll maxn2=max(b_max[l2][k2],b_max[r2-(1<<k2)+1][k2]);
		ll minn2=min(b_min[l2][k2],b_min[r2-(1<<k2)+1][k2]);
		ll ans;
		if(maxn2<=0){
			if(minn1<=0) ans=minn1*maxn2;
			else ans=minn1*minn2;
		}
		else if(minn2>=0){
			if(maxn1>=0) ans=minn2*maxn1;
			else ans=maxn2*maxn1;
		}
		else if(maxn1<=0){
			ans=maxn1*maxn2;
		}
		else if(minn1>=0){
			ans=minn1*minn2;
		}
		else{
			ll maxn=max(a_maxn[l1][k1],a_maxn[r1-(1<<k1)+1][k1]);
			ll minn=min(a_minn[l1][k1],a_minn[r1-(1<<k1)+1][k1]);
			ans=max(maxn*maxn2,minn*minn2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
