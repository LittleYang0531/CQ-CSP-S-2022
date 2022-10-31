#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n, m, q, op, u, v, sum;
bool loop[1005], vis[1005];
bool mp[1005][1005], bg[1005][1005];
inline bool judge(int r){
	if (loop[r]) return 1;
	if (vis[r]){
		loop[r] = 1;
		return 1;
	}
	vis[r] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (mp[r][i]) ++cnt;
	if (cnt != 1) return 0;
	for (int i = 1; i <= n; i++)
		if (mp[r][i] && judge(i)) return loop[r] = 1;
	return 0;
}
int main(){
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++){
		scanf("%d %d", &u, &v);
		mp[u][v] = bg[u][v] = 1;
	}
	sum = m;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &op);
		if (op == 1){
			scanf("%d %d", &u, &v);
			mp[u][v] = 0;
			sum--;
		}
		if (op == 2){
			scanf("%d", &u);
			for (int i = 1; i <= n; i++)
				if (mp[i][u]) mp[i][u] = 0, sum--;
		}
		if (op == 3){
			scanf("%d %d", &u, &v);
			mp[u][v] = 1;
			sum++;
		}
		if (op == 4){
			scanf("%d", &u);
			for (int i = 1; i <= n; i++)
				if (mp[i][u] != bg[i][u]) ++sum, mp[i][u] = bg[i][u];
		}
		memset(loop, 0, sizeof loop);
		memset(vis, 0, sizeof vis);
		bool flag = 1;
		for (int i = 1; i <= n && flag; i++)
			flag = judge(i);
		if (!flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
