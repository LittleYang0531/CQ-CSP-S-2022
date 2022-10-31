/*

*/
#include <bits/stdc++.h>
using namespace std;

#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define Check(a) freopen(a".in", "r", stdin), freopen(a".ans", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t i7;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int mod = 1e9 + 7;
inline void mi(int &x, int y) {x += y, x >= mod && (x -= mod);}
inline void ad(int &x, int y) {x -= y, x < 0 && (x += mod);}

const int N = 2505, M = 1e4 + 7;

int n, m, K, fst[N], tot;
struct edge {int nxt, to;} e[M << 1];

#define add(u, v) (e[++tot] = (edge) {fst[u], v}, fst[u] = tot)

ll a[N], g[N][5];
vector<int> f[N][5];
bool ex[N][N];
int le[N];
queue<int> q;

inline void topo(int zs, int k) {
	for (int i = 1; i <= n; ++i) le[i] = 0;
	q.push(zs); le[zs] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ex[zs][u] = 1;
		if (le[u] > k) continue;
		
		for (int i = fst[u], v; i; i = e[i].nxt) 
			!le[v = e[i].to] && (q.push(v), le[v] = le[u] + 1);
	}
}

inline bool ck(int i, int k, int j) {
	if (f[i][k].size() != k + 1) return 0;
	for (int v : f[i][k]) if (v == j) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	File("holiday");
	
	cin >> n >> m >> K; ++K;
	for (int i = 2; i <= n; ++i) cin >> a[i];
	for (int i = 1, u, v; i <= m; ++i) 
		cin >> u >> v, add(u, v), add(v, u);
		
	for (int i = 1; i <= n; ++i) topo(i, K);
	for (int i = 1; i <= n; ++i) ex[i][i] = 0;
	for (int j = 2; j <= n; ++j) ex[1][j] && (f[j][0].push_back(j), g[j][0] = a[j]);

	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= n; ++j) for (int k = 1; k <= n; ++k) 
			ex[j][k] && g[j][i - 1] + a[k] > g[k][i] && ck(j, i - 1, k) && (
				f[k][i] = f[j][i - 1], f[k][i].push_back(k), g[k][i] = g[j][i - 1] + a[k]);
	}

	cout << g[1][4] << "\n";
	
	return 0;
}
