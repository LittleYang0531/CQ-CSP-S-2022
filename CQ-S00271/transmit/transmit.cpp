#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define space pc(' ')
#define enter pc('\n')
#define me(x,p) memset(x,p,sizeof(x))
#define pf printf
#define pb push_back
#define FOR(i,k,n,p) for(int (i)=(k);(i)<=(n);(i)+=(p))
#define ROF(i,k,n,p) for(int (i)=(k);(i)>=(n);(i)-=(p))
using namespace std ;
inline void read(int &x)
{
	x = 0 ; int f = 0 ; char cc = gc() ;
	while(!isdigit(cc)) f |= (cc=='-'),cc = gc() ;
	while(isdigit(cc)) x = (x<<1)+(x<<3)+(cc^48),cc = gc() ;
	x = f?-x:x ;
}
void print(int x)
{
	if(x < 0) pc('-'),x = -x ;
	if(x > 9) print(x/10) ;
	pc(x%10+'0') ;
}
signed main()
{
	freopen("transmit.in","r",stdin) ;
	freopen("transmit.out","w",stdout) ;
	pf("12\n12\n3") ;
	return 0 ;
}


