#include<bits/stdc++.h>
#define int long long
#define N ((int)3e2 + 2)
#define M ((int)1e5 + 2)
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
int n, m, K;
int a[N];
int head[N], pos;
struct Edge { int to, next; }edge[M << 1];
inline void add_edge (int u, int v) {
	edge[++pos] = (Edge) {v, head[u]}, head[u] = pos; }
bool vis[N];
int dis[N];
priority_queue<pii, vector<pii >, greater<pii > > q;
vector<int> from_[N], to_[N];
bool con[N][N];
inline bool a_cmp (int x, int y) {
	return a[x] > a[y]; }
inline void dijkstra (int s) {
	rep (i, 1, n) dis[i] = INF, vis[i] = false;
	dis[s] = 0, q.push(MP(0, s));
	while (!q.empty()) {
		int u = q.top().sec;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		go (i, u) {
			int v = edge[i].to;
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(MP(dis[v], v));
			}
		}
	}
}
inline bool check (int p, int i, int j, int q) {
	if (p == 1 || i == 1 || j == 1 || q == 1) return false;
	if (p == q || p == i || p == j || i == q || i == j || j == q) return false;
	return true;
}
inline void freo () {
	freopen("holiday.in", "r", stdin), freopen("holiday.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> K;
	rep (i, 2, n) cin >> a[i];
	int u, v;
	rep (i, 1, m) {
		cin >> u >> v;
		add_edge(u, v), add_edge(v, u);
	}
	rep (i, 1, n) {
		dijkstra(i);
		rep (j, 1, n) if (j != i && dis[j] - 1 <= K) {
			con[i][j] = con[j][i] = true;
			//cout<<"nb: "<<i<<" "<<j<<'\n';
			if (con[1][j]) to_[i].emplace_back(j);
			if (con[1][i]) from_[j].emplace_back(i);
		}
	}
	rep (i, 1, n) {
		sort(from_[i].begin(), from_[i].end(), a_cmp);
		sort(to_[i].begin(), to_[i].end(), a_cmp);
	}
	int ans = 0;
	rep (i, 1, n) rep (j, 1, n) if (i != j && con[i][j]) {
		rep (p_, 0, min((int)from_[i].size() - 1, 4ll)) rep (q_, 0, min((int)to_[j].size() - 1, 4ll)) {
			int p = from_[i][p_], q = to_[j][q_];
			//cout<<p<<" "<<i<<" "<<j<<" "<<q<<'\n';
			if (check(p, i, j, q))
				/*cout<<p<<" "<<i<<" "<<j<<" "<<q<<'\n',*/ ans = max(ans, a[p] + a[i] + a[j] + a[q])/*, cout<<ans<<'\n'*/;
		}
	}
	cout << ans << '\n';
return 0;
} 
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
