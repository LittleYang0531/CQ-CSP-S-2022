#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2505,M = 20005;
const ll inf = 2e18;
int n,m,k,dis[N][N],Max[N][3];
ll a[N];
int tot,h[N],nxt[M],to[M];
bool vis[N];
struct Doge {
	int u,le;
};
Doge tmp;
queue <Doge> Q;
inline void Add(int x,int y) {
	nxt[++ tot] = h[x];
	h[x] = tot;
	to[tot] = y;
}
void Bfs(int s) {
	Q.push(Doge {s,0});
	for (int i = 1; i <= n; i ++) {
		vis[i] = 0;
		dis[s][i] = 0x3f3f3f3f;
	}
	dis[s][s] = 0;
	while (Q.size()) {
		Doge tmp = Q.front();
		Q.pop();
		int u = tmp.u,lev = tmp.le + 1;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int E = h[u]; E; E = nxt[E]) {
			int v = to[E];
			if (dis[s][v] > lev) {
				dis[s][v] = lev;
				Q.push(Doge {v,lev});
			}
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 2; i <= n; i ++) scanf("%lld",&a[i]);
	a[1] = -inf;
	for (int i = 1; i <= m; i ++) {
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	for (int i = 1; i <= n; i ++) Bfs(i);
	for (int i = 2; i <= n; i ++)
		if (dis[1][i] <= 2 * k + 2)
			for (int j = 2; j <= n; j ++)
				if (i != j && dis[i][j] <= k + 1 && dis[1][j] <= k + 1) {
					for (int i1 = 0; i1 < 3; i1 ++)
						if (a[j] > a[Max[i][i1]]) {
							for (int j1 = 2; j1 > i1; j1 --)
								Max[i][j1] = Max[i][j1 - 1];
							Max[i][i1] = j;
							break;
						}
				}
	long long ans = 0ll;
	for (int i = 2; i <= n; i ++)
		if (dis[1][i] <= 2 * k + 2)
			for (int j = 2; j <= n; j ++)
				if (i != j && dis[i][j] <= k + 1 && dis[1][j] <= 2 * k + 2) {
					long long sum = 0ll;
					for (int i1 = 0; i1 < 3; i1 ++)
						if (Max[i][i1] <= 1) break;
						else if (Max[i][i1] != j) {
							for (int j1 = 0; j1 < 3; j1 ++)
								if (Max[j][j1] <= 1) break;
								else if (Max[i][i1] != Max[j][j1] && i != Max[j][j1]) {
									sum = max(sum,a[i] + a[j] + a[Max[i][i1]] + a[Max[j][j1]]);
								} 
						}
					ans = max(ans,sum);
				}
	printf("%lld",ans);
	return 0;
}
