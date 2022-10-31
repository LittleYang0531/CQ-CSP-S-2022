#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int read();
const int MAXN = 2505, MAXM = 20005; 

int n, m, k, u, v;
ll val[MAXN];

int head[MAXN], nxt[MAXM], to[MAXM], cnt;
void addEdge(int x, int y) {
	nxt[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y; 
}

bool cmp(int x, int y) {
	return val[x] > val[y];
}

struct node{
	int pt;
	int ord[MAXN];
	void sortt() { sort(ord + 1, ord + n + 1, cmp); }
}a[MAXN];

void init() {
	n = read(), m = read(), k = read();
	for (int i = 2; i <= n; i++) scanf("%lld", &val[i]);
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		addEdge(u, v);
		addEdge(v, u);
	}
}

bool arr[MAXN];
int dis[MAXN];
queue<int> q;
void arrive() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dis[j] = 1000000;

		dis[i] = -1;
		q.push(i);

		int id;
		while (q.size()) {
			id = q.front();
			q.pop();
			
			for (int j = head[id]; j; j = nxt[j]) {
				if (dis[to[j]] < 1000000 || dis[id] + 1 > k) continue;
				dis[to[j]] = dis[id] + 1;
				q.push(to[j]);
			}
		}
		dis[i] = 1000000;
		if (dis[1] < 1000000) arr[i] = 1;
		for (int j = 2; j <= n; j++) {
			if (dis[j] <= k) {
				a[i].pt ++;
				a[i].ord[a[i].pt] = j;
			}
		}
		a[i].sortt();
	}
}

ll ans;
void solve() {
	int sa, sb, sc, sd;
	ll va, vb, vc, vd;
	for (int i = 1; i <= a[1].pt; i++) {
		sa = a[1].ord[i];
		va = val[sa];
		for (int j = 1; j <= a[sa].pt; j++) {
			sb = a[sa].ord[j];
			vb = va + val[sb];
			for (int k = 1; k <= a[sb].pt; k++) {
				sc = a[sb].ord[k];
				vc = vb + val[sc];
				if (sc == sa) continue;
				for (int l = 1; l <= a[sc].pt; l++) {
					sd = a[sc].ord[l];
					vd = vc + val[sd];
					
					if (ans >= vd) break;
					if (sd == sb || sd == sa || (arr[sd] == false)) continue;
					ans = vd;
					break;
				}
			}
		}
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	init();
	arrive();
	solve();
	printf("%lld", ans);
	return 0;
}

int read() {
	char x = 0;
	int y = 0;
	while (x < '0' || x > '9')
		x = getchar();
	while (x >= '0' && x <= '9') {
		y = (y << 1) + (y << 3) + (x ^ 48);
		x = getchar();
	}
	return y;
}
