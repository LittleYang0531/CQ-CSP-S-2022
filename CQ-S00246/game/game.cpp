#include <bits/stdc++.h>
using namespace std;
int n, m, q, a[100005], b[100005], l1, r1, l2, r2;
long long maxn, minn, c[5500][5500], tp;
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for(register int i=1;i<=n;++i) scanf("%d", &a[i]);
	for(register int i=1;i<=m;++i) scanf("%d", &b[i]);
	for(register int t=1;t<=q;++t){
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		maxn = -1145141919810114514;
		minn = 1145141919810114514;
		for(register int i=l1;i<=r1;++i){
			for(register int j=l2;j<=r2;++j){
				if(i <= 5500 && j <= 5500){
					if(!c[i][j]) c[i][j] = a[i]*b[j];
					maxn = max(c[i][j], maxn);
					minn = min(c[i][j], minn);
				}else{
					tp = a[i]*b[j];
					maxn = max(tp, maxn);
					minn = min(tp, minn);
				}
			}
		}
		printf("%lld\n", maxn);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
