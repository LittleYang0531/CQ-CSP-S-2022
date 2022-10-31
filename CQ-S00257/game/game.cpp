#include<cstdio>
#include<algorithm>
using namespace std;
#define re register
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll n, m, q, a[MAXN], b[MAXN];
inline ll max(re ll a, re ll b){
	return a > b ? a : b;
}
inline ll min(re ll a, re ll b){
	return a < b ? a : b;
}
inline ll getmax1(re ll l, re ll r){
	ll maxn = -0x3f3f3f3f3f3f;
	for(; l <= r; l ++)maxn = max(maxn, a[l]);
	return maxn;
}
inline ll getmax2(re ll l, re ll r){
	ll maxn = -0x3f3f3f3f3f3f;
	for(; l <= r; l ++)maxn = max(maxn, b[l]);
	return maxn;
}
inline ll getmin1(re ll l, re ll r){
	ll minn = 0x3f3f3f3f3f3f;
	for(; l <= r; l ++)minn = min(minn, a[l]);
	return minn;
}
inline ll getmin2(re ll l, re ll r){
	ll minn = 0x3f3f3f3f3f3f;
	for(; l <= r; l ++)minn = min(minn, b[l]);
	return minn;
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &q);
	for(ll i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	for(ll i = 1; i <= m; i ++){
		scanf("%lld", &b[i]);
	}
	while(q --){
		ll l1, l2, r1, r2;
		scanf("%lld %lld %lld %lld", &l1, &r1, &l2, &r2);
		ll t1 = getmin2(l2, r2), t2 = getmax2(l2, r2);
		ll ans = -0x3f3f3f3f3f3f;
		if(t1 <= 0ll){
			if(t2 <= 0ll){
				printf("%lld\n", t2 * getmin1(l1, r1));
				continue;
			}
			ll x = 0x3f3f3f3f3f3f, y = -0x3f3f3f3f3f3f;
			for(ll i = l1; i <= r1; i ++){
				if(a[i] >= 0ll && a[i] < x){
					x = a[i];
				}
				if(a[i] <= 0ll && a[i] > y){
					y = a[i];
				}
			}
			if(x == 0x3f3f3f3f3f3f){
				ans = x * t1;
			}
			if(y == -0x3f3f3f3f3f3f){
				ans = y * t2;
			}
			if(x != 0x3f3f3f3f3f3f && y != -0x3f3f3f3f3f3f){
				ans = max(x * t1, y * t2);
			}
		}
		else{
			ans = getmax1(l1, r1) * t1;
		}
		printf("%lld\n", ans);
	}
	return 0; 
}
