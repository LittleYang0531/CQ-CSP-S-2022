#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n, m, q, a[100005], b[100005], sum1[400005], sum2[400005], sum3[400005], sum4[400005], sum5[400005], sum6[400005];
void build1(int i, int l, int r)
{
	if (l==r)
	{
		sum1[i] = a[l];
		sum2[i] = a[l];
		if (a[l]>0)
		{
			sum5[i] = a[l];
			sum6[i] = -2147483647;
		}
		else if (a[l]<0)
		{
			sum5[i] = 2147483647;
			sum6[i] = a[l];
		}
		else
		{
			sum5[i] = 0;
			sum6[i] = 0;
		}
		return ;
	}
	int mid = l+r>>1;
	build1(i*2, l, mid);
	build1(i*2+1, mid+1, r);
	sum1[i] = max(sum1[i*2], sum1[i*2+1]);
	sum2[i] = min(sum2[i*2], sum2[i*2+1]);
	sum5[i] = min(sum5[i*2], sum5[i*2+1]);
	sum6[i] = max(sum6[i*2], sum6[i*2+1]);
	return ;
}
void build2(int i, int l, int r)
{
	if (l==r)
	{
		sum3[i] = b[l];
		sum4[i] = b[l];
		return ;
	}
	int mid = l+r>>1;
	build2(i*2, l, mid);
	build2(i*2+1, mid+1, r);
	sum3[i] = max(sum3[i*2], sum3[i*2+1]);
	sum4[i] = min(sum4[i*2], sum4[i*2+1]);
	return ;
}
int found1(int i, int l, int r, int q, int w)
{
	if (l>=q&&r<=w)
	{
		return sum1[i];
	}
	int mid = l+r>>1, ans = -2147483647;
	if (q<=mid)
	{
		ans = max(ans, found1(i*2, l, mid, q, w));
	}
	if (w>mid)
	{
		ans = max(ans, found1(i*2+1, mid+1, r, q, w));
	}
	return ans;
}
int found2(int i, int l, int r, int q, int w)
{
	if (l>=q&&r<=w)
	{
		return sum2[i];
	}
	int mid = l+r>>1, ans = 2147483647;
	if (q<=mid)
	{
		ans = min(ans, found2(i*2, l, mid, q, w));
	}
	if (w>mid)
	{
		ans = min(ans, found2(i*2+1, mid+1, r, q, w));
	}
	return ans;
}
int found3(int i, int l, int r, int q, int w)
{
	if (l>=q&&r<=w)
	{
		return sum3[i];
	}
	int mid = l+r>>1, ans = -2147483647;
	if (q<=mid)
	{
		ans = max(ans, found3(i*2, l, mid, q, w));
	}
	if (w>mid)
	{
		ans = max(ans, found3(i*2+1, mid+1, r, q, w));
	}
	return ans;
}
int found4(int i, int l, int r, int q, int w)
{
	if (l>=q&&r<=w)
	{
		return sum4[i];
	}
	int mid = l+r>>1, ans = 2147483647;
	if (q<=mid)
	{
		ans = min(ans, found4(i*2, l, mid, q, w));
	}
	if (w>mid)
	{
		ans = min(ans, found4(i*2+1, mid+1, r, q, w));
	}
	return ans;
}
int found5(int i, int l, int r, int q, int w)
{
	if (l>=q&&r<=w)
	{
		return sum5[i];
	}
	int mid = l+r>>1, ans = 2147483647;
	if (q<=mid)
	{
		ans = min(ans, found5(i*2, l, mid, q, w));
	}
	if (w>mid)
	{
		ans = min(ans, found5(i*2+1, mid+1, r, q, w));
	}
	return ans;
}
int found6(int i, int l, int r, int q, int w)
{
	if (l>=q&&r<=w)
	{
		return sum6[i];
	}
	int mid = l+r>>1, ans = -2147483647;
	if (q<=mid)
	{
		ans = max(ans, found6(i*2, l, mid, q, w));
	}
	if (w>mid)
	{
		ans = max(ans, found6(i*2+1, mid+1, r, q, w));
	}
	return ans;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int p=1;p<=n;p++)
	{
		scanf("%d", &a[p]);
	}
	build1(1, 1, n);
	for (int p=1;p<=m;p++)
	{
		scanf("%d", &b[p]);
	}
	build2(1, 1, m);
	for (int p=1;p<=q;p++)
	{
		int l1, r1, l2, r2;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		long long u = -2e18, u1 = found1(1, 1, n, l1, r1), u2 = found2(1, 1, n, l1, r1), u3 = found3(1, 1, m, l2, r2), u4 = found4(1, 1, m, l2, r2), u5 = found5(1, 1, n, l1, r1), u6 = found6(1, 1, n, l1, r1); 
		if (u3>=0)
		{
			if (u6>=-1e9)
			{
				u = max(u, u6*u3);
			}
		}
		if (u2<=0)
		{
			u = max(u, u2*u3);
		}
		if (u4<0)
		{
			if (u5<=1e9)
			{
				u = max(u, u5*u4);
			}
		}
		if (u1>=0)
		{
			u = max(u, u1*u4);
		}
		printf("%lld\n", u);
	}
	
	return 0;
}
