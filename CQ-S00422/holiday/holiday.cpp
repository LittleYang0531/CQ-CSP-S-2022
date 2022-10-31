// Never Gonna Give¡ü You¡ü Up¡ý 
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
namespace yj{
const int MAXN = 2505;
const int MAXM = 10005;
bool mt[MAXN][MAXN]; int res[MAXN], res2[MAXN], res3[MAXN];
struct edge {
	int to, nxt;
} edges[MAXM << 1];
int head[MAXN]; int tot;
void add(int u, int v) {
	edges[++tot].to = v; edges[tot].nxt = head[u]; head[u] = tot;
}
int dep[MAXN];int n, m, k;
void bfs(int s) {
	for (int i = 1; i <= n; i++) dep[i] = 0x7f7f7f7f;
	queue<int> q; q.push(s); dep[s] = 0;
	while (q.empty() == 0) {
		int u = q.front();q.pop();
		for (int i = head[u]; i; i = edges[i].nxt) {
//			printf("%d upd %d\n", u, edges[i].to);
			if (dep[edges[i].to] == 0x7f7f7f7f) dep[edges[i].to] = dep[u] + 1, q.push(edges[i].to);
		}
	}
}
long long val[MAXN];
int read() {
	char ch; while ((ch = getchar()) < '0');
	int x = ch - '0'; while ((ch = getchar()) >= '0') x = x * 10 + ch - '0';
	return x;
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = read(); m = read(); k = read(); k++; k = min(k, n - 1);
	for (int i = 2; i <= n; i++) val[i] = read();
	for (int i = 1; i <= m; i++) {
		int u, v; u = read(); v = read(); add(u, v); add(v, u);
	}
	for (int i = 1; i <= n; i++) {
		bfs(i); for (int j = 1; j <= n; j++) {
			mt[i][j] = dep[j] <= k;
		}
		if (i > 1) {
			for (int j = 2; j <= n; j++) {
				if (i == j) continue;
				if (dep[j] <= k && mt[1][j]) {
//					printf("ch %d %d\n", i, j);
					if (res[i] == 0 || val[res[i]] <= val[j]) {
						res3[i] = res2[i]; res2[i] = res[i]; res[i] = j;
					}
					else if (res2[i] == 0 || val[res2[i]] <= val[j]) {
						res3[i] = res2[i]; res2[i] = j;
					}
					else if (res3[i] == 0 || val[res3[i]] <= val[j]) {
						res3[i] = j;
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == j) continue;
			if (mt[i][j]) {
//				printf("%d %d (%d %d %d %d %d %d)\n", i, j, res[i], res2[i], res3[i], res[j], res2[j], res3[j]);
				// i -> 1st
				if (res[i] != 0 && res[i] != j) {
					if (res[j] != 0 && (res[j] != res[i] && res[j] != i)) {
						ans = max(ans, val[res[i]] + val[res[j]] + val[i] + val[j]);
//						printf("11 %d %d %d %d - %lld\n", i, j, res[i], res[j], ans);
					}
					else if (res2[j] != 0 && (res2[j] != res[i] && res2[j] != i)) {
						ans = max(ans, val[res[i]] + val[res2[j]] + val[i] + val[j]);
//						printf("12 %d %d %d %d - %lld\n", i, j, res[i], res2[j], ans);
					}
					else if (res3[j] != 0) {
						ans = max(ans, val[res[i]] + val[res3[j]] + val[i] + val[j]);
//						printf("13 %d %d %d %d - %lld\n", i, j, res[i], res3[j], ans);
					}
				}
				
				if (res2[i] != 0 && res2[i] != j) {
					if (res[j] != 0 && (res[j] != res2[i] && res[j] != i)) {
						ans = max(ans, val[res2[i]] + val[res[j]] + val[i] + val[j]);
//						printf("21 %d %d %d %d - %lld\n", i, j, res2[i], res[j], ans);
					}
					else if (res2[j] != 0 && (res2[j] != res2[i] && res2[j] != i)) {
						ans = max(ans, val[res2[i]] + val[res2[j]] + val[i] + val[j]);
//						printf("22 %d %d %d %d - %lld\n", i, j, res2[i], res2[j], ans);
					}
					else if (res3[j] != 0) {
						ans = max(ans, val[res2[i]] + val[res3[j]] + val[i] + val[j]);
//						printf("23 %d %d %d %d - %lld\n", i, j, res2[i], res3[j], ans);
					}
				}
				
				if (res3[i] != 0 && res3[i] != j) {
					if (res[j] != 0 && (res[j] != res3[i] && res[j] != i)) {
						ans = max(ans, val[res3[i]] + val[res[j]] + val[i] + val[j]);
//						printf("31 %d %d %d %d - %lld\n", i, j, res3[i], res[j], ans);
					}
					else if (res2[j] != 0 && (res2[j] != res3[i] && res2[j] != i)) {
						ans = max(ans, val[res3[i]] + val[res2[j]] + val[i] + val[j]);
//						printf("32 %d %d %d %d - %lld\n", i, j, res3[i], res2[j], ans);
					}
					else if (res3[j] != 0) {
						ans = max(ans, val[res3[i]] + val[res3[j]] + val[i] + val[j]);
//						printf("33 %d %d %d %d - %lld\n", i, j, res3[i], res3[j], ans);
					}
				}
			}
		}
	}
	printf("%lld\n", ans); return 0;
}
}
int main() {return yj::main();} // mem 7852
