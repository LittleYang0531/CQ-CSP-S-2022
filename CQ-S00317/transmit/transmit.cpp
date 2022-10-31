#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 20005 ;
int n, Q, k, w[MAXN], u, v, D[MAXN][MAXN], INF = 0x3f3f3f3f ;
bool Vis[MAXN] ;
struct Edge
{
	int v, w ;
} ;
vector<Edge> G[MAXN], P[MAXN] ;
queue<Edge> q ;
int read()
{
	int x = 0 ;
	char c = getchar() ;
	while(c < '0' || c > '9')	c = getchar() ;
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0' ;
		c = getchar() ;
	}
	return x ;
}
void dfs(int id, int Num, int Now)
{
	if(Num == 0)	return ; 
	for(int i = 0; i < P[Now].size(); i ++)
	{
		Edge x = P[Now][i] ;
		G[id].push_back((Edge){x.v, w[id]}) ;
		dfs(id, Num - 1, x.v) ;
	}
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
	freopen("transmit.in", "r", stdin) ;
	freopen("transmit.out", "w",stdout) ;
	n = read(), Q = read(), k = read() ;
	for(int i = 1; i <= n; i ++)
	{
		w[i] = read() ;
	}
	for(int i = 1; i < n; i ++)
	{
		u = read(), v = read() ;
		P[u].push_back((Edge){v, 0}) ;
		P[v].push_back((Edge){u, 0}) ;	
	} 
	for(int i = 1; i <= n; i ++)
	{
		dfs(i, k, i) ;
	}
	for(int i = 1; i <= n; i ++)	SPFA(i) ;
	for(int i = 1; i <= Q; i ++)
	{
		u = read(), v = read() ;
		printf("%d\n", D[u][v] + w[v]) ;
	}
	return 0 ;		
}
