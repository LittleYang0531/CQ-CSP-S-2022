#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[100005],b[100005],l1,r1,l2,r2;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		long long ans=-0x3f3f3f3f3f3f3f3f;
		for(int i=l1;i<=r1;i++){
			long long fans=0x3f3f3f3f3f3f3f3f;
			for(int j=l2;j<=r2;j++){
				fans=min(a[i]*b[j],fans);
			}
			ans=max(ans,fans);
		}
		cout<<ans<<endl;
	}	
	return 0;
}
