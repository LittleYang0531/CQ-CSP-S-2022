#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#define LL long long
#define uint unsigned int
#define uLL unsigned long long
#define mr make_pair
#define pr pair <int, int>
using namespace std;
const int MAXN = 1e5 + 5, inf = 1e9 + 1;
struct node {
	int L, R, fminn, fmaxx, zminn, zmaxx, F;
}tree[2][MAXN << 2];
void read(int &x) {
	x = 0; bool f = 1; char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') f = 0;
	for(; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = (f ? x : -x);
}
int n, m, q, a[2][MAXN];
int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x > y ? x : y; }
void update(node &x, node &y, node &z) {
	x.fminn = Min(y.fminn, z.fminn); x.zminn = Min(y.zminn, z.zminn);
	x.fmaxx = Max(y.fmaxx, z.fmaxx); x.zmaxx = Max(y.zmaxx, z.zmaxx);
	x.F = (y.F | z.F);
}
void build(int f, int p, int l, int r) {
	tree[f][p].L = l; tree[f][p].R = r; 
	tree[f][p].fminn = inf; tree[f][p].fmaxx = -inf;
	tree[f][p].zminn = inf; tree[f][p].zmaxx = -inf;
	if(l == r) {
		if(a[f][l] < 0) tree[f][p].fminn = tree[f][p].fmaxx = a[f][l];
		else if(a[f][l] > 0) tree[f][p].zminn = tree[f][p].zmaxx = a[f][l];
		else tree[f][p].F = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(f, p << 1, l, mid); build(f, p << 1 | 1, mid + 1, r);
	update(tree[f][p], tree[f][p << 1], tree[f][p << 1 | 1]);
}
node ask(int f, int p, int ql, int qr) {
	if(tree[f][p].L >= ql && tree[f][p].R <= qr) return tree[f][p];
	int mid = (tree[f][p].L + tree[f][p].R) >> 1;
	if(mid < ql) return ask(f, p << 1 | 1, ql, qr);
	if(mid >= qr) return ask(f, p << 1, ql, qr);
	node x, y = ask(f, p << 1, ql, qr), z = ask(f, p << 1 | 1, ql, qr); update(x, y, z);
	return x;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int x, y, u, v;
	read(n); read(m); read(q);
	for(int i = 1; i <= n; i ++) read(a[0][i]);
	for(int i = 1; i <= m; i ++) read(a[1][i]);
	build(0, 1, 1, n); build(1, 1, 1, m);
	for(int i = 1; i <= q; i ++) {
		read(x); read(y); read(u); read(v);
		node s = ask(0, 1, x, y), t = ask(1, 1, u, v); LL maxx = -5e18, minn = 5e18;
		if(s.zmaxx != -inf) {
			minn = 5e18;
			if(t.fminn != inf) minn = min(minn, 1ll * s.zmaxx * t.fminn);
			if(t.fmaxx != -inf) minn = min(minn, 1ll * s.zmaxx * t.fmaxx);
			if(t.zmaxx != -inf) minn = min(minn, 1ll * s.zmaxx * t.zmaxx);
			if(t.zminn != inf) minn = min(minn, 1ll * s.zmaxx * t.zminn);
			if(t.F) minn = min(minn, 0ll);
			maxx = max(maxx, minn); 
		}
		if(s.zminn != inf) {
			minn = 5e18;
			if(t.fminn != inf) minn = min(minn, 1ll * s.zminn * t.fminn);
			if(t.fmaxx != -inf) minn = min(minn, 1ll * s.zminn * t.fmaxx);
			if(t.zmaxx != -inf) minn = min(minn, 1ll * s.zminn * t.zmaxx);
			if(t.zminn != inf) minn = min(minn, 1ll * s.zminn * t.zminn);
			if(t.F) minn = min(minn, 0ll);
			maxx = max(maxx, minn); 
		}
		if(s.fmaxx != -inf) {
			minn = 5e18;
			if(t.fminn != inf) minn = min(minn, 1ll * s.fmaxx * t.fminn);
			if(t.fmaxx != -inf) minn = min(minn, 1ll * s.fmaxx * t.fmaxx);
			if(t.zmaxx != -inf) minn = min(minn, 1ll * s.fmaxx * t.zmaxx);
			if(t.zminn != inf) minn = min(minn, 1ll * s.fmaxx * t.zminn);
			if(t.F) minn = min(minn, 0ll);
			maxx = max(maxx, minn); 
		}
		if(s.fminn != inf) {
			minn = 5e18;
			if(t.fminn != inf) minn = min(minn, 1ll * s.fminn * t.fminn);
			if(t.fmaxx != -inf) minn = min(minn, 1ll * s.fminn * t.fmaxx);
			if(t.zmaxx != -inf) minn = min(minn, 1ll * s.fminn * t.zmaxx);
			if(t.zminn != inf) minn = min(minn, 1ll * s.fminn * t.zminn);
			if(t.F) minn = min(minn, 0ll);
			maxx = max(maxx, minn); 
		}
		if(s.F) maxx = max(maxx, 0ll);
		printf("%lld\n", maxx);
	}
	return 0;
}

