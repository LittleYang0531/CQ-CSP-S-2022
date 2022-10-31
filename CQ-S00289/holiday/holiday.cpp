#include <bits/stdc++.h>
using namespace std;
int v[2505];
vector<int> G[10005];
int vis[2505];
int maxn = 0;
int n,m,k;
void dfs(int p,int sum,int cost,int cnt){
	if (p == 1 && sum > 0 && cnt == 4) {
		maxn = max(maxn,sum);
		return;
	}
	if (cost > k) {
		return;
	}

	
	for (int j = 0;j < G[p].size();j++) {
		
		if (!vis[G[p][j]]) {
			vis[G[p][j]] = 1;
			dfs(G[p][j],sum,cost+1,cnt);
			vis[G[p][j]] = 0;
			
		}
		if (!vis[G[p][j]] && cnt < 4 && G[p][j] != 1) {
			vis[G[p][j]] = 1;
			dfs(G[p][j],sum + v[G[p][j]],0,cnt+1);
			vis[G[p][j]] = 0;
			
		}
		
	}
	
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	cin >> n >> m >>k;
	for (int i = 2;i <= n ;i++) {
		cin >> v[i];
	}
	for (int i = 0;i < m;i++) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0,0,0);
	cout << maxn << endl;
	return 0;
}
