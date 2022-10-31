#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5;
int n,m,degc[MAXN + 5],q,num[MAXN + 5],t,u,v;
int vis[MAXN + 5];
vector<int> g[MAXN + 5];
map<pair<int,int> ,int> c;
bool dfs(int now){
	vis[now] = -1;
	for(int i = 0; i < g[now].size(); i++){
		int k = g[now][i];
		if(c.find(make_pair(now,k)) != c.end() && c[make_pair(now,k)] == 1){
			if(vis[k] == -1)return 0;
			if(vis[k] == 0 && !dfs(k))return 0;
			if(vis[k] == 0 && dfs(k))return 1;
		}
	}
	vis[now] = 1;
	return 1;
}
bool check(){
	memset(vis,0,sizeof vis);
	for(int i = 1; i <= n; i++){
		if(dfs(i) != 0)return 0;
	}
	for(int i = 1; i <= n; i++){
		if(degc[i] != 1)return 0;
	}
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		c[make_pair(u,v)] = 1;
		degc[u]++;
		num[u]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> t;
		if(t == 1){
			int a,b;
			cin >> a >> b;
			degc[a]--;
			c[make_pair(a,b)] = 0;
		}
		else if(t == 2){
			int a;
			cin >> a;
			for(int j = 0; j < g[a].size(); j++){
				if(c.find(make_pair(g[a][j],a)) != c.end() && c[make_pair(g[a][j],a)] == 1){
					degc[g[a][j]]--;
					c[make_pair(g[a][j],a)] = 0;
				}
			}
		}
		else if(t == 3){
			int a,b;
			cin >> a >> b;
			degc[a]++;
			c[make_pair(a,b)] = 1;
		}
		else if(t == 4){
			int a;
			cin >> a;
			for(int j = 0; j < g[a].size(); j++){
				if(c.find(make_pair(g[a][j],a)) != c.end() && c[make_pair(g[a][j],a)] == 0){
					degc[g[a][j]]++;
					c[make_pair(g[a][j],a)] = 1;
				}
			}
		}
		if(check()){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}

