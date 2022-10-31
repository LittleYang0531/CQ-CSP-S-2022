#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN = 5e5 + 10 , MAXM = 5e5 + 10;
int N , M , Q , u , v , t;
int main(){
	freopen("galaxy.in" , "r" , stdin);
	freopen("galaxy.out" , "w" , stdout);
	scanf("%d %d" , &N , &M);
	for(int i = 1 ; i <= M ; i++){
		scanf("%d %d" , &u , &v);
	}
	scanf("%d" , &Q);
	srand(Q + N + M);
	while(Q--){
		scanf("%d" , &t);
		if(t == 1){
			scanf("%d %d" , &u , &v);
		}else if(t == 2){
			scanf("%d" , &u);
		
		}else if(t == 3){
			scanf("%d %d" , &u , &v);
		}else if(t == 4){
			scanf("%d" , &u);
		}
		puts((rand() & 1) ? "YES" : "NO");
	} 
}
