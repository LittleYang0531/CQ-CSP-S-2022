#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std; 
const int MAXN = 2505;
int n, m, k;
vector<int> v[MAXN];
long long a[MAXN], ans = 4;
pair<long long, int> h[4][MAXN];
int d[MAXN][MAXN];
queue<int> q;
void sllr(int s) {
	while (!q.empty()) {
		q.pop();
	}
	q.push(s);
	d[s][s] = -1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int siz = v[x].size();
		for (int i = 0; i < siz; i++) {
			int y = v[x][i];
			if (d[s][y] == 0x3f3f3f3f) {
				d[s][y] = d[s][x] + 1;
				q.push(y);
			}
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
//	memset(dp, 0x3f, sizeof(dp));
	memset(d, 0x3f, sizeof(d));
//	printf("%lld\n", dp[0][0] + dp[1][1]);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i < n; i++) {
		scanf("%lld", &a[i + 1]);
	}
	for (int i = 1, uu, vv; i <= m; i++) {
		scanf("%d %d", &uu, &vv);
		v[uu].push_back(vv);
		v[vv].push_back(uu);
	}
	for (int i = 1; i <= n; i++) {
		sllr(i);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == j) continue;
			if (d[1][i] > k || d[i][j] > k) continue;
			long long tmp = a[i] + a[j];
//			printf("AAA %d %d\n", i, j);
			if (tmp > h[1][j].first) {
				h[3][j] = h[2][j];
				h[2][j] = h[1][j];
				h[1][j].first = tmp;
				h[1][j].second = i;
			}
			else if (tmp > h[2][j].first) {
				h[3][j] = h[2][j];
				h[2][j].first = tmp;
				h[2][j].second = i;
			}
			else if (tmp > h[3][j].first) {
				h[3][j].first = tmp;
				h[3][j].second = i;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == j) continue;
			if (d[i][j] > k) continue;
			for (int k = 1; k <= 9; k++) {
				int x = k % 3, y = k / 3;
				if (x == 0) x = 3;
				if (h[x][i].second != h[y][j].second && h[x][i].second != j && h[y][j].second != i) {
					ans = max(ans, h[x][i].first + h[y][j].first);
//					printf("BBB %d %d %d %d : %d\n", i, h[x][i].second, h[x][j].second, j, h[x][i].first + h[y][j].first);
				}
			}
//			if (h[1][i].second != h[1][j].second && h[1][i].second != j && h[1][j].second != i) {
//				ans = max(ans, h[1][i].first + h[1][j].first);
//			}
//			if (h[1][i].second != h[2][j].second && h[1][i].second != j && h[1][j].second != i) {
//				ans = max(ans, h[1][i].first + h[2][j].first);
//			}
//			if (h[2][i].second != h[1][j].second) {
//				ans = max(ans, h[2][i].first + h[1][j].first);
//			}
//			if (h[2][i].second != h[2][j].second) {
//				ans = max(ans, h[2][i].first + h[2][j].first);
//			}
		}
	}
	printf("%lld", ans);
//	4557430888798830399
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
////			printf("dis %d %d is %d\n", i, j, d[i][j]);
//			if (d[i][j] != d[j][i]) printf("????????\n");
//		}
//	}
	return 0;
}
