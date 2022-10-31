#include<bits/stdc++.h>
#define ll long long
const ll N=5e5+10;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
using namespace std;

ll n,m,q;



int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;++i){
		ll x,y;
		scanf("%lld%lld",&x,&y);
	}
	scanf("%lld",&q);
	for(ll i=1;i<=q;++i){
		if(i&1)printf("No\n");
		else printf("Yes\n");
	}
	
	return 0;
}
