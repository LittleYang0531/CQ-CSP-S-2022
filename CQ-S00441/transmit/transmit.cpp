#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read() {
	int sum, f = 1;
	char ch;
	while((ch = getchar()) && (ch < '0' || ch > '9')) {
		if(ch == '-') f = -1;
	}
	sum = (ch ^ 48);
	while((ch = getchar()) && (ch >= '0' && ch <= '9')) {
		sum = (sum << 1) + (sum << 3) + (ch ^ 48);
	}
	return sum * f;
}
void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x >= 10) print(x / 10);
	putchar(x % 10 + 48);
}
const ll maxn = 1e17;
int n, q, k;
ll ans;
int s, t;
int val[100005];
bool vis[100005][5];
vector<int> w[100005];
void dfs(int x, int cnt, ll v) {
	if(x == t) {
		ans = min(ans, v + (cnt > 0 ? val[t] : 0));
		return;
	}
	for(int i = 0; i < w[x].size(); i++) {
		int y = w[x][i];
		if(cnt + 1 < k && !vis[y][cnt + 1]) {
			vis[y][cnt + 1] = true;
			dfs(y, cnt + 1, v);
			vis[y][cnt + 1] = false;
		}
		if(vis[y][0]) continue;
		vis[y][0] = true;
		dfs(y, 0, v + val[y]);
		vis[y][0] = false;
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	cin>>n>>q>>k;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		w[u].push_back(v);
		w[v].push_back(u);
	}
	while(q--) {
		for(int i = 1; i <= n; i++) vis[i][0] = vis[i][1] = vis[i][2] = 0;
		ans = maxn;
		scanf("%d %d", &s, &t);
		dfs(s, 0, val[s]);
		printf("%lld\n", ans);
	}
	return 0;
}

