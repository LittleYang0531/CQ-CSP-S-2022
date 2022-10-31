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
const int MAXN = 2e5 + 5;
const LL lof = 1e18;
__int128 Min(__int128 x, __int128 y) { return x < y ? x : y; }
int n, q, k, a[MAXN];
vector <int> v[MAXN];
struct node {
	__int128 s[3][3];
	node() {
		for(int i = 0; i <= 2; i ++) for(int j = 0; j <= 2; j ++) s[i][j] = (LL)1e18;
	}
	node operator * (const node P) const {
		node ans;
		for(int k = 0; k <= 2; k ++) {
			for(int i = 0; i <= 2; i ++) {
				for(int j = 0; j <= 2; j ++) {
					ans.s[i][j] = Min(ans.s[i][j], s[i][k] + P.s[k][j]);
				}
			}
		}
		return ans;
	}
};
struct sgt {
	int L, R;
	node mat[2]; // 正、反 
}tree[MAXN << 2];
/*
tree
k=1，两个点之间的路径，lca 实现 16pts
k=2, val[i] 为与 i 相连(包括 i)的最小权值，dp 实现，matrix 40 pts
k=3，同理 

打不完了. 
*/
int d[MAXN], dfn[MAXN], mp[MAXN], tot, son[MAXN], siz[MAXN], Fa[MAXN], tp[MAXN];
int minn[MAXN][3];
void read(int &x) {
	x = 0; bool f = 1; char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') f = 0;
	for(; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = (f ? x : -x);
}
void dfs(int x, int fa) {
	d[x] = d[fa] + 1; siz[x] = 1; Fa[x] = fa;
	for(auto y : v[x]) {
		if(y == fa) continue;
		dfs(y, x); siz[x] += siz[y];
		if(siz[son[x]] < siz[y]) son[x] = y;
	}
}
void dfs1(int x, int t) {
	dfn[++ tot] = x; mp[x] = tot; tp[x] = t;
	if(son[x]) dfs1(son[x], t);
	for(auto y : v[x]) {
		if(y == son[x] || y == Fa[x]) continue;
		dfs1(y, y);
	}
}
void update(sgt &x, sgt &y, sgt &z) {
	x.mat[0] = y.mat[0] * z.mat[0];
	x.mat[1] = z.mat[1] * y.mat[1];
}
void build(int F, int p, int l, int r) {
	tree[p].L = l; tree[p].R = r;
	if(l == r) {
		if(F == 2) {
			tree[p].mat[0].s[0][0] = lof; tree[p].mat[0].s[0][1] = a[dfn[l]];
			tree[p].mat[0].s[1][0] = minn[dfn[l]][1]; tree[p].mat[0].s[1][1] = a[dfn[l]];
			
			tree[p].mat[1] = tree[p].mat[0];
		}
		return;
	}
	int mid = (l + r) >> 1; build(F, p << 1, l, mid); build(F, p << 1 | 1, mid + 1, r);
	update(tree[p], tree[p << 1], tree[p << 1 | 1]);
}
node ask(int F, int p, int l, int r, int qwq) {
//	printf("|%d %d %d %d|\n", tree[p].L, tree[p].R, l, r);
	if(tree[p].L >= l && tree[p].R <= r) return tree[p].mat[qwq];
	int mid = (tree[p].L + tree[p].R) >> 1;
	if(mid < l) return ask(F, p << 1 | 1, l, r, qwq);
	if(mid >= r) return ask(F, p << 1, l, r, qwq);
	node x, y = ask(F, p << 1, l, r, qwq), z = ask(F, p << 1 | 1, l, r, qwq);
	if(qwq == 0) x = y * z;
	return x = z * y;
	return x;
}
void write(int F, node x) {
	for(int i = 0; i < F; i ++) {
		for(int j = 0; j < F; j ++) {
			printf("%lld ", (LL)x.s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
node query(int F, int x, int y) {
	node lft, rgt;
	for(int i = 0; i < F; i ++) {
		for(int j = 0; j < F; j ++) {
			lft.s[i][j] = rgt.s[i][j] = 0;
		}
	}
	for(int i = 0; i < F; i ++) {
		lft.s[i][i] = rgt.s[i][i] = 1;
	}
	while(tp[x] != tp[y]) {
	//	printf("|%d %d %d %d %d %d|\n", x, y,mp[tp[x]], mp[x],mp[tp[y]], mp[y]);
		if(d[tp[x]] > d[tp[y]]) lft = lft * ask(F, 1, mp[tp[x]], mp[x], 0), x = Fa[tp[x]];
		else rgt = ask(F, 1, mp[tp[y]], mp[y], 1) * rgt, y = Fa[tp[y]];
	//	write(F, ask(F, 1, mp[tp[y]], mp[y], 1));
//		printf("lft\n");
//		write(F, lft); write(F, rgt);
	}
	if(d[x] < d[y]) rgt = ask(F, 1, mp[x], mp[y], 1) * rgt;
	else lft = lft * ask(F, 1, mp[y], mp[x], 0);
	lft = lft * rgt; return lft;
}
int mb, wh[MAXN], dis, viss[MAXN];
LL dp[MAXN][3];
bool DFS(int x, int fa, int qaq) {
//	printf("|%d %d|",x,fa);
	if(x == mb) {
		wh[qaq] = x; dis = qaq; return 1;
	}
	for(auto y : v[x]) {
		if(viss[y]) continue;
		viss[y] = 1;
		if(DFS(y, x, qaq + 1)) {
			wh[qaq] = x; wh[qaq + 1] = y; return 1;
		}
	}
	return 0;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int x, y;
	read(n); read(q); read(k);
	for(int i = 1; i <= n; i ++) read(a[i]), minn[i][0] = a[i];
	for(int i = 1; i < n; i ++) {
		read(x); read(y); v[x].push_back(y); v[y].push_back(x);
	}
	for(int T = 1; T <= 2; T ++) {
		for(int i = 1; i <= n; i ++) {
			for(auto j : v[i]) {
				minn[j][T] = min(minn[j][T], minn[i][T - 1]);
			}
		}
	}
//	printf("*%d %d*", a[138], minn[138][1]);
	if(n <= 2000) {
		while(q --) {
			read(x); read(y); mb = y; dis = 0;
			for(int i = 1; i <= n; i ++) viss[i] = 0;
			viss[x] = 1;
			DFS(x, 0, 1); LL res = 0;
			for(int i = 0; i <= n; i ++) for(int j = 0; j <= 2; j ++) dp[i][j] = lof;
			if(k == 1) {
				for(int i = 1; i <= dis; i ++) res += a[wh[i]];
				printf("%lld\n", res);
			}
			if(k == 2) {
				dp[1][0] = a[wh[1]];
				for(int i = 2; i <= dis; i ++) {
					dp[i][1] = dp[i - 1][0] + min(minn[wh[i]][1], a[wh[i]]);
					dp[i][0] = min(min(dp[i - 2][0], dp[i - 1][0]), dp[i - 1][1]) + a[wh[i]];
				}
				printf("%lld\n", dp[dis][0]);
			}
			if(k == 3) {
				dp[1][0] = a[wh[1]];
				for(int i = 2; i <= dis; i ++) {
					dp[i][2] = min(dp[i - 1][0] + minn[wh[i - 1]][1], dp[i - 1][0] + minn[wh[i]][2]);
					dp[i][1] = min(dp[i - 1][1] + minn[wh[i]][1], dp[i - 1][0] + minn[wh[i]][1]);
					if(i >= 3) dp[i][0] = dp[i - 3][0] + a[wh[i]];
					dp[i][0] = min(dp[i][0], dp[i - 2][1] + a[wh[i]]);
					
					dp[i][0] = min(dp[i][0], dp[i - 2][0] + a[wh[i]]);
					dp[i][0] = min(dp[i][0], dp[i - 1][2] + a[wh[i]]);
					dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[wh[i]]);
					
					dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[wh[i]]);
				}
				printf("%lld\n", dp[dis][0]);
			}
		}
		return 0;
	}
	if(k == 2) {
		dfs(1, 0); dfs1(1, 1);
		build(2, 1, 1, n);
		while(q --) {
			read(x); read(y);
			node ans = query(2, x, y); printf("%lld\n", (LL)ans.s[1][1]);
		}
	}
	
	return 0;
}

