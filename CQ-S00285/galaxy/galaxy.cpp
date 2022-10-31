#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
const int nn = 5e5 + 5;
std::vector<int> adj[nn];
int n, m, t, deg[nn], now[nn], sum = 0;
std::map<int, int> tmp[nn];
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1, p, q; i <= m; i++) {
		scanf("%d %d", &p, &q);
		adj[q].push_back(p);
		deg[p]++;
	}
	for (int i = 1; i <= n; i++) {
		sum += deg[i] == 1;
		now[i] = 1;
	}
	scanf("%d", &t);
	while (t--) {
		int op, p, q;
		scanf("%d %d", &op, &p);
		if (op == 1) {
			scanf("%d", &q);
			sum -= deg[p] == 1;
			if (tmp[q].find(p) == tmp[q].end())
				deg[p] -= now[q];
			else deg[p] -= tmp[q][p];
			tmp[q][p] = 0;
			sum += deg[p] == 1;
		}
		if (op == 3) {
			scanf("%d", &q);
			sum -= deg[p] == 1;
			if (tmp[q].find(p) == tmp[q].end())
				deg[p] -= now[q];
			else deg[p] -= tmp[q][p];
			tmp[q][p] = 1;
			deg[p]++;
			sum += deg[p] == 1;
		}
		if (op == 2) {
			for (auto it : tmp[p]) {
				sum -= deg[it.first] == 1;
				deg[it.first] -= it.second;
				deg[it.first] += now[p];
				sum += deg[it.first] == 1;
			}
			tmp[p].clear();
			if (now[p] != 0) 
				for (int q : adj[p]) {
					sum -= deg[q] == 1;
					deg[q]--;
					sum += deg[q] == 1;
				}
			now[p] = 0;
		}
		if (op == 4) {
			for (auto it : tmp[p]) {
				sum -= deg[it.first] == 1;
				deg[it.first] -= it.second;
				deg[it.first] += now[p];
				sum += deg[it.first] == 1;
			}
			tmp[p].clear();
			if (now[p] != 1)
				for (int q : adj[p]) {
					sum -= deg[q] == 1;
					deg[q]++;
					sum += deg[q] == 1;
				}
			now[p] = 1;
		}
//		if (t % 1000 == 0) fprintf(stderr, "%d\n", t);
		puts(sum == n ? "YES" : "NO");
	}
	return 0;
}
