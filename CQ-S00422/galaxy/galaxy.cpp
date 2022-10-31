// Never Gonna Run¡ú A¡üround¡ý And
// 40pts
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
namespace yj{
const int MAXN = 1005;
const int MAXM = 10005;
struct edge {
	int to, val, nxt;
} edges[MAXM << 1];
int head[MAXN], invh[MAXN], tot;
void add(int u, int v, int *h) {
	edges[++tot].to = v; edges[tot].nxt = h[u]; h[u] = tot;
	edges[tot].val = 1;
}
int n;
bool check() {
	static int dep[MAXN];
	for (int i = 1; i <= n; i++) dep[i] = 0;
	for (int i = 1; i <= n; i++) {
		int tots = 0;
		for (int j = head[i]; j; j = edges[j].nxt) {
			if (edges[j].val) dep[edges[j].to]++, tots++;
		}
		if (tots != 1) return 0;
	}
	queue<int> q; for (int i = 1; i <= n; i++) {
		if (dep[i] == 0) q.push(i);
	}
	while (q.empty() == 0) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = edges[i].nxt) {
			if (edges[i].val) {
				dep[edges[i].to]--;
				if (dep[edges[i].to] == 0) q.push(edges[i].to);
			}
		}
	}
	bool flg = 0;
	for (int i = 1; i <= n; i++) {
		if (dep[i]) flg = 1;
	}
	return flg;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	tot = 1;
	int m, q; scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d %d", &u, &v); add(u, v, head); add(v, u, invh);
	}
	scanf("%d", &q); while (q--) {
		int a, b, c; scanf("%d %d", &a, &b);
		if (a == 1 || a == 3) scanf("%d", &c);
		if (a == 1) {
			for (int i = head[b]; i; i = edges[i].nxt) {
				if (edges[i].to == c) edges[i].val = 0;
			}
		}
		if (a == 2) {
			for (int i = invh[b]; i; i = edges[i].nxt) {
				edges[i ^ 1].val = 0;
			}
		}
		if (a == 3) {
			for (int i = head[b]; i; i = edges[i].nxt) {
				if (edges[i].to == c) edges[i].val = 1;
			}
		}
		if (a == 4) {
			for (int i = invh[b]; i; i = edges[i].nxt) {
				edges[i ^ 1].val = 1;
			}
		}
		puts(check() ? "YES" : "NO");
	}
	return 0;
}
}
int main() {return yj::main();}
