#include <bits/stdc++.h>
#define Inf 0x7fffffff / 2
using namespace std;
const int N = 1e5 + 5;

int n, m, q;
int a[N], b[N];

struct node {
	int l, r, min_a, max_a, min_b, max_b, zero_a, zero_b, close_one_a, close_one_b_zheng, close_one_b_fu;
} t[N << 1];

int Max(int a, int b) {return a > b ? a : b;}
int Min(int a, int b) {return a < b ? a : b;}
int ABS(int a) {return a > 0 ? a : -a;}

void update(int rt) {
	t[rt].max_a = Max(t[rt << 1].max_a, t[rt << 1 | 1].max_a);
	t[rt].min_a = Min(t[rt << 1].min_a, t[rt << 1 | 1].min_a);
	t[rt].zero_a = Max(t[rt << 1].zero_a, t[rt << 1 | 1].zero_a);
	
	t[rt].max_b = Max(t[rt << 1].max_b, t[rt << 1 | 1].max_b);
	t[rt].min_b = Min(t[rt << 1].min_b, t[rt << 1 | 1].min_b);
	t[rt].zero_b = Max(t[rt << 1].zero_b, t[rt << 1 | 1].zero_b);
	
	if(ABS(t[rt << 1].close_one_a) > ABS(t[rt << 1 | 1].close_one_a))
		t[rt].close_one_a = t[rt << 1 | 1].close_one_a;
	else 
		t[rt].close_one_a = t[rt << 1].close_one_a;
		
	t[rt].close_one_b_zheng = Min(t[rt << 1].close_one_b_zheng, t[rt << 1 | 1].close_one_b_zheng);
	t[rt].close_one_b_fu = max(t[rt << 1].close_one_b_fu, t[rt << 1 | 1].close_one_b_fu);
	
	return ;
}

node merge(node a, node b) {
	node p;
	p.max_a = Max(a.max_a, b.max_a);
	p.min_a = Min(a.min_a, b.min_a);
	p.zero_a = Max(a.zero_a, b.zero_a);
	
	p.max_b = Max(a.max_b, b.max_b);
	p.min_b = Min(a.min_b, b.min_b);
	p.zero_b = Max(a.zero_b, b.zero_b);
	
	if(ABS(a.close_one_a) > ABS(b.close_one_a))
		p.close_one_a = b.close_one_a;
	else 
		p.close_one_a = a.close_one_a;
	
	p.close_one_b_fu = max(a.close_one_b_fu, b.close_one_b_fu);
	p.close_one_b_zheng = min(a.close_one_b_zheng, b.close_one_b_zheng);
	
	return p;
}

void build(int l, int r, int rt) {
	t[rt].l = l, t[rt].r = r;
	t[rt].close_one_a = Inf;
	t[rt].close_one_b_zheng = Inf;
	t[rt].close_one_b_fu = -Inf;
	if(l == r) {
		t[rt].max_a = t[rt].min_a = b[l];
		t[rt].min_b = t[rt].max_b = a[l];	
		if(a[l] == 0)
			t[rt].zero_a = t[rt].zero_b = 1;
		t[rt].close_one_a = b[l];
	t[rt].close_one_b_zheng = max(a[l],0);
	t[rt].close_one_b_fu = min(a[l], 0);
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	update(rt);
}

node Que(int rt, int l, int r) {
	if(t[rt].l >= l && t[rt].r <= r)
		return t[rt];
	int mid = t[rt].l + t[rt].r >> 1;
	if(mid >= l && mid < r)
		return merge(Que(rt << 1, l, r), Que(rt << 1 | 1, l, r));
	else if(mid >= l)
		return Que(rt << 1, l, r);
	else 
		return Que(rt << 1 | 1, l, r);
}

int work(node a1, node b1) {
	if(a1.max_a < 0) {
		if(b1.max_b < 0)
			return a1.max_a * b1.min_b;
		
		if(b1.min_b > 0) 
			return a1.min_a * b1.min_b;
		
		if(b1.max_b > 0 && b1.min_b < 0)
			return b1.min_b * a1.max_a;
	}
	
	if(a1.min_a > 0) {
		if(b1.max_b < 0)
			return a1.max_a * b1.max_b;
		
		if(b1.min_b > 0)
			return a1.min_b * b1.max_b;
		
		if(b1.min_b < 0 && b1.max_b > 0)
			return a1.min_a * b1.max_b;
	}
	
	if(a1.max_a > 0 && a1.min_a < 0) {
		if(b1.zero_b) return 0;
		if(b1.close_one_b_fu != 0 && b1.close_one_b_zheng != 0) 
			return max(Min(b1.close_one_b_fu * a1.max_a, b1.close_one_b_fu * a1.min_a), Min(b1.close_one_b_zheng * a1.max_a, b1.close_one_b_zheng * a1.min_a));
		else if(b1.close_one_b_fu != 0)
			return Min(b1.close_one_b_fu * a1.max_a, b1.close_one_b_fu * a1.min_a);
		else 
			return Min(b1.close_one_b_zheng * a1.max_a, b1.close_one_b_zheng * a1.min_a);
	}
}

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	build(1, n, 1);
	int l1, r1, l2, r2;
	for(int i = 1; i <= q; ++i) {
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		node b1 = Que(1, l1, r1);
		node a1 = Que(1, l2, r2);
		printf("%d\n", work(a1, b1));
	}
 	return 0;
}
