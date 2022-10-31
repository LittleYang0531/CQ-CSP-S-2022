#include <cstdio>
#include <vector>
#include <assert.h>
using namespace std;

const int MAXN = 5e5;
int n , m , q; vector< int > bel[ MAXN + 5 ] , Graph[ MAXN + 5 ];

struct dsu {
    int fa[ MAXN + 5 ] , siz;
    void make( ) { siz = n; for( int i = 1 ; i <= n ; i ++ ) fa[ i ] = i; }
    int find( int x ) { return x == fa[ x ] ? x : fa[ x ] = find( fa[ x ] ); }
    void unite( int u , int v ) {
        int x = find( u ) , y = find( v );
        if( x == y ) return; fa[ x ] = y; siz --;
    }
}S;

int in[ MAXN + 5 ];
bool Check( ) {
    if( n == 1 ) return 1;
    for( int i = 1 ; i <= n ; i ++ ) in[ i ] = 0;
    for( int u = 1 ; u <= n ; u ++ ) for( int v : Graph[ u ] ) in[ v ] ++;
    // for( int i = 1 ; i <= n ; i ++ ) printf("%d ", in[ i ] ); puts("");
    // for( int u = 1 ; u <= n ; u ++ ) for( int v : Graph[ u ] ) printf("%d %d\n", u , v );
    for( int i = 1 ; i <= n ; i ++ ) if( in[ i ] != 1 ) return 0;

    S.make();
    for( int u = 1 ; u <= n ; u ++ ) for( int v : Graph[ u ] ) S.unite( u , v );
    return S.siz == 1;
}

int main( ) {
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    
    scanf("%d %d",&n,&m);
    for( int i = 1 , u , v ; i <= m ; i ++ ) {
        scanf("%d %d",&u,&v); swap( u , v );
        Graph[ u ].push_back( v );
        bel[ u ].push_back( v );
    }

    scanf("%d",&q);
    for( int i = 1 , t , u , v ; i <= q ; i ++ ) {
        scanf("%d %d",&t,&u);
        if( t == 1 ) {
            scanf("%d",&v); swap( u , v );
            for( int i = 0 ; i < Graph[ u ].size() ; i ++ ) {
                if( Graph[ u ][ i ] == v ) Graph[ u ].erase( Graph[ u ].begin() + i );
            }
        }
        if( t == 2 ) {
            Graph[ u ].clear();
        }
        if( t == 3 ) {
            scanf("%d",&v); swap( u , v );
            for( int i = 0 ; i < Graph[ u ].size() ; i ++ ) assert( Graph[ u ][ i ] != v );
            Graph[ u ].push_back( v );
        }
        if( t == 4 ) {
            Graph[ u ] = bel[ u ];
        }
        puts( Check() ? "YES" : "NO" );
    }
    return 0;
}