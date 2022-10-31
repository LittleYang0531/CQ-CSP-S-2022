#include <bits/stdc++.h>
using namespace std;
const int maxn = 2505;

int n, m, k;
unsigned long long s[maxn];
vector<int> r[maxn];
bool rd[maxn][maxn];
bool vis[maxn];
//bool vis2[maxn];
//int h, t;
//int a[1e6];
int x, y;
unsigned long long ans;
void dfs1(int x, unsigned long long sum, int t){
//	printf("%d %d %d\n", x, sum, t);
	if(t > 4)return;
	if(t == 4){
		if(rd[x][1])ans = max(ans, sum + s[x]);
		return;
	}
	else{
		int Size, u;
		Size = r[x].size();
		for(int i = 0; i < Size; i ++){
			u = r[x][i];
			if(rd[x][u] && !vis[u]){
				vis[u] = 1;
				dfs1(u, sum + s[x], t + 1);
				vis[u] = 0;
			}
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 2; i <= n; i ++){
		scanf("%d", &s[i]);
	}
	for(int i = 1; i <= m; i ++){
		scanf("%d %d", &x, &y);
		r[x].push_back(y);
		r[y].push_back(x); 
		rd[x][y] = 1;
		rd[y][x] = 1;
	}
	if(!k){
		vis[1] = 1;
		dfs1(1, 0, 0);
		printf("%llu", ans);
	}
	return 0;
} 
