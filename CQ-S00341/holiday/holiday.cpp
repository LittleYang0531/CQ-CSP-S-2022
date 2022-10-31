#include <bits/stdc++.h> 
using namespace std;

const int N = 25005;

int n, m, k;
struct node
{
	int id;
	long long num;
}a[N];

int g[2505][2505];
int h[N], ne[N], e[N], cnt, ans, now, ko;
bool fl[2505];
queue<int> q, p;

void add (int a, int b)
{
	e[++cnt] = b;
	ne[cnt] = h[a];
	h[a] = cnt;
}

void bfs ()
{
	q.push (1);
	fl[1] = 1;
	ans = 0;
	now = -1, mmax = 0;
	while (q.size())
	{
		if (now == k)
		{
			now = 0;
			q = p;
			if (ko == 4) 
			{
				
			}
		}
		int u = q.front();
		for (int i = h[u]; i; i = ne[i])
		{
			if (!fl[e[i]]) q.push (e[i]);
			mmax = max(mmax, a[e[i]]);
		}
		fl[mmax] = 1;
		now ++;
	}
}

bool cmp (node a, node b)
{
	return a[i].num > b[i].num;
}

int main ()
{
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	memset (g, 0x3f, sizeof g);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%d", a[i].num);
		a[i].id = i;
	}
	sort (a + 1, a + 1 + n, cmp);
	
	for (int i = 1; i <= m; i ++)
	{
		int x, y;
		scanf ("%d%d", &x, &y);
		g[x][y] = 0;
		g[y][x] = 0;
		add (x, y);
		add (y, x);
	}
	
	dfs(0, 1);
	
	return 0;
}
