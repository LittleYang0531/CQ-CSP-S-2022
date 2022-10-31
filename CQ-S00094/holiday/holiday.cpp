#include<bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(x) begin(x), end(x)
#define int long long

using namespace std;

bool mem1;
const int N = 2505, M = 2e4 + 5, inf = 0x3f3f3f3f;
int n, m, K, a[N], q[N], ql, qr;
int head[N], nex[M << 1], e[M << 1], tot = 1;
int dis[N], d[N][N];
struct Node {
	int A, B, C;
	Node(int aa = 0, int bb = 0, int cc = 0) : A(aa), B(bb), C(cc) {}
	friend Node operator + (const Node &x, const int &y) {
		Node res = x;
		if(a[y] > a[res.A]) {
			res = Node(y, res.A, res.B);
		} else if(a[y] > a[res.B]) {
			res = Node(res.A, y, res.B);
		} else if(a[y] > a[res.C]) {
			res = Node(res.A, res.B, y);
		}
		return res;
	}
};
Node f[N];
bool mem2;

void add(int x, int y) {
	nex[++tot] = head[x];
	head[x] = tot;
	e[tot] = y;
}

void bfs(int S) {
	fill(dis + 1, dis + n + 1, inf);
	dis[S] = 0;
	q[ql = qr = 1] = S;
	while(ql <= qr) {
		int x = q[ql++];
		if(dis[x] == K + 1) {
			continue;
		}
		for(int i = head[x]; i; i = nex[i]) {
			int y = e[i];
			if(dis[y] == inf) {
				dis[y] = dis[x] + 1;
				q[++qr] = y;
			}
		}
	}
}

signed main() {
	File("holiday");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> K;
	for(int i = 2; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	for(int i = 1; i <= n; ++i) {
		bfs(i);
		for(int j = 1; j <= n; ++j) {
			d[i][j] = dis[j];
		} 
	}
	for(int i = 2; i <= n; ++i) {
		f[i] = Node(0, 0, 0);
		for(int j = 2; j <= n; ++j) {
			if(i == j) {
				continue;
			}
			if(d[1][j] <= K + 1 && d[j][i] <= K + 1) {
				f[i] = f[i] + j;
			}
		}
	}
	int ans = 0;
	for(int x = 2; x <= n; ++x) {
		for(int y = 2; y <= n; ++y) {
			if(x == y || f[x].A == 0 || f[y].A == 0 || d[x][y] > K + 1) {
				continue;
			}
			int val = a[x] + a[y];
			vector<int> v1, v2;
			if(f[x].A != y) v1.push_back(f[x].A);
			if(f[x].B != y) v1.push_back(f[x].B);
			if(f[x].C != y) v1.push_back(f[x].C);
			if(f[y].A != x) v2.push_back(f[y].A);
			if(f[y].B != x) v2.push_back(f[y].B);
			if(f[y].C != x) v2.push_back(f[y].C);
			while(!v1.empty() && v1.back() == 0) {
				v1.pop_back();
			}
			while(!v2.empty() && v2.back() == 0) {
				v2.pop_back();
			}
			if(v1[0] == v2[0]) {
				if(v1.size() == 1 && v2.size() == 1) {
					continue;
				}
				int mx = 0;
				if(v1.size() >= 2) {
					mx = max(mx, a[v1[1]]);
				}
				if(v2.size() >= 2) {
					mx = max(mx, a[v2[1]]);
				}
				val += a[v1[0]] + mx;
			} else {
				val += a[v1[0]] + a[v2[0]];
			}
			ans = max(ans, val);
		}
	}
	cout << ans << "\n";
	return 0;
}
/*

*/
