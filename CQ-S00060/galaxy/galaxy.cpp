#include<bits/stdc++.h>
#define LL long long
#define MOD 998244353 
using namespace std;
template<typename T> void chkmn(T &a, const T &b)
{
	(a > b) && (a = b);
}
template<typename T> void chkmx(T &a, const T &b)
{
	(a < b) && (a = b);
}
int inc(const int &a, const int &b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}
int dec(const int &a, const int &b)
{
	return a - b < 0 ? a - b + MOD : a - b;
}
int mul(const int &a, const int &b)
{
	return 1LL * a * b % MOD;
}
void Inc(int &a, const int &b)
{
	((a += b) >= MOD) && (a -= MOD);
}
void Dec(int &a, const int &b)
{
	((a -= b) < 0) && (a += MOD);
}
void Mul(int &a, const int &b)
{
	a = 1LL * a * b % MOD;
}
void Sqr(int &a)
{
	a = 1LL * a * a % MOD;
}
int qwqmi(int x, int k = MOD - 2)
{
	int res = 1;
	while(k)
	{
		if(k & 1) Mul(res, x);
		Sqr(x), k >>= 1;
	}
	return res;
}


int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	return 0;
}
