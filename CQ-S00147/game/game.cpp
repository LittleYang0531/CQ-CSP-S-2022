#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 4e18;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e5 + 5, MAXLOG = 18;

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
inline _T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

struct Sequence {
    int posMax[MAXLOG][MAXN], posMin[MAXLOG][MAXN],
        negMax[MAXLOG][MAXN], negMin[MAXLOG][MAXN];
    int cnt0[MAXN], lg2[MAXN];

    Sequence() {}

    inline void Init( int *s, const int &n ) {
        lg2[0] = -1, cnt0[0] = 0;
        rep( i, 1, n ) lg2[i] = lg2[i >> 1] + 1;
        rep( i, 1, n ) {
            posMax[0][i] = s[i] > 0 ? s[i] : - inf;
            posMin[0][i] = s[i] > 0 ? s[i] : inf;
            negMax[0][i] = s[i] < 0 ? - s[i] : - inf;
            negMin[0][i] = s[i] < 0 ? - s[i] : inf;
            cnt0[i] = cnt0[i - 1] + ( s[i] == 0 );
        }
        for( int j = 1 ; j <= lg2[n] ; j ++ )
            for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= n ; i ++ ) {
                posMax[j][i] = Max( posMax[j - 1][i], posMax[j - 1][i + ( 1 << ( j - 1 ) )] );
                negMax[j][i] = Max( negMax[j - 1][i], negMax[j - 1][i + ( 1 << ( j - 1 ) )] );
                posMin[j][i] = Min( posMin[j - 1][i], posMin[j - 1][i + ( 1 << ( j - 1 ) )] );
                negMin[j][i] = Min( negMin[j - 1][i], negMin[j - 1][i + ( 1 << ( j - 1 ) )] );
            }
    }

    inline std :: vector<int> Query( const int &l, const int &r ) {
        std :: vector<int> ret;
        int k = lg2[r - l + 1], t = r - ( 1 << k ) + 1, tmp; 

        if( cnt0[r] > cnt0[l - 1] ) ret.push_back( 0 );
        if( ( tmp = Max( posMax[k][l], posMax[k][t] ) ) > 0 ) ret.push_back( tmp );
        if( ( tmp = Max( negMax[k][l], negMax[k][t] ) ) > 0 ) ret.push_back( - tmp );
        if( ( tmp = Min( posMin[k][l], posMin[k][t] ) ) < inf ) ret.push_back( tmp );
        if( ( tmp = Min( negMin[k][l], negMin[k][t] ) ) < inf ) ret.push_back( - tmp );
        return ret;
    }
};

Sequence seqA, seqB;
int A[MAXN], B[MAXN];

int N, M, Q;

int main() {
    freopen( "game.in", "r", stdin );
    freopen( "game.out", "w", stdout );
    Read( N ), Read( M ), Read( Q );
    rep( i, 1, N ) Read( A[i] );
    rep( i, 1, M ) Read( B[i] );
    seqA.Init( A, N );
    seqB.Init( B, M );
    while( Q -- ) {
        int l1, r1, l2, r2;
        Read( l1 ), Read( r1 ), Read( l2 ), Read( r2 );
        std :: vector<int> avaiA( seqA.Query( l1, r1 ) ),
                           avaiB( seqB.Query( l2, r2 ) );
        LL ans = - INF, res;
        int n = avaiA.size(), m = avaiB.size();
        rep( i, 0, n - 1 ) {
            res = INF;
            rep( j, 0, m - 1 )
                res = Min( res, 1ll * avaiA[i] * avaiB[j] );
            ans = Max( ans, res );
        }
        Write( ans ), putchar( '\n' );
    }
    return 0;
}