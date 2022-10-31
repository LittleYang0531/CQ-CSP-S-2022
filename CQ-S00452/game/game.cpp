#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,m,q,l1,r1,l2,r2;
ll a[N],b[N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	while(q--){
		cin>>l1>>r1>>l2>>r2;
		ll cnt[N],ans=INT_MIN;
		memset(cnt,0,sizeof(cnt));
		for(int i=l1;i<=r1;i++){
			ll Min=INT_MAX;
			for(int j=l2;j<=r2;j++)
				Min=min(Min,a[i]*b[j]);
			cnt[i]=Min;
		}
		for(int i=l1;i<=r1;i++)
			ans=max(ans,cnt[i]);
		cout<<ans<<endl;
	}
	return 0;
}

