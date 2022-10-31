#include <bits/stdc++.h> 
using namespace std;

long long n, Q, k, a[2000005], ans;
const int N = 4000005;
long long h[N], ne[N], e[N], cnt;
queue <long long> q, p;
long long fl[200005];
void add (long long a, long long b)
{
	e[++cnt] = b;
	ne[cnt] = h[a];
	h[a] = cnt;
}

void dfs (int x, int y, int ss[], int &s)
{
//	cout << 1<<endl;
	memset (fl, 0, sizeof fl);
	s = 0;
	q = p;
	q.push (x);
	while (q.size ())
	{
		int u = q.front ();
		q.pop();
		if (u == y) 
		{
			while (x != u)
			{
				ss[++s] = u;
				u = fl[u];
			}
			ss [++s] = x; 
			return;
		}
		for (int i = h[u]; i; i = ne[i])
		{
			int v = e[i];
			if(v != u && !fl[v])
			{
//				cout << u <<" "<<v<<endl;
				fl[v] = u;
				q.push (v);
			}
		}
	}
}

long long sdsd (long long xx, long long yy)
{
	int qq[5005] = {0}, hh = 0, tt = 0, s[200005], len = 0, f[200005], mmin = 0x3f3f3f3f;
	
	dfs (xx, yy, s, len); 
//	cout <<len<<endl;
	for (int i = 2; i < len; i ++)
	{
//		cout <<i<<endl;
		if (qq[hh] < i - k) hh ++;
		f[i] = a[s[i]] + a[qq[hh]];
//		cout <<f[i]<<" "<<qq[hh]<<endl;
//		cout <<a[i]<<endl;cout <<i<<endl;
//		cout <<"hjuio "<<i<<" "<<qq[tt];
		while (tt >= hh && a[qq[tt]] > a[i])
		{
			tt--;
		}
		qq[++tt] = i;
	}
	for (int i = len - 1; i >= len - k; i --)
	{
		mmin = min (mmin, f[i]);
	}
	return mmin;
}

int main ()
{
	freopen ("transmit.in", "r", stdin);
	freopen ("transmit.out", "w", stdout);
	scanf ("%lld%lld%lld", &n, &Q, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i < n; i ++)
	{
		long long x, y;
		scanf ("%lld%lld", &x, &y);
		add (x, y);
		add (y, x);
	}
//	cout <<"er";
//	sdsd(1, 5);
//	cout <<"er";
	while (Q --)
	{
		long long x, y;
		scanf ("%lld%lld", &x, &y);	
		ans = a[x] + a[y];
//		cout <<"1:" <<ans<<endl;
		ans = ans + sdsd (x, y);
//		cout <<"fdfs:    "<<sdsd (x, y)<<endl;
		printf("%lld\n", ans);
	} 
	return 0;
}
