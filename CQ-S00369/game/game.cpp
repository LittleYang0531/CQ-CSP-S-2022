#include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 10, K = 20 + 5;

long long n, m, q;
long long Logn, Logm; 
long long a[N], b[N];
long long stn0[N][K], stn1[N][K], stmin[N][K], stmax[N][K], stnin[N][K], stnax[N][K];

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);	
	
	scanf("%lld%lld%lld", &n, &m, &q);
	
	memset(stn0, -0x3f3f3f3f, sizeof stn0);
	memset(stn1, 0x3f3f3f3f, sizeof stn1);
		
	long long JIX = stn0[1][0];
	long long JIA = stn1[1][0];
	
	for(long long i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		
		if(a[i] >= 0)
		{
			stn1[i][0] = a[i];
		}
		if(a[i] <= 0)
		{
			stn0[i][0] = a[i];
		}
		
		stnin[i][0] = a[i];
		stnax[i][0] = a[i];
	}
	
	Logn = log2(n);
	
	for(long long i = 1; i <= Logn; ++i)
	{
		for(long long j = 1; j <= n - (1 << i) + 1; ++j)
		{
			stnin[j][i] = min(stnin[j][i - 1], stnin[j + (1 << (i - 1))][i - 1]);
			stnax[j][i] = max(stnax[j][i - 1], stnax[j + (1 << (i - 1))][i - 1]);
			
			stn0[j][i] = max(stn0[j][i - 1], stn0[j + (1 << (i - 1))][i - 1]);
			stn1[j][i] = min(stn1[j][i - 1], stn1[j + (1 << (i - 1))][i - 1]);
		}
	}
	
	for(long long j = 1; j <= m; ++j)
	{
		scanf("%lld", &b[j]);
		stmin[j][0] = b[j];
		stmax[j][0] = b[j];
	}
	
	Logm = log2(m);
	
	for(long long i = 1; i <= Logm; ++i)
	{
		for(long long j = 1; j <= m - (1 << i) + 1; ++j)
		{
			stmin[j][i] = min(stmin[j][i - 1], stmin[j + (1 << (i - 1))][i - 1]);
			stmax[j][i] = max(stmax[j][i - 1], stmax[j + (1 << (i - 1))][i - 1]);
		}
	}
	
	while(q--)
	{
		long long la, ra, lb, rb;
		scanf("%lld%lld%lld%lld", &la, &ra, &lb, &rb);
		long long mmax, mmin;
		mmax = max(stmax[lb][(long long)log2(rb - lb + 1)], stmax[rb - (1 << ((long long)log2(rb - lb + 1))) + 1][(long long)log2(rb - lb + 1)]);
		mmin = min(stmin[lb][(long long)log2(rb - lb + 1)], stmin[rb - (1 << ((long long)log2(rb - lb + 1))) + 1][(long long)log2(rb - lb + 1)]); 
				
		if(mmax >= 0 && mmin >= 0)
		{
			printf("%lld\n", mmin * max(stnax[la][(long long)log2(ra - la + 1)], stnax[ra - (1 << ((long long)log2(ra - la + 1))) + 1][(long long)log2(ra - la + 1)]));
		}else{
			if(mmax < 0 && mmin < 0)
			{
				printf("%lld\n", mmax * min(stnin[la][(long long)log2(ra - la + 1)], stnin[ra - (1 << ((long long)log2(ra - la + 1))) + 1][(long long)log2(ra - la + 1)]));
			}else{
				long long x = min(stn1[la][(long long)log2(ra - la + 1)], stn1[ra - (1 << ((long long)log2(ra - la + 1))) + 1][(long long)log2(ra - la + 1)]);
				long long y = max(stn0[la][(long long)log2(ra - la + 1)], stn0[ra - (1 << ((long long)log2(ra - la + 1))) + 1][(long long)log2(ra - la + 1)]);
				
				if(x == JIA) printf("%lld\n", mmax * y);
				else{
					if(y == JIX) printf("%lld\n", mmin * x);
					else printf("%lld\n", max(mmax * y, mmin * x));
				}
			}
		}
		
	}
	
	return 0;
}
