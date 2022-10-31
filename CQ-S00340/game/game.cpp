#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void chkmax(T &x,T y) {x = max(x,y);}
template <typename T> inline void chkmin(T &x,T y) {x = min(x,y);}
inline int read() {
	int res = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return res * f;
}
const long long INF = 0x3f3f3f3f3f3f3f3f; 
const int MAXN = 1e5 + 5;
int n,m,q;
struct Segment_Tree {
	struct Node {
		int l,r;
		long long Min,Max;
	} node[MAXN << 2];
	long long a[MAXN];
	#define lson (p << 1)
	#define rson (p << 1 | 1)
	inline void pushup(int p) {
		node[p].Min = min(node[lson].Min,node[rson].Min);
		node[p].Max = max(node[lson].Max,node[rson].Max);
	}
	inline void build(int p,int l,int r) {
		node[p].l = l,node[p].r = r;
		if (l == r) {
			node[p].Min = node[p].Max = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(lson,l,mid),build(rson,mid + 1,r);
		pushup(p);
	}
	inline long long query_max(int x,int y,int p) {
		if (x <= node[p].l && node[p].r <= y) {
			return node[p].Max;
		}
		int mid = node[p].l + node[p].r >> 1;
		long long res = -INF;
		if (x <= mid) chkmax(res,query_max(x,y,lson));
		if (y > mid) chkmax(res,query_max(x,y,rson));
		return res;
	}
	inline long long query_min(int x,int y,int p) {
		if (x <= node[p].l && node[p].r <= y) {
			return node[p].Min;
		}
		int mid = node[p].l + node[p].r >> 1;
		long long res = INF;
		if (x <= mid) chkmin(res,query_min(x,y,lson));
		if (y > mid) chkmin(res,query_min(x,y,rson));
		return res;
	}
} sega,segb;
int main(void) {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	bool ok1 = true;
	for (int i = 1;i <= n; ++ i) {
		scanf("%lld",&sega.a[i]);
		if (sega.a[i] < 0) ok1 = false;
	}
	for (int i = 1;i <= m; ++ i) {
		scanf("%lld",&segb.a[i]);
		if (segb.a[i] < 0) ok1 = false;
	}
	sega.build(1,1,n),segb.build(1,1,m);
	while (q --) {
		int l1,r1,l2,r2;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		if (l1 == r1) {
			long long ta = sega.a[l1];
			if (ta < 0) printf("%lld\n",ta * segb.query_max(l2,r2,1));
			else printf("%lld\n",ta * segb.query_min(l2,r2,1));
		} else if (l2 == r2) {
			long long ta = segb.a[l2];
			if (ta < 0) printf("%lld\n",ta * sega.query_min(l1,r1,1));
			else printf("%lld\n",ta * sega.query_max(l1,r1,1));
		} else if (ok1) {
			printf("%lld\n",sega.query_max(l1,r1,1) * segb.query_min(l2,r2,1));
		} else {
			long long ans1,ans2;
			ans1 = -INF;
			long long Max = segb.query_max(l2,r2,1),Min = segb.query_min(l2,r2,1);
			for (int i = l1;i <= r1; ++ i) {
				if (sega.a[i] < 0) chkmax(ans1,sega.a[i] * Max);
				else chkmax(ans1,sega.a[i] * Min);
			}
			ans2 = INF;
			Max = sega.query_max(l1,r1,1),Min = sega.query_min(l1,r1,1);
			for (int i = l2;i <= r2; ++ i) {
				if (segb.a[i] < 0) chkmin(ans2,segb.a[i] * Min);
				else chkmin(ans2,segb.a[i] * Max);
			}
			printf("%lld\n",min(ans1,ans2));
		}
	}
	
	return 0;
}

