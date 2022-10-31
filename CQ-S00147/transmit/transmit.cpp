#include <queue>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const int MAXN = 2e5 + 5, MAXLOG = 20;

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

struct Edge {
    int to, nxt;
} Graph[MAXN << 1];

int tour[MAXLOG][MAXN << 1], lg2[MAXN << 1];
int dep[MAXN], fir[MAXN], ID = 0;

int val[MAXN];
int head[MAXN], cnt = 1;

int N, Q, K;

inline void AddEdge( const int &from, const int &to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

void Init( const int &u, const int &fa ) {
    dep[u] = dep[fa] + 1;
    tour[0][fir[u] = ++ ID] = u;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa )
            Init( v, u ), tour[0][++ ID] = u;
}

inline void Init() {
    Init( 1, 0 ), lg2[0] = -1;
    rep( i, 1, ID ) lg2[i] = lg2[i >> 1] + 1;
    for( int j = 1, a, b ; j <= lg2[ID] ; j ++ )
        for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= ID ; i ++ ) {
            a = tour[j - 1][i], b = tour[j - 1][i + ( 1 << ( j - 1 ) )];
            tour[j][i] = dep[a] < dep[b] ? a : b;
        }
}

inline int LCA( const int &u, const int &v ) {
    int l = fir[u], r = fir[v];
    if( l > r ) std :: swap( l, r );
    int k = lg2[r - l + 1], a = tour[k][l],
        b = tour[k][r - ( 1 << k ) + 1];
    return dep[a] < dep[b] ? a : b;
}

inline int DirectDist( const int &u, const int &v ) {
    return dep[u] + dep[v] - 2 * dep[LCA( u, v )];
}

namespace Force {
    const int MAXn = 2005, MAXS = 330;

    typedef unsigned long long ull;
    typedef std :: pair<LL, int> Node;

    struct Bitset {
        ull bit[MAXS];

        Bitset(): bit{} {}

        inline void Set( const int &x ) {
            bit[x >> 6] |= 1llu << ( x & 63 );
        }

        inline void Reset( const int &x ) {
            bit[x >> 6] &= ~ ( 1llu << ( x & 63 ) );
        }

        inline int FindNext( const int &x ) {
            int y = x & 63;
            if( y < 63 && ( bit[x >> 6] >> ( y + 1 ) ) ) 
                return __builtin_ctzll( bit[x >> 6] >> ( y + 1 ) ) + x + 1;
            for( unsigned k = ( x >> 6 ) + 1 ; k < MAXS ; k ++ )
                if( bit[k] ) return __builtin_ctzll( bit[k] ) | ( k << 6 );
            return -1;
        }

        inline Bitset operator & ( const Bitset &q ) {
            Bitset ret;
            for( int k = 0 ; k < MAXS ; k ++ )
                ret.bit[k] = bit[k] & q.bit[k];
            return ret;
        }
    };

    Bitset grph[MAXn], vis, tmp, all;
    
    std :: priority_queue<Node, std :: vector<Node>, std :: greater<Node> > q;

    inline LL Dijkstra( const int &s, const int &t ) {
        if( s == t ) return val[t];

        vis = all;
        while( ! q.empty() ) q.pop();
        q.push( { val[s], s } ), vis.Reset( s );
        while( ! q.empty() ) {
            Node h = q.top(); q.pop();
            LL d = h.first; int u = h.second;
            tmp = vis & grph[u];
            for( int v = tmp.FindNext( 0 ) ; ~ v ; v = tmp.FindNext( v ) ) {
                if( v == t ) return d + val[t];
                vis.Reset( v ), q.push( { d + val[v], v } );
            }
        }
        return INF;
    }

    void Solve() {
        rep( i, 1, N ) all.Set( i );
        rep( i, 1, N ) rep( j, 1, N )
            if( DirectDist( i, j ) <= K )
                grph[i].Set( j );
        while( Q -- ) {
            int s, t; Read( s ), Read( t );
            Write( Dijkstra( s, t ) ), putchar( '\n' );
        }
    }
}

namespace Simple {
    LL pref[MAXN];

    void DFS( const int &u, const int &fa ) {
        pref[u] = pref[fa] + val[u];
        for( int i = head[u], v ; i ; i = Graph[i].nxt )
            if( ( v = Graph[i].to ) ^ fa ) DFS( v, u );
    }

    inline LL Calc( const int &s, const int &t ) {
        int w = LCA( s, t );
        return pref[s] + pref[t] - 2 * pref[w] + val[w];
    }

    inline void Solve() {
        DFS( 1, 0 );
        while( Q -- ) {
            int s, t; Read( s ), Read( t );
            Write( Calc( s, t ) ), putchar( '\n' );
        }
    }
}

namespace Medium {
    LL pref[MAXN][2]; int fath[MAXN];

    inline void DFS( const int &u, const int &fa, const int &lst ) {
        fath[u] = fa;
        pref[u][0] = pref[lst][0] + val[u];
        if( fa ) pref[u][1] = Min( pref[fa][0], pref[lst][1] ) + val[u]; 
        else pref[u][1] = INF;
        for( int i = head[u], v ; i ; i = Graph[i].nxt )
            if( ( v = Graph[i].to ) ^ fa )
                DFS( v, u, fa );
    }

    inline void Process() {
        pref[0][1] = INF, DFS( 1, 0, 0 );
    }

    inline LL Calc( const int &s, const int &t ) {
        LL ret = INF;
        int w = LCA( s, t );
        int ds = dep[s] % 2, dt = dep[t] % 2, dw = dep[w] % 2;
        if( DirectDist( s, t ) % 2 == 0 ) {
            ret = 0;
            ret += pref[s][0] - pref[dw == ds ? w : fath[w]][0];
            ret += pref[t][0] - pref[dw == dt ? w : fath[w]][0];
            if( dw == dt && dw == ds ) ret += val[w];
        } else {
            if( dep[s] > dep[w] ) {
                LL tmp = 0;
                tmp += pref[s][1] - pref[dw == ds ? fath[w] : w][0];
                tmp += pref[t][0] - pref[dw == dt ? w : fath[w]][0];
                if( ds ^ dw ) tmp += val[w];
                ret = Min( ret, tmp );
            } 
            if( dep[t] > dep[w] ) {
                LL tmp = 0;
                tmp += pref[s][0] - pref[dw == ds ? w : fath[w]][0];
                tmp += pref[t][1] - pref[dw == dt ? fath[w] : w][0];
                if( dt ^ dw ) tmp += val[w];
                ret = Min( ret, tmp );
            }
        }
        return ret;
    }

    inline void Solve() {
        Process();
        while( Q -- ) {
            int s, t; Read( s ), Read( t );
            Write( Calc( s, t ) ), putchar( '\n' );
        }
    }
}

int main() {
    freopen( "transmit.in", "r", stdin );
    freopen( "transmit.out", "w", stdout );
    Read( N ), Read( Q ), Read( K );
    rep( i, 1, N ) Read( val[i] );
    rep( i, 1, N - 1 ) {
        int u, v; Read( u ), Read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    Init();
    if( N <= 2000 )
        return Force :: Solve(), 0;
    if( K == 1 )
        return Simple :: Solve(), 0;
    if( K == 2 )
        return Medium :: Solve(), 0;
    return 0;
}