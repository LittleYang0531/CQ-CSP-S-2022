#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int f(int l, int r) {
	int ans = a[l];
	for(int i = l + 1; i <= r; i++) ans = max(ans, a[i]);
	return ans;
}
int f1(int l, int r) {
	int ans = b[l];
	for(int i = l + 1; i <= r; i++) ans = min(ans, b[i]);
	return ans;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, q, l1, r1, l2, r2, Max, Min, flag = 1;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < 0) flag = 0;
		if(i == 1) Max = a[i];
		Max = max(Max, a[i]);
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		if(b[i] < 0) flag = 0;
		if(i == 1) Min = b[i];
		Min = min(Min, b[i]);
	}
	if(flag == 1) {
		while(q--) {
			cin >> l1 >> r1 >> l2 >> r2;
			int s1 = f(l1, r1);
			int s2 = f1(l2, r2);
			long long ans = s1 * s2;
			cout << ans << endl;
		}
		return 0;
	}
	while(q--) {
		cin >> l1 >> r1 >> l2 >> r2;
		if(l1 == r1) {
			long long ans = f1(l2, r2) * a[l1];
			cout << ans << endl;
			continue;
		}
		if(l2 == r2) {
			long long ans = f(l1, r1) * b[l2];
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
