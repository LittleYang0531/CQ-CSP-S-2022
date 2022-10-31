#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, q, out;
int cnt, h[N], v[N];
bool vst[N];
struct edge {
	int to, next;
}a[N], Ba[N];
void Add(int x, int y) {
	cnt++;
	a[cnt].to = y;
	a[cnt].next = h[x];
	h[x] = cnt;
}
void dfs(int x, int y, int sum, int k) {
	if(k > m) return;
	if(x == y) {
		out = min(out, sum);
		return;
	}
	int tr(0);
	for(int i = h[x];i;i = a[i].next) {
		tr = a[i].to;
		vst[tr] = 1;
		dfs(tr, y, sum, k + 1);
		dfs(tr, y, sum + v[a[i].to], 0);
		vst[tr] = 0;
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	cin >> n >> q >> m;
	for(int i = 1;i <= n; i++)
		scanf("%d", v + i);
	int x(0), y(0);
	for(int i = 1;i <= n - 1; i++) {
		scanf("%d%d", &x, &y);
		Add(x, y);
	}
	while(q--) {
		out = 0xfffffff;
		scanf("%d%d", &x, &y);
		dfs(x, y, v[x], 0);
		cout << out << endl;
	}
	return 0;
}

