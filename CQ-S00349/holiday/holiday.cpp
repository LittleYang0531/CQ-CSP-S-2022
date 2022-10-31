#include<bits/stdc++.h>
#define NM "holiday"
using namespace std;
const int N=2505;
int n, m, k, sc[N];
vector<int> mp[N], st;
int vis[N];
int ans;
void dfs(int x, int s, int c) {
	if(x==1&&c==5) {
		ans=max(ans, s);
		for(int i:st)
			cout<<i<<' ';
		puts("");
		return ;
	}
	if(c==5&&x!=1)
		return ;
	for(int i:mp[x]) {
		if(vis[i])
			continue;
		vis[i]=1;
		st.push_back(i);
		dfs(i, s+sc[i], c+1);
		vis[i]=0;
		st.pop_back();
	}
}
int main() {
	freopen(NM".in", "r", stdin);
	freopen(NM".out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=2; i<=n; ++i)
		scanf("%d", sc+i);
	for(int i=1; i<=m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1, 0, 0);
	cout<<ans;
	return 0;
}