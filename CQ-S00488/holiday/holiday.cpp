#include <cstdio>
#include <queue>
#include <algorithm>

#define LL long long

using namespace std;

const LL N = 2505;
const LL M = 2e4 + 5;
const LL INF = 1145141919810;

LL n, m;
LL p;
LL idx;
LL ans;
LL w[N];
LL elast[N];
LL dis[N][N];

bool flag[N];

struct node
{
	LL x;
	LL y;
	LL next;
};
node e[M];

void add (LL u, LL v)
{
	idx ++;
	e[idx].x = u;
	e[idx].y = v;
	e[idx].next = elast[u];
	elast[u] = idx;
}

void dijkstra (LL s)
{
	for (LL i = 1; i <= n; i ++)
	{
		flag[i] = 0;
		dis[s][i] = INF;
	}
	
	queue <LL> q;
	q.push (s);
	dis[s][s] = 0;
	
	while (q.size ()) 
	{
		LL u = q.front () ;
		q.pop ();
		
		if (flag[u])
			continue;
		flag[u] = 1;
		
		for (LL i = elast[u]; i; i = e[i].next)
		{
			LL v = e[i].y;
			if (dis[s][v] > dis[s][u] + 1)
			{
				dis[s][v] = dis[s][u] + 1;
				q.push (v);
			}
		}
	}
}

int main ()
{
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);
	
	scanf ("%lld %lld %lld", &n, &m, &p);
	for (LL i = 2; i <= n; i ++)
		scanf ("%lld", &w[i]);
	for (LL i = 1; i <= m; i ++)
	{
		LL u, v;
		scanf ("%lld %lld", &u, &v);
		add (u, v);
		add (v, u);
	}
	
	for (LL i = 1; i <= n; i ++)
		dijkstra (i);
	
	for (LL i = 2; i <= n; i ++)
		for (LL j = 2; j <= n; j ++)
			for (LL k = 2; k <= n; k ++)
				for (LL u = 2; u <= n; u ++)
					if (dis[1][i] <= p + 1 && dis[i][j] <= p + 1 && dis[j][k] <= p + 1 && dis[k][u] <= p + 1 && dis[u][1] <= p + 1 && i != j && i != k && i != u && j != k && j != u && k != u)
						ans = max (ans, w[i] + w[j] + w[k] + w[u]);
	
	printf ("%lld\n", ans);
	
	return 0;
}

