#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
int n, m, q, l1, r1, l2, r2, lg[N], sum[N];
LL a[N], b[N], fa[N][20][2][2], fb[N][20][2];
inline LL geta(int l, int r, int x, int y){
	int s = lg[r - l + 1];
	if (!y) return min(fa[l][s][x][y], fa[r - (1 << s) + 1][s][x][y]);
	else return max(fa[l][s][x][y], fa[r - (1 << s) + 1][s][x][y]);
}
inline LL getb(int l, int r, int p){
	int s = lg[r - l + 1];
	if (!p) return min(fb[l][s][p], fb[r - (1 << s) + 1][s][p]);
	else return max(fb[l][s][p], fb[r - (1 << s) + 1][s][p]);
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	lg[0] = -1;
	for (int i = 1; i <= max(n, m); i++) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1];
		fa[i][0][0][0] = fa[i][0][1][0] = INT_MAX;
		fa[i][0][0][1] = fa[i][0][1][1] = INT_MIN;
		if (a[i] == 0) sum[i]++;
		if (a[i] > 0) fa[i][0][0][0] = fa[i][0][0][1] = a[i];
		if (a[i] < 0) fa[i][0][1][0] = fa[i][0][1][1] = a[i];
	}
	for (int i = 1; i <= m; i++){
		scanf("%lld", &b[i]);
		fb[i][0][0] = fb[i][0][1] = b[i];
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++){
			fa[i][j][0][0] = min(fa[i][j - 1][0][0], fa[i + (1 << (j - 1))][j - 1][0][0]);
			fa[i][j][1][0] = min(fa[i][j - 1][1][0], fa[i + (1 << (j - 1))][j - 1][1][0]);
			fa[i][j][0][1] = max(fa[i][j - 1][0][1], fa[i + (1 << (j - 1))][j - 1][0][1]);
			fa[i][j][1][1] = max(fa[i][j - 1][1][1], fa[i + (1 << (j - 1))][j - 1][1][1]);
		}
	for (int j = 1; j <= lg[m]; j++)
		for (int i = 1; i + (1 << j) - 1 <= m; i++){
			fb[i][j][0] = min(fb[i][j - 1][0], fb[i + (1 << (j - 1))][j - 1][0]);
			fb[i][j][1] = max(fb[i][j - 1][1], fb[i + (1 << (j - 1))][j - 1][1]);
		}
	while(q--){
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		LL ans = (sum[r1] - sum[l1 - 1] > 0)? 0 : LLONG_MIN;
		LL A1 = geta(l1, r1, 0, 0), A2 = geta(l1, r1, 0, 1);
		LL A3 = geta(l1, r1, 1, 0), A4 = geta(l1, r1, 1, 1);
		LL B1 = getb(l2, r2, 0), B2 = getb(l2, r2, 1);
		if (A1 != INT_MAX) ans = max(ans, A1 * B1);
		if (A2 != INT_MIN) ans = max(ans, A2 * B1);
		if (A3 != INT_MAX) ans = max(ans, A3 * B2);
		if (A4 != INT_MIN) ans = max(ans, A4 * B2);
		printf("%lld\n", ans);
	}
	return 0;
}
