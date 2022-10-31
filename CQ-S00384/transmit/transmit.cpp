#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>

using namespace std ;
typedef long long ll ;

const int N = 2500 + 5 ;
int M = 10000 + 5 ;

ll rd()
{
	ll x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch > '9' || ch < '0')
	{
		if(ch == '-') f = -1 ;
		ch = getchar() ;
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) +  (ch ^ 48) ;
		ch = getchar() ;
	}
	return x *= f ;
}

int vis[2005][2005] ;
vector<int> G[2005] , T[2005] ;
int n , q , k ;

ll dis[2005] , d[2005] ;
int f[2005] ;
priority_queue<pair<ll , int> > Q ;

void Dij(int s)
{
	while(!Q.empty()) Q.pop() ;
	memset(f , 0 , sizeof f) ;
	memset(d , 127 , sizeof d) ;
	d[s] = dis[s] ; Q.push({-d[s] , s}) ;
	while(!Q.empty())
	{
		int u = Q.top().second ; Q.pop() ;
		f[u] = 0 ;
		for(int v : G[u])
		{
			if(d[u] + dis[v] <= d[v])
			{
				d[v] = dis[v] + d[u] ;
				if(!f[1])
				{
					Q.push({-d[v] , v}) ;
					f[v] = 1 ;
				}
			}
		}
	}
}

void add2()
{
	for(int u = 1 ; u <= n ; u++)
		for(int t : T[u]) for(int v : T[t])
		if(!vis[u][v] && u != v)
		{
			G[u].push_back(v) ;
			G[v].push_back(u) ;
			vis[u][v] = vis[u][v] = 1 ;
		}
}
void add3()
{
	for(int u = 1 ; u <= n ; u++)
		for(int i : T[u])
		for(int j : T[i]) if(j != u)
		for(int v : T[j]) if(v != j)
		if(!vis[u][v] && u != v)
		{
			G[u].push_back(v) ;
			G[v].push_back(u) ;
			vis[u][v] = vis[u][v] = 1 ;
		}
}

int main()
{
	freopen("transmit.in","r",stdin) ;
	freopen("transmit.out","w",stdout) ;
//	cout << 2000*2000*(int)log2(2000) ;
	n = rd() ; q = rd() ; k = rd() ;
	for(int i = 1 ; i <= n ; i++)
		dis[i] = rd() ;
	for(int i = 1 ; i < n ; i++)
	{
		int x = rd() , y = rd() ; 
		T[x].push_back(y) ; T[y].push_back(x) ;
		G[x].push_back(y) ; G[y].push_back(x) ;
		vis[x][y] = vis[y][x] = 1 ;
	}
	if(k == 2)
		add2() ;
	else if(k == 3)
		add2() , add3() ;
	for(int i = 1 ; i <= q ; i++)
	{
		int s = rd() , e = rd() ;
		Dij(s) ;
		cout << d[e] << '\n' ;
	}
	return 0 ;
}
