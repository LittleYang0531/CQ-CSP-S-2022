#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 1005;
int n,m,t,num,x,y,p,q;
ll a[MAXN],b[MAXN],ans;

struct segment_tree
{
	int l,r;
	ll minn;
}tree[MAXN << 2][MAXN];

template <typename T>
inline void read(T &s)
{
	s = 0;
	bool w = false;
	char ch = getchar();
	while(ch < '0'||ch > '9')
	{
		if(ch == '-')
			w = true;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9')
	{
		s = (s<<3) + (s<<1) + (ch^48);
		ch = getchar();
	}
	s = w ? -s:s;
	return;
}

inline void pushup(int k)
{
	tree[k][num].minn = min(tree[k<<1][num].minn,tree[k<<1|1][num].minn);
	return;
}

inline void build(int k,int l,int r)
{
	tree[k][num].l = l,tree[k][num].r = r;
	if(l == r)
	{
		tree[k][num].minn = a[num] * b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
	return;
}

inline ll Query(int k,int l,int r)
{
	if(l <= tree[k][num].l && r >= tree[k][num].r)
		return tree[k][num].minn;
	int mid = (tree[k][num].l + tree[k][num].r) >> 1;
	ll res = 1e18;
	if(l <= mid)
		res = min(res,Query(k<<1,l,r));
	if(r > mid)
		res = min(res,Query(k<<1|1,l,r));
	return res;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	read(m);
	read(t);
	for(int i = 1;i <= n;i++)
		read(a[i]);
	for(int i = 1;i <= m;i++)
		read(b[i]);
	for(num = 1;num <= n;num++)
		build(1,1,m);
	for(int i = 1;i <= t;i++)
	{
		read(x);
		read(y);
		read(p);
		read(q);
		ans = -1e18;
		for(num = x;num <= y;num++)
			ans = max(ans,Query(1,p,q));
		printf("%lld\n",ans);
	}
	return 0;
}

