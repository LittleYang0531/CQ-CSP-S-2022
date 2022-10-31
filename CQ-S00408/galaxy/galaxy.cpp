#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,csp,q,t,u,v;
vector<int> fa[500005];
set<int> s[500005];
set<int>::iterator it;
bool vis[500005],hq[500005];
bool dfs(int x) {
	vis[x] = 1;
	it = s[x].begin();
	if(!vis[*it]) hq[x] |= dfs(*it);
	else hq[x] |= 1;
	return hq[x];
}
bool check() {
	bool res = 1;
	memset(vis,0,sizeof(vis));
	memset(hq,0,sizeof(hq));
	for(int i = 1;i <= n;i++) {
		if(s[i].size() != 1) return 0;
	}
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) dfs(i);
	}
	for(int i = 1;i <= n;i++) {
		if(!hq[i]) return 0;
	}
	return 1;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&csp);
	while(csp--) {
		scanf("%d%d",&u,&v);
		fa[v].push_back(u);
		s[u].insert(v);
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&t);
		if(t == 1) {
			scanf("%d%d",&u,&v);
			s[u].erase(v);
		} else if(t == 2) {
			scanf("%d",&u);
			for(int i = 0;i < fa[u].size();i++) s[fa[u][i]].erase(u);
		} else if(t == 3) {
			scanf("%d%d",&u,&v);
			s[u].insert(v);
		} else if(t == 4) {
			scanf("%d",&u);
			for(int i = 0;i < fa[u].size();i++) s[fa[u][i]].insert(u);
		}
		printf(check() ? "YES\n" : "NO\n");
	}
	if(1 + 1 != 2) printf("HOOCH AK IOI!!!\n");
	return 0;
}
