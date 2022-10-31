#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 2505 ;
int n, m, k, u, v, D[MAXN][MAXN], INF = 0x3f3f3f3f ;
long long Ans = 0, s[MAXN] ; 
bool Vis[MAXN] ;
struct Edge
{
	int v ;
	long long w ;
} ;
queue <Edge> q ;
vector<Edge> G[MAXN], P[MAXN] ;
long long read()
{
	long long x = 0 ;
	char c = getchar() ;
	while(c < '0' || c > '9')	c = getchar() ;
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0' ;
		c = getchar() ;
	}
	return x ;
}
void SPFA(int id)
{
	for(int i = 1; i <= n; i ++){
		D[id][i] = INF ;
		Vis[i] = 0 ;
	}
	D[id][id] = 0 ;
	q.push((Edge){id, 0}) ;
	Vis[id] = 1 ;
	while(q.empty() == 0)
	{
		Edge x, y ;
		x = q.front() ;
		q.pop() ;
		Vis[x.v] = 0 ;
		for(int i = 0; i < G[x.v].size(); i ++)
		{
			y = G[x.v][i] ;
			if(D[id][y.v] > D[id][x.v] + y.w)
			{
				D[id][y.v] = D[id][x.v] + y.w ;
				if(Vis[y.v] == 0)
				{
					Vis[y.v] = 1 ;
					q.push((Edge){y.v, D[id][y.v]}) ;	
				}	
			} 
		}
	}
}
int main()
{
	freopen("holiday.in", "r", stdin) ;
	freopen("holiday.out", "w", stdout) ;
	int a, b, x, y ;
	n = (int)read(), m = (int)read(), k = (int)read() ;
	for(int i = 2; i <= n; i ++)	s[i] = read() ;
	for(int i = 1; i <= m; i ++)
	{
		u = (int)read(), v = (int)read() ;
		G[u].push_back((Edge){v, 1}) ;
		G[v].push_back((Edge){u, 1}) ;
	}
	for(int i = 1; i <= n; i ++)	SPFA(i) ;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			if(i == j)	continue ;
			if((D[i][j] - 1) <= k)
			{
				P[i].push_back((Edge){j, s[j]}) ;
			}
		}
	}
	for(int i = 0; i < P[1].size(); i ++)
	{
		a = P[1][i].v ;
		for(int j = i + 1; j < P[1].size(); j ++)
		{
			b = P[1][j].v ;
			for(int l = 0; l < P[a].size(); l ++)
			{
				x = P[a][l].v ;
				for(int r = 0; r < P[b].size(); r ++)
				{
					y = P[b][r].v ;
					if(x == y || a == y || b == x)	continue ;
					if((D[x][y] - 1) <= k)
					{
						Ans = max(Ans, s[a] + s[b] + s[x] + s[y]) ;
					}
				}
			}
		}
	}
	printf("%lld", Ans) ;
	return 0 ;
} 
