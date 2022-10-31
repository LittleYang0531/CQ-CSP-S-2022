#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std ;
typedef long long ll ;

const int N = 1e5 + 5 ;

int rd()
{
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch > '9' || ch < '0')
	{
		if(ch == '-') f = -1 ;
		ch = getchar() ;
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) +  (ch ^ 48) ;
		ch = getchar() ;
	}
	return x *= f ;
}


struct SegTree
{
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)
	int a[N] ;
	int maxn[N * 4] , minn[N * 4] ;
	void build(int k , int l , int r)
	{
		if(l == r){minn[k] = maxn[k] = a[l] ; return ;}
		build(ls , l , mid) ;
		build(rs , mid + 1 , r) ;
		maxn[k] = max(maxn[ls] , maxn[rs]) ; 	
		minn[k] = min(minn[ls] , minn[rs]) ; 	
	}
	int query_max(int k , int l , int r , int x , int y)
	{
		if(x <= l && r <= y) return maxn[k] ;
		int res = -1e9 - 1 ;
		if(x <= mid) res = max(res , query_max(ls , l , mid , x , y)) ;
		if(y > mid) res = max(res , query_max(rs , mid+ 1 , r , x, y)) ;
		return res ;
	}
	int query_min(int k , int l , int r , int x , int y)
	{
		if(x <= l && r <= y) return minn[k] ;
		int res = 1e9 + 1 ;
		if(x <= mid) res = min(res , query_min(ls , l , mid , x , y)) ;
		if(y > mid) res = min(res , query_min(rs , mid+ 1 , r , x, y)) ;
		return res ;
	}
} A , B ;

int n , m , q ;

struct T
{
	int x , y , l , r ;
}ask[N] ;

multiset<ll> st ;

void Solve3()
{
	int l = 0 , r = 0 ;
	for(int i = 1 ; i <= q ; i++)
	{
		int Amx = A.query_max(1 , 1 , n , ask[i].x , ask[i].y) , 
			Ami = A.query_min(1 , 1 , n , ask[i].x , ask[i].y) , 
			Bmx = B.query_max(1 , 1 , m , ask[i].l , ask[i].r) , 
			Bmi = B.query_min(1 , 1 , m , ask[i].l , ask[i].r) ;
		while(r < ask[i].y){st.insert(A.a[++r]) ;}
		while(l > ask[i].x){st.erase(A.a[--l]) ;}
		while(r > ask[i].y){st.erase(A.a[r--]) ;}
		while(l < ask[i].x){st.insert(A.a[l++]) ;}	
		if(Ami >= 0)
		{
			if(Bmi >= 0)// + +
			{
				cout << 1ll * Amx * Bmi << '\n' ;
			}
			else// + +/-
			{
				cout << 1ll * Ami * Bmi << '\n' ;	
			}
		}
		else if(Amx < 0)
		{
			if(Bmi >= 0)// - +
			{
				cout << 1ll * Amx * Bmx << '\n' ;
			}
			else// - +/-
			{
				cout << 1ll * Amx * Bmx << '\n' ;
			}
		}
		else
		{
			if(Bmi >= 0)// -/+ +
			{
				cout << 1ll * Amx * Bmi << '\n' ;
			}
			else if(Bmx < 0) // -/+ -
			{
				cout << 1ll * Ami * Bmx << '\n' ;
			}
			else // -/+ -/+
			{
				multiset<ll>::iterator p = st.lower_bound(0) ;
				if(*p == 0){cout << 0 << '\n' ; continue ;}
				int  up0 = *p , low0 = *(--p) ;
//				if(i == 5) 
//				cout << low0 << ' ' << up0 <<'\n' ;
//				cout << Bmx << ' ' << Bmi << '\n' ;
				cout << max(1ll*low0*Bmx,1ll*up0*Bmi) << '\n' ;
			}
		}
	}
}


void Solve2()
{
	for(int i = 1 ; i <= q ; i++)
	{
		if(ask[i].x == ask[i].y)
		{
			int k1 = A.a[ask[i].x] , k2 = 0 ;
			if(k1 > 0)
				k2 = B.query_min(1 , 1 , m , ask[i].l , ask[i].r) ;
			else if(k1 < 0)
				k2 = B.query_max(1 , 1 , m , ask[i].l , ask[i].r) ;
			cout << 1ll * k1 * k2 << '\n' ;
		}
		else
		{
			int k1 = 0 , k2 = B.a[ask[i].l] ;
			if(k2 > 0)
				k1 = A.query_max(1 , 1 , n , ask[i].x , ask[i].y) ;
			else if(k1 < 0)
				k1 = A.query_min(1 , 1 , n , ask[i].x , ask[i].y) ;
			cout << 1ll * k1 * k2 << '\n' ;	
		}
	}
}

void Solve1()
{
	for(int i = 1 ; i <= q ; i++)
	{
		int l = rd() , r = rd() ;
		int k1 = A.query_max(1 , 1 , n , l , r) ;
		l = rd() , r = rd() ;
		int k2 = B.query_min(1 , 1 , m , l , r) ;
		cout << 1ll * k1 * k2 << '\n' ;
	}
}

int main()
{
	freopen("game.in","r",stdin) ;
	freopen("game.out","w",stdout) ;
	
	n = rd() ; m = rd() ; q = rd() ;
	int fl = 1 ;
	for(int i = 1 ; i <= n ; i++)
	{
		A.a[i] = rd() ;
		if(A.a[i] < 0) fl = 0 ;		
	}
	A.build(1 , 1 , n) ;
	for(int i = 1 ; i <= m ; i++)
	{
		B.a[i] = rd() ;
		if(B.a[i] < 0) fl = 0 ;		
	}
	B.build(1 , 1 , m) ;
	if(fl) {Solve1() ; return 0 ; }
	fl = 1 ;
	for(int i = 1 ; i <= q ; i++)
	{
		ask[i].x = rd() ; ask[i].y = rd() ;
		ask[i].l = rd() ; ask[i].r = rd() ;
		if(ask[i].x != ask[i].y && ask[i].l != ask[i].r) fl = 0 ;
	}
	if(fl) {Solve2() ; return 0 ; }
	Solve3() ;
	return 0 ;
}
