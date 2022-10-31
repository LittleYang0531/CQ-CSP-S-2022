#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<long long, long long> PII;

const int N = 2510;
const int M = 20010;

long long n, m, p, a, b, ans;
long long h[N], e[M], ne[M], idx;
long long dis[N][N], point[N];
bool st[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void spfa(int sta) {
	queue<int> q;
	memset(st, false, sizeof st);
	dis[sta][sta] = 0;
	q.push(sta), st[sta] = true;
	while (q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (dis[sta][t] + 1 < dis[sta][j]) {
				dis[sta][j] = dis[sta][t] + 1;
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	memset(h, -1, sizeof h);
	memset(dis, 0x3f3f3f, sizeof dis);
	
	scanf("%lld%lld%lld", &n, &m, &p);
	
	for (int i = 2; i <= n; i ++) scanf("%lld", &point[i]);
	
	for (int i = 1; i <= m; i ++) {
		scanf("%lld%lld", &a, &b);
		add(a, b), add(b, a);
	}
	
	for (int i = 1; i <= n; i ++) spfa(i);
	
	for (int i = 2; i <= n; i ++) {
		for (int j = 2; j <= n; j ++) {
			if (i == j || dis[i][j] - 1 > p) continue;
			int ans1 = -2e9, ans2 = -2e9, Use = -1;
			for (int k = 2; k <= n; k ++) {
				if (k == i || k == j) continue;
				if (dis[1][k] - 1 <= p && dis[k][i] - 1 <= p) {
					if (point[k] > ans1) {
						ans1 = point[k];
						Use = k;
					}
				}
			}
			if (Use == -1) continue;
			for (int k = 2; k <= n; k ++) {
				if (k == i || k == j || k == Use) continue;
				if (dis[j][k] - 1 <= p && dis[k][1] - 1 <= p && point[k] > ans2)
					ans2 = point[k];
			}
			ans = max(ans, point[i] + point[j] + ans1 + ans2);
			ans1 = ans2 = -2e9, Use = -1;
			for (int k = 2; k <= n; k ++) {
				if (k == i || k == j) continue;
				if (dis[j][k] - 1 <= p && dis[k][1] - 1 <= p) {
					if (point[k] > ans1) {
						ans1 = point[k];
						Use = k;
					}
				}
			}
			if (Use == -1) continue;
			for (int k = 2; k <= n; k ++) {
				if (k == i || k == j || k == Use) continue;
				if (dis[1][k] - 1 <= p && dis[k][i] - 1 <= p && point[k] > ans2)
					ans2 = point[k];
			}
			ans = max(ans, point[i] + point[j] + ans1 + ans2);
		}
	}
	
	printf("%lld", ans);
	
	return 0;
} 
