#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long n, m, q;
long long a[N], b[N], c[N][N];
long long Max[N], Min[N], maxn = -99999999999999;
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w" ,stdout);
	scanf("%lld%lld%lld", &n, &m, &q);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= m; i++){
		scanf("%lld", &b[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			c[i][j] = a[i] * b[j];
		}
	}
	for(int i = 1; i <= n; i++){
		Min[i] = 0x3f3f3f3f;
		Max[i] = 0;
	}
	for(int i = 1; i <= q; i++){
		int l1, r1, l2, r2, id1;
		maxn = -999999999999999;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		memset(Max, 0, sizeof(Max));
		memset(Min, 0x3f3f3f3f, sizeof(Min));
		for(int j = l1; j <= r1; j++){
			for(int k = l2; k <= r2; k++){
				Max[j] = max(Max[j], c[j][k]);
				Min[j] = min(Min[j], c[j][k]);
			}
		}
		for(int j = l1; j <= r1; j++){
			if(Min[j] >= maxn){
				id1 = j;
				maxn = Min[j];
			}
		}
		printf("%lld\n", Min[id1]);
	}
	return 0;
}
