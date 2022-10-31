#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int Maxn = 1e5 + 5;
#define ll long long
int n, m, q, f; 
ll a[Maxn], b[Maxn], dp[2][2][Maxn][25];
template <class T>
void read(T &x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ '0');
		ch = getchar();
	}
	x *= f;
}
ll solve(int l, int r, int f, int f2) {
	int p = log2(r - l + 1);
	if(!f2) return max(dp[f][f2][l][p], dp[f][f2][r - (1 << p) + 1][p]);
	else return min(dp[f][f2][l][p], dp[f][f2][r - (1 << p) + 1][p]);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	f = 1;
	for(int i = 1; i <= n; i++) {
		read(a[i]);
		if(a[i] <= 0) f = 0;
		dp[0][0][i][0] = dp[0][1][i][0] = a[i];
	}
	for(int i = 1; i <= m; i++) {
		read(b[i]);
		if(b[i] <= 0) f = 0;
		dp[1][0][i][0] = dp[1][1][i][0] = b[i];
	}
	for(int j = 1; j < 25; j++) {
		for(int i = 1; i + (1 << j) - 1 <= n; i++) {
			dp[0][0][i][j] = max(dp[0][0][i][j - 1], dp[0][0][i + (1 << j - 1)][j - 1]);
			dp[1][0][i][j] = max(dp[1][0][i][j - 1], dp[1][0][i + (1 << j - 1)][j - 1]);
			dp[0][1][i][j] = min(dp[0][1][i][j - 1], dp[0][1][i + (1 << j - 1)][j - 1]);
			dp[1][1][i][j] = min(dp[1][1][i][j - 1], dp[1][1][i + (1 << j - 1)][j - 1]);
		}
	}
	while(q--) {
		int l1, r1, l2, r2;
		read(l1), read(r1), read(l2), read(r2);
		if(l1 == r1) {
			if(a[l1] > 0) printf("%lld\n", a[l1] * solve(l2, r2, 1, 1));
			else printf("%lld\n", a[l1] * solve(l2, r2, 1, 0));
		}
		else if(l2 == r2) {
			if(b[l2] > 0) printf("%lld\n", solve(l1, r1, 0, 0) * b[l2]);
			else printf("%lld\n", solve(l1, r1, 0, 1) * b[l2]);
		}
		else {
			if(f) {
				printf("%lld\n", solve(l1, r1, 0, 0) * solve(l2, r2, 1, 1));
				continue;
			}
			ll Max1 = -1e18, Max2 = -1e18, Min1 = 1e18, Min2 = 1e18;
			bool flag = false;
			for(int i = l1; i <= r1; i++) {
				if(a[i] < 0) Max1 = max(Max1, a[i]); 
				if(a[i] < 0) Min1 = min(Min1, a[i]);
				if(a[i] > 0) Max2 = max(Max2, a[i]);
				if(a[i] > 0) Min2 = min(Min2, a[i]);
				if(!a[i]) flag = 1;
			}
			ll res = -1e18, Min = 1e18;
			if(flag) res = 0;
			for(int i = l2; i <= r2; i++) if(Min > Max1 * b[i]) Min = Max1 * b[i];
			res = max(res, Min);
			Min = 1e18;
			for(int i = l2; i <= r2; i++) if(Min > Min1 * b[i]) Min = Min1 * b[i];
			res = max(res, Min);
			Min = 1e18;
			for(int i = l2; i <= r2; i++) if(Min > Max2 * b[i]) Min = Max2 * b[i];
			res = max(res, Min);
			Min = 1e18;
			for(int i = l2; i <= r2; i++) if(Min > Min2 * b[i]) Min = Min2 * b[i];
			res = max(res, Min);
			if(flag && Min < 0) Min = 0;
			printf("%lld\n", res);
		}
	}
	return 0;
}

