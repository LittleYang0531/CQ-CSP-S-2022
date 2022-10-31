#include<bits/stdc++.h>
using namespace std;

const int N = 2500 + 10;
int n, m, k, x, y;
vector<int>v[N];
long long a[N], ans, sum;
int vis[N], flag;
bool check(int x) {
	for(int i = 0; i < v[x].size(); i++) {
		if(v[x][i] == 1) return true;
	}
	return false;
}
void dfs(int x, int cnt) {
	if(cnt == 4) {
		if(check(x))
			ans = max(ans, sum);
		return;	
	}
	for(int i = 0; i < v[x].size(); i++) {
		if(!vis[v[x][i]] && v[x][i] != 1) {
			sum += a[v[x][i]];
			vis[v[x][i]] = 1;
			dfs(v[x][i], cnt + 1);
			vis[v[x][i]] = 0;
			sum -= a[v[x][i]];
		}

	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 2; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
