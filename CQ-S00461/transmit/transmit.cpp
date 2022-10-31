#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 2147483647 * 40;
int n, q, k;

unsigned long long v[maxn];
vector<int> t[maxn];
int x, y;
int r[maxn];
int l;
bool flag;
unsigned long long dp[maxn];
void dfs(int fa, int x, int y){
	if(x == y)return;
	if(flag)return;
	int Size = t[x].size();
	if(!Size)return;
	int u;
	for(int i = 0; i < Size; i ++){
		u = t[x][i];
		if(u == fa)continue;
		if(u == y){
			flag = 1;
			r[++ l] = u;
			return;
		}
		else{
			dfs(x, u, y);
			if(flag){
				r[++ l] = u;
				break;
			}
		}
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &q, &k);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &v[i]);
	}
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		t[x].push_back(y);
		t[y].push_back(x);
	}
	for(int i = 1; i <= q; i ++){
		scanf("%d %d", &x, &y);
		l = 0;
		flag = 0;
		dfs(0, x, y);
		r[++ l] = x;
		for(int j = 2; j < maxn; j ++){
			dp[j] = INF;
		}
		dp[1] = v[y];
		for(int j = 2; j <= l; j ++){
			for(int w = 1; w <= k && w < j; w ++){
				dp[j] = min(dp[j], v[r[j]] + dp[j - w]); 
			}
		}
		printf("%d\n", dp[l]);
	}
	return 0;
} 
