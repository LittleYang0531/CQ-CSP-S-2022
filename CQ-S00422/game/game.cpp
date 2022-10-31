// Never Gonna Let¡ú You¡ú Down¨K 
#include <cstdio>
#include <algorithm>
using namespace std;
namespace yj {
const int MAXN = 114514;
int a[MAXN], b[MAXN];
int ap[MAXN], an[MAXN], bp[MAXN], bn[MAXN];
int apt, ant, bpt, bnt;
struct maxrmq {
	int rm[MAXN][18], Lg[MAXN];
	void build(int n, int *x, int *w) {
		for (int i = 1; i <= n; i++) rm[i][0] = x[w[i]];
		Lg[1] = 0; for (int i = 2; i <= n; i++) Lg[i] = Lg[i >> 1] + 1;
		for (int i = 1; i <= 17; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				rm[j][i] = max(rm[j][i - 1], rm[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	int query(int l, int r) {
		int L = Lg[r - l + 1];
		return max(rm[l][L], rm[r - (1 << L) + 1][L]);
	}
} maxr[4];
struct minrmq {
	int rm[MAXN][18], Lg[MAXN];
	void build(int n, int *x, int *w) {
		for (int i = 1; i <= n; i++) rm[i][0] = x[w[i]];
		Lg[1] = 0; for (int i = 2; i <= n; i++) Lg[i] = Lg[i >> 1] + 1;
		for (int i = 1; i <= 17; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				rm[j][i] = min(rm[j][i - 1], rm[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	int query(int l, int r) {
//		printf("(q) %d %d\n", l, r);
		int L = Lg[r - l + 1];
		return min(rm[l][L], rm[r - (1 << L) + 1][L]);
	}
} minr[4];
int read() {
	bool op = 1;
	char ch; while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') op = !op;
	int x = ch - '0'; while ((ch = getchar()) >= '0') x = x * 10 + ch - '0';
	return op ? x : -x;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, q; scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	for (int i = 1; i <= n; i++) if (a[i] >= 0) ap[++apt] = i;
	for (int i = 1; i <= n; i++) if (a[i] < 0) an[++ant] = i;
	for (int i = 1; i <= m; i++) if (b[i] >= 0) bp[++bpt] = i;
	for (int i = 1; i <= m; i++) if (b[i] < 0) bn[++bnt] = i;
	maxr[0].build(apt, a, ap); minr[0].build(apt, a, ap);
	maxr[1].build(ant, a, an); minr[1].build(ant, a, an);
	maxr[2].build(bpt, b, bp); minr[2].build(bpt, b, bp);
	maxr[3].build(bnt, b, bn); minr[3].build(bnt, b, bn);
	while (q--) {
		int x1, x2, x3, x4; x1 = read(); x2 = read(); x3 = read(); x4 = read();
		pair<int, int> apr, anr, bpr, bnr;
		apr.first = lower_bound(ap + 1, ap + 1 + apt, x1) - ap;
		apr.second = upper_bound(ap + 1, ap + 1 + apt, x2) - ap - 1;
		anr.first = lower_bound(an + 1, an + 1 + ant, x1) - an;
		anr.second = upper_bound(an + 1, an + 1 + ant, x2) - an - 1;
		bpr.first = lower_bound(bp + 1, bp + 1 + bpt, x3) - bp;
		bpr.second = upper_bound(bp + 1, bp + 1 + bpt, x4) - bp - 1;
		bnr.first = lower_bound(bn + 1, bn + 1 + bnt, x3) - bn;
		bnr.second = upper_bound(bn + 1, bn + 1 + bnt, x4) - bn - 1;
		long long ans1 = 0, ans2 = 0, ans = -0x7f7f7f7f7f7f7f7f;
		if (anr.first <= anr.second) {
			if (bpr.first > bpr.second) {
//				puts("ev1");
				ans1 = 1ll * minr[1].query(anr.first, anr.second) * maxr[3].query(bnr.first, bnr.second);
			}
			else {
//				puts("ev2");
				ans1 = 1ll * maxr[1].query(anr.first, anr.second) * maxr[2].query(bpr.first, bpr.second);
			}
			ans = max(ans, ans1);
		}
		if (apr.first <= apr.second) {
			if (bnr.first > bnr.second) {
//				puts("ev3");
				ans2 = 1ll * maxr[0].query(apr.first, apr.second) * minr[2].query(bpr.first, bpr.second);
//				printf("%d %d\n", maxr[0].query(apr.first, apr.second), minr[2].query(bpr.first, bpr.second));
			}
			else {
//				puts("ev4");
				ans2 = 1ll * minr[0].query(apr.first, apr.second) * minr[3].query(bnr.first, bnr.second);
			}
			ans = max(ans, ans2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
}
int main() {return yj::main();} // mem 72220kb
