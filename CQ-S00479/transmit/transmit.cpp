#include <cstdio>
#define INF 3e18
#define ll long long
using namespace std;
ll N , Q , K , u , v;
const ll MAXN = 2e5;
int a[MAXN + 1];
struct Edge{
	ll To , Next;
}e[MAXN + 1];
ll Head[MAXN + 1] , Cnt , Dep[MAXN + 1] , Pre[MAXN + 1] , s , t , dp[MAXN + 1];
ll t1[MAXN + 1] , t2[MAXN + 1] , cnt1 , cnt2; 
ll nums[MAXN + 1];
inline void AddEdge(ll u , int v){
	++Cnt;
	e[Cnt].To = v;
	e[Cnt].Next = Head[u];
	Head[u] = Cnt; 
}
void dfs(ll now ,ll la , ll dep){
	Dep[now] = dep;
	for(ll i = Head[now] ; i ; i = e[i].Next){
		if(e[i].To != la) {
			Pre[e[i].To] = now;
			dfs(e[i].To , now , dep + 1);
		}
	}
}
void Swap(ll &a , ll &b){
	a ^= b ^= a ^= b; 
} 
inline ll Max(ll a , ll b){
	return a > b ? a : b;
} 
inline ll Min(ll a , ll b){
	return a < b ? a : b;
}
int main(){
	freopen("transmit.in" , "r" , stdin);
	freopen("transmit.out" , "w" , stdout);
	scanf("%lld %lld %lld" , &N , &Q , &K);
	for(ll i = 1 ; i <= N ; i++){
		scanf("%lld" , &a[i]);
	}
	for(ll i = 1 ; i <= N - 1 ; i++){
		scanf("%lld %lld", &u , &v);
		AddEdge(u , v);
		AddEdge(v , u);
	}
	dfs(1 , -1 , 0);
	Pre[1] = 1;
	while(Q--){
		scanf("%lld %lld" , &s , &t);
		if(Dep[s] < Dep[t])
			Swap(s , t);
		cnt1 = cnt2 = 0;
		while(Dep[s] != Dep[t]){
		//	printf("(%d %d)[%d %d]\n" , s , t , Dep[s] , Pre[t]);			
			t1[++cnt1] = a[s];
			s = Pre[s];
		}
		while(s != t){
			t1[++cnt1] = a[s] , t2[++cnt2] = a[t];
			s = Pre[s] , t = Pre[t];
		}t1[++cnt1] = a[s];
		ll cnt = cnt1 + cnt2;
		for(ll i = 1 ; i <= cnt1 ; i++){
			nums[i] = t1[i];
		}
		for(ll j = 1 ; j <= cnt2 ; j++){
			nums[j + cnt1] = t2[cnt2 - j + 1];
		}
		for(ll i = 1 ; i <= cnt ; i++){
			dp[i] = INF;
		}
		for(ll i = 1 ; i <= K ; i++){
			dp[i] = nums[i];
		} 
		dp[1] = 0;
		for(ll i = K + 1 ; i <= cnt ; i++){
			for(ll j = i - K ; j < i ; j++){
				dp[i] = Min(dp[i] , dp[j] + nums[i]);
			}
		}
		dp[cnt] -= nums[cnt];
		ll ans = INF;
		for(ll i = cnt ; i > cnt - K ; i--){
			ans = Min(ans , dp[i]);
		}printf("%lld\n" , ans + nums[1] + nums[cnt]);
	}
} 
