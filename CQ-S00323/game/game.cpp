#include <bits/stdc++.h>
#define re(i, x, y) for (int i = (x); i < (y); ++i)
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)

using namespace std;
typedef long long LL;
template<typename T> void chkmx(T &x, const T &y) {
	x = x < y ? y : x;
}
template<typename T> void chkmn(T &x, const T &y) {
	x = x > y ? y : x;
}

const int N = 1e5, maxn = N + 5, inf = 1e9;
const LL INF = 1e18;
int n, m, q;
int lo[maxn], z1[maxn], z2[maxn];
int mx1[17][maxn], mn1[17][maxn], mx2[17][maxn], mn2[17][maxn], mx3[17][maxn], mn3[17][maxn], mx4[17][maxn], mn4[17][maxn];

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &q);
	memset(mx1, 128, sizeof(mx1));
	memset(mx2, 128, sizeof(mx2));
	memset(mx3, 128, sizeof(mx3));
	memset(mx4, 128, sizeof(mx4));
	memset(mn1, 0x3f, sizeof(mn1));
	memset(mn2, 0x3f, sizeof(mn2));
	memset(mn3, 0x3f, sizeof(mn3));
	memset(mn4, 0x3f, sizeof(mn4));
	int x;
	rep(i, 1, n) {
		scanf("%d", &x);
		z1[i] = z1[i - 1];
		if (x > 0) {
			mx1[0][i] = mn1[0][i] = x;
		}
		else if (x < 0) {
			mx2[0][i] = mn2[0][i] = x;
		}
		else {
			++z1[i];
		}
	}
	rep(i, 1, m) {
		scanf("%d", &x);
		z2[i] = z2[i - 1];
		if (x > 0) {
			mx3[0][i] = mn3[0][i] = x;
		}
		else if (x < 0) {
			mx4[0][i] = mn4[0][i] = x;
		}
		else {
			++z2[i];
		}
	}
	lo[0] = -1;
	rep(i, 1, N) {
		lo[i] = lo[i >> 1] + 1;
	}
	re(i, 1, 17) {
		rep(j, 1, n - (1 << i) + 1) {
			mx1[i][j] = max(mx1[i - 1][j], mx1[i - 1][j + (1 << i - 1)]);
			mx2[i][j] = max(mx2[i - 1][j], mx2[i - 1][j + (1 << i - 1)]);
			mn1[i][j] = min(mn1[i - 1][j], mn1[i - 1][j + (1 << i - 1)]);
			mn2[i][j] = min(mn2[i - 1][j], mn2[i - 1][j + (1 << i - 1)]);
		}
		rep(j, 1, m - (1 << i) + 1) {
			mx3[i][j] = max(mx3[i - 1][j], mx3[i - 1][j + (1 << i - 1)]);
			mx4[i][j] = max(mx4[i - 1][j], mx4[i - 1][j + (1 << i - 1)]);
			mn3[i][j] = min(mn3[i - 1][j], mn3[i - 1][j + (1 << i - 1)]);
			mn4[i][j] = min(mn4[i - 1][j], mn4[i - 1][j + (1 << i - 1)]);
		}
	}
	auto qry = [&] (int o, int p, int l, int r) {
		int L = lo[r - l + 1]; 
		if (o == 1) {
			if (p) {
				return max(mx1[L][l], mx1[L][r - (1 << L) + 1]);
			}
			else {
				return min(mn1[L][l], mn1[L][r - (1 << L) + 1]);
			}
		}
		else if (o == 2) {
			if (p) {
				return max(mx2[L][l], mx2[L][r - (1 << L) + 1]);
			}
			else {
				return min(mn2[L][l], mn2[L][r - (1 << L) + 1]);
			}
		}
		else if (o == 3) {
			if (p) {
				return max(mx3[L][l], mx3[L][r - (1 << L) + 1]);
			}
			else {
				return min(mn3[L][l], mn3[L][r - (1 << L) + 1]);
			}
		}
		if (p) {
			return max(mx4[L][l], mx4[L][r - (1 << L) + 1]);
		}
		else {
			return min(mn4[L][l], mn4[L][r - (1 << L) + 1]);
		}
	};
	
	int l1, r1, l2, r2;
	rep(i, 1, q) {
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		LL ans = -INF;
		if (z1[r1] ^ z1[l1 - 1]) {
			chkmx(ans, 0LL);
		}
		array<int, 4> aa = {qry(1, 0, l1, r1), qry(2, 0, l1, r1), qry(1, 1, l1, r1), qry(2, 1, l1, r1)};
		array<int, 4> bb = {qry(3, 0, l2, r2), qry(4, 0, l2, r2), qry(3, 1, l2, r2), qry(4, 1, l2, r2)};
		re(j, 0, 4) {
			if (aa[j] < -inf || aa[j] > inf) {
				continue ;
			}
			LL res = INF;
			re(k, 0, 4) {
				if (bb[k] < -inf || bb[k] > inf) {
					continue ;
				}
				chkmn(res, 1LL * aa[j] * bb[k]);	
			} 
			if (z2[r2] ^ z2[l2 - 1]) {
				chkmn(res, 0LL);
			}
			chkmx(ans, res);
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
