#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 323;
int n, m, num, x, y, l1, r1, l2, r2;
int ta, blocka, tb, blockb, amx, bmx, ami, bmi;
int a[N], b[N], sta[M], stb[M], eda[M], edb[M], belonga[N], belongb[N];
int mina[M], minb[M], maxa[M], maxb[M];
long long ans;

void find()
{
	amx = bmx = -0x3f3f3f3f, ami = bmi = 0x3f3f3f3f;
	int pa = belonga[l1], qa = belonga[r1];
	int pb = belongb[l2], qb = belongb[r2];
	
	if(pa == qa)
	{
		for(int i=l1; i<=r1; i++)
			amx = max(amx, a[i]), ami = min(ami, a[i]);
	}
	else
	{
		for(int i=pa+1; i<=qa-1; i++)
			amx = max(amx, maxa[i]), ami = min(ami, mina[i]);
		
		for(int i=l1; i<=eda[pa]; i++)
			amx = max(amx, a[i]), ami = min(ami, a[i]);
		for(int i=sta[pa]; i<=r1; i++)
			amx = max(amx, a[i]), ami = min(ami, a[i]);
	}
	
	if(pb == qb)
	{
		for(int i=l2; i<=r2; i++)
			bmx = max(bmx, b[i]), bmi = min(bmi, b[i]);
	}
	else
	{
		for(int i=pb+1; i<=qb-1; i++)
			bmx = max(bmx, maxb[i]), bmi = min(bmi, minb[i]);
		
		for(int i=l2; i<=edb[pb]; i++)
			bmx = max(bmx, b[i]), bmi = min(bmi, b[i]);
		for(int i=stb[pb]; i<=r2; i++)
			bmx = max(bmx, b[i]), bmi = min(bmi, b[i]);
	}
}

void init()
{
	blocka = sqrt(n);
	ta = n / blocka;
	if(n % blocka)
		ta ++;
	
	blockb = sqrt(m);
	tb = m / blockb;
	if(m % blockb)
		tb ++;
	
	for(int i=1; i<=ta; i++)
		sta[i] = (i-1) * blocka + 1, eda[i] = i * blocka;
	eda[ta] = n;
	
	for(int i=1; i<=tb; i++)
		stb[i] = (i-1) * blockb + 1, edb[i] = i * blockb;
	edb[tb] = m;
	
	for(int i=1; i<=n; i++)
	{
		belonga[i] = (i-1) / blocka + 1;
		mina[belonga[i]] = min(mina[belonga[i]], a[i]);
		maxa[belonga[i]] = max(maxa[belonga[i]], a[i]);
	}
	
	for(int i=1; i<=m; i++)
	{
		belongb[i] = (i-1) / blockb + 1;
		minb[belongb[i]] = min(minb[belongb[i]], b[i]);
		maxb[belongb[i]] = max(maxb[belongb[i]], b[i]);
	}
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(int i=1; i<=m; i++)
		scanf("%d", &b[i]);
	init();
	
	while(q --)
	{//1e5
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		
		find();
		
		num = -0x3f3f3f3f;
		for(int i=l1; i<=r1; i++)
		{
			if(a[i] > 0 && a[i] * bmi > num)
				num = a[i] * bmi, x = i;
			if(a[i] <= 0 && a[i] * bmx > num)
				num = a[i] * bmx, x = i;
		}
		
		num = 0x3f3f3f3f;
		for(int i=l2; i<=r2; i++)
		{
			if(b[i] > 0 && b[i] * amx < num)
				num = b[i] * amx, y = i;
			if(b[i] <= 0 && b[i] * ami < num)
				num = b[i] * ami, y = i;
		}
		
		ans = a[x] * b[y];
		printf("%lld\n", ans);
	}
	
	return 0;
}
/*
1s
1 <= n, m, q <= 10^5
-10^9 <= ai, bi <= 10^9

3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

0
4

----------

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

0
-2
3
2
-1
*/
