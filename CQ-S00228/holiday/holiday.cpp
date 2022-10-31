#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2500 + 5, M = 10000 + 10;
int n, m, k;
struct node {
	long long val;
	int id;
} a[N];
struct edge {
	int nxt, to;
} e[M*2];
int h[N], num;
int dis[N][N];
bool vis[N];
void addedge(int x, int y) {
	e[++num].nxt = h[x];
	e[num].to = y;
	h[x] = num;
}
bool cmp(const node &x, const node &y) {
	return x.val > y.val;
}
void Read() {
	scanf ("%d%d%d", &n, &m, &k);
	a[1].id = 1;
	for (int i = 2; i <= n; ++i) {
		scanf ("%lld", &a[i].val);
		a[i].id = i;
	}
	for (int i = 1, x, y; i <= m; ++i) {
		scanf ("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
}
priority_queue<pair<int, int> > q;
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	dis[s][s] = -1;
	q.push(make_pair(1, s));
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x] = true;
		for (int i = h[x]; i; i = e[i].nxt) {
			int y = e[i].to;
			if (dis[s][y] > dis[s][x] + 1) {
				dis[s][y] = dis[s][x] + 1;
				q.push(make_pair(-dis[s][y], y));
			}
		}
	}
}
long long dfs(int x, int p) {
	if (x == 1 && p == 5) return 0;
	if (p == 5) return -1;
//	cout << x << ' ' << p << endl;
	long long sum=-1;
	for (int i = h[x]; i; i = e[i].nxt) {
		int y = e[i].to;
		if (vis[y]) continue;
		vis[y]=true;
		long long g=dfs(y, p+1);
		sum=max(sum, g);
		vis[y]=0;
	}
	if (sum==-1) return sum;
//	cout  << x << ' ' <<p << '\n';
	return sum+a[x].val;
}
void solve() {
	long long ans = 0;
//	for (int i = h[6];i;i=e[i].nxt)cout<<e[i].to<<'\n';
	for (int i = h[1]; i; i = e[i].nxt) {
//		cout << dfs(e[i].to, 1) << '\n';
		vis[e[i].to]=1;
//		cout << e[i].to <<' '<< dfs(e[i].to, 1) << '\n';
//cout <<"GOOD\n"<<e[i].to<<'\n';
		ans = max(ans, dfs(e[i].to, 1));
		vis[e[i].to]=0;
	}
	printf ("%lld\n", ans);
}
void Solve() {
	if (k == 0) {
		solve();
		return;
	}
	stable_sort(a+2, a+2+n, cmp);
	memset(dis, 0x3f, sizeof(dis));
	long long ans = 0;
	for (int i=1; i<=n; ++i) dijkstra(i);
	for (int A = 2; A <= n; ++A)  {
		for (int B = 2; B <= n; ++B) {
			if (A == B) continue;
			for (int C = 2; C <= n; ++C) {
				if (A == C || B == C) continue;
				for (int D = 2; D <= n; ++D) {
					if (A == D || B == D || C == D) continue;
					if (a[A].val+a[B].val+a[C].val+a[D].val<=ans) break;
					if (dis[a[1].id][a[A].id] <= k) {
						if (dis[a[B].id][a[C].id] <= k) {
							if (dis[a[C].id][a[D].id] <= k) {
								if (dis[a[D].id][a[1].id] <= k) {
									if (dis[a[A].id][a[B].id] <= k) {
										ans = max(ans, a[A].val + a[B].val + a[C].val + a[D].val);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf ("%lld\n", ans);
}
int main() {
	freopen("holiday.in", "r", stdin);//!!!!!!!!!!!!
	freopen("holiday.out", "w", stdout);
	Read();
	Solve();
//	while(1);
	return 0;
}

