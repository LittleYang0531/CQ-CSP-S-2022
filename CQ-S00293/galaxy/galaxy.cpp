#include<bits/stdc++.h>
using namespace std ;
const int Ma = 1e5 + 10 , Max = 1e3 + 10 , TIL = 1e7 + 9 ;
struct Node { int V , Ne ; } Tr[Max * 2] ; 
bool Vis[Max][Max] , Tun[Max][Max] ;
bool IS[Ma] , Falg[Ma] ;
int Yun[Ma] , Low[Ma] ;
int Bo[Ma] , Ecn = 1 ; 
int P[Ma] , Mun ;  
int OP , X , Y ;
int N , M , Q ;
int Pin[Ma] ;
int In[Ma] ;
int Time ;
int Ans ;
bool DFS( int X ) {
	Yun[X] = Low[X] = ++ Time ;
	IS[X] = true ; P[ ++ Mun] = X ;
	for(int i = 1 ; i <= N ; i ++ ) {
		if( !Tun[X][i] ) continue ; 
		if( !Yun[i] ) DFS( i ) , Low[X] = min( Low[X] , Low[i] ) ; 
		else if( IS[i] ) Low[X] = min( Low[X] , Yun[i] ) ; 
	}
	if( Low[X] == Yun[X] ) {
		int T = false , Pon = ( P[Mun] != X ) ;
		while( T != X ) {
			T = P[Mun -- ] ; 
			IS[T] = false ; Falg[T] = Pon ; 
		} 
	}
}
int main( ) {
	freopen("galaxy.in" , "r" , stdin ) ;
	freopen("galaxy.out" , "w" , stdout ) ;
	scanf("%d%d" , &N , &M ) ;
	for(int i = 1 ; i <= M ; i ++ ) {
		scanf("%d%d" , &X , &Y ) ; In[X] ++ ;  
		Vis[X][Y] = Tun[X][Y] = true ;  
	} 
	scanf("%d" , &Q ) ;
	while( Q -- ) {
		scanf("%d%d" , &OP , &X ) ; Ans = true ; 
		if( OP == 1 ) scanf("%d" , &Y ) , Tun[X][Y] = false , In[X] -- ;
		if( OP == 2 ) for(int i = 1 ; i <= N ; i ++ ) {
			if(	Tun[i][X] ) In[i] -- ;
			Tun[i][X] = false ;
		}
		if( OP == 3 ) scanf("%d" , &Y ) , Tun[X][Y] = true , In[X] ++ ;
		if( OP == 4 ) for(int i = 1 ; i <= N ; i ++ ) {
			if( Tun[i][X] != Vis[i][X] ) In[i] ++ ;
			Tun[i][X] = Vis[i][X] ;
		}
		for(int i = 1 ; i <= N ; i ++ ) Yun[i] = Low[i] = IS[i] = Pin[i] = Falg[i] = false ; 
		Mun = Time = false ;
		for(int i = 1 ; i <= N ; i ++ ) if( !Yun[i] ) DFS( i ) ; 
		for(int i = 1 ; i <= N ; i ++ ) if( In[i] == 1 ) {
			bool Lin = false ;
			for(int l = 1 ; l <= N ; l ++ ) {
				if( Tun[i][l] && Falg[l] ) {
					Lin = true ; 
					break ;
				} 
			}
			Ans &= Lin ;
			if( !Ans ) break ;
		} else Ans = false ; 
		if( Ans ) printf("YES\n") ; 
		else printf("NO\n") ; 
	} 
	return false ; 
} 
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2

*/


