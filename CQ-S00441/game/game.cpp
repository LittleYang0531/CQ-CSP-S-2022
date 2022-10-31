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
void print(ll x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x >= 10) print(x / 10);
	putchar(x % 10 + 48);
}
int n, m, q;
int a[100005], b[100005];
int p[100005];
int f[5][100005][20], g[5][100005][20];
int l1, r1, l2, r2;
int Log[100005];
ll ans;
ll fmax2, fmaxn, gmax2, fmin2, fminn, gmin2;
int fmax1(int l, int r, int id) {
	int len = r - l + 1;
	return max(f[id][l][Log[len]], f[id][r - (1 << Log[len]) + 1][Log[len]]);
}
int fmin1(int l, int r, int id) {
	int len = r - l + 1;
	return min(f[id][l][Log[len]], f[id][r - (1 << Log[len]) + 1][Log[len]]);
}
int gmax1(int l, int r, int id) {
	int len = r - l + 1;
	return max(g[id][l][Log[len]], g[id][r - (1 << Log[len]) + 1][Log[len]]);
}
int gmin1(int l, int r, int id) {
	int len = r - l + 1;
	return min(g[id][l][Log[len]], g[id][r - (1 << Log[len]) + 1][Log[len]]);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin>>n>>m>>q;
	for(int i = 2; i <= n || i <= m; i++) {
		Log[i] = Log[i / 2] + 1; 
	}
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i] > 0) {
			f[1][i][0] = f[3][i][0] = a[i];
			f[2][i][0] = -INT_MAX, f[4][i][0] = INT_MAX; 
		} else {
			f[2][i][0] = f[4][i][0] = a[i];
			f[1][i][0] = INT_MAX, f[3][i][0] = -INT_MAX; 
		}
	}
	for(int i = 1; i <= m; i++) {
		b[i] = read();
		g[1][i][0] = g[2][i][0] = b[i];
	}
	for(int j = 1; (1 << j) <= n; j++) {
		int len = (1 << j);
		for(int i = 1; i <= n - len + 1; i++) {
			f[1][i][j] = min(f[1][i][j - 1], f[1][i + (1 << j - 1)][j - 1]);
			f[2][i][j] = max(f[2][i][j - 1], f[2][i + (1 << j - 1)][j - 1]);
			f[3][i][j] = max(f[3][i][j - 1], f[3][i + (1 << j - 1)][j - 1]);
			f[4][i][j] = min(f[4][i][j - 1], f[4][i + (1 << j - 1)][j - 1]);
		}
	}
	for(int j = 1; (1 << j) <= m; j++) {
		int len = (1 << j);
		for(int i = 1; i <= m - len + 1; i++) {
			g[1][i][j] = max(g[1][i][j - 1], g[1][i + (1 << j - 1)][j - 1]);
			g[2][i][j] = min(g[2][i][j - 1], g[2][i + (1 << j - 1)][j - 1]);
		}
	}
	while(q--) {
		l1 = read(), r1 = read(), l2 = read(), r2 = read();
		fmin2 = fmin1(l1, r1, 1), fmax2 = fmax1(l1, r1, 2);
		fmaxn = fmax1(l1, r1, 3), fminn = fmin1(l1, r1, 4);
		gmax2 = gmax1(l2, r2, 1), gmin2 = gmin1(l2, r2, 2);
		ans = -1000000000000000001;
//		cout<<fmaxn<<' '<<fmin2<<' '<<fmax2<<' '<<fminn<<' '<<gmax2<<' '<<gmin2<<endl;
		if(fminn != INT_MAX) {
			ans = max(ans, fminn * gmax2);
		}
		if(fmaxn != -INT_MAX) {
			ans = max(ans, fmaxn * gmin2);
		}
		if(fmin2 != INT_MAX) {
			ans = max(ans, fmin2 * gmin2);
		}
		if(fmax2 != -INT_MAX) {
			ans = max(ans, fmax2 * gmax2);
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}

