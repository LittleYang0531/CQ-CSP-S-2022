//求求你下次不要把难度反着拍好不好 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MAXN 100000
#define MAXM 17
#define INF 0x3f3f3f3f

int sa[MAXN + 5], sb[MAXN + 5];
int sta[2][2][MAXM + 5][MAXN + 5];
int suma[2][MAXN + 5];
int stb[2][2][MAXM + 5][MAXN + 5];
int sumb[2][MAXN + 5];
int Log2[MAXN + 5];

void read (int &n) {
	n = 0;

	char c = getchar ();
	bool flag = 0;

	while (c < '0' || c > '9') {
		if (c == '-') {
			flag = 1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar ();
	}
	n = flag ? -n : n;
}
int aska (int k1, int k2, int l, int r) {
	int u = Log2[r - l + 1];
	
	if (k2 == 0) {
		return min (sta[k1][k2][u][l], sta[k1][k2][u][r - (1 << u) + 1]);
	}
	else {
		return max (sta[k1][k2][u][l], sta[k1][k2][u][r - (1 << u) + 1]);
	}
}
int askb (int k1, int k2, int l, int r) {
	int u = Log2[r - l + 1];
	
	if (k2 == 0) {
		return min (stb[k1][k2][u][l], stb[k1][k2][u][r - (1 << u) + 1]);
	}
	else {
		return max (stb[k1][k2][u][l], stb[k1][k2][u][r - (1 << u) + 1]);
	}
}

int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	
	int n, m, q;
	
	read (n), read (m), read (q);
	for (int i = 1; i <= n; i ++) {
		read (sa[i]);
		if (sa[i] > 0) {
			sta[0][0][0][i] = sa[i];
			sta[1][0][0][i] = INF;
			sta[0][1][0][i] = sa[i];
			sta[1][1][0][i] = -INF;
			suma[0][i] = 1;
		}
		else if (sa[i] < 0){
			sta[1][0][0][i] = -sa[i];
			sta[0][0][0][i] = INF;
			sta[1][1][0][i] = -sa[i];
			sta[0][1][0][i] = -INF;
			suma[1][i] = 1;
		}
		else {
			sta[1][0][0][i] = 0;
			sta[0][0][0][i] = 0;
			sta[1][1][0][i] = 0;
			sta[0][1][0][i] = 0;
			suma[1][i] = 1;
			suma[0][i] = 1;
		}
	} 
	for (int i = 1; i <= m; i ++) {
		read (sb[i]);
		if (sb[i] > 0) {
			stb[0][0][0][i] = sb[i];
			stb[1][0][0][i] = INF;
			stb[0][1][0][i] = sb[i];
			stb[1][1][0][i] = -INF;
			sumb[0][i] = 1;
		}
		else if (sb[i] < 0){
			stb[1][0][0][i] = -sb[i];
			stb[0][0][0][i] = INF;
			stb[1][1][0][i] = -sb[i];
			stb[0][1][0][i] = -INF;
			sumb[1][i] = 1;
		}
		else {
			stb[1][0][0][i] = 0;
			stb[0][0][0][i] = 0;
			stb[1][1][0][i] = 0;
			stb[0][1][0][i] = 0;
			sumb[1][i] = 1;
			sumb[0][i] = 1;
		}
	} 
	Log2[0] = 0;
	Log2[1] = 0;
	for (int i = 2; i <= n || i <= m; i ++) {
		Log2[i] = Log2[i >> 1] + 1;
	}
	for (int i = 1; (1 << i) <= n; i ++) {
		for (int j = 1; j <= (n - (1 << i) + 1); j ++) {
			sta[0][0][i][j] = min (sta[0][0][i - 1][j], sta[0][0][i - 1][j + (1 << (i - 1))]);
			sta[1][0][i][j] = min (sta[1][0][i - 1][j], sta[1][0][i - 1][j + (1 << (i - 1))]);
			sta[0][1][i][j] = max (sta[0][1][i - 1][j], sta[0][1][i - 1][j + (1 << (i - 1))]);
			sta[1][1][i][j] = max (sta[1][1][i - 1][j], sta[1][1][i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 1; (1 << i) <= m; i ++) {
		for (int j = 1; j <= (m - (1 << i) + 1); j ++) {
			stb[0][0][i][j] = min (stb[0][0][i - 1][j], stb[0][0][i - 1][j + (1 << (i - 1))]);
			stb[1][0][i][j] = min (stb[1][0][i - 1][j], stb[1][0][i - 1][j + (1 << (i - 1))]);
			stb[0][1][i][j] = max (stb[0][1][i - 1][j], stb[0][1][i - 1][j + (1 << (i - 1))]);
			stb[1][1][i][j] = max (stb[1][1][i - 1][j], stb[1][1][i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		suma[0][i] += suma[0][i - 1];
		suma[1][i] += suma[1][i - 1];
	}
	for (int i = 1; i <= m; i ++) {
		sumb[0][i] += sumb[0][i - 1];
		sumb[1][i] += sumb[1][i - 1];
	}
	for (int i = 1; i <= q; i ++) {
		int l1, r1, l2, r2;
		
		read (l1), read (r1), read (l2), read (r2);
		if (suma[0][r1] - suma[0][l1 - 1] == r1 - l1 + 1) {
			if (sumb[0][r2] - sumb[0][l2 - 1] == r2 - l2 + 1) {
				printf ("%lld\n", 1ll * aska(0, 1, l1, r1) * askb(0, 0, l2, r2));
			}
			else {
				printf ("%lld\n", -1ll * aska(0, 0, l1, r1) * askb(1, 1, l2, r2));
			}
		}
		else if (suma[1][r1] - suma[1][l1 - 1] == r1 - l1 + 1) {
			if (sumb[1][r2] - sumb[1][l2 - 1] == r2 - l2 + 1) {
				printf ("%lld\n", 1ll * aska(1, 1, l1, r1) * askb(1, 0, l2, r2));
			}
			else {
				printf ("%lld\n", -1ll * aska(1, 0, l1, r1) * askb(0, 1, l2, r2));
			}
		}
		else {
			if (sumb[0][r2] - sumb[0][l2 - 1] == r2 - l2 + 1) {
				printf ("%lld\n", 1ll * aska(0, 1, l1, r1) * askb(0, 0, l2, r2));
			}
			else if (sumb[1][r2] - sumb[1][l2 - 1] == r2 - l2 + 1) {
				printf ("%lld\n", 1ll * aska(1, 1, l1, r1) * askb(1, 0, l2, r2));
			}
			else {
				printf ("%lld\n", max (-1ll * aska(0, 0, l1, r1) * askb(1, 1, l2, r2), -1ll * aska(1, 0, l1, r1) * askb(0, 1, l2, r2)));
			}
		}
	}
	
	return 0;
}


