#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 200005;
int n, q, k;
int w[N];
int h[N], e[N], ne[N], idx = 0;
int dis[2005][2005];
bool st[2005][2005];
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}
void dij()
{
	memset(dis, 0x3f, sizeof dis);
	priority_queue<PII, vector<PII>, greater<PII>> q;
	for(int s = 1; s <= n; s ++ )
	{
		int kk = k + 1;
		dis[s][s] = 0;
		q.push({0, s});
		while(q.size() && kk)
		{
			PII t = q.top();
			q.pop();
			if(st[s][t.y])continue;
			st[s][t.y] = 1;
			for(int i = h[t.y]; ~i; i = ne[i])
			{
				int j = e[i];
				if(dis[s][j] > dis[s][t.y] + w[j])
				{
					dis[s][j] = dis[s][t.y] + w[i];
					q.push({dis[s][j], j});
				}
			}
			kk -- ;
		}
		while(q.size())q.pop();
	}
}
int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d%d%d", &n, &q, &k);
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; i ++ )
		scanf("%d", &w[i]);
	for(int i = 1; i < n; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	dij();
	for(int i = 1; i <= q; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", dis[a][b]);
	}
	return 0;
}

