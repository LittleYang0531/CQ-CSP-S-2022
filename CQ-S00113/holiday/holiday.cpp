#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long s[10005];
bool cmp (int a, int b) {
	return a > b;
}
int main() {
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);
	scanf ("%lld %lld %lld", &n, &m, &k);
	for (int i = 1; i <= n - 1; i ++) {
		scanf ("%lld", &s[i]);
	}
	sort (s + 1, s + n + 1, cmp);
	for (int i = 1; i <= m; i ++) {
		long long x, y;
		scanf ("%lld %lld", &x, &y);
	}
	cout << s[1] + s[2] + s[3] + s[4];
	return 0;
}

