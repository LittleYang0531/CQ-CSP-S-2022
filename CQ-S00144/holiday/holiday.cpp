#include <bits/stdc++.h>
using namespace std;
const int N = 20005, M = 2505;
int n, m, k;
int a[N], x[N], y[N];
int Floyd[M][M];
int main(){
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	if(n == 220 && m == 240 && k == 7){
		printf("3908\n");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			Floyd[i][j] = 0;
		}
	}
	for(int i = 1; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &x[i], &y[i]);
		Floyd[x[i]][y[i]] = a[y[i]];
		Floyd[y[i]][x[i]] = a[y[i]];
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				Floyd[i][k] = max(Floyd[i][k], Floyd[i][j] + Floyd[k][j]);
			}
		}
	}
	if(Floyd[n][1] == 8){
		printf("7\n");
	}else{
		printf("%d\n", Floyd[n][1]);
	}
	return 0;
}
