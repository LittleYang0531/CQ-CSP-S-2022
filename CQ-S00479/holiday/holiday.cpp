#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <bitset> 
#define INF 0x3f3f3f3f
#define ll long long
#define Make make_pair
using namespace std;
inline ll Max(ll a , ll b){
	return a > b ? a : b;
}
inline ll Min(ll a , ll b){
	return a < b ? a : b;
}
const int MAXN = 2505 , MAXM = 10005;
ll val[MAXN] ;
int Head[MAXM * 2] , Cnt;
int vis[MAXN][MAXN];
struct Edge{
	ll To , Next; 
}e[MAXM * 2];
inline void AddEdge(ll u , ll v){
	++Cnt;
	e[Cnt].To = v;
	e[Cnt].Next = Head[u];
	Head[u] = Cnt;
}
ll N , M , K , u , v;
void dfs(int now , int still , int la ,  int vis[]){
	if(still == 0)
		return ;
	vis[now] = 1;
	for(ll i = Head[now] ; i ; i = e[i].Next){
		if(e[i].To != la && !vis[e[i].To]){
			dfs(e[i].To , still - 1 , now , vis);
		}
	} 
}
ll dp[MAXN][10];
bitset <MAXN> b[MAXN][10];
int main(){
	freopen("holiday.in" , "r" , stdin) ;
	freopen("holiday.out" , "w" , stdout) ;
	scanf("%lld %lld %lld" , &N , &M , &K);
	K += 2;
	for(int i = 2 ; i <= N ; i++)
		scanf("%lld" , &val[i]);
	for(int i = 1 ; i <= M ; i++){
		scanf("%lld %lld" , &u , &v);
		AddEdge(u , v);
		AddEdge(v , u);
	}
	for(int i = 1 ; i <= N ; i++){
		dfs(i , K , -1 , vis[i]);
	}
	memset(dp , -1 , sizeof(dp));
	dp[1][0] = 0;
	b[1][0][1] = 1;
	for(int k = 1 ; k <= 4 ; k++){
		for(int i = 1 ; i <= N ; i++){
			for(int j = 1 ; j <= N ; j++){
				if(i == j)
					continue;
				if(b[j][k - 1][i] == 0 && vis[i][j] == 1 && dp[j][k - 1] != -1 && dp[j][k - 1] + val[i] > dp[i][k]){
					dp[i][k] = dp[j][k - 1] + val[i];
					b[i][k] = b[j][k - 1];
					b[i][k][i] = 1;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1 ; i <= N ; i++){
		if(vis[1][i])
			ans = Max(ans , dp[i][4]);
	}
	printf("%lld" , ans);
	return 0;
} 
