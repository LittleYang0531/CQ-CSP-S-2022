#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5000 + 5;

int n,m,q,cnt[MAX_N];

vector<int> V[MAX_N];

set<int> adj[MAX_N];

int fa[MAX_N];

int _find(int x){
	if(fa[x]!=x) fa[x]=_find(fa[x]);
	return fa[x];
}

bool vis[MAX_N];

void dfs(int x,int col){
	if(!vis[x]) vis[x]=col;
	else{
		fa[_find(vis[x])]=col;
		return;
	}
	for(auto y:adj[x]){
		dfs(y,col);
	}
}

int in[MAX_N];

inline bool check(){
//	for(int i=1;i<=n;++i) adj[i].clear();
	for(int i=1;i<=n;++i){
		if(adj[i].size()!=1) return false;
	}
	for(int i=1;i<=n;++i) vis[i]=0,fa[i]=i;
	int aa=0;
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,++aa);
	int goal=_find(1);
	for(int i=2;i<=n;++i) if(_find(vis[i])!=goal) return false;
	return true;
}

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		cnt[x]++;
		V[y].push_back(x);
		adj[x].insert(y);
	}
	scanf("%d",&q);
	while(q--){
		int op,u,v;
		scanf("%d%d",&op,&u);
		if(op==1){
			scanf("%d",&v);
			adj[u].erase(v);
			cnt[u]--;
		}
		else if(op==2){
			for(int i=1;i<=n;++i){
				
				if(adj[i].count(u)) adj[i].erase(u),cnt[i]--;
			}
		}
		else if(op==3){
			scanf("%d",&v);
			adj[u].insert(v);
			cnt[u]++;
		}
		else if(op==4){
			for(auto x:V[u]){
				adj[x].insert(u);
				cnt[x]++;
			}
		}
		if(check()) puts("YES");
		else puts("NO");
	}
	return 0;
}
