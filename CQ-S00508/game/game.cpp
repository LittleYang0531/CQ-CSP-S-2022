#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const long long INF = 1e18;
int n, m, q, logm;
long long a[N], b[N], kk;
int l1, r1, l2, r2;
long long RMQ[N][N][25], out;
void ST() {
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= m; j++)
			RMQ[i][j][0] = a[i] * b[j];
	logm = log2(m);
	for(int i = 1;i <= n; i++) {
		kk = 1;
		for(int k = 1;k <= logm; k++) {
			kk = (kk << 1);
			for(int j = 1;j + kk - 1 <= m; j++)
				RMQ[i][j][k] = min(RMQ[i][j][k - 1], RMQ[i][j + kk / 2][k - 1]);
		}
	}
}
long long ASK(int h, int l, int r) {
	int logg = log2(r - l + 1);
	return min(RMQ[h][l][logg], RMQ[h][r - (1 << logg) + 1][logg]);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m >> q;
	for(int i = 1;i <= n; i++)
		scanf("%lld", a + i);
	for(int i = 1;i <= m; i++)
		scanf("%lld", b + i);
	if(n <= 3000) {
		ST();
		for(int i = 1;i <= q; i++) {
			scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			out = -INF;
			for(int j = l1;j <= r1; j++) {
				out = max(out, ASK(j, l2, r2));
			}
			cout << out << endl;
		}
		return 0;
	}
	else {
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if(l1 == r1) {
			out = INF;
			for(int i = l2;i <= r2; i++)
				out = min(out, a[l1] * b[i]);
			cout << out << endl;
		}
		else if(l2 == r2) {
			out = -INF;
			for(int i = l1;i <= r1; i++)
				out = max(out, a[i] * b[l2]);
			cout << out << endl;
		}
		else {
			cout << "I don't know" << endl;
			return 0;
		}
		return 0;
	}
	return 0;
}
//MLE
