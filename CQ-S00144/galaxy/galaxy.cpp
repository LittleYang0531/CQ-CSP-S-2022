#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, m, q;
int tu[N][N];
int main(){
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		tu[u][v]++;
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		int t, u, v;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d", &u, &v);
			tu[u][v]--;
		}else if(t == 2){
			scanf("%d", &u);
			for(int j = 1; j <= n; j++){
				if(tu[u][i] != 0){
					tu[u][i]--;
				}
			}
		}else if(t == 3){
			scanf("%d%d", &u, &v);
			tu[u][v]++;
		}else if(t == 4){
			scanf("%d", &u);
			for(int j = 1; j <= n; j++){
				if(tu[u][i] != 1){
					tu[u][i]++;
				}
			}
		}
		if(tu[u][v] == 1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
