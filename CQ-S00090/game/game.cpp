#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define SF scanf
#define PF printf
int n, m;
struct Tree {
	int l, r;
	long long Min;
}tree[1005][1005 << 2];
long long a[1005], b[1005], s[1005][1005];
void make_Tree(int p, int i, int l, int r) {
	tree[p][i].l = l, tree[p][i].r = r;
	if(l == r) {
		tree[p][i].Min = s[p][l];
		return;
	}
	int mid = l + r >> 1;
	make_Tree(p, i << 1, l, mid), make_Tree(p, i << 1 | 1, mid + 1, r);
	tree[p][i].Min = min(tree[p][i << 1].Min, tree[p][i << 1 | 1].Min); 
}
long long Query(int p, int i, int l, int r) {
	if(l <= tree[p][i].l && tree[p][i].r <= r) return tree[p][i].Min;
	long long ans = 1e12;
	if(tree[p][i << 1].r >= l) ans = min(ans, Query(p, i << 1, l, r));
	if(tree[p][i << 1 | 1].l <= r) ans = min(ans, Query(p, i << 1 | 1, l, r));
	return ans; 
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int q;
	SF("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i++) SF("%lld", &a[i]);
	for(int i = 1; i <= m; i++) SF("%lld", &b[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) s[i][j] = a[i] * b[j];
		make_Tree(i, 1, 1, m);
	}
	while(q--) {
		int l1, r1, l2, r2;
		SF("%d%d%d%d", &l1, &r1, &l2, &r2);
		long long ans = -1e12;
		for(int i = l1; i <= r1; i++) ans = max(ans, Query(i, 1, l2, r2));
		PF("%lld\n", ans);
	}
	return 0;
} 
