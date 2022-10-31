#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

const int N = 1e5 + 10;
long long a[N],b[N];
long long f,n,m,q,azs,afs,az,bzs,bfs,bz,ma,mi;
long long ans = 1;

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld",&a[i]);
		if (a[i] > 0) azs ++;
		else if (a[i] < 0) afs ++;
		else az ++;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%lld",&b[i]);
		if (b[i] > 0) bzs ++;
		else if (b[i] < 0) bfs ++;
		else bz ++;
	}
	if (!afs && !az && !bfs && !bz) f = 1;
	while (q --) {
		long long l,r,ll,rr;
		scanf("%lld%lld%lld%lld",&l,&r,&ll,&rr);
		if (l == r) {
			mi = 1e9 + 1,ans = 1e9,ma = a[l];
			for (int i = ll; i <= rr; i ++) ans = min(ans,b[i] * ma);
			printf("%lld\n",ans);
			continue;
		} else if (ll == rr) {
			ma = 0,ans = -1e9,mi = b[ll];
			for (int i = l; i <= r; i ++) ans = max(ans,a[i] * mi);
			printf("%lld\n",ans);
			continue;
		}
		else if (f) {
			ans = 1,ma = 0,mi = 1e9 + 1;
			for (int i = l; i <= r; i ++) ma = max(ma,a[i]);
			for (int i = ll; i <= rr; i ++) mi = min(mi,b[i]);
			ans = ma * mi;
			printf("%lld\n",ans);
		} 
	}
	return 0;
}
