#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define Lint __int128
#define pii pair< Lint , int >
#define fi first
#define sc second
#define mp make_pair

const int MAXN = 2500;
int n , m , k; ll val[ MAXN + 5 ];
vector< int > Graph[ MAXN + 5 ];

int dis[ MAXN + 5 ][ MAXN + 5 ];
void bfs( int s ) {
    queue< int > q;
    q.push( s ); dis[ s ][ s ] = 0;
    while( !q.empty() ) {
        int u = q.front(); q.pop();
        for( int v : Graph[ u ] ) if( dis[ s ][ v ] > dis[ s ][ u ] + 1 ) {
            dis[ s ][ v ] = dis[ s ][ u ] + 1;
            q.push( v );
        }
    }
}

pii pref[ MAXN + 5 ][ MAXN + 5 ];

int main( ) {
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);

    scanf("%d %d %d",&n,&m,&k); k ++;
    for( int i = 2 ; i <= n ; i ++ ) scanf("%lld",&val[ i ]);
    for( int i = 1 , u , v ; i <= m ; i ++ ) {
        scanf("%d %d",&u,&v);
        Graph[ u ].push_back( v );
        Graph[ v ].push_back( u );
    }

    memset( dis , 0x3f , sizeof( dis ) );
    for( int i = 1 ; i <= n ; i ++ ) bfs( i );
    for( int i = 1 ; i <= n ; i ++ ) {
        for( int j = 1 ; j <= n ; j ++ ) {
            if( j == 1 || dis[ i ][ j ] > k || dis[ j ][ 1 ] > k || j == i ) pref[ i ][ j ] = mp( (Lint)-4e18 , j );
            else pref[ i ][ j ] = mp( val[ j ] , j );
        }
        sort( pref[ i ] + 1 , pref[ i ] + n + 1 , greater< pii >() );
    }

    ll ans = 0;
    for( int u = 2 ; u <= n ; u ++ )
        for( int v = 2 ; v <= n ; v ++ )
            if( u != v && dis[ u ][ v ] <= k ) {
                pii u1 = mp( 0 , 0 ) , u2 = mp( 0 , 0 ) , v1 = mp( 0 , 0 ) , v2 = mp( 0 , 0 );
                for( int i = 1 ; i <= 3 ; i ++ ) if( pref[ u ][ i ].sc != v ) {
                    if( !u1.sc ) u1 = pref[ u ][ i ]; else if( !u2.sc ) u2 = pref[ u ][ i ];
                }
                for( int i = 1 ; i <= 3 ; i ++ ) if( pref[ v ][ i ].sc != u ) {
                    if( !v1.sc ) v1 = pref[ v ][ i ]; else if( !v2.sc ) v2 = pref[ v ][ i ];
                }
                if( u1.sc == v1.sc ) ans = max( (Lint)ans , val[ u ] + val[ v ] + max( u1.fi + v2.fi , u2.fi + v1.fi ) );
                else ans = max( (Lint)ans , val[ u ] + val[ v ] + u1.fi + v1.fi );
            }
    printf("%lld\n", ans );
    return 0;
}