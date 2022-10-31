#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const int MAXN = 2e5;
const int Inf1 = 0x3f3f3f3f; const ll Inf2 = 0x3f3f3f3f3f3f3f3fll;
int n , k , q , val[ MAXN + 5 ];
vector< int > Graph[ MAXN + 5 ];

int dep[ MAXN + 5 ] , par[ MAXN + 5 ] , siz[ MAXN + 5 ] , hs[ MAXN + 5 ];
void dfs1( int u , int fa ) {
    dep[ u ] = dep[ fa ] + 1; par[ u ] = fa; siz[ u ] = 1;
    for( int v : Graph[ u ] ) if( v != fa ) {
        dfs1( v , u ); siz[ u ] += siz[ v ];
        if( siz[ hs[ u ] ] < siz[ v ] ) hs[ u ] = v;
    }
}
int tim , top[ MAXN + 5 ] , dfn[ MAXN + 5 ] , seq[ MAXN + 5 ];
void dfs2( int u , int tp ) {
    top[ u ] = tp; dfn[ u ] = ++ tim; seq[ tim ] = u;
    if( hs[ u ] ) dfs2( hs[ u ] , tp );
    for( int v : Graph[ u ] ) if( v != par[ u ] && v != hs[ u ] ) dfs2( v , v );
}
int lca( int u , int v ) {
    while( top[ u ] != top[ v ] ) {
        if( dep[ top[ u ] ] < dep[ top[ v ] ] ) swap( u , v );
        u = par[ top[ u ] ];
    }
    return dfn[ u ] <= dfn[ v ] ? u : v;
}

int f1[ MAXN + 5 ][ 4 ] , f2[ MAXN + 5 ][ 4 ] , g[ MAXN + 5 ][ 4 ];
void dfs3( int u , int fa ) {
    f1[ u ][ 0 ] = val[ u ];
    for( int v : Graph[ u ] ) if( v != fa ) {
        dfs3( v , u );
        for( int i = 1 ; i <= 3 ; i ++ ) {
            if( f1[ v ][ i - 1 ] < f1[ u ][ i ] ) f2[ u ][ i ] = f1[ u ][ i ] , f1[ u ][ i ] = f1[ v ][ i - 1 ];
            else if( f1[ v ][ i - 1 ] < f2[ u ][ i ] ) f2[ u ][ i ] = f1[ v ][ i - 1 ];
        }
    }
}
void dfs4( int u , int fa ) {
    for( int v : Graph[ u ] ) if( v != fa ) {
        g[ v ][ 1 ] = val[ u ];
        for( int i = 2 ; i <= 3 ; i ++ ) {
            g[ v ][ i ] = g[ u ][ i - 1 ];
            if( f1[ u ][ i - 1 ] == f1[ v ][ i - 1 ] ) g[ v ][ i ] = min( g[ v ][ i ] , f2[ u ][ i - 1 ] );
            else g[ v ][ i ] = min( g[ v ][ i ] , f1[ u ][ i - 1 ] );
        }
        dfs4( v , u );
    }
}

namespace Solve1 {
    ll f[ MAXN + 5 ];
    void dfs( int u , int fa ) {
        f[ u ] = f[ fa ] + val[ u ];
        for( int v : Graph[ u ] ) if( v != fa ) dfs( v , u );
    }
    void Solve( ) {
        dfs( 1 , 0 );
        for( int i = 1 , s , t ; i <= q ; i ++ ) {
            scanf("%d %d",&s,&t); int u = lca( s , t );
            printf("%lld\n", f[ s ] + f[ t ] - f[ u ] - f[ par[ u ] ] );
        }
    }
}

namespace Solve2 {
    int v[ MAXN + 5 ][ 3 ]; ll dp[ MAXN + 5 ][ 3 ]; //0,1,2
    vector< int > rv;
    void Solve( ) {
        for( int Q = 1 , s , t ; Q <= q ; Q ++ ) {
            scanf("%d %d",&s,&t); int u = lca( s , t );
            int len = 0;
            while( s != u ) {
                ++ len; v[ len ][ 0 ] = val[ s ];
                for( int i = 1 ; i <= k - 1 ; i ++ ) v[ len ][ i ] = f1[ s ][ i ];
                s = par[ s ];
            }
            ++ len; v[ len ][ 0 ] = val[ s ];
            for( int i = 1 ; i <= k - 1 ; i ++ ) v[ len ][ i ] = g[ s ][ i ];
            
            rv.clear();
            while( t != u ) {
                rv.push_back( t );
                t = par[ t ];
            } reverse( rv.begin() , rv.end() );
            for( int p : rv ) {
                ++ len; v[ len ][ 0 ] = val[ p ];
                for( int i = 1 ; i <= k - 1 ; i ++ ) v[ len ][ i ] = f1[ p ][ i ];
            }

            for( int i = 1 ; i <= len ; i ++ ) for( int j = 0 ; j <= 2 ; j ++ ) dp[ i ][ j ] = Inf2;
            dp[ 1 ][ 0 ] = v[ 1 ][ 0 ];
            for( int i = 2 ; i <= len ; i ++ ) for( int j = 0 ; j <= 2 ; j ++ ) {
                for( int p = max( i - 3 , 1 ) ; p <= i - 1 ; p ++ ) for( int q = 0 ; q <= 2 ; q ++ ) {
                    if( i - p + q + j <= k ) {
                        dp[ i ][ j ] = min( dp[ i ][ j ] , dp[ p ][ q ] + v[ i ][ j ] );
                    }
                }
            }
            printf("%lld\n", dp[ len ][ 0 ] );
        }
    }
}

int main( ) {
    freopen("transmit.in","r",stdin);
    freopen("transmit.out","w",stdout);

    scanf("%d %d %d",&n,&q,&k);
    for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&val[ i ]);
    for( int i = 1 , u , v ; i < n ; i ++ ) {
        scanf("%d %d",&u,&v);
        Graph[ u ].push_back( v );
        Graph[ v ].push_back( u ); 
    }
    dfs1( 1 , 0 ); dfs2( 1 , 1 );
    memset( f1 , 0x3f , sizeof( f1 ) );
    memset( f2 , 0x3f , sizeof( f2 ) );
    memset( g , 0x3f , sizeof( g ) );
    dfs3( 1 , 0 ); dfs4( 1 , 0 );
    // for( int i = 1 ; i <= n ; i ++ ) for( int j = 1 ; j <= k - 1 ; j ++ )
    //     printf("%d %d %d\n", i , j , g[ i ][ j ] );

    if( k == 1 ) Solve1::Solve();
    else Solve2::Solve();
    return 0;
}