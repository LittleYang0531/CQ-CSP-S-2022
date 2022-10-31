#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<typename T> void chkmn(T &a, const T &b)
{
	(a > b) && (a = b);
}
template<typename T> void chkmx(T &a, const T &b)
{
	(a < b) && (a = b);
}

const int N = 2505;
const int M = 1e4 + 5;
const int INF = 1e9;

int n, m, k;
int f[N][N];
LL w[N], ans;
int b[N], bcnt;
int idx, h[N], e[2 * N], ne[2 * N];
void add(int a, int b)
{
	idx++;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
}
bool vis[N];
void dfs(int u, int step, LL sum)
{
	if(step == 5)
	{
		if(u == 1) chkmx(ans, sum);
		return;
	}
	if(step == 4)
	{
		for(int i = h[u]; i; i = ne[i])
		{
			int v = e[i];
			if(vis[v]) continue;
			if(v == 1) dfs(1, step + 1, sum);
		}
	}
	for(int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if(vis[v]) continue;
		if(v == 1) continue;
		vis[v] = 1;
		dfs(v, step + 1, sum + w[v]);
		vis[v] = 0;
	}
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 2; i <= n; ++i)
		scanf("%lld", &w[i]);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			f[i][j] = INF;
	for(int i = 1; i <= n; ++i)
		f[i][i] = 0;
	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		add(a, b);
		add(b, a);
		f[a][b] = f[b][a] = 1;
	}
	if(k == 0 && n >= 300)
	{
		dfs(1, 0, 0);
		printf("%lld\n", ans);
		return 0;
	}
	for(int p = 1; p <= n; ++p)
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j)
				if(f[i][j] > f[i][p] + f[p][j])
					f[i][j] = f[j][i] = f[i][p] + f[p][j];
	for(int i = 2; i <= n; ++i)
		if(f[1][i] <= k + 1)
			b[++bcnt] = i;
	for(int i = 1; i <= bcnt; ++i)
		for(int j = i + 1; j <= bcnt; ++j) // A 和 D 本质相同 
		{
			int A = b[i], D = b[j]; 
			for(int B = 2; B <= n; ++B)
				if(f[A][B] <= k + 1 && A != B && D != B)
					for(int C = 2; C <= n; ++C)
						if(A != C && D != C && B != C)
						{
							if(f[B][C] > k + 1 || f[C][D] > k + 1)
								continue;
							chkmx(ans, w[A] + w[B] + w[C] + w[D]);
						}
		}
	printf("%lld\n", ans);
	return 0;
}
