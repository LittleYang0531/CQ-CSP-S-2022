#include<bits/stdc++.h>
using namespace std;

const int N = 2510, M = 20010;
int n, m, k;
int a[N], maxa;

int h[N], ne[M], e[M], idx;
void add(int a, int b)
{
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

int g[N][N];
int dis[N];
void bfs(int x)
{
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q;
	dis[x] = 0, q.push(x);
	
	while(!q.empty())
	{
		int t = q.front(); q.pop();
		
		for(int i = h[t]; i; i = ne[i])
		{
			int j = e[i];
			if(dis[j] > 1e9 && dis[t] <= k)
			{
				g[x][j] = 1;
				dis[j] = dis[t] + 1, q.push(j);
			}
		}
	}
}

bool flag[N];
int ans;
void dfs(int x, int p, int sum)
{
	if(x == 5)
	{
		if(g[p][1])
			ans = max(ans, sum);
		return;
	}
	if(sum + maxa * (5 - x) <= ans)
		return;
	
	for(int i = 1; i <= n; i++)
		if(g[p][i] && !flag[i])
		{
			flag[i] = 1;
			dfs(x + 1, i, sum + a[i]);
			flag[i] = 0;
		}
}

int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &a[i]);
		maxa = max(maxa, a[i]);
	}
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	
	for(int i = 1; i <= n; i++)
		bfs(i);
	
	flag[1] = 1;
	dfs(1, 1, 0);
	
	cout << ans << endl;
	return 0;
}

