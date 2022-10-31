#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+15;
const int inf = 1e18;
int n,m,q,a[N],b[N];
signed main(){
	#ifndef SNOWIO
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
	#endif
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=m;i++)
		scanf("%lld",b+i);
	while(q--){
		int l,r,x,y,ma=-inf,mi;
		scanf("%lld%lld%lld%lld",&l,&r,&x,&y);
		for(int i=l;i<=r;i++){
			mi=inf;
			for(int j=x;j<=y;j++)
				mi=min(mi,a[i]*b[j]);
			ma=max(ma,mi);
		}
		printf("%lld\n",ma);
	}
	return 0;
}