#include <bits/stdc++.h>
#define int long long
#define re register
using namespace std;
const int maxn = 1e3 + 2;
int n, m, q;
int a[maxn];
int b[maxn];
int c[maxn][maxn];
int tp[maxn];
int o[maxn];
int p[maxn];
inline int read() {
	int sum = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		sum = (sum << 3) + (sum << 1) + (c ^ 48);
		c = getchar();
	}
	return f * sum;
}
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(), m = read(), q = read();
	for(re int i = 1; i <= n; ++ i) a[i] = read();
	for(re int i = 1; i <= m; ++ i) b[i] = read();
	if(n <= 200 && m <= 200 && q <= 200) {
		for(re int i = 1; i <= n; ++ i) {
			for(re int j = 1; j <= m; ++ j) {
				c[i][j] = a[i] * b[j];
			}
		}
		while(q --) {
			int l1 = read(), r1 = read(), l2 = read(), r2 = read();
			int ans = INT_MIN, t = INT_MAX;
			for(re int i = l1; i <= r1; ++ i){
				for(re int j = l2; j <= r2; ++ j) {
					t = min(t, c[i][j]);
				}
				ans = max(ans, t);
			}
			printf("%d\n", ans);
		}
	}else {
		while(q --) {
			int l1 = read(), r1 = read(), l2 = read(), r2 = read();
			if(l1 == r1) {
				int t = INT_MAX;
				for(re int i = l2; i <= r2; ++ i) {
					t = min(t, a[l1] * b[i]);
				}
				printf("%d\n", t);
			}else if(l2 == r2) {
				int t = INT_MIN;
				for(re int i = l1; i <= r1; ++ i) {
					t = max(t, a[i] * b[l2]);
				}
				printf("%d\n", t);
			} 
		} 
	}
	return 0;
} 
