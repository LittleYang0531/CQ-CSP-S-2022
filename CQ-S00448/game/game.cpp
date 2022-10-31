#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q,ma[10005],mb[10005];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",ma+i);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",mb+i);
	}
	while(q--){
		priority_queue<ll>bi2,sm2;
		ll l1,l2,r1,r2,ans=-0x7ffffffffff;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		for(int i=l2;i<=r2;i++)bi2.push(mb[i]),sm2.push(-mb[i]);
		for(int i=l1;i<=r1;i++){
			ans=max(ans,min(ma[i]*bi2.top(),ma[i]*sm2.top()*-1));
		}
		cout<<ans<<endl;
	}
	return 0;
}

