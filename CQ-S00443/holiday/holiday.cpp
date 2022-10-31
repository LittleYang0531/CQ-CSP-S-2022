#include<bits/stdc++.h>
#define LL long long
#define mes(s, x) memset(s, x, sizeof(s))
#define MAXN 2505
using namespace std;
vector<int> G[MAXN];
LL v[MAXN], d[MAXN], q[MAXN], mx[MAXN][3], p[MAXN][3], ans;
bitset<MAXN> b[MAXN];
void bfs(int i){
	mes(d, -1);
	d[i] = 0;
	int l = 1, r = 1, x, y;
	q[1] = i;
	while(l <= r){
		x = q[l++];
		for(int j = 0; j < G[x].size(); j++){
			y = G[x][j];
			if(d[y] == -1){
				d[y] = d[x] + 1;
				q[++r] = y;
			}
		}
	}
}
void udp(int i, int j, int x, int y){
	if(x == j || y == i || x == y || (x && y) == 0) return;
	ans = max(ans, v[i] + v[j] + v[x] + v[y]);
} 
int main(){//Д§бщ 
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	int n, m, k, x, y;
	scanf("%d %d %d", &n, &m, &k);
	k++;
	for(int i = 2; i <= n; i++) scanf("%lld", &v[i]);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		bfs(i);
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			b[i][j] = d[j] <= k;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= n; j++){
			if(i == j) continue;
			if(b[i][j] && b[1][j]){
				if(mx[i][0] < v[j]){
					mx[i][2] = mx[i][1];
					p[i][2] = p[i][1];
					mx[i][1] = mx[i][0];
					p[i][1] = p[i][0];
					mx[i][0] = v[j];
					p[i][0] = j;
				}else if(mx[i][1] < v[j]){
					mx[i][2] = mx[i][1];
					p[i][2] = p[i][1];
					mx[i][1] = v[j];
					p[i][1] = j;
				}else if(mx[i][2] < v[j]){
					mx[i][2] = v[j];
					p[i][2] = j;
				}
			}
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(b[i][j]){
				for(int k = 0; k < 3; k++){
					for(int o = 0; o < 3; o++){
						udp(i, j, p[i][k], p[j][o]);
					}
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
