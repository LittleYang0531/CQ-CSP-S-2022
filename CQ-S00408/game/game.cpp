#include<queue>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n,m,q,a[100005],b[100005],l1,r1,l2,r2;
unsigned long long rp;
signed main() {
	rp--;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	for(int i = 1;i <= m;i++) scanf("%lld",&b[i]);
	while(q--) {
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		int ma = -0x7fffffffffffffffll;
		for(int i = l1;i <= r1;i++) {
			int mi = 0x7fffffffffffffffll;
			for(int j = l2;j <= r2;j++) mi = min(mi,a[i] * b[j]);
			ma = max(ma,mi);
		}
		printf("%lld\n",ma);
	}
	if(1 + 1 != 2) printf("HOOCH AK IOI!!!\n");
	return 0;
}
