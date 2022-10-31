#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define Lint __int128
#define ll long long

template<typename _T>
void read( _T &x ) {
    x = 0; int f = 1; char s = getchar();
    for( ; s < '0' || s > '9' ; s = getchar() ) if( s == '-' ) f = -1;
    for( ; s >= '0' && s <= '9' ; s = getchar() ) x = x * 10 + s - '0';
    x *= f;
}
int pb , buf[ 100 ];
template<typename _T>
void write( _T x , char ed = '\n' ) {
    if( x == 0 ) buf[ ++ pb ] = 0;
    if( x < 0 ) x = -x , putchar('-');
    while( x ) buf[ ++ pb ] = x % 10 , x /= 10;
    while( pb ) putchar( buf[ pb -- ] + '0' );
    putchar( ed );
}

const int MAXN = 1e5 , MAXK = 20;
int n , m , q , a[ MAXN + 5 ] , b[ MAXN + 5 ];
int mna[ MAXN + 5 ][ MAXK + 1 ] , mxa[ MAXN + 5 ][ MAXK + 1 ] , mnb[ MAXN + 5 ][ MAXK + 1 ] , mxb[ MAXN + 5 ][ MAXK + 1 ];
int fa[ MAXN + 5 ][ MAXK + 1 ] , ga[ MAXN + 5 ][ MAXK + 1 ];

inline int Qmaxa( int l , int r ) {
    int k = log2( r - l + 1 );
    return max( mxa[ l ][ k ] , mxa[ r - ( 1 << k ) + 1 ][ k ] );
}
inline int Qmina( int l , int r ) {
    int k = log2( r - l + 1 );
    return min( mna[ l ][ k ] , mna[ r - ( 1 << k ) + 1 ][ k ] );
}
inline int Qmaxb( int l , int r ) {
    int k = log2( r - l + 1 );
    return max( mxb[ l ][ k ] , mxb[ r - ( 1 << k ) + 1 ][ k ] );
}
inline int Qminb( int l , int r ) {
    int k = log2( r - l + 1 );
    return min( mnb[ l ][ k ] , mnb[ r - ( 1 << k ) + 1 ][ k ] );
}
inline Lint Qaf( int l , int r ) {
    int k = log2( r - l + 1 );
    int val = max( fa[ l ][ k ] , fa[ r - ( 1 << k ) + 1 ][ k ] );
    return val == -1e9 - 1 ? -1e18 : val;
}
inline Lint Qag( int l , int r ) {
    int k = log2( r - l + 1 );
    int val = min( ga[ l ][ k ] , ga[ r - ( 1 << k ) + 1 ][ k ] );
    return val == 1e9 + 1 ? 1e18 : val;
}

int main( ) {
    freopen("game.in","r",stdin); 
    freopen("game.out","w",stdout);

    read( n ); read( m ); read( q );
    for( int i = 1 ; i <= n ; i ++ ) read( a[ i ] );
    for( int i = 1 ; i <= m ; i ++ ) read( b[ i ] );

    for( int i = 1 ; i <= n ; i ++ ) {
        mna[ i ][ 0 ] = mxa[ i ][ 0 ] = a[ i ];
        fa[ i ][ 0 ] = a[ i ] <= 0 ? a[ i ] : ( -1e9 - 1 );
        ga[ i ][ 0 ] = a[ i ] >= 0 ? a[ i ] : ( 1e9 + 1 );
    }
    for( int j = 1 ; 1 << j <= n ; j ++ )
        for( int i = 1 ; i + ( 1 << j ) - 1 <= n ; i ++ ) {
            mxa[ i ][ j ] = max( mxa[ i ][ j - 1 ] , mxa[ i + ( 1 << j - 1 ) ][ j - 1 ] );
            mna[ i ][ j ] = min( mna[ i ][ j - 1 ] , mna[ i + ( 1 << j - 1 ) ][ j - 1 ] );
            fa[ i ][ j ] = max( fa[ i ][ j - 1 ] , fa[ i + ( 1 << j - 1 ) ][ j - 1 ] );
            ga[ i ][ j ] = min( ga[ i ][ j - 1 ] , ga[ i + ( 1 << j - 1 ) ][ j - 1 ] );
        }

    for( int i = 1 ; i <= m ; i ++ )
        mnb[ i ][ 0 ] = mxb[ i ][ 0 ] = b[ i ];
    for( int j = 1 ; 1 << j <= m ; j ++ )
        for( int i = 1 ; i + ( 1 << j ) - 1 <= m ; i ++ ) {
            mxb[ i ][ j ] = max( mxb[ i ][ j - 1 ] , mxb[ i + ( 1 << j - 1 ) ][ j - 1 ] );
            mnb[ i ][ j ] = min( mnb[ i ][ j - 1 ] , mnb[ i + ( 1 << j - 1 ) ][ j - 1 ] );
        }

    for( int i = 1 , l1 , r1 , l2 , r2 ; i <= q ; i ++ ) {
        read( l1 ); read( r1 ); read( l2 ); read( r2 );

        int xa = Qmaxa( l1 , r1 ) , na = Qmina( l1 , r1 );
        int xb = Qmaxb( l2 , r2 ) , nb = Qminb( l2 , r2 );
        ll ans = -1e18;
        if( xb > 0 ) {
            ans = max( (Lint)ans , Qaf( l1 , r1 ) * xb );
        }
        else {
            if( na <= 0 ) ans = max( ans , 1ll * na * xb );
        }
        if( nb < 0 ) {
            ans = max( (Lint)ans , Qag( l1 , r1 ) * nb );
        }
        else {
            if( xa >= 0 ) ans = max( ans , 1ll * xa * nb );
        }
        write( ans );
    }
    return 0;
}