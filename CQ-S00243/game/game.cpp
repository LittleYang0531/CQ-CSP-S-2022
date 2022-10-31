/*
分讨即可。 
*/ 
#include "bits/stdc++.h"
using namespace std;
const int Len = 1e5 + 5 , Inf = 1e9 + 1;
#define ll long long
const ll inf = 1e18 + 1;
int n,m,q,A[Len],B[Len];
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
struct Seg
{
	int N,mx[Len << 2],mn[Len << 2],a[Len],fg[Len];
	Seg(){N = 0;}
	void init(int NN){N = NN;}
	void Init(int x,int op)
	{
		if(!op) a[x] = A[x];
		else a[x] = B[x];
		fg[x] = 1;
	}
	inline void push_up(int p)
	{
		mx[p] = max(mx[ls(p)] , mx[rs(p)]);
		mn[p] = min(mn[ls(p)] , mn[rs(p)]);
	}
	void build(int p,int l,int r)
	{
		if(l == r)
		{
			if(fg[l]) mx[p] = mn[p] = a[l];
			else mx[p] = -Inf , mn[p] = Inf;
			return;
		}
		int mid = (l + r) >> 1;
		build(ls(p) , l , mid);
		build(rs(p) , mid + 1 , r);
		push_up(p);
	}
	int Q(int p,int l,int r,int nl,int nr,int op)
	{
		if(nl <= l && nr >= r) 
		{
			if(!op) return mn[p];
			return mx[p];
		}
		int mid = (l + r) >> 1 , res = 0;
		if(!op) res = Inf;
		else res = -Inf;
		if(nl <= mid) 
		{
			if(!op) res = min(res , Q(ls(p) , l , mid , nl , nr , op));
			else res = max(res , Q(ls(p) , l , mid , nl , nr , op));
		}
		if(nr > mid) 
		{
			if(!op) res = min(res , Q(rs(p) , mid + 1 , r , nl , nr , op));
			else res = max(res , Q(rs(p) , mid + 1 , r , nl , nr , op));
		}
		return res;
	}
}T1[2],T2[2];
int sum0[Len][2];
inline int read()
{
	int x = 0 , f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	while('0' <= ch && ch <= '9') 
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();	
	} 
	return x * f;
}
void write(ll x)
{
	if(x < 0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if(x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n = read() , m = read() , q = read();
	for(int i = 1 ; i <= n ; i ++) 
	{
		A[i] = read();
		sum0[i][0] = sum0[i - 1][0] + (A[i] == 0);
	}
	for(int i = 1 ; i <= m ; i ++) 
	{
		B[i] = read();
		sum0[i][1] = sum0[i - 1][1] + (B[i] == 0);
	}
	T1[0].init(n) , T1[1].init(n) , T2[0].init(m) , T2[1].init(m); 
	for(int i = 1 ; i <= n ; i ++) 
	{
		if(A[i] > 0) T1[1].Init(i , 0);
		if(A[i] < 0) T1[0].Init(i , 0);
	}
	for(int i = 1 ; i <= m ; i ++) 
	{
		if(B[i] > 0) T2[1].Init(i , 1);
		if(B[i] < 0) T2[0].Init(i , 1);
	}
	T1[0].build(1 , 1 , n) , T1[1].build(1 , 1 , n) , T2[0].build(1 , 1 , m) , T2[1].build(1 , 1 , m); 
	for(int i = 1 ; i <= q ; i ++)
	{
		int l,r,L,R;l = read() , r = read() , L = read() , R = read();ll as = -inf;
		int za = sum0[r][0] - sum0[l - 1][0] , zb = sum0[R][1] - sum0[L - 1][1];  
		//选正数
		int mxa = T1[1].Q(1 , 1 , n , l , r , 1) , mna = T1[1].Q(1 , 1 , n , l , r , 0);
		int mxb = T2[0].Q(1 , 1 , m , L , R , 0) , mnb = T2[1].Q(1 , 1 , m , L , R , 0);
		if(mxb < 0) 
		{
			if(mna != Inf) as = max(as , 1ll * mna * mxb);//有负数，选最大的负数 
		}
		else 
		{
			if(mxa != -Inf) as = max(as , 1ll * mxa * mnb);//没负数，选最小的正数
		}
		//选负数
		mxa = T1[0].Q(1 , 1 , n , l , r , 0) , mna = T1[0].Q(1 , 1 , n , l , r , 1);
		mxb = T2[1].Q(1 , 1 , m , L , R , 1) , mnb = T2[0].Q(1 , 1 , m , L , R , 1);
		if(mxb > 0) 
		{
			if(mna != -Inf) as = max(as , 1ll * mna * mxb);//有正数，选最大的正数
		}
		else 
		{
			if(mxa != Inf) as = max(as , 1ll * mxa * mnb);//没正数，选最大的负数 
		}
		if(za && as < 0) as = 0;
		if(zb && as > 0) as = 0;
		write(as) , putchar('\n');
	}
	return 0;
}
