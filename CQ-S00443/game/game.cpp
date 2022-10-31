#include<bits/stdc++.h>
#define LL long long
#define mes(s, x) memset(s, x, sizeof(s))
#define MAXN 100005
using namespace std;
int a[2][2][2][20][MAXN];//大小、正负、ab //是否含有正/负数 
int f(int z, int d, int j, int l, int r){
	int t = log2(r - l + 1);
	if(z == 0) return max(a[z][d][j][t][l], a[z][d][j][t][r - (1 << t) + 1]);
	else return min(a[z][d][j][t][l], a[z][d][j][t][r - (1 << t) + 1]);
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, q, x, y, l1, r1, l2, r2;
	scanf("%d %d %d", &n, &m, &q);
	LL ans;
	mes(a[0], 128);
	mes(a[1], 0x3f);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		if(x >= 0) a[0][0][0][0][i] = a[1][0][0][0][i] = x;
		if(x <= 0) a[0][1][0][0][i] = a[1][1][0][0][i] = x;
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", &x);
		if(x >= 0) a[0][0][1][0][i] = a[1][0][1][0][i] = x;
		if(x <= 0) a[0][1][1][0][i] = a[1][1][1][0][i] = x;
	}
	for(int i = 1; 1 << i <= n; i++){
		for(int j = 1; j + (1 << i) - 1 <= n; j++){
			a[0][0][0][i][j] = max(a[0][0][0][i - 1][j], a[0][0][0][i - 1][j + (1 << i - 1)]);
			a[0][1][0][i][j] = max(a[0][1][0][i - 1][j], a[0][1][0][i - 1][j + (1 << i - 1)]);
			a[1][0][0][i][j] = min(a[1][0][0][i - 1][j], a[1][0][0][i - 1][j + (1 << i - 1)]);
			a[1][1][0][i][j] = min(a[1][1][0][i - 1][j], a[1][1][0][i - 1][j + (1 << i - 1)]);
		}
	}
	for(int i = 1; 1 << i <= m; i++){
		for(int j = 1; j + (1 << i) - 1 <= m; j++){
			a[0][0][1][i][j] = max(a[0][0][1][i - 1][j], a[0][0][1][i - 1][j + (1 << i - 1)]);
			a[0][1][1][i][j] = max(a[0][1][1][i - 1][j], a[0][1][1][i - 1][j + (1 << i - 1)]);
			a[1][0][1][i][j] = min(a[1][0][1][i - 1][j], a[1][0][1][i - 1][j + (1 << i - 1)]);
			a[1][1][1][i][j] = min(a[1][1][1][i - 1][j], a[1][1][1][i - 1][j + (1 << i - 1)]);
		}
	}
	for(int i = 1; i <= q; i++){
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		if(f(1, 1, 1, l2, r2) > 0){//b只有正数 
			if(f(0, 0, 0, l1, r1) > 0) printf("%lld\n", f(0, 0, 0, l1, r1) * 1ll * f(1, 0, 1, l2, r2));//a有正数 
			else printf("%lld\n", f(0, 1, 0, l1, r1) * 1ll * f(0, 0, 1, l2, r2));//a没有正数 
		}else if(f(0, 0, 1, l2, r2) < 0){//b只有负数 
			if(f(1, 1, 0, l1, r1) < 0) printf("%lld\n", f(1, 1, 0, l1, r1) * 1ll * f(0, 1, 1, l2, r2));//a有负数 
			else printf("%lld\n", f(1, 0, 0, l1, r1) * 1ll * f(1, 1, 1, l2, r2));//a没有负数 
		}else{//b有正有负 
			ans = -1e18-114514;
			if(f(0, 0, 0, l1, r1) > 0) ans = max(ans, f(1, 0, 0, l1, r1) * 1ll * f(1, 1, 1, l2, r2));//a选正数 
			if(f(0, 1, 0, l1, r1) < 0) ans = max(ans, f(0, 1, 0, l1, r1) * 1ll * f(0, 0, 1, l2, r2));//a选负数 
			printf("%lld\n", ans);
		}
	}
	return 0;
}
