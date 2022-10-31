#include <iostream>
#include <cstdio>
#include <vector>
const int nn = 2e5 + 5;
typedef long long ll;
int n, m, K;
ll v[nn], tmp[nn];
const ll inf = 1e18;
struct info {
	ll v[3][3]; int len;
	info(const ll val = inf) {
		v[0][1] = v[0][2] = v[1][1] = v[1][2] = inf;
		v[2][2] = v[2][1] = v[2][0] = v[1][0] = inf;
		v[0][0] = val; len = val != inf;
	}
//	void print()const {
//		puts("========");
//		printf("%d\n", len);
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++)
//				printf("%lld ", v[i][j]);
//			puts("");
//		}
//		puts("========");
//	}
	info operator+ (const info &rhs)const {
//		puts("operator+:");
//		print();
//		rhs.print();
		if (len == 0) return rhs;
		info ret; ret.len = len + rhs.len;
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				ret.v[i][j] = inf;
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				for (int k = 0; k < K - j; k++)
					for (int l = 0; l < K; l++)
						ret.v[i][l] = std::min(ret.v[i][l], v[i][j] + rhs.v[k][l]);
		for (int i = 0; i + len < K; i++)
			for (int j = 0; j < K; j++)
				ret.v[i + len][j] = std::min(ret.v[i + len][j], rhs.v[i][j]);
		for (int i = 0; i < K; i++)
			for (int j = 0; j + rhs.len < K; j++)
				ret.v[i][j + rhs.len] = std::min(ret.v[i][j + rhs.len], v[i][j]);
//		ret.print();
		return ret;
	}
} mt[18][nn];
int fath[18][nn], dep[nn];
std::vector<int> adj[nn];
void dfs(int p, int fa) {
	dep[p] = dep[fath[0][p] = fa] + 1;
	if (fa) {
		tmp[fa] = std::min(tmp[fa], v[p]);
		tmp[p] = std::min(tmp[p], v[fa]);
	}
	for (int q : adj[p])
		if (q != fa) dfs(q, p);
}
int lca(int p, int q) {
	if (dep[p] < dep[q]) std::swap(p, q);
	for (int i = 17; i >= 0; i--)
		if ((1 << i) <= dep[p] - dep[q]) p = fath[i][p];
	if (p == q) return p;
//	printf("%d %d\n", p, q);
	for (int i = 17; i >= 0; i--)
		if (fath[i][p] != fath[i][q])
			p = fath[i][p], q = fath[i][q];
//	printf("%d %d\n", p, q);
	return fath[0][p];
}
ll solve(int p, int q) {
	int l = lca(p, q);
//	printf("%d %d %d\n", p, q, l);
	info v1 = info(), v2 = info();
	int dep1 = dep[p] - dep[l] + 1, dep2 = dep[q] - dep[l] + 1;
	for (int i = 17; i >= 0; i--) {
		if (dep1 >> i & 1) {
			v1 = v1 + mt[i][p];
			p = fath[i][p];
		}
		if (dep2 >> i & 1) {
			v2 = v2 + mt[i][q];
			q = fath[i][q];
		}
//		v1.print();
//		v2.print();
	}
//	v1.print(); v2.print();
	ll ret = v1.v[0][0] + v2.v[0][0] - (p == l || q == l ? 0 : v[l]);
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K && i + j <= K; j++)
			ret = std::min(ret, v1.v[0][i] + v2.v[0][j]);
	return ret;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &K);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", v + i);
		tmp[i] = 1e18;
	}
	for (int i = 1, p, q; i < n; i++) {
		scanf("%d %d", &p, &q);
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	dfs(1, 0);
	for (int p = 1; p <= n; p++) {
		mt[0][p] = info(v[p]);
		mt[0][p].v[1][1] = tmp[p];
		for (int i = 1; (1 << i) <= dep[p]; i++) {
			fath[i][p] = fath[i - 1][fath[i - 1][p]];
			mt[i][p] = mt[i - 1][p] + mt[i - 1][fath[i - 1][p]];
//			mt[i][p].print();
		}
	}
//	puts("----------------------------------------");
	while (m--) {
		int p, q; scanf("%d %d", &p, &q);
		printf("%lld\n", solve(p, q));
	}
	return 0;
}
