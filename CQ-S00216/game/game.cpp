#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5 + 5;
template<typename item> 
void read(item &x) {
	x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= f;
}
int n , m , q , l1 , r1 , l2 , r2 , Log2[MAXN];
ll a[MAXN] , b[MAXN] , dp[MAXN][31][2] , dp1[MAXN][31][2] , dp2[MAXN][31] , dp3[MAXN][31];
int main() {
	freopen("game.in" , "r" , stdin);
	freopen("game.out" , "w" , stdout);
	read(n);read(m);read(q); 
	for (int i = 2 ; i <= 1e5 ; i ++) Log2[i] = Log2[i / 2] + 1;
	for (int i = 1 ; i <= n ; i ++) {
		read(a[i]);
		if (a[i] > 0) {
			dp1[i][0][0] = a[i];
			dp1[i][0][1] = -2e18;
		} else {
			dp1[i][0][0] = 2e18;
			dp1[i][0][1] = a[i];
		}
		dp[i][0][0] = dp[i][0][1] = a[i];
	}
	for (int i = 1 ; i <= 21 ; i ++) {
		for (int j = 1 ; j + (1 << i) - 1 <= n ; j ++) {
			dp[j][i][0] = max(dp[j][i - 1][0] , dp[j + (1 << (i - 1))][i - 1][0]);
			dp[j][i][1] = min(dp[j][i - 1][1] , dp[j + (1 << (i - 1))][i - 1][1]);
			dp1[j][i][0] = min(dp1[j][i - 1][0] , dp1[j + (1 << (i - 1))][i - 1][0]);
			dp1[j][i][1] = max(dp1[j][i - 1][1] , dp1[j + (1 << (i - 1))][i - 1][1]);
		}
	}
	for (int i = 1 ; i <= m ; i ++) {
		read(b[i]);
		dp2[i][0] = dp3[i][0] = b[i];
	}	
	for (int i = 1 ; i <= 21 ; i ++) {
		for (int j = 1 ; j + (1 << i) - 1 <= m ; j ++) {
			dp2[j][i] = max(dp2[j][i - 1] , dp2[j + (1 << (i - 1))][i - 1]);
			dp3[j][i] = min(dp3[j][i - 1] , dp3[j + (1 << (i - 1))][i - 1]);
		}
	}
	while(q --) {
		read(l1);read(r1);read(l2);read(r2);
		int s = Log2[r2 - l2 + 1];
		ll tmp1 = min(dp3[l2][s] , dp3[r2 - (1 << s) + 1][s]) , tmp2 = max(dp2[l2][s] , dp2[r2 - (1 << s) + 1][s]);
		int s2 = Log2[r1 - l1 + 1];
		ll tmp3 = max(dp[l1][s2][0] , dp[r1 - (1 << s2) + 1][s2][0]) , tmp4 = min(dp[l1][s2][1] , dp[r1 - (1 << s2) + 1][s2][1]);
		if (tmp2 < 0) {
			if (tmp4 > 0) printf("%lld\n", tmp1 * tmp4);
			else printf("%lld\n", tmp4 * tmp2);
		} else if (tmp1 > 0) {
			if (tmp3 < 0) printf("%lld\n", tmp2 * tmp3);
			else printf("%lld\n", tmp3 * tmp1);
		} else {
			ll ans = -1e18;
			ll tmp5 = min(dp1[l1][s2][0] , dp1[r1 - (1 << s2) + 1][s2][0]) , tmp6 = max(dp1[l1][s2][1] , dp1[r1 - (1 << s2) + 1][s2][1]);
			if (tmp5 != 2e18) {
				ans = max(ans , tmp5 * tmp1);
			}
			if (tmp6 != -2e18) {
				ans = max(ans , tmp6 * tmp2);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}


