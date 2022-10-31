#include <map>
#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 5e5 + 5, MAXM = 5e5 + 5;

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

std :: map<LL, int> edg;

int opt[MAXN], qX[MAXN], qY[MAXN];

int cnt[MAXN], all = 0;
int fr[MAXN], to[MAXN];
bool alv[MAXN];

int N, M, Q;

#define GetId( x, y ) ( 1ll * (x) * ( N + 1 ) + (y) )

inline bool Chk() {
    if( all != N ) return false;
    rep( i, 1, N )
        if( cnt[i] != 1 )
            return false;
    return true;
}

namespace Force {
    std :: vector<int> grphIn[MAXN]; int degIn[MAXN];
    std :: vector<int> grphOt[MAXN]; int degOt[MAXN];

    void Solve() {
        rep( i, 1, M )
            degIn[to[i]] ++, degOt[fr[i]] ++;
        rep( i, 1, N ) {
            cnt[i] = degOt[i];
            grphIn[i].reserve( degIn[i] );
            grphOt[i].reserve( degOt[i] );
        }
        rep( i, 1, M ) {
            grphOt[fr[i]].push_back( i );
            grphIn[to[i]].push_back( i );
            alv[i] = true;
        }
        all = M;
        rep( cas, 1, Q ) {
            int x = qX[cas], y = qY[cas];
            if( opt[cas] == 1 ) {
                int cur = edg[GetId( x, y )];
                if( ! alv[cur] ) continue;
                alv[cur] = false, all --, cnt[x] --;
            }
            if( opt[cas] == 2 ) {
                int n = grphIn[x].size(), cur;
                rep( i, 0, n - 1 ) {
                    cur = grphIn[x][i];
                    if( ! alv[cur] ) continue;
                    alv[cur] = false, all --, cnt[fr[cur]] --;
                }
            }
            if( opt[cas] == 3 ) {
                int cur = edg[GetId( x, y )];
                if( alv[cur] ) continue;
                alv[cur] = true, all ++, cnt[x] ++;
            }
            if( opt[cas] == 4 ) {
                int n = grphIn[x].size(), cur;
                rep( i, 0, n - 1 ) {
                    cur = grphIn[x][i];
                    if( alv[cur] ) continue;
                    alv[cur] = true, all ++, cnt[fr[cur]] ++;
                }
            }
            puts( Chk() ? "YES" : "NO" );
        }
    }
}

namespace Advanced {
    inline bool Chk() {
        rep( i, 1, Q )
            if( opt[i] == 4 )
                return false;
        return true;
    }

    int buc[MAXN];
    std :: vector<int> app[MAXN];

    inline void Destroy( const int &x ) {
        if( ! alv[x] ) return ;
        buc[cnt[fr[x]]] --;
        buc[-- cnt[fr[x]]] ++;
        alv[x] = false, all --;
    }

    inline void Rebuild( const int &x ) {
        if( alv[x] ) return ;
        buc[cnt[fr[x]]] --;
        buc[++ cnt[fr[x]]] ++;
        app[to[x]].push_back( x );
        alv[x] = true, all ++;
    }

    inline void Solve() {
        rep( i, 1, M ) cnt[to[i]] ++;
        rep( i, 1, N ) app[i].reserve( cnt[i] ), cnt[i] = 0;
        rep( i, 1, M ) app[to[i]].push_back( i ), cnt[fr[i]] ++, alv[i] = true;
        rep( i, 1, N ) buc[cnt[i]] ++;
        rep( cas, 1, Q ) {
            int x = qX[cas], y = qY[cas];
            if( opt[cas] == 1 )
                Destroy( edg[GetId( x, y )] );
            if( opt[cas] == 2 ) {
                int n = app[x].size();
                rep( i, 0, n - 1 )
                    Destroy( app[x][i] );
                app[x].clear();
            }
            if( opt[cas] == 3 )
                Rebuild( edg[GetId( x, y )] );
            puts( buc[1] == N ? "YES" : "NO" );
        }
    }
}

int main() {
    freopen( "galaxy.in", "r", stdin );
    freopen( "galaxy.out", "w", stdout );
    Read( N ), Read( M );
    rep( i, 1, M ) {
        Read( fr[i] ), Read( to[i] );
        edg[GetId( fr[i], to[i] )] = i;
    }
    Read( Q );
    rep( i, 1, Q ) {
        Read( opt[i] ), Read( qX[i] );
        if( opt[i] % 2 ) Read( qY[i] );
    }
    if( Advanced :: Chk() )
        return Advanced :: Solve(), 0;
    Force :: Solve();
    return 0;
}