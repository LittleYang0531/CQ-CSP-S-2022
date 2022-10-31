#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int inf = 1e9;
const LL INF = 4.1e18;
const int MAXN = 3005, MAXM = 1e4 + 5;

template<typename _T>
inline void Read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) Write( x / 10 );
    putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

std :: vector<int> grph[MAXN];

bool avai[MAXN][MAXN];

int dist[MAXN], q[MAXN];

LL scr[MAXN];
int mx[MAXN][3];

int N, M, K;

inline void BFS( const int &s ) {
    int h = 1, t = 0;
    rep( i, 1, N ) dist[i] = inf;
    dist[q[++ t] = s] = 0;
    while( h <= t ) {
        int u = q[h ++], n = grph[u].size();
        for( int i = 0, v ; i < n ; i ++ )
            if( dist[v = grph[u][i]] > dist[u] + 1 )
                dist[q[++ t] = v] = dist[u] + 1;
    }
}

int main() {
    freopen( "holiday.in", "r", stdin );
    freopen( "holiday.out", "w", stdout );
    Read( N ), Read( M ), Read( K );
    rep( i, 2, N ) Read( scr[i] );
    rep( i, 1, M ) {
        int u, v;
        Read( u ), Read( v );
        grph[u].push_back( v );
        grph[v].push_back( u );
    }
    rep( i, 1, N ) {
        BFS( i );
        rep( j, 1, N ) if( i ^ j )
            avai[i][j] = dist[j] - 1 <= K;
    }
    scr[0] = - INF;
    rep( i, 1, N ) rep( j, 0, 2 ) mx[i][j] = 0;
    rep( i, 2, N ) if( avai[1][i] )
        rep( j, 2, N ) if( i ^ j && avai[i][j] )
            rep( k, 0, 2 ) if( scr[mx[j][k]] <= scr[i] ) {
                per( t, 2, k + 1 ) mx[j][t] = mx[j][t - 1];
                mx[j][k] = i;
                break;
            }
    LL ans = - INF;
    int fir[3] = {}, sec[3] = {};
    rep( i, 2, N ) if( mx[i][0] )
        rep( j, 2, N ) if( i ^ j && mx[j][0] && avai[i][j] ) {
            int totA = 0, totB = 0;
            rep( k, 0, 2 ) {
                if( mx[i][k] && mx[i][k] ^ j )
                    fir[totA ++] = mx[i][k];
                if( mx[j][k] && mx[j][k] ^ i )
                    sec[totB ++] = mx[j][k];
            }
            if( ! totA || ! totB ) continue;
            if( fir[0] ^ sec[0] ) ans = Max( ans, scr[i] + scr[j] + scr[fir[0]] + scr[sec[0]] );
            else {
                if( totA >= 2 ) ans = Max( ans, scr[i] + scr[j] + scr[fir[1]] + scr[sec[0]] );
                if( totB >= 2 ) ans = Max( ans, scr[i] + scr[j] + scr[fir[0]] + scr[sec[1]] );
            }
        }
    Write( ans ), putchar( '\n' );
    return 0;
}