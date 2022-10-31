#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

//char buf[1 << 23], *p1 = buf, *p2 = buf;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-')  w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
}

bool mem1;

int a[N], b[N], sum[N], Log[N];
int n, m, q;

struct ST {
	int mx[20][N], mn[20][N];
	
	void init(int op) {
		int V = op ? m : n;
		for(int i = 1; i <= V; ++ i) 
			mx[0][i] = mn[0][i] = (op ? b[i] : a[i]);
		for(int i = 1; (1 << i) <= V; ++ i)
			for(int j = 1; j + (1 << i) - 1 <= V; ++ j)
				mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]),
				mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
	}
	int askmx(int l, int r) {
		int t = Log[r - l + 1];
		return max(mx[t][l], mx[t][r - (1 << t) + 1]);
	}
	int askmn(int l, int r) {
		int t = Log[r - l + 1];
		return min(mn[t][l], mn[t][r - (1 << t) + 1]);
	}
} A, B;

void BF() { // qn
	while(q --) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		int ans = -1e18, mn = 1e18, mx = -1e18;
		for(int j = l2; j <= r2; ++ j)
			mn = min(mn, b[j]), mx = max(mx, b[j]);
			
		for(int i = l1; i <= r1; ++ i) {
//			int res = 1e18;
//			for(int j = l2; j <= r2; ++ j)
//				res = min(res, a[i] * b[j]);
//			ans = max(ans, res);
			if(a[i] >= 0) ans = max(ans, a[i] * mn);
			else ans = max(ans, a[i] * mx);
		}
		printf("%lld\n", ans);
	}
}

int mx[20][N], mn[20][N];
int askmx(int l, int r) {
	int t = Log[r - l + 1];
	return max(mx[t][l], mx[t][r - (1 << t) + 1]);
}
int askmn(int l, int r) {
	int t = Log[r - l + 1];
	return min(mn[t][l], mn[t][r - (1 << t) + 1]);
}

void Solve() {
	Log[0] = -1;
	for(int i = 1; i <= n; ++ i) {
		Log[i] = Log[i >> 1] + 1;
		mx[0][i] = -1e18, mn[0][i] = 1e18;
		if(a[i] < 0) mx[0][i] = a[i];
		if(a[i] > 0) mn[0][i] = a[i];
	}
	for(int i = 1; (1 << i) <= n; ++ i)
		for(int j = 1; j + (1 << i) - 1 <= n; ++ j)
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]),
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
	
	A.init(0), B.init(1);
//	cout << A.askmn(1, n);
	for(int i = 1; i <= n; ++ i)
		sum[i] = sum[i - 1] + (a[i] == 0);
	for(int i = 1; i <= q; ++ i) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		int mnA = A.askmn(l1, r1), mxA = A.askmx(l1, r1);
		int mnB = B.askmn(l2, r2), mxB = B.askmx(l2, r2);
		int mxneg = askmx(l1, r1), mnpos = askmn(l1, r1);
		
//		printf("%d %d %d %d\n", mnA, mxA, mnB, mxB);
		
		int ans = -1e18;
		if(mxA > 0) ans = max(ans, mxA * mnB);
		if(mnpos != 1e18) ans = max(ans, mnpos * mnB);
		if(mnA < 0) ans = max(ans, mnA * mxB);
		if(mxneg != -1e18) ans = max(ans, mxneg * mxB);
		if(sum[r1] - sum[l1 - 1] > 0) ans = max(ans, (int)0);
		printf("%lld\n", ans);
	}
}

bool mem2;

signed main() {
	file();
//	freopen("game4.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	printf("Memory Cost is: %lf\n", (&mem2 - &mem1) / 1024. / 1024.);

	n = read(), m = read(), q = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	for(int i = 1; i <= m; ++ i) b[i] = read();
	
	if(n <= 1000 && m <= 1000 && q <= 1000) return BF(), 0;
	Solve();
	return 0;
}
