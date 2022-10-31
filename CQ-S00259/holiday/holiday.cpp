#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 2.5e3 + 5, MAXM = 2e4 + 5;
long long a[MAXN], ans, maxn;
vector<int> G[MAXN];
int dis[MAXN], head[MAXN], Next[MAXM], ver[MAXM], n, k, cnt;
bool vis[MAXN];

struct point {
	int k, cnt, a[5];
	long long sum;
	p(int K, int Cnt, int A[], long long Sum) {
		k = K, cnt = Cnt, sum = Sum;
		for (int i = 1; i <= cnt; i++)
			a[i] = A[i];
	}
} t1;

void f(point t) {
	if (dis[t.k] > (4 - t.cnt + 1) * (k + 1))
		return;
	if (t.sum + (4 - t.cnt) * maxn <= ans)
		return;
	if (t.cnt == 4) {
		ans = t.sum;
		return;
	}
	for (int i = 0; i < G[t.k].size(); i++) {
		int x = G[t.k][i];
		bool flag = false;
		for (int j = 1; j <= t.cnt; j++)
			if (x == t.a[j]) {
				flag = true;
				break;
			}
		if (flag)
			continue;
		t1 = t;
		t1.k = x, t1.a[++t1.cnt] = x, t1.sum += a[x];
		f(t1);
	}
}

struct node {
	int x, dis;
	node(int X, int Dis) {
		x = X, dis = Dis;
	}
	bool operator < (const node& o) const {
		return dis > o.dis;
	}
};

priority_queue<node> q;

void Dijkstra() {
	while (!q.empty()) {
		int t = q.top().x;
		q.pop();
		if (vis[t])
			continue;
		vis[t] = true;
		for (int i = head[t]; i; i = Next[i]) {
			int x = ver[i];
			if (!vis[x] && dis[x] > dis[t] + 1) {
				dis[x] = dis[t] + 1;
				q.push(node(x, dis[x]));
			}
		}
	}
}

void dfs(int s, int t, int step) {
	if (step > k)
		return;
	if (t != s && t != 1)
		G[s].push_back(t);
	vis[t] = true;
	for (int i = head[t]; i; i = Next[i]) {
		int x = ver[i];
		if (!vis[x])
			dfs(s, x, step + 1);
	}
}

void AddEdge(int x, int y) {
	ver[++cnt] = y;
	Next[cnt] = head[x], head[x] = cnt;
}

long long read() {
	long long x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}

int Read() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}

long long Max(long long x, long long y) {
	return x > y ? x : y;
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	int m, x, y;
	scanf("%d %d %d", &n, &m, &k);
	a[1] = 0;
	for (int i = 2; i <= n; i++) {
		a[i] = read(), dis[i] = 0x3f3f3f3f;
		maxn = Max(maxn, a[i]);
	}
	while (m--) {
		x = Read(), y = Read();
		AddEdge(x, y);
		AddEdge(y, x);
	}
	q.push(node(1, dis[1]));
	Dijkstra();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			vis[j] = false;
		dfs(i, i, -1);
	}
	t1.k = 1, t1.cnt = 0, t1.a[0] = 0, t1.sum = 0;
	f(t1);
	printf("%lld", ans);
	return 0;
}

