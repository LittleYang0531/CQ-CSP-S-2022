#include <cstdio>
#include <vector>

#define LL long long
#define uLL unsigned LL

LL rint() {
	LL x = 0, Fx = 1; char c = getchar();
	while (c < '0' || c > '9') { Fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	return Fx ? x : -x;
}

LL Max(LL u, LL v) { return (u > v) ? u : v; }
LL Min(LL u, LL v) { return (u < v) ? u : v; }

const LL inf = 0x3f3f3f3f3f3f3f3f;

const int MAX_n = 2e5;
const int MAX_m = 2e5;
const int MAX_k = 3;

int n, m, k, Time;
int vs[MAX_n + 5];
int fa[MAX_n + 5];
int idx[MAX_n + 5];
int dep[MAX_n + 5];
int siz[MAX_n + 5];
int Top[MAX_n + 5];
int dfn[MAX_n + 5];

std::vector<int> G[MAX_n + 5];

LL dpx[MAX_n + 5];
LL Temp[MAX_k + 5];

struct node {
	LL dp[3][3], dpp[3];
	
	node () {
		dp[0][0] = dp[0][1] = dp[0][2] = inf;
		dp[1][0] = dp[1][1] = dp[1][2] = inf;
		dp[2][0] = dp[2][1] = dp[2][2] = inf;
		dpp[0] = dpp[1] = dpp[2] = inf;
	}
	
	node operator + (const node &rhs) const {
		node res;
		for (int j = 0; j < k; j++) {
			Temp[0] = rhs.dp[0][j];
			for (int y = 1; y < k; y++)
				Temp[y] = Min(Temp[y - 1], rhs.dp[y][j]);
			for (int i = 0; i < k; i++) {
				for (int x = 0; x < k; x++)
					res.dp[i][j] = Min(res.dp[i][j], dp[i][x] + Temp[k - x - 1]);
				for (int x = 0; x < j; x++)
					res.dp[i][j] = Min(res.dp[i][j], dp[i][x] + rhs.dpp[j - 1 - x]);
				for (int y = 0; y < i; y++)
					res.dp[i][j] = Min(res.dp[i][j], dpp[i - 1 - y] + rhs.dp[y][j]);
			}
			for (int i = 0; i < k - 1 - j; i++)
				res.dpp[i + j + 1] = Min(res.dpp[i + j + 1], dpp[i] + rhs.dpp[j]);
		}
		return res;
	}
} tree[MAX_n * 4 + 5];

void pushup(int u) {
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}

void build(int u, int L, int R) {
	if (L == R) {
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				tree[u].dp[i][j] = vs[idx[L]];
		tree[u].dp[1][1] = Min(tree[u].dp[1][1], dpx[idx[L]]);
		tree[u].dpp[0] = 0;
		return ;
	}
	int Mid = (L + R) >> 1;
	build(u << 1, L, Mid);
	build(u << 1 | 1, Mid + 1, R);
	pushup(u);
}

node Ask(int u, int L, int R, int qL, int qR) {
	if (qL <= L && R <= qR)
		return tree[u];
	int Mid = (L + R) >> 1;
	if (qL <= Mid && qR > Mid)
		return Ask(u << 1, L, Mid, qL, qR) + Ask(u << 1 | 1, Mid + 1, R, qL, qR);
	else if (qL <= Mid)
		return Ask(u << 1, L, Mid, qL, qR);
	else
		return Ask(u << 1 | 1, Mid + 1, R, qL, qR);
}

void Add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

void dfs1(int u, int Fu) {
	fa[u] = Fu;
	dep[u] = dep[Fu] + 1;
	siz[u] = 1;
	for (auto v : G[u])
		if (v != Fu) dfs1(v, u), siz[u] += siz[v];
}

void dfs2(int u, int utop) {
	dfn[u] = ++Time;
	Top[u] = utop;
	idx[Time] = u;
	int son = 0;
	for (auto v : G[u])
		if (v != fa[u] && siz[v] > siz[son]) son = v;
	if (son) dfs2(son, utop);
	for (auto v : G[u])
		if (v != fa[u] && v != son) dfs2(v, v);
}

LL solve(int u, int v) {
	node s, t;
	s.dp[k - 1][0] = 0;
	t.dp[k - 1][0] = 0;
	while (Top[u] != Top[v]) {
		if (dep[Top[u]] > dep[Top[v]])
			s = Ask(1, 1, n, dfn[Top[u]], dfn[u]) + s, u = fa[Top[u]];
		else
			t = Ask(1, 1, n, dfn[Top[v]], dfn[v]) + t, v = fa[Top[v]];
	}
	if (dep[u] > dep[v])
		s = Ask(1, 1, n, dfn[v], dfn[u]) + s, u = v;
	else
		t = Ask(1, 1, n, dfn[u], dfn[v]) + t, v = u;
	LL res = s.dp[0][0] + t.dp[0][0];
	for (int x = 0; x < k; x++)
		for (int y = 0; y < k - x; y++)
			res = Min(res, s.dp[x][0] + t.dp[y][0]);
	return res;
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	n = rint(), m = rint(), k = rint();
	for (int i = 1; i <= n; i++)
		vs[i] = rint(), dpx[i] = inf;
	for (int i = 1, u, v; i < n; i++) {
		u = rint(), v = rint();
		Add_edge(u, v);
		dpx[u] = Min(dpx[u], vs[v]);
		dpx[v] = Min(dpx[v], vs[u]);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	int s, t;
	while (m--) {
		s = rint(), t = rint();
		printf("%lld\n", solve(s, t));
	}
	return 0;
}

