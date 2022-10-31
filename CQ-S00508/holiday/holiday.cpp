#include <bits/stdc++.h>
using namespace std;
const int N = 2505, M = 10005;
int n, m, k, c[N], tj[5];
int cnt, h[N], maxc;
bool vst[N], vis[N];
struct edge {
	int to, next;
}a[M * 2];
void Add(int x, int y) {
	cnt++;
	a[cnt].to = y;
	a[cnt].next = h[x];
	h[x] = cnt;
}
void dfs(int x, int sumc, int zhuan, int zhan) {
	if(zhuan > k) return;
//	cout << x << endl;
	if(x == 1 && zhan == 4) {
		maxc = max(maxc, sumc);
		return;
	}
	int y(0);
	for(int i = h[x];i;i = a[i].next) {
		y = a[i].to;
		if(!vis[y]) {
			vis[y] = 1;
			dfs(y, sumc, zhuan + 1, zhan);
			vis[y] = 0;
		}
		tj[zhan + 1] = y;
		if(y != 1 && !vst[y]) {
			vst[y] = 1;
			dfs(y, sumc + c[y], 0, zhan + 1);
			vst[y] = 0;
		}
		if(y == 1 && zhan == 4) {
			dfs(y, sumc, zhuan, zhan);
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 2;i <= n; i++)
		scanf("%d", c + i);
	int x(0), y(0);
	for(int i = 1;i <= m; i++) {
		scanf("%d%d", &x, &y);
		Add(x, y);
		Add(y, x);
	}
	dfs(1, 0, 0, 0);
	cout << maxc << endl;
	return 0;
}

