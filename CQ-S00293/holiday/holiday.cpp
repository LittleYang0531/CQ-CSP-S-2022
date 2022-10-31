#include<bits/stdc++.h>
using namespace std ;
const int Max = 1e4 + 10 , TIL = 1e7 + 9 ;
struct Node { int V , Ne ; } Tr[Max * 2] ; 
int Bo[Max] , Ecn = 1 ; 
long long A[Max] ;
queue < int > Q ; 
bool Vis[Max] ;
int N , M , K ;
int Maxn , L ;
int Un , Ans ;
int Dis[Max] ;
int X , Y ;
int Pu ; 
void ADD( int X , int Y ) {
	Tr[Ecn].V = Y ; 
	Tr[Ecn].Ne = Bo[X] ;
	Bo[X] = Ecn ++ ; 
}
void BFS( int X , int P , int Yun , int Sun , int Mun ) {
	//cout << X << endl ;  
	if( X == 1 && P == 4 ) Ans = max( Ans , Sun ) ; 
	if( ( P == 4 && X == 1 ) || Yun >= Pu + 1 ) return ; 
	for(int i = Bo[X] ; i ; i = Tr[i].Ne ) {
		int V = Tr[i].V ; 
		if( Yun + Dis[V] >= Pu ) continue ; 
		if( !Vis[V] && V != 1 && P != 4 && Mun <= K ) Vis[V] = true , BFS( V , P + 1 , Yun + 1 , Sun + A[V] , false ) , Vis[V] = false ; 
		if( Mun <= K && !( Mun == K && Vis[V] )) BFS( V , P , Yun + 1 , Sun , Mun + 1 ) ; 
	}
}
void Diun( ) {
	Dis[1] = false ; 
	for(int i = 2 ; i <= N ; i ++ ) Dis[i] = TIL ; 
	for(int P = 1 ; P <= N - 1 ; P ++ ) {
		Maxn = TIL , L = - 1 ; 
		for(int i = 1 ; i <= N ; i ++ )
			if( Dis[i] <= Maxn && !Vis[i] ) Maxn = Dis[i] , L = i ;
		Vis[L] = true ; 
		for(int i = Bo[L] ; i ; i = Tr[i].Ne ) 
			Dis[Tr[i].V] = min( Dis[Tr[i].V] , Dis[L] + 1 ) ;
	}
}
int main( ) {
	freopen("holiday.in" , "r" , stdin ) ;
	freopen("holiday.out" , "w" , stdout ) ;
	scanf("%d%d%d" , &N , &M , &K ) ;
	for(int i = 2 ; i <= N ; i ++ ) scanf("%d" , &A[i] ) ;
	for(int i = 1 ; i <= M ; i ++ ) {
		scanf("%d%d" , &X , &Y ) ;
		ADD( X , Y ) ; ADD( Y , X ) ;
	} 
	for(int i = 1 ; i <= N ; i ++ ) Vis[i] = false ; 
	Diun( ) ; Pu = min( M , 5 * ( K + 1 ) )  ;
	for(int i = 1 ; i <= N ; i ++ ) Vis[i] = false ;
	BFS( 1 , false , false , false , false ) ;
	printf("%d\n" , Ans ) ; 
	return false ; 
} 
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/


