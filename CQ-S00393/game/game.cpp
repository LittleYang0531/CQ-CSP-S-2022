#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// ai * bi <= long long
const long long maxn = 1e5 + 5;
const long long inf = -999999999;
long long a[maxn],b[maxn],n,m,q;

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
	for(int i = 1;i <= m;i ++) scanf("%lld",&b[i]);
	for(int i = 1;i <= q;i ++) {
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long minn = -inf,maxx = inf;
		for(int j = l2;j <= r2;j ++) {
			minn = min(minn,b[j]);
			maxx = max(maxx,b[j]);
//			printf("minn = %d,maxx = %d\n",minn,maxx);
		}
		long long answer = -inf * inf;
		for(int j = l1;j <= r1;j ++) {
			if(a[j] > 0) answer = max(answer,a[j] * minn);
			else if(a[j] < 0) answer = max(answer,a[j] * maxx);
			else answer = max(answer,(long long)(0));
//			printf("%d %d\n",a[j],a[j] * minn);
		}
		printf("%lld\n",answer);
	}
	return 0;
}
