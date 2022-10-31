#include <stdio.h>
#include <math.h>

typedef long long ll;

inline int min(int a, int b){
	return a < b ? a : b;
}

inline int max(int a, int b){
	return a > b ? a : b;
}

typedef struct {
	int stmin[100007][17], stmax[100007][17], st_non_pos_min[100007][17], st_non_neg_min[100007][17], st_neg_abs_min[100007][17], st_pos_min[100007][17];
	
	inline void init(int n, int a[]){
		int m = log2(n);
		for (int i = 1; i <= n; i++){
			stmin[i][0] = stmax[i][0] = a[i];
			st_non_pos_min[i][0] = a[i] <= 0 ? a[i] : 0x80000000;
			st_non_neg_min[i][0] = a[i] >= 0 ? a[i] : 0x7fffffff;
			st_neg_abs_min[i][0] = a[i] < 0 ? a[i] : 0x80000000;
			st_pos_min[i][0] = a[i] > 0 ? a[i] : 0x7fffffff;
		}
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n - (1 << i) + 1; j++){
				stmin[j][i] = min(stmin[j][i - 1], stmin[j + (1 << (i - 1))][i - 1]);
				stmax[j][i] = max(stmax[j][i - 1], stmax[j + (1 << (i - 1))][i - 1]);
				st_non_pos_min[j][i] = max(st_non_pos_min[j][i - 1], st_non_pos_min[j + (1 << (i - 1))][i - 1]);
				st_non_neg_min[j][i] = min(st_non_neg_min[j][i - 1], st_non_neg_min[j + (1 << (i - 1))][i - 1]);
				st_neg_abs_min[j][i] = max(st_neg_abs_min[j][i - 1], st_neg_abs_min[j + (1 << (i - 1))][i - 1]);
				st_pos_min[j][i] = min(st_pos_min[j][i - 1], st_pos_min[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	
	inline int get_min(int l, int r){
		int t = log2(r - l + 1);
		return min(stmin[l][t], stmin[r - (1 << t) + 1][t]);
	}
	
	inline int get_max(int l, int r){
		int t = log2(r - l + 1);
		return max(stmax[l][t], stmax[r - (1 << t) + 1][t]);
	}
	
	inline int get_non_pos_min(int l, int r){
		int t = log2(r - l + 1);
		return max(st_non_pos_min[l][t], st_non_pos_min[r - (1 << t) + 1][t]);
	}
	
	inline int get_non_neg_min(int l, int r){
		int t = log2(r - l + 1);
		return min(st_non_neg_min[l][t], st_non_neg_min[r - (1 << t) + 1][t]);
	}
	
	inline int get_neg_abs_min(int l, int r){
		int t = log2(r - l + 1);
		return max(st_neg_abs_min[l][t], st_neg_abs_min[r - (1 << t) + 1][t]);
	}
	
	inline int get_pos_min(int l, int r){
		int t = log2(r - l + 1);
		return min(st_pos_min[l][t], st_pos_min[r - (1 << t) + 1][t]);
	}
} ST;

ST st1, st2;
int a[100007], posa[100007], zeroa[100007], nega[100007], b[100007], posb[100007], zerob[100007], negb[100007];

inline ll max(ll a, ll b){
	return a > b ? a : b;
}

int main(){
	int n, m, q;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		posa[i] = posa[i - 1] + (a[i] > 0);
		zeroa[i] = zeroa[i - 1] + (a[i] == 0);
		nega[i] = nega[i - 1] + (a[i] < 0);
	}
	for (int i = 1; i <= m; i++){
		scanf("%d", &b[i]);
		posb[i] = posb[i - 1] + (b[i] > 0);
		zerob[i] = zerob[i - 1] + (b[i] == 0);
		negb[i] = negb[i - 1] + (b[i] < 0);
	}
	st1.init(n, a);
	st2.init(m, b);
	for (int i = 1; i <= q; i++){
		int l1, r1, l2, r2;
		ll ans = 0x8000000000000000ll;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		// 1. L choose a A[x] which is negative
		if (nega[r1] - nega[l1 - 1] > 0){
			int x, y;
			if (posb[r2] - posb[l2 - 1] == 0){
				x = st1.get_min(l1, r1);
				y = st2.get_non_pos_min(l2, r2);
			} else {
				x = st1.get_neg_abs_min(l1, r1);
				y = st2.get_max(l2, r2);
			}
			ans = (ll)x * y;
		}
		// 2. L choose a A[x] which is zero
		if (zeroa[r1] - zeroa[l1 - 1] > 0){
			if (ans < 0) ans = 0;
		}
		// 3. L choose a A[x] which is positive
		if (posa[r1] - posa[l1 - 1] > 0){
			int x, y;
			if (negb[r2] - negb[l2 - 1] == 0){
				x = st1.get_max(l1, r1);
				y = st2.get_non_neg_min(l2, r2);
			} else {
				x = st1.get_pos_min(l1, r1);
				y = st2.get_min(l2, r2);
			}
			ans = max(ans, (ll)x * y);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
