/*
内向基环森林
第 60 分用 set 就可以解决 
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

const int N = 5e5 + 7;

int n, m, q, du[N], ru[N], num;
vector<int> g[N], vi[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	File("galaxy");
	
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) 
		cin >> u >> v, ++du[u], g[v].push_back(u);
		
	for (int i = 1; i <= n; ++i) {
		num += (du[i] == 1); vi[i].resize(ru[i] = g[i].size());
		for (int j = 0; j < g[i].size(); ++j) vi[i][j] = 0;
		sort(g[i].begin(), g[i].end());
	}
	
	cin >> q;
	for (int i = 1, op, u, v; i <= q; ++i) {
		cin >> op >> u;
		if (op == 1) {
			cin >> v;
			int po = lower_bound(g[v].begin(), g[v].end(), u) - g[v].begin();
			vi[v][po] = 1;
			num -= (du[u] == 1); --du[u]; num += (du[u] == 1);
		}
		else if (op == 3) {
			cin >> v;
			int po = lower_bound(g[v].begin(), g[v].end(), u) - g[v].begin();
			vi[v][po] = 0;
			num -= (du[u] == 1); ++du[u]; num += (du[u] == 1);
		}
		else if (op == 2) {
			for (int j = 0; j < g[u].size(); ++j) if (!vi[u][j]) {
				vi[u][j] = 1; v = g[u][j];
				num -= (du[v] == 1); --du[v]; num += (du[v] == 1);
			}
		}
		else {
			for (int j = 0; j < g[u].size(); ++j) if (vi[u][j]) {
				vi[u][j] = 0; v = g[u][j];
				num -= (du[v] == 1); ++du[v]; num += (du[v] == 1);
			}
		}
		if (num == n) cout << "YES\n"; else cout << "NO\n";
	}
	
	return 0;
}
