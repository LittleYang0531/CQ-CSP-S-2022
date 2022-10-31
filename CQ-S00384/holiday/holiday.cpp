#include<iostream>
#include<cstdio>
#include<cstring>
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

ll dp[N][5] , w[N] ;
int fa[N][105] , fl[N] , k , n , m ;
vector<int> G[N] ;

void dfs(int u , int f , int d)
{
	fl[u] = fa[u][1] = f ;
	for(int i = 2 ; i <= min(d , k) ; i++)
		fa[u][i] = fa[fa[u][i - 1]][1] ;
	for(int i = 1 ; i <= min(d , k) ; i++)
	{
		if(fa[u][i] == 1) dp[u][1] = w[u] ;
		for(int l = 2 ; l <= min(d , 4) ; l++)
			dp[u][l] = max(dp[fa[u][i]][l - 1] + w[u] , dp[u][l]) ;
	}
	for(int v : G[u])
	{
		if(fl[v]) continue ;
		dfs(v , u , d + 1) ;
	}		
}

int dist[N] ;
vector<int> kth ;

void DFS(int u , int d)
{
	if(d > k) return ;
	if(u != 1)kth.push_back(u) ;
	for(int v : G[u])
	{
		if(dist[v] <= d + 1) continue ;
		dist[v] = d + 1 ;
		DFS(v , d + 1) ;
	}		
}

ll ans = 0 ;

void dfs0(int u ,  int s , int d)
{
	if(d > 4) return ;
	fl[u] = 1 ;
	for(int v : G[u])
	{
		if(d == 4 && v == 1) ans = max(ans , s + w[u]) ;
		if(fl[v]) continue ;
		dfs0(v , s + w[u] , d + 1) ;
	}
	fl[u] = 0 ;
}

int main()
{
	freopen("holiday.in","r",stdin) ;
	freopen("holiday.out","w",stdout) ;

	n = rd() ; m = rd() ; k = rd() + 1 ;
	for(int i = 2 ; i <= n ; i++) w[i] = rd() ;
	for(int i = 1 ; i <= m ; i++)
	{
		int x = rd() , y = rd() ; 
		G[x].push_back(y) ; G[y].push_back(x) ;
	}
	
	if(!k)
	{
		dfs0(1 , 0 , 0) ;
		cout << ans ;
		return 0 ;
	}
	
	memset(dist , 127 , sizeof dist) ;
	DFS(1 , 0) ;
	
//	for(int v : kth) cout << v << ' ' ;
//	cout << '\n' ;

	for(int v : G[1])
	{
		memset(dp , 0 , sizeof dp) ;
		memset(fa , 0 , sizeof fa) ;
		memset(fl , 0 , sizeof fl) ;
		fl[1] = 1 ; dfs(v , 1 , 1) ;
	
//		cout << '\n' << v << " : \n" ;	
//		for(int i = 1 ; i <= n ; i++)
//		{
//			for(int j = 1 ; j <= 4 ; j++)
//				cout << dp[i][j] << ' ' ;
//			cout << '\n' ;
//		}
//		cout << '\n' ;
		
		for(int v : kth)
		{
//			cout << v << ' ' << dp[v][4] <<'\n' ;
			ans = max(dp[v][4] , ans) ;	
		}
	}
	cout << ans ;
	return 0 ;
}
