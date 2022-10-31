#include <iostream>
#include <cstdio>
#include <vector>
const int nn = 2505;
std::vector<int> adj[nn];
int dis[nn][nn], n, m, k, v[nn];
long long f[nn][nn];
int que[nn], head, tail;
void bfs(int x) {
	for (int i = 1; i <= n; i++) dis[x][i] = nn;
	dis[x][que[head = tail = 1] = x] = 0;
	while (head <= tail) {
		int p = que[head++];
		for (int q : adj[p]) {
			if (dis[x][q] > dis[x][p] + 1) {
				dis[x][q] = dis[x][p] + 1;
				que[++tail] = q;
			}
		}
	}
}
int pp[nn], qq[nn];
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k); k++;
	for (int i = 2; i <= n; i++) scanf("%d", v + i);
	for (int i = 1, p, q; i <= m; i++) {
		scanf("%d %d", &p, &q);
		adj[p].push_back(q);
		adj[q].push_back(p);
		pp[i] = p; qq[i] = q;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = -1e18;
	for (int i = 1; i <= n; i++) bfs(i);
	for (int p = 2; p <= n; p++) {
		for (int q = p + 1; q <= n; q++) {
			if (dis[1][p] <= k && dis[p][q] <= k)
				f[q][p] = v[p] + v[q];
			if (dis[1][q] <= k && dis[q][p] <= k)
				f[p][q] = v[q] + v[p];
		}
	}
	long long ans = 0;
	if (k == 1) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= i; j++) {
				if (i == j) continue;
				int p1 = pp[i], q1 = qq[i];
				int p2 = pp[j], q2 = qq[j];
				if (p1 == p2 || p1 == q2 || q1 == p2 || q1 == q2) continue;
				if (p1 == 1 || q1 == 1 || p2 == 1 || q2 == 1) continue;
				if (dis[1][q1] <= k && dis[p1][p2] <= k && dis[1][q2] <= k) {
					ans = std::max(ans, f[p1][q1] + f[p2][q2]);
//					printf("%d %d %d %d %lld\n", p1, q1, p2, q2, f[p1][q1] + f[p2][q2]);
				}
				std::swap(p1, q1);
				if (dis[1][q1] <= k && dis[p1][p2] <= k && dis[1][q2] <= k) {
					ans = std::max(ans, f[p1][q1] + f[p2][q2]);
//					printf("%d %d %d %d %lld\n", p1, q1, p2, q2, f[p1][q1] + f[p2][q2]);
				}
				std::swap(p2, q2);
				if (dis[1][q1] <= k && dis[p1][p2] <= k && dis[1][q2] <= k) {
					ans = std::max(ans, f[p1][q1] + f[p2][q2]);
//					printf("%d %d %d %d %lld\n", p1, q1, p2, q2, f[p1][q1] + f[p2][q2]);
				}
				std::swap(p1, q1);
				if (dis[1][q1] <= k && dis[p1][p2] <= k && dis[1][q2] <= k) {
					ans = std::max(ans, f[p1][q1] + f[p2][q2]);
//					printf("%d %d %d %d %lld\n", p1, q1, p2, q2, f[p1][q1] + f[p2][q2]);
				}
			}
		}
	} else {
		for (int p1 = 2; p1 <= n; p1++) {
			for (int q1 = 2; q1 <= n; q1++) {
				if (p1 == q1 || f[p1][q1] < 0) continue;
				for (int p2 = 2; p2 <= n; p2++) {
					if (p1 == p2 || q1 == p2) continue;
					for (int q2 = 2; q2 <= n; q2++) {
						if (p1 == q2 || q1 == q2 || p2 == q2) continue;
						if (dis[p1][p2] > k) continue;
						ans = std::max(ans, f[p1][q1] + f[p2][q2]);
//						if (f[p1][q1] + f[p2][q2] > 0) printf("%d %d %d %d %lld\n", p1, q1, p2, q2, f[p1][q1] + f[p2][q2]);
					}
				}
			}
//			if (p1 % 10 == 0) fprintf(stderr, "%d\n", p1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
