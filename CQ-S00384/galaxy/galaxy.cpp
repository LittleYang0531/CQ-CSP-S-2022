#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<stack>
#include<vector>

using namespace std ;
typedef long long ll ;

const int N = 25000 + 5 ;
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

vector<int> G[N] , ins[N] ;
set<pair<int,int> > mp ;
int n , m , q ;
int broken[N] ;
int deg[N] , in[N] , out[N] , f[N] ;

int topsort()
{
	stack<int> sta ;
	for(int i = 1 ; i <= n ; i++)
		deg[i] = in[i] ;
	memset(f , 1 , sizeof f) ;
	for(int i = 1 ; i <= n ; i++)
		if(!deg[i]) f[i] = 0 , sta.push(i) ;
	while(!sta.empty())
	{
		int u = sta.top() ; sta.pop() ;
		for(int v : G[u])
		if(!mp.count({u , v}))
		{
			deg[v]-- ;
			if(!deg[v]) f[v] = 0 , sta.push(v) ;
		}
	}
	for(int i = 1 ; i <= n ; i++)
		if(f[i]) return 1 ;
	return 0 ;
}

int judge()
{
	for(int i = 1 ; i <= n ; i++)
		if(out[i] != 1) return 0 ;
	return 1 ;
}

int main()
{
	freopen("galaxy.in","r",stdin) ;
	freopen("galaxy.out","w",stdout) ;

	n = rd() ; m = rd() ; 
	for(int i = 1 ; i <= m ; i++)
	{
		int x = rd() , y = rd() ; 
		G[x].push_back(y) ;
		ins[y].push_back(x) ;
		in[y]++ ; out[x]++ ;
	}
	q = rd() ;
	for(int i = 1 ; i <= q ; i++)
	{
		int t = rd() , x = rd() , y ;
		switch(t)
		{
			case 1 :
				y = rd() ;
				mp.insert({x , y}) ;
				out[x]-- ; in[y]-- ;
				break ;	
			case 2 :
				if(!in[x]) break ;
				for(int y : ins[x])
					if(!mp.count({y,x}))
					mp.insert({y , x}) , 
					out[y]-- , in[x]-- ;
				break ;
			case 3 :
				y = rd() ;
				out[x]++ ; in[y]++ ;
				mp.erase({x , y}) ;
				break ;
			case 4 :
				if(in[x] == ins[x].size()) break ;
				for(int y : ins[x])
					if(mp.count({y,x}))
					mp.erase({y , x}) ,
					out[y]++ , in[x]++ ;
				break ;
		}
		
//		cout << '\n' << i << " : \n" ;
//		for(int i = 1 ; i <= n ; i++)
//			for(int j : G[i])
//				if(!mp.count({i , j}))
//					cout << i << ' ' << j << '\n' ;
		
		if(judge() && topsort()) puts("YES") ;
		else puts("NO") ; 
	}
	return 0 ;
}
