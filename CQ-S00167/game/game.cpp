#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = log2(N) + 5;
const long long INF = 0x3f3f3f3f;

int n, m, q;
long long fmxA[N][M][2], fmiA[N][M][2];
long long fmxB[N][M][2], fmiB[N][M][2];

void Read() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		if (x >= 0) {
			fmxA[i][0][1] = fmiA[i][0][1] = x;
			fmxA[i][0][0] = -INF;
			fmiA[i][0][0] = INF;
		} else {
			fmxA[i][0][0] = fmiA[i][0][0] = x;
			fmxA[i][0][1] = -INF;
			fmiA[i][0][1] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		long long x;
		cin >> x;
		if (x >= 0) {
			fmxB[i][0][1] = fmiB[i][0][1] = x;
			fmxB[i][0][0] = -INF;
			fmiB[i][0][0] = INF;
		} else {
			fmxB[i][0][0] = fmiB[i][0][0] = x;
			fmxB[i][0][1] = -INF;
			fmiB[i][0][1] = INF;
		}
	}
}

void Init() {
	for (int j = 1; j <= log2(N); j++)
		for (int i = 1; i <= n - (1 << j) + 1; i++)
			for (int k = 0; k < 2; k++) {
				fmxA[i][j][k] = max(fmxA[i][j - 1][k], fmxA[i + (1 << (j - 1))][j - 1][k]);
				fmiA[i][j][k] = min(fmiA[i][j - 1][k], fmiA[i + (1 << (j - 1))][j - 1][k]);
				fmxB[i][j][k] = max(fmxB[i][j - 1][k], fmxB[i + (1 << (j - 1))][j - 1][k]);
				fmiB[i][j][k] = min(fmiB[i][j - 1][k], fmiB[i + (1 << (j - 1))][j - 1][k]);
			}
//				cout << fmxB[2][0][0] << '\n';
}

void Solve() {
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int len1 = log2(r1 - l1 + 1), len2 = log2(r2 - l2 + 1);
		long long mx0A = max(fmxA[l1][len1][0], fmxA[r1 - (1 << len1) + 1][len1][0]);
		long long mx1A = max(fmxA[l1][len1][1], fmxA[r1 - (1 << len1) + 1][len1][1]);
		long long mi0A = min(fmiA[l1][len1][0], fmiA[r1 - (1 << len1) + 1][len1][0]);
		long long mi1A = min(fmiA[l1][len1][1], fmiA[r1 - (1 << len1) + 1][len1][1]);
		long long mx0B = max(fmxB[l2][len2][0], fmxB[r2 - (1 << len2) + 1][len2][0]);
		long long mx1B = max(fmxB[l2][len2][1], fmxB[r2 - (1 << len2) + 1][len2][1]);
		long long mi0B = min(fmiB[l2][len2][0], fmiB[r2 - (1 << len2) + 1][len2][0]);
		long long mi1B = min(fmiB[l2][len2][1], fmiB[r2 - (1 << len2) + 1][len2][1]);
//		cout << mx0A << ' ' << mx1A << ' ' << mi0A << ' ' << mi1A << ' ';
//		cout << mx0B << ' ' << mx1B << ' ' << mi0B << ' ' << mi1B << ' ';
		if (mi0B != INF && mx1B != -INF) { // < 0 && > 0
//			cout << "1: ";
			long long tmp1 = mx1B * mx0A;
			long long tmp2 = mi0B * mi1A;
			cout << max(tmp1, tmp2) << '\n';
		} else if (mi0B == INF) {  // > 0
//			cout << "2: ";
//			cout << max(mx0A, mx1A) << ' ';
			if (mi0A != INF && mx1A != -INF)
				cout << mi1B * max(mx0A, mx1A) << '\n';
			else if (mi0A == INF)  // > 0
				cout << mi1B * mx1A << '\n';
			else 
				cout << mx1B * mx0A << '\n';
		} else {                          // < 0
//			cout << "3: ";
			if (mi0A != INF && mx1A != -INF)
				cout << mx0B * min(mi0A, mi1A) << '\n';
			else if (mi0A == INF)  // > 0
				cout << mi0B * mi1A << '\n';
			else 
				cout << mx0B * mi0A << '\n';
		}
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	Read();
	Init();
	Solve();

	return 0;
}

/*
input:
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

output:
0
4
*/

/*
input:
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

output:
0
-2
3
2
-1
*/
