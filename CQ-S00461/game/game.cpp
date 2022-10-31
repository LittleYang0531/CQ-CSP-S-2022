#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int INF = 2147483647;
int a[maxn], b[maxn];
int s[maxn][maxn];
int Min[maxn];
int n, m, q;
int l1, r1, l2, r2;
int ans;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out ", "w", stdout);
	scanf("%d %d %d", &m, &n, &q);
	for(int i = 1; i <= m; i ++){
		scanf("%d", &a[i]);
	}
	for(int j = 1; j <= n; j ++){
		scanf("%d", &b[j]);
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			s[i][j] = a[i] * b[j];
		}
	}
	for(int i = 1; i <= q; i ++){
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		ans = -2147483647;
		for(int j = l1; j <= r1; j ++){
			Min[j] = 2147483647;
			for(int k = l2; k <= r2; k ++){
				Min[j] = min(Min[j], s[j][k]);
			}
			ans = max(Min[j], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
