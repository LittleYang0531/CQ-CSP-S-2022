#include<bits/stdc++.h>
#define LL long long
#define ls(x) x << 1
#define rs(x) x << 1 | 1
using namespace std;
template<typename T> void chkmn(T &a, const T &b)
{
	(a > b) && (a = b);
}
template<typename T> void chkmx(T &a, const T &b)
{
	(a < b) && (a = b);
}
const int N = 1e5 + 5;
const int F = 31;
const int INF = 1e9;
int n, m, Q;
int a[N], b[N];
struct SegTree
{
	int l, r;
	int neg, pos; // all -/+
	int maxx, minx;
	int maxneg, minpos; // for a (include 0)
}tra[4 * N], trb[4 * N];
//inline int ls(int x)
//{
//	return x << 1;
//}
//inline int rs(int x)
//{
//	return x << 1 | 1;
//}
inline void pushupa(int p)
{
//	tra[p].neg = tra[ls(p)].neg & tra[rs(p)].neg;
//	tra[p].pos = tra[ls(p)].pos & tra[rs(p)].pos;
	tra[p].maxx = max(tra[ls(p)].maxx, tra[rs(p)].maxx);
	tra[p].minx = min(tra[ls(p)].minx, tra[rs(p)].minx);
	tra[p].maxneg = max(tra[ls(p)].maxneg, tra[rs(p)].maxneg);
	tra[p].minpos = min(tra[ls(p)].minpos, tra[rs(p)].minpos);
}

void builda(int p, int l, int r)
{
	tra[p].l = l;
	tra[p].r = r;
	if(l == r)
	{
//		tra[p].neg = (a[l] < 0);
//		tra[p].pos = (a[l] > 0);
//		tra[p].maxx = tra[p].minx = a[l];
//		if(a[l] == 0) tra[p].maxneg = tra[p].minpos = 0;
//		else if(a[l] < 0) tra[p].maxneg = a[l], tra[p].minpos = INF;
//		else if(a[l] > 0) tra[p].maxneg = -INF, tra[p].minpos = a[l];
		tra[p].maxneg = a[l] <= 0 ? a[l] : -INF;
		tra[p].minpos = a[l] >= 0 ? a[l] : INF;
		return;
	}
	int mid = l + (r - l) / 2;
	builda(ls(p), l, mid);
	builda(rs(p), mid + 1, r);
	pushupa(p);
}

//inline void pushupb(int p)
//{
//	trb[p].neg = trb[ls(p)].neg & trb[rs(p)].neg;
//	trb[p].pos = trb[ls(p)].pos & trb[rs(p)].pos;
//	trb[p].maxx = max(trb[ls(p)].maxx, trb[rs(p)].maxx);
//	trb[p].minx = min(trb[ls(p)].minx, trb[rs(p)].minx);
//}

//void buildb(int p, int l, int r)
//{
//	trb[p].l = l;
//	trb[p].r = r;
//	if(l == r)
//	{
//		trb[p].neg = (b[l] < 0);
//		trb[p].pos = (b[l] > 0);
//		trb[p].maxx = trb[p].minx = b[l];
//		return;
//	}
//	int mid = l + (r - l) / 2;
//	buildb(ls(p), l, mid);
//	buildb(rs(p), mid + 1, r);
//	pushupb(p);
//}

//inline int querya_neg(int p, int l, int r)
//{
//	if(tra[p].l >= l && tra[p].r <= r)
//		return tra[p].neg;
//	int mid = tra[p].l + (tra[p].r - tra[p].l) / 2;
//	int res = 1;
//	if(mid >= l) res &= querya_neg(ls(p), l, r);
//	if(mid < r) res &= querya_neg(rs(p), l, r);
//	return res;
//}
//
//inline int querya_pos(int p, int l, int r)
//{
//	if(tra[p].l >= l && tra[p].r <= r)
//		return tra[p].pos;
//	int mid = tra[p].l + (tra[p].r - tra[p].l) / 2;
//	int res = 1;
//	if(mid >= l) res &= querya_pos(ls(p), l, r);
//	if(mid < r) res &= querya_pos(rs(p), l, r);
//	return res; 
//}
//
//inline int queryb_neg(int p, int l, int r)
//{
//	if(trb[p].l >= l && trb[p].r <= r)
//		return trb[p].neg;
//	int mid = trb[p].l + (trb[p].r - trb[p].l) / 2;
//	int res = 1;
//	if(mid >= l) res &= queryb_neg(ls(p), l, r);
//	if(mid < r) res &= queryb_neg(rs(p), l, r);
//	return res;
//}
//
//inline int queryb_pos(int p, int l, int r)
//{
//	if(trb[p].l >= l && trb[p].r <= r)
//		return trb[p].pos;
//	int mid = trb[p].l + (trb[p].r - trb[p].l) / 2;
//	int res = 1;
//	if(mid >= l) res &= queryb_pos(ls(p), l, r);
//	if(mid < r) res &= queryb_pos(rs(p), l, r);
//	return res;
//}

//int querya_maxx(int p, int l, int r)
//{
//	if(tra[p].l >= l && tra[p].r <= r)
//		return tra[p].maxx;
//	int mid = tra[p].l + (tra[p].r - tra[p].l) / 2;
//	int res = -INF;
//	if(mid >= l) chkmx(res, querya_maxx(ls(p), l, r));
//	if(mid < r) chkmx(res, querya_maxx(rs(p), l, r));
//	return res;
//}
//
//int querya_minx(int p, int l, int r)
//{
//	if(tra[p].l >= l && tra[p].r <= r)
//		return tra[p].minx;
//	int mid = tra[p].l + (tra[p].r - tra[p].l) / 2, res = INF;
//	if(mid >= l) chkmn(res, querya_minx(ls(p), l, r));
//	if(mid < r) chkmn(res, querya_minx(rs(p), l, r));
//	return res;
//}
//
//int queryb_maxx(int p, int l, int r)
//{
//	if(trb[p].l >= l && trb[p].r <= r)
//		return trb[p].maxx;
//	int mid = trb[p].l + (trb[p].r - trb[p].l) / 2, res = -INF;
//	if(mid >= l) chkmx(res, queryb_maxx(ls(p), l, r));
//	if(mid < r) chkmx(res, queryb_maxx(rs(p), l, r));
//	return res;
//}
//
//int queryb_minx(int p, int l, int r)
//{
//	if(trb[p].l >= l && trb[p].r <= r)
//		return trb[p].minx;
//	int mid = trb[p].l + (trb[p].r - trb[p].l) / 2, res = INF;
//	if(mid >= l) chkmn(res, queryb_minx(ls(p), l, r));
//	if(mid < r) chkmn(res, queryb_minx(rs(p), l, r));
//	return res;
//}

int querya_maxneg(int p, int l, int r)
{
	if(tra[p].l >= l && tra[p].r <= r)
		return tra[p].maxneg;
	int mid = tra[p].l + (tra[p].r - tra[p].l) / 2, res = -INF;
	if(mid >= l) chkmx(res, querya_maxneg(ls(p), l, r));
	if(mid < r) chkmx(res, querya_maxneg(rs(p), l, r));
	return res;
}

int querya_minpos(int p, int l, int r)
{
	if(tra[p].l >= l && tra[p].r <= r)
		return tra[p].minpos;
	int mid = tra[p].l + (tra[p].r - tra[p].l) / 2;
	int res = INF;
	if(mid >= l) chkmn(res, querya_minpos(ls(p), l, r));
	if(mid < r) chkmn(res, querya_minpos(rs(p), l, r));
	return res;
}

int chkmxa[N][F], chkmna[N][F];
int chkmxb[N][F], chkmnb[N][F];
int get_chkmxa(int l, int r)
{
	int len = r - l + 1;
	int j = log2(len);
	return max(chkmxa[l][j], chkmxa[r - (1 << j) + 1][j]);
}
int get_chkmna(int l, int r)
{
	int len = r - l + 1;
	int j = log2(len);
	return min(chkmna[l][j], chkmna[r - (1 << j) + 1][j]);
}
int get_chkmxb(int l, int r)
{
	int len = r - l + 1;
	int j = log2(len);
	return max(chkmxb[l][j], chkmxb[r - (1 << j) + 1][j]);
}
int get_chkmnb(int l, int r)
{
	int len = r - l + 1;
	int j = log2(len);
	return min(chkmnb[l][j], chkmnb[r - (1 << j) + 1][j]);
}


inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

// CCF哪都好 开个2s好不好 
// 算了 改写RMQWQ 蓝勾有了 

int main() // data structure
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	n = read(), m = read(), Q = read();
	
	for(int i = 1; i <= n; ++i) a[i] = read();
	for(int i = 1; i <= m; ++i) b[i] = read();
	
	builda(1, 1, n);
//	buildb(1, 1, m);
	
	for(int i = 1; i <= n; ++i)
		chkmxa[i][0] = chkmna[i][0] = a[i];
	for(int i = 1; i <= m; ++i)
		chkmxb[i][0] = chkmnb[i][0] = b[i];
	
	for(int j = 1; j < F; ++j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			chkmxa[i][j] = max(chkmxa[i][j - 1], chkmxa[i + (1 << (j - 1))][j - 1]);
			chkmna[i][j] = min(chkmna[i][j - 1], chkmna[i + (1 << (j - 1))][j - 1]);
		}
	for(int j = 1; j < F; ++j)
		for(int i = 1; i + (1 << j) - 1 <= m; ++i)
		{
			chkmxb[i][j] = max(chkmxb[i][j - 1], chkmxb[i + (1 << (j - 1))][j - 1]);
			chkmnb[i][j] = min(chkmnb[i][j - 1], chkmnb[i + (1 << (j - 1))][j - 1]);
		}
	
	while(Q--)
	{
		int lone, rone, ltwo, rtwo;
		lone = read(), rone = read();
		ltwo = read(), rtwo = read();
		
//		int w, wone = 0, wtwo = 0;
//		w = querya_neg(1, lone, rone);
//		if(w) wone = 1;
//		if(!wone)
//		{	
//			w = querya_pos(1, lone, rone);
//			if(w) wone = 2;
//		}
//		w = queryb_neg(1, ltwo, rtwo);
//		if(w) wtwo = 1;
//		if(!wtwo)
//		{
//			w = queryb_pos(1, ltwo, rtwo);
//			if(w) wtwo = 2;
//		}
		
//		int maxa = querya_maxx(1, lone, rone);
//		int mina = querya_minx(1, lone, rone);
//		int maxb = queryb_maxx(1, ltwo, rtwo);
//		int minb = queryb_minx(1, ltwo, rtwo);
		
		int maxa = get_chkmxa(lone, rone);
		int mina = get_chkmna(lone, rone);
		int maxb = get_chkmxb(ltwo, rtwo);
		int minb = get_chkmnb(ltwo, rtwo);
		
		int wone = 0, wtwo = 0;
		if(maxa < 0) wone = 1;
		else if(mina > 0) wone = 2;
		
		if(maxb < 0) wtwo = 1;
		else if(minb > 0) wtwo = 2;
		
		if(wone == 0 && wtwo == 0)
		{
			LL w1 = 1LL * querya_maxneg(1, lone, rone) * maxb;
			LL w2 = 1LL * querya_minpos(1, lone, rone) * minb;
			printf("%lld\n", max(w1, w2));
		}
		else if(wone == 0 && wtwo == 1)
			printf("%lld\n", 1LL * mina * maxb);
		else if(wone == 0 && wtwo == 2)
			printf("%lld\n", 1LL * maxa * minb);
		else if(wone == 1 && wtwo == 0)
			printf("%lld\n", 1LL * maxa * maxb);
		else if(wone == 1 && wtwo == 1)
			printf("%lld\n", 1LL * mina * maxb);
		else if(wone == 1 && wtwo == 2)
			printf("%lld\n", 1LL * maxa * maxb);
		else if(wone == 2 && wtwo == 0)
			printf("%lld\n", 1LL * mina * minb);
		else if(wone == 2 && wtwo == 1)
			printf("%lld\n", 1LL * mina * minb);
		else if(wone == 2 && wtwo == 2)
			printf("%lld\n", 1LL * maxa * minb);
	}
	return 0;
}
