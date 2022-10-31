#include<bits/stdc++.h>
#define int long long
#define N ((int)2e5 + 2)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define INF ((int)1e18 + 2)
#define pii pair<int, int>
#define fir first
#define sec second
#define MP make_pair
#define eps 1e-8
#define db double
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i) 
using namespace std;
int n, Q, K;
int a[N];
int head[N], pos;
struct Edge { int to, next; }edge[N << 1];
inline void add_edge (int u, int v) {
	edge[++pos] = (Edge) {v, head[u]}, head[u] = pos; }
namespace Solve1 {
	int f[N], st, ed;
	vector<int> path_;
	inline int calc () {
		/*rep (i, 0, (int)path_.size() - 1) f[i] = INF, cout<<path_[i]<<" ";
		cout<<'\n';*/
		f[0] = a[path_[0]];
		rep (i, 0, (int)path_.size() - 2) rep (j, 1, K) if (i + j <= (int)path_.size() - 1) {
			f[i + j] = min(f[i + j], f[i] + a[path_[i + j]]); }
		/*rep (i, 0, (int)path_.size() - 1) cout << f[i]<<" ";
		cout<<'\n';*/
		printf("%lld\n", f[(int)path_.size() - 1]);
	}
	inline void dfs (int u, int fa) {
		path_.emplace_back(u);
		if (u == ed) {
			calc();
			return;
		}
		go (i, u) {
			int v = edge[i].to;
			if (v == fa) continue;
			dfs(v, u);
		}
		path_.pop_back();
	}
}
inline void solve1 () {
	using namespace Solve1;
	while (Q--) {
		scanf("%lld%lld", &st, &ed);
		dfs(st, 0), path_.clear();
	}
}
namespace Solve2 {
	
}
inline void solve2 () {
	//裸树剖，只有10分不写了 
}
namespace Solve3 {
	int st, ed;
	int f[N];
	unordered_map<int, bool> mp;
	vector<int> to_root[N];
	vector<int> path_;
	inline void dfs (int u, int fa) {
		path_.emplace_back(u);
		drep (i, (int) path_.size() - 1, 0)
			to_root[u].emplace_back(path_[i]);
		go (i, u) {
			int v = edge[i].to;
			if (v == fa) continue;
			dfs(v, u);
		}
		path_.pop_back();
	}
}
inline void solve3 () {
	using namespace Solve3;
	dfs(1, 0);
	while (Q--) {
		scanf("%lld%lld", &st, &ed);
		rep (i, 0, to_root[ed].size() - 1) mp[to_root[ed][i]] = true;
		rep (i, 0, to_root[st].size() - 1) {
			path_.emplace_back(to_root[st][i]);
			if (mp[to_root[st][i]]) {
				int p;
				rep (j, 0, to_root[ed].size() - 1) if (to_root[ed][j] == to_root[st][i]) p = j - 1;
				drep (j, p, 0) path_.emplace_back(to_root[ed][j]);
				break;
			}
		}
		rep (i, 0, (int)path_.size() - 1) f[i] = INF;
		f[0] = a[path_[0]];
		rep (i, 0, (int)path_.size() - 2) rep (j, 1, K) if (i + j <= (int)path_.size() - 1) {
			f[i + j] = min(f[i + j], f[i] + a[path_[i + j]]); }
		printf("%lld\n", f[(int)path_.size() - 1]), path_.clear(), mp.clear();
	}
}
inline void freo () {
	freopen("transmit.in", "r", stdin), freopen("transmit.out", "w", stdout); }
signed main () {
	freo();
	scanf("%lld%lld%lld", &n, &Q, &K);
	rep (i, 1, n) scanf("%lld", &a[i]);
	int u, v;
	rep (i, 1, n - 1) {
		scanf("%lld%lld", &u, &v);
		add_edge(u, v), add_edge(v, u);
	}
	if (n <= 2000) solve1();
	else solve3();
return 0;
}
