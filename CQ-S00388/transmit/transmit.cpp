#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 2010;
const int M = 4e5 + 10;

long long n, Q, p, a, b;
long long v[N], Map[N][N], dp[N];
bool st[N];
vector<int> G[N];
queue<int> q;

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
	memset(Map, 0x3f3f3f, sizeof Map);
	
	scanf("%lld%lld%lld", &n, &Q, &p);
	
	for (int i = 1; i <= n; i ++) scanf("%lld", &v[i]);
	
	for (int i = 1; i < n; i ++) {
		scanf("%lld%lld", &a, &b);
		Map[a][b] = Map[b][a] = 1;
	}
	
	for (int i = 1; i <= n; i ++) Map[i][i] = 0;
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i != j && Map[i][j] <= p) G[i].push_back(j);
	
	while (Q --) {
		for (int i = 1; i <= n; i ++) dp[i] = 1e18;
		memset(st, false, sizeof st);
		
		scanf("%lld%lld", &a, &b);
		
		dp[a] = v[a], st[a] = true;
		queue<int> q;
		q.push(a);
		while (q.size()) {
			int t = q.front();
			q.pop();
			st[t] = false;
			for (int i = 0; i < G[t].size(); i ++) {
				int j = G[t][i];
				if (dp[j] > dp[t] + v[j]) {
					dp[j] = dp[t] + v[j];
					if (!st[j]) {
						st[j] = true;
						q.push(j); 
					} 
				}
			}
		}
		
		printf("%lld\n", dp[b]);
	} 
	
	return 0;
} 
