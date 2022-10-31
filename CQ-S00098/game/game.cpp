#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,m,q,a[maxn],b[maxn];
int check(int l1,int r1,int l2,int r2){
	vector<ll> t;
	for(int i(l1);i<=r1;++i){
		ll ans=1e10;
		for(int j(l2);j<=r2;++j){
			ans=min(ans,(ll)a[i]*b[j]);
		}
		t.push_back(ans);
	}
	int s=t.size();
	ll ans=-1e10;
	for(int i(0);i<s;++i){
		ans=max(ans,t[i]);
	}
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i(1);i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i(1);i<=m;++i){
		scanf("%d",&b[i]);
	}
	for(int i(1);i<=q;++i){
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int ans=check(l1,r1,l2,r2);
		printf("%d\n",ans);
	}
	return 0;
}

