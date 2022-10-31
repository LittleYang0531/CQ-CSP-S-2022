#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

typedef long long ll;
template<typename T>inline void read(T &a)
{
	a = 0;
	int f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c))	a = a * 10 + c - 48,c = getchar();
	a *= f;
}

template<typename T,typename ...L>inline void read(T&a,L&...l)
{
	read(a),read(l...);
}

template<typename T>inline void write(T a)
{
	T x = a;
	char ch[20];
	int top = 0;
	if(x < 0)
		putchar('-'),x = -x;
	do{
		ch[top++] = x % 10 + '0',x /= 10;
	}while(x);
	while(top--)
		putchar(ch[top]);
	putchar('\n');
}

template<typename T,typename ...L>inline void write(T a,L...l)
{
	write(a),write(l...);
}

struct Node{
	int l,r;
	int Min,Max;
	int zxz,zdf;
}arr[N<<2],brr[N<<2];


void pushup(int u,Node arr[])
{
	arr[u].Min = min(arr[u<<1].Min,arr[u<<1|1].Min); 
	arr[u].Max = max(arr[u<<1].Max,arr[u<<1|1].Max);
	if(arr[u<<1].zxz == -1 && arr[u<<1|1].zxz == -1)
		arr[u].zxz = -1;
	else if(arr[u<<1].zxz == -1)
		arr[u].zxz = arr[u<<1|1].zxz;
	else if(arr[u<<1|1].zxz == -1)
		arr[u].zxz = arr[u<<1].zxz;
	else
		arr[u].zxz = min(arr[u<<1].zxz,arr[u<<1|1].zxz); 
	if(arr[u<<1].zdf == 1 && arr[u<<1|1].zdf == 1)
		arr[u].zdf = 1;
	else if(arr[u<<1].zdf == 1)
		arr[u].zdf = arr[u<<1|1].zdf;
	else if(arr[u<<1|1].zdf == 1)
		arr[u].zdf = arr[u<<1].zdf;
	else
		arr[u].zdf = max(arr[u<<1].zdf,arr[u<<1|1].zdf); 
}

void build(int u,int l,int r,int a[],Node arr[])
{
	arr[u].l = l,arr[u].r = r;
	if(l == r)
	{
		arr[u].Min = arr[u].Max = a[l];
		if(a[l] >= 0)
			arr[u].zxz = a[l],arr[u].zdf = 1;
		if(a[l] <= 0)
			arr[u].zdf = a[l],arr[u].zxz = -1;
		return;
	}
	int mid = (l + r) >> 1;
	build(u<<1,l,mid,a,arr);
	build(u<<1|1,mid+1,r,a,arr);
	pushup(u,arr);
}

long long query_min(int u,int l,int r,Node arr[])
{
	if(arr[u].l >= l && arr[u].r <= r)
		return arr[u].Min;
	int mid = (arr[u].l + arr[u].r) >> 1;
	long long sum = LLONG_MAX;
	if(l <= mid)	
		sum = min(sum,query_min(u<<1,l,r,arr));
	if(r > mid)	
		sum = min(sum,query_min(u<<1|1,l,r,arr));
	return sum;
}

long long query_max(int u,int l,int r,Node arr[])
{
	if(arr[u].l >= l && arr[u].r <= r)
		return arr[u].Max;
	int mid = (arr[u].l + arr[u].r) >> 1;
	long long sum = LLONG_MIN;
	if(l <= mid)	
		sum = max(sum,query_max(u<<1,l,r,arr));
	if(r > mid)	
		sum = max(sum,query_max(u<<1|1,l,r,arr));
	return sum;
}

long long query_zxz(int u,int l,int r)
{
	if(arr[u].l >= l && arr[u].r <= r)
		return arr[u].zxz;
	int mid = (arr[u].l + arr[u].r) >> 1;
	long long suml = -1,sumr = -1,sum = 0;
	if(l <= mid)	
		suml = query_zxz(u<<1,l,r);
	if(r > mid)	
		sumr = query_zxz(u<<1|1,l,r);
	if(suml == -1 && sumr == -1)
		sum = -1;
	else if(suml == -1)
		sum = sumr;
	else if(sumr == -1)
		sum = suml;
	else
		sum = min(suml,sumr);
	return sum;
}

long long query_zdf(int u,int l,int r)
{
	if(arr[u].l >= l && arr[u].r <= r)
		return arr[u].zdf;
	int mid = (arr[u].l + arr[u].r) >> 1;
	long long suml = 1,sumr = 1,sum = 0;
	if(l <= mid)	
		suml = query_zdf(u<<1,l,r);
	if(r > mid)	
		sumr = query_zdf(u<<1|1,l,r);
	if(suml == 1 && sumr == 1)
		sum = 1;
	else if(suml == 1)
		sum = sumr;
	else if(sumr == 1)
		sum = suml;
	else
		sum = max(suml,sumr);
	return sum;
}

ll ans;
int n,m,q,a[N],b[N],l1,r1,l2,r2;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int j=1;j<=m;j++)
		read(b[j]);
	build(1,1,n,a,arr);
	build(1,1,m,b,brr);
	while(q--)
	{
		read(l1,r1,l2,r2);
		ll Mn1 = query_min(1,l1,r1,arr);
		ll Mx1 = query_max(1,l1,r1,arr);
		ll Mn2 = query_min(1,l2,r2,brr);
		ll Mx2 = query_max(1,l2,r2,brr);
		ll zxz = query_zxz(1,l1,r1);
		ll zdf = query_zdf(1,l1,r1);
		if(Mx1 <= 0)
		{
			if(Mx2 <= 0)
				write(Mn1 * Mx2);
			else if(Mn2 >= 0)
				write(Mx1 * Mx2);
			else
				write(Mx1 * Mx2);
		}
		else if(Mn1 >= 0)
		{
			if(Mx2 <= 0)
				write(Mn1 * Mn2);
			else if(Mn2 >= 0)
				write(Mx1 * Mn2);
			else
				write(Mn1 * Mn2);
		}
		else
		{
			if(Mx2 <= 0)
				write(Mn1 * Mx2);
			else if(Mn2 >= 0)
				write(Mx1 * Mn2);
			else
			{
				ll tmp = LLONG_MIN;
				if(zxz != -1)
					tmp = max(tmp,zxz * Mn2);
				if(zdf != 1)
					tmp = max(tmp,zdf * Mx2);
				write(tmp);
			}
		}
	 } 
}

