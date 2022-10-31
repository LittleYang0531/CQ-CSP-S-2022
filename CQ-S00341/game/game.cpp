#include <bits/stdc++.h> 
using namespace std;

int n, m, q;
int a[100005], b[100005];
int l1, l2, r1, r2;
struct node
{
	int l, r, mmax, mmin, ok;
	int big_f, sma_z;
};
node tr1[800000];
node tr2[800000];

void bt1(int l, int r, int op)
{
	if (l == r)
	{
		tr1[op].l = tr1[op].r = l;
		tr1[op].mmin = tr1[op].mmax = a[l];
		if (a[l] == 0) tr1[op].ok = 1;
		else tr1[op].ok = 0;
		if (a[l] > 0) tr1[op].sma_z = a[l];
		else if (a[l] < 0) tr1[op].big_f = a[l];
	}
	tr1[op].l = l, tr1[op].r = r;
	bt1 (l, (l + r) >> 1, op * 2);
	bt1 ((l + r) >> 1, r, op * 2);
	tr1[op].mmax = max (tr1[op * 2].mmax, tr1[op * 2 + 1].mmax);
	tr1[op].mmin = min (tr1[op * 2].mmin, tr1[op * 2 + 1].mmin);
	
	if (tr1[op * 2].big_f == 0) tr1[op].big_f = tr1[op * 2 + 1].big_f;
	else if (tr1[op * 2 + 1].big_f == 0) tr1[op].big_f = tr1[op * 2].big_f;
	else tr1[op].big_f = max (tr1[op * 2].big_f, tr1[op * 2 + 1].big_f);
	
	if (tr1[op * 2].sma_z == 0) tr1[op].sma_z = tr1[op * 2 + 1].sma_z;
	else if (tr1[op * 2 + 1].sma_z == 0) tr1[op].sma_z = tr1[op * 2].sma_z;
	else tr1[op].sma_z = min (tr1[op * 2].sma_z, tr1[op * 2 + 1].sma_z);
}

void bt2(int l, int r, int op)
{
	if (l == r)
	{
		tr2[op].l = tr2[op].r = l;
		tr2[op].mmin = tr2[op].mmax = b[l];
		if (b[l] == 0) tr2[op].ok = 1;
		else tr2[op].ok = 0;
		if (b[l] > 0) tr2[op].sma_z = b[l];
		else if (b[l] < 0) tr2[op].big_f = b[l];
	}
	tr2[op].l = l, tr2[op].r = r;
	bt2 (l, (l + r) >> 1, op * 2);
	bt2 ((l + r) >> 1, r, op * 2);
	tr2[op].mmax = max (tr2[op * 2].mmax, tr2[op * 2 + 1].mmax);
	tr2[op].mmin = min (tr2[op * 2].mmin, tr2[op * 2 + 1].mmin);
	if (tr2[op * 2].big_f == 0) tr2[op].big_f = tr2[op * 2 + 1].big_f;
	else if (tr2[op * 2 + 1].big_f == 0) tr2[op].big_f = tr2[op * 2].big_f;
	else tr2[op].big_f = max (tr2[op * 2].big_f, tr2[op * 2 + 1].big_f);
	
	if (tr2[op * 2].sma_z == 0) tr2[op].sma_z = tr2[op * 2 + 1].sma_z;
	else if (tr2[op * 2 + 1].sma_z == 0) tr2[op].sma_z = tr2[op * 2].sma_z;
	else tr2[op].sma_z = min (tr2[op * 2].sma_z, tr2[op * 2 + 1].sma_z);
}

int sma1 (int k, int l, int r)
{
	if (l <= tr1[k].l && r>= tr1[k].r)
	{
		return tr1[k].mmin;
	}
	int mid = (l + r) >> 1;
	int mm = 0x3f3f3f3f, ll = 0x3f3f3f3f;
	if (l < mid && r >= tr1[k].l) mm = sma1 (k * 2, l, r);
	if (r > mid && l <= tr1[k].r) ll = sma1 (k * 2 + 1, l, r);
	return min(mm, ll);
}int sma2 (int k, int l, int r)
{
	if (l <= tr2[k].l && r>= tr2[k].r)
	{
		return tr2[k].mmin;
	}
	int mid = (l + r) >> 1;
	int mm = 0x3f3f3f3f, ll = 0x3f3f3f3f;
	if (l < mid && r >= tr2[k].l) mm = sma2 (k * 2, l, r);
	if (r > mid && l <= tr2[k].r) ll = sma2 (k * 2 + 1, l, r);
	return min(mm, ll);
}

int bigg1 (int k, int l, int r)
{
	if (l <= tr1[k].l && r>= tr1[k].r)
	{
		return tr1[k].mmax;
	}
	int mid = (l + r) >> 1;
	int mm = -0x3f3f3f3f, ll = -0x3f3f3f3f;
	if (l < mid && r >= tr1[k].l) mm = bigg1 (k * 2, l, r);
	if (r > mid && l <= tr1[k].r) ll = bigg1 (k * 2 + 1, l, r);
	return max(mm, ll);
}int bigg2 (int k, int l, int r)
{
	if (l <= tr2[k].l && r>= tr2[k].r)
	{
		return tr2[k].mmax;
	}
	int mid = (l + r) >> 1;
	int mm = -0x3f3f3f3f, ll = -0x3f3f3f3f;
	if (l < mid && r >= tr2[k].l) mm = bigg2 (k * 2, l, r);
	if (r > mid && l <= tr2[k].r) ll = bigg2 (k * 2 + 1, l, r);
	return max(mm, ll);
}

bool check1 (int k, int l, int r)
{
	if (l <= tr1[k].l && r>= tr1[k].r)
	{
		return tr1[k].ok;
	}
	int mid = (l + r) >> 1;
	int mm = 0, ll = 0;
	if (l < mid && r >= tr1[k].l) mm = check1 (k * 2, l, r);
	if (r > mid && l <= tr1[k].r) ll = check1 (k * 2 + 1, l, r);
	return mm | ll;
}bool check2 (int k, int l, int r)
{
	if (l <= tr2[k].l && r>= tr2[k].r)
	{
		return tr2[k].ok;
	}
	int mid = (l + r) >> 1;
	int mm = 0, ll = 0;
	if (l < mid && r >= tr2[k].l) mm = check2 (k * 2, l, r);
	if (r > mid && l <= tr2[k].r) ll = check2 (k * 2 + 1, l, r);
	return mm | ll;
}

int gbs1 (int k, int l, int r)
{
	if (l <= tr1[k].l && r>= tr1[k].r)
	{
		return tr1[k].big_f;
	}
	int mid = (l + r) >> 1;
	int mm = 0, ll = 0;
	if (l < mid && r >= tr1[k].l) mm = gbs1 (k * 2, l, r);
	if (r > mid && l <= tr1[k].r) ll = gbs1 (k * 2 + 1, l, r);
	
	
	if (tr1[k * 2].big_f == 0) return tr1[k * 2 + 1].big_f;
	else if (tr1[k * 2 + 1].big_f == 0) return tr1[k * 2].big_f;
	else return max (tr1[k * 2].big_f, tr1[k * 2 + 1].big_f);
}int gbs2 (int k, int l, int r)
{
	if (l <= tr2[k].l && r>= tr2[k].r)
	{
		return tr2[k].big_f;
	}
	int mid = (l + r) >> 1;
	int mm = 0, ll = 0;
	if (l < mid && r >= tr2[k].l) mm = gbs2 (k * 2, l, r);
	if (r > mid && l <= tr2[k].r) ll = gbs2 (k * 2 + 1, l, r);
	
	
	if (tr2[k * 2].big_f == 0) return tr2[k * 2 + 1].big_f;
	else if (tr2[k * 2 + 1].big_f == 0) return tr2[k * 2].big_f;
	else return max (tr2[k * 2].big_f, tr2[k * 2 + 1].big_f);
}

int gss1 (int k, int l, int r)
{
	if (l <= tr1[k].l && r>= tr1[k].r)
	{
		return tr1[k].sma_z;
	}
	int mid = (l + r) >> 1;
	int mm = 0, ll = 0;
	if (l < mid && r >= tr1[k].l) mm = gbs1 (k * 2, l, r);
	if (r > mid && l <= tr1[k].r) ll = gbs1 (k * 2 + 1, l, r);
	
	
	if (tr1[k * 2].sma_z == 0) return tr1[k * 2 + 1].sma_z;
	else if (tr1[k * 2 + 1].sma_z == 0) return tr1[k * 2].sma_z;
	else return min (tr1[k * 2].sma_z, tr1[k * 2 + 1].sma_z);
}int gss2 (int k, int l, int r)
{
	if (l <= tr2[k].l && r>= tr2[k].r)
	{
		return tr2[k].sma_z;
	}
	int mid = (l + r) >> 1;
	int mm = 0, ll = 0;
	if (l < mid && r >= tr2[k].l) mm = gbs2 (k * 2, l, r);
	if (r > mid && l <= tr2[k].r) ll = gbs2 (k * 2 + 1, l, r);
	
	
	if (tr2[k * 2].sma_z == 0) return tr2[k * 2 + 1].sma_z;
	else if (tr2[k * 2 + 1].sma_z == 0) return tr2[k * 2].sma_z;
	else return min (tr2[k * 2].sma_z, tr2[k * 2 + 1].sma_z);
}

int main ()
{
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i ++) scanf ("%d", &a[i]);
	for (int i = 1; i <= m; i ++) scanf ("%d", &b[i]);
	
	bt1(1, n, 1);
	bt2(1, m, 1);
	
	while (q --)
	{
		scanf ("%d%d%d%d", &l1, &r1, &l2, &r2);
		int L_sm = sma1 (1, l1, r1);
		int L_bi = bigg1 (1, l1, r1);
		int szL = gss1 (1, l1, r1);
		int bfL = gsf1 (1, l1, r1);
		bool L = check1 (1, l1, r1);
		int Q_sm = sma2 (1, l2, r2);
		int Q_bi = bigg2 (1, l2, r2);
		bool Q = check2 (1, l2, r2);
		int szQ = gss2 (1, l2, r2);
		int bfQ = gsf2 (1, l2, r2);
		
		if (Q_bi < 0)
		{
			if (L_bi < 0) printf("%d\n", Q_bi * L_sm);
			else if (L_sm > 0) printf("%d\n", Q_sm * L_sm);
			else
			{
				printf("%d\n", Q_bi * L_sm);
			}
		}
		else if (Q_sm > 0)
		{
			if (L_bi < 0) 
			{
				printf("%d\n", Q_bi * L_bi);
			}
			else if(L_sm > 0)printf("%d\n", Q_sm * L_bi);
			else printf("%d\n", Q_sm * L_bi);
		}
		else 
		{
			if (L) printf ("0\n");
			else if (L_bi < 0) printf("%d\n", Q_bi * L_bi);
			else if (L_sm > 0) printf("%d\n", Q_sm * L_sm);
			else  printf("%d\n", max (bfL * szQ, szL * bfQ));
		}
	}
	return 0;
}
