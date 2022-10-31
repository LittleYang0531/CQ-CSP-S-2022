#include<bits/stdc++.h>
#define LL long long
#define mes(s, x) memset(s, x, sizeof(s))
#define lc 2 * i
#define rc 2 * i + 1
#define MAXN 200005
using namespace std;
int k;
struct node{
	LL a[3][3];
	int l;
	node(){
		l = 0;
		mes(a, 0x3f);
	}
	node(int l0){
		l = l0;
		mes(a, 0x3f);
	}
	node operator+(const node x){
		node t(l + x.l);
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				for(int p = 0; p < k; p++){
					for(int q = 0; p + q < k; q++){
						t.a[i][j] = min(t.a[i][j], a[i][p] + x.a[q][j]);
					}
				}
				if(x.l <= j) t.a[i][j] = min(t.a[i][j], a[i][j - x.l]);
				if(l <= i) t.a[i][j] = min(t.a[i][j], x.a[i - l][j]);
			}
		}
		return t;
	}
	node operator~(){
		node t(l);
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				t.a[i][j] = a[j][i];
			}
		}
		return t;
	}
} hiro;
struct tree{
	int l, r;
	node x;
}a[4 * MAXN];
vector<int> G[MAXN];
int v[MAXN], fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], dfn[MAXN], bad[MAXN], top[MAXN], cnt;
void dfs(int i){
	siz[i] = 1;
	int x;
	for(int j = 0; j < G[i].size(); j++){
		x = G[i][j];
		if(x == fa[i]) continue;
		fa[x] = i;
		dep[x] = dep[i] + 1;
		dfs(x);
		siz[i] += siz[x];
		if(siz[x] > siz[son[i]]) son[i] = x;
	}
}
void dfs2(int i, int tp){
	top[i] = tp;
	dfn[i] = ++cnt;
	bad[cnt] = i;
	if(son[i]) dfs2(son[i], tp);
	int x;
	for(int j = 0; j < G[i].size(); j++){
		x = G[i][j];
		if(x == fa[i] || x == son[i]) continue;
		dfs2(x, x);
	}
}
void build(int i, int l, int r){
	a[i].l = l, a[i].r = r, a[i].x.l = r - l + 1;
	if(l == r){
		a[i].x.a[0][0] = v[bad[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	a[i].x = a[lc].x + a[rc].x;
}
node tot(int i, int l, int r){
	if(l > r) return hiro;
	if(l <= a[i].l && a[i].r <= r) return a[i].x;
	int mid = (a[i].l + a[i].r) / 2;
	if(r <= mid) return tot(lc, l, r);
	else if(mid < l) return tot(rc, l, r);
	return tot(lc, l, r) + tot(rc, l, r);
}
node lca(int x, int y){
	node px(0), py(0);
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]){
			swap(x, y);
			swap(px, py);
		}
		px = px + ~tot(1, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]){
		swap(x, y);
		swap(px, py);
	}
	px = px + ~tot(1, dfn[y], dfn[x]);
	return px + (~py);
}
int main(){
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int n, q, x, y;
	scanf("%d %d %d", &n, &q, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	dfs2(1, 1);
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		scanf("%d %d", &x, &y);
		printf("%lld\n", lca(x, y).a[0][0]);
	}
	return 0;
}
