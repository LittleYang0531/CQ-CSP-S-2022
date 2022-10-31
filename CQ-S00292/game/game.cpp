#include <bits/stdc++.h>
#define st first
#define nd second
#define db double
#define re register
#define pb push_back
#define mk make_pair
#define int long long
#define ull unsigned long long
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;
const int N = 1e5 + 10, INF = 2e18;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
int n, m, q;
int a[N], b[N], C[N];
#define ls k << 1
#define rs k << 1 | 1
#define mid ((l + r) >> 1)
struct SegmentTree{
	int mi[N << 2], mx[N << 2], cnt[N << 2];
	inline void pushup(int k) { mi[k] = min(mi[ls], mi[rs]), mx[k] = max(mx[ls], mx[rs]), cnt[k] = cnt[ls] + cnt[rs]; }
	inline void build(int k, int l, int r, int op){
		if(l == r){
			if(!op){ //正数 
				if(C[l] >= 0) mi[k] = mx[k] = C[l], cnt[k] = 1;
				else mi[k] = INF, mx[k] = -INF;
			}
			else{
				if(C[l] <= 0) mi[k] = mx[k] = C[l], cnt[k] = 1;
				else mi[k] = INF, mx[k] = -INF;
			}
			return;
		}
		build(ls, l, mid, op), build(rs, mid + 1, r, op);
		pushup(k);
	}
	inline int Query_cnt(int k, int l, int r, int x, int y){
		if(l >= x && r <= y) return cnt[k];
		if(y <= mid) return Query_cnt(ls, l, mid, x, y);
		else if(x > mid) return Query_cnt(rs, mid + 1, r, x, y); 
		else return Query_cnt(ls, l, mid, x, mid) + Query_cnt(rs, mid + 1, r, mid + 1, y);
	}
	inline int Query_mi(int k, int l, int r, int x, int y){
		if(l >= x && r <= y) return mi[k];
		if(y <= mid) return Query_mi(ls, l, mid, x, y);
		else if(x > mid) return Query_mi(rs, mid + 1, r, x, y); 
		else return min(Query_mi(ls, l, mid, x, mid), Query_mi(rs, mid + 1, r, mid + 1, y));
	}
	inline int Query_mx(int k, int l, int r, int x, int y){
		if(l >= x && r <= y) return mx[k];
		if(y <= mid) return Query_mx(ls, l, mid, x, y);
		else if(x > mid) return Query_mx(rs, mid + 1, r, x, y); 
		else return max(Query_mx(ls, l, mid, x, mid), Query_mx(rs, mid + 1, r, mid + 1, y));
	}
}A[2], B[2]; //一个正数线段树，一个负数线段树 
signed main() //100pts
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(), m = read(), q = read();
	for(re int i = 1; i <= n; i++) a[i] = read(), C[i] = a[i];
	A[0].build(1, 1, n, 0), A[1].build(1, 1, n, 1);
	for(re int i = 1; i <= m; i++) b[i] = read(), C[i] = b[i];
	B[0].build(1, 1, m, 0), B[1].build(1, 1, m, 1);
	while(q--){
		int la = read(), ra = read(), lb = read(), rb = read(), ans = -INF, x, y;
		if(A[0].Query_cnt(1, 1, n, la, ra)){ //可以选择正数 
			if(B[1].Query_cnt(1, 1, m, lb, rb)){
				x = A[0].Query_mi(1, 1, n, la, ra), y = B[1].Query_mi(1, 1, m, lb, rb);
				ans = max(ans, x * y);
			}
			else{
				x = A[0].Query_mx(1, 1, n, la, ra), y = B[0].Query_mi(1, 1, m, lb, rb);
				ans = max(ans, x * y);
			}
		}
		if(A[1].Query_cnt(1, 1, n, la, ra)){
			if(B[0].Query_cnt(1, 1, m, lb, rb)){
				x = A[1].Query_mx(1, 1, n, la, ra), y = B[0].Query_mx(1, 1, m, lb, rb);
				ans = max(ans, x * y);
			}
			else{
				x = A[1].Query_mi(1, 1, n, la, ra), y = B[1].Query_mx(1, 1, m, lb, rb);
				ans = max(ans, x * y);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
