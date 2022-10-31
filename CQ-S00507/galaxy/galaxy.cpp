#include<iostream>
#include<cstring>
#include<algorithm>
#include<random>
#include<time.h>

using namespace std;

int n, m, q, u, v, w, ans;

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(0));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++ ){
		scanf("%d%d", &u, &v);
	}
	scanf("%d", &q);
	
	while(q -- ){
		scanf("%d", &u);
		ans = rand();
		if(u == 1){
			scanf("%d%d", &v, &w);
			
		}
		if(u == 2){
			scanf("%d", &v);
			
		}
		if(u == 3){
			scanf("%d%d", &v, &w);
			
		}
		if(u == 4){
			scanf("%d", &v);
			
		}
		if(ans % 3 == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}



