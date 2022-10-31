#include<bits/stdc++.h>
using namespace std ;
const int Ma = 25 , Max = 1e5 + 10 , TIL = ( 1 << 28 ) ;
int FA_Min[Max][Ma] , FA_Max[Max][Ma] ;
int FB_Min[Max][Ma] , FB_Max[Max][Ma] ;
int A[Max] , B[Max] ; 
int L , R , L1 , R1 ; 
int N , M , Q ; 
bool F = true ; 
int Pun( int X , int Y ) {
	int K = false ;
	while( X + ( 1 << K ) - 1 <= Y ) K ++ ; 
	return K - 1 ;  
}
int main( ) {
	freopen("game.in" , "r" , stdin ) ;
	freopen("game.out" , "w" , stdout ) ;
	scanf("%d%d%d" , &N , &M , &Q ) ;
	for(int i = 1 ; i <= N ; i ++ ) scanf("%d" , &A[i] ) , FA_Min[i][false] = FA_Max[i][false] = A[i] , F &= ( A[i] > 0 ) ;
	for(int i = 1 ; i <= M ; i ++ ) scanf("%d" , &B[i] ) , FB_Min[i][false] = FB_Max[i][false] = B[i] , F &= ( A[i] > 0 ) ;
	for(int l = 1 ; l <= Ma - 1 ; l ++ ) for(int i = 1 ; i + ( 1 << l ) - 1 <= N ; i ++ ){
		FA_Min[i][l] = min( FA_Min[i][l - 1] , FA_Min[i + ( 1 << ( l - 1 ) )][l - 1] ) ;
		FA_Max[i][l] = max( FA_Max[i][l - 1] , FA_Max[i + ( 1 << ( l - 1 ) )][l - 1] ) ;
	} for(int l = 1 ; l <= Ma - 1 ; l ++ ) for(int i = 1 ; i + ( 1 << l ) - 1 <= N ; i ++ ){
		FB_Min[i][l] = min( FB_Min[i][l - 1] , FB_Min[i + ( 1 << ( l - 1 ) )][l - 1] ) ;
		FB_Max[i][l] = max( FB_Max[i][l - 1] , FB_Max[i + ( 1 << ( l - 1 ) )][l - 1] ) ;
	} 
	while( Q -- ) {
		scanf("%d%d%d%d" , &L , &R , &L1 , &R1 ) ;
		int KA = Pun( L , R ) ;
		int KB = Pun( L1 , R1 ) ;
		if( F ) printf("%d\n" , max( FA_Max[L][KA] , FA_Max[R - ( 1 << KA )][KA] ) * min( FA_Min[L1][KB] , FA_Max[R1 - ( 1 << KB )][KB] ) ) ;
		else {
			if( L == R ) printf("%d\n" , A[L] * min( FA_Min[L1][KB] , FA_Max[R1 - ( 1 << KB )][KB] ) ) ;
			else if( L1 == R1 ) printf("%d\n" , max( FA_Max[L][KA] , FA_Max[R - ( 1 << KA )][KA] ) * B[L1] ) ;
		}
	}
	return false ;
}

/*

3 2 2
0 1 -2
-3 4
2 3 2 2
*/

