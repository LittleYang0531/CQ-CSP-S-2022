#include<bits/stdc++.h>

using namespace std;

const int N = 500000 + 10;

long long chu[N];
long long n, m;
long long Head[N], End[N * 2], Nex[N * 2], tot = 0;
bool alive[N * 2];

void Add(long long x, long long y)
{
	End[++tot] = y, Nex[tot] = Head[x], Head[x] = tot;
}

int main()
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	
	for(long long i = 1; i <= m; ++i)
	{
		long long x, y;
		scanf("%lld%lld", &x, &y);
		Add(y, x);
		chu[x]++;
	}
	
	long long ok = 0;
	for(long long i = 1; i <= n; ++i)
	{
		if(chu[i] == 1) ok++;
	}
	
	long long q;
	scanf("%lld", &q);
	
	while(q--)
	{
		long long op;
		scanf("%lld", &op);
		if(op == 1)
		{
			long long x, y;
			scanf("%lld%lld", &x, &y);
			if(chu[x] == 1) ok--;
			chu[x]--;
			for(long long i = Head[y]; i; i = Nex[i])
			{
				if(End[i] == x)
				{
					alive[i] = true;
					break;
				}
			}
			if(chu[x] == 1) ok++;
			if(ok == n) puts("YES");
			else puts("NO");
		}
		if(op == 2)
		{
			long long y;
			scanf("%lld", &y);
			for(long long i = Head[y]; i; i = Nex[i])
			{
				if(!alive[i])
				{
					alive[i] = true;
					if(chu[End[i]] == 1) ok--;
					chu[End[i]]--;
					if(chu[End[i]] == 1) ok++;
				} 
			}
			if(ok == n) puts("YES");
			else puts("NO");
		}
		if(op == 3)
		{
			long long x, y;
			scanf("%lld%lld", &x, &y);
			if(chu[x] == 1) ok--;
			chu[x]++;
			for(long long i = Head[y]; i; i = Nex[i])
			{
				if(End[i] == x)
				{
					alive[i] = false;
					break;
				}
			}
			if(chu[x] == 1) ok++;
			if(ok == n) puts("YES");
			else puts("NO");
		}
		if(op == 4)
		{
			long long y;
			scanf("%lld", &y);
			for(long long i = Head[y]; i; i = Nex[i])
			{
				if(alive[i])
				{
					alive[i] = false;
					if(chu[End[i]] == 1) ok--;
					chu[End[i]]++;
					if(chu[End[i]] == 1) ok++;
				} 
			}
			if(ok == n) puts("YES");
			else puts("NO");
		}
	}
	
	return 0;
}
