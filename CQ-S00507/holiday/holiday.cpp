#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 2510;

int n, m, q, x, y, a[N], z[N][N], ans;

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	scanf("%d%d%d", &n, &m, &q);
	
	q += 2;
	
	for(int i = 2; i <= n; i ++ ){
		scanf("%d", &a[i]);
	}
	
	for(int i = 1; i <= m; i ++ ){
		scanf("%d%d", &x, &y);
		z[x][y] = 2;
		z[y][x] = 2;
	}
	
	for(int k = 1; k <= n; k ++ ){
		for(int i = 1; i <= n; i ++ ){
			for(int j = 1; j <= n; j ++ ){
				if(z[i][k] && z[k][j]) z[i][j] = min(z[i][k] + z[k][j] - 1, z[i][j]);
			}
		}
	}
	
	for(int i = 2; i <= n; i ++ ){
		for(int j = 2; j <= n; j ++ ){
			if(z[i][j] <= q && z[i][j] && i != j){
				for(int k = 2; k <= n; k ++ ){
					if(z[j][k] <= q && z[j][k] && i != k && k != j){
						for(int l = 2; l <= n; l ++ ){
							if(z[l][1] <= q && z[l][1] && z[k][l] <= q && z[k][l] && k != l && i != l && l != j) ans = max(ans, a[i] + a[j] + a[k] + a[l]);
						}
					}
				}
			}
		}
	}
	
	printf("%d", ans);

	return 0;
}


