#include <bits/stdc++.h>
using namespace std;

int n, q, k, a, b, s, t, ans = INT_MAX;
bool vis[200001];

struct gnode{
	int val;
	vector<int> nlist;
}alln[200001];

void dfs(int f, int tpt, int time) {
	if (tpt >= k) {
		for (int i = 0; i < alln[f].nlist.size(); i++) {
			if (vis[alln[f].nlist[i]] == 0) {
				vis[alln[f].nlist[i]] = 1;
				dfs(alln[f].nlist[i], 0, time+alln[f].val);
				vis[alln[f].nlist[i]] = 0;
			}
		}
		return ;
	}
	if (f == t) {
		ans = min(ans, time+alln[f].val);
		return ;
	}
	for (int i = 0; i < alln[f].nlist.size(); i++) {
		if (vis[alln[f].nlist[i]] == 0) {
			vis[alln[f].nlist[i]] = 1;
			dfs(alln[f].nlist[i], 0, time+alln[f].val);
			dfs(alln[f].nlist[i], tpt+1, time);
			vis[alln[f].nlist[i]] = 0;
		}
	}
}

int main(){
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	scanf("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &alln[i].val);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		alln[a].nlist.push_back(b);
		alln[b].nlist.push_back(a);
	}
//	for (int i = 0; i < alln[4].nlist.size(); i++) {
//		cout << alln[4].nlist[i] << " ";
//	}
//	cout << endl;
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &s, &t);
		fill(vis, vis+200001, 0);
		ans = INT_MAX;
		vis[s] = 1;
		dfs(s, 0, 0);
		vis[s] = 0;
		printf("%d\n", ans);
	}
}
