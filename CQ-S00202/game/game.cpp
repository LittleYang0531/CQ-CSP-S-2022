#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct sheet{
	int s[100005], f[100005][10], t;
	bool p;  // 1=max, 0=min
	void buildf() {
		for (int i = 1; i <= t; i++) f[i][0] = s[i];
		int m = log2(t);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= i+(1<<i); j++)
				f[j][i] = (p?max(f[j][i-1], f[j+(1<<(i-1))][i-1]):min(f[j][i-1], f[j+(1<<(i-1))][i-1]));
	}
	int query(int l, int r) {
		if (l == r) return f[l][0];
		int m = log2(r-l+1);
		return (p?max(f[l][m], f[l+(1<<(m-1))][m]):min(f[l][m], f[l+(1<<(m-1))][m]));
	}
};

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	sheet a[2][2], b[2][2];  // 第一维：正负情况，第二维：最大最小情况 
	a[1][0].p = 0; a[1][1].p = 1; b[1][0].p = 0; b[1][1].p = 1; a[0][1].p = 1; a[0][0].p = 0; b[0][1].p = 1; b[0][0].p = 0;
	int x, y, z, w;
	x = y = z = w = 0;
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp >= 0) { a[1][0].s[++x]; a[1][1].s[++x]; }
		if (tmp <= 0) { a[0][1].s[++z]; a[0][0].s[++z]; }
	}
	for (int i = 1; i <= m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp >= 0) { b[1][0].s[++y]; b[1][1].s[++y]; }
		if (tmp <= 0) { b[0][1].s[++w]; b[0][0].s[++w]; }
	}
	a[1][0].t = x; a[1][1].t = x; b[1][0].t = y; b[1][1].t = y; a[0][1].t = z; a[0][0].t = z; b[0][1].t = w; b[0][0].t = w;
	a[1][0].buildf(); a[1][1].buildf(); b[1][0].buildf(); b[1][1].buildf(); a[0][1].buildf(); a[0][0].buildf(); b[0][1].buildf(); b[0][0].buildf();
	for (int i = 1; i <= q; i++) {
		int l1, r1, l2, r2, ans = -1;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		for (int i1 = 0; i1 <= 1; i1++)
			for (int j1 = 0; j1 <= 1; j1++)
				for (int i2 = 0; i2 <= 1; i2++)
					for (int j2 = 0; j2 <= 1; j2++)
						ans = max(ans, a[i1][j1].query(l1, r1)+b[i2][j2].query(l2, r2));
		printf("%d\n", ans);
//		printf("%d\n", max(a[1][0].query(l1, r1)+b[1][0].query(l2, r2),max(a[1][0].query(l1, r1)+b[0][1].query(l2, r2),max(a[0][1].query(l1, r1)+b[1][0].query(l2, r2),a[0][1].query(l1, r1)+b[0][1].query(l2, r2)))));
//		printf("%d\n", a[0][1].query(l1, r1)+b[1][0].query(l2, r2));
//	                                                                                                        
	}
	return 0;
}
