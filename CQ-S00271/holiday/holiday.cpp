#include <bits/stdc++.h>
#define int long long
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
const int N = 2.5e3+5 ;
const int M = 1e4+5 ;
__int128 n,m,k,ans ;
__int128 a[N],vis[N] ;
int dis[N][N] ;
vector<int>e[N] ;
vector<int>ds[N],oh[N] ;
inline void read(__int128 &x)
{
	x = 0 ; int f = 0 ; char cc = gc() ;
	while(!isdigit(cc)) f |= (cc=='-'),cc = gc() ;
	while(isdigit(cc)) x = (x<<1)+(x<<3)+(cc^48),cc = gc() ;
	x = f?-x:x ;
}
void print(__int128 x)
{
	if(x < 0) pc('-'),x = -x ;
	if(x > 9) print(x/10) ;
	pc(x%10+'0') ;
}
inline void DJ(int x)
{
	queue<int>q ;
	q.push(x),me(vis,0),me(dis[x],0x3f),dis[x][x] = 0 ;
	while(!q.empty())
	{
		int g = q.front() ; q.pop() ;
		vis[g] = 0 ;
		for(auto v:e[g])
			if(dis[x][v] > dis[x][g]+1)
			{
				dis[x][v] = dis[x][g]+1 ;
				if(!vis[v]) q.push(v),vis[v] = 1 ;
			}
	}
}
inline int cmp(int x,int y)
{
	return a[x] > a[y] ;
}
inline void Solve(int x,int y)
{
	int cnt1 = 0,cnt2 = 0 ;
	for(auto l:oh[x])
	{
		cnt2 = 0 ;
		if(l == y) continue ;
		for(auto r:oh[y])
		{
			if(r != x && r != l) ans = max(ans,a[l]+a[r]+a[x]+a[y]) ;
			++cnt2 ; if(cnt2 > 4) break ;
		}
		++cnt1 ; if(cnt1 > 4) break ;
	}
}
inline void Debug()
{
	FOR(i,2,n,1) FOR(j,2,n,1) FOR(l,2,n,1) FOR(r,2,n,1)
	{
		if(i != j && i != l && i != r && j != l && j != r && l != r)
		if(dis[i][j] <= k && dis[j][l] <= k && dis[l][r] <= k && dis[1][r] <= k && dis[1][i] <= k)
		{
			ans = max(ans,a[i]+a[j]+a[l]+a[r]) ;
			if(a[i]+a[j]+a[l]+a[r]==3908)
			{
				print(i),space,print(j),space,print(l),space,print(r),enter ;
				print(dis[1][i]),space,print(dis[i][j]),space,print(dis[j][l]),space,print(dis[l][r]),space,print(dis[r][1]),enter ;
			}
		}
			
	}
}
signed main()
{
	freopen("holiday.in","r",stdin) ;
	freopen("holiday.out","w",stdout) ;
	read(n),read(m),read(k),k++ ;
	FOR(i,2,n,1) read(a[i]) ;
	FOR(i,1,m,1)
	{
		__int128 u,v ; read(u),read(v) ;
		e[u].pb(v),e[v].pb(u) ;
	}
	FOR(i,1,n,1) DJ(i) ;	
	FOR(i,2,n,1) FOR(j,2,n,1) if(dis[i][j] <= k && dis[j][1] <= k && i != j)
		oh[i].pb(j) ;
	FOR(i,1,n,1) sort(oh[i].begin(),oh[i].end(),cmp) ;
	FOR(i,2,n,1) FOR(j,2,n,1)
	{
		if(dis[i][j] > k || i == j) continue ;
		Solve(i,j) ;
	}
	print(ans) ;
	return 0 ;
}

