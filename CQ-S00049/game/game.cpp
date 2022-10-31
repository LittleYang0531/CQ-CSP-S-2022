#include<bits/stdc++.h>
using namespace std;
#define inf 0x7fffffffffffffff 
struct doge{int x,y;};
long long n,m,q,a[1005],b[1005],c[1005][1005],l,r,ll,rr;
void init(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
		}
	}
}
void solve(){
	while(q--){
		long long maxx=-inf;
		scanf("%lld%lld%lld%lld",&l,&r,&ll,&rr);
		for(int i=l;i<=r;i++){
			long long minn=inf;
			for(int j=ll;j<=rr;j++){
				minn=min(minn,c[i][j]);
			}
			maxx=max(minn,maxx);
		}
		cout<<maxx<<endl;
	}
	
}
int main(){
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	init();
	solve();
	return 0;
}

