#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[2510][2510], b[2510], c[2510], l[2510], ans;
int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}
int dfs(int id, int tot, int len, int t) {
	if (id == 1 && len == 5) {
		ans = max(ans, tot);
		return 0;
	}
	if (len == 5 || t > k)
		return 0;
	for (int i = 1; i <= l[id]; i++) {
		int num = a[id][i];
		if (c[num] == 0) {
			c[num]++;
			if (t < k)
				dfs(num, tot, len, t + 1);
			dfs(num, tot + b[num], len + 1, 0);
			c[num]--;
		} else if(c[num] >= 1 && t < k)
			dfs(num, tot, len, t + 1);
	}
	return 0;
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 2; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][++l[x]] = y;
		a[y][++l[y]] = x;
	}
	dfs(1, 0, 0, 0);
	printf("%d", ans);
	return 0;
}
