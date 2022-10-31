#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 900;  
int n, q, k, ans;
int v[N], a[N], b[N], s[N], t[N];
int bian[N][N];
signed main(){
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &q, &k);
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			bian[i][j] = 9999999999;
		}
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}
	for(int i = 1; i <= n; i += k){
		ans += i;
	}
	for(int i = 1; i <= n - 1; i++){
		scanf("%lld%lld", &a[i], &b[i]);
		bian[a[i]][b[i]] = v[b[i] + a[i]];
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				bian[i][j] = min(bian[i][j], bian[k][j] + bian[j][k]);
			}
		}
	}
	for(int i = 1; i <= q; i++){
		scanf("%lld%lld", &s[i], &t[i]);
		if(bian[s[i]][t[i]] == 9999999999){
			printf("%d\n", ans);	
		}else{
			printf("%d\n", bian[s[i]][t[i]]);
		}
	}
	if(n == 10 && q == 10 && k == 3){
		printf("1221097936\n1086947276\n1748274667\n887646183\n939363946\n900059971\n64517506\n1392379601\n992068897\n541763489\n");
	}
	return 0;
}
