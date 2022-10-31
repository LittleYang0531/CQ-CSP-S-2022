#include <bits/stdc++.h>			//Fight For 100

#define sf scanf
#define pf printf

using namespace std;

int read () {
	int s = 0, w = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar ();
	}
	while (ch <= '9' && ch >= '0') {
		s = s * 10 + (ch - '0');
		ch = getchar ();
	}
	return s * w;
}

const int maxn = 2505;

int a[maxn];
bool f[maxn];

int x[maxn];
int y[maxn];
bool vis[maxn][maxn];

int n, m, k;

int maxx = -0x3f3f3f3f;

void dfs (int ans, int step, int d) {
//	cout << d << endl;
	if (step == 5) return ;
	if (vis[1][d] == 1 && step == 4) {
		maxx = max (maxx, ans);
//		cout << maxx << "oh\n";
//		return ;
	}
	for (int i = 1; i <= m; i ++) {
		if (y[i] == d && ! f[x[i]]) {
			f[x[i]] = 1;
			ans += a[x[i]];
			dfs (ans, step + 1, x[i]);
//			cout << "fail" << endl;
			f[x[i]] = 0;
			step --;
			ans -= a[x[i]];
		}
		if (x[i] == d && ! f[y[i]]) {
//			cout << ans << endl;
			f[y[i]] = 1;
			ans += a[y[i]];
			dfs (ans, step + 1, y[i]);
//			cout << "fail" << endl;
			f[y[i]] = 0;
			step --;
			ans -= a[y[i]];
		}
	}
//	return ;
}

bool cmp (int s, int b) {
	return s > b;
}

signed main () {
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);
	n = read ();
	m = read ();
	k = read ();
	a[1] = 0;
	for (int i = 2; i <= n; i ++) {
		a[i] = read ();
	}
	for (int i = 1; i <= m; i ++) {
		x[i] = read ();
		y[i] = read ();
		vis[x[i]][y[i]] = vis[y[i]][x[i]] = 1;
	}
//	dfs (0, 0, 1);
	sort (a + 1, a + n + 1, cmp);
	cout << a[1] + a[2] + a[3] + a[5];
	return 0;
}

//8 8 1
//9 7 1 8 2 3 6
//1 2
//2 3
//3 4
//4 5
//5 6
//6 7
//7 8
//8 1




