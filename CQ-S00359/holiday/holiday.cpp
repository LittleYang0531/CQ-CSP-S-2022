#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int n, m, K, head[N], nxt[N], to[N], ecnt, dis[2503][2503];
void add_edge(int u, int v) {nxt[++ecnt] = head[u]; to[ecnt] = v; head[u] = ecnt;}
ll a[N];
void BFS(int s) {
	queue<int> Q;
	dis[s][s] = 0;
	Q.push(s);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		if(dis[s][u] >= K) continue;
		for(int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if(dis[s][v] != inf) continue;
			dis[s][v] = dis[s][u] + 1;
			Q.push(v);
		}
	}
}


int st[2503][4];

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d%d%d", &n, &m, &K); K++;
	for(int i = 2; i <= n; i++) {scanf("%lld", &a[i]);}
	for(int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v); add_edge(u, v), add_edge(v, u);
	}
	for(int i = 1; i <= n; i++) BFS(i);
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			printf("dis[%d][%d]=%d\n", i, j, dis[i][j]); 
//		}
//	}
	ll ans = 0;
	for(int i = 2; i <= n; i++) {
		if(dis[i][1] > K) continue;
		for(int j = 2; j <= n; j++) {
			if(i == j || dis[i][j] > K) continue;
			if(a[i] > a[st[j][1]]) {
				st[j][3] = st[j][2]; st[j][2] = st[j][1]; st[j][1] = i;
			}
			else if(a[i] > a[st[j][2]]) {
				st[j][3] = st[j][2]; st[j][2] = i;
			}
			else if(a[i] > a[st[j][3]]) {
				st[j][3] = i;
			}
		}
	}
//	for(int i = 1; i <= n; i++) {
//		printf("i=%d: rk1=%d rk2=%d rk3=%d\n", i, st[i][1], st[i][2], st[i][3]);
//	}
	for(int B = 2; B <= n; B++) {	//B
		for(int C = 2; C <= n; C++) {	//C
			if(B == C || dis[B][C] > K) continue;
			for(int l = 1; l <= 3; l++) {	//A
				int A = st[B][l];
				if(!A) break;
				if(A == C) continue;
				for(int r = 1; r <= 3; r++) {
					int D = st[C][r];
					if(!D) break;
					if(A == D || B == D) continue;
//					printf("A=%d B=%d C=%d D=%d ans=%lld\n", A, B, C, D, ans);
					ans = max(ans, a[A] + a[B] + a[C] + a[D]);
					break;
				}
			}
		}
	}
	
	printf("%lld", ans);
	return 0;
}

//I can't say only word right now. 
//Just fighting until you die!
