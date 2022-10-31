#include <stdio.h>

#include <queue>

using namespace std;

typedef long long ll;

typedef struct {
	int nxt;
	int end;
} Edge;

int cnt = 0;
int dis[2507][2507], head[2507], max_pos[2507], cmax_pos[2507], ccmax_pos[2507];
ll s[2507], f[2507][2507];
Edge edge[20007];
queue<int> q;

inline void init(int n){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = 0x7fffffff;
		}
	}
}

inline void add_edge(int start, int end){
	cnt++;
	edge[cnt].nxt = head[start];
	head[start] = cnt;
	edge[cnt].end = end;
}

void bfs(int start, int n){
	dis[start][start] = 0;
	q.push(start);
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i = head[cur]; i != 0; i = edge[i].nxt){
			int x = edge[i].end;
			if (dis[start][x] == 0x7fffffff){
				dis[start][x] = dis[start][cur] + 1;
				q.push(x);
			}
		}
	}
}

inline ll max(ll a, ll b){
	return a > b ? a : b;
}

int main(){
	int n, m, k;
	ll ans = 0;
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	init(n);
	for (int i = 2; i <= n; i++){
		scanf("%lld", &s[i]);
	}
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
	for (int i = 1; i <= n; i++){
		bfs(i, n);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i != j && dis[1][i] <= k + 1 && dis[i][j] <= k + 1){
				f[i][j] = s[i] + s[j];
			} else {
				f[i][j] = -4e18;
			}
		}
	}
	for (int i = 2; i <= n; i++){
		max_pos[i] = cmax_pos[i] = ccmax_pos[i] = i;
		for (int j = 2; j <= n; j++){
			if (f[max_pos[i]][i] < f[j][i]){
				ccmax_pos[i] = cmax_pos[i];
				cmax_pos[i] = max_pos[i];
				max_pos[i] = j;
			} else if (f[cmax_pos[i]][i] < f[j][i]){
				ccmax_pos[i] = cmax_pos[i];
				cmax_pos[i] = j;
			} else if (f[ccmax_pos[i]][i] < f[j][i]){
				ccmax_pos[i] = j;
			}
		}
	}
	for (int i = 2; i <= n; i++){
		for (int j = 2; j <= n; j++){
			if (i != j && dis[i][j] <= k + 1){
				int A = max_pos[i], B = cmax_pos[i], C = ccmax_pos[i], D = max_pos[j], E = cmax_pos[j], F = ccmax_pos[j];
				if (A != j){
					if (D != A && D != i){
						ans = max(ans, f[A][i] + f[D][j]);
					}
					if (E != A && E != i){
						ans = max(ans, f[A][i] + f[E][j]);
					}
					if (F != A && F != i){
						ans = max(ans, f[A][i] + f[F][j]);
					}
				}
				if (B != j){
					if (D != B && D != i){
						ans = max(ans, f[B][i] + f[D][j]);
					}
					if (E != B && E != i){
						ans = max(ans, f[B][i] + f[E][j]);
					}
					if (F != B && F != i){
						ans = max(ans, f[B][i] + f[F][j]);
					}
				}
				if (C != j){
					if (D != C && D != i){
						ans = max(ans, f[C][i] + f[D][j]);
					}
					if (E != C && E != i){
						ans = max(ans, f[C][i] + f[E][j]);
					}
					if (F != C && F != i){
						ans = max(ans, f[C][i] + f[F][j]);
					}
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
