#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 3e18
#define Make make_pair
#define ll long long
using namespace std;
inline ll Max(ll a , ll b){
	return a > b ? a : b;
}
inline ll Min(ll a , ll b){
	return a < b ? a : b;
}
const int MAXN = 1e5 + 5 , MAXUP = 18;
int N , M , Que , l1 , r1 , l2 , r2;
ll a[MAXN] , b[MAXN];
ll rmqval[3][3][MAXN][MAXUP] , rmqlow[3][3][MAXN][MAXUP] , Log2[MAXN];
inline void Get(int N , ll rmq[MAXN][MAXUP] , int type){
	for(int j = 1 ; (1 << j) <= N ; j++){
		for(int i = 1 ; i + (1 << j - 1) <= N ; i++){
			if(type == 1)
				rmq[i][j] = Max(rmq[i][j - 1] , rmq[i + (1 << j - 1)][j - 1]);
			else
				rmq[i][j] = Min(rmq[i][j - 1] , rmq[i + (1 << j - 1)][j - 1]);
		}
	}
} 
inline ll ask(int l , int r , ll rmq[MAXN][MAXUP] , int type){
	int k = Log2[r - l + 1];
	if(type == 1)
		return Max(rmq[l][k] , rmq[r - (1 << k) + 1][k]);
	else
		return Min(rmq[l][k] , rmq[r - (1 << k) + 1][k]);	
}
int main(){
	freopen("game.in" , "r" , stdin);
	freopen("game.out" , "w" , stdout);
	scanf("%lld %lld %lld" , &N , &M , &Que);
	for(int i = 1 ; i <= N ; i++)
		scanf("%lld" , &a[i]);
	for(int j = 1 ; j <= M ; j++)
		scanf("%lld" , &b[j]);
	for(int i = 2 ; i <= Max(N , M) ; i++)
		Log2[i] = Log2[i / 2] + 1;
	for(int i = 1 ; i <= N ; i++){
		rmqval[1][1][i][0] = rmqval[1][2][i][0] = a[i];
		if(a[i] <= 0)
			rmqlow[1][1][i][0] = a[i] , rmqlow[1][2][i][0] = INF;
		if(a[i] >= 0)
			rmqlow[1][2][i][0] = a[i] , rmqlow[1][1][i][0] = -INF;
	}
	for(int i = 1 ; i <= M ; i++){
		rmqval[2][1][i][0] = rmqval[2][2][i][0] = b[i];
		if(b[i] <= 0)
			rmqlow[2][1][i][0] = b[i] , rmqlow[2][2][i][0] = INF;
		if(b[i] >= 0)
			rmqlow[2][2][i][0] = b[i] , rmqlow[2][1][i][0] = -INF;
	}
	Get(N , rmqval[1][1] , 1) , Get(N , rmqval[1][2] , 2);
	Get(M , rmqval[2][1] , 1) , Get(M , rmqval[2][2] , 2); 
	Get(N , rmqlow[1][1] , 1) , Get(N , rmqlow[1][2] , 2);
	Get(M , rmqlow[2][1] , 1) , Get(M , rmqlow[2][2] , 2);

	while(Que--){
		scanf("%lld %lld %lld %lld" , &l1 , &r1 , &l2 , &r2);
		ll mi1 = ask(l1 , r1 , rmqval[1][2] , 2) , ma1 = ask(l1 , r1 , rmqval[1][1] , 1);
		ll mi2 = ask(l2 , r2 , rmqval[2][2] , 2) , ma2 = ask(l2 , r2 , rmqval[2][1] , 1);
		if(ma2 <= 0){
			if(mi1 <= 0){
				printf("%lld\n" , mi1 * ma2);
			}else{
				printf("%lld\n" , mi1 * mi2);
			}
		}else if(mi2 >= 0){
			if(ma1 >= 0){
				printf("%lld\n" , ma1 * mi2);
			}else{
				printf("%lld\n" , ma1 * ma2);
			}
		} else{
			if(mi1 >= 0){
				printf("%lld\n" , mi1 * mi2);
			}else if(ma1 <= 0){
				printf("%lld\n" , ma1 * ma2);
			}else{
				ll t1 = ask(l1 , r1 , rmqlow[1][1] , 1) , t2 = ask(l1 , r1 , rmqlow[1][2] , 2);
				printf("%lld\n" , Max(t1 * ma2 , t2 * mi2));
			}
		}
	//	puts("IOI");
	}
	return 0;
} 

